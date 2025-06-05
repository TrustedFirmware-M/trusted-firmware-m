##############################
Porting TF-M to a New Hardware
##############################

The purpose of this document is to provide a guide on how to integrate TF-M
with another hardware platform. This document will give general guidance on
how to port a platform on the TF-M build system and which interfaces must
exist on the platform for TF-M (S and NS) to run on this new platform.


*************
Prerequisites
*************

Building environment
====================

Make sure you have a working build environment and that you can build
TF-M on AN521 following the
:doc:`Build instructions </building/tfm_build_instruction>`.

Toolchains and software requirements
====================================

Please follow the :doc:`Getting started guide </getting_started/tfm_getting_started>`.

CMSIS Drivers
=============

The TF-M stack requires at least two CMSIS HAL implementations:

    - `USART <https://arm-software.github.io/CMSIS_6/latest/Driver/group__usart__interface__gr.html>`_
    - `FLASH <https://arm-software.github.io/CMSIS_6/latest/Driver/group__flash__interface__gr.html>`_

************
Porting flow
************

In a nutshell, this should be a 6 iterative steps process:

    #. Adding all the mandatory files and expected objects/functions declarations

    #. Booting and configuring the core(s)

        - startup(s) code and SystemInit

    #. Adding the USART drivers

        - CMSIS HAL

    #. Adding the FLASH drivers

        - CMSIS HAL

    #. Enabling/Configuring/Disabling features including templated features

        - E.G. NV Counters, attestation, crypto keys....

    #. Adding the optional platform SVC handling

        Some platforms may have their own SVC requests in addition to the TF-M built-in ones.

    #. Running the regression tests

        - See :doc:`Running TF-M on Arm platforms </building/run_tfm_examples_on_arm_platforms>`
          as an example


*****************
File architecture
*****************
The platform selection when building TF-M is set via the CMake
variable TFM_PLATFORM. This variable holds part of the path to the platform.
When using ``-DTFM_PLATFORM=arm/mps2/an521`` or ``-DTFM_PLATFORM=an521``
TF-M build system will look for the platform in
<TF-M ROOT>/platform/ext/target/arm/mps2/an521.
Therefore all hardware dependent code for your platform should go to
<TF-M ROOT>/platform/ext/target/.

platform/ext/target
===================
This folder contains a first level of board vendor (such as ARM, STM, NXP,
Cypress ....), each folder will usually contain a second level for each
board. This second level is not mandatory.

    platform/ext/target/<vendor>/[<board name>/]

From now on this will be referred to as the ``platform folder``.

platform/ext/common
===================
This folder contains files and folder commons to the platforms, such as the
shims to the CMSIS drivers. It also contains the scatter files that can be
used for the bl2, tfm_s, tfm_ns partitions.

This folder also contains another folder named template. The latter contains
example implementations that are used for platforms by default, but which can be
altered or replaced if other functionality is required.

    +------------------------------+-----------------------------------------------------------------------------+
    |    name                      |        description                                                          |
    +==============================+=============================================================================+
    |PLATFORM_DEFAULT_ATTEST_HAL   |Use the default implementation of the attestation HAL (default True)         |
    +------------------------------+-----------------------------------------------------------------------------+
    |PLATFORM_DEFAULT_NV_COUNTERS  |Use the default implementation of the counters in NV (default True)          |
    +------------------------------+-----------------------------------------------------------------------------+
    |PLATFORM_DEFAULT_CRYPTO_KEYS  |Use the default implementation of crypto keys (default True)                 |
    +------------------------------+-----------------------------------------------------------------------------+
    |PLATFORM_DEFAULT_ROTPK        |Use the default implementation of the RoT Public Key (default True)          |
    +------------------------------+-----------------------------------------------------------------------------+
    |PLATFORM_DEFAULT_IAK          |Use the default implementation of the initial attestation key (default True) |
    +------------------------------+-----------------------------------------------------------------------------+
    |PLATFORM_DEFAULT_UART_STDOUT  |Use the default implementation of the uart for stdout output (default True)  |
    +------------------------------+-----------------------------------------------------------------------------+
    |PLATFORM_DEFAULT_NV_SEED      |Use the default implementation of the NV seed in the RNG (default True)      |
    +------------------------------+-----------------------------------------------------------------------------+
    |PLATFORM_DEFAULT_OTP          |Use the default implementation of the OTP (default True)                     |
    +------------------------------+-----------------------------------------------------------------------------+

***************
Platform Folder
***************

Description
===========

Depending on the level of integration you want with TF-M some files or
information will be mandatory for the build system to build working firmware.

