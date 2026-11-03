#! /usr/bin/env python3
#
#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

import re
import os
import sys
import click
from inspect import signature

# Add the cwd to the path so that if there is a version of imgtool in there then
# it gets used over the system imgtool. Used so that imgtool from upstream
# mcuboot is preferred over system imgtool
cwd = os.getcwd()
sys.path = [cwd] + sys.path
import imgtool
import imgtool.main

parser_path = os.path.abspath(os.path.join(os.path.dirname(__file__), '../'))
sys.path.append(parser_path)
import bl2.macro_parser as macro_parser

sign_bin_size_re = re.compile(r"^\s*RE_SIGN_BIN_SIZE\s*=\s*(.*)")
load_addr_re = re.compile(r"^\s*RE_IMAGE_LOAD_ADDRESS\s*=\s*(.*)")
rom_fixed_re = re.compile(r"^\s*RE_IMAGE_ROM_FIXED\s*=\s*(.*)")

#This works around Python 2 and Python 3 handling character encodings
#differently. More information about this issue at
#https://click.palletsprojects.com/en/5.x/python3
os.environ['LC_ALL'] = 'C.UTF-8'
os.environ['LANG'] = 'C.UTF-8'

@click.argument('outfile')
@click.argument('infile')
@click.option('-R', '--erased-val', type=click.Choice(['0', '0xff']),
              required=False, help='The value that is read back from erased '
                                   'flash.')
@click.option('-x', '--hex-addr', type=imgtool.main.BasedIntParamType(),
              required=False, help='Adjust address in hex output file.')
@click.option('--measured-boot-record', default=False, is_flag=True, help='Add '
              'CBOR encoded measured boot record to the image manifest.')
@click.option('--image-type', type=click.Choice(['SPE', 'NSPE', 'NSPE_SPE']),
              help='Software component type for the measured boot record. '
                   'Overrides the type inferred from the layout filename.')
@click.option('--save-enctlv', default=False, is_flag=True,
              help='When upgrading, save encrypted key TLVs instead of plain '
                   'keys. Enable when BOOT_SWAP_SAVE_ENCTLV config option '
                   'was set.')
@click.option('-E', '--encrypt', metavar='filename',
              help='Encrypt image using the provided public key')
@click.option('-e', '--endian', type=click.Choice(['little', 'big']),
              default='little', help="Select little or big endian")
@click.option('--overwrite-only', default=False, is_flag=True,
              help='Use overwrite-only instead of swap upgrades')
@click.option('-M', '--max-sectors', type=int,
              help='When padding allow for this amount of sectors (defaults '
                   'to 128)')
@click.option('--confirm', default=False, is_flag=True,
              help='When padding the image, mark it as confirmed')
@click.option('--pad', default=False, is_flag=True,
              help='Pad image to the size determined by --layout, adding '
                   'trailer magic')
@click.option('-l', '--layout', help='The file containing the macros of the '
                                     'slot sizes')
@click.option('--pad-header', default=False, is_flag=True,
              help='Adds --erased-val (defaults to 0xff) --header-size times '
                   'at the beginning of the image')
@click.option('-H', '--header-size',
              callback=imgtool.main.validate_header_size,
              type=imgtool.main.BasedIntParamType(), required=True)
@click.option('-d', '--dependencies', callback=imgtool.main.get_dependencies,
              required=False, help='''Add dependence on another image, format:
                                   "(<image_ID>,<image_version>), ... "''')
@click.option('-s', '--security-counter',
              callback=imgtool.main.validate_security_counter,
              help='Specify the value of security counter. Use the `auto` '
              'keyword to automatically generate it from the image version.')
@click.option('-L', '--encrypt-keylen', type=click.Choice(['128', '256']),
              default='128',
              help='Specify the value of encrypt key length. Default 128.')
@click.option('-v', '--version', callback=imgtool.main.validate_version,
              required=True)
@click.option('--align', type=click.Choice(['1', '2', '4', '8', '16', '32']),
              required=True)
@click.option('--public-key-format', type=click.Choice(['hash', 'full']),
              default='hash', help='In what format to add the public key to '
              'the image manifest: full key or hash of the key.')
@click.option('--psa-key-ids', multiple=True, type=int, required=False,
              help='List of integer key IDs for each signature.')
@click.option('--extra-tlv', required=False, nargs=2, default=[], multiple=True,
              metavar='[tag] [value]',
              help='Unprotected vendor TLV to append. '
                   'tag is an integer (e.g. 0x00A4). '
                   'value is 0x<hexbytes> (e.g. 16 bytes of FF) or a string. '
                   'Repeat to add multiple TLVs.')
@click.option('-k', '--key', multiple=True, metavar='filename')
@click.command(help='''Create a signed or unsigned image\n
               INFILE and OUTFILE are parsed as Intel HEX if the params have
               .hex extension, otherwise binary format is used''')
