LP_MSPM33C321A
==============

Introduction
------------

The LP_MSPM33C321A LaunchPad is a development board based on the Texas Instruments
MSPM33C321A microcontroller. The device features an Arm Cortex-M33 core with
TrustZone-M support, 1 MB main flash, 32 KB data flash, and 256 KB SRAM, making
it suitable for PSA Certified implementations.

This platform port supports TF-M regression tests (Secure and Non-Secure) and
PSA Arch tests with Isolation Level 1.

.. note::

   Only the GNU Arm Embedded toolchain (12.3 or later) is supported.

.. note::

   BL2 (MCUboot) is not supported. The secure image executes directly from
   flash at ``0x10000000`` with no bootloader.

Directory Content
-----------------

- ``platform/ext/target/ti/LP_MSPM33C321A/Native_Driver/``:
   Bundled TI driverlib sources required by the platform (flash controller,
   UART, GPIO, GSC, sysctl). Taken from the
   `MSP SDK <https://www.ti.com/tool/MSPM0-SDK>`__ (BSD-3-Clause).
   No external SDK installation is required to build.

   To use driverlib sources from an existing SDK installation instead, pass
   ``-DTFM_PLATFORM_TI_HAL_FILE_PATH=/path/to/mspm33_sdk`` to CMake.

- ``platform/ext/target/ti/LP_MSPM33C321A/cmsis_drivers/``:
   CMSIS-compliant Flash and USART driver wrappers.

Building TF-M
-------------

Follow the :doc:`generic build instructions </building/tfm_build_instruction>`
and set ``-DTFM_PLATFORM=ti/LP_MSPM33C321A``.

First, clone tf-m-tests at the version pinned by this TF-M release:

.. code-block:: bash

   git clone https://git.trustedfirmware.org/TF-M/tf-m-tests.git
   # Check the pinned version:
   cat <TF-M source dir>/lib/ext/tf-m-tests/version.txt

Example: regression tests (Secure and Non-Secure), Isolation Level 1
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Building the Secure side:

.. code-block:: bash

    cmake -S <tf-m-tests>/tests_reg/spe \
          -B <build_dir>/spe \
          -DTFM_PLATFORM=ti/LP_MSPM33C321A \
          -DTFM_TOOLCHAIN_FILE=<TF-M source dir>/toolchain_GNUARM.cmake \
          -DCONFIG_TFM_SOURCE_PATH=<TF-M source dir> \
          -DCROSS_COMPILE=<toolchain_path>/arm-none-eabi \
          -DCMAKE_BUILD_TYPE=Release \
          -DTEST_S=ON \
          -DTEST_NS=ON

    cmake --build <build_dir>/spe --target install -- -j8

Building the Non-Secure side:

.. code-block:: bash

    cmake -S <tf-m-tests>/tests_reg \
          -B <build_dir>/ns \
          -DCONFIG_SPE_PATH=<build_dir>/spe/api_ns \
          -DTFM_TOOLCHAIN_FILE=<build_dir>/spe/api_ns/cmake/toolchain_ns_GNUARM.cmake \
          -DCROSS_COMPILE=<toolchain_path>/arm-none-eabi \
          -DCMAKE_BUILD_TYPE=Release

    cmake --build <build_dir>/ns -- -j8

Flashing
--------

Use `Code Composer Studio (CCS) <https://www.ti.com/tool/CCSTUDIO>`__ to program
the device via a project-less debug session (Target Configuration for
``MSPM33C321A``, then ``Debug Without Program``/connect to the target).

Erasing
^^^^^^^

With the target connected, erase the device using the Scripting Console:

- ``Scripts > MSPM33C321A_Commands > MSPM33_Mailbox_MassErase_Auto`` erases
  the main flash bank.
- ``Scripts > MSPM33C321A_Commands > MSPM33_Mailbox_FactoryReset_Auto`` also
  erases the data flash bank. Use this if PS/ITS/NV counters (stored in the
  data bank) need to be reset as well.

Programming
^^^^^^^^^^^

Load the Non-Secure image first, then the Secure image, at their respective
addresses:

- Non-Secure image (``tfm_ns.bin``): ``0x00080000``
- Secure image (``tfm_s.bin``): ``0x10000000``

.. important::

   Before loading either image, set the flash programmer option to
   **Do not erase Flash memory**. If flash-erase-on-load is left enabled,
   loading the Secure image second will erase the previously loaded
   Non-Secure image.

UART Output
-----------

TF-M log output is available on the LaunchPad's back-channel UART (XDS110).
Serial port settings:

- Baud rate: 115200
- Data: 8 bits
- Parity: none
- Stop: 1 bit
- Flow control: none

--------------

*SPDX-License-Identifier: BSD-3-Clause*

*SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors*

*Copyright (c) 2026 Texas Instruments Incorporated*
