#####################
RSE integration guide
#####################

*******
Porting
*******

To create a port for a new platform integration of RSE, make a new directory
under the top-level RSE platform: ``platform/ext/target/arm/rse/<platform name>``.

At a minimum an RSE platform port must include the following.

Build and configuration files (see
:doc:`Porting TF-M </integration_guide/platform/porting_tfm_to_a_new_hardware>`
for more detail about each file):

- ``check_config.cmake``: Used to check for invalid build configs. At a minimum,
  include the common RSE ``check_config.cmake``.

- ``CMakeLists.txt``: CMakeLists file to build the files added to the platform.
  Call ``add_subdirectory()`` first to add the common RSE ``CMakeLists.txt``.

- ``config_tfm_target.h``: Defines TF-M configuration options.

- ``config.cmake``: Defines build configuration options (see below).

- ``cpuarch.cmake``: Defines HW properties for the build system. Include the
  common RSE ``cpuarch.cmake`` unless different properties are required.

- ``ns/CMakeLists.txt``: CMakeLists file for the NSPE build. Include the common
  RSE ``common.cmake`` first and add any files in the platform needed for the
  NSPE build.

- ``tests/tfm_tests_config.cmake``: Build configuration for the tests. Include
  the common RSE ``tfm_tests_config.cmake`` and add extra settings if required.

- ``tests/tfm_tests_ns_config.cmake``: Build configuration for the NS tests.
  Include the common RSE ``tfm_tests_config.cmake`` and add extra settings if
  required.

Platform files:

- ``flash_layout.h``: Defines the layout of firmware images in flash. See
  :doc:`Porting TF-M </integration_guide/platform/porting_tfm_to_a_new_hardware>`.

- ``host_base_address.h``: Defines the base addresses of host system flash and
  image load destinations.

- ``rse_memory_sizes.h``: Defines memory area sizes in RSE that may be
  configured by the platform.

- ``cmsis_drivers/Driver_Flash.c``: CMSIS Driver for the host flash device that
  contains the boot images.

- ``cmsis_drivers/host_cmsis_driver_config.h``: CMSIS Driver config definitions.

- ``device/host_device_cfg.h``: Configuration file to define which additional
  peripheral devices in ``host_device_definition.c`` to include in the build.

- ``device/host_device_definition.c``: Defines device structs for additional
  peripherals in the platform on top of the RSE base peripherals.

- ``device/host_device_definition.h``: Declarations for additional peripheral
  device structs.

Boot HAL:

- ``bl2/boot_hal_bl2.c``: Platform HAL for the BL2 bootloader. The platform
  should implement the ``boot_platform_post_init()`` and
  ``boot_platform_start_next_image()`` functions to initialize and uninitialize drivers. It
  should implement ``boot_platform_pre_load()`` and
  ``boot_platform_post_load()`` to setup and tear down the required ATU regions
  before and after each image is loaded, as well as to implement any required
  synchronization between processing elements (PEs) before or after each image
  is loaded.

- ``bl2/flash_map_bl2.c``: Defines the flash areas that store each boot image
  loaded by the BL2 boot stage using the definitions in ``flash_layout.h``.

Comms HAL:

- ``rse_comms/rse_comms_permissions_hal.c``: Implements access control for RSE
  runtime service requests received over MHU. The platform should implement the
  ``comms_permissions_service_check()`` function to define which services can be
  accessed by an MHU endpoint. It should implement the
  ``comms_permissions_memory_check()`` function to control which host memory
  areas may be used to pass input and/or output parameters to RSE when using the
  pointer access RSE comms protocol.

*******************
Build configuration
*******************

The RSE platform supports a large degree of configuration via build options
defined in ``platform/ext/target/arm/rse/common/config.cmake``. System
integrators may override the defaults in the common config by setting them in
``rse/<platform name>/config.cmake``, before including the common config file.

The common config file describes each option, and more detail is provided below
for some critical options.

Boot configuration
==================

- ``MCUBOOT_IMAGE_NUMBER``: Set to the number of images for RSE BL2 to load. For
  example, if BL2 is loading RSE SPE, RSE NSPE, AP BL1 and SCP BL1 then set to
  ``4``. Defaults to ``4``.

- ``TFM_LOAD_NS_IMAGE``: Set to ``ON`` to load an RSE NSPE image, or ``OFF`` to
  run SPE runtime firmware only on RSE. Defaults to ``ON``.

- ``RSE_XIP``: Set to ``ON`` to execute the RSE SPE and RSE NSPE (if applicable)
  in place in external storage via the Secure I-Cache, or ``OFF`` to load the
  RSE runtime firmware into RSE SRAM. This option should be set to ``ON`` if the
  RSE HW has been configured with the Secure I-Cache peripheral and without
  enough internal SRAM to hold the full runtime firmware binary. Defaults to
  ``OFF``.

Attestation scheme
==================

RSE supports three attestation schemes:

- PSA Attestation
- CCA Attestation
- DICE Protection Environment (DPE)

Set ``TFM_ATTESTATION_SCHEME`` to ``PSA``, ``CCA`` or ``DPE`` as required by the
use case of the platform integrating RSE, or set it to ``OFF`` to disable all
attestation services.

