# -------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
# -------------------------------------------------------------------------------

import sys
import argparse

from tfm_tools.c_struct import C_struct, C_array
from tfm_tools.c_macro import C_macro
from tfm_tools import c_include
from tfm_tools import arg_utils

from rse.otp_config import OTP_config

import logging
logger = logging.getLogger("TF-M.{}".format(__name__))

region_names = ['header', 'cm', 'bl1_2', 'dm', 'soc', 'dynamic']


def add_arguments(parser: argparse.ArgumentParser,
                  prefix: str = "",
                  required: bool = True,
                  ) -> None:

    arg_utils.add_prefixed_argument(parser, "otp_image_input",
                                    help="binary file of OTP image to import",
                                    type=arg_utils.arg_type_bytes,
                                    required=False)

    arg_utils.add_prefixed_argument(parser, "otp_image_output_file",
                                    help="file to export binary OTP image to",
                                    type=arg_utils.arg_type_bytes_output_file,
                                    required=False)

    arg_utils.add_prefixed_argument(parser, "otp_config_output_file",
                                    help="Path to output otp config file",
                                    type=arg_utils.arg_type_bytes_input_file,
                                    required=False)

    return arg_utils.pre_parse_args(parser, "otp_config",
                                    help="Path to input otp config file",
                                    type=OTP_config.from_config_file)


def add_field_args(otp_config: OTP_config, parser):
    regions = [getattr(otp_config, x) for x in region_names]
    for r, r_name in zip(regions, region_names):
        optional_fields = []
        optional_fields += [f.split(".", 1)[1] for f in r.get_field_strings()]
        optional_fields = [f for f in optional_fields if "raw_data" not in f]

        for f in optional_fields:
            f_name = arg_utils.join_prefix(f, r_name)
            if isinstance(r.get_field(f), C_array):
                arg_type = arg_utils.arg_type_bytes
            else:
                arg_type = int

            arg_utils.add_prefixed_argument(parser, "{}".format(f_name), "",
                                            help="value to set {} to".format(f_name),
                                            metavar="<path or hex>",
                                            type=arg_type, required=False)


def set_from_field_args(otp_config: OTP_config, parser):
    for k, v in vars(parser).items():
        if ":" not in k or v is None:
            continue

        prefix, path = k.split(":", 1)
        assert prefix in region_names

        getattr(otp_config, prefix).get_field(path).set_value(v)


def parse_args(args: argparse.Namespace,
               prefix: str = "",
               ) -> dict:
    out = {}

    if "otp_config" not in out.keys():
        out |= arg_utils.parse_args_automatically(args, ["otp_config"], prefix)

    if otp_image := arg_utils.get_arg(args, "otp_image_input", prefix):
        out[otp_config].set_value_from_bytes(otp_image)

    out |= arg_utils.parse_args_automatically(
        args, "otp_config_output_file", prefix)

    return out


def main() -> None:
    parser = argparse.ArgumentParser(allow_abbrev=False,
                                     formatter_class=argparse.ArgumentDefaultsHelpFormatter,
                                     description=script_description)
    parser.add_argument("--rse_otp_layout_h_file",
                        help="path to rse_otp_layout.h",
                        required=False)

    parser.add_argument("--compile_commands_file",
                        help="path to compile_commands.json",
                        required=False)

    parser.add_argument("--log_level",
                        help="log level",
                        required=False, default="ERROR",
                        choices=logging._levelToName.values())

    parser.add_argument("--otp_image_input",
                        help="binary file of OTP image to import",
                        type=arg_utils.arg_type_bytes,
                        required=False)

    parser.add_argument("--otp_image_output_file",
                        help="file to export binary OTP image to",
                        type=arg_utils.arg_type_bytes_output_file,
                        required=False)

    parser.add_argument("--otp_config_output_file",
                        help="Path to output otp config file",
                        type=arg_utils.arg_type_bytes_output_file,
                        required=False)

    otp_config = arg_utils.pre_parse_args(parser, "otp_config",
                                          help="Path to input otp config file",
                                          type=OTP_config.from_config_file,
                                          required=False)

    if otp_config:
        add_field_args(otp_config, parser)

    args = parser.parse_args()
    logging.getLogger("TF-M").setLevel(args.log_level)
    logger.addHandler(logging.StreamHandler())

    if args.otp_config:
        otp_config = args.otp_config
    else:
        compiler = c_include.get_compiler(args.compile_commands_file, "otp_lcm.c")
        includes = c_include.get_includes(args.compile_commands_file, "otp_lcm.c")
        defines = c_include.get_defines(args.compile_commands_file, "otp_lcm.c")

        otp_config = OTP_config.from_h_file(args.rse_otp_layout_h_file, compiler, includes, defines)

    if args.otp_image_input:
        otp_config.set_value_from_bytes(args.otp_image_input)

    set_from_field_args(otp_config, args)

    logger.info(otp_config)

    if args.otp_config_output_file:
        otp_config.to_config_file(args.otp_config_output_file)

    if args.otp_image_output_file:
        args.otp_config_output_file.write(otp_config.to_bytes())

    if not (args.otp_config_output_file or args.otp_image_output_file):
        print(otp_config)

script_description = """
This script takes an instance of rse_otp_layout.h and a set of definitions
(extracted from compile_commands.json), and creates a config file which
corresponds to the OTP layout defined by those two, which can then be used to
create binary OTP images, or to allow other scripts to access the OTP
configuration options.
"""
if __name__ == "__main__":
    main()
