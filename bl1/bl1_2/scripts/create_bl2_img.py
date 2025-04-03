#!/usr/bin/env python3
#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

import sign_data
import encrypt_data

import logging
logger = logging.getLogger("TF-M.{}".format(__name__))
from tfm_tools.arg_utils import *
from tfm_tools.crypto_conversion_utils import convert_curve_define, convert_hash_define

import sys
import os
sys.path.append(os.path.join(sys.path[0], 'modules'))

import bl2_image_config
from bl2_image_config import BL2_image_config

def add_arguments(parser : argparse.ArgumentParser,
                  prefix : str = "",
                  required : bool = True,
                  ) -> None:
    image_config = bl2_image_config.add_arguments(parser, prefix, required)

    add_prefixed_argument(parser, "bl2_bin", prefix, help="Binary file for BL2 code and data", type=arg_type_bytes, required=True)
    add_prefixed_argument(parser, "image_version", prefix, help="BL2 image version", type=arg_type_version, default="0.0.0+0", required=False)
    add_prefixed_argument(parser, "image_security_counter", prefix, help="BL2 image security counter value", type=int, default=0, required=False)

    for i in range(int(image_config.TFM_BL1_2_SIGNER_AMOUNT)):
        sign_data.add_arguments(parser, "signer_{}".format(i), False)

    if hasattr(image_config, "TFM_BL1_2_IMAGE_ENCRYPTION"):
        encrypt_data.add_arguments(parser, "", required)


def parse_args(args : argparse.Namespace,
               prefix : str = "",
               ) -> dict:
    out = parse_args_automatically(args, ["bl2_bin", "image_version",
                                          "image_security_counter",
                                          "bl2_image_config"], prefix)
    out["encrypt_args"] = encrypt_data.parse_args(args)
    for i in range(int(out["bl2_image_config"].TFM_BL1_2_SIGNER_AMOUNT)):
        out["signer_{}_args".format(i)] = sign_data.parse_args(args,
                                                               prefix="signer_{}".format(i))

    out.update(bl2_image_config.parse_args(args, prefix))

    return out

def get_data_to_be_signed(bl2_image_config : BL2_image_config,
                          bl2_bin : bytes,
                          image_version : [int] = [0, 0, 0, 0],
                          image_security_counter : int = 0,
                          ) -> bytes:
    image = bl2_image_config.image
    config = bl2_image_config.defines

    image.protected_values.encrypted_data.data.set_value(bl2_bin)

    image.protected_values.version.major.set_value(image_version[0])
    image.protected_values.version.minor.set_value(image_version[1])
    image.protected_values.version.revision.set_value(image_version[2])
    if (len(image_version) == 4):
        image.protected_values.version.build_num.set_value(image_version[3])

    image.protected_values.security_counter.set_value(image_security_counter)

    if hasattr(config, "TFM_BL1_2_IMAGE_ENCRYPTION"):
        magic = config.TFM_BL1_2_IMAGE_DECRYPT_MAGIC_EXPECTED
        image.protected_values.encrypted_data.decrypt_magic.set_value(magic)

    return image.protected_values.to_bytes()

def get_data_to_encrypt(bl2_image_config : BL2_image_config) -> bytes:
    image = bl2_image_config.image
    config = bl2_image_config.defines
    return image.protected_values.encrypted_data.to_bytes()

