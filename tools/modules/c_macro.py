#!/usr/bin/env python3
#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

import re
import ast
import sys
import os
import operator as op
import string
from tfm_tools.c_include import get_includes, get_defines

def _int(x):
    if isinstance(x, str):
        return int(x, 0)
    else:
        return x


def _split_inner_brackets(x):
    if not ("(" in x or ")" in x):
        return "", x, ""

    open_brackets  = [i for i, c in enumerate(x) if c == "("]
    close_brackets = [i for i, c in enumerate(x) if c == ")"]
    assert(len(open_brackets) == len(close_brackets))

    c = close_brackets[0]
    o = [b for b in open_brackets if b < c][-1]
    return x[:o], x[o+1:c], x[c+1:]

def _split_outer_brackets(x):
    if not ("(" in x or ")" in x):
        return "", x, ""

    open_brackets  = [i for i, c in enumerate(x) if c == "("]
    close_brackets = [i for i, c in enumerate(x) if c == ")"]

    while len(open_brackets) > 0:
        c = close_brackets[0]
        o = [b for b in open_brackets if b < c][-1]
        close_brackets.remove(c)
        open_brackets.remove(o)
    return x[:o], x[o+1:c], x[c+1:]

def _replace_from_dict(s, d):
    for k,v in d.items():
        s = s.replace(k, str(v))
    return s

def _eval_maths(expr):
    return _int(__eval_maths(expr))

def ternary(cond, if_true, if_false):
    return if_true if cond else if_false

def __eval_maths(expr):
    def _bool_to_int(b):
        if isinstance(b, bool):
            return 1 if b else 0
        else:
            return b

    expr = expr.rstrip().lstrip()

    if "(" in expr or ")" in expr:
        s, b, e = _split_inner_brackets(expr)
        return _eval_maths(s + str(_eval_maths(b)) + e)

    ops = {
        ternary:   r"(.*)\?(.*):(.*)",
        op.or_:    r"(.*)\|\|(.*)",
        op.and_:   r"(.*)&&(.*)",
        op.ne:     r"(.*)!=(.*)",
        op.eq:     r"(.*)==(.*)",
        op.ge:     r"(.*)>=(.*)",
        op.le:     r"(.*)<=(.*)",
        op.gt:     r"(.*)>(.*)",
        op.lt:     r"(.*)<(.*)",
        op.rshift: r"(.*)>>(.*)",
        op.lshift: r"(.*)<<(.*)",
        op.sub:   r"(.*)-(.*)",
        op.add:   r"(.*)\+(.*)",
        op.mod:   r"(.*)%(.*)",
        op.floordiv:   r"(.*)/(.*)",
        op.mul:   r"(.*)\*(.*)",
        op.not_:  r"!([^=].*)",
    }
    for f, regex in ops.items():
        r = re.search(regex, expr)
        if not r:
            continue
        return _bool_to_int(f(*[_int(__eval_maths(x)) for x in r.groups()]))
    return _int(expr)

def _remove_comments(text):
    # Remove comments from the line
    text = re.sub(r"/\*.*?\*/", "", text)
    text = text.split("//")[0].strip()
    return text

def _get_next_line(text):
    lines = text.split("\n")
    is_multiline_comment = False
    for I in range(len(lines)):
        yield_line = lines[I]

        yield_line = _remove_comments(yield_line)

        if is_multiline_comment:
            if "*/" not in yield_line:
                continue
            else:
                is_multiline_comment = False
                yield_line = "/*" + yield_line
        else:
            if "/*" in yield_line and "*/" not in yield_line:
                is_multiline_comment = True

                # Multi-line macros comments will be handled after
                if(yield_line[-1] != "\\"):
                    yield_line = yield_line[:yield_line.find("/*")]

        while (len(yield_line) > 0 and yield_line[-1] == "\\"):
            I += 1
            yield_line = yield_line[:-1] + lines[I]

        yield_line = _remove_comments(yield_line)

        yield yield_line

def split_expr(expr: str):
    # First split on whitespace
    parts = expr.split()
    tokens = []
    for part in parts:
        # For each chunk, split again on math symbols
        for op in "()*/+-":
            part = part.replace(op, f" {op} ")
        tokens.extend(part.split())
    return tokens

def _replace_whole_word(text, target, replacement):
    custom_punct = string.punctuation.replace("_", "")
    words = split_expr(text)
    new_words = [
        word.replace(target, replacement) if word.strip(custom_punct) == target else word
        for word in words
    ]
    return ' '.join(new_words)

def contains_identifier(text: str, identifier: str) -> bool:
        pattern = rf'(?<![A-Za-z0-9_]){re.escape(identifier)}(?![A-Za-z0-9_])'
        return re.search(pattern, text) is not None

class Conditional_block_state():
    """Represents the state of a conditional block (#if/elif/else)"""
    def __init__(self, condition):
        self._in_true_branch = condition
        self._had_true_branch = condition

    def update_else(self, condition):
        """Update the state when processing an #elif or #else"""
        self._in_true_branch = not self._had_true_branch and condition
        self._had_true_branch = self._had_true_branch or self._in_true_branch

    def is_in_true_branch(self):
        return self._in_true_branch

