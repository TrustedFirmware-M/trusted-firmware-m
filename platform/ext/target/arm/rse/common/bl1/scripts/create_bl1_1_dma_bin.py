#-------------------------------------------------------------------------------
# Copyright (c) 2023, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------
import yaml
import logging, logging.handlers
import os
import argparse

from yaml.loader import SafeLoader

# logging setup
logging.basicConfig(level=logging.WARNING, format='%(name)s - %(levelname)s - %(message)s')

parser = argparse.ArgumentParser(allow_abbrev=False)
parser.add_argument("--input_file", help="DMA programs high level yaml file", required=True)
parser.add_argument("--output_dir", help="Output directory", required=True)
args = parser.parse_args()

class Loader(yaml.SafeLoader):
    def __init__(self, stream):
        self._root = os.path.split(stream.name)[0]
        super(Loader, self).__init__(stream)

    # load nested yaml files (if any)
    def include(self, node):
        filepath = os.path.join(self._root, self.construct_scalar(node))
        command_name = os.path.basename(self.construct_scalar(node)).replace('.yaml', '')

        with open(filepath, 'r') as f:
            child_node = yaml.load(f, Loader)
            child_node['command_name'] = command_name
            return child_node

Loader.add_constructor('!include', Loader.include)

# calculate header word from bit fields
def calculate_header_word(header):
    final_val=0
    for i in range(len(header)):
        for key in header[i]:
            val=header[i][key]
            final_val = final_val + (val << i)
    return final_val


def parse_store(command, key, reference_string):
    return command_storage_locations[reference_string]

def parse_exec(command, key, reference_string):
    command_location = command_execution_locations[reference_string]
    # Need to set bit 0 if the link should be executed
    if key != 'SRCADDR' and key != 'DESADDR':
        try:
            if command['execute_link']:
                command_location += 1
        except KeyError:
            # Default to performing the link
            command_location += 1
    return command_location

def parse_size(command, key, reference_string):
    size = sizes[reference_string]
    if key == 'XSIZE':
        size = size // 4
        size &= 0xFFFF
        size |= size << 16
    elif key != 'SRCADDR' and key != 'DESADDR':
        # Convert size to words
        size = size // 4
    return size

def parse_base_address(command, key, reference_string):
    return location_base_addresses[reference_string]

def parse_register_offset(reference_string):
    reg_offset = data['common']['reg_offset']

    for reg_frame in reg_offset:
        if (reg_frame + '_') in reference_string:
            reg = reference_string.replace(reg_frame + '_',"")
            return reg_offset[reg_frame][reg]

    assert False, f"PARSE REGISTER OFFSET: Invalid register block name: {reference_string}"

def parse(command, key, reference_string):
    if "-" in reference_string:
        split = reference_string.split(" - ", maxsplit=1)
        return parse(command, key, split[0].lstrip()) - parse(command, key, split[1])

    if "+" in reference_string:
        split = reference_string.split(" + ", maxsplit=1)
        return parse(command, key, split[0].lstrip()) + parse(command, key, split[1])

    if "/" in reference_string:
        split = reference_string.split(" / ", maxsplit=1)
        return parse(command, key, split[0].lstrip()) // parse(command, key, split[1])

    if "*" in reference_string:
        split = reference_string.split(" * ", maxsplit=1)
        return parse(command, key, split[0].lstrip()) * parse(command, key, split[1])

    if "_store_addr" in reference_string:
        value = parse_store(command, key, reference_string.replace("_store_addr", ""))
    elif "_exec_addr" in reference_string:
        value = parse_exec(command, key, reference_string.replace("_exec_addr", ""))
    elif "_size" in reference_string:
        value = parse_size(command, key, reference_string.replace("_size", ""))
    elif "_base_address" in reference_string:
        value = parse_base_address(command, key, reference_string.replace("_base_address", ""))
    elif "reg_offset_" in reference_string:
        value = parse_register_offset(reference_string.replace("reg_offset_", ""))
    else:
        value = int(reference_string, 0)

    logging.debug('resolving reference {} as {}'.format(reference_string, hex(value)))
    return value

# load top level input config file
with open(args.input_file, 'r') as f:
   data = yaml.load(f, Loader)

program_count = len(data["program"])

location_base_addresses={}
location_next_addresses={}
location_word_arrays={}
output_locations={}

command_storage_locations = {}
command_execution_locations = {}
sizes = {}

reserved_keys=['command_name', 'execute_link','regclear']

