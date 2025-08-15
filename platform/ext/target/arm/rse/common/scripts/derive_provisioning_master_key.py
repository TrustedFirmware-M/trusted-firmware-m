#!/usr/bin/env python3
#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

import sys
import argparse
from tfm_tools.arg_utils import pre_parse_args, arg_type_bytes, arg_type_bytes_output_file
from tfm_tools.key_derivation import derive_symmetric_key


def main():
    lcses = ["CM", "DM"]
    parser = argparse.ArgumentParser(allow_abbrev=False)
    parser.add_argument("--krtl", type=arg_type_bytes, help="KRTL (input) in raw binary form", required=True)

    key_owner = pre_parse_args(parser, name="key_owner", choices=lcses, help="Owner of master key to derive")

    if key_owner == "CM":
        parser.add_argument("--batch_number", type=int, help="Hardware batch number", required=True)
    else:
        parser.add_argument("--dm_number", type=int, help="Number of the DM", required=True)

    parser.add_argument("--kmaster_file", type=arg_type_bytes_output_file, help="KMASTER (output) file", required=True)

    args = parser.parse_args()

    if key_owner == "CM":
        context = args.batch_number
    else:
        context = args.dm_number

    context = context.to_bytes(4, 'little')

    kmaster = derive_symmetric_key(args.krtl, context, "KMASTER_" + args.key_owner, 32)
    args.kmaster_file.write(kmaster)

if __name__ == "__main__":
    sys.exit(main())
