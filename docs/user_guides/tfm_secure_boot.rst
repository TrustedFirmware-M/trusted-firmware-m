##############################
Trusted Firmware M secure boot
##############################
For secure devices it is security critical to enforce firmware authenticity to
protect against execution of malicious software. This is implemented by building
a trust chain where each step in the execution chain authenticates the next
step before execution. The chain of trust in based on a "Root of Trust" which
is implemented using asymmetric cryptography. The Root of Trust is a combination
of an immutable bootloader and a public key (ROTPK).

*******************************
Second stage bootloader in TF-M
*******************************
To implement secure boot functionality an external project MCUBoot has been
integrated to TF-M. For further information please refer to the
`MCUBoot homepage <https://www.mcuboot.com/>`__. Original source-code is
available at `GitHub <https://github.com/JuulLabs-OSS/mcuboot>`__. This document
contains information about MCUBoot modifications and how MCUBoot has been
integrated to TF-M.

Bootloader is started when CPU is released from reset. It runs in secure mode.
It authenticates the firmware image by hash (SHA-256) and digital signature
(RSA-3072) validation. Public key, that the checks happens against, is built
into the bootloader image. Metadata of the image is delivered together with the
image itself in a header and trailer section. In case of successful
authentication, bootloader passes execution to the secure image. Execution never
returns to bootloader until next reset.

A default RSA key pair is stored in the repository, public key is in ``keys.c``
and private key is in ``root-rsa-3072.pem``.

.. Warning::
    DO NOT use them in production code, they are exclusively for testing!

Private key must be stored in a safe place outside of the repository.
``Imgtool.py`` can be used to generate new key pairs.

The bootloader handles the secure and non-secure images as a single blob which
is contiguous in the device memory. At compile time these images are
concatenated and signed with RSA-3072 digital signature. Preparation of payload
is done by Python scripts: ``bl2/ext/mcuboot/scripts/``. At the end of a
successful build signed TF-M payload can be found in:
``<build_dir>/install/outputs/fvp/tfm_sign.bin``

*********************
Integration with TF-M
*********************
MCUBoot assumes a predefined memory layout which is described below (applicable
for AN521). It is mandatory to define slot 0 and slot 1 partitions, but their
size can be changed::

    - 0x0000_0000 - 0x0007_FFFF:    BL2 bootloader - MCUBoot
    - 0x0008_0000 - 0x000F_FFFF:    Slot 0 : Single binary blob: Secure + Non-Secure
                                    image; Primary memory partition
      - 0x0008_0000 - 0x0008_03FF:  Common image header
      - 0x0008_0400 - 0x0008_xxxx:  Secure image
      - 0x0008_xxxx - 0x0010_03FF:  Padding (with 0xFF)
      - 0x0010_0400 - 0x0010_xxxx:  Non-secure image
      - 0x0010_xxxx - 0x0010_xxxx:  Hash value(SHA256) and RSA signature
                                    of combined image

    - 0x0018_0000 - 0x0027_FFFF:    Slot 1 : Secure + Non-Secure image; Secondary
                                    memory partition, structured identically to slot
                                    0
    - 0x0028_0000 - 0x0037_FFFF:    Scratch area, only used during image swapping

**************************
Firmware upgrade operation
**************************
MCUBoot handles only the firmware authenticity check after start-up and the
firmware switch part of the firmware update process. Downloading the new version
of the firmware is out-of-scope for MCUBoot. MCUBoot supports three different
ways to switch to the new firmware and it is assumed that firmware images are
executed-in-place (XIP). The default behaviour is the overwrite-based image
upgrade. In this case the active firmware is always executed from slot 0 and
slot 1 is a staging area for new images. Before executing the new firmware
image, the content of slot 0 must be overwritten with the content of slot 1
(the new firmware image). The second option is the image swapping strategy when
the content of the two memory slots must be physically swapped. This needs the
scratch area to be defined in the memory layout. The third option is the
non-swapping version, which eliminates the complexity of image swapping and its
administration. Active image can be executed from either memory slot, but new
firmware must be linked to the address space of the proper (currently inactive)
memory slot.

