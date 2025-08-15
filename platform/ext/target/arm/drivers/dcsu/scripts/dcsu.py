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
    DCSU_TX_COMMAND_GENERATE_SOC_UNIQUE_ID = 0x1
    DCSU_TX_COMMAND_WRITE_SOC_FAMILY_ID = 0x2
    DCSU_TX_COMMAND_WRITE_SOC_IEEE_ECID = 0x3
    DCSU_TX_COMMAND_COMPUTE_ZC_SOC_IDS = 0x4
    DCSU_TX_COMMAND_READ_SOC_FAMILY_ID = 0x5
    DCSU_TX_COMMAND_READ_SOC_IEEE_ECID = 0x6
    DCSU_TX_COMMAND_WRITE_SOC_CONFIG_DATA = 0x7
    DCSU_TX_COMMAND_COMPUTE_ZC_SOC_CFG = 0x8
    DCSU_TX_COMMAND_READ_SOC_CONFIG_DATA = 0x9
    DCSU_TX_COMMAND_IMPORT_DATA_NO_CHECKSUM = 0xA
    DCSU_TX_COMMAND_IMPORT_DATA_CHECKSUM = 0xB
    DCSU_TX_COMMAND_COMPLETE_IMPORT_DATA = 0xC
    DCSU_TX_COMMAND_CANCEL_IMPORT_DATA_WITH_CHECKSUM = 0xD
    DCSU_TX_COMMAND_READ_COD_DATA = 0xE
    DCSU_TX_COMMAND_READ_EC_PARAMS = 0xF

class dcsu_rx_command(Enum):
    DCSU_RX_COMMAND_IMPORT_READY = 0x1
    DCSU_RX_COMMAND_REPORT_STATUS = 0x2
    DCSU_RX_COMMAND_EXPORT_DATA_WITH_CHECKSUM = 0x3
    DCSU_RX_COMMAND_EXPORT_DATA_NO_CHECKSUM = 0x4
    DCSU_RX_COMMAND_COMPLETE_EXPORT_DATA = 0x5

class dcsu_tx_message_error(Enum):
    DCSU_TX_MSG_RESP_NO_RESP = 0x0
    DCSU_TX_MSG_RESP_SUCCESS = 0x1
    DCSU_TX_MSG_RESP_OTP_ALREADY_WRITTEN = 0x2
    DCSU_TX_MSG_RESP_OTP_WRITE_FAILED = 0x3
    DCSU_TX_MSG_RESP_TOO_LARGE_OFFSET_PARAM = 0x4
    DCSU_TX_MSG_RESP_TOO_LARGE_ACCESS_REQUEST = 0x5
    DCSU_TX_MSG_RESP_BAD_INTEGRITY_VALUE = 0x6
    DCSU_TX_MSG_RESP_SOC_FAM_ID_NOT_INIT = 0x7
    DCSU_TX_MSG_RESP_SOC_IEEE_ECID_NOT_INIT = 0x8
    DCSU_TX_MSG_RESP_GENERATE_SOC_UNIQUE_ID_NI = 0x9
    DCSU_TX_MSG_RESP_VERIFY_BLOB_FAILED = 0xA
    DCSU_TX_MSG_RESP_UNEXPECTED_NUMBER_OF_WORDS = 0xB
    DCSU_TX_MSG_RESP_UNEXPECTED_IMPORT = 0xC
    DCSU_TX_MSG_RESP_RANGE_NOT_INITIALIZED = 0xD
    DCSU_TX_MSG_RESP_GENERIC_ERROR = 0xFE
    DCSU_TX_MSG_RESP_INVALID_COMMAND = 0xFF

class dcsu_rx_message_error(Enum):
    DCSU_RX_MSG_ERROR_SUCCESS = 0x1
    DCSU_RX_MSG_ERROR_GENERIC_FAILURE = 0x2

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

