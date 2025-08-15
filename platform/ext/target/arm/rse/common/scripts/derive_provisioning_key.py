#!/usr/bin/env python3
#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

import sys
import argparse

from tfm_tools.arg_utils import arg_type_bytes, arg_type_bytes_output_file

from tfm_tools.key_derivation import derive_symmetric_key

def main():
    parser = argparse.ArgumentParser(allow_abbrev=False)
    parser.add_argument("--kmaster", type=arg_type_bytes, help="KMASTER (input) in raw binary form", required=True)
    parser.add_argument("--key_owner", choices=["CM", "DM"], help="Owner of master key to derive", required=True)

    parser.add_argument("--kprov_file", type=arg_type_bytes_output_file, help="KPROV (output) file", required=True)

    args = parser.parse_args()

    kprov = derive_symmetric_key(args.kmaster, bytes(0), "KPROV_" + args.key_owner, 32)
    args.kprov_file.write(kprov)


if __name__ == "__main__":
    sys.exit(main())