Overwrite operation
===================
Active image is stored in slot 0, and this image is started always by the
bootloader. Therefore images must be linked to slot 0. If the bootloader finds
a valid image in slot 1, which is marked for upgrade, then the content of slot 0
will be simply overwritten with the content of slot 1, before starting the new
image from slot 0. After the content of slot 0 has been successfully
overwritten, the header and trailer of the new image in slot 1 is erased to
prevent the triggering of another unncessary image uprade after a restart. The
overwrite operation is fail-safe and resistant to power-cut failures. For more
details please refer to the MCUBoot
`documentation <https://www.mcuboot.com/mcuboot/design.html>`__.

Swapping operation
==================
This operation can be set with the ``MCUBOOT_UPGRADE_STRATEGY`` compile time
switch (see `Build time configuration`_). With swapping image upgrade strategy
the active image is also stored in slot 0 and it will always be started by the
bootloader. If the bootloader finds a valid image in slot 1, which is marked for
upgrade, then contents of slot 0 and slot 1 will be swapped, before starting the
new image from slot 0. Scratch area is used as a temporary storage place during
image swapping. Update mark from slot 1 is removed when the swapping is
successful. The boot loader can revert the swapping as a fall-back mechanism to
recover the previous working firmware version after a faulty update. The swap
operation is fail-safe and resistant to power-cut failures. For more details
please refer to the MCUBoot
`documentation <https://www.mcuboot.com/mcuboot/design.html>`__.

.. Note::

    After a successful image upgrade the firmware can mark itself as "OK" at
    runtime by setting the image_ok flag in the flash. When this happens, the
    swap is made "permanent" and MCUBoot will then still choose to run it
    during the next boot. Currently TF-M does not set the image_ok flag,
    therefore the bootloader will always perform a "revert" (swap the images
    back) during the next boot.

Non-swapping operation
======================
This operation can be set with the ``MCUBOOT_UPGRADE_STRATEGY`` compile time
switch (see `Build time configuration`_). When enabling non-swapping operation
then the active image flag is moved between slots during firmware upgrade. If
firmware is executed-in-place (XIP), then two firmware images must be generated.
One of them is linked to be executed from slot 0 memory region and the other
from slot 1. The firmware upgrade client, which downloads the new image, must be
aware, which slot hosts the active firmware and which acts as a staging area and
it is responsible for downloading the proper firmware image. At boot time
MCUBoot inspects the version number in the image header and passes execution to
the newer firmware version. New image must be marked for upgrade which is
automatically done by Python scripts at compile time. Image verification is done
the same way in all operational modes. If new image fails during authentication
then MCUBoot erases the memory slot and starts the other image, after successful
authentication.

At build time automatically two binaries are generated::

    <build_dir>/install/outputs/fvp/tfm_s_ns_signed.bin : Image linked for slot 0 memory partition

    <build_dir>/install/outputs/fvp/tfm_s_ns_signed_1.bin : Image linked for slot 1 memory partition

RAM Loading firmware upgrade
============================
Musca-A supports an image upgrade mode that is separate to the other (overwrite,
swapping and non-swapping) modes. This is the ``RAM loading`` mode (please refer
to the table below). Like the non-swapping mode, this selects the newest image
by reading the image version numbers in the image headers, but instead of
executing it in place, the newest image is copied to RAM for execution. The load
address, the location in RAM where the image is copied to, is stored in the
image header.

Summary of different modes for image upgrade
============================================
Different implementations of the image upgrade operation (whether through
overwriting, swapping, non-swapping or loading into RAM and executing from
there) are supported by the platforms. The table below shows which of these
modes are supported by which platforms:

