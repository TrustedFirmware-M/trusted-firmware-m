TF-M Crypto Service design
==========================

:Author: Antonio de Angelis
:Organization: Arm Limited
:Contact: Antonio de Angelis <antonio.deangelis@arm.com>

.. contents:: Table of Contents

Abstract
--------

This document describes the design of the TF-M Cryptographic Secure Service
(in short, TF-M Crypto service).

Introduction
------------

The TF-M Crypto service provides an implementation of the PSA Certified Crypto
APIs in a PSA RoT secure partition in TF-M. It is based on the Mbed TLS
project, which provides a reference implementation of the PSA Crypto APIs as a
`C` software library. For more details on the PSA Crypto APIs refer to [1]_,
while for the Mbed TLS reference software refer to [2]_ and [3]_

The service can be requested by other services running in the SPE, or by
applications running in the NSPE, and its aim is to provide cryptographic
primitives in a secure and efficient way, either via software or by routing the
calls to any underlying crypto hardware accelerator or secure element that the
platform might provide.

Components
----------

The TF-M Crypto service is implemented by a number of different firmware
components residing in the Crypto partition, which are listed below:

.. table:: Components table
   :widths: auto

   +-----------------------------+---------------------------------------------------------------+----------------------------------------------------------------------+
   | **Component name**          | **Description**                                               | **Location**                                                         |
   +=============================+===============================================================+======================================================================+
   | Client API interface        | This module exports the PSA Crypto API to be callable from the| ``interface/src/tfm_crypto_api.c``                                   |
   |                             | users, which are called also `clients`. They could be either  |                                                                      |
   |                             | other secure partitions or Non Secure world based callers.    |                                                                      |
   +-----------------------------+---------------------------------------------------------------+----------------------------------------------------------------------+
   | Mbed TLS ``libmbedcrypto.a``| The Mbed TLS ``libmbedcrypto.a`` library is used in the       | Needed as dependency specified by the ``MBEDCRYPTO_PATH`` CMake      |
   |                             | service as a cryptographic `backend` library which provides   | configuration option                                                 |
   |                             | the APIs to implement a PSA Crypto `core`, SW based crypto    |                                                                      |
   |                             | primitives and wrappers for HW crypto accelerators and Secure |                                                                      |
   |                             | Elements. It exposes those through the PSA Crypto APIs        |                                                                      |
   +-----------------------------+---------------------------------------------------------------+----------------------------------------------------------------------+
   | Init module                 | This module handles the initialisation of the service objects | ``secure_fw/partitions/crypto/crypto_init.c``                        |
   |                             | during TF-M boot and provides the infrastructure to service   |                                                                      |
   |                             | requests when TF-M is built for IPC or SFN model.             |                                                                      |
   |                             | The dispatching mechanism of IPC requests is based on a look  |                                                                      |
   |                             | up table of function pointers.                                |                                                                      |
   |                             | This design allows for better scalability and support of a    |                                                                      |
   |                             | higher number of Secure functions with minimal overhead and   |                                                                      |
   |                             | duplication of code.                                          |                                                                      |
   |                             | This module is in charge of providing an ID of the caller of  |                                                                      |
   |                             | each API in the backend, allowing to enforce key ownership    |                                                                      |
   |                             | policies.                                                     |                                                                      |
   +-----------------------------+---------------------------------------------------------------+----------------------------------------------------------------------+
   | Alloc module                | This module handles the allocation of contexts for multipart  | ``secure_fw/partitions/crypto/crypto_alloc.c``                       |
   |                             | operations in the Secure world. This is required because the  |                                                                      |
   |                             | caller view of contexts, i.e. `clients`, does not contain any |                                                                      |
   |                             | sensible information but just a number handle which is then   |                                                                      |
   |                             | used by the service itself to match the context to the actual |                                                                      |
   |                             | context information which will be stored securely in the TF-M |                                                                      |
   |                             | crypto partition private memory. This is enabled by setting   |                                                                      |
   |                             | ``MBEDTLS_PSA_CRYPTO_CLIENT`` option on the caller side. Note |                                                                      |
   |                             | that setting this option on the client side is a hard         |                                                                      |
   |                             | requirement in order for the clients to work correctly        |                                                                      |
   +-----------------------------+---------------------------------------------------------------+----------------------------------------------------------------------+
   | Service modules             | These modules (AEAD, Asymmetric, Cipher, Hash, Key Derivation,| ``secure_fw/partitions/crypto/crypto_aead.c``                        |
   |                             | Key Management, MAC, Random Number Generation) represent a    | ``secure_fw/partitions/crypto/crypto_asymmetric.c``                  |
   |                             | thin layer which is in charge of servicing the calls from the | ``secure_fw/partitions/crypto/crypto_cipher.c``                      |
   |                             | clients. They provide parameter sanitization and context      | ``secure_fw/partitions/crypto/crypto_hash.c``                        |
   |                             | retrieval for multipart operations, and dispatching to the    | ``secure_fw/partitions/crypto/crypto_key_derivation.c``              |
   |                             | corresponding backend library function exposed by the         | ``secure_fw/partitions/crypto/crypto_key_management.c``              |
   |                             | underlying library.                                           | ``secure_fw/partitions/crypto/crypto_mac.c``                         |
   |                             |                                                               | ``secure_fw/partitions/crypto/crypto_rng.c``                         |
   +-----------------------------+---------------------------------------------------------------+----------------------------------------------------------------------+
   | Backend library abstraction | This module contains several APIs to abstract the interface   | ``secure_fw/partitions/crypto/crypto_library.*``                     |
   |                             | towards the backend library, which must provide the PSA Crypto|                                                                      |
   |                             | core layer, key management, SW based crypto and possibly      |                                                                      |
   |                             | interfaces for HW crypto accelerators and Secure Elements     |                                                                      |
   +-----------------------------+---------------------------------------------------------------+----------------------------------------------------------------------+
   | Manifest                    | The manifest file is a description of the service components. | ``secure_fw/partitions/crypto/tfm_crypto.yaml``                      |
   +-----------------------------+---------------------------------------------------------------+----------------------------------------------------------------------+
   | CMake, Kconfig and headers  | The CMake files are used by the TF-M CMake build system to    | ``secure_fw/partitions/crypto/CMakeLists.txt``                       |
   |                             | build the service as part of the Secure FW build. The service | ``secure_fw/partitions/crypto/Kconfig``                              |
   |                             | is built as a static library                                  | ``secure_fw/partitions/crypto/Kconfig.comp``                         |
   |                             | (``libtfm_psa_rot_partition_crypto.a``).                      | ``secure_fw/partitions/crypto/config_crypto_check.h``                |
   |                             | The service itself depends on the build of the underlying     | ``secure_fw/partitions/crypto/config_engine_buf.h``                  |
   |                             | backend library, by default the ``libmbedcrypto.a`` target, a | ``secure_fw/partitions/crypto/tfm_crypto_api.h``                     |
   |                             | static library built by the Mbed TLS build system.            | ``secure_fw/partitions/crypto/crypto_spe.h``                         |
   |                             | The ``tfm_crypto_api.h`` header contains public service APIs, | ``interface/include/tfm_crypto_defs.h``                              |
   |                             | which expose each module's interface. The header available in |                                                                      |
   |                             | the interface, ``tfm_crypto_defs.h``, contains types and      |                                                                      |
   |                             | definitions to build the client interface of the service, i.e.|                                                                      |
   |                             | towards other services or NS world.                           |                                                                      |
   |                             | Finally, the ``crypto_spe.h`` header is used during the       |                                                                      |
   |                             | build of the Mbed TLS library, when the configuration option  |                                                                      |
   |                             | ``MBEDTLS_PSA_CRYPTO_SPM`` is defined, to add a custom prefix |                                                                      |
   |                             | to the PSA API symbols so that duplication of symbol names is |                                                                      |
   |                             | avoided. The prefix used for the symbols of the library is    |                                                                      |
   |                             | chosen to be ``mbedcrypto__``.                                |                                                                      |
   +-----------------------------+---------------------------------------------------------------+----------------------------------------------------------------------+
   | TF-M Crypto key abstraction | The TF-M Crypto service has its own type definition to be able| ``secure_fw/partitions/crypto/tfm_crypto_key.h``                     |
   |                             | to identify a key ID with its own owner. The definition of an |                                                                      |
   |                             | owner is provided by the TF-M Firmware Framework and is out of|                                                                      |
   |                             | the scope of the service itself and the PSA Crypto APIs spec. |                                                                      |
   |                             | The underlying library in practice must provide the same      |                                                                      |
   |                             | functionality, i.e handle key IDs with associated owner info. |                                                                      |
   |                             | For Mbed TLS, this is accomplished by the type                |                                                                      |
   |                             | ``mbedtls_svc_key_id_t`` when the config option of Mbed TLS   |                                                                      |
   |                             | ``MBEDTLS_PSA_CRYPTO_KEY_ID_ENCODES_OWNER`` is defined. Note  |                                                                      |
   |                             | that setting this option in Mbed TLS is a hard requirement for|                                                                      |
   |                             | when the library is built on the service side, while it shall |                                                                      |
   |                             | never be set when the headers are included for client side    |                                                                      |
   |                             | components (i.e. other partitions or NS interface).           |                                                                      |
   +-----------------------------+---------------------------------------------------------------+----------------------------------------------------------------------+
   | Documentation               | The                                                           | ``docs/integration_guide/services/tfm_crypto_integration_guide.rst`` |
   |                             | :ref:`integration guide <tfm-crypto-integration-guide-label>` |                                                                      |
   |                             | contains the description of the TF-M Crypto service modules   |                                                                      |
   |                             | and interfaces.                                               |                                                                      |
   +-----------------------------+---------------------------------------------------------------+----------------------------------------------------------------------+