RSE does not currently support multiple simultaneous attestation services.

**************
Key management
**************

BL1 bootloader keys
===================

The BL1 bootloader requires an LMS keypair to verify signed BL2 images and a
256-bit AES key to decrypt encrypted BL2 images.

Generate an LMS keypair with LMS parameter set lms_sha256_m32_h10 and LMOTS
parameter set lmots_sha256_n32_w8. This can be done using the
`pyhsslms <https://pypi.org/project/pyhsslms/>`_ Python package by calling its
``genkey`` command::

    hsslms genkey bl2_signing_key --levels 1 --lms 10 --lmots 8 --alg sha256 --trunc 32

This will generate a private key ``bl2_signing_key.prv`` and public key
``bl2_signing_key.pub``, which can be used to replace the development keys in
``bl1/bl1_2/bl1_dummy_rotpk.prv`` and ``bl1/bl1_2/bl1_dummy_rotpk.pub`` by
building TF-M with the parameter
``TFM_BL2_CM_SIGNING_KEY_PATH=path/to/bl2_signing_key``.

The private key is updated each time a new BL2 image is signed. In a production
system, a process must be put in place to ensure that the private keys are kept
secret and that a previously-used LMS private key is never reused.

Generate a 256-bit AES key by generating 32-bytes of random number generator
output. For example, using openssl::

    openssl rand -out bl2_encryption_key 32

The key generated can be used to replace the development key in
``bl1/bl1_2/bl2_dummy_encryption_key.bin`` by building TF-M with the parameter
``TFM_BL2_ENCRYPTION_KEY_PATH=path/to/bl2_encryption_key``.

The public key and encryption key must be added to the provisioning values (see
below).

BL2 bootloader keys
===================

The BL2 bootloader requires asymmetric keypairs to verify signed RSE NSPE, RSE
SPE and other PE BL1 images. By default, the RSE platform configures BL2 to use
ECDSA with the P256 curve as the signature scheme, but it can be changed using
the ``MCUBOOT_SIGNATURE_TYPE`` build option. This guide assumes ECDSA-P256 is
used.

Generate an ECDSA-P256 key using the `imgtool <https://pypi.org/project/imgtool/>`_
``keygen`` command::

    imgtool keygen -k keyname.pem -t ecdsa-p256

This will generate a private key ``keyname.pem``, which can be used to replace
the development key in ``bl2/ext/mcuboot/root-EC-P256.pem``. Build TF-M with
the parameter ``MCUBOOT_KEY_S=path/to/keyname.pem`` to set the key to sign the
RSE SPE and ``MCUBOOT_KEY_NS=path/to/keyname.pem`` for the NSPE. The keys for
signing the SPE and NSPE may be the same or different depending on whether the
same trust agent is producing both images.

To sign other PE BL1 images loaded by RSE BL2 but not built as part of the TF-M
build, use the ``imgtool sign`` command::

    imgtool sign \
        --key <path/to/keyname.pem> \
        --public-key-format full \
        --max-align 8 \
        --align 1 \
        --version "<major>.<minor>.<patch>[+<build>]" \
        --security-counter <security count> \
        --header-size 0x2000 \
        --pad-header \
        --slot-size 0x80000 \
        --pad \
        --load-addr <load address> \
        <binary infile> \
        <signed binary outfile>

The public key can then be extracted from the private key file using the
``imgtool getpub`` command::

    imgtool getpub -o keyname.pub -k keyname.pem -e lang-c

The public keys must be added to the provisioning values (see below).

Provisioning values
===================

The GUK is a key unique to a group of chips that have identical security
properties, used to derive the attestation key. It is a 256-bit value that
should be created from random number generator output. The dummy key in
``bl1/bl1_1/dummy_guk.bin`` must be replaced by setting the build parameter
``TFM_GUK_PATH`` to the path of the generated GUK.

The RTL key is a 256-bit key embedded in the RSE HW and used for authenticated
decryption of encrypted provisioning bundles. The path to the RTL key file must
be supplied via the ``RSE_RTL_KEY_PATH`` build parameter to use it to encrypt
the provisioning bundles.

The dummy provisioning data in
``platform/ext/target/arm/rse/common/provisioning/bundle_cm/cm_dummy_provisioning_data.c``
and
``platform/ext/target/arm/rse/common/provisioning/bundle_dm/dm_dummy_provisioning_data.c``
must be replaced with files containing the real provisioning values.

The GUK must be included in the CM provisioning data.

The BL1 public key and encryption key must be included in the DM provisioning
data.

If the BL2 default config is used, i.e.
``MCUBOOT_BUILTIN_KEY=OFF`` and ``MCUBOOT_HW_KEY=ON``, then the SHA-256 hashes
of the public keys must be provisioned. Otherwise, a platform might decide to
enable direct usage of builtin keys, i.e. ``MCUBOOT_BUILTIN_KEY=ON`` and
``MCUBOOT_HW_KEY=OFF``: In this case, the whole BL2 public key for each image
must be included in the DM provisioning bundle.

--------------

*SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors*

*SPDX-License-Identifier: BSD-3-Clause*
