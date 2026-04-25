#!/usr/bin/env python3
#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

import sys
import re
from datetime import datetime

def load_symbols_to_keep(symbols):
    return [re.compile(x.replace('*', '.*')) for x in symbols]

def convert_fromelf_to_symdefs(fromelf_lines, symbols_to_keep):
    lines = []
    lines.append(f"#<SYMDEFS># Generated from fromelf --text -s: Last Updated: {datetime.now()}\n")

    pattern = re.compile(r"\s*\d+\s+(\S+)\s+(?:\n\s+)?(0x[0-9a-fA-F]+)\s+(\S+)\s+(\S+)\s+(\S+)")

    for match in pattern.finditer(fromelf_lines):
        symbol, address, bind, section, stype = match.groups()

        if not any(p.search(symbol) for p in symbols_to_keep):
            continue

        # Normalize symbol type
        if stype == "Code":
            sym_type = "T"
        elif stype == "Data":
            sym_type = "D"
        else:
            sym_type = "N"  # Unknown or other

        lines.append(f"{address} {sym_type} {symbol}\n")

    return lines

def main():
    fromelf_path = sys.argv[1]
    output_path = sys.argv[2]
    symbols_list = sys.argv[3:]

    symbols_to_keep = load_symbols_to_keep(symbols_list)

    with open(fromelf_path, "r") as f:
        fromelf_lines = f.read()

    newlines = convert_fromelf_to_symdefs(fromelf_lines, symbols_to_keep)

    with open(output_path, "w") as f:
        f.writelines(newlines)

if __name__ == "__main__":
    main()
