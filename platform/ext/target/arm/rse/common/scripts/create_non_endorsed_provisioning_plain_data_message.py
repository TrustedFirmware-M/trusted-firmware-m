#!/usr/bin/env python3
# -------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
# -------------------------------------------------------------------------------

import argparse
import sys
import os
import logging
logger = logging.getLogger("TF-M.{}".format(__name__))

from rse.provisioning_config import Provisioning_config
import rse.provisioning_config as pc
from rse.provisioning_message_config import Provisioning_message_config
import rse.provisioning_message_config as pmc
from rse.otp_config import OTP_config
import rse.otp_config as oc
from tfm_tools import arg_utils


def add_arguments(parser: argparse.ArgumentParser,
                  prefix: str = "",
                  required: bool = True,
                  ) -> None:
    oc.add_arguments(parser, prefix, required)
    pc.add_arguments(parser, prefix, required, regions=["non_endorsed_dm"])
    pmc.add_arguments(parser, prefix, required,
                      message_type="RSE_PROVISIONING_MESSAGE_TYPE_PLAIN_DATA")


def parse_args(args: argparse.Namespace,
               prefix: str = "",
               ) -> dict:
    out = {}

    out |= oc.parse_args(args, prefix=prefix)
    out |= pc.parse_args(args, prefix=prefix, otp_config=out["otp_config"])
    out |= pmc.parse_args(args, prefix=prefix)

    return out


script_description = """
This script takes as arguments various config files and input
arguments corresponding to the fields of the non-endorsed DM provisioning
values structure. It uses these to produce a plain data message
"""
def main():
    parser = argparse.ArgumentParser(allow_abbrev=False,
                                     formatter_class=argparse.ArgumentDefaultsHelpFormatter,
                                     description=script_description)

    add_arguments(parser)

    parser.add_argument("--output_file", help="bundle output file", required=True)
    parser.add_argument("--log_level", help="log level", required=False, default="ERROR", choices=logging._levelToName.values())

    args = parser.parse_args()
    logging.getLogger("TF-M").setLevel(args.log_level)
    logger.addHandler(logging.StreamHandler())

    kwargs = parse_args(args)

    with open(args.output_file, "wb") as f:
        message = pmc.create_plain_data_message(**kwargs,
                                            plain_data_type=kwargs['provisioning_message_config'].RSE_PROVISIONING_PLAIN_DATA_TYPE_NON_ENDORSED_DM_ROTPKS,
                                            data=kwargs['provisioning_config'].non_endorsed_dm_layout.to_bytes())
        f.write(message)


if __name__ == "__main__":
    sys.exit(main())
