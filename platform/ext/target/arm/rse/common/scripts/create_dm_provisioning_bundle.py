#!/usr/bin/env python3
#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

import sys
import argparse
from tfm_tools import arg_utils

import logging
logger = logging.getLogger("TF-M.{}".format(__name__))

import rse.otp_config as oc
from rse.otp_config import OTP_config

import rse.provisioning_message_config as pmc
from rse.provisioning_message_config import Provisioning_message_config

import rse.provisioning_config as pc
from rse.provisioning_config import Provisioning_config

import rse.routing_tables as rt
from rse.routing_tables import Routing_tables


def add_arguments(parser : argparse.ArgumentParser,
                  prefix : str = "",
                  required : bool = True,
                  ) -> None:
    oc.add_arguments(parser, prefix, required)
    rt.add_arguments(parser, prefix, required=False)
    pc.add_arguments(parser, prefix, required, regions=["non_secret_dm", "secret_dm"])
    pmc.add_arguments(parser, prefix, required,
                      message_type="RSE_PROVISIONING_MESSAGE_TYPE_BLOB")

    arg_utils.add_prefixed_argument(parser, "provisioning_code_elf", prefix, help="provisioning code image elf file",
                                            type=arg_utils.arg_type_elf_section(["CODE", "DATA"]), required=True)
    arg_utils.add_prefixed_argument(parser, "routing_tables_idx", prefix,
                                    help="The index within the system wide routing table to add to the provisioning bundle",
                                    type=int, required=False)

def parse_args(args : argparse.Namespace,
               prefix : str = "",
               default_field_owner : str = "dm"
               ) -> dict:
    out = {}
    out |= dict(zip(["code", "elf_data"], arg_utils.get_arg(args, "provisioning_code_elf", prefix)))
    out |= arg_utils.parse_args_automatically(args, ["routing_tables_idx"], prefix)

    out |= oc.parse_args(args, prefix=prefix)
    out |= rt.parse_args(args, prefix=prefix)
    out |= pc.parse_args(args, prefix=prefix, otp_config = out["otp_config"])
    out |= pmc.parse_args(args, prefix=prefix)

    return out

script_description = """
This script takes as various config files, and produces from them and input
arguments corresponding to the fields of the DM provisioning bundle, and
produces a signed DM provisioning bundle which can be input into the RSE for
provisioning DM data
"""
def main():
    parser = argparse.ArgumentParser(allow_abbrev=False,
                                     formatter_class=argparse.ArgumentDefaultsHelpFormatter,
                                     description=script_description)

    add_arguments(parser)

    parser.add_argument("--bundle_output_file",    help="bundle output file", required=True)
    parser.add_argument("--log_level", help="log level", required=False, default="ERROR", choices=logging._levelToName.values())

    args = parser.parse_args()
    logging.getLogger("TF-M").setLevel(args.log_level)
    logger.addHandler(logging.StreamHandler())

    kwargs = parse_args(args)

    kwargs['otp_config'].set_dm_offsets_automatically()
    kwargs['provisioning_config'].set_area_infos_from_otp_config(**kwargs)
    if 'routing_tables_idx' in kwargs:
        assert 'routing_tables' in kwargs
        kwargs['provisioning_config'].set_routing_tables(kwargs['routing_tables_idx'],kwargs['routing_tables'])

    logger.debug(kwargs['provisioning_config'].non_secret_dm_layout)
    logger.debug(kwargs['provisioning_config'].secret_dm_layout)

    blob_type = kwargs['provisioning_message_config'].RSE_PROVISIONING_BLOB_TYPE_SINGLE_LCS_PROVISIONING

    with open(args.bundle_output_file, "wb") as f:

        message = pmc.create_blob_message(blob_type=blob_type, **kwargs,
                                          data = (kwargs['elf_data'] or bytes(0)) +
                                          kwargs['provisioning_config'].non_secret_dm_layout.to_bytes(),
                                          secret_values = kwargs['provisioning_config'].secret_dm_layout.to_bytes())
        f.write(message)


if __name__ == "__main__":
    sys.exit(main())
