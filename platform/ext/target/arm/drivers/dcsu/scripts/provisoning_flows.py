#!/usr/bin/env python3

#-------------------------------------------------------------------------------
# SPDX-License-Identifier: BSD-3-Clause
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#-------------------------------------------------------------------------------

import os
import yaml
import logging
import argparse

from enum import Enum
from multiprocessing import Process, Queue
from dcsu import (dcsu_tx_command,
                  dcsu_rx_command,
                  dcsu_tx_message_error,
                  dcsu_rx_message_error,
                  setup_backend,
                  dcsu_command)

# ============================= Globals ==================================== #
buildpath = ""


# ============================= Classes ==================================== #
class Command:
    """ Contains command and corresponding args """
    command_word: Enum
    command_resp: Enum
    command_data: argparse.Namespace

    offset_write_commands = \
        [dcsu_tx_command.DCSU_TX_COMMAND_WRITE_SOC_CONFIG_DATA,
         dcsu_tx_command.DCSU_TX_COMMAND_IMPORT_DATA_NO_CHECKSUM,
         dcsu_tx_command.DCSU_TX_COMMAND_IMPORT_DATA_CHECKSUM]

    offset_read_commands = \
        [dcsu_tx_command.DCSU_TX_COMMAND_READ_SOC_CONFIG_DATA,
         dcsu_tx_command.DCSU_TX_COMMAND_READ_COD_DATA,
         dcsu_tx_command.DCSU_TX_COMMAND_READ_EC_PARAMS]

    data_transfer_commands = \
        [dcsu_tx_command.DCSU_TX_COMMAND_WRITE_SOC_FAMILY_ID,
         dcsu_tx_command.DCSU_TX_COMMAND_WRITE_SOC_IEEE_ECID,
         dcsu_tx_command.DCSU_TX_COMMAND_WRITE_SOC_CONFIG_DATA,
         dcsu_tx_command.DCSU_TX_COMMAND_IMPORT_DATA_NO_CHECKSUM,
         dcsu_tx_command.DCSU_TX_COMMAND_IMPORT_DATA_CHECKSUM]

    size_read_commands = \
        [dcsu_tx_command.DCSU_TX_COMMAND_READ_SOC_CONFIG_DATA,
         dcsu_tx_command.DCSU_TX_COMMAND_READ_COD_DATA,
         dcsu_tx_command.DCSU_TX_COMMAND_READ_EC_PARAMS]

    byte_order_commands = \
        [dcsu_tx_command.DCSU_TX_COMMAND_WRITE_SOC_FAMILY_ID,
         dcsu_tx_command.DCSU_TX_COMMAND_WRITE_SOC_IEEE_ECID,
         dcsu_tx_command.DCSU_TX_COMMAND_WRITE_SOC_CONFIG_DATA,
         dcsu_tx_command.DCSU_TX_COMMAND_IMPORT_DATA_NO_CHECKSUM,
         dcsu_tx_command.DCSU_TX_COMMAND_IMPORT_DATA_CHECKSUM,
         dcsu_tx_command.DCSU_TX_COMMAND_READ_SOC_FAMILY_ID,
         dcsu_tx_command.DCSU_TX_COMMAND_READ_SOC_IEEE_ECID,
         dcsu_tx_command.DCSU_TX_COMMAND_READ_SOC_CONFIG_DATA,
         dcsu_tx_command.DCSU_TX_COMMAND_READ_COD_DATA,
         dcsu_tx_command.DCSU_TX_COMMAND_READ_EC_PARAMS]

    def __init__(self, command_word: Enum, command_resp: Enum,
                 command_data: argparse.Namespace) -> None:
        """ Command object, checks all parameters for specified command """
        if command_word in self.offset_write_commands and \
           hasattr(command_data, 'offset') is None:
            raise NameError(f'{command_word} requires write offset')

        if command_word in self.offset_read_commands and \
           hasattr(command_data, 'offset') is None:
            raise NameError(f'{command_word} requires read offset')

        if command_word in self.data_transfer_commands and \
           hasattr(command_data, 'data') is None and   \
           hasattr(command_data, 'data_file') is None:
            raise NameError(f'{command_word} requires data to transfer')

        if command_word in self.size_read_commands and \
           hasattr(command_data, 'size') is None:
            raise NameError(f'{command_word} requires read size (in words)')

        if command_word in self.byte_order_commands and \
           hasattr(command_data, 'byte_order') is None:
            raise NameError(f'{command_word} requires byte order of data')

        # if the data file is passed append to build path
        if hasattr(command_data, 'data_file'):
            command_data.data_file = \
                    os.path.join(buildpath, command_data.data_file)

        self.command_word = command_word
        self.command_resp = command_resp
        self.command_data = command_data

    def __str__(self):
        return f"Command({self.command_word.name}, {self.command_data})"

    def _exec_tx(self, backend, context) -> dcsu_tx_message_error:
        """ executes all the tx commands """
        match dcsu_command(backend, context,
                           self.command_word,
                           self.command_data):
            case output, _: return output
            case output:    return output

    def _exec_rx(self, backend, context) -> dcsu_rx_message_error:
        """ executes all the rx commands """
        return dcsu_command(backend, context,
                            self.command_word,
                            self.command_data)

    def execute(self, backend, context) -> Enum:
        """ generic execution interface """

        print(self)

        if self.command_word in dcsu_rx_command:
            return self._exec_rx(backend, context)
        if self.command_word in dcsu_tx_command:
            return self._exec_tx(backend, context)


# ============================= Functions ================================== #
def parse_yaml(file: str) -> [Command]:
    commands: [Command] = []
    contents            = None

    # extract commands
    with open(file, "r") as f:
        contents = yaml.safe_load(f)

    # parse contents
    if contents is not None:

        # create list of command names
        tx_names = [name for name in dcsu_tx_command.__members__]
        rx_names = [name for name in dcsu_rx_command.__members__]

        for c in contents.get('commands'):
            name       = c.get('name')
            response   = c.get('response')
            parameters = c.get('parameters', {})

            # convert k to enum
            if   name in tx_names: name = dcsu_tx_command[name]
            elif name in rx_names: name = dcsu_rx_command[name]
            else: raise NameError(f"invalid command {name}")

            # construct Command
            commands.append(Command(name, response,
                argparse.Namespace(**parameters) if parameters else None))

    return commands


def provison(parser: argparse.ArgumentParser) -> None:
    """ Connects to FVP, executes commands and compares to expected """
    global buildpath

    backend = setup_backend("iris")
    backend.add_args(parser)

    args = parser.parse_args()

    buildpath = args.buildpath

    context  = backend.setup_ctx(args)
    commands = parse_yaml(args.commands)

    for c in commands: c.execute(backend, context)


# ================================ Main ===================================== #
if __name__ == "__main__":
    logging.disable(logging.INFO)
    parser = argparse.ArgumentParser(
            formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    parser.add_argument("commands")
    parser.add_argument("buildpath")
    provison(parser)