+----------+-----------------+----------------------------------------------------------+
|          | Without BL2 [1]_| With BL2 [2]_                                            |
+==========+=================+===============+==========+=============+=================+
|          | XIP             | XIP           | XIP      | XIP         | Not XIP         |
+----------+-----------------+---------------+----------+-------------+-----------------+
|          |                 | Overwrite [3]_| Swap [4]_| No-swap [5]_| RAM loading [6]_|
+----------+-----------------+---------------+----------+-------------+-----------------+
| AN521    | Yes             | Yes           | Yes      | Yes         | No              |
+----------+-----------------+---------------+----------+-------------+-----------------+
| AN519    | Yes             | Yes           | Yes      | Yes         | No              |
+----------+-----------------+---------------+----------+-------------+-----------------+
| Musca-A  | No              | No            | No       | No          | Yes             |
+----------+-----------------+---------------+----------+-------------+-----------------+
| Musca-B1 | Yes             | No            | No       | Yes         | No              |
+----------+-----------------+---------------+----------+-------------+-----------------+
| AN524    | Yes             | No            | No       | Yes         | No              |
+----------+-----------------+---------------+----------+-------------+-----------------+

.. [1] To disable BL2, please turn off the ``BL2`` compiler switch in the
    top-level configuration file or in the command line

.. [2] BL2 is enabled by default

.. [3] The image executes in-place (XIP) and is in Overwrite mode for image
    update by default

.. [4] To enable XIP Swap mode, assign the "SWAP" string to the
    ``MCUBOOT_UPGRADE_STRATEGY`` configuration variable in the top-level
    configuration file, or include this macro definition in the command line

.. [5] To enable XIP No-swap, assign the "NO_SWAP" string to the
    ``MCUBOOT_UPGRADE_STRATEGY`` configuration variable in the top-level
    configuration file, or include this macro definition in the command line

.. [6] To enable RAM loading, assign the "RAM_LOADING" string to the
    ``MCUBOOT_UPGRADE_STRATEGY`` configuration variable in the top-level
    configuration file, or include this macro definition in the command line

********************
Signature algorithms
********************
MbedTLS library is used to sign the images. The list of supported signing
algorithms:

  - `RSA-2048`
  - `RSA-3072`: default

Example keys stored in ``root-rsa-2048.pem`` and ``root-rsa-3072.pem``.

************************
Build time configuration
************************
MCUBoot related compile time switches can be set in the high level build
configuration file::

    CommonConfig.cmake

Compile time switches:

- BL2 (default: True):
    - **True:** TF-M built together with bootloader. MCUBoot is executed after
      reset and it authenticates TF-M and starts secure code.
    - **False:** TF-M built without bootloader. Secure image linked to the
      beginning of the device memory and executed after reset. If it is false
      then using any of the further compile time switches are invalid.
- MCUBOOT_UPGRADE_STRATEGY (default: "OVERWRITE_ONLY"):
    - **"OVERWRITE_ONLY":** Default firmware upgrade operation with overwrite.
    - **"SWAP":** Activate swapping firmware upgrade operation.
    - **"NO_SWAP":** Activate non-swapping firmware upgrade operation.
    - **"RAM_LOADING":** Activate RAM loading firmware upgrade operation, where
      latest image is copied to RAM and runs from there instead of being
      executed in-place.
- MCUBOOT_SIGNATURE_TYPE (default: RSA-3072):
    - **RSA-3072** Image is signed with RSA-3072 algorithm
    - **RSA-2048** Image is signed with RSA-2048 algorithm

Image versioning
================
An image version number is written to its header by one of the python scripts,
and this number is used by the bootloader when the non-swapping or RAM loading
mode is enabled.

The version number of the image can manually be passed in through the command
line in the cmake configuration step::

    cmake -G"Unix Makefiles" -DTARGET_PLATFORM=AN521 -DCOMPILER=ARMCLANG -DIMAGE_VERSION=1.2.3+4 ../

