MAX32657
========


Introduction
------------

The MAX32657 microcontroller (MCU) is an advanced system-on-chip (SoC)
featuring an Arm® Cortex®-M33 core with single-precision floating point unit (FPU)
with digital signal processing (DSP) instructions, large flash and SRAM memories,
and the latest generation Bluetooth® 5.4 Low Energy (LE) radio.
The nano-power modes increase battery life substantially.

MAX32657 1MB flash and 256KB RAM split to define section for MCUBoot,
TF-M (S), Zephyr (NS) and storage that used for secure services and configurations.
Default layout of MAX32657 is listed in below table.

+----------+------------------+---------------------------------+
| Name     | Address[Size]    | Comment                         |
+==========+==================+=================================+
| boot     | 0x1000000[64K]   | MCU Bootloader                  |
+----------+------------------+---------------------------------+
| slot0    | 0x1010000[320k]  | Secure image slot0 (TF-M)       |
+----------+------------------+---------------------------------+
| slot0_ns | 0x1060000[576k]  | Non-secure image slot0          |
+----------+------------------+---------------------------------+
| slot1    | 0x10F0000[0k]    | Updates slot0 image             |
+----------+------------------+---------------------------------+
| slot1_ns | 0x10F0000[0k]    | Updates slot0_ns image          |
+----------+------------------+---------------------------------+
| storage  | 0x10f0000[64k]   | File system, persistent storage |
+----------+------------------+---------------------------------+


+----------------+------------------+-------------------+
| RAM            | Address[Size]    | Comment           |
+================+==================+===================+
| secure_ram     | 0x30000000[64k]  | Secure memory     |
+----------------+------------------+-------------------+
| non_secure_ram | 0x20010000[192k] | Non-Secure memory |
+----------------+------------------+-------------------+


Secure Boot ROM
---------------

MAX32657 has Secure Boot ROM that used to authenticate user code via ECDSA 256 public key.
The Secure Boot ROM is disabled on default, to enable it user need to provision device first.

ADI provides enable_secure_boot.py (under <CMAKE_BINARY_DIR>/lib/ext/tesa-toolkit-src/devices/max32657/scripts/bl1_provision)
script to simply provision the device. This script reads user certificate via command line parameter
then writes user key on the device and disables debug interface.

To create pub & private key pair for MAX32657 run:

.. code-block:: bash

    openssl ecparam -out <MY_CERT_FILE.pem> -genkey -name prime256v1


.. note::

   Debug interface will be disabled after secure boot is enabled.
   User must write final firmware before provisioning the device. It can
   be written during device provision, Just add your final firmware hex file in
   JLinkScript under <CMAKE_BINARY_DIR>/lib/ext/tesa-toolkit-src/devices/max32657/scripts/bl1_provision folder.


After secure boot has been enabled BL2 image must be signed with user certificate
otherwise Secure Boot ROM will not validate BL2 image and will not execute it.
The sign process will be done automatically if BL1 be ON ``-DBL1=ON``
The sign key can be specified over command line option -DTFM_BL2_SIGNING_KEY_PATH=<MY_KEY_FILE>
or by setting the flag in <TF-M base folder>/platform/ext/target/adi/max32657/config.cmake
Development purpose test certificate is here:
<CMAKE_BINARY_DIR>/lib/ext/tesa-toolkit-src/devices/max32657/keys/bl1_dummy.pem
It shall not been used for production purpose just for development purpose.

.. note::

   The signature generation depends on ecdsa that's have to be installed::

    pip3 install ecdsa


Building TF-M
-------------

This platform port supports TF-M regression tests (Secure and Non-secure)
with Isolation Level 1.

To build S and NS application, run the following commands:

.. note::

   Only GNU toolchain is supported.

.. note::

   Only "profile_small" predefined profile is supported.

Prepare the tf-m-tests repository inside the TF-M base folder.

.. code-block:: bash

    cd <TF-M base folder>
    git clone https://git.trustedfirmware.org/TF-M/tf-m-tests.git

