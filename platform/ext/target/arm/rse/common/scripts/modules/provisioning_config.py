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
from c_struct import C_array, C_enum
import arg_utils
import argparse
from otp_config import OTP_config
from cryptography.hazmat.primitives import hashes

import logging
logger = logging.getLogger("TF-M.{}".format(__name__))

from cryptography.hazmat.primitives.serialization import load_der_public_key, Encoding, PublicFormat

from crypto_conversion_utils import convert_hash_define

all_regions = ['cm', 'dm']

def _get_rotpk_area_index(f : str):
    _, f = f.rsplit("rotpk_areas_", 1)
    if "." in f:
        f, _ = f.split(".", 1)
    if "_" in f:
        f, _ = f.split("_", 1)
    return int(f)

def _get_rotpk_index(f : str):
    _, f = f.rsplit("rotpk_", 1)
    if "." in f:
        _, f = f.rsplit(".", 1)
    if "_" in f:
        _, f = f.rsplit("_", 1)
    return int(f)

def _handle_rotpk_add(config,
                      parser : argparse.ArgumentParser,
                      prefix : str,
                      required : bool,
                      region : str,
                      rotpk_field : str,
                      ):
    try:
        _get_rotpk_index(rotpk_field)
    except (ValueError,AssertionError):
        return

    # Don't add type fields for sub-rotpks
    if rotpk_field.rsplit(".", 1).count("_") > 1:
        return

    arg_utils.add_prefixed_enum_argument(parser=parser,
                                         arg_name="{}_policy_{}".format(*rotpk_field.rsplit("_", 1)),
                                         prefix=prefix,
                                         help="policy for {}".format(rotpk_field),
                                         enum=config.enums["rse_rotpk_policy"],
                                         default="RSE_ROTPK_POLICY_SIG_OPTIONAL",
                                         required=required)

    arg_utils.add_prefixed_enum_argument(parser=parser,
                                         arg_name="{}_type_{}".format(*rotpk_field.rsplit("_", 1)),
                                         prefix=prefix,
                                         help="policy for {}".format(rotpk_field),
                                         enum=config.enums["rse_rotpk_type"],
                                         default="RSE_ROTPK_TYPE_ECDSA",
                                         required=required)

    arg_utils.add_prefixed_enum_argument(parser=parser,
                                         arg_name="{}_hash_alg_{}".format(*rotpk_field.rsplit("_", 1)),
                                         prefix=prefix,
                                         help="policy for {}".format(rotpk_field),
                                         enum=config.enums["rse_rotpk_hash_alg"],
                                         default="RSE_ROTPK_HASH_ALG_SHA256",
                                         required=required)


arg_add_handlers = {
    "rotpk_" : _handle_rotpk_add,
}

def add_arguments(parser : argparse.ArgumentParser,
                  prefix : str = "",
                  required : bool = True,
                  regions : [str] = all_regions,
                  ) -> None:
    provisioning_config = arg_utils.pre_parse_args(parser, "provisioning_config",
                                                           help="Path to provisioning config file",
                                                           type=Provisioning_config.from_config_file)


    for r in regions:
        optional_fields = []
        optional_fields += [f.split(".", 1)[1] for f in getattr(provisioning_config, r + "_layout").get_field_strings()]
        optional_fields = [f for f in optional_fields if "zero_count" not in f and "raw_data" not in f and "rotpk_policies" not in f]

        for f in optional_fields:
            f_name = arg_utils.join_prefix(f, prefix)
            f_name = arg_utils.join_prefix(f_name, r)
            if isinstance(getattr(provisioning_config, r + "_layout").get_field(f), C_array):
                arg_type = arg_utils.arg_type_bytes
            else:
                arg_type = int

            for h in arg_add_handlers.keys():
                if h in f:
                    v = arg_add_handlers[h](provisioning_config, parser, prefix, False, r, f_name)

            arg_utils.add_prefixed_argument(parser, "{}".format(f_name), prefix,
                                                    help="value to set {} to".format(f_name),
                                                    metavar="<path or hex>", type=arg_type, required=False)

    return provisioning_config