Alternatively, the version number can be less specific (e.g 1, 1.2, or 1.2.3),
where the missing numbers are automatically set to zero. The image version
number argument is optional, and if it is left out, then the version numbers of
the image(s) being built in the same directory will automatically change. In
this case, the last component (the build number) automatically increments from
the previous one: 0.0.0+1 -> 0.0.0+2, for as many times as the build is re-ran,
**until a number is explicitly provided**. If automatic versioning is in place
and then an image version number is provided for the first time, the new number
will take precedence and be used instead. All subsequent image versions are
then set to the last number that has been specified, and the build number would
stop incrementing. Any new version numbers that are provided will overwrite
the previous one: 0.0.0+1 -> 0.0.0+2. Note: To re-apply automatic image
versioning, please start a clean build without specifying the image version
number at all.

Security counter
================
Each signed image contains a security counter in its manifest. It is used by the
bootloader and its aim is to have an independent (from the image version)
counter to ensure rollback protection by comparing the new image's security
counter against the original (currently active) image's security counter during
the image upgrade process. It is added to the manifest (to the TLV area that is
appended to the end of the image) by one of the python scripts when signing the
image. The value of the security counter is security critical data and it is in
the integrity protected part of the image. The last valid security counter is
always stored in a non-volatile and trusted component of the device and its
value should always be increased if a security flaw was fixed in the current
image version. The value of the security counter can be specified at build time
in the cmake configuration step::

    cmake -G"Unix Makefiles" -DTARGET_PLATFORM=AN521 -DCOMPILER=ARMCLANG -DSECURITY_COUNTER=42 ../

The security counter can be independent from the image version, but not
necessarily. Alternatively, if it is not specified at build time with the
``SECURITY_COUNTER`` option the python script will automatically generate it
from the image version number (not including the build number) and this value
will be added to the signed image.

************************
Testing firmware upgrade
************************
As downloading the new firmware image is out of scope for MCUBoot, the update
process is started from a state where the original and the new image are already
programmed to the appropriate memory slots. To generate the original and a new
firmware package, TF-M is built twice with different build configurations.

Overwriting firmware upgrade
============================
Run TF-M build twice with two different build configuration: default and
regression. Save the artifacts between builds, because second run can overwrite
original binaries. Download default build to slot 0 and regression build to
slot 1.

Executing firmware upgrade on FVP_MPS2_AEMv8M
---------------------------------------------
.. code-block:: bash

    <DS5_PATH>/sw/models/bin/FVP_MPS2_AEMv8M  \
    --parameter fvp_mps2.platform_type=2 \
    --parameter cpu0.baseline=0 \
    --parameter cpu0.INITVTOR_S=0x10000000 \
    --parameter cpu0.semihosting-enable=0 \
    --parameter fvp_mps2.DISABLE_GATING=0 \
    --parameter fvp_mps2.telnetterminal0.start_telnet=1 \
    --parameter fvp_mps2.telnetterminal1.start_telnet=0 \
    --parameter fvp_mps2.telnetterminal2.start_telnet=0 \
    --parameter fvp_mps2.telnetterminal0.quiet=0 \
    --parameter fvp_mps2.telnetterminal1.quiet=1 \
    --parameter fvp_mps2.telnetterminal2.quiet=1 \
    --application cpu0=<build_dir>/bl2/ext/mcuboot/mcuboot.axf \
    --data cpu0=<default_build_dir>/install/outputs/fvp/tfm_s_ns_signed.bin@0x10080000 \
    --data cpu0=<regresssion_build_dir>/install/outputs/fvp/tfm_s_ns_signed.bin@0x10180000

Executing firmware upgrade on SSE 200 FPGA on MPS2 board
--------------------------------------------------------

::

    TITLE: Versatile Express Images Configuration File
    [IMAGES]
    TOTALIMAGES: 3                     ;Number of Images (Max: 32)
    IMAGE0ADDRESS: 0x00000000
    IMAGE0FILE: \Software\mcuboot.axf  ; BL2 bootloader
    IMAGE1ADDRESS: 0x10080000
    IMAGE1FILE: \Software\tfm_sig1.bin ; TF-M default test binary blob
    IMAGE2ADDRESS: 0x10180000
    IMAGE2FILE: \Software\tfm_sig2.bin ; TF-M regression test binary blob

The following message will be shown in case of successful firmware upgrade:

::

    [INF] Starting bootloader
    [INF] Swap type: test
    [INF] Image upgrade slot1 -> slot0
    [INF] Erasing slot0
    [INF] Copying slot 1 to slot 0: 0x100000 bytes
    [INF] Bootloader chainload address offset: 0x80000
    [INF] Jumping to the first image slot
    [Sec Thread] Secure image initializing!

    #### Execute test suites for the Secure area ####
    Running Test Suite PSA protected storage S interface tests (TFM_SST_TEST_2XXX)...
    ...

Swapping firmware upgrade
=============================
Follow the same instructions and platform related configurations as in case of
overwriting build including these changes:

- Set MCUBOOT\_SWAP compile time switch to true before build.

The following message will be shown in case of successful firmware upgrade,
``Swap type: test`` indicates that images were swapped:

::

    [INF] Starting bootloader
    [INF] Image 0: magic= good, copy_done=0x3, image_ok=0x3
    [INF] Scratch: magic=  bad, copy_done=0x0, image_ok=0x2
    [INF] Boot source: slot 0
    [INF] Swap type: test
    [INF] Bootloader chainload address offset: 0x80000
    [INF] Jumping to the first image slot
    [Sec Thread] Secure image initializing!

    #### Execute test suites for the Secure area ####
    Running Test Suite PSA protected storage S interface tests (TFM_SST_TEST_2XXX)...
    ...

Non-swapping firmware upgrade
=============================
Follow the same instructions as in case of overwriting build including these
changes:

- Set the ``MCUBOOT_UPGRADE_STRATEGY`` compile time switch to "NO_SWAP"
  before build.
- Increase the image version number between the two build run.

Executing firmware upgrade on FVP_MPS2_AEMv8M
---------------------------------------------

.. code-block:: bash

    <DS5_PATH>/sw/models/bin/FVP_MPS2_AEMv8M  \
    --parameter fvp_mps2.platform_type=2 \
    --parameter cpu0.baseline=0 \
    --parameter cpu0.INITVTOR_S=0x10000000 \
    --parameter cpu0.semihosting-enable=0 \
    --parameter fvp_mps2.DISABLE_GATING=0 \
    --parameter fvp_mps2.telnetterminal0.start_telnet=1 \
    --parameter fvp_mps2.telnetterminal1.start_telnet=0 \
    --parameter fvp_mps2.telnetterminal2.start_telnet=0 \
    --parameter fvp_mps2.telnetterminal0.quiet=0 \
    --parameter fvp_mps2.telnetterminal1.quiet=1 \
    --parameter fvp_mps2.telnetterminal2.quiet=1 \
    --application cpu0=<build_dir>/bl2/ext/mcuboot/mcuboot.axf \
    --data cpu0=<default_build_dir>/install/outputs/fvp/tfm_s_ns_signed.bin@0x10080000 \
    --data cpu0=<regresssion_build_dir>/install/outputs/fvp/tfm_s_ns_signed_1.bin@0x10180000

Executing firmware upgrade on SSE 200 FPGA on MPS2 board
--------------------------------------------------------

::

    TITLE: Versatile Express Images Configuration File
    [IMAGES]
    TOTALIMAGES: 3                     ;Number of Images (Max: 32)
    IMAGE0ADDRESS: 0x00000000
    IMAGE0FILE: \Software\mcuboot.axf  ; BL2 bootloader
    IMAGE1ADDRESS: 0x10080000
    IMAGE1FILE: \Software\tfm_sign.bin ; TF-M default test binary blob
    IMAGE2ADDRESS: 0x10180000
    IMAGE2FILE: \Software\tfm_sig1.bin ; TF-M regression test binary blob

Executing firmware upgrade on Musca-B1 board
--------------------------------------------
After two images have been built, they can be concatenated to create the
combined image using ``srec_cat``:

- Linux::

    srec_cat bl2/ext/mcuboot/mcuboot.bin -Binary -offset 0xA000000 tfm_sign.bin -Binary -offset 0xA020000 tfm_sign_1.bin -Binary -offset 0xA0E0000 -o tfm.hex -Intel

