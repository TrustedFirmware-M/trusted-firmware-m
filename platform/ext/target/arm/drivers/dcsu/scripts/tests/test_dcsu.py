#!/usr/bin/env python3

#-------------------------------------------------------------------------------
# SPDX-License-Identifier: BSD-3-Clause
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#-------------------------------------------------------------------------------

import sys
import os
import tempfile

parent_dir = os.path.join(os.path.dirname(os.path.realpath(__file__)), "..")
sys.path.append(parent_dir)

from dcsu import *

TEST_DATA_BYTES = b"\xAB\xCD\xEF\x10\x01\x23\x45\x67" * 128

def get_random_bytes(num_bytes):
    return os.urandom(num_bytes)

def setup_args(args, data=None, data_file=None, offset=0x0, byte_order='little'):
    assert (data is not None) ^ (data_file is not None)
    args.offset = str(offset)
    if data is not None:
        args.data = '0x' + data.hex()
    else:
        args.data = None
    args.data_file = data_file
    args.byte_order = byte_order

def test_initial_import_ready(backend, ctx, args):
    status = dcsu_command(backend, ctx, dcsu_rx_command.DCSU_RX_COMMAND_IMPORT_READY, args)
    return status == 0

def test_data_with_checksum(backend, ctx, args):
    setup_args(args, get_random_bytes(28), None, 0x0)
    status = dcsu_command(backend, ctx, dcsu_tx_command.DCSU_TX_COMMAND_IMPORT_DATA_CHECKSUM, args)
    if status != dcsu_tx_message_error.DCSU_TX_MSG_RESP_SUCCESS:
        return False

    status = dcsu_command(backend, ctx, dcsu_tx_command.DCSU_TX_COMMAND_CANCEL_IMPORT_DATA_WITH_CHECKSUM, args)
    return status == dcsu_tx_message_error.DCSU_TX_MSG_RESP_SUCCESS

def test_data_without_checksum(backend, ctx, args):
    setup_args(args, get_random_bytes(28), None, 0x0)
    status = dcsu_command(backend, ctx, dcsu_tx_command.DCSU_TX_COMMAND_IMPORT_DATA_NO_CHECKSUM, args)
    return status == dcsu_tx_message_error.DCSU_TX_MSG_RESP_SUCCESS

def test_data_without_checksum_outside_buffer(backend, ctx, args):
    # Buffer passed in test_dcsu_drv.c is 1024 bytes
    setup_args(args, get_random_bytes(28), None, 1025)
    status = dcsu_command(backend, ctx, dcsu_tx_command.DCSU_TX_COMMAND_IMPORT_DATA_NO_CHECKSUM, args)
    return status == dcsu_tx_message_error.DCSU_TX_MSG_RESP_TOO_LARGE_OFFSET_PARAM

def test_data_without_checksum_offset_max_size(backend, ctx, args):
    # Use UINT32_MAX to check for naive overflow check
    setup_args(args, get_random_bytes(28), None, 2**32 - 1)
    status = dcsu_command(backend, ctx, dcsu_tx_command.DCSU_TX_COMMAND_IMPORT_DATA_NO_CHECKSUM, args)
    return status == dcsu_tx_message_error.DCSU_TX_MSG_RESP_TOO_LARGE_OFFSET_PARAM

def test_data_without_checksum_too_large(backend, ctx, args):
    # Buffer passed in test_dcsu_drv.c is 1024 bytes
    setup_args(args, get_random_bytes(1026), None, 0x0)
    status = dcsu_command(backend, ctx, dcsu_tx_command.DCSU_TX_COMMAND_IMPORT_DATA_NO_CHECKSUM, args)
    return status == dcsu_tx_message_error.DCSU_TX_MSG_RESP_TOO_LARGE_OFFSET_PARAM

def test_file_with_checksum(backend, ctx, args):
    random_bytes = get_random_bytes(28)
    with tempfile.NamedTemporaryFile() as tmp_file:
        tmp_file.write(random_bytes)
        setup_args(args, None, tmp_file.name, 0x0)

        status = dcsu_command(backend, ctx, dcsu_tx_command.DCSU_TX_COMMAND_IMPORT_DATA_CHECKSUM, args)
        if status != dcsu_tx_message_error.DCSU_TX_MSG_RESP_SUCCESS:
            return False

        status = dcsu_command(backend, ctx, dcsu_tx_command.DCSU_TX_COMMAND_CANCEL_IMPORT_DATA_WITH_CHECKSUM, args)
        if status != dcsu_tx_message_error.DCSU_TX_MSG_RESP_SUCCESS:
            return False

    return True

class invalid_dcsu_rx_command(Enum):
    DCSU_RX_INVALID_COMMAND = 0xDE

def test_invalid_command(backend, ctx, args):
    dummy_data = bytes([0xEF])
    backend.write_register(ctx, "DIAG_RX_LARGE_PARAM", 0x0)
    status = tx_command_send(backend, ctx, invalid_dcsu_rx_command.DCSU_RX_INVALID_COMMAND,
                             dummy_data, len(dummy_data), 'little', False)
    return status == dcsu_tx_message_error.DCSU_TX_MSG_RESP_INVALID_COMMAND