Please note that platform folder provides source for building both :term:`SPE`
and :term:`NSPE` parts. The SPE builds directly from the source tree while files
necessary for NSPE platform support are installed to ``<Artifact folder>``
for building TF-M application as described in the
:doc:`Build instructions </building/tfm_build_instruction>`.

Questions to be answered:
    - Will the platform use MCUboot as the second stage bootloader?

      BL2/MCUboot provides a secure bootloader that enables simple software
      upgrades.

      This optional second stage bootloader is set-up via the bl2 target in
      the CMakelists.txt file (see below).

    - Will the platform support the Non-Secure world application?

      A platform can be designed to only support the secure world, in which
      case we would refer to it as a secure enclave. TF-M build system allows
      the developer to strip all Non-Secure world related code out of the
      final image. Most platforms, and especially the ones intended to be
      generic or to have a Non-Secure application will require Non-Secure world
      support. In that case a platform shall instruct build system on the file
      set for exporting to Non-Secure world.

    - How does the non-secure world communicate with the secure world?

      TF-M supports running the non-secure world on the same CPU as the secure
      world, communicating via TrustZone or running the non-secure world on
      a separate CPU, communicating via a mailbox. The platform is responsible
      for configuring toolchains with correct CPU and architecture related
      features for secure and non-secure worlds.

      The architecture for secure world is configured in the cpuarch.cmake
      file (see below).

    - How does the FLASH need to be split between worlds?

      The flash split is very dependent on the support of BL2 and NS world.
      When porting a new platform, one shall arrange enough flash size for each
      of them.

      If supporting upgrades (via MCUboot), additional flash area will be
      required to store the updates before upgrading the whole system.

    - How does the RAM need to be split between worlds?

      The RAM split is very dependent on the support of the NS world.

      If you're not porting the platform for a specific project but are enabling
      the Non-Secure world, you should ensure that you leave enough RAM
      available for it to run.

.. Note::

   TF-M S world size in RAM and Flash varies greatly with different build
   options.

   TF-M project provides `metrics <https://qa-reports.linaro.org/tf/tf-m/metrics/?environment=DefaultProfileM&environment=DefaultProfileS&environment=DefaultProfileL&metric=:summary:>`_
   of the S world size for existing platforms, which may help to get a rough
   guide to the sizes needed.

Files
=====

CMakeLists.txt :
----------------

    (MANDATORY)

    This is the entry point for the build system to build your platform on the secure side and
    also export files to build Non-Secure side.

    it must:

        - Add a folder to the target platform_region_defs. [PLATFORM_REGION_DEFS_]

            This folder will contain two files flash_layout.h_ and region_defs.h_

        - Add scatter files to the bl2 and tfm_s targets. [SCATTER_]

            Please note that TF-M provides a common scatter file for the bl2, tfm_s and
            tfm_ns targets, which can be used in most cases.

        - Add startup files to the bl2 and tfm_s targets. [STARTUP_]
        - Add required sources and includes for the bl2 and tfm_s targets [SOURCES_INCLUDES_]
        - Install all files required for building the platform in the Non-secure application [INSTALL_]

    The installation section expands the common installation script with the platform specific files.
    The following predefined variables are available to address the respective subfolders
    of the target ``<Artifact folder>``.

    +-------------------------------------+------------------------------------------------------------+
    |    name                             |        description                                         |
    +=====================================+============================================================+
    |INSTALL_INTERFACE_INC_DIR            | interface/include - interface header files                 |
    +-------------------------------------+------------------------------------------------------------+
    |INSTALL_INTERFACE_SRC_DIR            | interface/src - interface source files                     |
    +-------------------------------------+------------------------------------------------------------+
    |INSTALL_INTERFACE_LIB_DIR            | interface/lib - interface libraries                        |
    +-------------------------------------+------------------------------------------------------------+
    |INSTALL_IMAGE_SIGNING_DIR            | image_signing tools and files                              |
    +-------------------------------------+------------------------------------------------------------+
    |INSTALL_CMAKE_DIR                    | CMake modules for Non-secure app build                     |
    +-------------------------------------+------------------------------------------------------------+
    |INSTALL_PLATFORM_NS_DIR              | NS platform source files                                   |
    +-------------------------------------+------------------------------------------------------------+

