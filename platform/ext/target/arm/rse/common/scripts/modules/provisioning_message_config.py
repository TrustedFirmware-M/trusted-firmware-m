#!/usr/bin/env python3
#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

import c_struct
import c_macro
import c_include
import pickle
import sys
from c_struct import C_enum
from secrets import token_bytes
import arg_utils
from cryptography.hazmat.primitives.serialization import load_pem_private_key, Encoding, PublicFormat

import sign_then_encrypt_data
import argparse

import logging
logger = logging.getLogger("TF-M.{}".format(__name__))

def add_arguments(parser : argparse.ArgumentParser,
                  prefix : str = "",
                  required : bool = True,
                  message_type : str = None
                  ) -> None:
    provisioning_message_config = arg_utils.pre_parse_args(parser, "provisioning_message_config",
                                                                    help="Path to provisioning message_config file",
                                                                    type=Provisioning_message_config.from_config_file)

    if not message_type:
        message_type = arg_utils.pre_parse_args(parser, "type_of_message",
                                                help="Type of provisioning message to create",
                                                type=str,
                                                choices=provisioning_message_config.enums['rse_provisioning_message_type_t'].dict.keys())

    if (message_type == "RSE_PROVISIONING_MESSAGE_TYPE_BLOB"):
        arg_utils.add_prefixed_enum_argument(parser=parser,
                                             enum=provisioning_message_config.enums['rse_provisioning_blob_valid_lcs_mask_t'],
                                             prefix=prefix,
                                             arg_name="valid_lcs",
                                             help="LCS is which blob can be run",
                                             nargs="+",
                                             action="extend",
                                             required=required)

        arg_utils.add_prefixed_enum_argument(parser=parser,
                                             enum=provisioning_message_config.enums['rse_provisioning_blob_required_tp_mode_config_t'],
                                             prefix=prefix,
                                             arg_name="tp_mode",
                                             help="TP Mode is which blob can be run",
                                             required=required)

        arg_utils.add_prefixed_enum_argument(parser=parser,
                                             enum=provisioning_message_config.enums['rse_provisioning_blob_required_sp_mode_config_t'],
                                             prefix=prefix,
                                             arg_name="sp_mode",
                                             help="Whether SP mode is required to be enabled for the blob to be run",
                                             required=required)

        arg_utils.add_prefixed_argument(parser, "sign_key_cm_rotpk", prefix,
                                                help="CM ROTPK to use when embedding key in bundle",
                                                type=int, required=False, default=0)

        arg_utils.add_prefixed_argument(parser, "soc_uid", prefix,
                                                help="ID of SOC to use for personalization",
                                                type=arg_utils.arg_type_bytes, required=False)

        arg_utils.add_prefixed_argument(parser, "version", prefix,
                                                help="Version of provisioning blob",
                                                type=int, required=required)

        arg_utils.add_prefixed_enum_argument(parser=parser,
                                             enum=provisioning_message_config.enums['rse_provisioning_blob_signature_config_t'],
                                             prefix=prefix,
                                             arg_name="signature_config",
                                             help="Configuration of the blob signature",
                                             required=required)

        arg_utils.add_prefixed_enum_argument(parser=parser,
                                             enum=provisioning_message_config.enums['rse_provisioning_blob_non_rom_pk_type_config_t'],
                                             prefix=prefix,
                                             arg_name="non_rom_pk_config",
                                             help="Configuration of the blob signature when the PK is not in the ROM",
                                             default="RSE_PROVISIONING_BLOB_DETAILS_NON_ROM_PK_TYPE_CM_ROTPK",
                                             required=False)

        arg_utils.add_prefixed_enum_argument(parser=parser,
                                             enum=provisioning_message_config.enums['rse_provisioning_blob_code_and_data_decryption_config_t'],
                                             prefix=prefix,
                                             arg_name="encrypt_code_and_data",
                                             help="Whether to encrypt blob secret values",
                                             default="RSE_PROVISIONING_BLOB_CODE_DATA_DECRYPTION_NONE",
                                             required=False)

        arg_utils.add_prefixed_enum_argument(parser=parser,
                                             enum=provisioning_message_config.enums['rse_provisioning_blob_secret_values_decryption_config_t'],
                                             prefix=prefix,
                                             arg_name="encrypt_secret_values",
                                             help="Whether to encrypt blob secret values",
                                             default="RSE_PROVISIONING_BLOB_SECRET_VALUES_DECRYPTION_AES",
                                             required=False)


    sign_then_encrypt_data.add_arguments(parser, prefix)

    return provisioning_message_config

