#-------------------------------------------------------------------------------
# Copyright (c) 2024, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

import argparse
from cryptography.hazmat.primitives import cmac
from tfm_tools.struct_pack import struct_pack
from provisioning_common_utils import *

def derive_encryption_key(input_key, provisioning_lcs, tp_mode, reprovisioning_bits,
                          bl1_2_hash, krtl_derivation_label):
    # Every element of the boot state is 0
    boot_state = struct_pack([
        tp_mode.to_bytes(4, byteorder='little'),
        provisioning_lcs.to_bytes(4, byteorder='little'),
        reprovisioning_bits.to_bytes(4, byteorder='little'),
        bl1_2_hash.to_bytes(32, byteorder='little'),
    ])
    hash = hashlib.sha256()
    hash.update(boot_state)
    context = hash.digest()

    state = struct_pack([krtl_derivation_label.encode('ascii') + bytes(1),
                         bytes(1), context,
                         (32).to_bytes(4, byteorder='little')])
    c = cmac.CMAC(algorithms.AES(input_key))
    c.update(state)
    k0 = c.finalize()

    output_key = bytes(0);
    # The KDF outputs 16 bytes per iteration, so we need 2 for an AES-256 key
    for i in range(2):
        state = struct_pack([(i + 1).to_bytes(4, byteorder='little'),
                             # C keeps the null byte, python removes it, so we add
                             # it back manually.
                             krtl_derivation_label.encode('ascii') + bytes(1),
                             bytes(1), context,
                             (32).to_bytes(4, byteorder='little'),
                             k0])
        c = cmac.CMAC(algorithms.AES(input_key))
        c.update(state)
        output_key += c.finalize()
    return output_key

parser = argparse.ArgumentParser(allow_abbrev=False)
parser.add_argument("--tp_mode", help="the test or production mode", choices=["TCI", "PCI"], required=True)
parser.add_argument("--krtl_file", help="the RTL key file", required=True)
parser.add_argument("--key_select", help="Which key to derive", choices=["cm", "dm"], required=True)
parser.add_argument("--output_key_file", help="key output file", required=True)
args = parser.parse_args()

if args.tp_mode == "TCI":
    tp_mode = 0x111155AA
elif args.tp_mode == "PCI":
    tp_mode = 0x2222AA55

reprovisioning_bits = 0
bl1_2_hash = 0

with open(args.krtl_file, "rb") as in_file:
    input_key = in_file.read()

if args.key_select == "cm":
    output_key = derive_encryption_key(input_key, 0, tp_mode, reprovisioning_bits,
                                       bl1_2_hash, "CM_PROVISIONING")
elif args.key_select == "dm":
    output_key = derive_encryption_key(input_key, 1, tp_mode, reprovisioning_bits,
                                       bl1_2_hash, "DM_PROVISIONING")

with open(args.output_key_file, "wb") as out_file:
    out_file.write(output_key)
