########################
Cypress PSoC 6 Specifics
########################

******************************************
Building Multi-Core TF-M on Cypress PSoC 6
******************************************

Please make sure you have all required software installed as explained in the
:doc:`software requirements </docs/user_guides/tfm_sw_requirement>`.

Please install CySecureTools with (requires Python3.7):

.. code-block:: bash

    pip install cysecuretools

For more details please refer to
`CySecureTools <https://pypi.org/project/cysecuretools>`_ page.

Please also make sure that all the source code are fetched by following
:doc:`general building instruction </docs/user_guides/tfm_build_instruction>`.


Configuring the build
=====================

The build configuration for TF-M is provided to the build system using command
line arguments:

.. list-table::
   :widths: 20 80

   * - -DPROJ_CONFIG=<file>
     - Specifies the way the application is built.

       | <file> is the absolute path to configurations file
         named as ``Config<APP_NAME>.cmake``.
       | e.g. On Linux:
         ``-DPROJ_CONFIG=`readlink -f ../configs/ConfigRegressionIPC.cmake```
       | Supported configurations files

           - IPC model without regression test suites in Isolation Level 1
             ``ConfigCoreIPC.cmake``
           - IPC model with regression test suites in Isolation Level 1
             ``ConfigRegressionIPC.cmake``
           - IPC model with PSA API test suite in Isolation Level 1
             ``ConfigPsaApiTestIPC.cmake``
           - IPC model without regression test suites in Isolation Level 2
             ``ConfigCoreIPCTfmLevel2.cmake``
           - IPC model with regression test suites in Isolation Level 2
             ``ConfigRegressionIPCTfmLevel2.cmake``
           - IPC model with PSA API test suite in Isolation Level 2
             ``ConfigPsaApiTestIPCTfmLevel2.cmake``

   * - -DTARGET_PLATFORM=psoc64
     - Specifies target platform name ``psoc64``

   * - -DCOMPILER=<compiler name>
     - Specifies the compiler toolchain
       The possible values are:

         - ``ARMCLANG``
         - ``GNUARM``

   * - -DCMAKE_BUILD_TYPE=<build type>
     - Configures debugging support.
       The possible values are:

         - ``Debug``
         - ``Release``


Build Instructions
==================

The following instructions build multi-core TF-M without regression test suites
in Isolation Level 1 on Linux.
Both the compiler and the debugging type can be changed to other configurations
listed above.

.. code-block:: bash

    cd <TF-M base folder>
    cd <trusted-firmware-m folder>

    mkdir <build folder>
    pushd <build folder>
    cmake -G"Unix Makefiles" -DPROJ_CONFIG=`readlink -f ../configs/ConfigCoreIPC.cmake` -DTARGET_PLATFORM=psoc64 -DCOMPILER=ARMCLANG -DCMAKE_BUILD_TYPE=Debug ../
    popd
    cmake --build <build folder> -- -j VERBOSE=1

The following instructions build multi-core TF-M with regression test suites
in Isolation Level 1 on Linux.
Both the compiler and the debugging type can be changed to other configurations
listed above.

.. code-block:: bash

    cd <TF-M base folder>
    cd <trusted-firmware-m folder>

    mkdir <build folder>
    pushd <build folder>
    cmake -G"Unix Makefiles" -DPROJ_CONFIG=`readlink -f ../configs/ConfigRegressionIPC.cmake` -DTARGET_PLATFORM=psoc64 -DCOMPILER=ARMCLANG -DCMAKE_BUILD_TYPE=Debug ../
    popd
    cmake --build <build folder> -- -j VERBOSE=1

The following instructions build multi-core TF-M with PSA API test suite for
the attestation service in Isolation Level 1 on Linux.
Both the compiler and the debugging type can be changed to other configurations
listed above.

