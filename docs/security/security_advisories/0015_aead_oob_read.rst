Advisory TFMV-15
================

+-----------------+------------------------------------------------------------+
| Title           | Out-of-bounds read in crypto AEAD service                  |
|                 |                                                            |
+=================+============================================================+
| CVE ID          | `CVE-2026-90476`_                                          |
+-----------------+------------------------------------------------------------+
| Public          | Nov 10, 2026                                               |
| Disclosure Date |                                                            |
+-----------------+------------------------------------------------------------+
| Versions        | TF-M `v2.3.0`_                                             |
| Affected        |                                                            |
+-----------------+------------------------------------------------------------+
| Configurations  | All platforms using AEAD encryption through the SW         |
|                 | implementation provided by TF-PSA-Crypto                   |
+-----------------+------------------------------------------------------------+
| Impact          | A non-secure client sets the AEAD nonce length past the    |
|                 | 16-byte buffer and the Crypto partition reads out-of-bound |
|                 | bytes disclosing secure-partition memory.                  |
+-----------------+------------------------------------------------------------+
| Fix Version     | `b23e66338d32f6ca76636f3ad121c3a3eb7bf8d3`_ and            |
|                 | TF-M `v2.3.1`_                                             |
+-----------------+------------------------------------------------------------+
| Credits         | animo                                                      |
+-----------------+------------------------------------------------------------+


Background
----------

The TF-M Crypto service provides authenticated encryption with associated data
(AEAD) operations to Non-secure clients through the PSA Crypto API.

A vulnerability exists in the single part AEAD encryption/decryption API
function where the caller-provided nonce_length is not validated against the
fixed 16-byte nonce buffer.
The unchecked length is forwarded to the underlying PSA Crypto implementation,
potentially causing an out-of-bounds read when processing the nonce.


Impact
------

A malicious Non-secure client can exploit this vulnerability by supplying a
nonce length larger than the allocated buffer.

When using AES-GCM, through the software based implementation provided by
TF-PSA-Crypto, this may result in the disclosure of adjacent Secure memory
through the generated authentication tag, compromising confidentiality.
A sufficiently large nonce length may also trigger a Secure fault, causing the
system to reset or halt and resulting in a denial of service.

The vulnerability affects TF-M configurations using AEAD operations based on the
AES-GCM algorithm and redirecting them to the SW based crypto implementation
provided by TF-PSA-Crypto.


Mitigation
----------

The TF-M Crypto service must validate the caller-provided nonce_length against
TFM_CRYPTO_MAX_NONCE_LENGTH before invoking the underlying PSA Crypto AEAD
operations.



.. _CVE-2026-90476: https://www.cve.org/CVERecord?id=CVE-2026-90476
.. _v2.3.0: https://git.trustedfirmware.org/plugins/gitiles/TF-M/trusted-firmware-m.git/+/refs/tags/TF-Mv2.3.0
.. _v2.3.1: https://git.trustedfirmware.org/plugins/gitiles/TF-M/trusted-firmware-m.git/+/refs/tags/TF-Mv2.3.1
.. _b23e66338d32f6ca76636f3ad121c3a3eb7bf8d3: https://git.trustedfirmware.org/plugins/gitiles/TF-M/trusted-firmware-m/+/b23e66338d32f6ca76636f3ad121c3a3eb7bf8d3

---------------------

*SPDX-License-Identifier: BSD-3-Clause*

*SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors*
