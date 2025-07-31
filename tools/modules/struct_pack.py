#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

import struct

import logging
logger = logging.getLogger("TF-M.{}".format(__name__))

def struct_pack(objects, pad_to=0):
    defstring = "<"
    for obj in objects:
        defstring += str(len(obj)) + "s"

    size = struct.calcsize(defstring)
    if size < pad_to:
        defstring += str(pad_to - size) + "x"
    assert size <= pad_to or pad_to == 0, "Error padding struct of size {} to {}".format(size, pad_to)

    return (bytes(struct.pack(defstring, *objects)))
