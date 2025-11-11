# -------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
# -------------------------------------------------------------------------------

from tfm_tools.c_struct import C_struct
from tfm_tools.c_macro import C_macro
import pickle
from os.path import isfile, dirname, isdir

region_names = ['header', 'cm', 'bl1_2', 'dm', 'soc', 'dynamic']

class OTP_config:
    def __init__(self, header, cm, bl1_2, dm, dynamic, soc, defines):
        self.header = header
        self.cm = cm
        self.bl1_2 = bl1_2
        self.dm = dm
        self.dynamic = dynamic
        self.soc = soc
        self.defines = defines
        self.defines._definitions = {k: v for k, v in self.defines._definitions.items()
                                     if not callable(v)}

        self.defines.__dict__ = {k: v for k, v in self.defines.__dict__.items()
                                 if not callable(v)}

        self.__dict__ |= self.defines._definitions

    @staticmethod
    def from_h_file(h_file_path, includes, defines):
        make_region = lambda x: C_struct.from_h_file(h_file_path,
                                                    "rse_otp_{}_area_t".format(x),
                                                    includes, defines)
        regions = [make_region(x) for x in region_names]

        for r, n in zip(regions, region_names):
            r.name = n

        regions = {r.name: r for r in regions}

        config = C_macro.from_h_file(h_file_path, includes, defines)

        return OTP_config(defines=config, **regions)

    @staticmethod
    def from_config_file(file):
        if isinstance(file, str):
            assert isfile(file), "File {} does not exist".format(file)
            file = open(file, "rb")

        return pickle.load(file)

    def __str__(self):
        out = ""
        for r in region_names:
            out += str(getattr(self, r)) + "\n\n"
        return out[:-2]

    def set_cm_offsets_automatically(self,
                                     dm_sets_dm_and_dynamic_area_size : bool = None
                                     ):
        offset_counter = 0
        if dm_sets_dm_and_dynamic_area_size is None:
            dm_sets_dm_and_dynamic_area_size = hasattr(self, "DM_SETS_DM_AND_DYNAMIC_AREA_SIZE")

        offset_counter += self.header.get_size()
        assert (offset_counter % 4) == 0, "Header area size {} not aligned to 4 byte boundary".format(offset_counter)
        self.header.cm_area_info.offset.set_value(offset_counter)
        self.header.cm_area_info.size.set_value(self.cm.get_size())

        offset_counter += self.cm.get_size()
        assert (offset_counter % 4) == 0, "CM area size {} not aligned to 4 byte boundary".format(offset_counter)
        self.header.bl1_2_area_info.offset.set_value(offset_counter)
        self.header.bl1_2_area_info.size.set_value(self.bl1_2.get_size())

        soc_area_size = self.soc.get_size()
        otp_size = int(self.RSE_OTP_SIZE)
        assert (soc_area_size % 4) == 0, "SOC area size {} not aligned to 4 byte boundary".format(soc_area_size)
        self.header.soc_area_info.offset.set_value(otp_size - soc_area_size)
        self.header.soc_area_info.size.set_value(soc_area_size)

        if not dm_sets_dm_and_dynamic_area_size:
            offset_counter += self.bl1_2.get_size()
            assert (offset_counter % 4) == 0, "Bl1_2 area size {} not aligned to 4 byte boundary".format(offset_counter)
            self.header.dm_area_info.offset.set_value(offset_counter)
            self.header.dm_area_info.size.set_value(self.dm.get_size())

            offset_counter += self.dm.get_size()
            assert (offset_counter % 4) == 0, "DM area size {} not aligned to 4 byte boundary".format(offset_counter)
            soc_area_offset = self.header.soc_area_info.offset.get_value()
            self.header.dynamic_area_info.offset.set_value(offset_counter)
            assert offset_counter + self.dynamic.get_size() <= soc_area_offset, "Memory layout overflows OTP size {} > {}, shortfall is {}".format(hex(offset_counter), hex(soc_area_offset), hex(offset_counter - soc_area_offset))
            self.header.dynamic_area_info.size.set_value(soc_area_offset - offset_counter)

    def set_dm_offsets_automatically(self):
        self.set_cm_offsets_automatically(False)

    def to_config_file(self, file):
        if isinstance(file, str):
            dir = dirname(file)
            if not dir:
                dir = "."
            assert isdir(dir), "Directory {} does not exist to create file ".format(dir)
            file = open(file, "wb")
        pickle.dump(self, file)

    def set_value_from_bytes(self, b):
        self.header.set_value_from_bytes(b[:self.header._size])

        for r in region_names[1:-1]:
            offset = getattr(self.header, "{}_area_info".format(r)).offset.get_value()
            size = getattr(self.header, "{}_area_info".format(r)).size.get_value()

            if (offset and size):
                getattr(self, r).set_value_from_bytes(b[offset:offset + size])

        offset = self.header.dynamic_area_info.offset.get_value()
        self.dynamic.set_value_from_bytes(b[offset:offset+self.dynamic._size])

    def to_bytes(self):
        b = self.header.to_bytes()
        b += bytes(16384 - len(b))
        b = bytearray(b)

        for r in region_names[1:]:
            offset = getattr(self.header, "{}_area_info".format(r)).offset.get_value()
            size = getattr(self.header, "{}_area_info".format(r)).size.get_value()

            if (offset and size):
                b[offset:offset + size] = getattr(self, r).to_bytes()

        return b
