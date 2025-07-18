#!/usr/bin/env python3
#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

import sys

from cryptography.hazmat.primitives.asymmetric import utils, ec
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.serialization import load_pem_private_key, Encoding, PublicFormat

import pyhsslms

from cryptography.hazmat.primitives.ciphers.aead import AESCCM
import secrets

from tfm_tools.arg_utils import *

import argparse
import logging
logger = logging.getLogger("TF-M.{}".format(__name__))

def _asn1_sig_to_raw(sig : bytes , curve : ec.EllipticCurve) -> bytes:
    point_size = curve.key_size // 8
    r, s = utils.decode_dss_signature(sig)
    return bytes(0).join([x.to_bytes(point_size, byteorder="big") for x in [r, s]])

def _pubkey_ecdsa(key : str) -> bytes:
    with open(key, "rb") as f:
        key_data = f.read()

    priv_key = load_pem_private_key(key_data, password=None)
    return priv_key.public_key().public_bytes(Encoding.DER, PublicFormat.SubjectPublicKeyInfo)

def _pubkey_lms(key : str) -> bytes:
    return pyhsslms.HssLmsPublicKey(key[:-4]).hss_pub.pub.serialize()

pubkey_algs = {
    "ECDSA": _pubkey_ecdsa,
    "LMS":   _pubkey_lms,
}

def _sign_ecdsa(data : bytes,
                key : str,
                curve : ec.EllipticCurve = None,
                hash_alg : hashes.HashAlgorithm = None,
                dsr_output_file = None,
                **kwargs : {},
                ) -> bytes:
    with open(key, "rb") as f:
        key_data = f.read()

    priv_key = load_pem_private_key(key_data, password=None)

    hash_alg_defaults = {
        ec.SECP256R1: hashes.SHA256,
        ec.SECP384R1: hashes.SHA384,
    }

    if curve:
        assert curve.name == priv_key.curve.name, "Key curve {} does not match required curve {}".format(priv_key.curve.name, curve.name)

    if not hash_alg:
        hash_alg = hash_alg_defaults[type(priv_key.curve)]

    logger.info("Signing with ECDSA key {} (curve {}) and hash {}".format(key, priv_key.curve.name, hash_alg.name))

    digest = hashes.Hash(hash_alg())
    digest.update(data)
    data_hash = digest.finalize()
    logger.info("Signing hash {}".format(data_hash.hex()))

    if dsr_output_file:
        dsr_output_file.write(data_hash)
        sys.exit(0)

    asn1_sig = priv_key.sign(data_hash, ec.ECDSA(utils.Prehashed(hash_alg()),deterministic_signing=True))

    return _asn1_sig_to_raw(asn1_sig, priv_key.curve)

def _sign_lms(data : bytes,
              key : str,
              dsr_output_file = None,
              **kwargs : {},
              ) -> bytes:
    if dsr_output_file:
        dsr_output_file.write(data)
        sys.exit(0)

    priv_key = pyhsslms.HssLmsPrivateKey(key[:-4])
    logger.info("Signing with LMS key {}".format(key))
    return priv_key.sign(data)[4:]

def sign_data(data : bytes,
              sign_key : str,
              sign_alg : str,
              sign_hash_alg : str = None,
              signature : bytes = None,
              **kwargs,
              ) -> bytes:
    if not signature:
        assert(sign_key)
        assert(sign_alg)

        signature = sign_algs[sign_alg](data = data,
                                        key = sign_key,
                                        hash_alg = sign_hash_alg,
                                        **kwargs)

    return signature

def get_pubkey(sign_key : str,
               sign_alg : str,
               **kwargs
               ) -> bytes:
    return pubkey_algs[sign_alg](sign_key)

sign_algs = {
    "ECDSA":     _sign_ecdsa,
    "LMS":       _sign_lms,
}

def add_arguments(parser : argparse.ArgumentParser,
                  prefix : str = "",
                  required : bool = True,
                  ) -> None:
    add_prefixed_argument(parser, "sign_key", prefix, help="signing key input file",
                          type=str, required=required)
    add_prefixed_argument(parser, "sign_alg", prefix, help="signing algorithm",
                          choices=sign_algs.keys(), required=required)
    add_prefixed_argument(parser, "sign_hash_alg", prefix, help="signing hash algorithm",
                          type=arg_type_hash, required=False)
    add_prefixed_argument(parser, "dsr_output_file", prefix, help="path to output Data Signing Request to",
                          type=arg_type_bytes_output_file, required=False)
    add_prefixed_argument(parser, "signature", prefix, help="signature (if already signed)",
                          type=arg_type_bytes, required=False)

def parse_args(args : argparse.Namespace,
               prefix : str = "",
               ) -> dict:
    out = parse_args_automatically(args, ["sign_key", "sign_alg", "sign_hash_alg"], prefix)
    return out

script_description = """
Sign some data.
"""
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

    print(sign_data(**config).hex())

if __name__ == "__main__":
    sys.exit(main())
