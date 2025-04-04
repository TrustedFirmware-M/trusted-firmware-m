#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

from cryptography.hazmat.primitives.asymmetric import ec
from cryptography.hazmat.primitives import hashes

import logging
logger = logging.getLogger("TF-M.{}".format(__name__))

def convert_curve_define(define_name : str,
                         define_prefix : str = "",
                         ) -> ec.EllipticCurve:
    curve_name = define_name.replace(define_prefix,"").replace("_", "")

    if not hasattr(ec, curve_name):
        curve_name = "SEC{}R1".format(curve_name)

    return getattr(ec, curve_name)

def convert_hash_define(define_name : str,
                        define_prefix : str = "",
                        ) -> hashes.HashAlgorithm:
    hash_name = define_name.replace(define_prefix,"").replace("_", "")
    return getattr(hashes, hash_name)
