###########
FRDM-MCXW70
###########

The NXP FRDM-MCXW70 is a development board for the MCXW70 wireless MCU, which provides an Arm Cortex-M33 TrustZone application core.

MCU device and part on board is shown below:

* Device: MCXW70AC
* Boardname: frdmmcxw70

****************
1. Building TF-M
****************

Prepare the tf-m-tests repository inside the TF-M base folder.

.. code-block:: bash

    cd <TF-M base folder>
    git clone https://git.trustedfirmware.org/TF-M/tf-m-tests.git

This board does not support the secondary bootloader (BL2) yet, so TF-M is built with ``-DBL2=OFF``.

1.1 Building TF-M demo
======================
To build S and NS application image, run the following commands:

.. code:: bash

    cd <TF-M base folder>/tf-m-tests/tests_reg
    cmake -S spe -B build_spe -DTFM_PLATFORM=nxp/frdmmcxw70 \
          -DCONFIG_TFM_SOURCE_PATH=<TF-M base folder>/trusted-firmware-m \
          -G "Unix Makefiles" -DBL2=OFF
    cmake --build build_spe -- install
    cmake -S . -B build_test -G"Unix Makefiles" \
          -DCONFIG_SPE_PATH=<TF-M base folder>/tf-m-tests/tests_reg/build_spe/api_ns
    cmake --build build_test

1.2 Building TF-M regression tests
==================================

To build the S and NS regression tests, run the following commands:

* Profile Medium:

.. code:: bash

    cd <TF-M base folder>/tf-m-tests/tests_reg
    cmake -S spe -B build_spe -DTFM_PLATFORM=nxp/frdmmcxw70 \
          -DCONFIG_TFM_SOURCE_PATH=<TF-M base folder>/trusted-firmware-m \
          -G "Unix Makefiles" -DTFM_PROFILE=profile_medium \
          -DTEST_S=ON -DTEST_NS=ON -DBL2=OFF
    cmake --build build_spe -- install
    cmake -S . -B build_test -G"Unix Makefiles" \
          -DCONFIG_SPE_PATH=<TF-M base folder>/tf-m-tests/tests_reg/build_spe/api_ns
    cmake --build build_test

.. note::

    Secure Storage uses RAM (``PLATFORM_RAM_FS=ON``) on this board, so stored
    keys and data do not survive a reset. The Protected Storage and Initial
    Attestation partitions are disabled in ``config.cmake``.

***********************************
2. Flashing TF-M with Segger J-Link
***********************************

.. note::

    Precondition: the NBU (wireless core) firmware must already be programmed
    on the board. The steps below do not load it.

Prerequisites:

#. Install the `J-Link Software and documentation pack`_. These steps were verified with
   JLink V9.24a; newer versions should work too.
#. Enter the board in the mode described in the board bring-up documentation.
#. Have the TF-M images available: ``tfm_s.bin`` from ``build_spe/bin/`` and
   ``tfm_ns.bin`` from ``build_test/bin/``.

Load addresses on this board:

.. list-table::
    :header-rows: 1

    * - Image
      - Address
    * - Secure image (``tfm_s.bin``)
      - ``0x48000``
    * - Non-secure image (``tfm_ns.bin``)
      - ``0x70000``

Flash Erase
===========

.. warning::

    Erase only the application area. Do not erase from ``0x0``, because that
    removes the NBU firmware. Run the erase step only when a full reflash is
    needed.

.. code-block:: console

    JLinkExe -device MCXW70AC -if SWD -jtagconf -1,-1 -speed 4000 -autoconnect 1
    J-Link>r
    J-Link>h
    J-Link>exec EnableEraseAllFlashBanks
    J-Link>erase 0x0048000 0x160000
    J-Link>r
    J-Link>h

Flash Write
===========

Flash the secure and non-secure TF-M images:

.. code-block:: console

    JLinkExe -device MCXW70AC -if SWD -jtagconf -1,-1 -speed 4000 -autoconnect 1
    J-Link>r
    J-Link>h
    J-Link>loadbin <TF-M base folder>/tf-m-tests/tests_reg/build_spe/bin/tfm_s.bin,0x48000
    J-Link>h
    J-Link>loadbin <TF-M base folder>/tf-m-tests/tests_reg/build_test/bin/tfm_ns.bin,0x70000
    J-Link>r

After the J-Link script completes, set the board DIP switches back to normal
boot configuration as described in the board bring-up documentation.

.. note::

    The NS offset ``0x70000`` assumes the default 160 KB secure partition. A
    build with ``-DMCU_SDK_REGRESSION=ON`` uses a 192 KB secure partition, so
    the NS image moves to ``0x78000``. Check this against the built layout
    before flashing.

.. _J-Link Software and documentation pack: https://www.segger.com/jlink-software.html

--------------

*Copyright 2026 NXP*
*SPDX-License-Identifier: BSD-3-Clause*
