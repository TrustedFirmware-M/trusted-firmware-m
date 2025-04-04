#!/usr/bin/env python3
#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

import argparse

import logging
logger = logging.getLogger("TF-M.{}".format(__name__))

import arg_utils
import sign_data
import encrypt_data

from cryptography.hazmat.primitives.ciphers.aead import AESCCM
import secrets

def _sign_then_encrypt_aes_ccm(data : bytes,
                               sign_and_encrypt_key : bytes,
                               aad : bytes = bytes(0),
                               iv : bytes = None,
                               tag_length : int = 16,
                               **kwargs,
                               ):
    if not iv:
        iv = secrets.token_bytes(12)

    output = AESCCM(sign_and_encrypt_key, tag_length=tag_length).encrypt(nonce=iv,
                                                                         data=data,
                                                                         associated_data=aad)
    signature = output[-tag_length:]
    ciphertext = output[:-tag_length]
    logger.info("Encrypting with IV {}".format(iv.hex()))
    logger.info("Encrypting with key {}".format(sign_and_encrypt_key.hex()))
    return iv, ciphertext, signature

combined_algs = {
    "AES_CCM": _sign_then_encrypt_aes_ccm,
}

def add_arguments(parser : argparse.ArgumentParser,
                  prefix : str = "",
                  required : bool = True,
                  ) -> None:
    arg_utils.add_prefixed_argument(parser, "sign_and_encrypt_key", prefix,
                                    help="combined sign/encrypt key input file",
                                    type=arg_utils.arg_type_bytes, required=False)
    arg_utils.add_prefixed_argument(parser, "sign_and_encrypt_alg", prefix,
                                    help="combined sign/encrypt algorithm",
                                    choices=combined_algs.keys(), required=False)
    encrypt_data.add_arguments(parser, prefix, False)
    sign_data.add_arguments(parser, prefix, False)

def parse_args(args : argparse.Namespace,
               prefix : str = "",
               ) -> dict:
    out = arg_utils.parse_args_automatically(args, ["sign_and_encrypt_alg",
                                             "sign_and_encrypt_key"], prefix)

    out |= sign_data.parse_args(args, prefix)
    out |= encrypt_data.parse_args(args, prefix)

    arg_utils.incompatible_arg(args, "sign_and_encrypt_alg", "sign_alg")
    arg_utils.incompatible_arg(args, "sign_and_encrypt_alg", "encrypt_alg")

    return out

def sign_then_encrypt_data(data : bytes,
                           sign_and_encrypt_alg : str = None,
                           aad : bytes = bytes(0),
                           **kwargs,
              ) -> bytes:
    if sign_and_encrypt_alg:
        return combined_algs[sign_and_encrypt_alg](data=data, aad=aad, **kwargs)
    else:
        iv, ciphertext = encrypt_data.encrypt_data(data=data, **kwargs)
        return iv, ciphertext, sign_data.sign_data(data=aad + data, **kwargs)

script_description = """
"""
if __name__ == "__main__":
    import argparse

    parser = argparse.ArgumentParser(allow_abbrev=False,
                                     formatter_class=argparse.ArgumentDefaultsHelpFormatter,
                                     description=script_description)
    parser.add_argument("--log_level", help="log level", required=False, default="ERROR", choices=logging._levelToName.values())

    args = parser.parse_args()
    logging.getLogger("TF-M").setLevel(args.log_level)
    logger.addHandler(logging.StreamHandler())
