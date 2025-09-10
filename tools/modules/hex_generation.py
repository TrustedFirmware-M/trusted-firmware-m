#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

import argparse
import os
import sys
from tfm_tools.c_macro import C_macro
from tfm_tools import c_include
from tfm_tools import arg_utils
from intelhex import bin2hex

def add_arguments(parser : argparse.ArgumentParser,
                  prefix : str = "",
                  required : bool = True,
                  ) -> None:

    arg_utils.add_prefixed_argument(parser, "image_layout_h_file", help="path to region_defs.h", required=True)
    arg_utils.add_prefixed_argument(parser, "file_to_mirror", help="path to mirror file", required=True)
    arg_utils.add_prefixed_argument(parser, "compile_commands_file", help="path to compile_commands.json", required=True)
    arg_utils.add_prefixed_argument(parser, "macro_name", help="macro name to evaluate", required=True)
    arg_utils.add_prefixed_argument(parser, "input_binary_file", help="path to the input binary", required=True)
    arg_utils.add_prefixed_argument(parser, "output_hex_file", help="path to output hex", required=True)
    arg_utils.add_prefixed_argument(parser, "bl2_header_excluded", help="bl2_header excluded from the address the macro store", default=False, action=argparse.BooleanOptionalAction)

def main(args : list = []) -> None:
    parser = argparse.ArgumentParser(allow_abbrev=False,
                                        formatter_class=argparse.ArgumentDefaultsHelpFormatter,
                                        description="Hex generator")

    add_arguments(parser, "", True)

    args = parser.parse_args()

    paths = args.file_to_mirror.split(";")
    mirror_filename = os.path.basename(paths[0])

    includes = c_include.get_includes(args.compile_commands_file, mirror_filename)
    defines = c_include.get_defines(args.compile_commands_file, mirror_filename)

    config = C_macro.from_h_file(args.image_layout_h_file, includes, defines)

    try:
        address = int(config._definitions[args.macro_name])
        if(args.bl2_header_excluded):
            address = address - int(config._definitions["BL2_HEADER_SIZE"])
    except KeyError:
        address = 0
        print("Macro (%s) did not find. Using offset 0 for hex generation." % (args.macro_name))
    except Exception as e:
        print(e)
        sys.exit(1)

    sys.exit(bin2hex(args.input_binary_file, args.output_hex_file, address))

if __name__ == "__main__":
    main(sys.argv)
