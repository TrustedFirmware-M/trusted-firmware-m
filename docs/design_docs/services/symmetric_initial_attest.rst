#################################################
Symmetric key algorithm based Initial Attestation
#################################################

:Author: David Hu
:Organization: Arm Limited
:Contact: david.hu@arm.com

************
Introduction
************

This document proposes a design of symmetric key algorithm based Initial
Attestation in TF-M.

Symmetric key algorithm based Initial Attestation
(*symmetric Initial Attestation* for short) signs and verifies Initial
Attestation Token (IAT) with a symmetric cryptography signature scheme, such as
HMAC.
It can reduce TF-M binary size and memory footprint on ultra-constrained devices
without integrating asymmetric ciphers.

This proposal follows PSA Attestation API document [1]_.

.. note ::

    As pointed out by PSA Attestation API [1]_, the use cases of Initial
    Attestation based on symmetric key algorithms can be limited due to
    the associated infrastructure costs for key management and operational
    complexities. It may also restrict the ability to interoperate with
    scenarios that involve third parties.

***************
Design overview
***************

The symmetric Initial Attestation follows the existing IAT generation sequence
for Initial Attestation based on asymmetric key algorithm
(*asymmetric Initial Attestation* for short).

As Profile Small design [2]_ requests, a configuration flag
``SYMMETRIC_INITIAL_ATTESTATION`` selects symmetric initial attestation during
build.

The top-level design is shown in :ref:`overall-diagram-figure` below.

.. _overall-diagram-figure:

.. figure:: /design_docs/media/symmetric_initial_attest/overall_diagram.png
    :align: center

    Overall design diagram

Symmetric Initial Attestation adds its own implementations of some steps in IAT
generation in Initial Attestation secure service. More details are covered in
`IAT generation in Initial Attestation secure service`_.

The interfaces and procedures of Initial Attestation secure service are not
affected. Refer to Initial Attestation Service Integration Guide [3]_ for
details of the implementation of Initial Attestation secure service.

Symmetric Initial Attestation invokes ``t_cose`` library to build up
``COSE_Mac0`` structure. ``COSE_Mac0`` support was originally added to the
``t_cose`` library fork in TF-M, however since ``t_cose 2.0`` it is part of
the upstream library [4]_ which is already used by TF-M too.

Several HAL APIs are defined to fetch platform specific assets required by
Symmetric Initial Attestation. For example, ``tfm_plat_get_symmetric_iak()``
fetches symmetric Initial Attestation Key (IAK). Those HAL APIs are summarized
in `HAL APIs`_.

Decoding and verification of symmetric Initial Attestation is also included in
this proposal for regression test.
The test suites and IAT decoding are discussed in `TF-M Test suite`_.

``QCBOR`` library and Crypto service are also invoked. But this proposal doesn't
require any modification to either ``QCBOR`` or Crypto service. Therefore,
descriptions of ``QCBOR`` and Crypto service are skipped in this document.

****************************************************
IAT generation in Initial Attestation secure service
****************************************************

The sequence of IAT generation of symmetric Initial Attestation is shown in
:ref:`ia-service-figure` below. Note that the ``Register symmetric IAK`` stage
is no longer required due to changes in the Crypto partition
(``attest_symmetric_key.c`` is now responsible only for calculating the instance
ID).

.. _ia-service-figure:

.. figure:: /design_docs/media/symmetric_initial_attest/ia_service_flow.png
    :align: center

    Symmetric IAT generation flow in Initial Attestation secure service

In Initial Attestation secure service, symmetric Initial Attestation implements
the following steps in ``attest_create_token()``, which are different from those
of asymmetric Initial Attestation.

    - ``attest_token_start()``,
    - Instance ID claims,
    - ``attest_token_finish()``.

If ``SYMMETRIC_INITIAL_ATTESTATION`` is selected, symmetric Initial Attestation
dedicated implementations of those steps are included in build.
Otherwise, asymmetric Initial Attestation dedicated implementations are included
instead. Symmetric Initial Attestation implementation resides a new file
``attest_symmetric_key.c`` to handle symmetric Instance ID related operations.
Symmetric Initial Attestation dedicated ``attest_token_start()`` and
``attest_token_finish()`` are added in ``attestation_token.c``.
The details are covered in following sections.

Symmetric Instance ID
=====================

