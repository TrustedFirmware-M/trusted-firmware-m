#!/usr/bin/env python3
#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

import argparse
from tfm_tools import arg_utils
import sys

import logging
logger = logging.getLogger("TF-M.{}".format(__name__))

import rse_scripts.create_cm_provisioning_bundle as cmpb
import rse_scripts.create_dm_provisioning_bundle as dmpb

from rse.otp_config import OTP_config

import rse.provisioning_message_config as pmc
from rse.provisioning_message_config import Provisioning_message_config

from rse.provisioning_config import Provisioning_config

from rse.routing_tables import Routing_tables


def add_arguments(parser : argparse.ArgumentParser,
                  prefix : str = "",
                  required : bool = True,
                  ) -> None:
    cmpb.add_arguments(parser, prefix, required)
    dmpb.add_arguments(parser, prefix, required)

def parse_args(args : argparse.Namespace,
               prefix : str = "",
               ) -> dict:
    out = {}
    out |= cmpb.parse_args(args, prefix)
    out |= dmpb.parse_args(args, prefix)

    return out

script_description = """
This script takes as various config files, and produces from them and input
arguments corresponding to the fields of the combined provisioning bundle, and
produces a signed combined provisioning bundle which can be input into the RSE for
provisioning CM and DM data
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

    kwargs['otp_config'].set_cm_offsets_automatically()
    kwargs['otp_config'].set_dm_offsets_automatically()
    kwargs['provisioning_config'].set_area_infos_from_otp_config(**kwargs)
    if 'routing_tables_idx' in kwargs:
        assert 'routing_tables' in kwargs
        kwargs['provisioning_config'].set_routing_tables(kwargs['routing_tables_idx'],kwargs['routing_tables'])

    logger.debug(kwargs['provisioning_config'].non_secret_cm_layout)
    logger.debug(kwargs['provisioning_config'].secret_cm_layout)
    logger.debug(kwargs['provisioning_config'].non_secret_dm_layout)
    logger.debug(kwargs['provisioning_config'].secret_dm_layout)

    blob_type = kwargs['provisioning_message_config'].RSE_PROVISIONING_BLOB_TYPE_COMBINED_LCS_PROVISIONING

    with open(args.bundle_output_file, "wb") as f:

        message = pmc.create_blob_message(blob_type=blob_type, **kwargs,
                                          data = (kwargs['elf_data'] or bytes(0))+
                                          kwargs['provisioning_config'].non_secret_cm_layout.to_bytes() +
                                          kwargs['provisioning_config'].non_secret_dm_layout.to_bytes(),
                                          secret_values =
                                          kwargs['provisioning_config'].secret_cm_layout.to_bytes()
                                          + kwargs['provisioning_config'].secret_dm_layout.to_bytes())
        f.write(message)

if __name__ == "__main__":
    sys.exit(main())
