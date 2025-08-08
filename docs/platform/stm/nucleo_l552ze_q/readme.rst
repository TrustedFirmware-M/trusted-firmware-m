-------
STM32L5
-------

TF-M is supported on STM32L5 family

https://www.st.com/en/microcontrollers-microprocessors/stm32l5-series.html

https://www.st.com/resource/en/user_manual/dm00678763-getting-started-with-stm32cubel5-tfm-application-stmicroelectronics.pdf

Directory content
^^^^^^^^^^^^^^^^^

- stm/common/stm32l5xx/stm32l5xx_hal:
   Content from https://github.com/STMicroelectronics/stm32l5xx_hal_driver.git

- stm/common/stm32l5xx/Device:
   Content from https://github.com/STMicroelectronics/cmsis_device_l5.git

- stm/common/stm32l5xx/bl2:
   stm32l5xx bl2 code specific from https://github.com/STMicroelectronics/STM32CubeL5.git (Projects/STM32L562E-DK/Applications/TFM)

- stm/common/stm32l5xx/secure:
   stm32l5xx Secure porting adaptation from https://github.com/STMicroelectronics/STM32CubeL5.git (Projects/STM32L562E-DK/Applications/TFM)

- stm/common/stm32l5xx/boards:
   Adaptation and tools specific to stm32 board using stm32l5xx soc from https://github.com/STMicroelectronics/STM32CubeL5.git (Projects/STM32L562E-DK/Applications/TFM)

- stm/common/stm32l5xx/CMSIS_Driver:
   Flash and uart driver for stm32l5xx platform

- stm/common/stm32l5xx/Native_Driver:
   Random generator and tickless implementation

Specific Software Requirements
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

STM32_Programmer_CLI is required.(see https://www.st.com/en/development-tools/stm32cubeprog.html)


NUCLEO_L552ZE_Q
^^^^^^^^^^^^^^^

STM32 Nucleo-144 development board with STM32L552ZE MCU, SMPS, supports Arduino, ST Zio and morpho connectivity

Configuration and Build
"""""""""""""""""""""""

GNUARM/ARMCLANG/IARARM compilation is available for this target.
and build the selected configuration as follow.

The build configuration for TF-M is provided to the build system using command
line arguments. Required arguments are noted below.

The following instructions build multi-core TF-M with regression test suites
in Isolation Level 1.

In common STM (``platform\ext\target\stm\common\build_stm``)
There are scripts that help users to build the TF-M project on all STM platforms

.. code-block:: bash


    cd <TF-M base folder>
    cd <trusted-firmware-m folder>

    git clone https://git.trustedfirmware.org/TF-M/tf-m-tests.git
    git checkout <recommended tf-m-tests commit> (..\trusted-firmware-m\lib\ext\tf-m-tests\version.txt)

    mkdir build_s && cd build_s

    cmake -S /../tf-m-tests/tests_reg/spe -B . -GNinja -DTFM_PLATFORM=stm/nucleo_l552ze_q
         -DTFM_TOOLCHAIN_FILE= /../toolchain_ARMCLANG.cmake
         -DCONFIG_TFM_SOURCE_PATH= /../trusted-firmware-m
         -DTFM_PSA_API=ON -DTFM_ISOLATION_LEVEL=1
         -DTEST_S=ON -DTEST_NS=ON

    ninja -C . install -j 8

    cd <trusted-firmware-m folder>
    mkdir build_ns && cd build_ns
    cmake -S /../trusted-firmware-m  /../tf-m-tests/tests_reg -B . -GNinja
         -DCONFIG_SPE_PATH= /../build_s/api_ns -DTFM_TOOLCHAIN_FILE= /../build_s/api_ns/cmake/toolchain_ns_ARMCLANG.cmake

    ninja -C . -j 8

The following instructions build multi-core TF-M with PSA API test suite for
the attestation service in Isolation Level 1 on Linux.

.. code-block:: bash


    cd <TF-M base folder>
    cd <trusted-firmware-m folder>

    git clone https://git.trustedfirmware.org/TF-M/tf-m-tests.git
    git checkout <recommended tf-m-tests commit> (..\trusted-firmware-m\lib\ext\tf-m-tests\version.txt)

    mkdir build_s && cd build_s

    cmake -S /../tf-m-tests/tests_psa_arch/spe -B . -GNinja -DTFM_PLATFORM=stm/nucleo_l552ze_q
         -DTFM_TOOLCHAIN_FILE= /../toolchain_ARMCLANG.cmake
         -DCONFIG_TFM_SOURCE_PATH= /../trusted-firmware-m
         -DTFM_PSA_API=ON -DTFM_ISOLATION_LEVEL=1
         -DTEST_PSA_API=INITIAL_ATTESTATION

    ninja -C . install -j 8

    cd <trusted-firmware-m folder>
    mkdir build_ns && cd build_ns
    cmake -S /../trusted-firmware-m  /../tf-m-tests/tests_psa_arch -B . -GNinja
         -DCONFIG_SPE_PATH= /../build_s/api_ns -DTFM_TOOLCHAIN_FILE= /../build_s/api_ns/cmake/toolchain_ns_ARMCLANG.cmake

    ninja -C . -j 8


Write software on target
^^^^^^^^^^^^^^^^^^^^^^^^
In secure build folder directory api_ns:

  - ``postbuild.sh``: Updates regression.sh and TFM_UPDATE.sh scripts according to flash_layout.h
  - ``regression.sh``: Sets platform option bytes config and erase platform
  - ``TFM_UPDATE.sh``: Writes bl2, secure, and non secure image in target


Connect board to USB and Execute the 3 scripts in following order to update platform:
postbuild.sh, regression.sh, TFM_UPDATE.sh

The virtual com port from STLINK is used for TFM log and serial port configuration should be:

  - Baud rate    = 115200
  - Data         = 8 bits
  - Parity       = none
  - Stop         = 1 bit
  - Flow control = none


.. _NUCLEO_L552ZE_Q: https://www.st.com/en/evaluation-tools/nucleo-l552ze-q.html

-------------

*Copyright (c) 2021-2025, Arm Limited. All rights reserved.*
*Copyright (c) 2019, STMicroelectronics. All rights reserved.*
*SPDX-License-Identifier: BSD-3-Clause*
