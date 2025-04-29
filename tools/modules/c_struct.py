#!/usr/bin/env python3
#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

import clang.cindex as cl
import struct
from collections import Counter
import os

import logging
logger = logging.getLogger("TF-M.{}".format(__name__))

from rich import inspect

pad = 4

format_chars = {
    'uint8_t'     : 'B',
    'uint16_t'    : 'H',
    'uint32_t'    : 'I',
    'uint64_t'    : 'Q',
    'bool'        : '?',
    'char'        : 'b',
    'short'       : 'H',
    'int'         : 'I',
    'long'        : 'I',
    'long long'   : 'Q',
    'uintptr_t'   : 'I',
    'size_t'      : 'I',
    'float'       : 'f',
    'double'      : 'd',
    'long double' : 'd',
}

def _c_struct_or_union_from_cl_cursor(cursor, name, f):
        def is_field(x):
            if x.kind == cl.CursorKind.FIELD_DECL:
                return True
            if x.kind in [cl.CursorKind.STRUCT_DECL, cl.CursorKind.UNION_DECL]:
                return True
            return False

        fields = [c for c in cursor.get_children() if is_field(c)]
        packed  = True if [c for c in cursor.get_children() if c.kind == cl.CursorKind.PACKED_ATTR] else False

        c_type = cursor.spelling

        fields = [_c_from_cl_cursor(f) for f in fields]
        fields = [f for f in fields if f.get_size() != 0]

        duplicate_types = Counter([f.c_type for f in fields if not isinstance(f, C_variable)])
        duplicate_types = [k for k,v in duplicate_types.items() if v > 1]
        fields = [f for f in fields if f.c_type not in duplicate_types or f.name != ""]

        return f(name, c_type, fields, packed)

def _pad_lines(text, size):
    lines = text.split("\n")
    lines = [" " * size + l for l in lines]
    return "\n".join(lines)

def _c_struct_or_union_get_value_str(self, struct_or_union):
    string = "{\n"
    fields_string = ""
    for f in self._fields:
        if f.to_bytes() != bytes(f.get_size()):
            fields_string += _pad_lines(".{} = {},".format(f.name, f.get_value_str()), pad)
            fields_string += "\n"
    fields_string = fields_string[:-1]
    if not fields_string:
        return "{}"
    string += fields_string
    string += "\n}"
    return string

def _c_struct_or_union_str(self, struct_or_union):
        string = ""
        string += "{} ".format(struct_or_union)
        string += "__attribute__((packed)) " if self._packed else ""
        string += "{} ".format(self.c_type) if self.c_type != "" else ""
        string += "{\n"

        fields_string = "\n".join([_pad_lines(str(f), pad) for f in self._fields])
        string += fields_string

        if string[-1] != "\n":
            string += "\n"

        string += "}"
        string += " {}".format(self.name) if self.name != "" else ""
        string += ";"
        return string

def _c_struct_or_union_get_field_strings(self):
    field_strings=[]

    for f in self._fields:
        name_format = "{}.".format(self.name) if self.name != "" else ""
        field_strings += [name_format + s for s in f.get_field_strings()]

    return field_strings

def _c_struct_or_union_field_to_bytes(field):
    if isinstance(field, C_variable):
        return field._get_format_string(), field.get_value()
    else:
        return _binary_format_string(field.get_size()), field.to_bytes()

def _c_struct_or_union_get_next_in_path(self, field_path):
    field_separator = "."

    if field_separator in field_path:
        field_name, remainder = field_path.split(".", 1)
    else:
        field_name = field_path
        remainder = None

    try:
        # Fields aren't allowed to duplicate names
        field = [f for f in self._fields if f.name == field_name][0]
        return field, remainder
    except (KeyError, IndexError):
        for f in self._fields:
            try:
                f.get_field(field_path)
                return f, field_path
            except KeyError:
                continue
    raise KeyError

def _c_struct_or_union_get_direct_members(self):
    subfields = []
    for f in self._fields:
        if f.name:
            continue
        subfields += _c_struct_or_union_get_direct_members(f)

    return [f for f in self._fields if f.name] + subfields