class dcsu_rx_command_override_checksum(Enum):
    # IMPORT_DATA_WITH_CHECKSUM command with the
    # checksum field set to a random value
    DCSU_RX_COMMAND_OVERRIDE_CHECKSUM = ((0xDEAD & 0x3FFF) << 10) | (0xB)

def test_invalid_checksum(backend, ctx, args):
    data = get_random_bytes(16)
    backend.write_register(ctx, "DIAG_RX_LARGE_PARAM", 0x0)
    status = tx_command_send(backend, ctx,
                             dcsu_rx_command_override_checksum.DCSU_RX_COMMAND_OVERRIDE_CHECKSUM,
                             data, len(data), 'little', True)
    if status != dcsu_tx_message_error.DCSU_TX_MSG_RESP_BAD_INTEGRITY_VALUE:
        return False

    # Send cancellation to reset checksum condition
    status = tx_command_send(backend, ctx, dcsu_tx_command.DCSU_TX_COMMAND_CANCEL_IMPORT_DATA_WITH_CHECKSUM)
    return status == dcsu_tx_message_error.DCSU_TX_MSG_RESP_SUCCESS

def test_specific_data_with_checksum(backend, ctx, args):
    setup_args(args, TEST_DATA_BYTES, None, 0x0)
    status = dcsu_command(backend, ctx, dcsu_tx_command.DCSU_TX_COMMAND_IMPORT_DATA_CHECKSUM, args)
    return status == dcsu_tx_message_error.DCSU_TX_MSG_RESP_SUCCESS

def test_specific_file_with_checksum(backend, ctx, args):
    with tempfile.NamedTemporaryFile(mode='wb', delete=False) as tmp_file:
        tmp_file.write(TEST_DATA_BYTES)
        tmp_file_name = tmp_file.name

    setup_args(args, None, tmp_file.name, 0x0)

    status = dcsu_command(backend, ctx, dcsu_tx_command.DCSU_TX_COMMAND_IMPORT_DATA_CHECKSUM, args)
    failed = (status == dcsu_tx_message_error.DCSU_TX_MSG_RESP_SUCCESS)

    os.remove(tmp_file_name)
    return failed

def test_send_completion(backend, ctx, args):
    status = tx_command_send(backend, ctx, dcsu_tx_command.DCSU_TX_COMMAND_COMPLETE_IMPORT_DATA)
    return status == dcsu_tx_message_error.DCSU_TX_MSG_RESP_SUCCESS

tests_0001 = [
    ("Initial IMPORT_READY command", test_initial_import_ready)
]

tests_0002 = [
    ("Data with checksum", test_data_with_checksum),
    ("Data without checksum", test_data_without_checksum),
    ("Data without checksum overwrite buffer", test_data_without_checksum_outside_buffer),
    ("Data without checksum offset UINT32_MAX", test_data_without_checksum_offset_max_size),
    ("Data without checksum data too large", test_data_without_checksum_too_large),
    ("File with checksum", test_file_with_checksum),
    ("Invalid command", test_invalid_command),
    ("Invalid checksum", test_invalid_checksum),
]

tests_0003 = [
    ("Specific data with checksum", test_specific_data_with_checksum),
]

tests_0004 = [
    ("Specific data in file with checksum", test_specific_file_with_checksum),
]

# Complete command tells the RSE to move onto the next test
tests_send_completion = [
    ("Send completion", test_send_completion),
]

tests_defs = tests_0001 + \
            tests_0002 + tests_send_completion + \
            tests_0003 + tests_send_completion + \
            tests_0004 + tests_send_completion

def test_fail(name):
    print("\033[31m")
    print(f"TEST: {name} FAILED")
    print("\033[0m")

def test_pass(name):
    print("\033[32m")
    print(f"TEST: {name} PASSED")
    print("\033[0m")

def run_tests(backend, ctx, args):
    for test in tests_defs:
        status = test[1](backend, ctx, args)
        assert isinstance(status, bool)
        if status:
            test_pass(test[0])
        else:
            test_fail(test[0])
            sys.exit(1)

script_description = """
Test script for dcsu.py. Requires the DCSU test binary running on the RSE
"""

if __name__ == "__main__":
    backend_dir = os.path.join(os.path.dirname(os.path.realpath(__file__)), "../backends")
    backends = os.listdir(backend_dir)
    backends = [b.replace("dcsu_backend_","").replace(".py", "") for b in backends if ".py" in b]

    parser = argparse.ArgumentParser(allow_abbrev=False,
                                     formatter_class=argparse.ArgumentDefaultsHelpFormatter,
                                     description=script_description)

    backend_name = pre_parse_backend(backends, parser)

    backend = setup_backend(backend_name)

    backend.add_args(parser)

    args = parser.parse_args()
    logging.basicConfig(level='DEBUG')

    logger.info("Using {} backend".format(backend_name))

    ctx = backend.setup_ctx(args)

    run_tests(backend, ctx, args)