def tx_command_send(backend, ctx, command : dcsu_tx_command, data : bytes = None, size = None, byteorder='little', checksum=True):
    command_word = command.value

    if (data):
        data_words = [int.from_bytes(b, byteorder=byteorder) for b in _chunk_bytes(data, 4)]

        assert (len(data_words) <= 4), "Data too large"

        if (size is not None):
            assert (len(data_words) == size), "Size does not match data"

        command_word |= ((len(data_words) - 1) & 0b11) << 8

        for r,w in zip(["DIAG_RX_DATA{}".format(i) for i in range(len(data_words))], data_words):
            backend.write_register(ctx, r, w)

        if checksum:
            checksum_value = sum(data) % ((1 << 14) - 1)
            command_word |= (checksum_value & 0x3FFF) << 10

    if (not data and size is not None):
        assert (size <= 4), "Data too large"
        command_word |= ((size - 1) & 0b11) << 8

    logger.info("Sending command {}".format(command.name))
    backend.write_register(ctx, "DIAG_RX_COMMAND", command_word)

    logger.info("Waiting for response")
    while (response := backend.read_register(ctx, "DIAG_RX_COMMAND") >> 24) == 0:
        time.sleep(0.1)

    response = dcsu_tx_message_error(response)

    logger.info("Received response {}".format(response))

    return response

def tx_command_read_data(backend, ctx, size, byteorder='little'):

    data_words = []

    for r in ["DIAG_TX_DATA{}".format(i) for i in range(size)]:
        data_words.append(backend.read_register(ctx, r))

    return b''.join([word.to_bytes(length=4, byteorder=byteorder) for word in data_words])

def rx_wait_for_command(backend, ctx, command : dcsu_rx_command):
    logger.info("Waiting for command {}".format(command.name))
    while (recieved_command := backend.read_register(ctx, "DIAG_TX_COMMAND") & 0xFF) == 0:
        time.sleep(0.1)

    assert (command.value == recieved_command), "Unexpected command {} received".format(dcsu_rx_command(recieved_command))

def rx_wait_for_any_command(backend, ctx) -> dcsu_rx_command:
    logger.info("Waiting for any command")
    while (recieved_command := backend.read_register(ctx, "DIAG_TX_COMMAND") & 0xFF) == 0:
        time.sleep(0.1)

    return dcsu_rx_command(recieved_command)

def rx_command_receive(backend, ctx, command : dcsu_rx_command) -> bytes:
    rx_wait_for_command(backend, ctx, command)

    if command in [dcsu_rx_command.DCSU_RX_COMMAND_EXPORT_DATA_NO_CHECKSUM,
                           dcsu_rx_command.DCSU_RX_COMMAND_REPORT_STATUS]:
        data = bytes(0)
        data_word_size = (backend.read_register(ctx, "DIAG_TX_COMMAND") >> 8) & 0b11

        for r in ["DIAG_TX_DATA{}".format(i) for i in range(data_word_size)]:
            data += backend.read_register(ctx, r).to_bytes(4, 'little')
    else:
        data = None

    backend.write_register(ctx, "DIAG_TX_COMMAND", dcsu_rx_message_error.DCSU_RX_MSG_ERROR_SUCCESS.value << 24)
    while (recieved_command := backend.read_register(ctx, "DIAG_TX_COMMAND") & 0xFF) != 0:
        time.sleep(0.1)
    backend.write_register(ctx, "DIAG_TX_COMMAND", 0)
    return data

def _get_data_from_args(args:argparse.Namespace) -> bytes:
    if args.data_file is not None:
        file = args.data_file
        with open(file, "rb") as f:
            data_bytes = f.read()
    else:
        data = args.data.replace("0x", "")
        assert (len(data) % 2  == 0), "Data must be a multiple of 2 hex digits"
        data_bytes = bytes.fromhex(data)

    padding =  4 - len(data_bytes) % 4
    if padding != 4:
        data_bytes += b'\0' * padding

    return data_bytes

def dcsu_tx_command_generate_soc_unique_id(backend, ctx, args: argparse.Namespace):
    return tx_command_send(backend, ctx, dcsu_tx_command.DCSU_TX_COMMAND_GENERATE_SOC_UNIQUE_ID)

def dcsu_tx_command_write_family_id(backend, ctx, args: argparse.Namespace):
    data = _get_data_from_args(args)
    return tx_command_send(backend, ctx, dcsu_tx_command.DCSU_TX_COMMAND_WRITE_SOC_FAMILY_ID, data=data, byteorder=args.byte_order)

