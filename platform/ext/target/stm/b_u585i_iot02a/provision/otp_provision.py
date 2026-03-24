#! /usr/bin/env python3
#
# -----------------------------------------------------------------------------
#
# Copyright (c) 2019-2020, Arm Limited. All rights reserved.
# Copyright (c) 2021 STMicroelectronics. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
# -----------------------------------------------------------------------------

import os
import sys
import click
from jinja2 import Environment, FileSystemLoader
from cryptography.hazmat.primitives.hashes import Hash, SHA256

cwd = os.getcwd()
sys.path = [cwd] + sys.path
import imgtool
import imgtool.main

_DEV_DEFAULT_HUK = (
    "0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,"
    "0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,"
    "0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,"
    "0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,"
)

_DEV_DEFAULT_IAK = (
    "0xA9, 0xB4, 0x54, 0xB2, 0x6D, 0x6F, 0x90, 0xA4,"
    "0xEA, 0x31, 0x19, 0x35, 0x64, 0xCB, 0xA9, 0x1F,"
    "0xEC, 0x6F, 0x9A, 0x00, 0x2A, 0x7D, 0xC0, 0x50,"
    "0x4B, 0x92, 0xA1, 0x93, 0x71, 0x34, 0x58, 0x5F,"
)

_DEV_DEFAULT_BOOT_SEED = (
    "0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7,"
    "0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF,"
    "0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7,"
    "0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF,"
)

_DEV_DEFAULT_IMPLEMENTATION_ID = (
    "0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA,"
    "0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB,"
    "0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC,"
    "0xDD, 0xDD, 0xDD, 0xDD, 0xDD, 0xDD, 0xDD, 0xDD,"
)

_DEV_DEFAULT_BL2_ROTPK_0 = (
    "0xbf, 0xe6, 0xd8, 0x6f, 0x88, 0x26, 0xf4, 0xff,"
    "0x97, 0xfb, 0x96, 0xc4, 0xe6, 0xfb, 0xc4, 0x99,"
    "0x3e, 0x46, 0x19, 0xfc, 0x56, 0x5d, 0xa2, 0x6a,"
    "0xdf, 0x34, 0xc3, 0x29, 0x48, 0x9a, 0xdc, 0x38,"
)

_DEV_DEFAULT_BL2_ROTPK_1 = (
    "0xb3, 0x60, 0xca, 0xf5, 0xc9, 0x8c, 0x6b, 0x94,"
    "0x2a, 0x48, 0x82, 0xfa, 0x9d, 0x48, 0x23, 0xef,"
    "0xb1, 0x66, 0xa9, 0xef, 0x6a, 0x6e, 0x4a, 0xa3,"
    "0x7c, 0x19, 0x19, 0xed, 0x1f, 0xcc, 0xc0, 0x49,"
)

_DEV_DEFAULT_BL2_ROTPK_2 = (
    "0xb3, 0x60, 0xca, 0xf5, 0xc9, 0x8c, 0x6b, 0x94,"
    "0x2a, 0x48, 0x82, 0xfa, 0x9d, 0x48, 0x23, 0xef,"
    "0xb1, 0x66, 0xa9, 0xef, 0x6a, 0x6e, 0x4a, 0xa3,"
    "0x7c, 0x19, 0x19, 0xed, 0x1f, 0xcc, 0xc0, 0x49,"
)

_DEV_DEFAULT_ENTROPY_SEED = (
    "0x12, 0x13, 0x23, 0x34, 0x0a, 0x05, 0x89, 0x78,"
    "0xa3, 0x66, 0x8c, 0x0d, 0x97, 0x55, 0x53, 0xca,"
    "0xb5, 0x76, 0x18, 0x62, 0x29, 0xc6, 0xb6, 0x79,"
    "0x75, 0xc8, 0x5a, 0x8d, 0x9e, 0x11, 0x8f, 0x85,"
    "0xde, 0xc4, 0x5f, 0x66, 0x21, 0x52, 0xf9, 0x39,"
    "0xd9, 0x77, 0x93, 0x28, 0xb0, 0x5e, 0x02, 0xfa,"
    "0x58, 0xb4, 0x16, 0xc8, 0x0f, 0x38, 0x91, 0xbb,"
    "0x28, 0x17, 0xcd, 0x8a, 0xc9, 0x53, 0x72, 0x66,"
)

_DEV_DEFAULT_IAK_ID = "stm.example.xcube!"
_DEV_DEFAULT_CERT_REF = "060456527282910010"
_SPKI_RAW_KEY_OFFSET = 26

parser_path = os.path.abspath(os.path.join(os.path.dirname(__file__), "../"))
sys.path.append(parser_path)

os.environ["LC_ALL"] = "C.UTF-8"
os.environ["LANG"] = "C.UTF-8"


def _hex_to_c_array(hex_val):
    c_array = ""
    for count, b in enumerate(hex_val):
        if count % 8 == 0 and count != 0:
            c_array = c_array + "\n"
        c_array = c_array + "0x{:02x}, ".format(b)

    return c_array