def parse_args(args : argparse.Namespace,
               prefix : str = "",
               ) -> dict:
    out = {}

    if "provisioning_message_config" not in out.keys():
        out = arg_utils.parse_args_automatically(args, ["provisioning_message_config"], prefix)

    out |= arg_utils.parse_args_automatically(args, ["valid_lcs", "tp_mode", "sp_mode",
                                                     "signature_config", "non_rom_pk_config",
                                                     "sign_key_cm_rotpk", "soc_uid", "version",
                                                     "encrypt_code_and_data",
                                                     "encrypt_secret_values"], prefix)

    out |= {
        "sign_and_encrypt_kwargs" : sign_then_encrypt_data.parse_args(args, prefix),
    }

    return out

class Provisioning_message_config:
    def __init__(self, message, defines, enums):
        self.message = message
        self.defines = defines
        self.defines._definitions = {k:v for k,v in self.defines._definitions.items() if not callable(v)}
        self.defines.__dict__ = {k:v for k,v in self.defines.__dict__.items() if not callable(v)}
        self.__dict__ |= self.defines._definitions
        self.enums = enums
        for e in self.enums:
            self.__dict__ |= self.enums[e].dict

    @staticmethod
    def from_h_file(h_file_path, includes, defines):
        message = c_struct.C_struct.from_h_file(h_file_path,
                                                'rse_provisioning_message_t',
                                                includes, defines)

        create_enum = lambda x:c_struct.C_enum.from_h_file(h_file_path, x, includes, defines)
        enum_names = [
            'rse_provisioning_message_type_t',
            'rse_provisioning_blob_type_t',
            'rse_provisioning_blob_required_tp_mode_config_t',
            'rse_provisioning_blob_required_sp_mode_config_t',
            'rse_provisioning_blob_valid_lcs_mask_t',
            'rse_provisioning_blob_code_and_data_decryption_config_t',
            'rse_provisioning_blob_secret_values_decryption_config_t',
            'rse_provisioning_blob_non_rom_pk_type_config_t',
            'rse_provisioning_blob_signature_config_t',
            'rse_provisioning_blob_personalization_config_t',
            'rse_provisioning_blob_sequencing_config_t',
        ]

        enums = {x : create_enum(x) for x in enum_names}

        config = c_macro.C_macro.from_h_file(h_file_path, includes, defines)

        return Provisioning_message_config(message, config, enums)

    @staticmethod
    def from_config_file(file_path):
        with open(file_path, "rb") as f:
            return pickle.load(f)

    def to_config_file(self, file_path):
        with open(file_path, "wb") as f:
            pickle.dump(self, f)

