#-------------------------------------------------------------------------------
# Copyright (c) 2021-2024, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

import hashlib
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.primitives import cmac
from cryptography.hazmat.primitives.kdf.hkdf import HKDF
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.backends import default_backend
import secrets
import argparse
import os
import sys
sys.path.append(os.path.join(os.path.dirname(os.path.realpath(__file__)), "../../../bl2/ext/mcuboot/scripts"))
import macro_parser
import struct
import pyhsslms

def struct_pack(objects, pad_to=0):
    defstring = "<"
    for obj in objects:
        defstring += str(len(obj)) + "s"

    size = struct.calcsize(defstring)
    if size < pad_to:
        defstring += str(pad_to - size) + "x"

    return (bytes(struct.pack(defstring, *objects)))

def parse_version(version_string):
    version = [0, 0, 0, 0]
    split = version_string.split("+")
    if len(split) > 1:
        version[3] = int(split[1])
    split = split[0].split(".")
    for i in range(len(split)):
        version[i] = int(split[i])

    return struct_pack([version[0].to_bytes(1, "little"),
                        version[1].to_bytes(1, "little"),
                        version[2].to_bytes(2, "little"),
                        version[3].to_bytes(4, "little")])

def derive_encryption_key_cmac(security_counter):
    with open(args.encrypt_key_file, "rb") as encrypt_key_file:
        encrypt_key = encrypt_key_file.read()

    state = struct_pack(["BL2_DECRYPTION_KEY".encode('ascii') + bytes(1),
                         bytes(1), security_counter,
                         (32).to_bytes(4, byteorder='little')])
    c = cmac.CMAC(algorithms.AES(encrypt_key))
    c.update(state)
    k0 = c.finalize()

    output_key = bytes(0);
    # The KDF outputs 16 bytes per iteration, so we need 2 for an AES-256 key
    for i in range(2):
        state = struct_pack([(i + 1).to_bytes(4, byteorder='little'),
                             # C keeps the null byte, python removes it, so we add
                             # it back manually.
                             "BL2_DECRYPTION_KEY".encode('ascii') + bytes(1),
                             bytes(1), security_counter,
                             (32).to_bytes(4, byteorder='little'),
                             k0])
        c = cmac.CMAC(algorithms.AES(encrypt_key))
        c.update(state)
        output_key += c.finalize()
    return output_key

def derive_encryption_key_hkdf(security_counter):
    with open(args.encrypt_key_file, "rb") as encrypt_key_file:
        encrypt_key = encrypt_key_file.read()

    state = struct_pack([
                        # C keeps the null byte, python removes it, so we add
                        # it back manually.
                        "BL2_DECRYPTION_KEY".encode('ascii') + bytes(1),
                        security_counter
                        ])

    output_key = bytes(0)
    hkdf = HKDF(
        algorithm=hashes.SHA256(),
        length=32,
        salt=None,
        info=state
    )
    output_key = hkdf.derive(encrypt_key)

    return output_key

def sign_binary_blob(blob):
    priv_key = pyhsslms.HssLmsPrivateKey(args.sign_key_file)
    # Remove the first 4 bytes since it's HSS info
    sig = priv_key.sign(blob)[4:]
    if (len(sig) != 1452):
        raise Exception
    return sig

def hash_binary_blob(blob):
   hash = hashlib.sha256()
   hash.update(blob)
   return hash.digest()

def encrypt_binary_blob(blob, counter_val, encrypt_key):
    cipher = Cipher(algorithms.AES(encrypt_key), modes.CTR(counter_val))
    return cipher.encryptor().update(blob)

parser = argparse.ArgumentParser(allow_abbrev=False)
parser.add_argument("--input_file", help="the image to process", required=True)
parser.add_argument("--img_version", help="version of the image", required=True)
parser.add_argument("--img_security_counter", help="Secuity counter value for the image", required=True)
parser.add_argument("--encrypt_key_file", help="encryption key file", required=True)
parser.add_argument("--sign_key_file", help="signing key file", required=False)
parser.add_argument("--img_output_file", help="image output file", required=True)
parser.add_argument("--hash_output_file", help="hash output file", required=False)
parser.add_argument("--signing_layout_file", help="signing layout file", required=True)
parser.add_argument("--header_size", help="size of the header", required=True)
parser.add_argument("--kdf_alg", help="which KDF will be used", required=False, default="cmac")
args = parser.parse_args()

with open(args.input_file, "rb") as in_file:
    bl2_code = in_file.read()

counter_val = secrets.token_bytes(12) + int(0).to_bytes(4, 'little')

version = parse_version(args.img_version)

bl2_partition_size = macro_parser.evaluate_macro(args.signing_layout_file,
                                    ".*(RE_BL2_BIN_SIZE) = *(.*)",
                                    1, 2, True)['RE_BL2_BIN_SIZE']

plaintext = struct_pack([
    int("0xDEADBEEF", 16).to_bytes(4, 'little'),
    int(0).to_bytes(int(args.header_size, 0) - (1452 + 16 + 8 + 4 + 4), 'little'),
    bl2_code,
    ],
    pad_to=bl2_partition_size - (1452 + 16 + 8 + 4))

if args.kdf_alg == "hkdf":
    encrypt_key = derive_encryption_key_hkdf(int(args.img_security_counter, 16).to_bytes(4, 'little'))
else:
    encrypt_key = derive_encryption_key_cmac(int(args.img_security_counter, 16).to_bytes(4, 'little'))
ciphertext = encrypt_binary_blob(plaintext, counter_val, encrypt_key)

data_to_sign = struct_pack([
    version,
    int(args.img_security_counter, 0).to_bytes(4, 'little'),
    plaintext,
    ])

hash = hash_binary_blob(data_to_sign)
sig = sign_binary_blob(data_to_sign)

image = struct_pack([
    counter_val,
    sig,
    version,
    int(args.img_security_counter, 0).to_bytes(4, 'little'),
    ciphertext,
    ])

if len(image) > bl2_partition_size:
    print("Error: Signed image size {} exceeds BL2 partition size {}"
          .format(len(image), bl2_partition_size))
    exit(1)

with open(args.img_output_file, "wb") as img_out_file:
    img_out_file.write(image)

with open(args.hash_output_file, "wb") as hash_out_file:
    hash_out_file.write(hash)