.. list-table::
   :widths: 20 80

   * - -DPSA_API_TEST_BUILD_PATH=<path> (optional)
     - Specifies the path to the PSA API build directory

         - ``${TFM_ROOT_DIR}/../psa-arch-tests/api-tests/BUILD`` (default)

   * - -D<PSA_API_TEST_xxx>=1 (choose exactly one)
     - Specifies the service to support
       The possible values are:

         - ``PSA_API_TEST_ATTESTATION``
         - ``PSA_API_TEST_CRYPTO``
         - ``PSA_API_TEST_SECURE_STORAGE``
         - ``PSA_API_TEST_INTERNAL_TRUSTED_STORAGE``

.. code-block:: bash

    cd <TF-M base folder>
    cd <trusted-firmware-m folder>

    mkdir <build folder>
    pushd <build folder>
    cmake ../ \
        -G"Unix Makefiles" \
        -DPROJ_CONFIG=`readlink -f ../configs/ConfigPsaApiTestIPC.cmake` \
        -DPSA_API_TEST_BUILD_PATH=../psa-arch-tests/api-tests/BUILD_ATT.GNUARM
        -DPSA_API_TEST_ATTESTATION=1 \
        -DTARGET_PLATFORM=psoc64 \
        -DCOMPILER=ARMCLANG \
        -DCMAKE_BUILD_TYPE=Debug
    popd
    cmake --build <build folder> -- -j VERBOSE=1

The following instructions build multi-core TF-M without regression test suites
in Isolation Level 2 on Linux.
Both the compiler and the debugging type can be changed to other configurations
listed above.

.. code-block:: bash

    cd <TF-M base folder>
    cd <trusted-firmware-m folder>

    mkdir <build folder>
    pushd <build folder>
    cmake -G"Unix Makefiles" -DPROJ_CONFIG=`readlink -f ../configs/ConfigCoreIPCTfmLevel2.cmake` -DTARGET_PLATFORM=psoc64 -DCOMPILER=ARMCLANG -DCMAKE_BUILD_TYPE=Debug ../
    popd
    cmake --build <build folder> -- -j VERBOSE=1

The following instructions build multi-core TF-M with regression test suites
in Isolation Level 2 on Linux.
Both the compiler and the debugging type can be changed to other configurations
listed above.

.. code-block:: bash

    cd <TF-M base folder>
    cd <trusted-firmware-m folder>

    mkdir <build folder>
    pushd <build folder>
    cmake -G"Unix Makefiles" -DPROJ_CONFIG=`readlink -f ../configs/ConfigRegressionIPCTfmLevel2.cmake` -DTARGET_PLATFORM=psoc64 -DCOMPILER=ARMCLANG -DCMAKE_BUILD_TYPE=Debug ../
    popd
    cmake --build <build folder> -- -j VERBOSE=1

The following instructions build multi-core TF-M with PSA API test suite for
the protected storage service in Isolation Level 2 on Linux.
Both the compiler and the debugging type can be changed to other configurations
listed above.

.. list-table::
   :widths: 20 80

   * - -DPSA_API_TEST_BUILD_PATH=<path> (optional)
     - Specifies the path to the PSA API build directory

         - ``${TFM_ROOT_DIR}/../psa-arch-tests/api-tests/BUILD`` (default)

   * - -D<PSA_API_TEST_xxx>=1 (choose exactly one)
     - Specifies the service to support
       The possible values are:

         - ``PSA_API_TEST_ATTESTATION``
         - ``PSA_API_TEST_CRYPTO``
         - ``PSA_API_TEST_SECURE_STORAGE``
         - ``PSA_API_TEST_INTERNAL_TRUSTED_STORAGE``

.. code-block:: bash

    cd <TF-M base folder>
    cd <trusted-firmware-m folder>

    mkdir <build folder>
    pushd <build folder>
    cmake ../ \
        -G"Unix Makefiles" \
        -DPROJ_CONFIG=`readlink -f ../configs/ConfigPsaApiTestIPCTfmLevel2.cmake` \
        -DPSA_API_TEST_BUILD_PATH=../psa-arch-tests/api-tests/BUILD_PS.GNUARM
        -DPSA_API_TEST_SECURE_STORAGE=1 \
        -DTARGET_PLATFORM=psoc64 \
        -DCOMPILER=ARMCLANG \
        -DCMAKE_BUILD_TYPE=Debug
    popd
    cmake --build <build folder> -- -j VERBOSE=1

