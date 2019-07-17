########################
Cypress PSoC 6 Specifics
########################

******************************************
Building Multi-Core TF-M on Cypress PSoC 6
******************************************

Please make sure you have all required software installed as explained in the
:doc:`software requirements </docs/user_guides/tfm_sw_requirement>`.

Please also download and install ModusToolbox from `Cypress
<https://www.cypress.com/products/modustoolbox-software-environment>`_
and ensure that it is able to communicate with the PSoC 6 board.

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

           - IPC model without regression test suites
             ``ConfigCoreIPC.cmake``
           - IPC model with regression test suites
             ``ConfigRegressionIPC.cmake``

   * - -DTARGET_PLATFORM=<target platform name>
     - Specifies target names of builds on secure and non-secure cores

         - ``psoc6_sc``
           target name of build on secure core
         - ``psoc6_host``
           target name of build on non-secure core

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
on Linux.
Both the compiler and the debugging type can be changed to other configurations
listed above.

.. code-block:: bash

    cd <TF-M base folder>
    cd <trusted-firmware-m folder>

    mkdir cmake_psoc_cm0p
    pushd cmake_psoc_cm0p
    cmake -G"Unix Makefiles" -DPROJ_CONFIG=`readlink -f ../configs/ConfigCoreIPC.cmake` -DTARGET_PLATFORM=psoc6_sc -DCOMPILER=ARMCLANG -DCMAKE_BUILD_TYPE=Debug ../
    popd
    cmake --build cmake_psoc_cm0p -- -j VERBOSE=1

    mkdir cmake_psoc_cm4
    pushd cmake_psoc_cm4
    cmake -G"Unix Makefiles" -DPROJ_CONFIG=`readlink -f ../configs/ConfigCoreIPC.cmake` -DTARGET_PLATFORM=psoc6_host -DCOMPILER=ARMCLANG -DCMAKE_BUILD_TYPE=Debug ../
    popd
    cmake --build cmake_psoc_cm4 -- -j VERBOSE=1

The following instructions build multi-core TF-M with regression test suites
enabled on Linux.
Both the compiler and the debugging type can be changed to other configurations
listed above.

.. code-block:: bash

    cd <TF-M base folder>
    cd <trusted-firmware-m folder>

    mkdir cmake_psoc_cm0p
    pushd cmake_psoc_cm0p
    cmake -G"Unix Makefiles" -DPROJ_CONFIG=`readlink -f ../configs/ConfigRegressionIPC.cmake` -DTARGET_PLATFORM=psoc6_sc -DCOMPILER=ARMCLANG -DCMAKE_BUILD_TYPE=Debug ../
    popd
    cmake --build cmake_psoc_cm0p -- -j VERBOSE=1

    mkdir cmake_psoc_cm4
    pushd cmake_psoc_cm4
    cmake -G"Unix Makefiles" -DPROJ_CONFIG=`readlink -f ../configs/ConfigRegressionIPC.cmake` -DTARGET_PLATFORM=psoc6_host -DCOMPILER=ARMCLANG -DCMAKE_BUILD_TYPE=Debug ../
    popd
    cmake --build cmake_psoc_cm4 -- -j VERBOSE=1


**********************
Programming the Device
**********************

After building, the mcuboot image must be signed using the ModusToolbox tools
and the signed mcuboot image and the TFM image must be programmed into flash
memory on the PSoC 6 device.

The instructions below assume that you have set up an environment variable
``CYSDK`` that points to your ModusToolbox installation, for example like this:

.. code-block:: bash

    export CYSDK=~/ModusToolbox_1.1

To program the primary image to the device:

.. code-block:: bash

    ${CYSDK}/tools/openocd-2.1/bin/openocd -s "${CYSDK}/tools/openocd-2.1/scripts" -c "source [find interface/kitprog3.cfg]" -c "source [find target/psoc6.cfg]" -c "program ./cmake_psoc_cm4/tfm_sign.bin offset 0x10020000 verify" -c "reset_config srst_only;psoc6.dap dpreg 0x04 0x00;shutdown"

Note that the ``0x10020000`` in the command above must match the start address
of the secure primary image specified in the file::

    platform/ext/target/psoc6/partition/flash_layout.h

so be sure to change it if you change that file.

To sign the mcuboot image:

.. code-block:: bash

    ${CYSDK}/tools/cymcuelftool-1.0/bin/cymcuelftool --sign ./cmake_psoc_cm0p/bl2/ext/mcuboot/mcuboot.axf --output ./cmake_psoc_cm0p/mcuboot_signed.elf

To program the signed mcuboot image to the device:

.. code-block:: bash

    ${CYSDK}/tools/openocd-2.1/bin/openocd -s "${CYSDK}/tools/openocd-2.1/scripts" -c "source [find interface/kitprog3.cfg]" -c "source [find target/psoc6.cfg]" -c "program ./cmake_psoc_cm0p/mcuboot_signed.elf verify" -c "reset_config srst_only;reset run;psoc6.dap dpreg 0x04 0x00;shutdown"

Alternatively, it is possible to program the device using ModusToolbox. For
details, please refer to the ModusToolbox documentation.

*Copyright (c) 2017-2019, Arm Limited. All rights reserved.*

*Copyright (c) 2019, Cypress Semiconductor Corporation. All rights reserved.*