- Windows::

    srec_cat.exe bl2\ext\mcuboot\mcuboot.bin -Binary -offset 0xA000000 tfm_sign.bin -Binary -offset 0xA020000 tfm_sign_1.bin -Binary -offset 0xA0E0000 -o tfm.hex -Intel

The following message will be shown in case of successful firmware upgrade,
notice that image with higher version number (``version=1.2.3.5``) is executed:

::

    [INF] Starting bootloader
    [INF] Image 0: version=1.2.3.4, magic= good, image_ok=0x3
    [INF] Image 1: version=1.2.3.5, magic= good, image_ok=0x3
    [INF] Booting image from slot 1
    [INF] Bootloader chainload address offset: 0xa0000
    [INF] Jumping to the first image slot
    [Sec Thread] Secure image initializing!

    #### Execute test suites for the Secure area ####
    Running Test Suite PSA protected storage S interface tests (TFM_SST_TEST_2XXX)...
    ...

Executing firmware upgrade on CoreLink SSE-200 Subsystem for MPS3 (AN524)
-------------------------------------------------------------------------

::

    TITLE: Arm MPS3 FPGA prototyping board Images Configuration File

    [IMAGES]
    TOTALIMAGES: 3                     ;Number of Images (Max: 32)

    IMAGE0UPDATE: AUTO                 ;Image Update:NONE/AUTO/FORCE
    IMAGE0ADDRESS: 0x00000000
    IMAGE0FILE: \SOFTWARE\mcuboot.bin  ;BL2 bootloader
    IMAGE1UPDATE: AUTO
    IMAGE1ADDRESS: 0x00040000
    IMAGE1FILE: \SOFTWARE\tfm_sig0.bin ;TF-M example application binary blob
    IMAGE2UPDATE: AUTO
    IMAGE2ADDRESS: 0x000C0000
    IMAGE2FILE: \SOFTWARE\tfm_sig1.bin ;TF-M regression test binary blob

RAM loading firmware upgrade
============================
To enable RAM loading, please set ``MCUBOOT_UPGRADE_STRATEGY`` to "RAM_LOADING"
(either in the configuration file or through the command line), and then specify
a destination load address in RAM where the image can be copied to and executed
from. The ``IMAGE_LOAD_ADDRESS`` macro must be specified in the target dependent
files, for example with Musca-A, its ``flash_layout.h`` file in the ``platform``
folder should include ``#define IMAGE_LOAD_ADDRESS #0x10020000``

Executing firmware upgrade on Musca-A board
--------------------------------------------
After two images have been built, they can be concatenated to create the
combined image using ``srec_cat``:

- Linux::

    srec_cat bl2/ext/mcuboot/mcuboot.bin -Binary -offset 0x200000 tfm_sign_old.bin -Binary -offset 0x220000 tfm_sign_new.bin -Binary -offset 0x320000 -o tfm.hex -Intel

- Windows::

    srec_cat.exe bl2\ext\mcuboot\mcuboot.bin -Binary -offset 0x200000 tfm_sign_old.bin-Binary -offset 0x220000 tfm_sign_new.bin -Binary -offset 0x320000 -o tfm.hex -Intel

The following message will be shown in case of successful firmware upgrade when,
RAM loading is enabled, notice that image with higher version number
(``version=0.0.0.2``) is executed:

::

    [INF] Starting bootloader
    [INF] Image 0: version=0.0.0.1, magic= good, image_ok=0x3
    [INF] Image 1: version=0.0.0.2, magic= good, image_ok=0x3
    [INF] Image has been copied from slot 1 in flash to SRAM address 0x10020000
    [INF] Booting image from SRAM at address 0x10020000
    [INF] Bootloader chainload address offset: 0x20000
    [INF] Jumping to the first image slot
    [Sec Thread] Secure image initializing!

--------------

*Copyright (c) 2018-2019, Arm Limited. All rights reserved.*