class C_macro():
    def __init__(self):
        self._definitions = {}
        self._include_paths = []
        self._ifdefs = []

    def _sync___dict__(self):
        self.__dict__.update(self._definitions)

    @staticmethod
    def from_h_file(h_file, include_paths = [], command_line_defines = []):
        macro = C_macro()
        macro._include_paths = include_paths

        for x in command_line_defines:
            macro._parse_define(x.replace("=", " "))

        macro.parse_header(h_file)
        return macro

    @staticmethod
    def from_text(text):
        macro = C_macro()
        macro.parse_text(text)
        return macro

    def _evaluate_macros_on_text_once(self, text):
        for d,v in self._definitions.items():
            if not v:
                continue

            if isinstance(v, str):
                text = _replace_whole_word(text, d, v)
            else:
                if contains_identifier(text, d):
                    s, me = text.split(d, 1)
                    _, m, e = _split_outer_brackets(me)
                    m = str(v(*[x.rstrip().lstrip() for x in m.split(",")]))
                    text = s + m + e

        try:
            text = str(_eval_maths(text))
        except Exception as ex:
            pass
        return text

    def evaluate_macros_on_text(self, text):
        processed_text = self._evaluate_macros_on_text_once(text)

        recurse_counter = 0
        while(processed_text != text and recurse_counter < 10):
            text = processed_text
            processed_text = self._evaluate_macros_on_text_once(text)
            recurse_counter += 1

        return processed_text

    def _parse_macro_function(self, x):

        name, rest = x.split("(", 1)
        args, func = rest.split(")", 1)
        args = [a.rstrip().lstrip() for a in args.split(",")]
        func = self.evaluate_macros_on_text(func)
        self._definitions[name] = lambda *x: _replace_from_dict(func, dict(zip(args, x)))
        self._sync___dict__()

    def _parse_define(self, x):
        if " " not in x:
            self._definitions[x] = None
            self._sync___dict__()
            return

        name, value = x.split(" ", 1)

        if "(" in name:
            return self._parse_macro_function(x)

        self._definitions[name.strip()] = self.evaluate_macros_on_text(value.strip())
        self._sync___dict__()

    def _parse_undef(self, x):
        self._definitions = {k:v for k,v in self._definitions.items() if k != x}
        self._sync___dict__()

    def _parse_ifdef(self, x):
        self._ifdefs.append([x, Conditional_block_state(x in self._definitions.keys())])

    def _parse_ifndef(self, x):
        self._ifdefs.append([x, Conditional_block_state(x not in self._definitions.keys())])

    def _parse_else(self, x):
        self._ifdefs[-1][1].update_else(True)

    def _parse_endif(self, x):
        self._ifdefs = self._ifdefs[:-1]

    def _eval_if(self, x):
        def replace_if_possible(x):
            if x.group(1) not in self._definitions.keys():
                return "0"
            else:
                return "1"

        condition = x
        if "defined(" in condition:
            condition = re.sub(r"defined\((.*?)\)", replace_if_possible, condition)

        condition = self.evaluate_macros_on_text(condition)

        try:
            value = _eval_maths(condition)
        except ValueError:
            value = 0
        return condition, value

    def _parse_if(self, x):
        condition, value = self._eval_if(x)
        self._ifdefs.append([condition, Conditional_block_state(value)])

    def _parse_elif(self, x):
        condition, value = self._eval_if(x)
        self._ifdefs[-1][1].update_else(value)

    def _parse_error(self, x):
        print(x)
        sys.exit(1)

    def parse_line(self, x):
        conditional_tokens = {
            "#ifdef ":  self._parse_ifdef,
            "#ifndef ":  self._parse_ifndef,
            "#endif":   self._parse_endif,
            "#if ": self._parse_if,
            "#else": self._parse_else,
            "#elif": self._parse_elif,
        }

        other_tokens = {
            "#define ": self._parse_define,
            "#undef ": self._parse_undef,
            "#include ": self.parse_header,
            "#error ": self._parse_error,
        }

        tokens = {**conditional_tokens, **other_tokens}

        x = x.strip()
        for t,f in tokens.items():
            if t in x:
                if t not in conditional_tokens.keys() and [i for i in self._ifdefs if not i[1].is_in_true_branch()]:
                    return

                f(x.replace(t, "").strip())

    def parse_text(self, text):
        for l in _get_next_line(text):
            self.parse_line(l)

    def _search_paths(self, h_file):
        for i in self._include_paths:
            file_path = os.path.join(i, h_file)
            try:
                if os.path.isfile(file_path):
                    return file_path
            except FileNotFoundError:
                continue
        return h_file

    def parse_header(self, h_file):
        #Don't parse system includes
        if "<" in h_file:
            return

        h_file = h_file.replace("\"", "")
        h_file = self._search_paths(h_file)

        with open(h_file, "rt") as f:
            self.parse_text(f.read())
        pass

def main():
    import argparse

    parser = argparse.ArgumentParser(allow_abbrev=False)
    parser.add_argument("--h_file", help="header file to parse", required=True)
    parser.add_argument("--macro_name", help="macro name to evaluate", required=True)
    parser.add_argument("--compile_commands_file", help="header file to parse", required=True)
    parser.add_argument("--c_file_to_mirror_includes_from", help="name of the c file to take", required=True)
    args = parser.parse_args()

    includes = get_includes(args.compile_commands_file, args.c_file_to_mirror_includes_from)
    defines = get_defines(args.compile_commands_file, args.c_file_to_mirror_includes_from)
    s = C_macro.from_h_file(args.h_file, includes, defines)
    print(s._definitions)

if __name__ == '__main__':
    sys.exit(main())