**********************
Signing the images
**********************

First, convert tfm_s.axf and tfm_ns.axf images to hex format. This also places
resulting files one folder level up.

GNUARM build:

.. code-block:: bash

    arm-none-eabi-objcopy -O ihex <build folder>/secure_fw/tfm_s.axf <build folder>/tfm_s.hex
    arm-none-eabi-objcopy -O ihex <build folder>/app/tfm_ns.axf <build folder>/tfm_ns.hex

ARMCLANG build:

.. code-block:: bash

    fromelf --i32 --output=<build folder>/tfm_s.hex <build folder>/secure_fw/tfm_s.axf
    fromelf --i32 --output=<build folder>/tfm_ns.hex <build folder>/app/tfm_ns.axf

Copy secure keys used in the board provisioning process to
platform/ext/target/psoc64/security/keys:

MCUBOOT_CM0P_KEY.json - private OEM key for signing CM0P image
USERAPP_CM4_KEY.json  - private OEM key for signing CM4 image

Note: provisioned board in SECURE claimed state is required, otherwise refer to
Cypress documentation for details on the provisioning process.

Sign the images (sign.py overwrites unsigned files with signed ones):

.. code-block:: bash

    ./platform/ext/target/psoc64/security/sign.py \
      -s <build folder>/tfm_s.hex \
      -n <build folder>/tfm_ns.hex \
      -p platform/ext/target/psoc6/security/policy_dual_stage_CM0p_CM4.json

**********************
Programming the Device
**********************

After building and signing, the TFM images must be programmed into flash
memory on the PSoC 6 device.

There are two methods to program psoc6 device.

DAPLink mode
============

Using KitProg3 mode button, switch it to DAPLink mode.
Mode LED should start blinking rapidly and depending on the host computer
settings DAPLINK will be mounted as a media storage device. 
Otherwise, mount it manually.

Copy tfm hex files one by one to the DAPLINK device:

.. code-block:: bash

    cp <build folder>/tfm_ns.hex <mount point>/DAPLINK/; sync
    cp <build folder>/tfm_s.hex <mount point>/DAPLINK/; sync

OpenOCD v.2.2
=============

Using KitProg3 mode button, switch to KitProg3 CMSIS-DAP BULK mode.
Status LED should be ON and not blinking.
To program the signed tfm_s image to the device with openocd (assuming
OPENOCD_PATH is pointing at the openocd installation directory) run the
following commands:

.. code-block:: bash

    ${OPENOCD_PATH}/bin/openocd \
            -s ${OPENOCD_PATH}/scripts \
            -f interface/kitprog3.cfg \
            -c "set ENABLE_ACQUIRE 0" \
            -f target/psoc6_secure.cfg \
            -c "init; reset init; flash write_image erase <build folder>/tfm_s.hex" \
            -c "resume; reset; exit"

    ${OPENOCD_PATH}/bin/openocd \
            -s ${OPENOCD_PATH}/scripts \
            -f interface/kitprog3.cfg \
            -c "set ENABLE_ACQUIRE 0" \
            -f target/psoc6_secure.cfg \
            -c "init; reset init; flash write_image erase <build folder>/tfm_ns.hex" \
            -c "resume; reset; exit"

Optionally, erase SST partition:

.. code-block:: bash

    ${OPENOCD_PATH}/bin/openocd \
            -s ${OPENOCD_PATH}/scripts \
            -f interface/kitprog3.cfg \
            -f target/psoc6_secure.cfg \
            -c "init; reset init" \
            -c "flash erase_address 0x100c0000 0x10000" \
            -c "shutdown"

Note that the ``0x100C0000`` in the command above must match the SST start
address of the secure primary image specified in the file:

    platform/ext/target/psoc64/partition/flash_layout.h

so be sure to change it if you change that file.

*Copyright (c) 2017-2019, Arm Limited. All rights reserved.*

*Copyright (c) 2019, Cypress Semiconductor Corporation. All rights reserved.*