config.cmake:
-------------

    (MANDATORY)

    This file is used to setup default build configurations for TF-M and platform configurations
    which have fixed values depending on hardware and software supportness.
    These configurations should be set as normal CMake variables while others are cache variables.

    The platform configurations in the below table are required.

    +------------------------------+-------------------------------------------------------------------+
    |    name                      |        description                                                |
    +==============================+===================================================================+
    |CONFIG_TFM_USE_TRUSTZONE      | Use TrustZone to transition between NSPE and SPE on the same CPU  |
    +------------------------------+-------------------------------------------------------------------+
    |TFM_MULTI_CORE_TOPOLOGY       | NSPE runs on a separate CPU to SPE                                |
    +------------------------------+-------------------------------------------------------------------+

    The platform configurations in the below table control optional features which rely on platform
    specific implementation.
    These features are disabled by default.
    Platforms shall implement corresponding functionalities and explicitly set the configuration to
    enable the feature.

    +-------------------------------------+------------------------------------------------------------+
    |    name                             |        description                                         |
    +=====================================+============================================================+
    |PLATFORM_HAS_ISOLATION_L3_SUPPORT    | Whether the platform has isolation level 3 support         |
    +-------------------------------------+------------------------------------------------------------+
    |PLATFORM_HAS_FIRMWARE_UPDATE_SUPPORT | Whether the platform has firmware update support           |
    +-------------------------------------+------------------------------------------------------------+
    |PSA_API_TEST_TARGET                  | The target platform name of PSA API test                   |
    +-------------------------------------+------------------------------------------------------------+
    |PLATFORM_SVC_HANDLERS                | Whether the platform has specific SVC handling             |
    +-------------------------------------+------------------------------------------------------------+

    For build configurations, please refer to ``config_base.cmake``.

    [config_cmake_]

cpuarch.cmake:
--------------

    (MANDATORY)

    This file contains hardware information such as the main processor and architecture of the SPE
    CPU.
    On single-core platforms, it should be installed to ``<Artifact folder>`` for NSPE build.
    On multi-core platforms, two cpuarch.cmake files should be added.

    - a SPE specific ``cpuarch.cmake`` used in SPE build
    - an NSPE one which should be installed to ``<Artifact folder>`` with filename ``cpuarch.cmake``
      for NSPE build. See `ns/cpuarch_ns.cmake`_.

    +-------------------------+------------------------------------------------------------+
    |    name                 |        description                                         |
    +=========================+============================================================+
    |TFM_SYSTEM_PROCESSOR     | The SPE Processor the platform is using                    |
    +-------------------------+------------------------------------------------------------+
    |TFM_SYSTEM_ARCHITECTURE  | The architecture of the processor                          |
    +-------------------------+------------------------------------------------------------+
    |CONFIG_TFM_FP_ARCH       | The Float Point architecture flag for toolchain            |
    +-------------------------+------------------------------------------------------------+
    |CONFIG_TFM_FP_ARCH_ASM   | The Float Point architecture flag for assembly code        |
    +-------------------------+------------------------------------------------------------+

tests/tfm_tests_config.cmake:
-----------------------------

    (OPTIONAL)

    This file contains platform-specific config options for TF-M regression tests.
    The ``tests`` folder should installed to <Artifact folder>/platform for NSPE build.
    Here are some examples.

    +--------------------------------+------------------------------------------------------------+
    |    name                        |        description                                         |
    +================================+============================================================+
    |PLATFORM_SLIH_IRQ_TEST_SUPPORT  | Whether the platform has SLIH test support                 |
    +-------------------------+-------------------------------------------------------------------+
    |PLATFORM_FLIH_IRQ_TEST_SUPPORT  | Whether the platform has FLIH test support                 |
    +--------------------------------+------------------------------------------------------------+

tests/psa_arch_tests_config.cmake:
----------------------------------

    (OPTIONAL)

    This file contains platform-specific config options for PSA API tests.
    Here are some examples.

    +--------------------------------+------------------------------------------------------------+
    |    name                        |        description                                         |
    +================================+============================================================+
    |PSA_API_TEST_TARGET             | The target platform name of PSA API test                   |
    +--------------------------------+------------------------------------------------------------+

startup files:
---------------

    (MANDATORY)

    These files (one for BL2, one for S, one for NS) are the expected startup
    files. The reset handler should call SystemInit and then should end up
    calling __START which should be defined as _start if not defined elsewhere.

.. _flash_layout.h:

flash_layout.h:
---------------

    (MANDATORY)

    This file can be anywhere in the platform folder, usually in a sub folder
    named ``partition``.
    TF-M doesn't provide a template for this file, common practice is to copy it
    from another platform (e.g. arm/mps2/an521) and update the following entries.

    Note: all size are in bytes

    +------------------------------+-------------------------------------------------------------------+-------------------------------------------+
    |    name                      |        description                                                |    Requisiteness                          |
    +==============================+===================================================================+===========================================+
    |FLASH_S_PARTITION_SIZE        | Size of the Secure partition in flash                             | Yes                                       |
    +------------------------------+-------------------------------------------------------------------+-------------------------------------------+
    |FLASH_NS_PARTITION_SIZE       | Size of the Non-Secure partition in flash                         | if tfm_ns is built                        |
    +------------------------------+-------------------------------------------------------------------+-------------------------------------------+
    |FLASH_AREA_IMAGE_SECTOR_SIZE  | Size of the flash sector                                          | if bl2 is built                           |
    +------------------------------+-------------------------------------------------------------------+-------------------------------------------+
    |FLASH_TOTAL_SIZE              | Flash total size                                                  | Yes                                       |
    +------------------------------+-------------------------------------------------------------------+-------------------------------------------+
    |FLASH_BASE_ADDRESS            | Flash base memory address                                         | if bl2 is built                           |
    +------------------------------+-------------------------------------------------------------------+-------------------------------------------+
    |FLASH_AREA_BL2_OFFSET         | BL2 offset in flash                                               | if bl2 is built                           |
    +------------------------------+-------------------------------------------------------------------+-------------------------------------------+
    |FLASH_AREA_BL2_SIZE           | BL2 flash size                                                    | if bl2 is built                           |
    +------------------------------+-------------------------------------------------------------------+-------------------------------------------+
    |FLASH_PS_AREA_SIZE            | Allocated size for the protected storage data in flash            | Yes                                       |
    +------------------------------+-------------------------------------------------------------------+-------------------------------------------+
    |FLASH_ITS_AREA_SIZE           | Allocated size for the internal trusted storage data in flash     | Yes                                       |
    +------------------------------+-------------------------------------------------------------------+-------------------------------------------+
    |SECURE_IMAGE_OFFSET           | Offset of the secure image data in flash                          | if bl2 is built                           |
    +------------------------------+-------------------------------------------------------------------+-------------------------------------------+
    |FLASH_DEV_NAME                | Name as defined in the CMSIS flash drivers                        | Yes                                       |
    +------------------------------+-------------------------------------------------------------------+-------------------------------------------+
    |TFM_HAL_PS_FLASH_DRIVER       | Name as defined in the CMSIS flash drivers                        | used by protected storage partition       |
    +------------------------------+-------------------------------------------------------------------+-------------------------------------------+
    |TFM_HAL_PS_SECTORS_PER_BLOCK  | Number of physical erase sectors per logical FS block             | used by protected storage partition       |
    +------------------------------+-------------------------------------------------------------------+-------------------------------------------+
    |TFM_HAL_PS_PROGRAM_UNIT       | Smallest flash programmable unit in bytes                         | used by protected storage partition       |
    +------------------------------+-------------------------------------------------------------------+-------------------------------------------+
    |TFM_HAL_ITS_FLASH_DRIVER      | Name as defined in the CMSIS flash drivers                        | used by internal trusted storage partition|
    +------------------------------+-------------------------------------------------------------------+-------------------------------------------+
    |TFM_HAL_ITS_SECTORS_PER_BLOCK | Number of physical erase sectors per logical ITS block            | used by internal trusted storage partition|
    +------------------------------+-------------------------------------------------------------------+-------------------------------------------+
    |TFM_HAL_ITS_PROGRAM_UNIT      | Smallest flash programmable unit in bytes                         | used by internal trusted storage partition|
    +------------------------------+-------------------------------------------------------------------+-------------------------------------------+
    |TFM_NV_COUNTERS_AREA_SIZE     | Allocated size for the NV counters data in flash                  | if using TF-M templates                   |
    +------------------------------+-------------------------------------------------------------------+-------------------------------------------+

.. _region_defs.h:

region_defs.h:
--------------

    (MANDATORY)

    This file can be anywhere in the platform folder, usually in a sub folder
    named ``partition``.
    TF-M doesn't provide a template for this file, common practice is to copy it
    from another platform (e.g. arm/mps2/an521) and update the following entries.

    General advice: if you don't know beforehand the size you will want for
    these elements you will have to make it iterative from an arbitrary value
    taken from another platform (e.g. arm/mps2/an521)

    Note: all size are in bytes

    +----------------------------------+-------------------------------------------------------------------+-----------------------------------------------+
    |    name                          |        description                                                | Requisiteness                                 |
    +==================================+===================================================================+===============================================+
    |BL2_HEAP_SIZE                     | Size of the Bootloader (MCUboot) heap                             | if bl2 is built                               |
    +----------------------------------+-------------------------------------------------------------------+-----------------------------------------------+
    |BL2_MSP_STACK_SIZE                | (if bl2 is built) Size of the Bootloader (MCUboot) Main stack     | if bl2 is built                               |
    +----------------------------------+-------------------------------------------------------------------+-----------------------------------------------+
    |S_HEAP_SIZE                       | Size of the Secure (S) world Heap                                 | yes                                           |
    +----------------------------------+-------------------------------------------------------------------+-----------------------------------------------+
    |S_MSP_STACK_SIZE                  | Size of the Secure (S) world Main stack                           | yes                                           |
    +----------------------------------+-------------------------------------------------------------------+-----------------------------------------------+
    |S_PSP_STACK_SIZE                  | Size of the Secure (S) world Process stack                        | no for IPC model                              |
    +----------------------------------+-------------------------------------------------------------------+-----------------------------------------------+
    |NS_HEAP_SIZE                      | Size of the Non-Secure (NS) world Heap                            | if tfm_ns is built                            |
    +----------------------------------+-------------------------------------------------------------------+-----------------------------------------------+
    |NS_STACK_SIZE                     | Size of the Non-Secure (NS) world stack                           | if tfm_ns is built                            |
    +----------------------------------+-------------------------------------------------------------------+-----------------------------------------------+
    |PSA_INITIAL_ATTEST_MAX_TOKEN_SIZE | Size of the buffer that will store the initial attestation        | used by initial attestation partition         |
    +----------------------------------+-------------------------------------------------------------------+-----------------------------------------------+
    |TFM_ATTEST_BOOT_RECORDS_MAX_SIZE  | Size of buffer that can store the encoded list of boot records    | used by delegated attestation partition       |
    +----------------------------------+-------------------------------------------------------------------+-----------------------------------------------+
    |BL2_HEADER_SIZE                   | Size of the Header for the Bootloader (MCUboot)                   | if bl2 is built                               |
    +----------------------------------+-------------------------------------------------------------------+-----------------------------------------------+
    |BL2_TRAILER_SIZE                  | Size of the Trailer for the Bootloader (MCUboot)                  | if bl2 is built                               |
    +----------------------------------+-------------------------------------------------------------------+-----------------------------------------------+
    |SHARED_SYMBOL_AREA_SIZE           | Size of shared common code between bl2 and tfm_s                  | if bl2 is built and want to reduce image size |
    +----------------------------------+-------------------------------------------------------------------+-----------------------------------------------+

    (OPTIONAL)

    If the TF-M common linker script is used then:

    +----------------------------------+-----------------------------------------------------------------------+-----------------------------------+
    |    name                          |        description                                                    | Requisiteness                     |
    +==================================+=======================================================================+===================================+
    |S_CODE_START                      | Start address for the S code                                          | Yes                               |
    +----------------------------------+-----------------------------------------------------------------------+-----------------------------------+
    |S_CODE_SIZE                       | Size of the S code                                                    | Yes                               |
    +----------------------------------+-----------------------------------------------------------------------+-----------------------------------+
    |S_DATA_START                      | Start address for the S data                                          | Yes                               |
    +----------------------------------+-----------------------------------------------------------------------+-----------------------------------+
    |S_DATA_SIZE                       | Size of the S data                                                    | Yes                               |
    +----------------------------------+-----------------------------------------------------------------------+-----------------------------------+
    |S_RAM_CODE_START                  | Start address for the S code                                          | if no XIP on flash                |
    +----------------------------------+-----------------------------------------------------------------------+-----------------------------------+
    |S_RAM_CODE_SIZE                   | Size of the S code                                                    | if no XIP on flash                |
    +----------------------------------+-----------------------------------------------------------------------+-----------------------------------+

CMSIS_Driver/Config/cmsis_driver_config.h:
------------------------------------------

    (location as defined in CMakeLists.txt)

    This file should include the CMSIS drivers implementation headers.

CMSIS_Driver/Config/RTE_Device.h:
---------------------------------

    (location as defined in CMakeLists.txt)

    This is the Run-Time Environment file from CMSIS, which is there to allow
    enabling or disabling drivers prior to building. If your platform is
    designed as a general use platform, this file should contain all the
    available CMSIS drivers, and you should provide a recommended configuration.
    If your platform is designed for a specific use-case then you should
    reference and enable only the mandatory drivers.

