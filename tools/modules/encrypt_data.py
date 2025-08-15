#!/usr/bin/env python3
#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes

import argparse
import secrets
import sys

from tfm_tools.arg_utils import *
from tfm_tools import key_derivation

import logging
logger = logging.getLogger("TF-M.{}".format(__name__))

def _encrypt_aes_ctr(data : bytes,
                     iv : bytes,
                     key : bytes
                     ) -> bytes:
    assert len(iv) >= 8

    if len(iv) < 16:
        iv += bytes(16 - len(iv))

    c = Cipher(algorithms.AES(key), modes.CTR(iv))
    return c.encryptor().update(data)

encrypt_algs = {
    "AES_CTR": _encrypt_aes_ctr,
}

def add_arguments(parser : argparse.ArgumentParser,
                  prefix : str = "",
                  required : bool = True,
                  ) -> None:
    add_prefixed_argument(parser, "encrypt_key", prefix, help="encryption key input file",
                          required=required, type=arg_type_bytes)
    add_prefixed_argument(parser, "encrypt_alg", prefix, help="encryption algorithm",
                          choices=encrypt_algs.keys(), required=required)
    add_prefixed_argument(parser, "iv", prefix, help="encryption intial value",
                          type=arg_type_bytes, required=False)

    key_derivation.add_arguments(parser, prefix, required=False)

def parse_args(args : argparse.Namespace,
               prefix : str = "",
               ) -> dict:
    out = parse_args_automatically(args, ["encrypt_alg", "encrypt_key", "iv"], prefix)
    out["kdf_args"] = key_derivation.parse_args(args)

    return out

def encrypt_data(data : bytes,
                 encrypt_key : bytes,
                 encrypt_alg : str,
                 kdf_args : dict,
                 iv : bytes = None,
                 **kwargs,
                 ) -> (bytes, bytes):
    if not data:
        return iv, data

    assert(encrypt_key)
    assert(encrypt_alg)

    if kdf_args:
        encrypt_key = key_derivation.derive_symmetric_key(**kdf_args,
                                                          input_key = encrypt_key,
                                                          length = 32
                                                          )

    if not iv:
        iv = secrets.token_bytes(12) + int(0).to_bytes(4, 'little')

    encrypted_data = encrypt_algs[encrypt_alg](
                                  data = data,
                                  key = encrypt_key,
                                  iv = iv)
    return iv, encrypted_data

def main():
    parser = argparse.ArgumentParser(allow_abbrev=False,
                                     formatter_class=argparse.ArgumentDefaultsHelpFormatter,
                                     description=script_description)
    parser.add_argument("--log_level", help="log level", required=False, default="ERROR", choices=logging._levelToName.values())
    parser.add_argument("--data", help="data to sign", type=arg_type_bytes, required=True)

    add_arguments(parser, required=True)

    args = parser.parse_args()
    logging.getLogger("TF-M").setLevel(args.log_level)
    logger.addHandler(logging.StreamHandler())

    config = parse_args(args)
    config |= parse_args_automatically(args, ["data"])

    print(encrypt_data(**config)[1].hex())


script_description = """
Encrypt some data
"""
if __name__ == "__main__":
    sys.exit(main())
