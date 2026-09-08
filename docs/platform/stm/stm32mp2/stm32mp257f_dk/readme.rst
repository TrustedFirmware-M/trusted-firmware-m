##############
stm32mp257f_dk
##############

The STM32MP257F discovery kit constitute a flexible and complete solution for
evaluating the capabilities of the `STM32MP25 microprocessor`_.

* `STM32MP257F-DK website`_
* `STM32MP257F-DK wiki`_

*****
Build
*****

The build generates:

- The SPE elf and binaries in ``<BUILD_DIRECTORY>/build_spe/bin``.
- Artifacts for building application (NSPE) in ``<BUILD_DIRECTORY>/build_spe/api_ns``
- Non secure firmware and TF-M binary concatenated (tfm_s_ns.bin) in ``<BUILD_DIRECTORY>/build_ns/bin``

.. caution::

   By default ``-DTFM_DUMMY_PROVISIONING=ON`` which will use default provisioning and dummy keys.
   This configuration is fine for development purpose but for **production software specific keys must be used**.
   Refer `How to perform Secure Boot from Distribution Package`_ to provision secrets on the SoC.

TF-M secure and non secure with|out regression tests
====================================================

Clone the tf-m-tests repository in ``<TF-M-TESTS_DIRECTORY>``.

.. code:: bash

   $ cmake -S <TF-M-TESTS_DIRECTORY>/tests_reg/spe -B <BUILD_DIRECTORY>/build_spe \
           -DTFM_PLATFORM=stm/stm32mp257f_dk \
           -DCONFIG_TFM_SOURCE_PATH=<TF-M_DIRECTORY> \
           -DTFM_TOOLCHAIN_FILE=<TF-M_DIRECTORY>/toolchain_GNUARM.cmake \
           -DTFM_PROFILE=profile_medium \
           -DTEST_S=ON -DTEST_NS=ON \
           -DCMAKE_BUILD_TYPE=Relwithdebinfo
   $ cmake --build <BUILD_DIRECTORY>/build_spe -- install

   $ cmake -S <TF-M-TESTS_DIRECTORY>/tests_reg -B <BUILD_DIRECTORY>/build_ns \
           -DCONFIG_SPE_PATH=<BUILD_DIRECTORY>/build_spe/api_ns \
   $ cmake --build <BUILD_DIRECTORY>/build_ns

.. Note::

    * To enable or disable S and|or NS regression tests modify ``-DTEST_S=ON|OFF`` ``-DTEST_NS=ON|OFF``.

TF-M secure only
================

Use this build method if you use your own non secure binary.
The secure and non secure binaries must be assembled then signed (see CubeIDE process).

.. code:: bash

   $ cmake -S <TF-M_DIRECTORY> -B <BUILD_DIRECTORY>/build_spe \
           -DTFM_PLATFORM=stm/stm32mp257f_dk \
           -DTFM_TOOLCHAIN_FILE=<TF-M_DIRECTORY>/toolchain_GNUARM.cmake \
           -DTFM_PROFILE=profile_medium \
           -DCMAKE_BUILD_TYPE=Relwithdebinfo
   $ cmake --build <BUILD_DIRECTORY>/build_spe -- install

**********************************
Programming, running and debugging
**********************************

* Programming: `Populate the target and boot the image`_

* To debug, add the flag ``-DDEBUG_AUTHENTICATION=FULL`` at build command line.
  With this flag, BL2 opens the debug port and waits for a debugger connection.

* Secure and Non Secure Cortex-M33 logs are mixed on UART5 of the STM32MP257F-DK board.
  You should setup a terminal with the following options: 115200, 8N1, no HW flow control.

.. code:: console

   [INF] welcome to MCUboot: TF-Mv2.3.0-83-g9f6164109
   [INF] cpu: STM32MP257FAK Rev.Y
   [INF] board: stm32mp257f disco
   [INF] board ID: MB1605 Var1.0 Rev.C-01
   [INF] dts: stm32mp257f-dk-cm33tdcid-sdmmc1-bl2.dts
   [INF] boot device: sdmmc1
   [INF] mcu sysclk: 400000000
   [INF] Boot status: Warm boot detected.
   [INF] Loading gpt header
   [INF] Starting bootloader
   [WRN] This device was provisioned with dummy keys.

   [WRN] This device is NOT SECURE

   [INF] PSA Crypto init done, sig_type: EC-P256
   [INF] Primary   slot: version=1.0.0+0
   [INF] Image 1 secondary slot: image not found
   [INF] Image 1 RAM loading to 0xe060000 is succeeded.
   [INF] Image 1 loaded from the primary slot
   [INF] BL2: image 1, enable DDR-FW
   [INF] Primary   slot: version=2.3.0+0
   [INF] Image 0 secondary slot: image not found
   [INF] Image 0 RAM loading to 0x80000000 is succeeded.
   [INF] Image 0 loaded from the primary slot
   [INF] Bootloader chainload address offset: 0x104400
   [INF] Image version: v2.3.0
   [INF] Jumping to the first image slot
   [INF] init:pmic@33 STPMIC:20 V1.1
   [INF] welcome to TF-M: TF-Mv2.3.0-83-g9f6164109
   [INF] board: stm32mp257f disco
   [INF] dts: stm32mp257f-dk-cm33tdcid-sdmmc1-s.dts
   [NOT] Booting TF-M v2.3.0+g9f6164109
   [NOT] Built Mon 07 Sep 2026 16:33:49 UTC
   [WRN] This device was provisioned with dummy keys.
   [WRN] This device is NOT SECURE
   Creating an empty ITS flash layout.
   Non-Secure system starting...

-------------

*Copyright (c) 2026 STMicroelectronics. All rights reserved.*
*SPDX-License-Identifier: BSD-3-Clause*

.. _STM32MP25 microprocessor: https://wiki.st.com/stm32mpu/wiki/STM32MP25_microprocessor
.. _STM32MP257F-DK website: https://www.st.com/en/evaluation-tools/stm32mp257f-dk.html
.. _STM32MP257F-DK wiki: https://wiki.st.com/stm32mpu/wiki/STM32MP257x-DKx_-_hardware_description
.. _How to perform Secure Boot from Distribution Package: https://wiki.st.com/stm32mpu/wiki/How_to_perform_Secure_Boot_from_Distribution_Package
.. _Populate the target and boot the image: https://wiki.st.com/stm32mpu/wiki/Getting_started/STM32MP2_boards/STM32MP257x-DK/Let%27s_start/Populate_the_target_and_boot_the_image