CMSIS_Driver/Driver_Flash.c:
----------------------------

    (location as defined in CMakeLists.txt)

    TF-M relies on CMSIS Drivers, as such it requires the CMSIS functions to
    be implemented. As a platform owner you can decide to either implement the
    drivers in the CMSIS functions or to use the CMSIS functions as a shim to
    your native drivers.

    Refer to the CMSIS `FLASH <https://arm-software.github.io/CMSIS_6/latest/Driver/group__flash__interface__gr.html>`_
    documentation.

CMSIS_Driver/Driver_USART.c:
----------------------------

    (location as defined in CMakeLists.txt)

    TF-M relies on CMSIS Drivers, as such it requires the CMSIS functions to
    be implemented. As a platform owner you can decide to either implement the
    drivers in the CMSIS functions or to use the CMSIS functions as a shim to
    your native drivers.

    Refer to the CMSIS `USART <https://arm-software.github.io/CMSIS_6/latest/Driver/group__usart__interface__gr.html>`_
    documentation.

target_cfg.[ch]:
----------------

    (location as defined in CMakeLists.txt)

    It is expected that these files contain all platform specific code related
    to memory protection (e.g. SAU/PPC/MPC). These functions will not be called
    by TF-M directly, but are expected to be called from the function
    tfm_hal_set_up_static_boundaries() in tfm_hal_isolation.c.

tfm_hal_platform.c:
-------------------

    (location as defined in CMakeLists.txt)

    Each platform is expected to implement the following API declared in
    platform/include/tfm_hal_platform.h

.. code-block:: c

    enum tfm_hal_status_t tfm_hal_platform_init(void);

    The function will be called before SPM initialization.

tfm_hal_isolation.c:
--------------------

    (location as defined in CMakeLists.txt)

    Each platform is expected to implement all the functions declared in
    platform/include/tfm_hal_isolation.h.

    A reference implementation for Armv8-M platforms is provided in
    platform/ext/common/tfm_hal_isolation_v8m.c. Platforms using the common TF-M
    linker scripts and scatter files can use it to implement standard TF-M
    isolation with Armv8-M MPU regions. Platform-specific MPU regions can be
    appended by defining PLATFORM_STATIC_MPU_REGIONS in the platform's
    tfm_peripherals_def.h header.

    These functions will be called from TF-M.

tfm_platform_system.c:
----------------------

    (location as defined in CMakeLists.txt)

    Each platform is expected to implement all the functions declared in
    platform/include/tfm_platform_system.h.

check_config.cmake:
-------------------

    As a platform owner you may want to enforce some configuration or to prevent
    the use of unsupported configurations.

    This file (CMake format) allows you to do so by allowing you to check for
    invalid configuration values.

    This file is optional.

    TF-M build system already provides a generic configuration checker that will
    be called on top of one provided by the platform owner. The generic checker
    is located in <TF-M ROOT>/config/.

    [check_config.cmake_]

platform_svc_numbers.h
----------------------

    (OPTIONAL)

    If your platform has its own SVC handling, then you need to

    - create the ``platform_svc_numbers.h`` which defines the platform SVC numbers.

      The bit [7] of the number must be set to 1 to reflect that it is a platform SVC number.
      The bit [6] indicates whether this SVC should be called from Handler mode or Thread mode.
      For more details of the bit assignments, please check the ``svc_num.h``.
      TF-M provides two Macros ``TFM_SVC_NUM_PLATFORM_THREAD(index)`` and
      ``TFM_SVC_NUM_PLATFORM_HANDLER(index)`` to easily construct a valid number.

    - implement the `platform_svc_handlers`_ function which handles SVC.
    - enable ``PLATFORM_SVC_HANDLERS`` config option.

ns/CMakeLists.txt
-----------------

    (MANDATORY)

    This is CMake script for building the platform support on NSPE side. It's
    copied to ``<Artifact folder>`` in the installation phase and instructs on
    how to build **platform_ns** target. The default NSPE build script expects
    this target definition and extends it with files, common for all TF-M platforms.

    Note::
        This file shall define and use paths of installed directories in ``<Artifact folder>``,
        instead of paths in TF-M platform folder.

    [NSCMakeLists.txt_]

ns/cpuarch_ns.cmake
-------------------

    (MANDATORY for multi-core platforms)

    This file contains the hardware information for the NSPE CPU.
    It should be installed to ``<Artifact folder>/platform`` for NSPE build,
    ranamed to ``ns/cpuarch_ns.cmake``.

    [`ns/cpuarch_ns.cmake`_]

.. _Functions:

Functions
=========

    There are a few functions that need to be declared and properly
    initialized for TF-M to work. The function declarations can be found in
    ``platform/include/tfm_platform_system.h`` and ``platform/include/tfm_hal_*.h``.

tfm_platform_hal_system_reset:
------------------------------

    This function will in most cases end up calling the NVIC System Reset.

    The platform can uninitialize or store some resources before reset.

.. code-block:: c

    void tfm_platform_hal_system_reset(void);


tfm_platform_hal_ioctl:
-----------------------

    A single entry point to platform-specific code across the HAL is provided by the
    IOCTL service.

.. code-block:: c

    enum tfm_platform_err_t tfm_platform_hal_ioctl(tfm_platform_ioctl_req_t request, psa_invec  *in_vec, psa_outvec *out_vec);

tfm_hal_set_up_static_boundaries:
---------------------------------

    Sets up the static isolation boundaries which are constant throughout the
    runtime of the system, including the SPE/NSPE and partition boundaries.

.. code-block:: c

    enum tfm_hal_status_t tfm_hal_set_up_static_boundaries(uintptr_t *p_spm_boundary);

tfm_hal_activate_boundary:
--------------------------

    Activates one Secure Partition boundary.

.. code-block:: c

    enum tfm_hal_status_t tfm_hal_activate_boundary(const struct partition_load_info_t *p_ldinf, uintptr_t boundary);

tfm_hal_memory_check:
---------------------

    Checks if a given range of memory can be accessed with specified access
    types in boundary. The boundary belongs to a partition which contains all
    asset info.

    A default implementation for Armv8-M platforms with TrustZone is provided in
    ``platform/ext/common/tfm_hal_isolation_v8m.c``. Multi-core topology
    platforms without TrustZone may use the
    :doc:`Memory Check APIs </design_docs/dual-cpu/tfm_multi_core_access_check>`
    to implement this HAL.

.. code-block:: c

    enum tfm_hal_status_t tfm_hal_memory_check(uintptr_t boundary, uintptr_t base, size_t size, uint32_t access_type);

tfm_hal_bind_boundary:
----------------------

    Binds partition boundaries with the platform. The platform maintains the
    platform-specific settings for SPM further usage, such as update partition
    boundaries or check resource accessibility. The platform needs to manage the
    settings with internal mechanism, and return a value to SPM. SPM delivers
    this value back to platform when necessary. And SPM checks this value to
    decide if the platform-specific settings need to be updated. Hence multiple
    partitions can have the same value if they have the same platform-specific
    settings, depending on isolation level.

.. code-block:: c

    enum tfm_hal_status_t tfm_hal_bind_boundary(const struct partition_load_info_t *p_ldinf, uintptr_t *p_boundary);

tfm_hal_boundary_need_switch:
-----------------------------

    Lets the platform decide if a boundary switch is needed.

.. code-block:: c

    bool tfm_hal_boundary_need_switch(uintptr_t boundary_from, uintptr_t boundary_to);

tfm_hal_irq_clear_pending:
--------------------------

    This function clears any pending IRQ.

.. code-block:: c

    void tfm_hal_irq_clear_pending(uint32_t irq_num);

tfm_hal_irq_enable:
-------------------

    This function enable an IRQ.

.. code-block:: c

    void tfm_hal_irq_enable(uint32_t irq_num);

tfm_hal_irq_disable:
--------------------

    This function disable an IRQ.

.. code-block:: c

    void tfm_hal_irq_disable(uint32_t irq_num);

platform_svc_handlers
---------------------

    This function is the platform's SVC handler.
    It should return the result for callers and the SPM will then return it to the caller.

.. code-block:: c

    int32_t platform_svc_handlers(uint8_t svc_num, uint32_t *svc_args, uint32_t exc_return);

Annex
=====

CMake build system snippets examples

.. _PLATFORM_REGION_DEFS:

CMakeLists.txt: Defining regions for Secure world platform and all linked to it.

.. code-block:: CMake

    target_include_directories(platform_region_defs
        INTERFACE
        <folder name under the platform folder - usually named platform>
    )

.. _SCATTER:

CMakeLists.txt: Scatter files for SPE platform and bootloader

