#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

from cryptography.hazmat.primitives.serialization import load_pem_private_key, Encoding, PublicFormat
import logging
logger = logging.getLogger("TF-M.{}".format(__name__))
from os.path import splitext, isfile

def _load_bin(filepath):
    with open(filepath, 'rb') as input_file:
        return input_file.read()

def _load_pem(filepath):
    with open(filepath, 'rb') as input_file:
        data = input_file.read()

    key = load_pem_private_key(data, password=None)

    # MCUBoot wants DER keys
    key_bytes = key.public_key().public_bytes(Encoding.DER, PublicFormat.SubjectPublicKeyInfo)
    logger.info("Loaded DER public key {} of size {} from {}".format(key_bytes, len(key_bytes), filepath))

    return key_bytes

def load_bytes_from_file(filepath):
    _, extension = splitext(filepath)

    if not filepath or not isfile(filepath):
        raise FileNotFoundError

    logging.info("Loading bytes from {} with type {}".format(filepath, extension))

    if extension == ".pem":
        return _load_pem(filepath)
    elif extension == ".pub":
        return _load_bin(filepath)[4:]
    else:
        return _load_bin(filepath)
