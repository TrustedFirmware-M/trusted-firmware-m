########
STM32MP2
########

The `STM32MP2 series`_ embed an Arm Cortex-A35 (single or dual) and Cortex-M33 cores.

Depending on which core owns the Trusted Domain of the platform, the Arm Cortex-M33 can be:

- Owner of Trusted Domain (TDCID) and launched by ROM code: M33-TD flavor (default)
- A simple co-processor launched by the Cortex-A35 (``STM32_M33TDCID=OFF``): A35-TD
  flavor (not yet available on TF-M)

.. note::

   Currently, this platform can only be built using GCC (GNU ARM Embedded toolchain).

   * Profile supported:

     - :doc:`TF-M Profile medium design </configuration/profiles/tfm_profile_medium>`: ``-DTFM_PROFILE=profile_medium``
     - :doc:`TF-M Profile small design </configuration/profiles/tfm_profile_small>`: ``-DTFM_PROFILE=profile_small``

   * Hardware configuration:

     This platform uses the device tree (DT) to describe the hardware available on boards.
     Based on Zephyr :ref:`devicetree` concept

   * The board defines a default device tree (dts), but if needed, an external device tree
     can be used for your components (BL2 | S | NS):

     - ``-DDTS_EXT_DIR=<external_dt_path>``
     - ``-DDTS_BOARD_S=<dts_file_secure>``
     - ``-DDTS_BOARD_NS=<dts_file_non_secure>``
     - ``-DDTS_BOARD_BL2=<dts_file_bl2>``

*****************
Directory content
*****************

- stm/common/stm32mp2xx/bl2:
   Specific code for bl2 platform initialisation.

- stm/common/stm32mp2xx/cmsis_driver:
   CMSIS interface to drivers.

- stm/common/stm32mp2xx/lib
   Specific libraries like qsort...

- stm/common/stm32mp2xx/linker_scripts:
   Specific linker script for bl2, TF-M secure and non secure.

- stm/common/stm32mp2xx/native_driver:
   Framework and drivers for system (with device tree support).

- stm/common/stm32mp2xx/stm32mp[21|23|25]
   Soc variant directory to define specific needs like config, cmakelist, startup...

- stm/common/stm32mp2xx/secure:
   Secure adaptation for STM32MP2 SOC device.

- stm/common/stm32mp2xx/secure_fw
   Secure firmware and the exported interfaces for application.

.. toctree::
    :maxdepth: 1
    :caption: Technical references
    :glob:

    technical/devicetree.rst
    technical/initlevel.rst

.. toctree::
    :maxdepth: 1
    :caption: Available platforms
    :glob:

    stm32mp257f_dk/readme.rst

-------------

*Copyright (c) 2026 STMicroelectronics. All rights reserved.*
*SPDX-License-Identifier: BSD-3-Clause*

.. _STM32MP2 series: https://www.st.com/en/microcontrollers-microprocessors/stm32mp2-series.html