def get_blob_details(provisioning_message_config : Provisioning_message_config,
                     encrypt_code_and_data : C_enum,
                     encrypt_secret_values : C_enum,
                     signature_config : C_enum,
                     non_rom_pk_config : C_enum,
                     sign_key_cm_rotpk : int,
                     encrypt_alg : str = None,
                     sign_alg : str = None,
                     sign_and_encrypt_alg : str = None,
                     soc_uid : bytes = None,
                     valid_lcs : [str] = None,
                     **kwargs
                     ) -> int:
    details_val = 0

    val = encrypt_code_and_data.get_value()
    details_val |= (val & int(provisioning_message_config.RSE_PROVISIONING_BLOB_DETAILS_CODE_DATA_DECRYPTION_MASK, 0)) \
                   << int(provisioning_message_config.RSE_PROVISIONING_BLOB_DETAILS_CODE_DATA_DECRYPTION_OFFSET, 0)

    val = encrypt_secret_values.get_value()
    details_val |= (val & int(provisioning_message_config.RSE_PROVISIONING_BLOB_DETAILS_SECRET_VALUES_DECRYPTION_MASK, 0)) \
                   << int(provisioning_message_config.RSE_PROVISIONING_BLOB_DETAILS_SECRET_VALUES_DECRYPTION_OFFSET, 0)

    val = signature_config.get_value()
    details_val |= (val & int(provisioning_message_config.RSE_PROVISIONING_BLOB_DETAILS_SIGNATURE_MASK, 0)) \
                   << int(provisioning_message_config.RSE_PROVISIONING_BLOB_DETAILS_SIGNATURE_OFFSET, 0)

    if signature_config.name == "RSE_PROVISIONING_BLOB_SIGNATURE_ROTPK_NOT_IN_ROM":
        val = non_rom_pk_config.get_value()
        details_val |= (val & int(provisioning_message_config.RSE_PROVISIONING_BLOB_DETAILS_NON_ROM_PK_TYPE_MASK, 0)) \
                        << int(provisioning_message_config.RSE_PROVISIONING_BLOB_DETAILS_NON_ROM_PK_TYPE_OFFSET, 0)
        if non_rom_pk_config.name == "RSE_PROVISIONING_BLOB_DETAILS_NON_ROM_PK_TYPE_CM_ROTPK":
            details_val |= (sign_key_cm_rotpk \
                            & int(provisioning_message_config.RSE_PROVISIONING_BLOB_DETAILS_CM_ROTPK_NUMBER_MASK, 0)) \
                            << int(provisioning_message_config.RSE_PROVISIONING_BLOB_DETAILS_CM_ROTPK_NUMBER_OFFSET, 0)

    if soc_uid:
        val = provisioning_message_config.RSE_PROVISIONING_BLOB_TYPE_PERSONALIZED.get_value()
    else:
        val = provisioning_message_config.RSE_PROVISIONING_BLOB_TYPE_STATIC.get_value()
    details_val |= (val & int(provisioning_message_config.RSE_PROVISIONING_BLOB_DETAILS_PERSONALIZATION_MASK, 0)) \
                   << int(provisioning_message_config.RSE_PROVISIONING_BLOB_DETAILS_PERSONALIZATION_OFFSET, 0)

    return details_val

def get_blob_purpose(provisioning_message_config : Provisioning_message_config,
                     blob_type : C_enum,
                     tp_mode : C_enum,
                     sp_mode : C_enum,
                     valid_lcs : [C_enum],
                     signature_config : C_enum,
                     non_rom_pk_config : C_enum,
                     **kwargs,
                     ):
    purpose_val = 0;

    val = blob_type.get_value()
    purpose_val |= (val & int(provisioning_message_config.RSE_PROVISIONING_BLOB_PURPOSE_TYPE_MASK, 0)) \
                    << int(provisioning_message_config.RSE_PROVISIONING_BLOB_PURPOSE_TYPE_OFFSET, 0)

    val = tp_mode.get_value()
    purpose_val |= (val & int(provisioning_message_config.RSE_PROVISIONING_BLOB_PURPOSE_TP_MODE_MASK, 0)) \
                    << int(provisioning_message_config.RSE_PROVISIONING_BLOB_PURPOSE_TP_MODE_OFFSET, 0)

    val = sp_mode.get_value()
    purpose_val |= (val & int(provisioning_message_config.RSE_PROVISIONING_BLOB_PURPOSE_SP_MODE_MASK, 0)) \
                    << int(provisioning_message_config.RSE_PROVISIONING_BLOB_PURPOSE_SP_MODE_OFFSET, 0)

    for l in valid_lcs:
        val = l.get_value()
        purpose_val |= (val & int(provisioning_message_config.RSE_PROVISIONING_BLOB_PURPOSE_LCS_MASK_MASK, 0)) \
                        << int(provisioning_message_config.RSE_PROVISIONING_BLOB_PURPOSE_LCS_MASK_OFFSET, 0)

    if signature_config.name == "RSE_PROVISIONING_BLOB_SIGNATURE_ROTPK_NOT_IN_ROM" and \
        non_rom_pk_config.name == "RSE_PROVISIONING_BLOB_DETAILS_NON_ROM_PK_TYPE_PREVIOUS_BLOB":
        purpose_val |= (provisioning_message_config.RSE_PROVISIONING_BLOB_CHAINED.get_value() \
                        & int(provisioning_message_config.RSE_PROVISIONING_BLOB_PURPOSE_SEQUENCING_MASK, 0)) \
                        << int(provisioning_message_config.RSE_PROVISIONING_BLOB_PURPOSE_SEQUENCING_OFFSET, 0)

    return purpose_val