def wrap(key, align, version, header_size, pad_header, layout, pad, confirm,
         max_sectors, overwrite_only, endian, encrypt, infile, outfile,
         dependencies, hex_addr, erased_val, save_enctlv, public_key_format,
         security_counter, encrypt_keylen, measured_boot_record, psa_key_ids,
         extra_tlv, image_type):

    slot_size = macro_parser.evaluate_macro(layout, sign_bin_size_re, 0, 1)
    load_addr = macro_parser.evaluate_macro(layout, load_addr_re, 0, 1)
    rom_fixed = macro_parser.evaluate_macro(layout, rom_fixed_re, 0, 1)

    if measured_boot_record:
        if image_type is not None:
            record_sw_type = image_type
        elif "_s.o" in layout:
            record_sw_type = "SPE"
        elif "_ns.o" in layout:
            record_sw_type = "NSPE"
        else:
            record_sw_type = "NSPE_SPE"
    else:
        record_sw_type = None

    if int(align) <= 8 :
        #default behaviour for max_align
        max_align=8
    else:
        #max_align must be set to align
        max_align=align

    img = imgtool.image.Image(version=imgtool.version.decode_version(version),
                              header_size=header_size, pad_header=pad_header,
                              pad=pad, confirm=confirm, align=int(align),
                              slot_size=slot_size, max_sectors=max_sectors,
                              overwrite_only=overwrite_only, endian=endian,
                              load_addr=load_addr, rom_fixed=rom_fixed,
                              erased_val=erased_val,
                              save_enctlv=save_enctlv,
                              security_counter=security_counter,
                              max_align=max_align)

    img.load(infile)
    if len(psa_key_ids) > 0:
        print("wrapper.py: PSA key ids provided: " + ", ".join(hex(x) for x in psa_key_ids))
        # The version of imgtool being used may vary depending on the platform
        # configuration, and the Image class may have different methods for setting key IDs.
        if hasattr(img, 'set_key_ids'):
            img.set_key_ids(psa_key_ids)
        elif hasattr(img, 'set_key_id'):
            img.set_key_id(psa_key_ids[0])
        else:
            raise click.UsageError("PSA key IDs provided but the image object does not support setting key IDs.")

    extra_tlvs = {}
    for tlv in extra_tlv:
        tag_str, val_str = tlv
        tag = int(tag_str, 0)
        if tag in extra_tlvs:
            raise click.UsageError(f'Extra TLV {hex(tag)} already exists.')
        if val_str.startswith('0x'):
            hexstr = val_str[2:]
            if len(hexstr) % 2:
                raise click.UsageError('Extra TLV length is odd.')
            extra_tlvs[tag] = bytes.fromhex(hexstr)
        else:
            extra_tlvs[tag] = val_str.encode('utf-8')


    for tag, val in extra_tlvs.items():
        print(f'wrapper.py: Extra TLV {hex(tag)}: {val}')

    if key:
        keys = [imgtool.main.load_key(k) for k in key]
    else:
        keys = None

    # Upstream imgtool only loads a base64 encoded AES-KW key when load_key()
    # is called with allow_aes=True. The imgtool on the tfm-2.3.0 feature
    # branch of MCUboot, which the RSE platform uses, does not have the
    # argument and loads "AES-KW:" prefixed keys as is.
    if encrypt:
        if "allow_aes" in signature(imgtool.main.load_key).parameters:
            enckey = imgtool.main.load_key(encrypt, allow_aes=True)
        else:
            enckey = imgtool.main.load_key(encrypt)
    else:
        enckey = None

    if enckey and key:
        if (isinstance(key, imgtool.keys.RSA) and
           not isinstance(enckey, imgtool.keys.RSAPublic)):
            # FIXME
            raise click.UsageError("Signing and encryption must use the same "
                                   "type of key")

    # The version of imgtool being used may vary depending on the platform
    # configuration, and the 'create' function may have different parameters.
    # Check the signature of the function to determine how to pass the key(s)
    # and extra TLVs.
    create_params = signature(img.create).parameters

    # If the 'create' function supports multiple keys, pass the list of keys.
    # Otherwise, pass only the first key.
    if keys is not None:
        key_input = keys if "keys" in create_params else keys[0]
    else:
        key_input = keys # None
    # Conditionally pass the dictionary of TLVs if the 'create' function
    # supports extra TLVs.
    kwargs = {}
    if "extra_tlvs" in create_params and extra_tlvs is not None:
        kwargs["extra_tlvs"] = extra_tlvs

    img.create(key_input, public_key_format, enckey, dependencies, record_sw_type,
                   None, encrypt_keylen=int(encrypt_keylen), **kwargs)
    img.save(outfile, hex_addr)

def main():
    wrap()

if __name__ == '__main__':
    main()
