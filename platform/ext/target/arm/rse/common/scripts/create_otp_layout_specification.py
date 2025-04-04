#!/usr/bin/env python3
import argparse
import sys
import os
import re

import logging
logger = logging.getLogger("TF-M.{}".format(__name__))

from arg_utils import parse_args_automatically

sys.path.append(os.path.join(sys.path[0], 'modules'))

from otp_config import OTP_config
import otp_config as oc
import arg_utils

def add_arguments(parser : argparse.ArgumentParser,
                  prefix : str = "",
                  required : bool = True,
                  ) -> None:
    oc.add_arguments(parser)

def parse_args(args : argparse.Namespace,
               prefix : str = "",
               ) -> dict:
    return oc.parse_args(args, prefix)

def create_layout_specification(otp_config : OTP_config,
                                **kwargs : dict,
                               ):
    otp_config.set_cm_offsets_automatically(False);
    otp_config.set_dm_offsets_automatically();

    output = []

    offset_counter = 0
    for f in otp_config.header.get_field_strings():
        if "raw_data" in f:
            continue
        name = f.replace("header.", "")
        size = otp_config.header.get_field(name).get_size()
        output.append("{}, {}, {},\n".format(f, hex(offset_counter), hex(size)))
        offset_counter += size;

    region_names = ['cm', 'bl1_2', 'dm', 'dynamic', 'soc']

    for r in region_names:
        region = vars(otp_config)[r]
        offset_counter = otp_config.header.get_field(r + "_area_info.offset").get_value()
        for f in region.get_field_strings():
            # Remove anything which is a prefix (array slices usually)
            if [_ for _ in region.get_field_strings() if f in _ and f != _]:
                continue
            name = f.replace(r + ".", "")
            size = region.get_field(name).get_size()
            output.append("{}, {}, {},\n".format(f, hex(offset_counter), hex(size)))
            offset_counter += size;

    return output

script_description = """
This script takes as input an OTP config file, and outputs an OTP layout table
in CSV format which can be used to generate documentation.
"""
if __name__ == "__main__":
    parser = argparse.ArgumentParser(allow_abbrev=False)

    parser = argparse.ArgumentParser(allow_abbrev=False,
                                     formatter_class=argparse.ArgumentDefaultsHelpFormatter,
                                     description=script_description)

    add_arguments(parser)
    parser.add_argument("--specification_output_file", help="File to output spec to",
                        required=True, type=arg_utils.arg_type_text_output_file)

    args = parser.parse_args()
    config = parse_args(args)

    layout_specification = create_layout_specification(**config)

    args.specification_output_file.writelines(layout_specification)