def get_header(provisioning_message_config : Provisioning_message_config):
    message = provisioning_message_config.message
    unsigned_size = message.blob.signature_size.get_size() + message.blob.signature.get_size()
    return message.blob.to_bytes()[unsigned_size:-message.blob.code_and_data_and_secret_values.get_size()]

def get_blob_pubkey(sign_alg : str = None,
                    sign_key : str = None,
                    sign_and_encrypt_alg : str = None,
                    sign_and_encrypt_key: str = None,
                    **kwargs : dict):
    if not sign_alg:
        sign_alg = sign_and_encrypt_alg
    if not sign_key:
        sign_key = sign_and_encrypt_key

    with open(sign_key, "rb") as f:
        key_data = f.read()

    priv_key = load_pem_private_key(key_data, password=None)
    pub_key = priv_key.public_key().public_bytes(Encoding.X962, PublicFormat.UncompressedPoint)
    # Drop 0x04
    return pub_key[1:]

def get_data_to_encrypt_and_sign(provisioning_message_config : Provisioning_message_config,
                                 code : bytes,
                                 encrypt_code_and_data : C_enum,
                                 encrypt_secret_values : C_enum,
                                 version : int,
                                 signature_config : C_enum,
                                 non_rom_pk_config : C_enum,
                                 sign_key_cm_rotpk : int,
                                 sign_and_encrypt_kwargs : dict,
                                 data : bytes = bytes(0),
                                 secret_values = bytes(0),
                                 soc_uid : bytes = None,
                                 **kwargs : dict,
                        ):
    message = provisioning_message_config.message
    message.header.type.set_value(provisioning_message_config.RSE_PROVISIONING_MESSAGE_TYPE_BLOB.get_value())

    # Cannot enable code and data encryption without secret values encryption
    assert not ((encrypt_code_and_data.name ==  "RSE_PROVISIONING_BLOB_CODE_DATA_DECRYPTION_AES") \
                and (encrypt_secret_values.name != "RSE_PROVISIONING_BLOB_SECRET_VALUES_DECRYPTION_AES"))

    if len(code) % 16 != 0:
        code += bytes(16 - (len(code) % 16))

    code_and_data = code
    message.blob.code_size.set_value(len(code))
    code_and_data_and_secret_values_len = len(code)


    if (data):
        if len(data) % 16 != 0:
            data += bytes(16 - (len(data) % 16))

        message.blob.data_size.set_value(len(data))
        code_and_data_and_secret_values_len += len(data)
        code_and_data += data

    if (secret_values):
        if len(secret_values) % 16 != 0:
            secret_values += bytes(16 - (len(secret_values) % 16))

        message.blob.secret_values_size.set_value(len(secret_values))
        code_and_data_and_secret_values_len += len(secret_values)

    data_length = message.blob.get_size() - message.blob.code_and_data_and_secret_values.get_size() + code_and_data_and_secret_values_len
    message.header.data_length.set_value(data_length)

    if version:
        message.blob.version.set_value(version)
    if soc_uid:
        message.blob.soc_uid.set_value_from_bytes(soc_uid)

    metadata = get_blob_details(provisioning_message_config=provisioning_message_config,
                                encrypt_code_and_data=encrypt_code_and_data,
                                encrypt_secret_values=encrypt_secret_values,
                                signature_config=signature_config,
                                non_rom_pk_config=non_rom_pk_config,
                                sign_key_cm_rotpk=sign_key_cm_rotpk,
                                soc_uid=soc_uid, **sign_and_encrypt_kwargs)
    message.blob.metadata.set_value(metadata)

    purpose = get_blob_purpose(provisioning_message_config=provisioning_message_config, signature_config=signature_config,
                                non_rom_pk_config=non_rom_pk_config, **kwargs)
    message.blob.purpose.set_value(purpose)

    if signature_config.name == "RSE_PROVISIONING_BLOB_SIGNATURE_ROTPK_NOT_IN_ROM" and \
        non_rom_pk_config.name == "RSE_PROVISIONING_BLOB_DETAILS_NON_ROM_PK_TYPE_CM_ROTPK":
        message.blob.public_key.set_value_from_bytes(get_blob_pubkey(**sign_and_encrypt_kwargs))

    plaintext = bytes(0)
    aad = get_header(provisioning_message_config)

    if encrypt_code_and_data.name == "RSE_PROVISIONING_BLOB_CODE_DATA_DECRYPTION_AES":
        plaintext += code_and_data
    else:
        aad += code_and_data

    if encrypt_secret_values.name == "RSE_PROVISIONING_BLOB_SECRET_VALUES_DECRYPTION_AES":
        plaintext += secret_values
    else:
        aad += secret_values
    return plaintext, aad

