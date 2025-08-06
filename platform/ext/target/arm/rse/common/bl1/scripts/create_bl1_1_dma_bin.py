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
import pandas as pd

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


def parse_store(reference_string):
    return command_storage_locations[reference_string]

def parse_exec(reference_string):
    return command_execution_locations[reference_string]

def parse_size(reference_string):
    return sizes[reference_string]

def parse_base_address(reference_string):
    return location_base_addresses[reference_string]

def parse_register_offset(reference_string):
    reg_offset = data['common']['reg_offset']

    for reg_frame in reg_offset:
        if (reg_frame + '_') in reference_string:
            reg = reference_string.replace(reg_frame + '_',"")
            return reg_offset[reg_frame][reg]

    assert False, f"PARSE REGISTER OFFSET: Invalid register block name: {reference_string}"

def parse_reg_fields(key, reg):
    out_val = 0
    reg_desc = data['common']['ch_reg_field_desc'][key]

    for name,field_string in reg.items():
        assert (name in reg_desc), ("Invalid " + name + "register bitfield name")
        try:
            field_val = int(field_string)
        except ValueError:
            if('DECODE' in reg_desc[name]) and (field_string in reg_desc[name]['DECODE']):
                field_val = reg_desc[name]['DECODE'][field_string]
            else:
                field_val = parse(field_string)

        out_val |= (field_val&reg_desc[name]['MASK'])<<reg_desc[name]['OFFSET']

    return out_val

def parse(reference_string):
    if "-" in reference_string:
        split = reference_string.split(" - ", maxsplit=1)
        return parse(split[0].lstrip()) - parse(split[1])

    if "+" in reference_string:
        split = reference_string.split(" + ", maxsplit=1)
        return parse(split[0].lstrip()) + parse(split[1])

    if "/" in reference_string:
        split = reference_string.split(" / ", maxsplit=1)
        return parse(split[0].lstrip()) // parse(split[1])

    if "*" in reference_string:
        split = reference_string.split(" * ", maxsplit=1)
        return parse(split[0].lstrip()) * parse( split[1])

    if "_store_addr" in reference_string:
        value = parse_store(reference_string.replace("_store_addr", ""))
    elif "_exec_addr" in reference_string:
        value = parse_exec(reference_string.replace("_exec_addr", ""))
    elif "_size" in reference_string:
        value = parse_size(reference_string.replace("_size", ""))
    elif "_base_address" in reference_string:
        value = parse_base_address(reference_string.replace("_base_address", ""))
    elif "reg_offset_" in reference_string:
        value = parse_register_offset(reference_string.replace("reg_offset_", ""))
    else:
        value = int(reference_string, 0)

    logging.debug('resolving reference {} as {}'.format(reference_string, hex(value)))
    return value

def create_csv():
    for location in output_locations:
        rows = []
        address = location_base_addresses[location]
        idx = 0

        for program in data['program']:
            if program['storage_location'] == location:

                rows.append([f"# Program: {program['name']}"])
                rows.append([f"# Channel: {program.get('channel', 'N/A')}"])
                rows.append([f"# Description: {program.get('description', 'N/A')}"])
                rows.append([f"# Size: {sizes[program['name']]}"])
                rows.append([])

                for command in program['commands']:
                    rows.append([f"# Command: {command['command_name']}"])
                    rows.append(['Address', 'Register Name', 'Value'])  # Column headers
                    for i in range(int(int(sizes[command['command_name']]) / 4)):
                        rows.append([
                            f"{address:#010x}",
                            location_named_word_arrays[location][idx][0],
                            f"{location_named_word_arrays[location][idx][1]:#010x}"
                        ])
                        address += 4
                        idx += 1
                    rows.append([])

                rows.append(['#' + '-' * 30])
                rows.append([])


        df = pd.DataFrame(rows)
        location_name = location
        if location == 'otp_dma_microcode':
            location_name = 'otp'
        # Save as CSV
        csv_filename = f"{location_name}_dma_ics.csv"
        df.to_csv(os.path.join(args.output_dir,csv_filename), index=False, header=False)

# load top level input config file
with open(args.input_file, 'r') as f:
   data = yaml.load(f, Loader)

program_count = len(data["program"])

location_base_addresses={}
location_next_addresses={}
location_word_arrays={}
location_named_word_arrays={}
output_locations={}

command_storage_locations = {}
command_execution_locations = {}
sizes = {}

reserved_keys=['command_name', 'execute_link','regclear']

# Setup locations
for location in data['locations']:
    location_word_arrays[location] = []
    location_named_word_arrays[location] = []
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

#enable references to triggers
if 'triggers' in data:
    data['common']['ch_reg_field_desc']['SRCTRIGINCFG']['SRCTRIGINSEL']['DECODE']=data['triggers']
    data['common']['ch_reg_field_desc']['DESTRIGINCFG']['DESTRIGINSEL']['DECODE']=data['triggers']

for program in data['program']:
    commands = program['commands']
    for command in commands:

        header_word = 0
        command_array = []
        command_named_array = []
        #raw data to be stored at end of command
        command_data = []
        command_named_data = []

        for key in command:
            if key in reserved_keys:
                continue
            try:
                val = (int(command[key]))
            except ValueError:
                val = (int(parse(command[key])))
            except TypeError:
                val = int(int(parse_reg_fields(key, command[key])))
            if(key == 'LINKADDR'):
                try:
                    if command['execute_link']:
                        val += 1
                except KeyError:
                    # Default to performing the link
                    val += 1
            if key in data['common']['cmd_header_bit_offsets']:
                header_bit_offset = data['common']['cmd_header_bit_offsets'][key]
                header_word |= 1<<header_bit_offset
                command_array.append((val, header_bit_offset))
                command_named_array.append((key,val,header_bit_offset))
            else:
                command_data.append(val)
                command_named_data.append((key,val))

        if(command_array):

            try:
                #REGLCEAR is the LSB of the header word
                if command['regclear'] == 1:
                    header_word |= 1
            except KeyError:
                #By default if regclear is not specifed, then do not set this bit
                pass

            command_array.append((header_word,0))
            command_named_array.append(('HEADER',header_word,0))

            #Sort DMA descriptor config registers in correct order according to HEADER bitmap
            command_array = [x[0] for x in sorted(command_array, key=lambda x: x[1])]
            command_named_array = [(x[0],x[1]) for x in sorted(command_named_array, key=lambda x: x[2])]

        location_word_arrays[program['storage_location']] += command_array + command_data
        location_named_word_arrays[program['storage_location']] += command_named_array + command_named_data

def zero_count(word_array):
    zero_count = 0
    for x in word_array:
        for bit_idx in range(32):
            zero_count += (1-((x>>bit_idx)&1))
    return zero_count

for location in output_locations:
    try:
        reserved_size = data['locations'][location]['reserved']
    except KeyError:
        reserved_size = 0
    if len(location_word_arrays[location]) * 4 + reserved_size > sizes[location]:
        raise Exception

    if location == 'otp':
        #Zero-Pad OTP DMA ICS and prepend zero count at the reserved area used in integrity check
        zero_pad_length = int(sizes[location]/4) - int(reserved_size/4) - len(location_word_arrays[location])
        location_word_arrays[location] = location_word_arrays[location] + [0] * zero_pad_length
        otp_ics_zero_count = zero_count(location_word_arrays[location])
        location_word_arrays[location] = [otp_ics_zero_count, 0] + location_word_arrays[location]
        location_named_word_arrays[location] = [('zero count', otp_ics_zero_count), ('zero pad',0)] + location_named_word_arrays[location]

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

create_csv()