def _c_struct_or_union_get_field(self, field_path):
    fields = [f for f in self._fields if f.name == field_path[:len(f.name)]]
    for f in fields:
        try:
            remainder = field_path.replace(f.name + ".", "") if f.name else field_path
            return f.get_field(remainder)
        except (KeyError, ValueError):
            continue
    raise KeyError


def _binary_format_string(size):
    return "{}s".format(size)

class C_enum:
    def __init__(self, name, c_type, members):
        self.name = name.replace("enum", "").lstrip()
        self._members = members
        self.dict = {m.name:m for m in self._members}
        self.__dict__.update({m.name:m for m in self._members})

    @staticmethod
    def from_h_file(h_file, name, includes = [], defines = []):
        return _c_from_h_file(h_file, name, includes, defines, C_enum, cl.CursorKind.ENUM_DECL)

    @staticmethod
    def from_cl_cursor(cursor, name=""):
        definition = cursor.get_definition()
        assert(definition.kind == cl.CursorKind.ENUM_DECL)

        max_value = max([x.enum_value for x in definition.get_children()])
        if (max_value <= 2^8):
            c_type = 'uint8_t'
        elif (max_value <= 2^16):
            c_type = 'uint16_t'
        else:
            c_type = 'uint32_t'

        members = [C_enum_member(x.spelling, c_type, x.enum_value) for x in definition.get_children()]
        members = [m for m in members if m.name[0] != '_']
        return C_enum(cursor.spelling, c_type, members)


    def __str__(self):
        pad = 4

        string = ""

        string += "enum "
        string += "{} ".format(self.name)
        string += "{\n"

        fields_string = "\n".join([_pad_lines(str(f), pad) for f in self._members])
        string += fields_string

        if string[-1] != "\n":
            string += "\n"

        string += "};"
        return string

class C_enum_member:
    def __init__(self, name, c_type, value):
        self.name = name
        self.c_type = c_type
        self.value = value
        self._format_string = self._get_format_string()
        self._size = struct.calcsize(self._get_format_string());

    def _get_format_string(self):
        return format_chars[self.c_type]

    def get_value(self):
        return self.value

    def to_bytes(self):
        return struct.pack("<" + self._format_string, self.get_value())

    def get_size(self):
        return self._size

    def __str__(self):
        return self.name

    def __repr__(self):
        return self.name