def _get_policy_field(provisioning_config, field_owner, area_index):
    return getattr(provisioning_config, "{}_layout".format(field_owner)).get_field("{}.rotpk_areas_{}.{}_rotpk_policies".format(field_owner, area_index, field_owner))

def _handle_rotpk_hash_alg(args: argparse.Namespace,
                           f : str,
                           v : C_enum,
                           field_owner : str,
                           provisioning_config,
                           **kwargs
                           ):
    rotpk = "{}.rotpk_areas_{}.rotpk_{}".format(field_owner, _get_rotpk_area_index(f),
                                                _get_rotpk_index(f))
    rotpk = arg_utils.join_prefix(rotpk, field_owner)
    if rotpk not in vars(args) or not getattr(args, rotpk):
        logger.warning("{} set but {} is not".format(f, rotpk))
        return

    area_index = _get_rotpk_area_index(f)
    policy_word_field = _get_policy_field(provisioning_config, field_owner, area_index)
    policy_word = policy_word_field.get_value()
    rotpk_index = _get_rotpk_index(f)

    getattr(provisioning_config, "{}_rotpk_hash_algs".format(field_owner))[(area_index, rotpk_index)] = v.name

    v = v.get_value()
    policy_word |= v << (12 + rotpk_index)
    policy_word_field.set_value(policy_word)


def _handle_rotpk_policy(args: argparse.Namespace,
                         f : str,
                         v : C_enum,
                         field_owner : str,
                         provisioning_config,
                         **kwargs
                         ):
    rotpk = "{}.rotpk_areas_{}.rotpk_{}".format(field_owner, _get_rotpk_area_index(f),
                                                _get_rotpk_index(f))
    rotpk = arg_utils.join_prefix(rotpk, field_owner)
    if rotpk not in vars(args) or not getattr(args, rotpk):
        logger.warning("{} set but {} is not".format(f, rotpk))
        return

    policy_word_field = _get_policy_field(provisioning_config, field_owner, _get_rotpk_area_index(f))
    policy_word = policy_word_field.get_value()
    rotpk_index = _get_rotpk_index(f)

    v = v.get_value()
    policy_word |= v << (18 + rotpk_index)
    policy_word_field.set_value(policy_word)

def _handle_rotpk_type(args: argparse.Namespace,
                       f : str,
                       v : C_enum,
                       field_owner : str,
                       provisioning_config,
                       **kwargs
                       ):
    rotpk = "{}.rotpk_areas_{}.rotpk_{}".format(field_owner, _get_rotpk_area_index(f),
                                                _get_rotpk_index(f))
    rotpk = arg_utils.join_prefix(rotpk, field_owner)
    if rotpk not in vars(args) or not getattr(args, rotpk):
        logger.warning("{} set but {} is not".format(f, rotpk))
        return

    policy_word_field = _get_policy_field(provisioning_config, field_owner, _get_rotpk_area_index(f))
    policy_word = policy_word_field.get_value()
    rotpk_index = _get_rotpk_index(f)

    v = v.get_value()
    getattr(provisioning_config, "{}_rotpk_types".format(field_owner))[rotpk_index] = v

    policy_word |= v << (2 * rotpk_index)
    policy_word_field.set_value(policy_word)

def _handle_rotpk(args: argparse.Namespace,
                  f : str,
                  v : bytes,
                  field_owner : str,
                  otp_config : OTP_config,
                  provisioning_config,
                  **kwargs,
                  ):
    assert(v)

    rotpk_index = _get_rotpk_index(f)
    if hasattr(otp_config.defines, "RSE_OTP_{}_ROTPK_IS_HASH_NOT_KEY".format(field_owner.upper())):
        area_index = _get_rotpk_area_index(f)
        assert (area_index, rotpk_index) in getattr(provisioning_config, "{}_rotpk_hash_algs".format(field_owner)).keys(), "--{}:{}.rotpk_hash_alg_{} required but not set".format(field_owner, field_owner, rotpk_index)

        hash_alg = getattr(provisioning_config,
                           "{}_rotpk_hash_algs".format(field_owner))[area_index, rotpk_index]
        hash_alg = convert_hash_define(hash_alg, "RSE_ROTPK_HASH_ALG_")
        digest = hashes.Hash(hash_alg())
        digest.update(v)
        out = digest.finalize()
        logger.info("Hashed public key {} with value {} using alg {} to hash {}".format(f, v.hex(), hash_alg.name, out.hex()))
        return out
    else:
        type = getattr(provisioning_config, "{}_rotpk_type".format(field_owner))[rotpk_index]
        if type == "RSE_ROTPK_TYPE_ECDSA":
            return load_der_public_key(v).public_bytes(Encoding.X962,
                                                       PublicFormat.UncompressedPoint)
        else:
            return v

