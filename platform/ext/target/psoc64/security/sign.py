#!/usr/bin/python3
"""
Copyright (c) 2019 Cypress Semiconductor Corporation

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
"""

import cysecuretools
import sys, getopt

def main(argv):
    s_hex_file=""
    ns_hex_file=""
    policy_file=""
    try:
        opts, args = getopt.getopt(argv,"hs:n:p:", ["s_hex=", "ns_hex=", "policy="])
    except getopt.GetoptError:
        print ('sign.py -s_hex <tfm_s hex> -ns_hex <tfm_ns hex> -policy <policy json>')
        sys.exit(2)
    for opt, arg in opts:
        if opt == '-h':
            print ('sign.py -s_hex <tfm_s hex> -ns_hex <tfm_ns hex> -policy <policy json>')
            sys.exit()
        elif opt in ("-s", "--s_hex"):
            s_hex_file = arg
        elif opt in ("-n", "--ns_hex"):
            ns_hex_file = arg
        elif opt in ("-p", "--policy"):
            policy_file = arg
    print ('tfm_s :', s_hex_file)
    print ('tfm_ns:', ns_hex_file)
    print ('policy:', policy_file)

    cysecuretools.sign_image(s_hex_file, policy_file, 1);
    cysecuretools.sign_image(ns_hex_file, policy_file, 16);

if __name__ == "__main__":
   main(sys.argv[1:])