class C_array:
    def __init__(self, name, c_type, members):
        self.name = name
        self.c_type = c_type
        self._members = members

        if self._members:
            self._dimensions = [len(self._members)]
            if isinstance(self._members[0], C_array):
                self._dimensions += self._members[0]._dimensions
        else:
            self._dimensions = [0]

        self._size = struct.calcsize(self._get_format_string());

    @staticmethod
    def from_h_file(h_file, name, includes = [], defines = []):
        return _c_from_h_file(h_file, name, includes, defines, C_array, cl.CursorKind.TYPE_DECL)

    @staticmethod
    def from_cl_cursor(cursor, name="", dimensions = []):
        c_type = cursor.type.spelling
        c_type = c_type.replace("unsigned", "")
        c_type = c_type.replace("volatile", "")
        c_type = c_type.replace("const", "")
        c_type = c_type.replace("static", "")

        if not dimensions:
            c_type, *dimensions = c_type.split("[")
            dimensions = [0 if d == "]" else int(d.replace("]", "")) for d in dimensions]
        c_type = c_type.strip()

        assert(len(dimensions) > 0)

        if (len(dimensions) > 1):
            f = lambda x:C_array.from_cl_cursor(cursor, x, dimensions[1:])
        elif c_type not in format_chars.keys():
            f = lambda x:_c_from_cl_cursor(list(cursor.get_children())[0].get_definition(), x)
        else:
            f = lambda x:C_variable(x, c_type)

        members = [f(name + "_{}".format(i)) for i in range(dimensions[0])]

        return C_array(name, c_type, members)

    def __getitem__(self, index):
        return self._members[index]

    # def __setitem__(self, index, value):
    #     return self._members[index].set_value_from_bytes(value)

    def _get_format_string(self):
        return "<" + "".join([_c_struct_or_union_field_to_bytes(m)[0] for m in self._members])

    def get_value(self):
        return self.to_bytes()

    def set_value(self, value):
        self.set_value_from_bytes(value)

    def set_value_from_bytes(self, value):
        assert(len(value) <= self._size), "{} of size {} cannot be set to value {} of size {}".format(self, self._size, value.hex(), len(value))
        value_used = 0
        for m in self._members:
            if (value_used == len(value)):
                break

            m.set_value_from_bytes(value[value_used:value_used + m.get_size()])
            value_used += m.get_size()

    def get_field_strings(self):
        return [self.name] + [f for m in self._members if not isinstance(m, C_variable) for f in m.get_field_strings()]

    def get_field(self, field_path):
        if field_path == self.name:
            return self

        field_path = field_path.replace(self.name + "_", "")

        splits = [x for x in [field_path.find('.'), field_path.find("_")] if x != -1]

        if not splits:
            index = field_path
            remainder = None
        else:
            split_idx = min(splits)
            index = field_path[:split_idx]
            remainder = field_path[split_idx + 1:]

        index = int(index)

        if (remainder):
            return self._members[index].get_field(remainder)
        else:
            return self._members[index]

    def to_bytes(self):
        format_str = ""
        values = []

        for m in self._members:
            field_string, field_data = _c_struct_or_union_field_to_bytes(m)
            format_str += field_string
            values.append(field_data)

        return struct.pack(format_str, *values)

    def get_size(self):
        return self._size

    def get_value_str(self):
        string = ""
        if self.to_bytes() != bytes(self.get_size()):
            string += "{\n"
            m_string = ""
            for idx,m in enumerate(self._members):
                tmp = m.get_value_str() + ", "
                m_string += tmp
                if m_string[-3:] == "}, " or idx % 8 == 7:
                    m_string = m_string[:-1] + "\n"
            m_string = m_string[:-1]
            string += _pad_lines(m_string, pad)
            string += "\n}"
            return string
        else:
            return "{}"

    def __str__(self):
        string = "{} {}".format(self.c_type, self.name)
        string += "".join(["[{}]".format(a) for a in self._dimensions])

        if self.to_bytes() != bytes(self.get_size()):
            string += " = " + self.get_value_str()

        string += ";"
        return string

class C_variable:
    def __init__(self, name, c_type, value = None):
        self.name = name
        self.c_type = c_type
        self._format_string = self._get_format_string()
        self._size = struct.calcsize(self._format_string)
        self.value = value

    @staticmethod
    def from_h_file(h_file, name, includes = [], defines = []):
        return _c_from_h_file(h_file, name, includes, defines, C_variable, cl.CursorKind.TYPE_DECL)

    @staticmethod
    def from_cl_cursor(cursor, name=""):
        c_type = cursor.type.spelling
        c_type = c_type.replace("unsigned", "")
        c_type = c_type.replace("volatile", "")
        c_type = c_type.replace("const", "")
        c_type = c_type.replace("static", "")

        if "[" in c_type:
            return C_array.from_cl_cursor(cursor, name)

        return C_variable(name, c_type)

    def _get_format_string(self):
        if 'enum' in self.c_type:
            return format_chars['uint32_t']

        return format_chars[self.c_type]

    def get_value(self):
        value = self.value if self.value else 0
        return value

    def set_value(self, value):
        if isinstance(value, str):
            self.value = int(value, 0)
        else:
            self.value = value

        #Sanity check the value
        self.to_bytes()

    def set_value_from_bytes(self, value):
        self.set_value(struct.unpack(self._format_string, value)[0])

    def get_field_strings(self):
        return [self.name]

    def get_field(self, field_path):
        if field_path != self.name:
            raise KeyError
        return self

    def to_bytes(self):
        return struct.pack("<" + self._format_string, self.get_value())

    def get_size(self):
        return self._size

    def get_value_str(self):
        value = self.value or 0
        return f"0x{value:02x}"

    def __str__(self):
        string = "{} {}".format(self.c_type, self.name)

        if self.value != None:
            string += " = {}".format(self.get_value_str())

        string += ";"
        return string