def dcsu_tx_command_write_ieee_ecid(backend, ctx, args: argparse.Namespace):
    data = _get_data_from_args(args)
    return tx_command_send(backend, ctx, dcsu_tx_command.DCSU_TX_COMMAND_WRITE_SOC_IEEE_ECID, data=data, byteorder=args.byte_order)

def dcsu_tx_command_compute_zc_soc_id(backend, ctx, args: argparse.Namespace):
    return tx_command_send(backend, ctx, dcsu_tx_command.DCSU_TX_COMMAND_COMPUTE_ZC_SOC_IDS)

def dcsu_tx_command_read_family_id(backend, ctx, args: argparse.Namespace):
    res = tx_command_send(backend, ctx, dcsu_tx_command.DCSU_TX_COMMAND_READ_SOC_FAMILY_ID, size=1, byteorder=args.byte_order)
    time.sleep(0.1)
    if res == dcsu_tx_message_error.DCSU_TX_MSG_RESP_SUCCESS:
        data = tx_command_read_data(backend, ctx, 1, byteorder=args.byte_order)
        return res, data
    return res, None

def dcsu_tx_command_read_ieee_ecid(backend, ctx, args: argparse.Namespace):
    res = tx_command_send(backend, ctx, dcsu_tx_command.DCSU_TX_COMMAND_READ_SOC_IEEE_ECID, size=4, byteorder=args.byte_order)
    time.sleep(0.1)
    if res == dcsu_tx_message_error.DCSU_TX_MSG_RESP_SUCCESS:
        data = tx_command_read_data(backend, ctx, 4, byteorder=args.byte_order)
        return res, data
    return res, None

def dcsu_tx_command_write_soc_cfg_data(backend, ctx, args: argparse.Namespace):
    offset = int(args.offset, 0)
    backend.write_register(ctx, "DIAG_RX_LARGE_PARAM", offset)

    data = _get_data_from_args(args)

    return tx_command_send(backend, ctx, dcsu_tx_command.DCSU_TX_COMMAND_WRITE_SOC_CONFIG_DATA, data=data, byteorder=args.byte_order)

def dcsu_tx_command_compute_zc_soc_cfg(backend, ctx, args: argparse.Namespace):
    return tx_command_send(backend, ctx, dcsu_tx_command.DCSU_TX_COMMAND_COMPUTE_ZC_SOC_CFG)

def dcsu_tx_command_read_soc_cfg_data(backend, ctx, args: argparse.Namespace):
    offset = int(args.offset, 0)
    backend.write_register(ctx, "DIAG_RX_LARGE_PARAM", offset)

    size = int(args.size, 0)

    res = tx_command_send(backend, ctx, dcsu_tx_command.DCSU_TX_COMMAND_READ_SOC_CONFIG_DATA, size=size, byteorder=args.byte_order)
    time.sleep(0.1)
    if res == dcsu_tx_message_error.DCSU_TX_MSG_RESP_SUCCESS:
        data = tx_command_read_data(backend, ctx, size, byteorder=args.byte_order)
        return res, data
    return res, None

def dcsu_tx_command_import_data(backend, ctx, args: argparse.Namespace, checksum=False):
    offset = int(args.offset, 0)
    data = _get_data_from_args(args)
    data_chunks = _chunk_bytes(data, 16)

    command = (dcsu_tx_command.DCSU_TX_COMMAND_IMPORT_DATA_CHECKSUM if checksum
                else dcsu_tx_command.DCSU_TX_COMMAND_IMPORT_DATA_NO_CHECKSUM)
    for c in data_chunks:
        logger.info(f"@0x{hex(offset)}: 0x{c.hex()}")
        backend.write_register(ctx, "DIAG_RX_LARGE_PARAM", offset)
        err: dcsu_tx_message_error = tx_command_send(backend, ctx,
                                                     command,
                                                     data=c, byteorder=args.byte_order,
                                                     checksum=checksum)
        if (err != dcsu_tx_message_error.DCSU_TX_MSG_RESP_SUCCESS):
            return err
        offset += 16

    return dcsu_tx_message_error.DCSU_TX_MSG_RESP_SUCCESS

def dcsu_tx_command_import_data_no_checksum(backend, ctx, args: argparse.Namespace):
    return dcsu_tx_command_import_data(backend, ctx, args, checksum=False)

def dcsu_tx_command_import_data_checksum(backend, ctx, args: argparse.Namespace):
    return dcsu_tx_command_import_data(backend, ctx, args, checksum=True)

