Advisory TFMV-13
================

+-----------------+------------------------------------------------------------+
| Title           | Plaintext SFCP packet on RSE returns delegated-attestation |
|                 | private key                                                |
+=================+============================================================+
| CVE ID          | `CVE-2026-73091`_                                          |
+-----------------+------------------------------------------------------------+
| Public          | Sept 14, 2026                                              |
| Disclosure Date |                                                            |
+-----------------+------------------------------------------------------------+
| Versions        | TF-M `v2.3.0`_                                             |
| Affected        |                                                            |
+-----------------+------------------------------------------------------------+
| Configurations  | Only RSE platforms                                         |
+-----------------+------------------------------------------------------------+
| Impact          | A peer SFCP node retrieves the delegated-attestation       |
|                 | private key without performing the trusted-subnet AEAD     |
|                 | handshake                                                  |
+-----------------+------------------------------------------------------------+
| Fix Version     | `5f592a5fbeb13a2c00ccf3070ce57bb97db213f7`_ and            |
|                 | TF-M `v2.3.1`_                                             |
+-----------------+------------------------------------------------------------+
| Credits         | Mohammad Seet                                              |
+-----------------+------------------------------------------------------------+

Background
----------

The platform expects that the RSEs in the system are members of the trusted
subnet and therefore use encrypted communications.
This is not enforced on the "non-interrupt driven" receive code path for
sfcp_receive_msg.
Therefore external RSEs in the system could send unencrypted packets which would
be successfully received
On RDV3, for example, this allowed a plaintext SFCP request to reach the
delegated-attestation service and return the delegated-attestation private key
over an unencrypted SFCP packet.

Impact
------

An attacker able to send SFCP packets to an affected RSE platform can bypass
the intended SFCP channel protection for delegated-attestation traffic. The
attacker can request ``DELEGATED_ATTEST_GET_DELEGATED_KEY`` and receive the
delegated-attestation private key in plaintext. A hostile actor may snoop
the bus and send unencrypted packets to the RSE to receive the vHUK seed.

Mitigation
----------

Apply the trusted-subnet encryption policy to every received non-handshake SFCP
packet before dispatching it to message or reply handlers.


.. _CVE-2026-73091: https://www.cve.org/CVERecord?id=CVE-2026-73091
.. _v2.3.0: https://git.trustedfirmware.org/plugins/gitiles/TF-M/trusted-firmware-m.git/+/refs/tags/TF-Mv2.3.0
.. _v2.3.1: https://git.trustedfirmware.org/plugins/gitiles/TF-M/trusted-firmware-m.git/+/refs/tags/TF-Mv2.3.1
.. _5f592a5fbeb13a2c00ccf3070ce57bb97db213f7: https://review.trustedfirmware.org/plugins/gitiles/TF-M/trusted-firmware-m/+/5f592a5fbeb13a2c00ccf3070ce57bb97db213f7

---------------------

*SPDX-License-Identifier: BSD-3-Clause*

*SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors*