arg_parse_handlers = {
    "rotpk_type_"      : _handle_rotpk_type,
    "rotpk_policy_"    : _handle_rotpk_policy,
    "rotpk_hash_alg_"  : _handle_rotpk_hash_alg,
    "rotpk_"           : _handle_rotpk,
}

def parse_args(args : argparse.Namespace,
               otp_config : OTP_config,
               prefix : str = "",
               regions : [str] = all_regions,
               ) -> dict:
    out = {}

    if "provisioning_config" not in out.keys():
        out |= arg_utils.parse_args_automatically(args, ["provisioning_config"], prefix)

    for f,v in sorted(vars(args).items(), key=lambda x:len(x[0]), reverse=True):
        if not v:
            logger.info("Skipping field {} due to missing value".format(f))
            continue

        f = arg_utils.unjoin_prefix(f, prefix)

        field_owner = None
        for r in regions:
            if arg_utils.is_prefixed(f, r):
                field_owner = r
                f = arg_utils.unjoin_prefix(f, r)
                break;

        if not field_owner:
            logger.info("Skipping field {} due to unknown owner".format(f))
            continue

        for h in arg_parse_handlers.keys():
            if h in f:
                logger.info("Running handler {} on field {}".format(arg_parse_handlers[h], f))
                v = arg_parse_handlers[h](args, f, v, field_owner=field_owner,
                                          otp_config = otp_config, **out)
                break

        if not v:
            continue

        try:
            getattr(out["provisioning_config"], "{}_layout".format(field_owner)).get_field(f).set_value(v)
        except KeyError:
            logger.warning("Skipping field {}:{} because no key matches".format(field_owner, f))
            continue

        try:
            getattr(out["provisioning_config"], "{}_layout".format(field_owner)).get_field(f + "_size").set_value(len(v))
        except KeyError:
            logger.debug("Not setting length for {}:{} as no key matches {}_len".format(field_owner, f, f))
            continue

    return out;

