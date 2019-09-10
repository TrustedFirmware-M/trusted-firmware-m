# Copyright 2017 Linaro Limited
# Copyright (c) 2018-2019, Arm Limited.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

"""
Image signing and management.
"""

from . import version as versmod
import hashlib
import struct

IMAGE_MAGIC = 0x96f3b83d
IMAGE_HEADER_SIZE = 32
TLV_HEADER_SIZE = 4
PAYLOAD_DIGEST_SIZE = 32  # SHA256 hash
KEYHASH_SIZE = 32
DEP_IMAGES_KEY = "images"
DEP_VERSIONS_KEY = "versions"

# Image header flags.
IMAGE_F = {
        'PIC':                   0x0000001,
        'NON_BOOTABLE':          0x0000010,
        'RAM_LOAD':              0x0000020, }
TLV_VALUES = {
        'KEYHASH': 0x01,
        'KEY'    : 0x02,
        'SHA256' : 0x10,
        'RSA2048': 0x20,
        'RSA3072': 0x23,
        'DEPENDENCY': 0x40,
        'SEC_CNT': 0x50, }

TLV_INFO_SIZE = 4
TLV_INFO_MAGIC = 0x6907

# Sizes of the image trailer, depending on flash write size.
trailer_sizes = {
    write_size: 128 * 3 * write_size + 8 * 2 + 16
    for write_size in [1, 2, 4, 8]
}

boot_magic = bytearray([
    0x77, 0xc2, 0x95, 0xf3,
    0x60, 0xd2, 0xef, 0x7f,
    0x35, 0x52, 0x50, 0x0f,
    0x2c, 0xb6, 0x79, 0x80, ])

class TLV():
    def __init__(self):
        self.buf = bytearray()

    def add(self, kind, payload):
        """Add a TLV record.  Kind should be a string found in TLV_VALUES above."""
        buf = struct.pack('<BBH', TLV_VALUES[kind], 0, len(payload))
        self.buf += buf
        self.buf += payload

    def get(self):
        header = struct.pack('<HH', TLV_INFO_MAGIC, TLV_INFO_SIZE + len(self.buf))
        return header + bytes(self.buf)