def create_blob_message(provisioning_message_config : Provisioning_message_config,
                        sign_and_encrypt_kwargs : dict,
                        signature_config : C_enum,
                        non_rom_pk_config : C_enum,
                        soc_uid : bytes = None,
                        sign_key_cm_rotpk : bytes = None,
                        **kwargs : dict,
                        ):
    message = provisioning_message_config.message
    defines = provisioning_message_config.defines

    iv = token_bytes(8)
    message.blob.iv.set_value_from_bytes(iv)

    plaintext, aad = get_data_to_encrypt_and_sign(provisioning_message_config,
                                                  sign_and_encrypt_kwargs=sign_and_encrypt_kwargs,
                                                  signature_config=signature_config, non_rom_pk_config=non_rom_pk_config,
                                                  sign_key_cm_rotpk=sign_key_cm_rotpk,
                                                  soc_uid=soc_uid,
                                                  **kwargs)

    _, ciphertext, signature = sign_then_encrypt_data.sign_then_encrypt_data(**sign_and_encrypt_kwargs,
                                                                             data = plaintext,
                                                                             aad = aad,
                                                                             iv=iv)

    message.blob.signature_size.set_value(len(signature))
    message.blob.signature.set_value_from_bytes(signature)

    logger.info(message)

    header_len = len(get_header(provisioning_message_config))

    return message.to_bytes()[:-message.blob.code_and_data_and_secret_values.get_size()] + aad[header_len:] + ciphertext

def create_plain_data_message(provisioning_message_config : Provisioning_message_config,
                              data : bytes, **kwargs
                              ):
    message = provisioning_message_config.message
    defines = provisioning_message_config.defines

    message.header.type.set_value(provisioning_message_config.RSE_PROVISIONING_MESSAGE_TYPE_BLOB.get_value())
    data_length = message.plain.get_size() - message.plain.data.get_size() + len(data)
    message.header.data_length.set_value(data_length)

    return message.to_bytes()[:message.header.get_size() + data_length - len(data)] + data

script_description = """
This script takes an instance of rse_provisioning_message.h, and a set of
definitions (extracted from compile_commands.json), and creates a config file
which corresponds to the layout of the RSE provisioning blob, cert, and plain
data messages, which can then be used to create binary provisioning messages, or
to allow other scripts to access the provisioning message configuration options.
"""
if __name__ == "__main__":
    import argparse
    import c_include

    parser = argparse.ArgumentParser(allow_abbrev=False)
    parser.add_argument("--rse_provisioning_message_h_file", help="path to rse_provisioning_message.h", required=True)
    parser.add_argument("--compile_commands_file", help="path to compile_commands.json", required=True)
    parser.add_argument("--provisioning_message_config_output_file", help="file to output provisioning message config to", required=True)
    parser.add_argument("--log_level", help="log level", required=False, default="ERROR", choices=logging._levelToName.values())

    args = parser.parse_args()
    logging.getLogger("TF-M").setLevel(args.log_level)
    logger.addHandler(logging.StreamHandler())

    includes = c_include.get_includes(args.compile_commands_file, "otp_lcm.c")
    defines = c_include.get_defines(args.compile_commands_file, "otp_lcm.c")

    provisioning_message_config = Provisioning_message_config.from_h_file(args.rse_provisioning_message_h_file,
                                                                includes, defines)

    provisioning_message_config.to_config_file(args.provisioning_message_config_output_file)