The interaction between the different components is described by the
block diagram in :numref:`block_diagram-label`

.. _block_diagram-label:
.. figure:: /design_docs/media/psa_rot_crypto_service_architecture.png

   Block diagram of the firmware architecture of the TF-M Crypto service. Dotted
   lines between services represent isolation boundaries once runtime firmware
   is initialized, i.e. TF-M init phase has completed. The diagram is simplified
   and shows only the major functional blocks, for a more detailed
   ``libmbedcrypto.a`` architecture please refer to [3]_.

Relationship between Mbed TLS and the TF-M Crypto service
---------------------------------------------------------

TF-M Crypto as a particular configuration of Mbed TLS
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Up until `TF-Mv2.0`, the TF-M Crypto service used to provide its own separate
implementation of the PSA Certified Crypto APIs, i.e. it provided its own
version of the implementation defined aspects of the specifications. Starting
from `TF-Mv2.1`, the TF-M Crypto service fully aligns to the implementation
defined by the Mbed TLS project, i.e. its implementation defined aspects are
the same as the ones defined by Mbed TLS.

As a consequence, starting from `TF-Mv2.1` the PSA Crypto headers available
in TF-M are a copy of those distributed by the Mbed TLS project. TF-M just
uses them and won't accept any contribution to them, as those need to be
discussed in the scope of the Mbed TLS project.

