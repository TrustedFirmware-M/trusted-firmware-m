.. _tf-m_configuration:

#############
Configuration
#############

.. toctree::
    :maxdepth: 1
    :glob:

    build_configuration.rst
    Component configuration <header_file_system>
    Kconfig <kconfig_system>
    Profiles <profiles/index>
    test_configuration.rst

TF-M is highly configurable project with many configuration options to meet
a user's needs. A user can select the desired set of services and fine-tune
them to their requirements. There are two types of configuration options

Build configuration
   Specifies which file or component to include into compilation and build.
   These are options, usually used by a build system to enable/disable
   modules, specify location of external dependency or other selection,
   global to a project. These option set shall be considered while adopting TF-M
   to other build systems.
   In the :ref:`Base_configuration` table these options have *Build* type.

Component configuration
   To adjust a particular parameter to a desired value. Those options are
   local to a component or externally referenced when components are coupled.
   Options are in C header file. The :ref:`Header_configuration` has more
   details about it.
   In the :ref:`Base_configuration` table these options have *Component* type.

.. Note::
   Originally, TF-M used CMake variables for both building and component tuning
   purposes. It was convenient to have a single system for both building and
   component's configurations. To simplify and improve configurability and
   better support build systems other than a CMake, TF-M introduced a
   :ref:`Header_configuration` and moved component options into a dedicated
   config headers.

****************
How to configure
****************

TF-M Project provides a base build, defined in ``/config/config_base.cmake``
and ``/config/config_base.h``.
Starting from the base, users can enable required services and features using several
independent methods to configure TF-M.

Use :ref:`tf-m_profiles`.
   There are 4 sets of predefined configurations for a elected
   use cases, called profiles. A user can select a profile by providing
   -DTFM_PROFILE=<profile file name>.
   Each profiles represented by a pair of configuration files for
   Building (CMake) options and Component options (.h file)

Use a custom profile.
   Another method is to take an existing TF-M profile and adjust the desired
   options manually editing CMake and config header files. This is for users
   familiar with TF-M.

Use :ref:`Kconfig_system`.
   This method is recommended for beginners. Starting from the
   *base configuration* a user can enable necessary services and options.
   KConfig ensurers that all selected options are consistent and valid.
   This is new in v1.7.0 and it covers only SPM and PSA services. As an output
   KConfig produces a pair of configuration files, similar to a profile.

.. Note::
   In contrast, before TF-M v1.7.0, the default build includes all possible
   features. With growing functionality, such rich default build became
   unpractical by not fitting into every platform and confusing of big
   memory requirements.

**********
Priorities
**********

A project configuration performed in multiple steps with priorities.
The list below explains the process but for the details specific to
:ref:`tfm_cmake_configuration` or :ref:`Header_configuration` please
check the corresponded document.

#. The base configuration with default values is used as a starting point
#. A profile options applied on top of the base
#. A platform can check the selected configuration and apply restrictions
#. Finally, command line options can modify the composed set

.. Note::
   To ensure a clear intention and conscious choice, all options must be
   provided explicitly via a project configuration file. Default values
   on step 1 will generate warnings which are expected to break a build.

.. _Base_configuration:

******************
Base Configuration
******************

The base configuration is the ground for configuring TF-M, provided defaults
are defined in ``/config/config_base.cmake`` and ``/config/config_base.h``.
The base build includes SPM and platform code only.

This table lists the config option categorizations of the SPM and Secure
Partitions.

Crypto
======
+-------------------------------------+-----------+------------+
| Options                             | Type      | Base Value |
+=====================================+===========+============+
|TFM_PARTITION_CRYPTO                 | Build     |   OFF      |
+-------------------------------------+-----------+------------+
|CRYPTO_TFM_BUILTIN_KEYS_DRIVER       | Build     |   ON       |
+-------------------------------------+-----------+------------+
|CRYPTO_NV_SEED                       | Component |   ON       |
+-------------------------------------+-----------+------------+
|CRYPTO_ENGINE_BUF_SIZE               | Component |   0x2080   |
+-------------------------------------+-----------+------------+
|CRYPTO_IOVEC_BUFFER_SIZE             | Component |   5120     |
+-------------------------------------+-----------+------------+
|CRYPTO_STACK_SIZE                    | Component |   0x1B00   |
+-------------------------------------+-----------+------------+
|CRYPTO_CONC_OPER_NUM                 | Component |   8        |
+-------------------------------------+-----------+------------+
|CRYPTO_RNG_MODULE_ENABLED            | Component |   1        |
+-------------------------------------+-----------+------------+
|CRYPTO_KEY_MODULE_ENABLED            | Component |   1        |
+-------------------------------------+-----------+------------+
|CRYPTO_AEAD_MODULE_ENABLED           | Component |   1        |
+-------------------------------------+-----------+------------+
|CRYPTO_MAC_MODULE_ENABLED            | Component |   1        |
+-------------------------------------+-----------+------------+
|CRYPTO_HASH_MODULE_ENABLED           | Component |   1        |
+-------------------------------------+-----------+------------+
|CRYPTO_CIPHER_MODULE_ENABLED         | Component |   1        |
+-------------------------------------+-----------+------------+
|CRYPTO_ASYM_SIGN_MODULE_ENABLED      | Component |   1        |
+-------------------------------------+-----------+------------+
|CRYPTO_ASYM_ENCRYPT_MODULE_ENABLED   | Component |   1        |
+-------------------------------------+-----------+------------+
|CRYPTO_KEY_DERIVATION_MODULE_ENABLED | Component |   1        |
+-------------------------------------+-----------+------------+
|CRYPTO_SINGLE_PART_FUNCS_ENABLED     | Component |   1        |
+-------------------------------------+-----------+------------+

