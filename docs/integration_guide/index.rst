#################
Integration Guide
#################
The purpose of this document is to provide a guide on how to integrate TF-M
with other hardware platforms and operating systems.

.. toctree::
    :maxdepth: 1

    Source Structure        <source_structure/index>
    SPM Backends            <spm_backends.rst>
    NS client integration   <non-secure_client_extension_integration_guide.rst>
    OS migration to Armv8-M <os_migration_guide_armv8m.rst>
    Floating-Point Support  <tfm_fpu_support.rst>
    Secure Interrupt        <tfm_secure_irq_integration_guide.rst>
    Platform Provisioning   <platform_provisioning.rst>
    Branch Protection       <branch_protection.rst>

.. toctree::
    :maxdepth: 2

    platform/index
    services/index

*****************
How to build TF-M
*****************
Follow the :doc:`Build instructions </building/tfm_build_instruction>`.

********************************************************
How to export files for building non-secure applications
********************************************************
Explained in the :doc:`Build instructions </building/tfm_build_instruction>`.

*************************
How to add a new platform
*************************

:doc:`Porting TF-M to a New Hardware </integration_guide/platform/porting_tfm_to_a_new_hardware>`
contains guidance on how to add a new platform.

***************************
How to integrate another OS
***************************

OS migration to Armv8-M platforms
=================================
To work with TF-M on Armv8-M platforms, the OS needs to support the Armv8-M
architecture and, in particular, it needs to be able to run in the non-secure
world. More information about OS migration to the Armv8-M architecture can be
found in the :doc:`OS requirements <os_migration_guide_armv8m>`. Depending upon
the system configuration this may require configuring drivers to use appropriate
address ranges.

Interface with TF-M
===================
The files needed for the interface with TF-M are exported at the
``<install_dir>/interface`` path. The NS side is only allowed to call
TF-M secure functions (veneers) from the NS Thread mode.

TF-M interface header files are exported in ``<install_dir>/interface/include``
directory. For example, the Protected Storage (PS) service PSA API is declared
in the file ``<install_dir>/interface/include/psa/protected_storage.h``.

TF-M also exports a reference implementation of PSA APIs for NS clients in the
``<install_dir>/interface/src``.

On Armv8-M TrustZone based platforms, NS OS uses ``tfm_ns_interface_dispatch()``
to integrate with TF-M implementation of PSA APIs. TF-M provides a reference
implementation of this function for RTOS and bare metal use cases.
RTOS implementation of ``tfm_ns_interface_dispatch()`` (provided in
``interface\src\os_wrapper\tfm_ns_interface_rtos.c``) uses mutex to provide
multithread safety. Mutex wrapper functions defined in
``interface/include/os_wrapper/mutex.h`` are expected to be provided by NS RTOS.
When reference RTOS implementation of dispatch function is used NS application
should call ``tfm_ns_interface_init()`` function before first PSA API call.
Bare metal implementation ``tfm_ns_interface_dispatch()`` (provided in
``interface\src\os_wrapper\tfm_ns_interface_bare_metal.c``) does not
provide multithread safety and does not require implementation of mutex
interface.
If needed, instead of using reference implementation, NS application may provide
its own implementation of ``tfm_ns_interface_dispatch()`` function.

TF-M provides a reference implementation of NS mailbox on multi-core platforms,
under folder ``interface/src/multi_core``.
See :doc:`Mailbox design </design_docs/dual-cpu/mailbox_design_on_dual_core_system>`
for TF-M multi-core mailbox design.

Interface with non-secure world regression tests
================================================
A non-secure application that wants to run the non-secure regression tests
needs to call the ``tfm_non_secure_client_run_tests()``. This function is
exported into the header file ``test_framework_integ_test.h`` inside the
``<build_dir>/install`` folder structure in the test specific files,
i.e. ``<build_dir>/install/export/tfm/test/inc``. The non-secure regression
tests are precompiled and delivered as a static library which is available in
``<build_dir>/install/export/tfm/test/lib``, so that the non-secure application
needs to link against the library to be able to invoke the
``tfm_non_secure_client_run_tests()`` function. The PS non-secure side
regression tests rely on some OS functionality e.g. threads, mutexes etc. These
functions comply with CMSIS RTOS2 standard and have been exported as thin
wrappers defined in ``os_wrapper.h`` contained in
``<build_dir>/install/export/tfm/test/inc``. OS needs to provide the
implementation of these wrappers to be able to run the tests.

NS client Identification
========================

The NS client identification (NSID) is specified by either SPM or NSPE RTOS.
If SPM manages the NSID (default option), then the same NSID (-1) will be used
for all connections from NS clients.
For the case that NSPE RTOS manages the NSID and/or different NSIDs should be
used for different NS clients. See
:doc:`Non-secure Client Extension Integration Guide </integration_guide/non-secure_client_extension_integration_guide>`.

*********************
Non-secure interrupts
*********************
Non-secure interrupts are allowed to preempt Secure thread mode.
With the current implementation, a NSPE task can spoof the identity of another
NSPE task. This is an issue only when NSPE has provisions for task isolation.
Note, that ``AIRCR.PRIS`` is still set to restrict the priority range available
to NS interrupts to the lower half of available priorities so that it wouldn't
be possible for any non-secure interrupt to preempt a higher-priority secure
interrupt.

********************************
Secure interrupts and scheduling
********************************
To ensure correct operation in the general case, the secure scheduler is not
run after handling a secure interrupt that pre-empted the NSPE. On systems
with specific constraints, it may be desirable to run the scheduler in this
situation, which can be done by setting
``CONFIG_TFM_SCHEDULE_WHEN_NS_INTERRUPTED`` to 1. This could be done if the
NSPE is known to be a simple, single-threaded application or if non-secure
interrupts cannot preempt the SPE, for example.

Note that scheduling also depends on the system topology. If your system has
multiple cores running multiple NSPEs, then refer to
:doc:`Scheduling Hybrid Platforms </design_docs/dual-cpu/hybrid_platform_solution>`
for more details.

**********************************
Integration with non-Cmake systems
**********************************

Generated Files
===============

Files that are derived from PSA manifests are generated at build-time by cmake.
For integration with systems that do no use cmake, the files must be generated
manually.

The ``tools/tfm_parse_manifest_list.py`` script can be invoked manually. Some
arguments will be needed to be provided. Please refer to
``tfm_parse_manifest_list.py --help`` for more details.

Some variables are used in the template files, these will need to be set in the
environment before the script will succeed when the script is not run via cmake.

--------------

*Copyright (c) 2017-2022, Arm Limited. All rights reserved.*
*Copyright (c) 2023 Cypress Semiconductor Corporation (an Infineon company)
or an affiliate of Cypress Semiconductor Corporation. All rights reserved.*