TF-M then represents just a configuration of the Mbed TLS reference
implementation where the TF-M Crypto APIs are provided as a remote call across
a transport channel, which might be represented by a TrustZone boundary (in
Armv8.x-M systems), by a mailbox channel in heterogeneous systems, e.g. Cortex-A
+ Cortex-M systems, by an SPM mediated interface, e.g. partition to partition
calls or, in general, through a mechanism which provides process separation
between the client and the service sides of the API.
In this context, the client must always define the Mbed TLS config option
``MBEDTLS_PSA_CRYPTO_CLIENT``, while the service must always have
``MBEDTLS_PSA_CRYPTO_SPM``, mainly to avoid symbol clashing at link time between
the library interface and the ``tfm_crypto_api.c`` interface. When there is a
component on the service side which is able to identify the client through an
ID, it is recommended to also define ``MBEDTLS_PSA_CRYPTO_KEY_ID_ENCODES_OWNER``
option in order to provide separation in the key space.

Usage of Mbed TLS configuration headers
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Mbed TLS uses two different configuration headers, specified through the setting
of the ``MBEDTLS_CONFIG_FILE``, i.e. Mbed TLS config, and the setting of
``MBEDTLS_PSA_CRYPTO_CONFIG_FILE``, i.e. the PSA configuration. In order to be
able to perform header inclusion for ``psa/crypto.h``, the configuration files
must be visible to the compilation unit through the include hierarchy. If none of
the macros are defined, the fall back strategy is to include the default config
files available in the Mbed TLS repo, i.e. ``include/mbedtls/mbedtls_config.h``
and ``include/psa/crypto_config.h``, which contain a set of default values for
the macros.

