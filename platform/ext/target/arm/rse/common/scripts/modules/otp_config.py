#!/usr/bin/env python3
#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

from tfm_tools.c_struct import C_struct, C_array
from tfm_tools.c_macro import C_macro
from tfm_tools import c_include
from tfm_tools import arg_utils
import pickle
import sys
import argparse

import logging
logger = logging.getLogger("TF-M.{}".format(__name__))

region_names = ['header', 'cm', 'bl1_2', 'dm', 'soc', 'dynamic']

def add_arguments(parser : argparse.ArgumentParser,
                  prefix : str = "",
                  required : bool = True,
                  ) -> None:

    arg_utils.add_prefixed_argument(parser, "otp_image_input", help="binary file of OTP image to import",
                                            type=arg_utils.arg_type_bytes, required=False)

    arg_utils.add_prefixed_argument(parser, "otp_image_output_file", help="file to export binary OTP image to",
                                            type=arg_utils.arg_type_bytes_output_file, required=False)

    arg_utils.add_prefixed_argument(parser, "otp_config_output_file", help="Path to output otp config file",
                                            type=arg_utils.arg_type_bytes_input_file, required=False)

    return arg_utils.pre_parse_args(parser, "otp_config", help="Path to input otp config file",
                                            type=OTP_config.from_config_file)


def parse_args(args : argparse.Namespace,
               prefix : str = "",
               ) -> dict:
    out = {}

    if "otp_config" not in out.keys():
        out |= arg_utils.parse_args_automatically(args, ["otp_config"], prefix)

    if otp_image := arg_utils.get_arg(args, "otp_image_input", prefix):
        out[otp_config].set_value_from_bytes(otp_image)

    out |= arg_utils.parse_args_automatically(args, "otp_config_output_file", prefix)

    return out

class OTP_config:
    def __init__(self, header, cm, bl1_2, dm, dynamic, soc, defines):
        self.header = header
        self.cm = cm
        self.bl1_2 = bl1_2
        self.dm = dm
        self.dynamic = dynamic
        self.soc = soc
        self.defines = defines
        self.defines._definitions = {k:v for k,v in self.defines._definitions.items() if not callable(v)}
        self.defines.__dict__ = {k:v for k,v in self.defines.__dict__.items() if not callable(v)}
        self.__dict__ |= self.defines._definitions

    @staticmethod
    def from_h_file(h_file_path, includes, defines):
        make_region = lambda x: C_struct.from_h_file(h_file_path,
                                                              "rse_otp_{}_area_t".format(x),
                                                              includes, defines)
        regions = [make_region(x) for x in region_names]

        for r,n in zip(regions, region_names):
            r.name = n

        regions = {r.name: r for r in regions}

        config = C_macro.from_h_file(h_file_path, includes, defines)

        return OTP_config(defines=config, **regions)

    @staticmethod
    def from_config_file(file):

        if type(file) == str:
            file = arg_utils.arg_type_bytes_input_file(file)

        return pickle.load(file)

    def __str__(self):
        out = ""
        for r in region_names:
            out += str(getattr(self, r)) + "\n\n"
        return out[:-2]

    def set_cm_offsets_automatically(self,
                                     dm_sets_dm_and_dynamic_area_size : bool = None
                                     ):
        offset_counter = 0
        if dm_sets_dm_and_dynamic_area_size is None:
            dm_sets_dm_and_dynamic_area_size = hasattr(self, "DM_SETS_DM_AND_DYNAMIC_AREA_SIZE")

        offset_counter += self.header.get_size()
        assert (offset_counter % 4) == 0, "Header area size {} not aligned to 4 byte boundary".format(offset_counter)
        self.header.cm_area_info.offset.set_value(offset_counter)
        self.header.cm_area_info.size.set_value(self.cm.get_size())

        offset_counter += self.cm.get_size()
        assert (offset_counter % 4) == 0, "CM area size {} not aligned to 4 byte boundary".format(offset_counter)
        self.header.bl1_2_area_info.offset.set_value(offset_counter)
        self.header.bl1_2_area_info.size.set_value(self.bl1_2.get_size())

        soc_area_size = self.soc.get_size()
        otp_size = int(self.RSE_OTP_SIZE)
        assert (soc_area_size % 4) == 0, "SOC area size {} not aligned to 4 byte boundary".format(soc_area_size)
        self.header.soc_area_info.offset.set_value(otp_size - soc_area_size)
        self.header.soc_area_info.size.set_value(soc_area_size)

        if not dm_sets_dm_and_dynamic_area_size:
            offset_counter += self.bl1_2.get_size()
            assert (offset_counter % 4) == 0, "Bl1_2 area size {} not aligned to 4 byte boundary".format(offset_counter)
            self.header.dm_area_info.offset.set_value(offset_counter)
            self.header.dm_area_info.size.set_value(self.dm.get_size())

            offset_counter += self.dm.get_size()
            assert (offset_counter % 4) == 0, "DM area size {} not aligned to 4 byte boundary".format(offset_counter)
            soc_area_offset = self.header.soc_area_info.offset.get_value()
            self.header.dynamic_area_info.offset.set_value(offset_counter)
            assert offset_counter + self.dynamic.get_size() <= soc_area_offset, "Memory layout overflows OTP size {} > {}, shortfall is {}".format(hex(offset_counter), hex(soc_area_offset), hex(offset_counter - soc_area_offset))
            self.header.dynamic_area_info.size.set_value(soc_area_offset - offset_counter)

    def set_dm_offsets_automatically(self):
        self.set_cm_offsets_automatically(False)

    def to_config_file(self, file):

        if type(file) == str:
            file = arg_utils.arg_type_bytes_output_file(file)

        pickle.dump(self, file)

    def set_value_from_bytes(self, b):
        self.header.set_value_from_bytes(b[:self.header._size])

        for r in region_names[1:-1]:
            offset = getattr(self.header, "{}_area_info".format(r)).offset.get_value()
            size = getattr(self.header, "{}_area_info".format(r)).size.get_value()

            if (offset and size):
                getattr(self, r).set_value_from_bytes(b[offset:offset + size])

        offset = self.header.dynamic_area_info.offset.get_value()
        self.dynamic.set_value_from_bytes(b[offset:offset+self.dynamic._size])

    def to_bytes(self):
        b = self.header.to_bytes()
        b += bytes(16384 - len(b))
        b = bytearray(b)

        for r in region_names[1:]:
            offset = getattr(self.header, "{}_area_info".format(r)).offset.get_value()
            size = getattr(self.header, "{}_area_info".format(r)).size.get_value()

            if (offset and size):
                b[offset:offset + size] = getattr(self, r).to_bytes()

        return b

