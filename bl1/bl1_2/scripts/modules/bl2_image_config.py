#!/usr/bin/env python3

#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

import c_struct
import c_macro
import c_include
import pickle
import sys
from enum import Enum
from arg_utils import pre_parse_args, parse_args_automatically
import argparse

def add_arguments(parser : argparse.ArgumentParser,
                  prefix : str = "",
                  required : bool = True,
                  ) -> None:
    return pre_parse_args(parser, "bl2_image_config",
                                  help="Path to bl2_image config file",
                                  type=BL2_image_config.from_config_file)

def parse_args(args : argparse.Namespace,
               prefix : str = "",
               ) -> dict:
    return parse_args_automatically(args, ["bl2_image_config"], prefix)

class BL2_image_config:
    def __init__(self, image, defines):
        self.image = image
        self.defines = defines
        self.defines._definitions = {k:v for k,v in self.defines._definitions.items() if not callable(v)}
        self.defines.__dict__ = {k:v for k,v in self.defines.__dict__.items() if not callable(v)}
        self.__dict__.update( self.defines._definitions)

    @staticmethod
    def from_h_file(h_file_path, includes, defines):
        image = c_struct.C_struct.from_h_file(h_file_path,
                                              'bl1_2_image_t',
                                              includes, defines)

        config = c_macro.C_macro.from_h_file(h_file_path, includes, defines)

        return BL2_image_config(image, config)

    @staticmethod
    def from_config_file(file_path):
        with open(file_path, "rb") as f:
            return pickle.load(f)

    def to_config_file(self, file_path):
        with open(file_path, "wb") as f:
            pickle.dump(self, f)

script_description = """
This script takes an instance of image_layout_bl1_2.h and a set of definitions
(extracted from compile_commands.json), and creates a config file which
corresponds to the BL2 image defined by those two, which can then be used as a
template to create a binary image of BL2.
"""
if __name__ == "__main__":
    import argparse
    import c_include

    parser = argparse.ArgumentParser(allow_abbrev=False,
                                     formatter_class=argparse.ArgumentDefaultsHelpFormatter,
                                     description=script_description)
    parser.add_argument("--bl2_image_layout_h_file", help="path to image_layout_bl1_2.h", required=True)
    parser.add_argument("--compile_commands_file", help="path to compile_commands.json", required=True)
    parser.add_argument("--bl2_image_config_output_file", help="file to output bl2 image config to", required=True)
    args = parser.parse_args()

    includes = c_include.get_includes(args.compile_commands_file, "bl1_2/main.c")
    defines = c_include.get_defines(args.compile_commands_file, "bl1_2/main.c")

    bl2_image_config = BL2_image_config.from_h_file(args.bl2_image_layout_h_file,
                                                    includes, defines)

    bl2_image_config.to_config_file(args.bl2_image_config_output_file)
