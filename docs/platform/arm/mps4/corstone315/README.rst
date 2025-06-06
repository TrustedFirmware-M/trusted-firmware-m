Corstone SSE-315 with Ethos-U65 Example Subsystem for Ecosystem FVP
===================================================================

Introduction
------------

Corstone-315 is an Arm reference subsystem for secure System on Chips containing
an Armv8.1-M Cortex-M85 processor and LCM, KMU and SAM IPs. and an
Ethos-U65 neural network processor. It is an MPS4 based platform.

This platform port supports all TF-M regression tests (Secure and Non-secure)
with Isolation Level 1 and 2.

.. note::

   For Ethos-U65 IP this platform support only provides base address,
   interrupt number and an example NPU setup as non-secure, unprivileged.

.. note::

   For Armclang compiler v6.18 or later version is required.

Building TF-M
-------------

Follow the instructions in :doc:`Building instructions </building/tfm_build_instruction>`.
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Build instructions with platform name: arm/mps4/corstone315
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
``-DTFM_PLATFORM=arm/mps4/corstone315``

.. note::

   The built binaries can be run on the Corstone-315 Ethos-U65 Ecosystem FVP
   (FVP_Corstone_SSE-315).

.. note::

   If ``-DTFM_DUMMY_PROVISIONING=ON`` then the keys in the
   ``tf-M/platform/ext/target/arm/mps4/common/provisioning/bundle_cm/cm_provisioning_config.cmake``,
   ``tf-M/platform/ext/target/arm/mps4/common/provisioning/bundle_dm/dm_provisioning_config.cmake`` and
   default MCUBoot signing and encryption keys will be used for provisioning.

   If ``-DTFM_DUMMY_PROVISIONING=OFF`` is set then unique values can be used for provisioning. The keys
   and seeds can be changed by passing the new values to the build command, or by setting the
   ``-DDM_PROVISIONING_KEYS_CONFIG`` and  ``-DCM_PROVISIONING_KEYS_CONFIG`` flag to the ``.cmake`` files
   which contain the keys. An example config cmake file can be seen at
   ``tf-m/platform/ext/target/arm/mps4/common/provisioning/bundle_cm/cm_provisioning_config.cmake``
   and ``tf-m/platform/ext/target/arm/mps4/common/provisioning/bundle_dm/dm_provisioning_config.cmake``.
   Otherwise new random values are going to be generated and used (or default values in some cases).

   For signing the BL2 image, ``${TFM_BL1_2_CM_SIGNING_KEY_PATH}`` key will be used. This should point
   to a valid LMS ``.pub`` file. The private key is found with the ``.prv`` extension. If
   ``-DTFM_GENERATE_BL1_2_CM_SIGNING_KEY=ON`` is set, then a new signing public and private keypair
   is going to be generated and it's going to be used to sign the the BL2 image.

   For the image signing the ``${MCUBOOT_KEY_S}`` and ``${MCUBOOT_KEY_NS}`` will be used. These variables
   should point to ``.pem`` files that contain the code signing private keys. The public keys are going
   to be generated from these private keys and will be used for provisioning. The hash of the public
   key is going to be written into the ``provisioning_data.c`` automatically. For the BL2 image
   encryption the ``TFM_BL2_ENCRYPTION_KEY_PATH`` has to be set to a .bin file which contains the
   encryption key.
   (For an example, see ``tf-m/bl1/bl1_2/bl2_dummy_encryption_key.bin``)

   If ``-DMCUBOOT_GENERATE_SIGNING_KEYPAIR=ON`` is set then a new MCUBoot signing public and private
   keypair is going to be generated and it's going to be used to sign the S and NS binaries.


   The new generated keypair can be found in the ``<build dir>/bin`` folder or in the
   ``<install directory>/image_signing/keys`` after installation.
   The generated provisioning_data.c file can be found at
   ``<build directory>/platform/target/provisioning/provisioning_data.c``

.. note::

   The provisioning bundle generation depends on pyelftools that's have to be installed::

    pip3 install pyelftools


To run the example code on Corstone-315 Ethos-U65 Ecosystem FVP
---------------------------------------------------------------
FVP is available to download `here <https://developer.arm.com/Tools%20and%20Software/Fixed%20Virtual%20Platforms/IoT%20FVPs>`__

#. Install the FVP
#. Copy ``bl1_1.bin``, ``cm_provisioning_bundle.bin``, ``dm_provisioning_bundle.bin``,
   ``bl2_signed.bin`` and ``tfm_s_ns_signed.bin``  files from
   build dir to ``<FVP installation path>/models/Linux64_GCC-6.4/``
#. Navigate to the same directory and execute the following command to start FVP::

    $ ./FVP_Corstone_SSE-315 --data "bl1_1.bin"@0x11000000
                   --data "cm_provisioning_bundle.bin"@0x12024000
                   --data "dm_provisioning_bundle.bin"@0x1202aa00
                   --data "bl2_signed.bin"@0x12031400
                   --data "tfm_s_ns_signed.bin"@0x38000000


#. After completing the procedure you should be able to see similar messages
   to this on the serial port (baud 115200 8n1)::

    Trying 127.0.0.1...
    Connected to localhost.
    Escape character is '^]'.
    [INF] Starting TF-M BL1_1
    [INF] Beginning provisioning
    [INF] TP mode set complete, system will now reset.
    [INF] Starting TF-M BL1_1
    [INF] Beginning provisioning
    [INF] Waiting for CM provisioning bundle
    [INF] Enabling secure provisioning mode, system will now reset.
    [INF] Starting TF-M BL1_1
    [INF] Beginning provisioning
    [INF] Waiting for CM provisioning bundle
    [INF] Running CM provisioning bundle
    [INF] Starting TF-M BL1_1
    [INF] Beginning provisioning
    [INF] Waiting for DM provisioning bundle
    [INF] Enabling secure provisioning mode, system will now reset.
    [INF] Starting TF-M BL1_1
    [INF] Beginning provisioning
    [INF] Waiting for DM provisioning bundle
    [INF] Running DM provisioning bundle
    [INF] Starting TF-M BL1_1
    [INF] Jumping to BL1_2
    [INF] starting TF-M bl1_2
    [INF] Attempting to boot image 0
    [INF] BL2 image decrypted successfully
    [INF] BL2 image validated successfully
    [INF] Jumping to BL2
    [INF] Starting bootloader
    [INF] Image index: 1, Swap type: none
    [INF] Image index: 0, Swap type: none
    [INF] Bootloader chainload address offset: 0x0
    [INF] Jumping to the first image slot
    Booting TF-M v2.0.0+d09934721
    Non-Secure system starting...

.. note::

   Some of the messages above are only visible when ``CMAKE_BUILD_TYPE`` is set
   to ``Debug``.

-------------

*Copyright (c) 2024-2025, Arm Limited. All rights reserved.*
