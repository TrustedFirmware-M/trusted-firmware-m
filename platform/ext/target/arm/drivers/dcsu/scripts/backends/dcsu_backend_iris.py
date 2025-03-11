#!/usr/bin/env python3

#-------------------------------------------------------------------------------
# SPDX-License-Identifier: BSD-3-Clause
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#-------------------------------------------------------------------------------

import iris.debug
import sys

import logging
logger = logging.getLogger("DCSU")

def add_args(parser, prefix=""):
    parser.add_argument("--{}iris_port".format(prefix), dest="iris_port", help="port to connect to IRIS on", type=int, default=7100)
    parser.add_argument("--{}iris_host".format(prefix), dest="iris_host", help="host to connect to IRIS on", default= "localhost")
    parser.add_argument("--{}iris_dcsu_component_string".format(prefix), dest="iris_dcsu_component_string", help="component string of DCSU to target if multiple exist in the system")

def setup_ctx(args):
    try:
        model = iris.debug.NetworkModel(args.iris_host, args.iris_port)
    except TypeError:
        sys.exit("Could not connect to FVP. Check that it is running, that it is "
                 "hosting an IRIS debug server, and that the connection arguments "
                 "are correct")
    dcsu_targets = [m.instance_name for m in model.get_target_info() if m.instance_name[-4:] == "dcsu"]

    assert (len(dcsu_targets) > 0), "Model does not contain a DCSU"

    if (len(dcsu_targets)) > 1 and args.iris_dcsu_component_string:
        dcsu_targets = [d for d in dcsu_targets if args.iris_dcsu_component_string in d]

    assert (len(dcsu_targets) == 1)
    dcsu_target = dcsu_targets[0]

    return model.get_target(dcsu_target)

def write_register(dcsu : iris.debug.Target, register : str, value: int):
    logger.debug("Writing {} to register {}".format(hex(value), register))
    dcsu.write_register(register, value)

def read_register(dcsu : iris.debug.Target, register : str) -> int:
    value = dcsu.read_register(register)
    logger.debug("Read {} from register {}".format(hex(value), register))
    return value