class Provisioning_config:
    def __init__(self, cm, dm, defines, enums):
        self.cm_layout = cm
        self.dm_layout = dm
        self.defines = defines
        self.defines._definitions = {k:v for k,v in self.defines._definitions.items() if not callable(v)}
        self.defines.__dict__ = {k:v for k,v in self.defines.__dict__.items() if not callable(v)}
        self.__dict__ |= self.defines._definitions
        self.enums = enums
        for e in self.enums:
            self.__dict__ |= self.enums[e].dict
        self.cm_rotpk_hash_algs = {}
        self.dm_rotpk_hash_algs = {}
        self.cm_rotpk_types = {}
        self.dm_rotpk_types = {}

    @staticmethod
    def from_h_file(h_file_path, policy_h_file_path, includes, defines):
        make_region = lambda x: c_struct.C_struct.from_h_file(h_file_path,
                                                              "rse_{}_provisioning_values_t".format(x),
                                                              includes, defines)
        regions = [make_region(x) for x in all_regions]
        config = c_macro.C_macro.from_h_file(h_file_path, includes, defines)

        rotpk_types = c_struct.C_enum.from_h_file(policy_h_file_path, "rse_rotpk_type", includes, defines)
        rotpk_policies = c_struct.C_enum.from_h_file(policy_h_file_path, "rse_rotpk_policy", includes, defines)
        rotpk_hash_algs = c_struct.C_enum.from_h_file(policy_h_file_path, "rse_rotpk_hash_alg", includes, defines)

        create_enum = lambda x:c_struct.C_enum.from_h_file(policy_h_file_path, x, includes, defines)
        enum_names = [
            'rse_rotpk_type',
            'rse_rotpk_policy',
            'rse_rotpk_hash_alg',
        ]

        enums = {x : create_enum(x) for x in enum_names}

        return Provisioning_config(*regions, defines=config, enums=enums)

    @staticmethod
    def from_config_file(file_path):
        with open(file_path, "rb") as f:
            return pickle.load(f)

    def to_config_file(self, file_path):
        with open(file_path, "wb") as f:
            pickle.dump(self, f)

    def set_area_infos_from_otp_config(self,
                                       otp_config : OTP_config,
                                       **kwargs : dict,
                                       ):
        dm_sets_dm_and_dynamic_area_size = hasattr(otp_config.defines, "DM_SETS_DM_AND_DYNAMIC_AREA_SIZE")

        if otp_config.header.cm_area_info.offset.get_value() != 0:
            self.cm_layout.cm_area_info.set_value_from_bytes(otp_config.header.cm_area_info.to_bytes())

        if otp_config.header.bl1_2_area_info.offset.get_value() != 0:
            self.cm_layout.bl1_2_area_info.set_value_from_bytes(otp_config.header.bl1_2_area_info.to_bytes())

        if otp_config.header.dm_area_info.offset.get_value() != 0:
            if not dm_sets_dm_and_dynamic_area_size:
                self.cm_layout.dm_area_info.set_value_from_bytes(otp_config.header.dm_area_info.to_bytes())
            if dm_sets_dm_and_dynamic_area_size:
                self.dm_layout.dm_area_info.set_value_from_bytes(otp_config.header.dm_area_info.to_bytes())

        if otp_config.header.dynamic_area_info.offset.get_value() != 0:
            if not dm_sets_dm_and_dynamic_area_size:
                self.cm_layout.dynamic_area_info.set_value_from_bytes(otp_config.header.dynamic_area_info.to_bytes())
            if dm_sets_dm_and_dynamic_area_size:
                self.dm_layout.dynamic_area_info.set_value_from_bytes(otp_config.header.dynamic_area_info.to_bytes())

script_description = """
This script takes an instance of rse_provisioning_layout.h, rse_rotpk_policy.h,
and a set of definitions (extracted from compile_commands.json), and creates a
config file which corresponds to the layout of CM, DM and combined provisioning
bundles defined by those three, which can then be used to create binary
provisioning bundles, or to allow other scripts to access the provisioning
configuration options.
"""
if __name__ == "__main__":
    import argparse
    import c_include

    parser = argparse.ArgumentParser(allow_abbrev=False,
                                     formatter_class=argparse.ArgumentDefaultsHelpFormatter,
                                     description=script_description)
    parser.add_argument("--rse_provisioning_layout_h_file", help="path to rse_provisioning_layout.h", type=arg_utils.arg_type_filepath, required=True)
    parser.add_argument("--rse_rotpk_policy_h_file", help="path to rse_rotpk_policy.h", type=arg_utils.arg_type_filepath, required=True)
    parser.add_argument("--compile_commands_file", help="path to compile_commands.json", type=arg_utils.arg_type_filepath, required=True)
    parser.add_argument("--provisioning_config_output_file", help="file to output provisioning config to", required=True)
    parser.add_argument("--log_level", help="log level", required=False, default="ERROR", choices=logging._levelToName.values())

    from rich import inspect
    args = parser.parse_args()
    logging.getLogger("TF-M").setLevel(args.log_level)
    logger.addHandler(logging.StreamHandler())

    includes = c_include.get_includes(args.compile_commands_file, "otp_lcm.c")
    defines = c_include.get_defines(args.compile_commands_file, "otp_lcm.c")

    provisioning_config = Provisioning_config.from_h_file(args.rse_provisioning_layout_h_file, args.rse_rotpk_policy_h_file, includes, defines)

    provisioning_config.to_config_file(args.provisioning_config_output_file)
