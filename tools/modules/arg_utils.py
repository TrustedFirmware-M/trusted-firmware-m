#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

import argparse

import logging
logger = logging.getLogger("TF-M.{}".format(__name__))

from elftools.elf.elffile import ELFFile
from tfm_tools.file_loader import load_bytes_from_file

from tfm_tools.c_struct import C_enum

from os.path import isfile, dirname, isdir

from tfm_tools.crypto_conversion_utils import convert_curve_define, convert_hash_define

prefix_sep = ":"

def incompatible_arg(args : argparse.Namespace,
                     arg1 : str,
                     arg2 : str
                     ):
    assert not (get_arg(args, arg1) and get_arg(args, arg2)), "Incompatible arguments {} and {} cannot both be specified".format(arg1, arg2)

def add_prefixed_argument(parser: argparse.ArgumentParser,
                          arg_name : str,
                          prefix : str = "",
                          **args):

    if "--" + arg_name not in parser._option_string_actions.keys():
        parser.add_argument("--" + join_prefix(arg_name, prefix), **args)

def _arg_type_enum(arg : str, enum : C_enum):
    assert arg in enum.dict.keys(), "Invalid enum value {} not in {}".format(arg, list(enum.dict.keys()))
    return enum.dict[arg]

def arg_type_enum(enum : C_enum):
    return lambda x: _arg_type_enum(x, enum)


def add_prefixed_enum_argument(parser : argparse.ArgumentParser,
                               enum : C_enum,
                               arg_name : str,
                               default : str = None,
                               prefix : str = "",
                               **kwargs):

    if default:
        assert default in enum.dict.keys()

    return add_prefixed_argument(parser=parser,
                                 arg_name = arg_name,
                                 type=arg_type_enum(enum),
                                 prefix=prefix,
                                 default=default,
                                 metavar=enum.name,
                                 choices=enum.dict.values(),
                                 **kwargs)


def join_prefix(arg : str, prefix : str):
    assert(arg)

    if not prefix:
        return arg

    if prefix_sep not in arg:
        return prefix + prefix_sep + arg
    else:
        #Insert the prefix at the right of current prefixes
        curr_prefix, arg = arg.rsplit(prefix_sep, 1)
        return curr_prefix + prefix_sep + prefix + prefix_sep + arg

def is_prefixed(arg : str, prefix : str):
    return prefix + prefix_sep in arg

def unjoin_prefix(arg : str, prefix : str):
    if not prefix:
        return arg

    assert(is_prefixed(arg, prefix))

    return arg.rsplit(prefix + prefix_sep, 1)[1]

def get_arg(args : argparse.Namespace,
            arg_name : str,
            prefix : str = "",
            ):
    if hasattr(args, join_prefix(arg_name, prefix)):
       return getattr(args, join_prefix(arg_name, prefix))
    else:
       logging.info("Arg {} value not set".format(arg_name))
       return None

def parse_args_automatically(args : argparse.Namespace,
               arg_names : [str],
               prefix : str = "",
               ) -> dict:
    return {a: get_arg(args, a, prefix) for a in arg_names if get_arg(args, a, prefix) is not None}

def arg_type_version(arg):
    assert (len(arg.split(".")) == 3), "Invalid image version format (must be \"x.y.z(+q)?\""
    return [int(x) for x in arg.replace("+", ".").split(".")]

def _arg_type_elf_section(arg : str,
                          section_name : str,
                          ) -> bytes:
    if type(section_name) == str:
        section_name = [section_name]

    out = []

    with ELFFile(open(arg, 'rb')) as elffile:
        for s in section_name:
            section = elffile.get_section_by_name(s)
            if section:
                out.append(section.data())
            else:
                out.append(None)
                logging.warning("ELF file {} does not contain section {}".format(arg, s))
    return out

def arg_type_elf_section(section_name : str):
    return lambda x: _arg_type_elf_section(x, section_name)

def arg_type_elf(arg : str) -> bytes:

        return {"code": code_section.data(), "data": data_section.data() if data_section else None}

def arg_type_input_filepath(arg : str) -> str:
    assert isfile(arg), "File {} does not exist".format(arg)
    return arg

def arg_type_output_filepath(arg : str) -> str:
    dir = dirname(arg)

    if not dir:
        dir = "."

    assert isdir(dir), "Directory {} does not exist to create file ".format(dir, arg)
    return arg

def arg_type_bytes_from_file(arg : str) -> (bytes, bytes):
    return load_bytes_from_file(arg)

def arg_type_hex(arg : str) -> int:
    assert(arg)
    return bytes.fromhex(arg)

def arg_type_bytes(arg : str) -> bytes:
    try:
        return arg_type_bytes_from_file(arg)
    except FileNotFoundError:
        assert len(arg) % 2 == 0, "Hex values must be a multiple of two characters long"
        return arg_type_hex(arg.replace("0x", ""))

def arg_type_bytes_input_file(arg : str):
    arg_type_input_filepath(arg)
    return open(arg, "rb")

def arg_type_text_input_file(arg : str):
    arg_type_input_filepath(arg)
    return open(arg, "rt")

def arg_type_bytes_output_file(arg : str):
    arg_type_output_filepath(arg)
    return open(arg, "wb")

def arg_type_text_output_file(arg : str):
    arg_type_output_filepath(arg)
    return open(arg, "wt")

def arg_type_hash(arg : str):
    return convert_hash_define(arg)

def arg_type_curve(arg : str):
    return convert_curve_define(arg)

def arg_type_bool(arg : str):
    larg = arg.lower()

    assert larg in ["true", "false", "on", "off"], "Invalid boolean value {}".format(arg)

    return larg in ["true", "on"]

def pre_parse_args(parser : argparse.ArgumentParser,
                   name : str,
                   required : bool = True,
                   **kwargs : dict):
    pre_arg_parser = argparse.ArgumentParser(add_help=False)

    pre_arg_parser.add_argument("--" + name, required=required, **kwargs)

    if "--" + name not in parser._option_string_actions.keys():
        parser.add_argument("--" + name, required=required, **kwargs)

    parsed, _ = pre_arg_parser.parse_known_args()
    return getattr(parsed, name)