class Image():
    @classmethod
    def load(cls, path, included_header=False, **kwargs):
        """Load an image from a given file"""
        with open(path, 'rb') as f:
            payload = f.read()
        obj = cls(**kwargs)
        obj.payload = payload

        # Add the image header if needed.
        if not included_header and obj.header_size > 0:
            obj.payload = (b'\000' * obj.header_size) + obj.payload

        obj.check()
        return obj

    def __init__(self, version, header_size=IMAGE_HEADER_SIZE, security_cnt=0,
                 pad=0):
        self.version = version
        self.header_size = header_size or IMAGE_HEADER_SIZE
        self.security_cnt = security_cnt
        self.pad = pad

    def __repr__(self):
        return "<Image version={}, header_size={}, security_counter={}, \
                 pad={}, payloadlen=0x{:x}>".format(
                self.version,
                self.header_size,
                self.security_cnt,
                self.pad,
                len(self.payload))

    def save(self, path):
        with open(path, 'wb') as f:
            f.write(self.payload)

    def check(self):
        """Perform some sanity checking of the image."""
        # If there is a header requested, make sure that the image
        # starts with all zeros.
        if self.header_size > 0:
            if any(v != 0 and v != b'\000' for v in self.payload[0:self.header_size]):
                raise Exception("Padding requested, but image does not start with zeros")

    def sign(self, key, ramLoadAddress, dependencies=None):
        # Size of the security counter TLV:
        # header ('BBH') + payload ('I') = 8 Bytes
        protected_tlv_size = TLV_INFO_SIZE + 8

        if dependencies is None:
            dependencies_num = 0
        else:
            # Size of a dependency TLV:
            # header ('BBH') + payload('IBBHI') = 16 Bytes
            dependencies_num = len(dependencies[DEP_IMAGES_KEY])
            protected_tlv_size += (dependencies_num * 16)

        self.add_header(key, protected_tlv_size, ramLoadAddress)

        tlv = TLV()

        payload = struct.pack('I', self.security_cnt)
        tlv.add('SEC_CNT', payload)

        if dependencies_num != 0:
            for i in range(dependencies_num):
                payload = struct.pack(
                                '<'+'B3x'+'BBHI',
                                int(dependencies[DEP_IMAGES_KEY][i]),
                                dependencies[DEP_VERSIONS_KEY][i].major,
                                dependencies[DEP_VERSIONS_KEY][i].minor,
                                dependencies[DEP_VERSIONS_KEY][i].revision,
                                dependencies[DEP_VERSIONS_KEY][i].build
                                )
                tlv.add('DEPENDENCY', payload)

        # Full TLV size needs to be calculated in advance, because the
        # header will be protected as well
        full_size = (TLV_INFO_SIZE + len(tlv.buf) + TLV_HEADER_SIZE
                     + PAYLOAD_DIGEST_SIZE)
        if key is not None:
            pub = key.get_public_bytes()
            if key.get_public_key_format() == 'hash':
                tlv_key_data_size = KEYHASH_SIZE
            else:
                tlv_key_data_size = len(pub)

            full_size += (TLV_HEADER_SIZE + tlv_key_data_size
                          + TLV_HEADER_SIZE + key.sig_len())
        tlv_header = struct.pack('HH', TLV_INFO_MAGIC, full_size)
        self.payload += tlv_header + bytes(tlv.buf)

        sha = hashlib.sha256()
        sha.update(self.payload)
        digest = sha.digest()

        tlv.add('SHA256', digest)

        if key is not None:
            if key.get_public_key_format() == 'hash':
                sha = hashlib.sha256()
                sha.update(pub)
                pubbytes = sha.digest()
                tlv.add('KEYHASH', pubbytes)
            else:
                tlv.add('KEY', pub)

            sig = key.sign(self.payload)
            tlv.add(key.sig_tlv(), sig)

        self.payload += tlv.get()[protected_tlv_size:]

    def add_header(self, key, protected_tlv_size, ramLoadAddress):
        """Install the image header.

        The key is needed to know the type of signature, and
        approximate the size of the signature."""

        flags = 0
        if ramLoadAddress is not None:
            # add the load address flag to the header to indicate that an SRAM
            # load address macro has been defined
            flags |= IMAGE_F["RAM_LOAD"]

        fmt = ('<' +
            # type ImageHdr struct {
            'I' +    # Magic    uint32
            'I' +    # LoadAddr uint32
            'H' +    # HdrSz    uint16
            'H' +    # PTLVSz   uint16
            'I' +    # ImgSz    uint32
            'I' +    # Flags    uint32
            'BBHI' + # Vers     ImageVersion
            'I'      # Pad1     uint32
            ) # }
        assert struct.calcsize(fmt) == IMAGE_HEADER_SIZE
        header = struct.pack(fmt,
                IMAGE_MAGIC,
                0 if (ramLoadAddress is None) else ramLoadAddress, # LoadAddr
                self.header_size,
                protected_tlv_size,  # TLV info header + SC TLV (+ DEP. TLVs)
                len(self.payload) - self.header_size, # ImageSz
                flags, # Flags
                self.version.major,
                self.version.minor or 0,
                self.version.revision or 0,
                self.version.build or 0,
                0)  # Pad1
        self.payload = bytearray(self.payload)
        self.payload[:len(header)] = header

    def pad_to(self, size, align):
        """Pad the image to the given size, with the given flash alignment."""
        tsize = trailer_sizes[align]
        padding = size - (len(self.payload) + tsize)
        if padding < 0:
            msg = "Image size (0x{:x}) + trailer (0x{:x}) exceeds requested size 0x{:x}".format(
                    len(self.payload), tsize, size)
            raise Exception(msg)
        pbytes  = b'\xff' * padding
        pbytes += b'\xff' * (tsize - len(boot_magic))
        pbytes += boot_magic
        self.payload += pbytes