def _rotpk_hash_or_default(key_file, mcuboot_hw_key, default, name):
    if not key_file:
        return default
    key = imgtool.main.load_key(key_file)
    if mcuboot_hw_key == "ON":
        digest = Hash(SHA256())
        digest.update(key.get_public_bytes())
        key_bytes = digest.finalize()
    else:
        key_bytes = key.get_public_bytes()[_SPKI_RAW_KEY_OFFSET:]
    return _hex_to_c_array(key_bytes)


def _value_or_default(value, default, name):
    if value:
        return value
    return default


@click.command(
    help="Render provisioning_data_template.jinja2 into OUTFILE using the "
    "supplied OTP values. Missing optional values fall back to insecure "
    "development defaults."
)
@click.argument("outfile")
@click.option("--template_path", metavar="filename", required=True)
@click.option("--bl2_rot_priv_key_0", metavar="filename", required=False)
@click.option("--bl2_rot_priv_key_1", metavar="filename", required=False)
@click.option("--bl2_rot_priv_key_2", metavar="filename", required=False)
@click.option("--bl2_mcuboot_hw_key", metavar="string", required=True)
@click.option("--secure_debug_pk", metavar="key", required=False, default="")
@click.option("--huk", metavar="key", required=False, default="")
@click.option("--iak", metavar="key", required=False, default="")
@click.option("--iak_id", metavar="id", required=False, default="")
@click.option("--cert_ref", metavar="string", required=False, default="")
@click.option("--boot_seed", metavar="seed", required=False, default="")
@click.option("--implementation_id", metavar="id", required=False, default="")
@click.option(
    "--certification_reference", metavar="reference", required=False, default=""
)
@click.option("--verification_service_url", metavar="url", required=False, default="")
@click.option("--entropy_seed", metavar="seed", required=False, default="")
def generate_provisioning_data_c(
    outfile,
    template_path,
    bl2_rot_priv_key_0,
    bl2_rot_priv_key_1,
    bl2_rot_priv_key_2,
    bl2_mcuboot_hw_key,
    secure_debug_pk,
    huk,
    iak,
    iak_id,
    cert_ref,
    boot_seed,
    implementation_id,
    certification_reference,
    verification_service_url,
    entropy_seed,
):
    environment = Environment(loader=FileSystemLoader(template_path))
    template = environment.get_template("provisioning_data_template.jinja2")

    bl2_rot_pub_key_0_hash = _rotpk_hash_or_default(
        bl2_rot_priv_key_0,
        bl2_mcuboot_hw_key,
        _DEV_DEFAULT_BL2_ROTPK_0,
        "BL2_ROT_PRIV_KEY_0",
    )

    bl2_rot_pub_key_1_hash = _rotpk_hash_or_default(
        bl2_rot_priv_key_1,
        bl2_mcuboot_hw_key,
        _DEV_DEFAULT_BL2_ROTPK_1,
        "BL2_ROT_PRIV_KEY_1",
    )

    bl2_rot_pub_key_2_hash = _rotpk_hash_or_default(
        bl2_rot_priv_key_2,
        bl2_mcuboot_hw_key,
        _DEV_DEFAULT_BL2_ROTPK_2,
        "BL2_ROT_PRIV_KEY_2",
    )

    huk = _value_or_default(huk, _DEV_DEFAULT_HUK, "HUK")
    iak = _value_or_default(iak, _DEV_DEFAULT_IAK, "IAK")
    boot_seed = _value_or_default(boot_seed, _DEV_DEFAULT_BOOT_SEED, "BOOT_SEED")
    implementation_id = _value_or_default(
        implementation_id, _DEV_DEFAULT_IMPLEMENTATION_ID, "IMPLEMENTATION_ID"
    )
    entropy_seed = _value_or_default(
        entropy_seed, _DEV_DEFAULT_ENTROPY_SEED, "ENTROPY_SEED"
    )

    iak_id = _hex_to_c_array((iak_id or _DEV_DEFAULT_IAK_ID).encode())
    cert_ref = _hex_to_c_array((cert_ref or _DEV_DEFAULT_CERT_REF).encode())

    key_arrays = {
        "bl2_rotpk_0": bl2_rot_pub_key_0_hash,
        "bl2_rotpk_1": bl2_rot_pub_key_1_hash,
        "bl2_rotpk_2": bl2_rot_pub_key_2_hash,
        "secure_debug_pk": secure_debug_pk,
        "huk": huk,
        "iak": iak,
        "iak_id": iak_id,
        "iak_len": "32",
        "boot_seed": boot_seed,
        "implementation_id": implementation_id,
        "certification_reference": certification_reference,
        "verification_service_url": verification_service_url,
        "entropy_seed": entropy_seed,
        "cert_ref": cert_ref,
    }

    with open(outfile, "w") as F:
        F.write(template.render(key_arrays))


if __name__ == "__main__":
    generate_provisioning_data_c()