def create_bl2_img(bl2_image_config : BL2_image_config,
                   bl2_bin : bytes,
                   image_version: [int] = [0, 0, 0, 0],
                   image_security_counter: int = 0,
                   encrypted_data : bytes = None,
                   encrypt_args : dict = {},
                   **kwargs
                   ):
    image = bl2_image_config.image
    config = bl2_image_config.defines

    data_to_be_signed = get_data_to_be_signed(bl2_image_config=bl2_image_config,
                                              bl2_bin=bl2_bin,
                                              image_version=image_version,
                                              image_security_counter=image_security_counter)
    with open("script.bin", "wb") as f:
        f.write(data_to_be_signed)

    image.protected_values.set_value_from_bytes(data_to_be_signed)

    for i in range(int(config.TFM_BL1_2_SIGNER_AMOUNT)):
        if not kwargs["signer_{}_args".format(i)]:
            continue
        else:
            sign_args = kwargs["signer_{}_args".format(i)]

        if "sign_hash_alg" in sign_args.keys():
            config_hash_alg = convert_hash_define(getattr(config, "TFM_BL1_2_MEASUREMENT_HASH_ALG"), "TFM_BL1_HASH_ALG")
            assert(config_hash_alg.name == sign_args["sign_hash_alg"].name)


        curve = convert_curve_define(getattr(config, "TFM_BL1_2_ECDSA_CURVE"), "TFM_BL1_CURVE")
        sign_args.update({"curve": curve})

        if "sig_{}".format(i) not in kwargs.keys():
            sig = sign_data.sign_data(data = image.protected_values.to_bytes(),
                                      **sign_args)
        else:
            sig = kwargs["sig_{}".format(i)]

        image.header.sigs[i].sig.set_value_from_bytes(sig)
        image.header.sigs[i].sig_len.set_value(len(sig))

        if hasattr(config, "TFM_BL1_2_EMBED_ROTPK_IN_IMAGE"):
            if "pub_key_{}".format(i) not in kwargs.keys():
                pub_key = sign_data.get_pubkey(**sign_args)
            else:
                pub_key = kwargs["pub_key_{}".format(i)]
            # if not hasattr(pub_key:
            image.header.sigs[i].rotpk.set_value_from_bytes(pub_key)
            image.header.sigs[i].rotpk_len.set_value(len(pub_key))

    if hasattr(config, "TFM_BL1_2_IMAGE_ENCRYPTION"):
        if (not encrypted_data):
            if (encrypt_args["kdf_args"]):
                encrypt_args["kdf_args"].update({
                    "context" : image.protected_values.security_counter.to_bytes(),
                    "label" : "BL2_DECRYPTION_KEY",
                })
            iv, encrypted_data = encrypt_data.encrypt_data(get_data_to_encrypt(bl2_image_config),
                                                           **encrypt_args)

        image.header.ctr_iv.set_value_from_bytes(iv)
        image.protected_values.encrypted_data.set_value_from_bytes(encrypted_data)

    image_size = image.get_size()
    image_max_size = int(config.IMAGE_BL2_CODE_SIZE, 0) + int(config.TFM_BL1_2_HEADER_MAX_SIZE, 0)
    header_size = image_size - image.protected_values.encrypted_data.data.get_size()
    header_max_size = int(config.TFM_BL1_2_HEADER_MAX_SIZE, 0)

    assert header_size <= header_max_size, "Header size {} is larger than HEADER_MAX_SIZE {}".format(header_size, header_max_size)
    assert image_size <= image_max_size, "Image size {} is larger than FLASH_BL2_PARTITION_SIZE {}".format(image_size, image_max_size)

    logger.debug(image)

    return image.to_bytes()

script_description = """
This script creates a BL2 image from a config file and some parameter arguments.
Any unset parameters will be 0.
"""
if __name__ == "__main__":
    import argparse

    parser = argparse.ArgumentParser(allow_abbrev=False,
                                     formatter_class=argparse.ArgumentDefaultsHelpFormatter,
                                     description=script_description)

    add_arguments(parser, "", True)

    parser.add_argument("--image_output_file", help="BL2 image output file", required=True)
    parser.add_argument("--log_level", help="log level", required=False, default="ERROR", choices=logging._levelToName.values())

    args = parser.parse_args()
    logging.getLogger("TF-M").setLevel(args.log_level)
    logger.addHandler(logging.StreamHandler())

    config = parse_args(args, "")

    output = create_bl2_img(**config)

    with open(args.image_output_file, "wb") as f:
        f.write(output)