Usage of the default header config when using the TF-M Crypto service is highly
discouraged, mainly because both on the client side and on the service side a
set of options must always be defined (or undefined), as described in the
previous section. TF-M provides example _profiles_ which show the options and
how they should be used on both client and service side of the integration. Note
that to avoid falling back to the default PSA configuration, the Mbed TLS config
file must always define the symbol ``MBEDTLS_PSA_CRYPTO_CONFIG``. The symbol to
enable the Mbed TLS config ``MBEDTLS_CONFIG_FILE`` instead must be available to
the unit being compiled which is including ``psa/crypto.h``, i.e. passed by the
build system config stage.

Hardware acceleration
~~~~~~~~~~~~~~~~~~~~~

The TF-M Crypto partition must handle all HW related crypto tasks, if the
platform is capable of offering hardware acceleration or if a complete Secure
Element is present. The main difference between the two is that a hardware
accelerator does not store keys but just accelerates operations, while a Secure
Element is capable of storing keys and the PSA Crypto core running on the host
must interface with it to store, retrieve or use them for crypto tasks, etc.

There are currently two methods to interface an accelerator into the Crypto
service, and both rely on the Crypto partition fully owning the Crypto hardware,
i.e. the memory mapped IO space must be bound the Crypto partition only. Both
methods are implemented through the capability of the _backend_ library to
either:

1. Provide a link time mechanism to replace pure SW implementations for algorithms
   with HW assisted implementations. In this case, the TF-M platform provides some
   additional HW abstraction through the usage of ``crypto_hw_accelerator_*()``
   APIs. This is dubbed the `_ALT` approach and will be soon to be deprecated
   potentially starting from the release of Mbed TLS 4.0
2. Provide a cleanly defined interface specification [4]_ to describe the APIs that
   a driver must expose to the PSA Crypto core in order for the core to be able to
   offload operations to hardware. This is the preferred method for interfacing with
   HW.

Both solutions are currently handled at build time (either compilation or linking)
by Mbed TLS. For details on how to integrate a driver please refer directly to the
documentation referenced above and to the Mbed TLS repo.

Builtin keys
~~~~~~~~~~~~

A particular driver using the interface described in [4]_ is the TF-M Builtin
Key Loader driver [5]_. The goal of the driver is to make Mbed TLS aware of
*transparent builtin keys*, i.e. keys which can be read from the core (i.e. not
fully opaque keys), but that are normally bound to the platform and provisioned
in it, for which it would be more appropriate to treat them as standard
*transparent keys*. The concept of *transparent builtin keys* is not defined
in the spec so it is specifically a non standard extension added by TF-M to the
Mbed TLS implementation, which might be changed between releases until a standard
solution is adopted. TF-M patches Mbed TLS on the fly to enable such behaviour
using patches available in ``lib/ext/mbedcrypto``. Implementations might disable
the ``tfm_builtin_key_loader`` and then must provide their own alternative storage
location for all of the TF-M required builtin keys, e.g. by having them stored in
a Secure Element with a corresponding opaque driver.

Service API description
-----------------------

The ``Alloc`` and ``Init`` modules implement public APIs which are specific to
the TF-M Crypto service, and are available only internally to other components
of the TF-M Crypto partition. For a detailed description of the prototypes
please refer to the ``tfm_crypto_api.h`` header.

