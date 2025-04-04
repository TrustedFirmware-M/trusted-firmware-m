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
import argparse
import arg_utils

import logging
logger = logging.getLogger("TF-M.{}".format(__name__))

def add_arguments(parser : argparse.ArgumentParser,
                  prefix : str = "",
                  required : bool = True,
                  ) -> None:

    arg_utils.add_prefixed_argument(parser, "otp_image_input", help="binary file of OTP image to import",
                                            type=arg_utils.arg_type_bytes, required=False);

    arg_utils.add_prefixed_argument(parser, "otp_image_output_file", help="file to export binary OTP image to",
                                            type=arg_utils.arg_type_bytes_output_file, required=False);

    return arg_utils.pre_parse_args(parser, "otp_config", help="Path to otp config file",
                                             type=OTP_config.from_config_file)


def parse_args(args : argparse.Namespace,
               prefix : str = "",
               ) -> dict:
    out = {}

    if "otp_config" not in out.keys():
        out |= arg_utils.parse_args_automatically(args, ["otp_config"], prefix)

    if otp_image := arg_utils.get_arg(args, "otp_image_input", prefix):
        out[otp_config].set_value_from_bytes(otp_image)

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
        region_names = ['header', 'cm', 'bl1_2', 'dm', 'dynamic', 'soc']

        make_region = lambda x: c_struct.C_struct.from_h_file(h_file_path,
                                                              "rse_otp_{}_area_t".format(x),
                                                              includes, defines)
        regions = [make_region(x) for x in region_names]

        for r,n in zip(regions, region_names):
            r.name = n

        config = c_macro.C_macro.from_h_file(h_file_path, includes, defines)

        return OTP_config(*regions, config)

    @staticmethod
    def from_config_file(file_path):
        with open(file_path, "rb") as f:
            return pickle.load(f)

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

    def to_config_file(self, file_path):
        with open(file_path, "wb") as f:
            pickle.dump(self, f)

    def set_value_from_bytes(self, b):
        self.header.set_value_from_bytes(b[:self.header._size])

        for r in self_regions[1:]:
            offset = getattr(self.header, "{}_area_info".format(r)).offset.get_value()
            size = getattr(self.header, "{}_area_info".format(r)).size.get_value()

            if (offset and size):
                getattr(self, x).set_value_from_bytes(b[offset:offset + size])

    def to_bytes(self):
        b = self.header.to_bytes()
        b += bytes(16384 - len(b))
        b = bytearray(b)

        for r in self_regions[1:]:
            offset = getattr(self.header, "{}_area_info".format(r)).offset.get_value()
            size = getattr(self.header, "{}_area_info".format(r)).size.get_value()

            if (offset and size):
                b[offset:offset + size] = getattr(self, x).to_bytes()

        return b

script_description = """
This script takes an instance of rse_otp_layout.h and a set of definitions
(extracted from compile_commands.json), and creates a config file which
corresponds to the OTP layout defined by those two, which can then be used to
create binary OTP images, or to allow other scripts to access the OTP
configuration options.
"""
if __name__ == "__main__":
    import argparse
    import c_include

    parser = argparse.ArgumentParser(allow_abbrev=False,
                                     formatter_class=argparse.ArgumentDefaultsHelpFormatter,
                                     description=script_description)
    parser.add_argument("--rse_otp_layout_h_file", help="path to rse_otp_layout.h", required=True)
    parser.add_argument("--compile_commands_file", help="path to compile_commands.json", required=True)
    parser.add_argument("--otp_config_output_file", help="file to output otp config to", required=True)
    parser.add_argument("--log_level", help="log level", required=False, default="ERROR", choices=logging._levelToName.values())

    args = parser.parse_args()
    logging.getLogger("TF-M").setLevel(args.log_level)
    logger.addHandler(logging.StreamHandler())

    includes = c_include.get_includes(args.compile_commands_file, "otp_lcm.c")
    defines = c_include.get_defines(args.compile_commands_file, "otp_lcm.c")

    otp_config = OTP_config.from_h_file(args.rse_otp_layout_h_file, includes, defines)

    otp_config.to_config_file(args.otp_config_output_file)