Symmetric Initial Attestation dedicated ``attest_symmetric_key.c`` implements
the ``attest_get_instance_id()`` function. This function returns the Instance ID
value, calculating it if it has not already been calculated. Refer to
`Instance ID claim`_ for more details.

.. note ::

    Only symmetric IAK for HMAC algorithm is allowed so far.

Instance ID calculation
-----------------------

In symmetric Initial Attestation, Instance ID is also calculated the first time
it is requested. It can protect critical symmetric IAK from being frequently
fetched, which increases the risk of asset disclosure.

The Instance ID value is the output of hashing symmetric IAK raw data *twice*,
as requested in PSA Attestation API [1]_. HMAC-SHA256 may be hard-coded as the
hash algorithm of Instance ID calculation.

.. note ::

    According to RFC2104 [5]_, if a HMAC key is longer than the HMAC block size,
    the key will be first hashed. The hash output is used as the key in HMAC
    computation.

    In current design, HMAC is used to calculate the authentication tag of
    ``COSE_Mac0``. Assume that symmetric IAK is longer than HMAC block size
    (HMAC-SHA256 by default), the Instance ID is actually the HMAC key for
    ``COSE_Mac0`` authentication tag generation, if Instance ID value is the
    output of hashing IAK only *once*.
    Therefore, attackers may request an valid IAT from device and fake malicious
    ones by using Instance ID to calculate valid authentication tags, to cheat
    others.

    As a result, symmetric IAK raw data should be hashed *twice* to generate the
    Instance ID value.

The Instance ID calculation result is stored in a static buffer.
Token generation process can call ``attest_get_instance_id()`` to
fetch the data from that static buffer.

attest_token_start()
====================

Symmetric Initial Attestation dedicated ``attest_token_start()`` initializes the
``COSE_Mac0`` computation context and builds up the ``COSE_Mac0`` Header.

The workflow inside ``attest_token_start()`` is shown in
:ref:`attest-token-start-figure` below.

.. _attest-token-start-figure:

.. figure:: /design_docs/media/symmetric_initial_attest/attest_token_start.png
    :align: center

    Workflow in symmetric Initial Attestation ``attest_token_start()``

Descriptions of each step are listed below:

#. ``t_cose_mac0_sign_init()`` is invoked to initialize ``COSE_Mac0`` signing
   context in ``t_cose``.

#. The symmetric IAK handle is set into ``COSE_Mac0`` signing context via
   ``t_cose_mac0_set_signing_key()``.

#. Initialize ``QCBOR`` encoder.

#. The header parameters are encoded into ``COSE_Mac0`` structure in
   ``t_cose_mac0_encode_parameters()``.

#. ``QCBOREncode_OpenMap()`` prepares for encoding the ``COSE_Mac0`` payload,
   which is filled with IAT claims.

For detailed description and documentation of the ``COSE_Mac0`` functionalities
please refer to the ``t_cose`` repository [4]_.

Instance ID claim
=================

Symmetric Initial Attestation also implements Instance ID claims in
``attest_add_instance_id_claim()``. The Instance ID value is fetched via
``attest_get_instance_id()``. The value has already been calculated during
symmetric IAK registration. See `Instance ID calculation`_ for details.

The other steps are the same as those in asymmetric Initial Attestation
implementation. The UEID type byte is set to 0x01.

attest_token_finish()
=====================

Symmetric Initial Attestation dedicated ``attest_token_finish()`` calls
``t_cose_mac0_encode_tag()`` to calculate and encode the authentication tag of
``COSE_Mac0`` structure. The whole COSE and CBOR encoding are completed in
``attest_token_finish()``. The simplified flow in ``attest_token_finish()`` is
shown in :ref:`attest-token-finish-figure` below.

.. _attest-token-finish-figure:

.. figure:: /design_docs/media/symmetric_initial_attest/attest_token_finish.png
    :align: center

    Workflow in symmetric Initial Attestation ``attest_token_finish()``

***************
TF-M Test suite
***************

Symmetric Initial Attestation adds dedicated non-secure and secure test suites.
The test suites also follow asymmetric Initial Attestation test suites
implementation but optimize the memory footprint.
Symmetric Initial Attestation non-secure and secure test suites request Initial
Attestation secure service to generate IATs. After IATs are generated
successfully, test suites decode IATs and parse the claims.
Secure test suite also verifies the authentication tag in ``COSE_Mac0``
structure.

