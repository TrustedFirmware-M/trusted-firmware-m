#!/usr/bin/env python3
#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

import argparse
import sys
import os

import arg_utils

import logging
logger = logging.getLogger("TF-M.{}".format(__name__))

sys.path.append(os.path.join(sys.path[0], 'modules'))

import create_cm_provisioning_bundle
import create_dm_provisioning_bundle

import otp_config as oc
from otp_config import OTP_config

import provisioning_message_config as pmc
from provisioning_message_config import Provisioning_message_config

import provisioning_config as pc
from provisioning_config import Provisioning_config


def add_arguments(parser : argparse.ArgumentParser,
                  prefix : str = "",
                  required : bool = True,
                  ) -> None:
    create_cm_provisioning_bundle.add_arguments(parser, prefix, required)
    create_dm_provisioning_bundle.add_arguments(parser, prefix, required)

def parse_args(args : argparse.Namespace,
               prefix : str = "",
               ) -> dict:
    out = {}
    out |= create_cm_provisioning_bundle.parse_args(args, prefix)
    out |= create_dm_provisioning_bundle.parse_args(args, prefix)

    return out


script_description = """
This script takes as various config files, and produces from them and input
arguments corresponding to the fields of the combined provisioning bundle, and
produces a signed combined provisioning bundle which can be input into the RSE for
provisioning CM and DM data
"""
if __name__ == "__main__":
    from provisioning_message_config import create_blob_message

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

    logger.debug(kwargs['provisioning_config'].cm_layout)
    logger.debug(kwargs['provisioning_config'].dm_layout)

    blob_type = kwargs['provisioning_message_config'].RSE_PROVISIONING_BLOB_TYPE_COMBINED_LCS_PROVISIONING

    with open(args.bundle_output_file, "wb") as f:
        message = create_blob_message(blob_type=blob_type, **kwargs,
                                      secret_values =
                                      kwargs['provisioning_config'].cm_layout.to_bytes()
                                      + kwargs['provisioning_config'].dm_layout.to_bytes())
        f.write(message)