Initial Attestation
===================
+-------------------------------------+-----------+-------------+
| Options                             | Type      | Base Value  |
+=====================================+===========+=============+
|TFM_PARTITION_INITIAL_ATTESTATION    | Build     |   OFF       |
+-------------------------------------+-----------+-------------+
|SYMMETRIC_INITIAL_ATTESTATION        | Build     |   OFF       |
+-------------------------------------+-----------+-------------+
|ATTEST_KEY_BITS                      | Build     |   256       |
+-------------------------------------+-----------+-------------+
|ATTEST_TOKEN_PROFILE                 | Component | "PSA_IOT_1" |
+-------------------------------------+-----------+-------------+
|ATTEST_INCLUDE_OPTIONAL_CLAIMS       | Component |   1         |
+-------------------------------------+-----------+-------------+
|ATTEST_INCLUDE_COSE_KEY_ID           | Component |   0         |
+-------------------------------------+-----------+-------------+
|ATTEST_STACK_SIZE                    | Component |   0x800     |
+-------------------------------------+-----------+-------------+

Internal Trusted Storage
========================
+---------------------------------------+-----------+------------------------+
| Options                               | Type      | Base Value             |
+=======================================+===========+========================+
|TFM_PARTITION_INTERNAL_TRUSTED_STORAGE | Build     |   OFF                  |
+---------------------------------------+-----------+------------------------+
|ITS_CREATE_FLASH_LAYOUT                | Component |   1                    |
+---------------------------------------+-----------+------------------------+
|ITS_RAM_FS                             | Component |   0                    |
+---------------------------------------+-----------+------------------------+
|ITS_VALIDATE_METADATA_FROM_FLASH       | Component |   1                    |
+---------------------------------------+-----------+------------------------+
|ITS_MAX_ASSET_SIZE                     | Component |   512                  |
+---------------------------------------+-----------+------------------------+
|ITS_NUM_ASSETS                         | Component |   10                   |
+---------------------------------------+-----------+------------------------+
|ITS_BUF_SIZE                           | Component |   ITS_MAX_ASSET_SIZE   |
+---------------------------------------+-----------+------------------------+
|ITS_STACK_SIZE                         | Component |   0x720                |
+---------------------------------------+-----------+------------------------+

Protected Storage
=================
+---------------------------------------+-----------+-----------------+
| Options                               | Type      | Base Value      |
+=======================================+===========+=================+
|TFM_PARTITION_PROTECTED_STORAGE        | Build     |   OFF           |
+---------------------------------------+-----------+-----------------+
|PS_ENCRYPTION                          | Build     |   ON            |
+---------------------------------------+-----------+-----------------+
|PS_SUPPORT_FORMAT_TRANSITION           | Build     |   OFF           |
+---------------------------------------+-----------+-----------------+
|PS_CRYPTO_AEAD_ALG                     | Build     |   PSA_ALG_GCM   |
+---------------------------------------+-----------+-----------------+
|PS_AES_KEY_USAGE_LIMIT                 | Build     |   0             |
+---------------------------------------+-----------+-----------------+
|PS_CREATE_FLASH_LAYOUT                 | Component |   1             |
+---------------------------------------+-----------+-----------------+
|PS_RAM_FS                              | Component |   0             |
+---------------------------------------+-----------+-----------------+
|PS_VALIDATE_METADATA_FROM_FLASH        | Component |   1             |
+---------------------------------------+-----------+-----------------+
|PS_MAX_ASSET_SIZE                      | Component |   2048          |
+---------------------------------------+-----------+-----------------+
|PS_NUM_ASSETS                          | Component |   10            |
+---------------------------------------+-----------+-----------------+
|PS_ROLLBACK_PROTECTION                 | Component |   1             |
+---------------------------------------+-----------+-----------------+
|PS_STACK_SIZE                          | Component |   0x700         |
+---------------------------------------+-----------+-----------------+