.. table:: Init and Alloc modules APIs
   :widths: auto

   +--------------------------------+--------------+-----------------+------------------------------------------------------+
   | **Function**                   | **Module**   | **Caller**      | **Scope**                                            |
   +================================+==============+=================+======================================================+
   | tfm_crypto_init()              | Init         | SPM             | Called during TF-M boot for initialisation. It       |
   |                                |              |                 | does modules initialisation (it initializes the Alloc|
   |                                |              |                 | module) and initializes the `backend` library. Being |
   |                                |              |                 | the partition enabled for the SFN model, it does not |
   |                                |              |                 | implement any IPC specific message handler, instead  |
   |                                |              |                 | it relies on the SPM being able to schedule SFN      |
   |                                |              |                 | partitions using the SFN dispatcher with little      |
   |                                |              |                 | overhead                                             |
   +--------------------------------+--------------+-----------------+------------------------------------------------------+
   | tfm_crypto_sfn()               | Init         | SPM             | Function to handle an SFN request or to interface    |
   |                                |              |                 | with the message handler when running in IPC model   |
   +--------------------------------+--------------+-----------------+------------------------------------------------------+
   | tfm_crypto_init_alloc()        | Alloc        | Init            | Called by ``tfm_crypto_init()``, it initialises the  |
   |                                |              |                 | internal memory storage in the TF-M Crypto partition |
   |                                |              |                 | that the service uses to store multipart operation   |
   |                                |              |                 | contexts as requested by clients.                    |
   +--------------------------------+--------------+-----------------+------------------------------------------------------+
   | tfm_crypto_operation_alloc()   | Alloc        | Service modules | It allocates a new operation context for a multipart |
   |                                |              |                 | operation. It returns an handle to the allocated     |
   |                                |              |                 | context in secure memory.                            |
   +--------------------------------+--------------+-----------------+------------------------------------------------------+
   | tfm_crypto_operation_lookup()  | Alloc        | Service modules | It retrieves a previously allocated operation context|
   |                                |              |                 | of a multipart operation, based on the handle given  |
   |                                |              |                 | as input.                                            |
   +--------------------------------+--------------+-----------------+------------------------------------------------------+
   | tfm_crypto_operation_release() | Alloc        | Service modules | It releases a previously allocated operation context |
   |                                |              |                 | of a multipart operation, based on the handle given  |
   |                                |              |                 | as input.                                            |
   +--------------------------------+--------------+-----------------+------------------------------------------------------+
   | tfm_crypto_*_interface()       | ``*``        | Init            | Interface functions called by the dispatcher to      |
   |                                |              |                 | service PSA Crypto APIs requests                     |
   +--------------------------------+--------------+-----------------+------------------------------------------------------+

Configuration parameters
------------------------

The TF-M Crypto service exposes some configuration parameters to tailor
the service configuration in terms of supported functionalities and
hence FLASH/RAM size to meet the requirements of different platforms and
use cases. These parameters can be provided via CMake parameters during
the CMake configuration step and as a configuration header to allow the
configuration of the Mbed TLS library. When using Kconfig they are also
exported in the Kconfig menus.