# Setup locations
for location in data['locations']:
    location_word_arrays[location] = []
    location_base_addresses[location] = data['locations'][location]['base_address']
    try:
        reserved_size = data['locations'][location]['reserved']
    except KeyError:
        reserved_size = 0
    location_next_addresses[location] = data['locations'][location]['base_address'] + reserved_size
    try:
        sizes[location] = data['locations'][location]['size']
        size = sizes[location]
    except KeyError:
        size = 'unknown'
        pass
    logging.info('Location {} at {}, size {}, first usable address {}'.format(
        location,
        hex(location_base_addresses[location]),
        size,
        hex(location_next_addresses[location])))

for program in data['program']:
    commands = program['commands']
    sizes[program['name']] = 0
    for command in commands:

        cmd_has_header_word = False
        cmd_non_header_word_count = 0

        for key in command:
            if key in data['common']['cmd_header_bit_offsets']:
                #if there are DMA config registers specified in the yaml file then treat this command
                #file as a DMA descriptor with a leading header word.
                cmd_has_header_word = True
            if key not in reserved_keys:
                cmd_non_header_word_count +=1

        command_size = (cmd_non_header_word_count + cmd_has_header_word)*4

        sizes[command['command_name']] = command_size
        sizes[program['name']] += command_size
        command_storage_locations[command['command_name']] = location_next_addresses[program['storage_location']]
        command_execution_locations[command['command_name']] = location_next_addresses[program['execution_location']]
        location_next_addresses[program['storage_location']] += command_size
        # don't increment twice if the storage location is the same as the
        # execution location
        if location_next_addresses[program['storage_location']] != location_next_addresses[program['execution_location']]:
            location_next_addresses[program['execution_location']] += command_size
        output_locations[program['storage_location']] = True
        logging.info('Command {} stored at {}, executed from {}, size {}'.format(
            command['command_name'],
            hex(command_storage_locations[command['command_name']]),
            hex(command_execution_locations[command['command_name']]),
            sizes[command['command_name']],
            ))
    logging.info('Program {} stored at {}, executed from {}, size {}'.format(
        program['name'],
        hex(location_next_addresses[program['storage_location']] - sizes[program['name']]),
        hex(location_next_addresses[program['execution_location']] - sizes[program['name']]),
        sizes[program['name']],
        ))

for program in data['program']:
    commands = program['commands']
    for command in commands:

        header_word = 0
        command_array = []
        #raw data to be stored at end of command
        command_data = []

        for key in command:
            if key in reserved_keys:
                continue
            try:
                val = (int(command[key]))
            except ValueError:
                val = (int(parse(command, key, command[key])))
            if key in data['common']['cmd_header_bit_offsets']:
                header_bit_offset = data['common']['cmd_header_bit_offsets'][key]
                header_word |= 1<<header_bit_offset
                command_array.append((val, header_bit_offset))
            else:
                command_data.append(val)

        if(command_array):

            try:
                #REGLCEAR is the LSB of the header word
                if command['regclear'] == 1:
                    header_word |= 1
            except KeyError:
                #By default if regclear is not specifed, then do not set this bit
                pass

            command_array.append((header_word,0))

            #Sort DMA descriptor config registers in correct order according to HEADER bitmap
            command_array = [x[0] for x in sorted(command_array, key=lambda x: x[1])]

        location_word_arrays[program['storage_location']] += command_array + command_data


for location in output_locations:
    try:
        reserved_size = data['locations'][location]['reserved']
    except KeyError:
        reserved_size = 0
    if len(location_word_arrays[location]) * 4 + reserved_size > sizes[location]:
        raise Exception
    with open(os.path.join(args.output_dir, location + "_dma_ics.bin"), mode="wb") as bin_file:
        with open(os.path.join(args.output_dir, location + "_dma_ics.hex"), mode="wt") as hex_file:
            logging.info('Writing output binary for location {} to file {} of size {}'.format(
                location, os.path.join(args.output_dir, location + "_dma_ics.bin"),
                len(location_word_arrays[location]) * 4))
            logging.info('Writing output hex for location {} to file {} of size {}'.format(
                location, os.path.join(args.output_dir, location + "_dma_ics.hex"),
                len(location_word_arrays[location]) * 4))
            for word in location_word_arrays[location]:
                bin_file.write(word.to_bytes(4, byteorder='little'))
                hex_file.write(word.to_bytes(4, byteorder='big').hex() + '\n')