class C_union:
    def __init__(self, name="", c_type="", fields=[], packed=False):
        self.name = name
        self.c_type = c_type.replace("union ", "")
        self._fields = fields
        self._packed = packed
        self._format_strings = self._get_format_strings()
        self._size = max(map(struct.calcsize, self._format_strings))
        self._actual_value = bytes(self._size)
        self.__dict__.update({f.name:f for f in _c_struct_or_union_get_direct_members(self)})

    @staticmethod
    def from_h_file(h_file, name, includes = [], defines = []):
        return _c_from_h_file(h_file, name, includes, defines, C_union, cl.CursorKind.UNION_DECL)

    @staticmethod
    def from_cl_cursor(cursor, name=""):
        return _c_struct_or_union_from_cl_cursor(cursor, name, C_union)

    def _ensure_consistency(self):
        binaries = [f.to_bytes() for f in self._fields]
        new_binaries = [b for b in binaries if b != self._actual_value[:len(b)]]
        new_binaries = list(set(new_binaries))

        assert(len(new_binaries) < 2)

        if new_binaries:
            self._actual_value = new_binaries[0] + self._actual_value[len(new_binaries[0]):]

        for f in self._fields:
            f.set_value_from_bytes(self._actual_value[:f._size])

    def _get_format_strings(self):
        format_endianness = "<" if self._packed else "@"
        return ["{}{}".format(format_endianness, _binary_format_string(f._size)) for f in self._fields]

    def set_value_from_bytes(self, value):
        for f in self._fields:
            f.set_value_from_bytes(value)
        self._ensure_consistency()

    def set_value(self, field_path, value):
        field.set_value(self.get_field(field_path))
        self._ensure_consistency()

    def get_value(self, field_path):
        self._ensure_consistency()
        return self.get_field(field_path).value

    def get_field_strings(self):
        self._ensure_consistency()
        return _c_struct_or_union_get_field_strings(self)

    def get_field(self, field_path):
        self._ensure_consistency()
        return _c_struct_or_union_get_field(self, field_path)

    def to_bytes(self):
        self._ensure_consistency()
        binaries = [f.to_bytes() for f in self._fields]

        binaries = set(binaries)
        return max(list(binaries))

    def get_size(self):
        return self._size

    def get_value_str(self):
        self._ensure_consistency()
        return _c_struct_or_union_get_value_str(self, "union")

    def __str__(self):
        self._ensure_consistency()
        return _c_struct_or_union_str(self, "union")

class C_struct:
    def __init__(self, name="", c_type="", fields=[], packed=False):
        self.name = name
        self.c_type = c_type.replace("struct ", "")
        self._fields = fields
        self._packed = packed
        self._format_string = self._get_format_string()
        self._size = struct.calcsize(self._format_string)
        self.__dict__.update({f.name:f for f in _c_struct_or_union_get_direct_members(self)})

    @staticmethod
    def from_h_file(h_file, name, includes = [], defines = []):
        return _c_from_h_file(h_file, name, includes, defines, C_struct, cl.CursorKind.STRUCT_DECL)

    @staticmethod
    def from_cl_cursor(cursor, name=""):
        return _c_struct_or_union_from_cl_cursor(cursor, name, C_struct)

    def _get_format_string(self):
        format_endianness = "<" if self._packed else "@"
        return format_endianness + "".join([_c_struct_or_union_field_to_bytes(f)[0] for f in self._fields])

    def set_value_from_bytes(self, value):
        value_used = 0
        for f in self._fields:
            f.set_value_from_bytes(value[value_used:value_used + f.get_size()])
            value_used += f.get_size()
        assert(value_used == len(value))

    def set_value(self, field_path, value):
        self.get_field(field_path).set_value(value)

    def get_value(self, field_path):
        return self.get_field(field_path).value

    def get_field_strings(self):
        return _c_struct_or_union_get_field_strings(self)

    def get_field(self, field_path):
        return _c_struct_or_union_get_field(self, field_path)

    def to_bytes(self):
        format_endianness = "<" if self._packed else "@"
        format_str = ""
        values = []

        for f in self._fields:
            field_string, field_data = _c_struct_or_union_field_to_bytes(f)
            format_str += field_string
            values.append(field_data)

        return struct.pack(format_str, *values)

    def get_size(self):
        return self._size

    def get_docs_table(self):
        return _c_struct_or_union_get_docs_table(self)

    def get_value_str(self):
        return _c_struct_or_union_get_value_str(self, "struct")

    def __str__(self):
        return _c_struct_or_union_str(self, "struct")