Firmware Update
===============
+-------------------------------------+-----------+-------------------------------------+
| Options                             | Type      | Base Value                          |
+=====================================+===========+=====================================+
|PLATFORM_HAS_FIRMWARE_UPDATE_SUPPORT | Build     |   OFF                               |
+-------------------------------------+-----------+-------------------------------------+
|TFM_PARTITION_FIRMWARE_UPDATE        | Build     |   OFF                               |
+-------------------------------------+-----------+-------------------------------------+
|TFM_CONFIG_FWU_MAX_WRITE_SIZE        | Build     |   1024                              |
+-------------------------------------+-----------+-------------------------------------+
|TFM_CONFIG_FWU_MAX_MANIFEST_SIZE     | Build     |   0                                 |
+-------------------------------------+-----------+-------------------------------------+
|FWU_DEVICE_CONFIG_FILE               | Build     |   ""                                |
+-------------------------------------+-----------+-------------------------------------+
|FWU_SUPPORT_TRIAL_STATE              | Build     | Depends on MCUBOOT_UPGRADE_STRATEGY |
+-------------------------------------+-----------+-------------------------------------+
|TFM_FWU_BOOTLOADER_LIB               | Build     |   "mcuboot"                         |
+-------------------------------------+-----------+-------------------------------------+
|FWU_DEVICE_IMPL_INFO_DEF_FILE        | Build     |   ""                                |
+-------------------------------------+-----------+-------------------------------------+
|TFM_FWU_BUF_SIZE                     | Component |   PSA_FWU_MAX_BLOCK_SIZE            |
+-------------------------------------+-----------+-------------------------------------+
|FWU_STACK_SIZE                       | Component |   0x600                             |
+-------------------------------------+-----------+-------------------------------------+

Platform Secure Partition
=========================
+-------------------------------------+-----------+------------+
| Options                             | Type      | Base Value |
+=====================================+===========+============+
|TFM_PARTITION_PLATFORM               | Build     |   OFF      |
+-------------------------------------+-----------+------------+
|PLATFORM_SERVICE_INPUT_BUFFER_SIZE   | Component |   64       |
+-------------------------------------+-----------+------------+
|PLATFORM_SERVICE_OUTPUT_BUFFER_SIZE  | Component |   64       |
+-------------------------------------+-----------+------------+
|PLATFORM_SP_STACK_SIZE               | Component |   0x500    |
+-------------------------------------+-----------+------------+
|PLATFORM_NV_COUNTER_MODULE_DISABLED  | Component |   0        |
+-------------------------------------+-----------+------------+

NS Agent Mailbox Secure Partition
=================================
+-------------------------------------+-----------+------------+
| Options                             | Type      | Base Value |
+=====================================+===========+============+
|NS_AGENT_MAILBOX_STACK_SIZE          | Component |   0x800    |
+-------------------------------------+-----------+------------+
|MAILBOX_IS_UNCACHED_S                | Component |   1        |
+-------------------------------------+-----------+------------+
|MAILBOX_IS_UNCACHED_NS               | Component |   1        |
+-------------------------------------+-----------+------------+


Secure Partition Manager
========================
+----------------------------------------+-----------+-------------+
| Options                                | Type      | Base Values |
+========================================+===========+=============+
|TFM_ISOLATION_LEVEL                     | Build     |   1         |
+----------------------------------------+-----------+-------------+
|PSA_FRAMEWORK_HAS_MM_IOVEC              | Build     |   OFF       |
+----------------------------------------+-----------+-------------+
|CONFIG_TFM_SPM_BACKEND                  | Build     |   "SFN"     |
+----------------------------------------+-----------+-------------+
|TFM_SPM_LOG_LEVEL                       | Build     |   1         |
+----------------------------------------+-----------+-------------+
|CONFIG_TFM_STACK_WATERMARKS             | Build     |   OFF       |
+----------------------------------------+-----------+-------------+
|CONFIG_TFM_CONN_HANDLE_MAX_NUM          | Component |   8         |
+----------------------------------------+-----------+-------------+
|CONFIG_TFM_DOORBELL_API                 | Component |   0         |
+----------------------------------------+-----------+-------------+
|CONFIG_TFM_SCHEDULE_WHEN_NS_INTERRUPTED | Component |   0         |
+----------------------------------------+-----------+-------------+
|CONFIG_TFM_HYBRID_PLAT_SCHED_TYPE       | Component |   0         |
+----------------------------------------+-----------+-------------+

--------------

*SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors*

*Copyright (c) 2023-2024 Cypress Semiconductor Corporation (an Infineon company)
or an affiliate of Cypress Semiconductor Corporation. All rights reserved.*

*SPDX-License-Identifier: BSD-3-Clause*
