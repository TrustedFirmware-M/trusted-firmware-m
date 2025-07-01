#######################
Adding Secure Partition
#######################

***********************
Terms and abbreviations
***********************
This document uses the following terms and abbreviations.

.. table:: term table
   :widths: auto

   ================== ==================================
    **Term**          **Meaning**
   ================== ==================================
   FF-M               Firmware Framework for M
   ID                 Identifier
   IPC                Interprocess communication
   IPC model          The secure IPC framework
   irqs               Interrupt requests
   MMIO               Memory Mapped I/O
   PSA                Platform Security Architecture
   RoT                Root of Trust
   SFN                Secure Function
   SFN model          Secure Function model
   SID                RoT Service ID
   SP                 Secure Partition
   SPM                Secure Partition Manager
   TF-M               Trusted firmware M
   ================== ==================================

************
Introduction
************
Secure Partition is an execution environment that provides the following
functions to Root of Trust (RoT) Services:

- Access to resources, protection of its own code and data.
- Mechanisms to interact with other components in the system.

Each Secure Partition is a single thread of execution and the smallest unit of
isolation.

This document mainly describes how to add a secure partition in TF-M and
focuses on the configuration, manifest, implement rules. The actual
source-level implementation is not included in this document.

.. Note::
   If not otherwise specified, the steps are identical for IPC and SFN model.

   The IPC and SFN model conforms to the *PSA Firmware Framework for M (FF-M) v
   1.1* changes. Refer to `PSA Firmware Framework specification`_ and
   `Firmware Framework for M 1.1 Extensions`_ for details.

*******
Process
*******
The main steps to add a secure partition are as follows:

- `Add source folder`_
- `Add manifest`_
- `Update the Build System`_
- `Implement the RoT services`_

