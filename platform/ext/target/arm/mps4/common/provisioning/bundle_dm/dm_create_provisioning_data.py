#! /usr/bin/env python3
#
# -----------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
# -----------------------------------------------------------------------------

import os
import sys
import click
from jinja2 import Environment, FileSystemLoader
from cryptography.hazmat.primitives.hashes import Hash, SHA256

# Add the cwd to the path so that if there is a version of imgtool in there then
# it gets used over the system imgtool. Used so that imgtool from upstream
# mcuboot is preferred over system imgtool
cwd = os.getcwd()
sys.path = [cwd] + sys.path
import imgtool.main
import imgtool

parser_path = os.path.abspath(os.path.join(os.path.dirname(__file__), '../'))
sys.path.append(parser_path)

# This works around Python 2 and Python 3 handling character encodings
# differently. More information about this issue at
# https://click.palletsprojects.com/en/5.x/python3
os.environ['LC_ALL'] = 'C.UTF-8'
os.environ['LANG'] = 'C.UTF-8'


def get_key_hash_c_array(key_file, mcuboot_hw_key):
    key = imgtool.main.load_key(key_file)
    key_bytes = []
    if mcuboot_hw_key == "ON":
        digest = Hash(SHA256())
        digest.update(key.get_public_bytes())
        key_bytes = digest.finalize()
    else:
        # If the full key is used then use only the raw key
        # bit string (subjectPublicKey). The offset of the
        # bit string is 26, so drop the first 26 bytes.
        key_bytes = key.get_public_bytes()[26:]

    return hex_to_c_array(key_bytes)


@click.argument('outfile')
@click.option('--template_path', metavar='filename', required=True)
@click.option('--bl1_rotpk_0_path', metavar='filename', required=True)
@click.option('--bl2_encryption_key_path', metavar='filename', required=True)
@click.option('--bl2_mcuboot_hw_key', metavar='string', required=True)
@click.option('--bl2_rot_priv_key_0', metavar='filename', required=True)
@click.option('--bl2_rot_priv_key_1', metavar='filename', required=False)
@click.option('--bl2_rot_priv_key_2', metavar='filename', required=False)
@click.option('--bl2_rot_priv_key_3', metavar='filename', required=False)
@click.option('--implementation_id', metavar='id', required=False)
@click.option('--verification_service_url', metavar='url', required=False,
              default='www.trustedfirmware.org', show_default=True)
@click.option('--attestation_profile_definition', metavar='definition',
              required=False, default='PSA_IOT_PROFILE_1', show_default=True)
@click.option('--secure_debug_pk', metavar='key', required=False)
@click.option('--boot_seed', metavar='seed', required=False)
@click.option('--certification_reference', metavar='reference',
              required=False, default='0604565272829-10010', show_default=True)
@click.option('--entropy_seed', metavar='seed', required=False)
@click.command(help='''Creates a .c file with the given keys, using the\n
               provisioning_data_template.jinja2 template which is located in
               "template_path" and outputs it to "outfile"''')
def generate_provisioning_data_c(outfile,
                                 template_path,
                                 bl1_rotpk_0_path,
                                 bl2_encryption_key_path,
                                 bl2_mcuboot_hw_key,
                                 bl2_rot_priv_key_0,
                                 bl2_rot_priv_key_1,
                                 bl2_rot_priv_key_2,
                                 bl2_rot_priv_key_3,
                                 implementation_id,
                                 verification_service_url,
                                 attestation_profile_definition,
                                 secure_debug_pk,
                                 boot_seed,
                                 certification_reference,
                                 entropy_seed):

    environment = Environment(loader=FileSystemLoader(template_path))
    template = environment.get_template("dm_provisioning_data_template.jinja2")

    with open(bl1_rotpk_0_path, "rb") as F:
        # Remove the first 4 bytes since it's HSS info
        bl1_rotpk_0 = hex_to_c_array(F.read()[4:])

    with open(bl2_encryption_key_path, "rb") as F:
        bl2_encryption_key = hex_to_c_array(F.read())

    bl2_rot_pub_key_0_hash = ""
    if bool(bl2_rot_priv_key_0) is True:
        bl2_rot_pub_key_0_hash = get_key_hash_c_array(
            bl2_rot_priv_key_0, bl2_mcuboot_hw_key)

    bl2_rot_pub_key_1_hash = ""
    if bool(bl2_rot_priv_key_1) is True:
        bl2_rot_pub_key_1_hash = get_key_hash_c_array(
            bl2_rot_priv_key_1, bl2_mcuboot_hw_key)

    bl2_rot_pub_key_2_hash = ""
    if bool(bl2_rot_priv_key_2) is True:
        bl2_rot_pub_key_2_hash = get_key_hash_c_array(
            bl2_rot_priv_key_2, bl2_mcuboot_hw_key)

    bl2_rot_pub_key_3_hash = ""
    if bool(bl2_rot_priv_key_3) is True:
        bl2_rot_pub_key_3_hash = get_key_hash_c_array(
            bl2_rot_priv_key_3, bl2_mcuboot_hw_key)

    if bool(implementation_id) is False:
        implementation_id = hex_to_c_array(os.urandom(32))

    if bool(verification_service_url) is False:
        verification_service_url = "www.trustedfirmware.org"

    if bool(attestation_profile_definition) is False:
        attestation_profile_definition = "PSA_IOT_PROFILE_1"

    if bool(secure_debug_pk) is False:
        secure_debug_pk = hex_to_c_array(os.urandom(32))

    if bool(boot_seed) is False:
        boot_seed = hex_to_c_array(os.urandom(32))

    if bool(certification_reference) is False:
        certification_reference = "0604565272829-10010"

    if bool(entropy_seed) is False:
        entropy_seed = hex_to_c_array(os.urandom(64))

    key_arrays = {
        "bl1_rotpk_0": bl1_rotpk_0,
        "bl2_encryption_key": bl2_encryption_key,
        "bl2_rotpk_0": bl2_rot_pub_key_0_hash,
        "bl2_rotpk_1": bl2_rot_pub_key_1_hash,
        "bl2_rotpk_2": bl2_rot_pub_key_2_hash,
        "bl2_rotpk_3": bl2_rot_pub_key_3_hash,
        "implementation_id": implementation_id,
        "verification_service_url": verification_service_url,
        "attestation_profile_definition": attestation_profile_definition,
        "secure_debug_pk": secure_debug_pk,
        "boot_seed": boot_seed,
        "certification_reference": certification_reference,
        "entropy_seed": entropy_seed
    }

    with open(outfile, "w") as F:
        F.write(template.render(key_arrays))


def hex_to_c_array(hex_val):
    c_array = ""
    for count, b in enumerate(hex_val):
        if count % 8 == 0 and count != 0:
            c_array = c_array + '\n'
        c_array = c_array + "0x{:02x}, ".format(b)

    return c_array


if __name__ == '__main__':
    generate_provisioning_data_c()
