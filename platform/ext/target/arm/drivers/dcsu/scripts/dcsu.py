#!/usr/bin/env python3

#-------------------------------------------------------------------------------
# SPDX-License-Identifier: BSD-3-Clause
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#-------------------------------------------------------------------------------

import argparse
import os
import sys
from enum import Enum
import time

import logging
logger = logging.getLogger("DCSU")

def _chunk_bytes(x, n):
    return [x[i:i+n] for i in range(0, len(x), n)]

def _round_up(x, boundary):
    return ((x + (boundary - 1)) // boundary) * boundary

class dcsu_tx_command(Enum):

class dcsu_rx_command(Enum):

class dcsu_tx_message_error(Enum):
    DCSU_TX_MSG_ERROR_SUCCESS = 0x1,
    DCSU_TX_MSG_ERROR_OTP_ALREADY_WRITTEN = 0x2,
    DCSU_TX_MSG_ERROR_OTP_WRITE_FAILED = 0x3,
    DCSU_TX_MSG_ERROR_SOC_UID_NOT_GENERATED = 0x4,
    DCSU_TX_MSG_ERROR_INVALID_NUM_WORDS = 0x5,
    DCSU_TX_MSG_ERROR_OFFSET_TOO_LARGE = 0x6,
    DCSU_TX_MSG_ERROR_OFFSET_INVALID = 0x7,
    DCSU_RX_MSG_ERROR_SIZE_TOO_LARGE = 0x8,

class dcsu_rx_message_error(Enum):
    DCSU_RX_MSG_ERROR_SUCCESS = 0x1,
    DCSU_RX_MSG_ERROR_GENERIC_FAILURE = 0x2,

def setup_backend(backend: str):
    backend_dir = os.path.join(os.path.dirname(os.path.realpath(__file__)), "backends")
    sys.path.append(backend_dir)
    return __import__("dcsu_backend_{}".format(backend))

def pre_parse_backend(backends : [str], parser : argparse.ArgumentParser, prefix : str = ""):
    pre_arg_parser = argparse.ArgumentParser(add_help=False)

    for p in [pre_arg_parser, parser]:
        p.add_argument("--{}backend".format(prefix), help="Backend to use for DCSU communication", choices=backends, required=True)

    parsed, _ = pre_arg_parser.parse_known_args()
    return parsed.backend

def tx_command_send(backend, ctx, command : dcsu_tx_command, data : bytes = None):
    command_word = command.value

    if (data):
        data_words = [int.from_bytes(b, byteorder='big') for b in _chunk_bytes(data, 4)]

        assert (len(data_words) <= 4), "Data too large"
        command_word |= ((len(data_words) - 1) & 0b11) << 8

        for r,w in zip(["DIAG_RX_DATA_{}".format(i) for i in range(len(data_words))], data_words):
            backend.write_register(ctx, r, w)

    logger.info("Sending command {}".format(command.name))
    backend.write_register(ctx, "DIAG_RX_COMMAND", command_word)


    logger.info("Waiting for response")
    while (response := backend.read_register(ctx, "DIAG_RX_COMMAND") << 24) == 0:
        time.sleep(0.1)

    response = dcsu_tx_message_error(response)

    logger.info("Received response {}".format(response))

    return response

def rx_wait_for_command(backend, ctx, command : dcsu_rx_command):
    logger.info("Waiting for command {}".format(command.name))
    while (recieved_command := backend.read_register(ctx, "DIAG_TX_COMMAND") & 0xFF) == 0:
        time.sleep(0.1)

    assert (command.value == recieved_command), "Unexpected command {} received".format(dcsu_rx_command(recieved_command))

def rx_command_receive(backend, ctx, command : dcsu_rx_command) -> bytes:
    rx_wait_for_command(command)

    if dcsu_rx_command in [DCSU_RX_COMMAND_EXPORT_DATA]:
        data = bytes(0)
        if command == DCSU_RX_COMMAND_WRITE_DATA:
            data_word_size = backend.read_register((ctx, "DIAG_TX_COMMAND", command_word) >> 8) & 0xb11
            for r in ["DIAG_TX_DATA_{}".format(i) for i in range(len(data_words))]:
                data += backend.read_register(ctx, r).to_bytes(4, 'little')
    else:
        data = None

    backend.write_register(ctx, "DIAG_TX_COMMAND", DCSU_RX_MSG_ERROR_SUCCESS << 24)
    return data

def _get_data_from_args(args:argparse.Namespace) -> bytes:



def dcsu_rx_command_export_data(backend, ctx, args: argparse.Namespace):
    rx_wait_for_command(backend, ctx, dcsu_rx_command.DCSU_RX_COMMAND_EXPORT_DATA)

    bytes_to_read = backend.read_register(ctx, "DIAG_TX_LARGE_PARAM")
    bytes_received = bytes(0)

    while len(bytes_received) < bytes_to_read:
         bytes_received += rx_command_receive(backend,
                                              ctx,
                                              dcsu_rx_command.DCSU_RX_COMMAND_EXPORT_DATA)
    return bytes_received


def dcsu_command(backend, ctx, command, args: argparse.Namespace):

    dcsu_command_handlers = {
    }
    return dcsu_command_handlers[command](backend, ctx, args)


script_description = """
This script allows interaction with the DCSU communications protocol over
various backends.

It allows a single DCSU command to be run at a time (though multiple
DCSU_TX_COMMAND_WRITE_DATA commands will be automatically chained to copy larger
amounts of data)
"""

command_description = {
}
if __name__ == "__main__":
    backend_dir = os.path.join(os.path.dirname(os.path.realpath(__file__)), "backends")
    backends = os.listdir(backend_dir)
    backends = [b.replace("dcsu_backend_","").replace(".py", "") for b in backends if ".py" in b]

    parser = argparse.ArgumentParser(allow_abbrev=False,
                                     formatter_class=argparse.ArgumentDefaultsHelpFormatter,
                                     description=script_description)

    parser.add_argument("--log_level", help="log level", required=False, default="ERROR", choices=logging._levelToName.values())

    subparsers = parser.add_subparsers(title="command", help="Command to run", dest='command', required=True)

    parsers = {x : subparsers.add_parser(x, description=command_description[x]) for x in dcsu_tx_command._member_names_ + dcsu_rx_command._member_names_}


    backend_name = pre_parse_backend(backends, parser)
    backend = setup_backend(backend_name)

    backend.add_args(parser)

    args = parser.parse_args()
    logging.basicConfig(level=args.log_level)

    logger.info("Using {} backend".format(backend_name))

    ctx = backend.setup_ctx(args)

    if "_RX_" in args.command:
        command = dcsu_rx_command[args.command]
        print(hex(dcsu_command(backend, ctx, command, args)))
        exit(0)
    else:
        command = dcsu_tx_command[args.command]
        output = dcsu_command(backend, ctx, command, args)
        print(output)
        exit(0 if output == dcsu_tx_message_error.DCSU_TX_MSG_ERROR_SUCCESS else output.value)
