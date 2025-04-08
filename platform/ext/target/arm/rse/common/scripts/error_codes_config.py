#!/usr/bin/env python3
import sys
import os
import c_struct
import c_include
import sys
import argparse
import arg_utils
import subprocess

sys.path.append(os.path.join(sys.path[0], 'modules'))

class Error_codes_config:
    def __init__(self, enums):
        self.__dict__ = {}
        for e in enums:
            self.__dict__ |= enums[e].dict

    @staticmethod
    def create(h_file_path_list, includes, defines):
        enums = {}
        for h_file_path, enum_name in h_file_path_list.items():
            enums |= {enum_name : c_struct.C_enum.from_h_file(h_file_path, enum_name, includes, defines)}

        return Error_codes_config(enums)

    def get_enum_list(self):
        return {k: v.get_value() for k, v in self.__dict__.items()}

def create_error_code_csv(config : Error_codes_config):
    enum_list = config.get_enum_list()

    output = []
    for enum, value in enum_list.items():
        output.append("{}, {},\n".format(enum, hex(value)))

    return output

def get_compiler_include_dirs(compiler):
    result = subprocess.run(
        [compiler, "-E", "-x", "c", "-", "-v"],
        input="",
        capture_output=True,
        text=True
    )

    include_dirs = []
    started = False
    for line in result.stderr.splitlines():
        if "#include <...> search starts here:" in line:
            started = True
            continue
        elif "End of search list." in line:
            break
        elif started:
            include_dirs.append(line.strip())

    return include_dirs

def parse_error_code_header_file(headers):
    mapping = {}
    for file_h in headers:
        file_path, enum_name = file_h.split(':', 1)
        file_path = file_path.strip()
        enum_name = enum_name.strip()

        if not os.path.isfile(file_path):
            raise FileNotFoundError(f"Header file not found: {file_path}")
        mapping[file_path] = enum_name
    return mapping

script_description = """
This script generate an Error codes table in CSV format which can be used to
check uart error values with more ease.
"""
if __name__ == "__main__":
    import c_include

    parser = argparse.ArgumentParser(allow_abbrev=False,
                                     formatter_class=argparse.ArgumentDefaultsHelpFormatter,
                                     description=script_description)

    parser.add_argument("headers", nargs="+", help="List of error code headers as 'filename:enum_name'")

    parser.add_argument("--compile_commands_file", help="path to compile_commands.json", required=True)
    parser.add_argument("--c_compiler", help="path to c compiler", required=True)

    parser.add_argument("--error_code_output_file", help="File to output error code to",
                        required=True, type=arg_utils.arg_type_text_output_file)

    args = parser.parse_args()

    includes = c_include.get_includes(args.compile_commands_file, "boot_hal_bl1_1.c")
    includes.extend(get_compiler_include_dirs(args.c_compiler))

    defines = c_include.get_defines(args.compile_commands_file, "boot_hal_bl1_1.c")

    header_details = parse_error_code_header_file(args.headers)

    config = Error_codes_config.create(header_details, includes, defines)

    csv_content = create_error_code_csv(config)
    args.error_code_output_file.writelines(csv_content)