.. table:: Configuration parameters table
   :widths: auto

   +------------------------------------+---------------------------+----------------------------------------------------------------+--------------------------------------------------------------------------+
   | **Parameter**                      | **Type**                  | **Description**                                                | **Default**                                                              |
   +====================================+===========================+================================================================+==========================================================================+
   | `CRYPTO_ENGINE_BUF_SIZE`           | CMake build               | Buffer used by Mbed TLS for its own allocations at runtime.    | 8096 (bytes)                                                             |
   |                                    | configuration parameter   | This is a buffer allocated in static memory.                   |                                                                          |
   +------------------------------------+---------------------------+----------------------------------------------------------------+--------------------------------------------------------------------------+
   | `CRYPTO_CONC_OPER_NUM`             | CMake build               | This parameter defines the maximum number of possible          | 8                                                                        |
   |                                    | configuration parameter   | concurrent operation contexts (cipher, MAC, hash and key deriv)|                                                                          |
   |                                    |                           | for multi-part operations, that can be allocated simultaneously|                                                                          |
   |                                    |                           | at any time.                                                   |                                                                          |
   +------------------------------------+---------------------------+----------------------------------------------------------------+--------------------------------------------------------------------------+
   | `CRYPTO_IOVEC_BUFFER_SIZE`         | CMake build               | This parameter applies only to IPC model builds. In IPC model, | 5120 (bytes)                                                             |
   |                                    | configuration parameter   | during a Service call, input and outputs are allocated         |                                                                          |
   |                                    |                           | temporarily in an internal scratch buffer whose size is        |                                                                          |
   |                                    |                           | determined by this parameter.                                  |                                                                          |
   +------------------------------------+---------------------------+----------------------------------------------------------------+--------------------------------------------------------------------------+
   | `CRYPTO_STACK_SIZE`                | CMake build               | Defines the stack size assigned to the crypto partition in     | 6912 (bytes)                                                             |
   |                                    | configuration parameter   | higher level of isolation configurations (L1 isolation has a   |                                                                          |
   |                                    |                           | common stack shared by all partitions)                         |                                                                          |
   +------------------------------------+---------------------------+----------------------------------------------------------------+--------------------------------------------------------------------------+
   | `CRYPTO_NV_SEED`                   | CMake build               | Uses the Mbed TLS Crypto NV seed feature to provide entropy in | Defined for platforms which don't have ``CRYPTO_HW_ACCELERATOR``         |
   |                                    | configuration parameter   | case there is no HW acceleration providing HW entropy          |                                                                          |
   +------------------------------------+---------------------------+----------------------------------------------------------------+--------------------------------------------------------------------------+
   | `CRYPTO_IOVEC_BUFFER_SIZE`         | CMake build               | Defines the size of scratch buffers to handle input/outputs if | 5120 (bytes)                                                             |
   |                                    | configuration parameter   | the Memory Mapped IOVEC feature is not enabled                 |                                                                          |
   +------------------------------------+---------------------------+----------------------------------------------------------------+--------------------------------------------------------------------------+
   | `CRYPTO_SINGLE_PART_FUNCS_DISABLED`| CMake build               | When enabled, only the multipart, i.e. non-integrated APIs will| Not defined (Profile default)                                            |
   |                                    | configuration parameter   | be available in the service                                    |                                                                          |
   +------------------------------------+---------------------------+----------------------------------------------------------------+--------------------------------------------------------------------------+
   | `CRYPTO_*_MODULE_ENABLED`          | CMake build               | When enabled, the corresponding shim layer module and relative | Defined (Profile default)                                                |
   |                                    | configuration parameters  | APIs are available in the service                              |                                                                          |
   +------------------------------------+---------------------------+----------------------------------------------------------------+--------------------------------------------------------------------------+
   | `MBEDTLS_CONFIG_FILE`              | Configuration header      | The Mbed TLS library can be configured to support different    | ``lib/ext/mbedcrypto/mbedcrypto_config/tfm_mbedcrypto_config_default.h`` |
   |                                    |                           | algorithms through the usage of a configuration header file    | (Profile default)                                                        |
   |                                    |                           | at build time. This allows for tailoring FLASH/RAM requirements|                                                                          |
   |                                    |                           | for different platforms and use cases.                         |                                                                          |
   +------------------------------------+---------------------------+----------------------------------------------------------------+--------------------------------------------------------------------------+
   | `MBEDTLS_PSA_CRYPTO_CONFIG_FILE`   | Configuration header      | This header file specifies which cryptographic mechanisms are  |  ``lib/ext/mbedcrypto/mbedcrypto_config/crypto_config_default.h``        |
   |                                    |                           | available through the PSA API when `MBEDTLS_PSA_CRYPTO_CONFIG` |  (Profile default)                                                       |
   |                                    |                           | is enabled, and is not used when `MBEDTLS_PSA_CRYPTO_CONFIG` is|                                                                          |
   |                                    |                           | disabled. Configuring TF-M always involves having the define   |                                                                          |
   |                                    |                           | enabled.                                                       |                                                                          |
   +------------------------------------+---------------------------+----------------------------------------------------------------+--------------------------------------------------------------------------+

References
----------

.. [1] PSA Certified Crypto API specifications: \ https://arm-software.github.io/psa-api/crypto/
.. [2] Using PSA - Getting started in Mbed TLS: \ https://mbed-tls.readthedocs.io/en/latest/getting_started/psa/
.. [3] ``Mbed TLS`` repository which holds the reference implementation as a `C` software library: \ https://github.com/Mbed-TLS
.. [4] PSA Unified Driver Interface for Cryptoprocessors: \ https://github.com/Mbed-TLS/TF-PSA-Crypto/blob/development/docs/proposed/psa-driver-interface.md
.. [5] TF-M Builtin Key Loader driver, normally described as :ref:`tfm_builtin_key_loader <tfm-builtin-keys-label>`

--------------

*Copyright (c) 2019-2024, Arm Limited. All rights reserved.*