.. code:: bash

    cd <TF-M base folder>/tf-m-test/tests_reg

    cmake -S <TF-M base folder> -B build_spe \
            -G"Unix Makefiles"               \
            -DTFM_PLATFORM=adi/max32657      \
            -DTFM_TOOLCHAIN_FILE=[tf-m path]/toolchain_GNUARM.cmake \
            -DTEST_S=OFF                \
            -DTEST_NS=ON               \
            -DTFM_NS_REG_TEST=ON        \
            -DMCUBOOT_LOG_LEVEL="INFO"  \
            -DTFM_ISOLATION_LEVEL=1
    cmake --build build_spe -- install

    cmake -S . -B build_test    \
            -G"Unix Makefiles"  \
            -DCONFIG_SPE_PATH=[tf-m-tests path]/tests_reg/build_spe/api_ns \
            -DTFM_TOOLCHAIN_FILE=cmake/toolchain_ns_GNUARM.cmake \
            -DTFM_NS_REG_TEST=ON
    cmake --build build_test


Merge and Flash Images
----------------------

Follow the steps below to program the flash with a compiled TF-M image (i.e. S, NS or both).


Generate Intel hex files from the output binary (bin) files as follows:

.. code-block:: console

    srec_cat build_test/bin/tfm_ns_signed.bin -binary --offset 0x01060000 -o build_test/bin/tfm_ns_signed.hex -intel


Merge hex files as follows:

.. code-block:: console

    srec_cat.exe build_spe/bin/bl2.hex -Intel build_spe/bin/tfm_s_signed.hex -Intel build_test/bin/tfm_ns_signed.hex -Intel -o tfm_merged.hex -Intel

.. note::

   Use bl2_signed.hex instead bl2.hex if Secure Boot ROM is enabled.


Flash them with JLink as follows:

.. code-block:: console

    JLinkExe -device MAX32657 -if swd -speed 2000 -autoconnect 1
    J-Link>h
    J-Link>r
    J-Link>erase
    J-Link>loadfile build_spe/bin/tfm_merged.hex


BL2 and TF-M Provisioning
-------------------------

On default ``-DPLATFORM_DEFAULT_PROVISIONING=ON`` and ``-DTFM_DUMMY_PROVISIONING=ON``
which will use default provisioning and dummpy keys, these configuration is fine
for development purpose but for production customer specific keys shall be used
Provisioning bundles can be generated with the ``-DPLATFORM_DEFAULT_PROVISIONING=OFF`` flag.
The provisioning bundle binary will be generated and it's going to contain
the provisioning code and provisioning values.

If ``-DPLATFORM_DEFAULT_PROVISIONING=OFF`` and ``-DTFM_DUMMY_PROVISIONING=ON`` then the keys in
the ``tf-m/platform/ext/target/common/provisioning/provisioning_config.cmake`` and the
default MCUBoot signing keys will be used for provisioning.

If ``-DPLATFORM_DEFAULT_PROVISIONING=OFF`` and ``-DTFM_DUMMY_PROVISIONING=OFF`` are set
then unique values can be used for provisioning. The keys and seeds can be changed by
passing the new values to the build command, or by setting the ``-DPROVISIONING_KEYS_CONFIG`` flag
to a .cmake file that contains the keys. An example config cmake file can be seen at
``tf-m/platform/ext/target/common/provisioning/provisioning_config.cmake``.
Otherwise new random values are going to be generated and used. For the image signing
the ${MCUBOOT_KEY_S} and ${MCUBOOT_KEY_NS} will be used. These variables should point to
.pem files that contain the code signing private keys. The public keys are going to be generated
from these private keys and will be used for provisioning. The hash of the public key is going to
be written into the ``provisioning_data.c`` automatically.

If ``-DMCUBOOT_GENERATE_SIGNING_KEYPAIR=ON`` is set then a new mcuboot signing public and private
keypair is going to be generated and it's going to be used to sign the S and NS binaries.

The new generated keypair can be found in the ``<build dir>/bin`` folder or in the
``<install directory>/image_signing/keys`` after installation.
The generated provisioning_data.c file can be found at
``<build directory>/platform/target/provisioning/provisioning_data.c``

.. note::

   The provisioning bundle generation depends on pyelftools that's have to be installed::

    pip3 install pyelftools

UART Console
************

MAX32657 has one UART (UART0) peripheral which is routed for Non-Secure console output by default.
S and NS firmware can not use UART at the same time.
If TFM_S_REG_TEST been defined the UART console will be routed to the Secure side otherwise it will
be on NS side.

--------------

*Copyright 2025 Analog Devices, Inc. All rights reserved.
*SPDX-License-Identifier: BSD-3-Clause*