Add source folder
=================
Add a source folder under ``<TF-M base folder>/secure_fw/partitions`` for the
new secure partition (Let's take ``example`` as the folder name):

This folder should include those parts:

- Manifest file
- CMake configuration files
- Source code files

Add manifest
============
Each Secure Partition must have resource requirements declared in a manifest
file. The Secure Partition Manager (SPM) uses the manifest file to assemble and
allocate resources within the SPE. The manifest includes the following:

- A Secure Partition name.
- A list of implemented RoT Services.
- Access to other RoT Services.
- Memory requirements.
- Scheduling hints.
- Peripheral memory-mapped I/O regions and interrupts.

.. Note::
   The current manifest format in TF-M is "yaml" which is different from the
   requirement of PSA FF.

.. Note::
   The users can set LOW, NORMAL or HIGH in ``priority`` attribute in a Secure
   Partition manifest.

   The manifest tool ``tools/tfm_parse_manifest_list.py`` calculates the load
   priority of Secure Partitions based on their ``priority`` values and their
   dependencies.
   SPM determines the loading and initialization order of Secure Partitions
   based on their load priority values during TF-M initialization.

   - A Secure Partition with a higher ``priority`` is loaded and initialized
     before Secure Partitions with lower ``priority``.
   - A Secure Partition is loaded and initialized after its dependencies are.

Here is a manifest reference example for the IPC model:

.. Note::
    To use SFN model, the user needs to replace ``"model": "IPC"`` to
    ``"model": "SFN"``. The user also needs to remove the attribute
    ``"entry_point"``, and optionally replace it with ``"entry_init"``.

.. code-block:: yaml

  {
    "psa_framework_version": 1.1,
    "name": "TFM_SP_EXAMPLE",
    "type": "APPLICATION-ROT",
    "priority": "NORMAL",
    "model": "IPC",
    "entry_point": "tfm_example_main",
    "stack_size": "0x0200",
    "services" : [
      {
        "name": "ROT_A",
        "sid": "0x000000E0",
        "non_secure_clients": true,
        "connection_based": true,
        "version": 1,
        "version_policy": "STRICT"
        "mm_iovec": "disable"
      }
    ],
    "mmio_regions": [
      {
        "name": "TFM_PERIPHERAL_A",
        "permission": "READ-WRITE"
      }
    ],
    "irqs": [
      {
        "source": "TFM_A_IRQ",
        "name": "A_IRQ",
        "handling": "SLIH"
      }
    ]
    "dependencies": [
      "TFM_CRYPTO",
      "TFM_INTERNAL_TRUSTED_STORAGE_SERVICE"
    ]
  }

Update manifest list
--------------------
The ``<TF-M base folder>/tools/tfm_manifest_list.yaml`` is used to collect
necessary information of secure partition.
The manifest tool ``tools/tfm_parse_manifest_list.py`` processes it and
generates necessary files while building.

Please refer to the :ref:`tfm_manifest_list` for the format of manifest lists.

Reference configuration example:

.. code-block:: yaml

    {
      "description": "TFM Example Partition",
      "manifest": "secure_fw/partitions/example/tfm_example_partition.yaml",
      "conditional": "@TFM_PARTITION_EXAMPLE@",
      "output_path": "partitions/example",
      "version_major": 0,
      "version_minor": 1,
      "pid": 290,
      "linker_pattern": {
        "library_list": [
          "*tfm_*partition_example*"
         ]
      }
    }

TF-M also supports out-of-tree Secure Partition build where you can have your
own manifest lists.
Please refer to `Out-of-tree Secure Partition build`_ for details.

Secure Partition ID Distribution
--------------------------------
Every Secure Partition has an identifier (ID). TF-M will generate a header file
that includes definitions of the Secure Partition IDs. The header file is
``<TF-M build folder>generated/interface/include/psa_manifest/pid.h``. Each
definition uses the ``name`` attribute in the manifest as its name and the
value is allocated by SPM.

The Partition ID can be set to a fixed value or omitted to be auto allocated.

.. code-block:: c

   #define name id-value

.. table:: PID table
   :widths: auto

   ==================================== ======================
   **Secure Partitions**                **PID Range**
   ==================================== ======================
   TF-M Internal Partitions             0 - 255
   PSA and user Partitions              256 - 2999
   TF-M test Partitions                 3000 - 4999
   Firmware Framework test Partitions   5000 - 5999
   Reserved                             6000 -
   ==================================== ======================

Please refer to ``<TF-M base folder>/tools/tfm_manifest_list.yaml``,
''<TF-M extras repo>/partitions/\*/\*_manifest_list.yaml'',
``<TF-M test repo>/tests_reg/test/secure_fw/tfm_test_manifest_list.yaml`` and
``<TF-M test repo>/tests_psa_arch/spe/tfm_psa_ff_test_manifest_list.yaml`` for the detailed
PID allocations.

About where to add the definition, please refer to the chapter `Update manifest list`_.

RoT Service ID (SID) Distribution
---------------------------------
An RoT Service is identified by its RoT Service ID (SID). A SID is a 32-bit
number that is associated with a symbolic name in the Secure Partition
manifest. The bits [31:12] uniquely identify the vendor of the RoT Service.
The remaining bits [11:0] can be used at the discretion of the vendor.

Here is the RoT Service ID table used in TF-M.

.. table:: SID table
   :widths: auto

   =========================== ====================== ========================
   **Partitions**              **Vendor ID(20 bits)** **Function ID(12 bits)**
   =========================== ====================== ========================
   initial_attestation         0x00000                0x020-0x03F
   platform                    0x00000                0x040-0x05F
   protected_storage           0x00000                0x060-0x06F
   internal_trusted_storage    0x00000                0x070-0x07F
   crypto                      0x00000                0x080-0x09F
   firmware_update             0x00000                0x0A0-0x0BF
   tfm_secure_client           0x0000F                0x000-0x01F
   tfm_ipc_client              0x0000F                0x060-0x07F
   tfm_ipc_service             0x0000F                0x080-0x09F
   tfm_slih_test_service       0x0000F                0x0A0-0x0AF
   tfm_flih_test_service       0x0000F                0x0B0-0x0BF
   tfm_ps_test_service         0x0000F                0x0C0-0x0DF
   tfm_secure_client_2         0x0000F                0x0E0-0x0FF
   tfm_sfn_test_service_1      0x0000F                0x100-0x11F
   tfm_sfn_test_service_2      0x0000F                0x120-0x13F
   tfm_attest_test_service     0x0000F                0x140-0x15F
   =========================== ====================== ========================

RoT Service Stateless Handle Distribution
-----------------------------------------
A Secure partition may include stateless services. They are distinguished and
referenced by stateless handles. In manifest, a ``stateless_handle`` attribute
is set for indexing stateless services. It must be either ``"auto"`` or a
number in the range [1, 32] in current implementation and may extend. Also the
``connection-based`` attribute must be set to ``false`` for stateless services.

The indexes of stateless handles are divided into two ranges for different
usages.
Indexes [1, 16] are assigned to TF-M Secure Partitions.
The rest indexes [17, 32] are reserved for any other Secure Partitions, for
example Secure Partitions in ``tf-m-tests`` and ``tf-m-extras``.

The following table summaries the stateless handle allocation for the TF-M
Secure Partitions.

.. table:: Stateless Handle table
   :widths: auto

   =============================== =======================
    **Partition name**              **Stateless Handle**
   =============================== =======================
   TFM_SP_CRYPTO                   1
   TFM_SP_PS                       2
   TFM_SP_ITS                      3
   TFM_SP_INITIAL_ATTESTATION      4
   TFM_SP_FWU                      5
   TFM_SP_PLATFORM                 6
   =============================== =======================

For the indexes of other Secure Partitions, please refer to their manifests or
documentations.

stack_size
----------
The ``stack_size`` is required to indicate the stack memory usage of the Secure
Partition.
The value of this attribute must be a decimal or hexadecimal value in bytes.
It can also be a build configurable with default value defined in
``config_base.cmake``.
The value of the configuration can be overridden to fit different use cases.

heap_size
---------
This attribute is optional. The default value is 0.
It indicates the heap memory usage of the Secure Partition.
The allowed values are the same as the ``stack_size``.

mmio_regions
------------
This attribute is a list of MMIO region objects which the Secure Partition
needs access to. TF-M only supports the ``named_region`` current. Please refer
to PSA FF for more details about it. The user needs to provide a name macro to
indicate the variable of the memory region.

TF-M uses the below structure to indicate a peripheral memory.

.. code-block:: c

  struct platform_data_t {
    uint32_t periph_start;
    uint32_t periph_limit;
    int16_t periph_ppc_bank;
    int16_t periph_ppc_loc;
  };

.. Note::
   This structure is not expected by TF-M, it's only that the current
   implementations are using. Other peripherals that need different information
   to create isolation need to define a different structure with the same name.

Here is an example for it:

.. code-block:: c

   struct platform_data_t tfm_peripheral_A;
   #define TFM_PERIPHERAL_A                 (&tfm_peripheral_A)

mm_iovec
--------
Memory-mapped iovecs (MM-IOVEC) provides direct mapping of client input and output vectors into the
Secure Partition.
When this attribute is set to ``enable``, it enables Secure Partitions to use the MM-IOVEC APIs if
the framework supports MM-IOVEC.

Using MM-IOVEC provides a memory and runtime optimization for larger buffers, but reduces mitigation
for common security vulnerabilities.
Please refer to `Firmware Framework for M 1.1 Extensions`_ for more details.
Whether to use MM-IOVEC depends on the requirements of memory and runtime optimization and security.

Update the Build System
=======================
The following changes to the build system are required for the newly added secure partition.

Add a CMakeLists.txt file
-------------------------
Each Secure Partition must have a corresponding ``CMakeLists.txt``, in this case,
``<TF-M base folder>/secure_fw/partitions/example/CMakeLists.txt``, which is the compilation
configuration for this Secure Partition.

Here is a reference example for `CMakeLists.txt`_

.. _CMakeLists.txt: https://git.trustedfirmware.org/plugins/gitiles/TF-M/tf-m-extras/+/refs/heads/main/examples/example_partition/CMakeLists.txt

The CMake file should include the following contents

- Add library ``tfm_app_rot_partition_example`` and associated source files.

  .. code-block:: cmake

      add_library(tfm_app_rot_partition_example STATIC)

      target_sources(tfm_app_rot_partition_example
          PRIVATE
              tfm_example_partition.c
      )

  .. Note::
    The secure partition must be built as a standalone static library, and the
    name of the library must follow this pattern, as it affects how the linker
    script will lay the partition in memory:

    - ``tfm_psa_rot_partition*`` in case of a PSA RoT partition
    - ``tfm_app_rot_partition*`` in case of an Application RoT partition

- Add source files generated by the manifest tool.

  .. code-block:: cmake

    # The intermedia file defines the partition stack.
    target_sources(tfm_app_rot_partition_example
        PRIVATE
            ${CMAKE_BINARY_DIR}/generated/example_partition/auto_generated/intermedia_tfm_example_partition.c
    )

    # The load info file includes the static data of the partition.
    target_sources(tfm_partitions
        INTERFACE
            ${CMAKE_BINARY_DIR}/generated/example_partition/auto_generated/load_info_tfm_example_partition.c
    )

- Add dependency with manifest tool.

  To make sure the above generated files are up-to-date when the Secure Partition library is built,
  dependencies between the library and the manifest tool target should be set up.

  .. code-block:: cmake

    add_dependencies(tfm_app_rot_partition_example manifest_tool)

- Link ``tfm_sprt`` for the PSA API interfaces.

  .. code-block:: cmake

    target_link_libraries(tfm_app_rot_partition_example
        PRIVATE
            tfm_sprt
    )

- Link the Secure Partition library to ``tfm_partitions`` so that it can be included in the final
  image.

  .. code-block:: cmake

    target_link_libraries(tfm_partitions
        INTERFACE
            tfm_app_rot_partition_example
    )

Finally, the build of this Secure Partition should be added to
``<TF-M base folder>/secure_fw/partitions/CMakeLists.txt``.

  .. code-block:: cmake

    add_subdirectory(example)

Update the Config System
------------------------
If the Secure Partition has the build config to enable or disable it, the config option should be
added to config systems.

CMake Config
^^^^^^^^^^^^
The default value of the config option should be added to the
``<TF-M base folder>/config/config_base.cmake``.

  .. code-block:: cmake

    set(TFM_PARTITION_EXAMPLE  OFF  CACHE BOOL  "Enable the example partition")

Kconfig
^^^^^^^
A ``menuconfig`` should be added to ``<TF-M base folder>/secure_fw/partitions/example/Kconfig``.

  .. code-block:: kconfig

    menuconfig TFM_PARTITION_EXAMPLE
        bool "Enable the Example Partition"
        default n

And add it to ``<TF-M base folder>/secure_fw/partitions/Kconfig``

  .. code-block:: kconfig

    rsource ``example/Kconfig``

.. Note::

  The Secure Partition building should be skipped if it is not enabled.
  This should be done by adding the following code at the beginning of its ``CMakeLists.txt``

  .. code-block:: cmake

    if (NOT TFM_PARTITION_EXAMPLE)
        return()
    endif()

Implement the RoT services
==========================
To implement RoT services, the partition needs a source file which contains the
implementations of the services, as well as the partition entry point. The user
can create this source file under
``<TF-M base folder>/secure_fw/partitions/example/tfm_example_partition.c``.

As an example, the RoT service with SID **ROT_A** will be implemented.

Entry point for IPC Model Partitions
------------------------------------
This function must have a loop that repeatedly waits for input signals and
then processes them, following the Secure Partition initialization.

.. code-block:: c

    #include "psa_manifest/tfm_example.h"
    #include "psa/service.h"

    void tfm_example_main(void)
    {
        psa_signal_t signals = 0;

        /* Secure Partition initialization */
        example_init();

        /*
         * Continually wait for one or more of the partition's RoT Service or
         * interrupt signals to be asserted and then handle the asserted
         * signal(s).
         */
        while (1) {
            signals = psa_wait(PSA_WAIT_ANY, PSA_BLOCK);
            if (signals & ROT_A_SIGNAL) {
                rot_A();
            } else {
                /* Should not come here */
                psa_panic();
            }
        }
    }

Entry init for SFN Model Partitions
-----------------------------------
In the SFN model, the Secure Partition consists of one optional initialization
function, which is declared as the ``entry_init`` symbol as mentioned in
section `Add manifest`_. After initialization, the entry_init function
returns the following values:

    - Return ``PSA_SUCCESS`` if initialization succeeds.

    - Return ``PSA_SUCCESS`` if initialization is partially successful,
      and you want some SFNs to receive messages. RoT Services that are
      non-operational must respond to connection requests with
      ``PSA_ERROR_CONNECTION_REFUSED``.

    - Return an error status if the initialization failed, and no SFNs
      within the Secure Partition must be called.

Service implementation for IPC Model
------------------------------------
The service is implemented by the ``rot_A()`` function, which is called upon an
incoming signal. This implementation is up to the user, however an example
service has been included for reference. The following example sends a message
"Hello World" when called.

.. code-block:: c

    #include "psa_manifest/tfm_example.h"
    #include "psa/service.h"

    /* Some other type of services. */
    #define SOME_ROT_A_SERVICE_TYPE                (1)

    static void rot_A(void)
    {
        const int BUFFER_LEN = 32;
        psa_msg_t msg;
        int i;
        uint8_t rec_buf[BUFFER_LEN];
        uint8_t send_buf[BUFFER_LEN] = "Hello World";

        psa_get(ROT_A_SIGNAL, &msg);
        switch (msg.type) {
        case PSA_IPC_CONNECT:
        case PSA_IPC_DISCONNECT:
            /*
             * This service does not require any setup or teardown on connect
             * or disconnect, so just reply with success.
             */
            psa_reply(msg.handle, PSA_SUCCESS);
            break;
        default:
            /* Handling services requested by psa_call. */
            if (msg.type == PSA_IPC_CALL) {
                for (i = 0; i < PSA_MAX_IOVEC; i++) {
                    if (msg.in_size[i] != 0) {
                        psa_read(msg.handle, i, rec_buf, BUFFER_LEN);
                    }
                    if (msg.out_size[i] != 0) {
                        psa_write(msg.handle, i, send_buf, BUFFER_LEN);
                    }
                }
                psa_reply(msg.handle, PSA_SUCCESS);
            } else if (msg.type == SOME_ROT_A_SERVICE_TYPE) {
                /* Operations for SOME_ROT_A_SERVICE_TYPE */
            } else {
                /* Invalid type for this Secure Partition. */
                return PSA_ERROR_PROGRAMMER_ERROR;
            }
        }
    }

Service implementation for SFN Model
------------------------------------
SFN model consists of a set of Secure Functions (SFN), one for each RoT
Service. The connection, disconnection and request messages do not cause a
Secure Partition signal to be asserted for SFN Secure Partitions. Instead,
the Secure Function (SFN) for the RoT Service is invoked by the framework,
with the message details provided as a parameter to the SFN. To add a secure
function (SFN) to process messages for each RoT Service, each SFN will have
following prototype.

.. code-block:: c

  psa_status_t <<name>>_sfn(const psa_msg_t *msg);

A connection-based example service has been included for reference which
sends a message "Hello World" when called.

.. code-block:: c

    #include "psa_manifest/tfm_example.h"
    #include "psa/service.h"

    /* Some other type of services. */
    #define SOME_ROT_A_SERVICE_TYPE                (1)

    psa_status_t rot_a_sfn(const psa_msg_t *msg)
    {
        const int BUFFER_LEN = 32;
        int i;
        uint8_t rec_buf[BUFFER_LEN];
        uint8_t send_buf[BUFFER_LEN] = "Hello World";

        switch (msg->type) {
        case PSA_IPC_CONNECT:
        case PSA_IPC_DISCONNECT:
            /*
             * This service does not require any setup or teardown on connect
             * or disconnect, so just reply with success.
             */
            return PSA_SUCCESS;
        default:
            /* Handling services requested by psa_call. */
            if (msg->type == PSA_IPC_CALL) {
                for (i = 0; i < PSA_MAX_IOVEC; i++) {
                    if (msg->in_size[i] != 0) {
                        psa_read(msg->handle, i, rec_buf, BUFFER_LEN);
                    }
                    if (msg.->out_size[i] != 0) {
                        psa_write(msg->handle, i, send_buf, BUFFER_LEN);
                    }
                }
                return PSA_SUCCESS;
            } else if (msg->type == SOME_ROT_A_SERVICE_TYPE) {
                /* Operations for SOME_ROT_A_SERVICE_TYPE */
            } else {
                /* Invalid type for this Secure Partition. */
                return PSA_ERROR_PROGRAMMER_ERROR;
            }
        }
    }

Test suites and test partitions
-------------------------------

A regression test suite can be added to verify whether the new secure partition
works as expected. Refer to
`Adding TF-M Regression Test Suite <https://trustedfirmware-m.readthedocs.io/projects/tf-m-tests/en/latest/tfm_test_suites_addition.html#adding-a-new-test-suite>`_
for the details of adding a regression test suite.

Some regression tests require a dedicated RoT service. The implementations of
the RoT service for test are similar to secure partition addition. Refer to
`Adding partitions for regression tests <https://trustedfirmware-m.readthedocs.io/projects/tf-m-tests/en/latest/tfm_test_partitions_addition.html>`_
to get more information.

Out-of-tree Secure Partition build
----------------------------------

TF-M supports out-of-tree Secure Partition build, whose source code folders
are maintained outside TF-M repo. Developers can configure
``TFM_EXTRA_MANIFEST_LIST_FILES`` and ``TFM_EXTRA_PARTITION_PATHS`` in build
command line to include out-of-tree Secure Partitions.

- ``TFM_EXTRA_MANIFEST_LIST_FILES``

  A list of the absolute path(s) of the manifest list(s) provided by out-of-tree
  Secure Partition(s).
  Use semicolons ``;`` to separate multiple manifest lists. Wrap the multiple
  manifest lists with double quotes.

- ``TFM_EXTRA_PARTITION_PATHS``

  A list of the absolute directories of the out-of-tree Secure Partition source
  code folder(s). TF-M build system searches ``CMakeLists.txt`` of partitions in
  the source code folder(s).
  Use semicolons ``;`` to separate multiple out-of-tree Secure Partition
  directories. Wrap the multiple directories with double quotes.

A single out-of-tree Secure Partition folder can be organized as the figure
below.

::

  secure partition folder
        ├── CMakeLists.txt
        ├── manifest_list.yaml
        ├── out_of_tree_partition_manifest.yaml
        └── source code

In the example above, ``TFM_EXTRA_MANIFEST_LIST_FILES`` and
``TFM_EXTRA_PARTITION_PATHS`` in the build command can be configured as listed
below.

.. code-block:: bash

  -DTFM_EXTRA_MANIFEST_LIST_FILES=<Absolute-path-sp-folder/manifest_list.yaml>
  -DTFM_EXTRA_PARTITION_PATHS=<Absolute-path-sp-folder>

Multiple out-of-tree Secure Partitions can be organized in diverse structures.
For example, multiple Secure Partitions can be maintained under the same
directory as shown below.

::

  top-level folder
        ├── Partition 1
        │       ├── CMakeLists.txt
        │       ├── partition_1_manifest.yaml
        │       └── source code
        ├── Partition 2
        │       └── ...
        ├── Partition 3
        │       └── ...
        ├── manifest_list.yaml
        └── Root CMakeLists.txt

In the example above, a root CMakeLists.txt includes all the partitions'
CMakLists.txt, for example via ``add_subdirectory()``. The manifest_list.yaml
lists all partitions' manifest files.
``TFM_EXTRA_MANIFEST_LIST_FILES`` and ``TFM_EXTRA_PARTITION_PATHS`` in build
command line can be configured as listed below.

.. code-block:: bash

  -DTFM_EXTRA_MANIFEST_LIST_FILES=<Absolute-path-top-level-folder/manifest_list.yaml>
  -DTFM_EXTRA_PARTITION_PATHS=<Absolute-path-top-level-folder>

Alternatively, out-of-tree Secure Partitions can be separated in different
folders.

::

    partition 1 folder                    partition 2 folder
        ├── CMakeLists.txt                    ├── CMakeLists.txt
        ├── manifest_list.yaml                ├── manifest_list.yaml
        ├── partition_1_manifest.yaml         ├── partition_2_manifest.yaml
        └── source code                       └── source code

In the example above, each Secure Partition manages its own manifest files and
CMakeLists.txt. ``TFM_EXTRA_MANIFEST_LIST_FILES`` and
``TFM_EXTRA_PARTITION_PATHS`` in build command line can be configured as listed
below. Please note those input shall be wrapped with double quotes.

.. code-block:: bash

  -DTFM_EXTRA_MANIFEST_LIST_FILES="<Absolute-path-part-1-folder/manifest_list.yaml>;<Absolute-path-part-2-folder/manifest_list.yaml>"
  -DTFM_EXTRA_PARTITION_PATHS="<Absolute-path-part-1-folder>;<Absolute-path-part-2-folder>"

.. Note::

   Manifest list paths in ``TFM_EXTRA_MANIFEST_LIST_FILES`` do NOT have to be
   one-to-one mapping to Secure Partition directories in
   ``TFM_EXTRA_PARTITION_PATHS``. The orders don't matter either.

   ``TFM_EXTRA_MANIFEST_LIST_FILES`` and ``TFM_EXTRA_PARTITION_PATHS`` can be
   configured in multiple extra sources. It is recommended to use CMake list
   ``APPEND`` method to avoid unexpected override.

Further Notes
-------------

- In the IPC model, Use PSA FF proposed memory accessing mechanism. SPM
  provides APIs and checking between isolation boundaries, a free accessing
  of memory can cause program panic.
- In the IPC model, the memory checking inside partition runtime is
  unnecessary. SPM handles the checking while memory accessing APIs are
  called.
- In the IPC model, the client ID had been included in the message structure
  and secure partition can get it when calling psa_get() function. The secure
  partition does not need to call ``tfm_core_get_caller_client_id()`` to get
  the caller client ID anymore.
- In the IPC model, SPM will check the security policy and partition
  dependence between client and service. So the service does not need to
  validate the secure caller anymore.

*********
Reference
*********

| `PSA Firmware Framework specification`_
| `Firmware Framework for M 1.1 Extensions`_

.. _PSA Firmware Framework specification:
  https://www.arm.com/architecture/security-features/platform-security

.. _Firmware Framework for M 1.1 Extensions: https://developer.arm.com/
  documentation/aes0039/latest

--------------

*SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributor*
