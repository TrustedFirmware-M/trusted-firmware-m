Nordic nRF5340
==============

The nRF5340 development kit (DK) is a single-board development kit for
the evaluation and development on the Nordic nRF5340 System-on-Chip (SoC).

The nRF5340 is a dual-core SoC based on the Arm® Cortex®-M33 architecture, with:

* a full-featured ARM Cortex-M33F core with DSP instructions, FPU, and
  ARMv8-M Security Extension, running at up to 128 MHz, referred to as
  the **Application MCU**
* a secondary ARM Cortex-M33 core, with a reduced feature set, running at
  a fixed 64 MHz, referred to as the **Network MCU**.

The nRF5340 Application MCU supports the Armv8m Security Extension.

Documentation
-------------

The following links provide useful information about the nRF5340

nRF5340 DK website:
   https://www.nordicsemi.com/Software-and-tools/Development-Kits/nRF5340-DK

Nordic Semiconductor TechDocs: https://docs.nordicsemi.com


Building TF-M on nRF5340 Application MCU
----------------------------------------

To build an S and NS application image for the nRF5340 Application MCU run the
following commands:


.. code-block:: bash

   cmake -S <TF-M base folder> -B build_spe \
           -DTFM_PLATFORM=nordic_nrf/nrf5340dk_nrf5340_cpuapp \
           -DTFM_TOOLCHAIN_FILE=../toolchain_GNUARM.cmake \
   cmake --build build_spe -- install

   cmake -S <Application base folder> -B build_app \
           -DCONFIG_SPE_PATH<Absolute path to TF-M base folder>/build_spe/api_ns
           -DTFM_TOOLCHAIN_FILE=cmake/toolchain_ns_GNUARM.cmake
   cmake --build

.. note::
   Currently, applications can only be built using GCC (GNU ARM Embedded
   toolchain).

.. note::
   BL2 (MCUBoot) logging output to be available, the project needs to be built
   with Debug configuration (CMAKE_BUILD_TYPE=Debug).

Flashing and debugging with Nordic nRF Segger J-Link
-----------------------------------------------------

nRF5340 DK is equipped with a Debug IC (Atmel ATSAM3U2C) which provides the
following functionality:

* Segger J-Link firmware and desktop tools
* SWD debug for the nRF5340 IC
* Mass Storage device for drag-and-drop image flashing
* USB CDC ACM Serial Port bridged to the nRFx UART peripheral
* Segger RTT Console
* Segger Ozone Debugger

To install the J-Link Software and documentation pack, follow the steps below:

#. Download the appropriate package from the `J-Link Software and documentation pack`_ website
#. Depending on your platform, install the package or run the installer
#. When connecting a J-Link-enabled board such as an nRF5340 DK, a drive
   corresponding to a USB Mass Storage device as well as a serial port should come up

nRF Util Installation
*********************

nRF Util allows you to control your nRF5340 device from the command line,
including resetting it, erasing or programming the flash memory and more.

To install nRF Util:

1. Visit `nRF Util product page`_.
2. Download the executable.
3. Follow the `nRF Util installation instructions`_.
4. Install ``nrfutil device`` subcommand for programming, flashing, and erasing devices:

   .. code-block:: console

      nrfutil install device

After installing, make sure that ``nrfutil.exe`` is somewhere in your executable
path to be able to invoke it from anywhere.

BL2, S, and NS application images can be flashed into nRF5340 separately or may be merged
together into a single binary.

Flashing the nRF5340 DK
************************

To program the flash with a compiled TF-M image (i.e. S, NS or both) after having
followed the instructions to install the Segger J-Link Software and the nRF
Command-Line Tools, follow the steps below:

Generate Intel hex files from the output binary (bin) files as follows:

.. code-block:: console

   srec_cat build_app/tfm_s_ns_signed.bin -binary --offset 0x10000 \
         -o build_app/tfm_s_ns_signed.hex -intel

* Connect the micro-USB cable to the nRF5340 DK and to your computer
* Erase the flash memory in the nRF5340 IC:

.. code-block:: console

   nrfutil device erase --all --x-family nrf53

* (Optionally) Erase the flash memory and reset flash protection and disable
   the read back protection mechanism if enabled.

.. code-block:: console

   nrfutil device recover --x-family nrf53

* Flash the BL2 and the TF-M image binaries from the sample folder of your choice:

.. code-block:: console

   nrfutil device program --x-family nrf53 --firmware build_spe/bin/bl2.hex --options chip_erase_mode=ERASE_RANGES_TOUCHED_BY_FIRMWARE
   nrfutil device program --x-family nrf53 --firmware build_app/tfm_s_ns_signed.hex --options chip_erase_mode=ERASE_RANGES_TOUCHED_BY_FIRMWARE

* Reset and start TF-M:

.. code-block:: console

   nrfutil device reset --x-family nrf53


Secure UART Console on nRF5340 DK
**********************************

SECURE_UART1 is enabled by default when building TF-M on nRF5340 DK, so the secure firmware console output
is available via USART1.
When using the nRF5340 network MCU make sure to configure different UART pins or disable SECURE_UART1.

Non-Secure console output is available via USART0.

.. note::
   By default USART0 and USART1 outputs are routed to separate serial ports.

.. _nRF Util product page: https://www.nordicsemi.com/Products/Development-tools/nRF-Util/

.. _nRF Util installation instructions: https://docs.nordicsemi.com/bundle/nrfutil/page/guides/installing.html

.. _J-Link Software and documentation pack: https://www.segger.com/jlink-software.html

--------------

*Copyright (c) 2020, Nordic Semiconductor. All rights reserved.*