class provisioning_message_status(Enum):
    PROVISIONING_STATUS_SUCCESS_CONTINUE = 0x1
    PROVISIONING_STATUS_SUCCESS_COMPLETE = 0x2
    PROVISIONING_STATUS_ERROR = 0x3

def dcsu_rx_command_report_status(backend, ctx, args: argparse.Namespace):
    responses = []
    data = rx_command_receive(backend, ctx, dcsu_rx_command.DCSU_RX_COMMAND_REPORT_STATUS)
    responses.append(data)
    status = provisioning_message_status(int.from_bytes(data[0:4], 'little'))

    match(status):
        case provisioning_message_status.PROVISIONING_STATUS_SUCCESS_CONTINUE:
            report = int.from_bytes(data[4:8], 'little')
            logger.info(f"Status Report {hex(report)}...")
            return 0
        case provisioning_message_status.PROVISIONING_STATUS_SUCCESS_COMPLETE:
            report = int.from_bytes(data[4:8], 'little')
            logger.info(f"Final Status Report {hex(report)}")
            return 0
        case provisioning_message_status.PROVISIONING_STATUS_ERROR:
            report = int.from_bytes(data[4:8], 'little')
            err = int.from_bytes(data[8:12], 'little')
            logger.error(f"Error Report {report}: {hex(err)}")
            return err

def dcsu_tx_command_complete_import(backend, ctx, args: argparse.Namespace):
    res = tx_command_send(backend, ctx, dcsu_tx_command.DCSU_TX_COMMAND_COMPLETE_IMPORT_DATA)

    if res != dcsu_tx_message_error.DCSU_TX_MSG_RESP_SUCCESS:
        return res

    responses = []

    while(1):
        # Wait for status report
        data = rx_command_receive(backend, ctx, dcsu_rx_command.DCSU_RX_COMMAND_REPORT_STATUS)
        responses.append(data)
        status = provisioning_message_status(int.from_bytes(data[0:4], 'little'))

        match(status):
            case provisioning_message_status.PROVISIONING_STATUS_SUCCESS_CONTINUE:
                report = int.from_bytes(data[4:8], 'little')
                logger.info(f"Status Report {hex(report)}...")
            case provisioning_message_status.PROVISIONING_STATUS_SUCCESS_COMPLETE:
                report = int.from_bytes(data[4:8], 'little')
                logger.info(f"Final Status Report {hex(report)}")
                return res
            case provisioning_message_status.PROVISIONING_STATUS_ERROR:
                report = int.from_bytes(data[4:8], 'little')
                err = int.from_bytes(data[8:12], 'little')
                logger.error(f"Error Report {report}: {hex(err)}")
                return err

        if status == provisioning_message_status.PROVISIONING_STATUS_SUCCESS_COMPLETE:
            return responses
        time.sleep(0.1)



def dcsu_tx_command_cancel_import(backend, ctx, args: argparse.Namespace):
    return tx_command_send(backend, ctx, dcsu_tx_command.DCSU_TX_COMMAND_CANCEL_IMPORT_DATA_WITH_CHECKSUM)

def dcsu_tx_command_read_cod_data(backend, ctx, args: argparse.Namespace):
    offset = int(args.offset, 0)
    backend.write_register(ctx, "DIAG_RX_LARGE_PARAM", offset)

    size = int(args.size, 0)

    res = tx_command_send(backend, ctx, dcsu_tx_command.DCSU_TX_COMMAND_READ_COD_DATA, size=size, byteorder=args.byte_order)
    time.sleep(0.1)
    if res == dcsu_tx_message_error.DCSU_TX_MSG_RESP_SUCCESS:
        data = tx_command_read_data(backend, ctx, size, byteorder=args.byte_order)
        return res, data
    return res, None

def dcsu_tx_command_read_ec_params(backend, ctx, args: argparse.Namespace):
    offset = int(args.offset, 0)
    backend.write_register(ctx, "DIAG_RX_LARGE_PARAM", offset)

    size = int(args.size, 0)

    res = tx_command_send(backend, ctx, dcsu_tx_command.DCSU_TX_COMMAND_READ_EC_PARAMS, size=size, byteorder=args.byte_order)
    time.sleep(0.1)
    if res == dcsu_tx_message_error.DCSU_TX_MSG_RESP_SUCCESS:
        data = tx_command_read_data(backend, ctx, size, byteorder=args.byte_order)
        return res, data
    return res, None

