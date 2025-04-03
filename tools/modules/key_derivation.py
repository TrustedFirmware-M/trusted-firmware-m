# -----------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
# -----------------------------------------------------------------------------

from tfm_tools.arg_utils import *
from cryptography.hazmat.primitives import cmac
from cryptography.hazmat.primitives.ciphers import algorithms

from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.kdf.hkdf import HKDF

import struct
import argparse
import logging
logger = logging.getLogger("TF-M.{}".format(__name__))


def symmetric_kdf_sp800_108_cmac(input_key: bytes,
                                 context: bytes,
                                 label: bytes,
                                 length: int,
                                 **kwargs: dict,
                                 ):
    """
    This assumes r == 32 bits, i.e. the size in bits over which
    the counter [i]2 is encoded as a binary number. For simplicity
    we use 4-bytes to encode the length as well, [L]2

    Args:
        input_key (bytes): Ki from which to derive a Ko
        context (bytes): Context bytes
        label (bytes): label bytes
        length (int): Size in bytes of the Ko to be derived
    """
    def prf_cmac(x: bytes, key: bytes):
        c = cmac.CMAC(algorithms.AES(key))
        c.update(x)
        return c.finalize()

    # K(0) = PRF(K_in, Label || 0x00 || Context || [L]2)
    state = label + bytes(1) + context + struct.pack(">I", 8 * length)
    K0 = prf_cmac(state, input_key)

    output_key = bytes(0)
    # K(i) = PRF(K_in, [i]2 || Label || 0x00 || Context || [L]2 || K(0))
    for i in range((length // 16) + 1):
        state = struct.pack(">I", i + 1) + label + bytes(1) + \
            context + struct.pack(">I", 8 * length) + K0
        output_key += prf_cmac(state, input_key)

    return output_key[:length]


def symmetric_kdf_hkdf(input_key: bytes,
                       context: bytes,
                       label: bytes,
                       length: int,
                       hkdf_hash_alg: str = "SHA256",
                       **kwargs: dict,
                       ):
    state = label + context

    hkdf = HKDF(
        algorithm=hkdf_hashes[hkdf_hash_alg](),
        length=length,
        salt=None,
        info=state)

    return hkdf.derive(input_key)


kdf_funcs = {
    "sp800-108_cmac": symmetric_kdf_sp800_108_cmac,
    "hkdf": symmetric_kdf_hkdf,
}

hkdf_hashes = {
    "SHA256": hashes.SHA256,
    "SHA384": hashes.SHA384,
    "SHA512": hashes.SHA512,
}


def add_arguments(parser: argparse.ArgumentParser,
                  prefix: str = "",
                  required: bool = True,
                  ) -> None:
    add_prefixed_argument(parser, "kdf_alg", prefix,
                          help="key deriation algorithm",
                          choices=kdf_funcs, required=required)
    add_prefixed_argument(parser, "hkdf_hash_alg", prefix,
                          help="hkdf hash function",
                          choices=hkdf_hashes, required=False)


def parse_args(args: argparse.Namespace,
               prefix: str = "",
               ) -> dict:
    out = parse_args_automatically(args, ["kdf_alg", "hkdf_hash_alg"], prefix)
    return out


def derive_symmetric_key(input_key: bytes,
                         context: bytes,
                         label: str,
                         length: int,
                         kdf_alg: str = "sp800-108_cmac",
                         **kdf_args: dict
                         ):
    # C keeps the null byte, python removes it, so we add it back manually.
    label_bytes = label.encode('ascii') + bytes(1) if label else bytes(0)

    output_key = kdf_funcs[kdf_alg](
        input_key, context, label_bytes, length, **kdf_args)

    return output_key


# Curve Parameters
CURVES = {
    "P-256": {  # secp256r1
        "order": int("FFFFFFFF00000000FFFFFFFFFFFFFFFFBCE6FAADA7179E84F3B9CAC2FC632551", 16),
        "key_size": 256,  # Bits
        "recommended_bits_for_generation": 352
    },
    "P-384": {  # secp384r1
        "order": int("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC7634D81F4372DDF581A0DB248B0A77AECEC196ACCC52973", 16),
        "key_size": 384,  # Bits
        "recommended_bits_for_generation": 384
    }
}


def derive_ecc_key(input_key: bytes,
                   context: bytes,
                   label: str,
                   curve: str = "P-256",
                   **kdf_args: dict
                   ):
    """
    Derives an ECC key following recommendation of FIPS 186-5 A.2.1

    Args:
        input_key (bytes): Input secret key material for derivation
        context (bytes): Context bytes
        label (str): Label string
        curve (str, optional): _description_. Defaults to "P-256".
    """

    l_bytes = (CURVES[curve]["recommended_bits_for_generation"] + 7) // 8
    align16 = lambda num: (num + 15) & ~15

    # Derive a key using SP 800-108 with AES-CMAC as PRF in Counter mode
    derived_key = derive_symmetric_key(input_key, context, label, align16(l_bytes))

    # Perform modular reduction using the desired curve order
    return int.from_bytes(derived_key, byteorder="big") % CURVES[curve]["order"]