def add_field_args(otp_config : OTP_config, parser):
    regions = [getattr(otp_config, x) for x in region_names]
    for r,r_name in zip(regions, region_names):
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
                                                    metavar="<path or hex>", type=arg_type, required=False)

def set_from_field_args(otp_config : OTP_config, parser):
    for k,v in vars(parser).items():
        if ":" not in k or v is None:
            continue

        prefix, path = k.split(":", 1)
        assert prefix in region_names

        getattr(otp_config, prefix).get_field(path).set_value(v)

script_description = """
This script takes an instance of rse_otp_layout.h and a set of definitions
(extracted from compile_commands.json), and creates a config file which
corresponds to the OTP layout defined by those two, which can then be used to
create binary OTP images, or to allow other scripts to access the OTP
configuration options.
"""
if __name__ == "__main__":
    import argparse

    parser = argparse.ArgumentParser(allow_abbrev=False,
                                     formatter_class=argparse.ArgumentDefaultsHelpFormatter,
                                     description=script_description)
    parser.add_argument("--rse_otp_layout_h_file", help="path to rse_otp_layout.h", required=False)
    parser.add_argument("--compile_commands_file", help="path to compile_commands.json", required=False)
    parser.add_argument("--log_level", help="log level", required=False, default="ERROR", choices=logging._levelToName.values())
    parser.add_argument("--otp_image_input", help="binary file of OTP image to import",
                        type=arg_utils.arg_type_bytes, required=False)
    parser.add_argument("--otp_image_output_file", help="file to export binary OTP image to",
                        type=arg_utils.arg_type_bytes_output_file, required=False)
    parser.add_argument("--otp_config_output_file", help="Path to output otp config file",
                        type=arg_utils.arg_type_bytes_output_file, required=False)

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
        includes = c_include.get_includes(args.compile_commands_file, "otp_lcm.c")
        defines = c_include.get_defines(args.compile_commands_file, "otp_lcm.c")

        otp_config = OTP_config.from_h_file(args.rse_otp_layout_h_file, includes, defines)

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