Symmetric Initial Attestation implements its dedicated
``attest_token_decode_validate_token()`` in ``attest_symmetric_iat_decoded.c``
to perform IAT decoding required by test suites.
If ``SYMMETRIC_INITIAL_ATTESTATION`` is selected,
``attest_symmetric_iat_decoded.c`` is included in build.
Otherwise, asymmetric Initial Attestation dedicated implementations are included
instead.

The workflow of symmetric Initial Attestation dedicated
``attest_token_decode_validate_token()`` is shown below.

.. _iat-decode-figure:

.. figure:: /design_docs/media/symmetric_initial_attest/iat_decode.png
    :align: center

    Workflow in symmetric Initial Attestation ``attest_token_decode_validate_token()``

If the decoding is required from secure test suite,
``attest_token_decode_validate_token()`` will fetch symmetric IAK to verify the
authentication tag in ``COSE_Mac0`` structure.
If the decoding is required from non-secure test suite,
``attest_token_decode_validate_token()`` will only decode ``COSE_Mac0`` by
setting ``T_COSE_OPT_DECODE_ONLY`` option flag. Non-secure must not access the
symmetric IAK.

********
HAL APIs
********

HAL APIs are summarized below.

Fetch device symmetric IAK
==========================

``tfm_plat_get_symmetric_iak()`` fetches device symmetric IAK.

  .. code-block:: c

    enum tfm_plat_err_t tfm_plat_get_symmetric_iak(uint8_t *key_buf,
                                                   size_t buf_len,
                                                   size_t *key_len,
                                                   psa_algorithm_t *key_alg);

  **Parameters:**

  +-------------+-----------------------------------------------------------+
  | ``key_buf`` | Buffer to store the symmetric IAK.                        |
  +-------------+-----------------------------------------------------------+
  | ``buf_len`` | The length of ``key_buf``.                                |
  +-------------+-----------------------------------------------------------+
  | ``key_len`` | The length of the symmetric IAK.                          |
  +-------------+-----------------------------------------------------------+
  | ``key_alg`` | The key algorithm. Only HMAC SHA-256 is supported so far. |
  +-------------+-----------------------------------------------------------+

It returns error code specified in ``enum tfm_plat_err_t``.

Get symmetric IAK key identifier
================================

``attest_plat_get_symmetric_iak_id()`` gets the key identifier of the symmetric
IAK as the ``kid`` parameter in COSE Header.

Optional if device doesn't install a key identifier for symmetric IAK.

  .. code-block:: c

    enum tfm_plat_err_t attest_plat_get_symmetric_iak_id(void *kid_buf,
                                                         size_t buf_len,
                                                         size_t *kid_len);

  **Parameters:**

  +-------------+-------------------------------------+
  | ``kid_buf`` | Buffer to store the IAK identifier. |
  +-------------+-------------------------------------+
  | ``buf_len`` | The length of ``kid_buf``.          |
  +-------------+-------------------------------------+
  | ``kid_len`` | The length of the IAK identifier.   |
  +-------------+-------------------------------------+

It returns error code specified in ``enum tfm_plat_err_t``.

*********
Reference
*********

.. [1] `PSA Attestation API 1.0 (ARM IHI 0085) <https://developer.arm.com/-/media/Files/pdf/PlatformSecurityArchitecture/Implement/IHI0085-PSA_Attestation_API-1.0.2.pdf?revision=eef78753-c77e-4b24-bcf0-65596213b4c1&la=en&hash=E5E0353D612077AFDCE3F2F3708A50C77A74B2A3>`_

.. [2] :doc:`Trusted Firmware-M Profile Small Design </configuration/profiles/tfm_profile_small>`

.. [3] :doc:`Initial Attestation Service Integration Guide </integration_guide/services/tfm_attestation_integration_guide>`

.. [4] `MAC compute in t_cose library <https://github.com/laurencelundblade/t_cose/blob/v2.0-alpha-2/inc/t_cose/t_cose_mac_compute.h>`_

.. [5] `HMAC: Keyed-Hashing for Message Authentication <https://tools.ietf.org/html/rfc2104>`_

----------------

*Copyright (c) 2020-2025 Arm Limited. All Rights Reserved.*