def _parse_field_dec(cursor):
    return list(cursor.get_children())[0], cursor.spelling

def _parse_type_ref(cursor, name):
    return cursor.get_definition(), name

def _c_from_cl_cursor(cursor, name = ""):
    if cursor.kind == cl.CursorKind.STRUCT_DECL:
        return C_struct.from_cl_cursor(cursor, name)

    elif cursor.kind == cl.CursorKind.UNION_DECL:
        return C_union.from_cl_cursor(cursor, name)

    elif cursor.kind in [cl.CursorKind.TYPEDEF_DECL, cl.CursorKind.ENUM_DECL]:
        return C_variable.from_cl_cursor(cursor, name)

    elif cursor.kind == cl.CursorKind.FIELD_DECL:
        if cursor.type.kind == cl.TypeKind.CONSTANTARRAY:
            return C_variable.from_cl_cursor(cursor, cursor.spelling)

        return _c_from_cl_cursor(*_parse_field_dec(cursor))

    elif cursor.kind == cl.CursorKind.TYPE_REF:
        return _c_from_cl_cursor(*_parse_type_ref(cursor, name))

    raise NotImplementedError

def _c_from_h_file(h_file, name, includes, defines, f, kind):
    name = name.replace("struct ", "")
    name = name.replace("union ", "")

    args = ["-I{}".format(i) for i in includes if os.path.isdir(i)]
    args += ["-D{}".format(d) for d in defines]

    if not os.path.isfile(h_file):
        return FileNotFoundError

    idx = cl.Index.create()
    tu = idx.parse(h_file, args=args)

    t = [cl.Cursor().from_location(tu, t.location) for t in tu.cursor.get_tokens() if t.spelling == name]
    t = [x for x in t if x.kind == kind]

    errors = ["{}: {} at {}:{}".format(d.category_name, d.spelling, d.location.file.name, d.location.line) for d in tu.diagnostics if d.severity > 2]
    warnings = ["{}: {} at {}:{}".format(d.category_name, d.spelling, d.location.file.name, d.location.line) for d in tu.diagnostics if d.severity > 3]

    for w in warnings:
        print(w)

    if errors:
        for e in errors:
            print(e)
        exit(1)

    if len(t) == 0:
        print("Failed to find {} in {}".format(name, h_file))
        exit(1)

    assert(len(t) == 1)
    t = t[0]

    return f.from_cl_cursor(t, name)


if __name__ == '__main__':
    import argparse
    import c_include

    parser = argparse.ArgumentParser(allow_abbrev=False)
    parser.add_argument("--h_file", help="header file to parse", required=True)
    parser.add_argument("--struct_name", help="struct name to evaluate", required=True)
    parser.add_argument("--compile_commands_file", help="header file to parse", required=True)
    parser.add_argument("--c_file_to_mirror_includes_from", help="name of the c file to take", required=True)
    parser.add_argument("--log_level", help="log level", required=False, default="ERROR", choices=logging._levelToName.values())
    args = parser.parse_args()
    logging.getLogger("TF-M").setLevel(args.log_level)
    logger.addHandler(logging.StreamHandler())

    includes = c_include.get_includes(args.compile_commands_file, args.c_file_to_mirror_includes_from)
    defines = c_include.get_defines(args.compile_commands_file, args.c_file_to_mirror_includes_from)

    s = C_struct.from_h_file(args.h_file, args.struct_name, includes, defines)
    print(s)