def dcsu_rx_command_import_ready(backend, ctx, args: argparse.Namespace):
    rx_command_receive(backend, ctx, dcsu_rx_command.DCSU_RX_COMMAND_IMPORT_READY)
    return 0

def dcsu_rx_command_export_data(backend, ctx, args: argparse.Namespace):
    got_complete = False
    bytes_received = bytearray(200)
    max_len = 0

    while not got_complete:
        if (recieved_command := rx_wait_for_any_command(backend, ctx)) == \
            dcsu_rx_command.DCSU_RX_COMMAND_COMPLETE_EXPORT_DATA:
            got_complete = True

        if recieved_command == dcsu_rx_command.DCSU_RX_COMMAND_EXPORT_DATA_NO_CHECKSUM:
            offset = backend.read_register(ctx, "DIAG_TX_LARGE_PARAM")

        data = rx_command_receive(backend, ctx, recieved_command)
        if data is not None:
            max_len = offset + len(data)
            bytes_received[offset:max_len] = data

    return bytes(bytes_received[:max_len])


def dcsu_command(backend, ctx, command, args: argparse.Namespace):

    dcsu_command_handlers = {
        dcsu_tx_command.DCSU_TX_COMMAND_GENERATE_SOC_UNIQUE_ID: dcsu_tx_command_generate_soc_unique_id,
        dcsu_tx_command.DCSU_TX_COMMAND_WRITE_SOC_FAMILY_ID: dcsu_tx_command_write_family_id,
        dcsu_tx_command.DCSU_TX_COMMAND_WRITE_SOC_IEEE_ECID: dcsu_tx_command_write_ieee_ecid,
        dcsu_tx_command.DCSU_TX_COMMAND_COMPUTE_ZC_SOC_IDS: dcsu_tx_command_compute_zc_soc_id,
        dcsu_tx_command.DCSU_TX_COMMAND_READ_SOC_FAMILY_ID: dcsu_tx_command_read_family_id,
        dcsu_tx_command.DCSU_TX_COMMAND_READ_SOC_IEEE_ECID: dcsu_tx_command_read_ieee_ecid,
        dcsu_tx_command.DCSU_TX_COMMAND_WRITE_SOC_CONFIG_DATA: dcsu_tx_command_write_soc_cfg_data,
        dcsu_tx_command.DCSU_TX_COMMAND_COMPUTE_ZC_SOC_CFG: dcsu_tx_command_compute_zc_soc_cfg,
        dcsu_tx_command.DCSU_TX_COMMAND_READ_SOC_CONFIG_DATA: dcsu_tx_command_read_soc_cfg_data,
        dcsu_tx_command.DCSU_TX_COMMAND_IMPORT_DATA_NO_CHECKSUM: dcsu_tx_command_import_data_no_checksum,
        dcsu_tx_command.DCSU_TX_COMMAND_IMPORT_DATA_CHECKSUM: dcsu_tx_command_import_data_checksum,
        dcsu_tx_command.DCSU_TX_COMMAND_COMPLETE_IMPORT_DATA: dcsu_tx_command_complete_import,
        dcsu_tx_command.DCSU_TX_COMMAND_CANCEL_IMPORT_DATA_WITH_CHECKSUM: dcsu_tx_command_cancel_import,
        dcsu_tx_command.DCSU_TX_COMMAND_READ_COD_DATA: dcsu_tx_command_read_cod_data,
        dcsu_tx_command.DCSU_TX_COMMAND_READ_EC_PARAMS: dcsu_tx_command_read_ec_params,
        dcsu_rx_command.DCSU_RX_COMMAND_IMPORT_READY: dcsu_rx_command_import_ready,
        dcsu_rx_command.DCSU_RX_COMMAND_REPORT_STATUS: dcsu_rx_command_report_status,
        dcsu_rx_command.DCSU_RX_COMMAND_EXPORT_DATA_NO_CHECKSUM: dcsu_rx_command_export_data,
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
    "DCSU_TX_COMMAND_GENERATE_SOC_UNIQUE_ID": """
The DCSU_TX_COMMAND_GENERATE_SOC_UNIQUE_ID command triggers the DCSU to
generate the SOC unique ID and write its zero count.
""",
    "DCSU_TX_COMMAND_WRITE_SOC_FAMILY_ID": """
The DCSU_TX_COMMAND_WRITE_SOC_FAMILY_ID command to write input data to the SOC
Family ID.
""",
    "DCSU_TX_COMMAND_WRITE_SOC_IEEE_ECID": """
The DCSU_TX_COMMAND_WRITE_SOC_IEEE_ECID command to write input data to the SOC
IEEE ECID.
""",
    "DCSU_TX_COMMAND_COMPUTE_ZC_SOC_IDS": """
The DCSU_TX_COMMAND_COMPUTE_ZC_SOC_IDS command compute and write zero count for
the SOC Family ID and SOC IEEE ECID.
""",
    "DCSU_TX_COMMAND_READ_SOC_FAMILY_ID": """
The DCSU_TX_COMMAND_READ_SOC_FAMILY_ID command to read data from the SOC Family
ID.
""",
    "DCSU_TX_COMMAND_READ_SOC_IEEE_ECID": """
The DCSU_TX_COMMAND_READ_SOC_IEEE_ECID command to read data from the SOC IEEE
ECID.
""",
    "DCSU_TX_COMMAND_WRITE_SOC_CONFIG_DATA": """
The DCSU_TX_COMMAND_WRITE_SOC_CONFIG_DATA command write the input data at the
input offset in the SOC CFG OTP area.
""",
    "DCSU_TX_COMMAND_COMPUTE_ZC_SOC_CFG": """
The DCSU_TX_COMMAND_COMPUTE_ZC_SOC_CFG command calculates the zero count of
input start offset to input size before writing to input zero count offset.
""",
    "DCSU_TX_COMMAND_READ_SOC_CONFIG_DATA": """
The DCSU_TX_COMMAND_READ_SOC_CONFIG_DATA command read the data from the input
offset in the SOC CFG OTP area.
""",
    "DCSU_TX_COMMAND_IMPORT_DATA_NO_CHECKSUM": """
The DCSU_TX_COMMAND_IMPORT_DATA_NO_CHECKSUM command writes data to the DCSU TX
data buffer. This command may trigger multiple commands in order to copy more
data than the DCSU RX buffer size.
""",
    "DCSU_TX_COMMAND_IMPORT_DATA_CHECKSUM": """
The DCSU_TX_COMMAND_IMPORT_DATA_CHECKSUM command writes data to the DCSU TX
data buffer along with a checksum. This command may trigger multiple commands
in order to copy more data than the DCSU RX buffer size.
""",
    "DCSU_TX_COMMAND_COMPLETE_IMPORT_DATA": """
The DCSU_TX_COMMAND_COMPLETE_IMPORT_DATA command triggers the DCSU to run the
pre-defined handler on the data in the TX data buffer.
""",
    "DCSU_TX_COMMAND_CANCEL_IMPORT_DATA_WITH_CHECKSUM": """
The DCSU_TX_COMMAND_CANCEL_IMPORT_DATA_WITH_CHECKSUM command triggers the DCSU
to discard the incomplete previous loaded data.
""",
    "DCSU_RX_COMMAND_IMPORT_READY": """
The DCSU_RX_COMMAND_IMPORT_READY command waits for the DCSU to signal it is
ready for importing data.
""",
    "DCSU_RX_COMMAND_REPORT_STATUS": """
The DCSU_RX_COMMAND_REPORT_STATUS command waits for a status report from DCSU.
""",
    "DCSU_RX_COMMAND_EXPORT_DATA_WITH_CHECKSUM": """
The DCSU_RX_COMMAND_EXPORT_DATA_WITH_CHECKSUM command waits for data to be exported from the
DCSU with a checksum. This command may trigger multiple commands in order to copy more data than
the DCSU TX buffer size.
""",
    "DCSU_RX_COMMAND_EXPORT_DATA_NO_CHECKSUM": """
The DCSU_RX_COMMAND_EXPORT_DATA_NO_CHECKSUM command waits for data to be exported from the
DCSU without a checksum. This command may trigger multiple commands in order to copy more data than
the DCSU TX buffer size.
""",
    "DCSU_RX_COMMAND_COMPLETE_EXPORT_DATA": """
The DCSU_RX_COMMAND_COMPLETE_EXPORT_DATA command indicates to the DCSU that the export has
completed and that the data can be returned from the script.
""",
    "DCSU_TX_COMMAND_READ_COD_DATA": """
The DCSU_TX_COMMAND_READ_COD_DATA command reads the data from the input
offset in the COD OTP area.
""",
    "DCSU_TX_COMMAND_READ_EC_PARAMS": """
The DCSU_TX_COMMAND_READ_EC_PARAMS command reads the data from the input
offset in the endorsement certificate and params area.
""",
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

    for c in ["DCSU_TX_COMMAND_WRITE_SOC_CONFIG_DATA",
              "DCSU_TX_COMMAND_IMPORT_DATA_NO_CHECKSUM",
              "DCSU_TX_COMMAND_IMPORT_DATA_CHECKSUM"]:
        parsers[c].add_argument("--offset", help="Offset to write", required=True, default="0")

    for c in ["DCSU_TX_COMMAND_READ_SOC_CONFIG_DATA",
              "DCSU_TX_COMMAND_READ_COD_DATA",
              "DCSU_TX_COMMAND_READ_EC_PARAMS"]:
        parsers[c].add_argument("--offset", help="Offset to read", required=True, default="0")

    for c in ["DCSU_TX_COMMAND_WRITE_SOC_FAMILY_ID",
              "DCSU_TX_COMMAND_WRITE_SOC_IEEE_ECID",
              "DCSU_TX_COMMAND_WRITE_SOC_CONFIG_DATA",
              "DCSU_TX_COMMAND_IMPORT_DATA_NO_CHECKSUM",
              "DCSU_TX_COMMAND_IMPORT_DATA_CHECKSUM"]:
        mgroup = parsers[c].add_mutually_exclusive_group(required=True)
        mgroup.add_argument("--data",   help="Data to write", default="0x00")
        mgroup.add_argument("--data-file",   help="Data file to load and write")

    for c in ["DCSU_TX_COMMAND_READ_SOC_CONFIG_DATA",
              "DCSU_TX_COMMAND_READ_COD_DATA",
              "DCSU_TX_COMMAND_READ_EC_PARAMS"]:
        parsers[c].add_argument("--size", help="Size (in number of words) to read", required=True, default="4")

    for c in ["DCSU_TX_COMMAND_WRITE_SOC_FAMILY_ID",
              "DCSU_TX_COMMAND_WRITE_SOC_IEEE_ECID",
              "DCSU_TX_COMMAND_WRITE_SOC_CONFIG_DATA",
              "DCSU_TX_COMMAND_IMPORT_DATA_NO_CHECKSUM",
              "DCSU_TX_COMMAND_IMPORT_DATA_CHECKSUM",
              "DCSU_TX_COMMAND_READ_SOC_FAMILY_ID",
              "DCSU_TX_COMMAND_READ_SOC_IEEE_ECID",
              "DCSU_TX_COMMAND_READ_SOC_CONFIG_DATA",
              "DCSU_TX_COMMAND_READ_COD_DATA",
              "DCSU_TX_COMMAND_READ_EC_PARAMS"]:
        parsers[c].add_argument("--byte-order", help="Byte order of data", default="little")

    backend_name = pre_parse_backend(backends, parser)
    try:
        backend = setup_backend(backend_name)

        backend.add_args(parser)

        args = parser.parse_args()
        logging.basicConfig(level=args.log_level)

        logger.info("Using {} backend".format(backend_name))

        ctx = backend.setup_ctx(args)

        if "_RX_" in args.command:
            command = dcsu_rx_command[args.command]
            logger.info(f"res: {hex(dcsu_command(backend, ctx, command, args))}")
            sys.exit(0)
        else:
            command = dcsu_tx_command[args.command]
            match dcsu_command(backend, ctx, command, args):
                case output, data:
                    logger.info(f"res {output}: {data.hex() if data is not None else data}")
                case output:
                    logger.info(f"res {output}")
            sys.exit(0 if output == dcsu_tx_message_error.DCSU_TX_MSG_RESP_SUCCESS else output.value)
    except KeyboardInterrupt:
        sys.exit(1)
