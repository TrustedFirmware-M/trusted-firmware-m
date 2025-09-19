#!/usr/bin/env python3
#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

from tfm_tools import arg_utils, c_struct, c_macro, c_include
import argparse
import pickle
import re
import networkx as nx

import logging
logger = logging.getLogger("TF-M.{}".format(__name__))

def add_arguments(parser : argparse.ArgumentParser,
                  prefix : str = "",
                  required : bool = True,
                  ) -> None:

    return arg_utils.add_prefixed_argument(parser, "routing_tables", prefix=prefix,
                                           help="Path to routing tables pickle",
                                           type=Routing_tables.from_config_file,
                                           required=required)

def parse_args(args : argparse.Namespace,
               prefix : str = "",
               ) -> dict:
    out = {}

    if "routing_tables" not in out.keys():
        out |= arg_utils.parse_args_automatically(args, ["routing_tables"], prefix)

    return out


def load_graph(filename):
    assert(filename[-4:] == ".tgf")

    with open(filename, 'rt') as graph_file:
        lines = graph_file.readlines()

    graph = nx.DiGraph()

    re_line = re.compile(r"(\d+) (\d+) Node (\d+) Link (\d+) Node (\d+) Link (\d+)")
    re_node = re.compile(r"(\d+) ([a-zA-Z0-9\s-]+)")
    edge = [0] * 2
    node = [0] * 2
    link = [0] * 2

    for line in lines:
        line = line.strip()
        line_match = re_line.fullmatch(line)
        node_match = re_node.fullmatch(line)
        if line_match is not None:
            edge[0], edge[1], node[0], link[0], node[1], link[1] = map(int, line_match.groups())
            assert (edge[0] == node[0]) and (edge[1] == node[1])
            assert (link[0] != 0) and (link[1] != 0)
            graph.add_edge(edge[0], edge[1], link=link[0])
            graph.add_edge(edge[1], edge[0], link=link[1])
        elif node_match is not None:
            node_idx, node_name = node_match.groups()
            graph.add_node(int(node_idx), name=node_name)
        else:
            assert line == ''

    return graph

def routing_tables_from_graph(graph, rse_id, num_nodes):
    routing_table = [0] * num_nodes

    for destination in range(num_nodes):
        if destination is rse_id:
            continue

        logger.info("Finding path from {} to {}".format(rse_id, destination))
        path = nx.shortest_path(graph, rse_id, destination)
        nexthop = path[1]
        routing_table[destination] = graph[rse_id][nexthop]['link']

    routing_table_bytes = bytes(0)
    for table_entry in routing_table:
        routing_table_bytes += table_entry.to_bytes(1, byteorder='little')

    return routing_table_bytes

class Routing_tables:
    def __init__(self, routing_tables):
        self.routing_tables = routing_tables

    @staticmethod
    def from_h_file(h_file_path, includes, defines):
        routing_tables_struct =  c_struct.C_struct.from_h_file(h_file_path,
                                                              "rse_whole_system_routing_tables_t",
                                                              includes, defines)

        return Routing_tables(routing_tables_struct)

    @staticmethod
    def from_config_file(file_path):
        with open(file_path, "rb") as f:
            return pickle.load(f)

    def get_number_rses(self):
        return self.routing_tables.routing_table.get_size() // self.routing_tables.routing_table[0].get_size()

    def get_routing_tables_source(self):
        return self.routing_tables.get_value_str()

    def get_routing_tables_bytes(self):
        return self.routing_tables.to_bytes()

    def set_routing_tables_bytes(self, value):
        self.routing_tables.set_value_from_bytes(value)

    def get_rse_routing_table_bytes(self, rse_id):
        return self.routing_tables.routing_table[rse_id].to_bytes()

    def set_rse_routing_table_bytes(self, rse_id, table):
        self.routing_tables.routing_table[rse_id].routing_table.set_value_from_bytes(table)

    def to_config_file(self, file_path):
        with open(file_path, "wb") as f:
            pickle.dump(self, f)

script_description = """
This script takes an input of the header file containing the RSE routing tables
definition and uses the TGF file definition to populate this structure with the
defined routing tables. This structure is then output to a pickle file where it
can be used by other scripts (such as the OTP config generation script)
"""
def main():
    parser = argparse.ArgumentParser(allow_abbrev=False,
                                     formatter_class=argparse.ArgumentDefaultsHelpFormatter,
                                     description=script_description)
    parser.add_argument("--rse_routing_tables_h_file", help="path to rse_routing_tables.h", type=arg_utils.arg_type_input_filepath, required=True)
    parser.add_argument("--compile_commands_file", help="path to compile_commands.json", type=arg_utils.arg_type_input_filepath, required=True)
    parser.add_argument("--topology_graph_file", help="The topology graph file expressing the system", type=arg_utils.arg_type_input_filepath, required=True)
    parser.add_argument("--routing_tables_output_file", help="file to output routing tables to", required=True)
    parser.add_argument("--log_level", help="log level", required=False, default="ERROR", choices=logging._levelToName.values())#

    args = parser.parse_args()
    logging.getLogger("TF-M").setLevel(args.log_level)
    logger.addHandler(logging.StreamHandler())

    includes = c_include.get_includes(args.compile_commands_file, "rse_get_routing_tables.c")
    defines = c_include.get_defines(args.compile_commands_file, "rse_get_routing_tables.c")

    routing_tables = Routing_tables.from_h_file(args.rse_routing_tables_h_file, includes, defines)

    graph = load_graph(args.topology_graph_file)
    number_rses = routing_tables.get_number_rses()
    number_nodes = graph.number_of_nodes()
    # Assumes that RSE nodes are defined before any other components
    for rse_id in range(number_rses):
        table = routing_tables_from_graph(graph, rse_id, number_nodes)
        routing_tables.set_rse_routing_table_bytes(rse_id, table)

    routing_tables.to_config_file(args.routing_tables_output_file)


if __name__ == "__main__":
    main()