.. code-block:: CMake

    target_add_scatter_file(bl2
        $<$<C_COMPILER_ID:ARMClang>:${PLATFORM_DIR}/ext/common/armclang/tfm_common_bl2.sct>
        $<$<C_COMPILER_ID:GNU>:${PLATFORM_DIR}/ext/common/gcc/tfm_common_bl2.ld>
        $<$<C_COMPILER_ID:IAR>:${PLATFORM_DIR}/ext/common/iar/tfm_common_bl2.icf>
    )
    target_add_scatter_file(tfm_s
        $<$<C_COMPILER_ID:ARMClang>:${PLATFORM_DIR}/ext/common/armclang/tfm_isolation_s.sct>
        $<$<C_COMPILER_ID:GNU>:${PLATFORM_DIR}/ext/common/gcc/tfm_isolation_s.ld>
        $<$<C_COMPILER_ID:IAR>:${PLATFORM_DIR}/ext/common/iar/tfm_isolation_s.icf>
    )

.. _STARTUP:

CMakeLists.txt: Startup files for SPE platform and bootloader

.. code-block:: CMake

    target_sources(bl2
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/platform/ext/target/<folder to platform>/device/source/startup_<platform name>.c
    )
    target_sources(tfm_s
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/platform/ext/target/<folder to platform>/device/source/startup_<platform name>.c
    )

.. _SOURCES_INCLUDES:

CMakeLists.txt: The Secure world platform sources

.. code-block:: CMake

    target_include_directories(platform_bl2
        PUBLIC
    )
    target_include_directories(platform_s
        PUBLIC
    )

    target_sources(platform_bl2
        PRIVATE
    )
    target_sources(platform_s
        PRIVATE
    )
    target_sources(tfm_spm
        PRIVATE
            target_cfg.c
            tfm_hal_isolation.c
            tfm_hal_platform.c
    )

.. _INSTALL:

CMakeLists.txt: installation for the Non-Secure world platform build

.. code-block:: CMake

    install(FILES ${PLATFORM_DIR}/ext/common/uart_stdout.c
                  native_drivers/arm_uart_drv.c
                  native_drivers/timer_cmsdk/timer_cmsdk.c
                  cmsis_drivers/Driver_USART.c
                  retarget/platform_retarget_dev.c
                  cmsis_core/an521_ns_init.c
            DESTINATION ${INSTALL_PLATFORM_NS_DIR})

    install(DIRECTORY ${PLATFORM_DIR}/ext/common
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}/ext)

.. _config_cmake:

config.cmake

.. code-block:: CMake

    set(CONFIG_TFM_USE_TRUSTZONE            ON)
    set(TFM_MULTI_CORE_TOPOLOGY             OFF)
    set(BL2                                 OFF         CACHE BOOL      "Whether to build BL2")
    set(NS                                  FALSE       CACHE BOOL      "Whether to build NS app" FORCE)

.. _check_config.cmake:

check_config.cmake

.. code-block:: CMake

    function(tfm_invalid_config)
        if (${ARGV})
            string (REPLACE ";" " " ARGV_STRING "${ARGV}")
            string (REPLACE "STREQUAL"     "=" ARGV_STRING "${ARGV_STRING}")
            string (REPLACE "GREATER"      ">" ARGV_STRING "${ARGV_STRING}")
            string (REPLACE "LESS"         "<" ARGV_STRING "${ARGV_STRING}")
            string (REPLACE "VERSION_LESS" "<" ARGV_STRING "${ARGV_STRING}")
            string (REPLACE "EQUAL"        "=" ARGV_STRING "${ARGV_STRING}")
            string (REPLACE "IN_LIST"      "in" ARGV_STRING "${ARGV_STRING}")

            message(FATAL_ERROR "INVALID CONFIG: ${ARGV_STRING}")
        endif()
    endfunction()

    # Requires armclang >= 6.10.1
    tfm_invalid_config((CMAKE_C_COMPILER_ID STREQUAL "ARMClang") AND (CMAKE_C_COMPILER_VERSION VERSION_LESS "6.10.1"))

.. _NSCMakeLists.txt:

/ns/CMakeLists.txt:

.. code-block:: CMake

    add_library(platform_ns)

    target_sources(platform_ns
        PRIVATE
            arm_uart_drv.c
            timer_cmsdk.c
            uart_stdout.c
            Driver_USART.c
        PUBLIC
            cmsis_core/startup_an521.c
    )

    target_include_directories(platform_ns
        PUBLIC
            include
            cmsis
            cmsis_core
    )

    target_compile_definitions(platform_ns
        PUBLIC
            $<$<BOOL:${PLATFORM_DEFAULT_CRYPTO_KEYS}>:PLATFORM_DEFAULT_CRYPTO_KEYS>
    )

*Copyright (c) 2021-2024, Arm Limited. All rights reserved.*

*Copyright (c) 2022 Cypress Semiconductor Corporation (an Infineon company)
or an affiliate of Cypress Semiconductor Corporation. All rights reserved.*
