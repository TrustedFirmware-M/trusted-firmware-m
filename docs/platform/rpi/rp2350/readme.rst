RP2350
======

Introduction
------------

RP2350 features a dual-core Arm Cortex-M33 processor with 520 kiB on-chip SRAM,
support for up to 16MB of off-chip flash and a wide range of flexible I/O option
including I2C, SPI, and - uniquely - Programmable I/O (PIO). With its security
features RP2350 offers significant enhancements over RP2040.

This platform port supports TF-M regression tests (Secure and Non-secure)
with Isolation Level 1 and 2.

.. note::

   Only GNU toolchain is supported.

Building TF-M
-------------

Follow the instructions in :doc:`Building instructions </building/tfm_build_instruction>`.
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Build instructions with platform name: rpi/rp2350
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
``-DTFM_PLATFORM=rpi/rp2350``

.. note::

   This platform port relies on
   `Raspberry Pi Pico SDK <https://github.com/raspberrypi/pico-sdk>`__
   Make sure it is either cloned locally or available to download during build.
   SDK version used for testing: SDK 2.0.0 release

.. note::

   Building the default platform configuration requires the board to be
   provisioned. For this the provision bundle needs to be built and run on the
   board with ``-DPLATFORM_DEFAULT_PROVISIONING=OFF``. The binary must be
   placed in flash at the address defined by ``PROVISIONING_BUNDLE_START``. One
   way to do this is to generate a .uf2 file containing the bundle at the start
   address and copy it to the board. There is an example in the provided
   pico_uf2.sh script and in the description below.

   If ``-DPLATFORM_DEFAULT_PROVISIONING=OFF`` and
   ``-DTFM_DUMMY_PROVISIONING=ON`` then the keys in the
   ``tf-m/platform/ext/common/provisioning_bundle/provisioning_config.cmake``
   and the default MCUBoot signing keys will be used for provisioning.

   If ``-DPLATFORM_DEFAULT_PROVISIONING=OFF`` and
   ``-DTFM_DUMMY_PROVISIONING=OFF`` are set then unique values can be used for
   provisioning. The keys and seeds can be changed by passing the new values to
   the build command, or by setting the ``-DPROVISIONING_KEYS_CONFIG`` flag to a
   .cmake file that contains the keys. An example config cmake file can be seen
   at
   ``tf-m/platform/ext/common/provisioning_bundle/provisioning_config.cmake``.
   Otherwise new random values are going to be generated and used. For the image
   signing the ${MCUBOOT_KEY_S} and ${MCUBOOT_KEY_NS} will be used. These
   variables should point to .pem files that contain the code signing private
   keys. The public keys are going to be generated from these private keys and
   will be used for provisioning. The hash of the public key is going to be
   written into the ``provisioning_data.c`` automatically.

   If ``-DMCUBOOT_GENERATE_SIGNING_KEYPAIR=ON`` is set then a new mcuboot
   signing public and private keypair is going to be generated and it's going to
   be used to sign the S and NS binaries.

   The new generated keypair can be found in the ``<build dir>/bin`` folder or
   in the ``<install directory>/image_signing/keys`` after installation.
   The generated provisioning_data.c file can be found at
   ``<build directory>/platform/target/provisioning/provisioning_data.c``

.. note::

   The provisioning bundle generation depends on pyelftools that's have to be
   installed::

    pip3 install pyelftools

Example build instructions for regression tests with dummy keys:
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Building Secure side with provisioning bundle:

.. note::

   Add -DTFM_MULTI_CORE_TOPOLOGY=ON to the above for multicore support


.. code-block:: bash

     cmake -S <TF-M tests source dir>/tests_reg/spe \
     -B <TF-M tests source dir>/tests_reg/spe/build_rpi_myns_single \
     -DTFM_PLATFORM=rpi/rp2350 \
     -DTFM_TOOLCHAIN_FILE=<TF-M source dir>/toolchain_GNUARM.cmake \
     -DCONFIG_TFM_SOURCE_PATH=<TF-M source dir> \
     -DTFM_PROFILE=profile_medium -DPLATFORM_DEFAULT_PROVISIONING=OFF \
     -DTEST_S=ON -DTEST_NS=ON

.. code-block:: bash

     cmake --build <TF-M tests source dir>/tests_reg/spe/build_rpi_myns_single \
     -- -j8 install


Building Non-Secure side:

.. code-block:: bash

     cmake -S <TF-M tests source dir>/tests_reg \
     -B <TF-M tests source dir>/tests_reg/build_rpi_myns_single \
     -DCONFIG_SPE_PATH=<TF-M tests source dir>/tests_reg/spe/build_rpi_myns_single/api_ns \
     -DTFM_TOOLCHAIN_FILE=<TF-M tests source dir>/tests_reg/spe/build_rpi_myns_single/api_ns/cmake/toolchain_ns_GNUARM.cmake
     cmake --build <TF-M tests source dir>/tests_reg/build_rpi_myns_single -- -j8

Binaries need to be converted with a small script pico_uf2.sh
It uses uf2conv.py from here:
https://github.com/microsoft/uf2/blob/master/utils/uf2conv.py
It depends on:
https://github.com/microsoft/uf2/blob/master/utils/uf2families.json
The tool takes the combined and signed S and NS images in .bin format, and
outputs .uf2. It also generates the .uf2 for the bootloader (bl2.uf2) and the
provisioning bundle.

.. code-block:: bash

     pico_uf2.sh <TF-M tests source dir> build_rpi_myns_single

Then just copy the bl2.uf and tfm_s_ns_signed.bin.uf2 files to the board. It
will run the BL2, S and NS tests and print the results to the UART (Baudrate
115200).
If the board needs provisioning, the .uf2 file containing the provisioning
bundle needs to be copied before tfm_s_ns_signed.bin.uf2. It only needs to be
done once.

-------------

 *SPDX-License-Identifier: BSD-3-Clause*
 *SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors*
