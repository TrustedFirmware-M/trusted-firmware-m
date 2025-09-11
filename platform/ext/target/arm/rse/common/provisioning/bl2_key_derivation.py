#-------------------------------------------------------------------------------
# Copyright (c) 2025, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

import argparse
from cryptography.hazmat.primitives import hashes
from tfm_tools.key_derivation import derive_symmetric_key
import base64

parser = argparse.ArgumentParser(allow_abbrev=False)
parser.add_argument("--key_file", help="the key file be the source of derivation", required=True)
parser.add_argument("--key_select", help="Which key to derive", choices=["kce:cm", "kce:dm"], required=True)
parser.add_argument("--tp_mode", help="the test or production mode", choices=["TCI", "PCI"], required=True)
parser.add_argument("--output_key_file", help="key output file", required=True)
args = parser.parse_args()

if args.tp_mode == "TCI":
    tp_mode = "0x111155AA"
elif args.tp_mode == "PCI":
    tp_mode = "0x2222AA55"

reprovisioning_bits = "0x00000000"

with open(args.key_file, "rb") as in_file:
    input_key = in_file.read()

digest = hashes.Hash(hashes.SHA256())
digest.update(int(tp_mode, 16).to_bytes(4, 'little'))
digest.update(int(reprovisioning_bits, 16).to_bytes(4, 'little'))
data_hash = digest.finalize()

if args.key_select == "kce:cm":
    label = "RUNTIME_SECURE_ENCRYPTION_KEY"
elif args.key_select == "kce:dm":
    label = "RUNTIME_NON_SECURE_ENCRYPTION_KEY"

output_key = derive_symmetric_key(input_key, bytes(data_hash), label, 32)
encoded_key = "AES-KW:" + base64.b64encode(output_key).decode('utf-8')

with open(args.output_key_file, "w") as out_file:
    out_file.write(encoded_key)
