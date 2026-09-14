Advisory TFMV-12
================

+-----------------+------------------------------------------------------------+
| Title           | Pre-auth OOB write in RSE SFCP handshake hijacks BL1       |
|                 | boot-ROM control flow                                      |
+=================+============================================================+
| CVE ID          | `CVE-2026-73065`_                                          |
+-----------------+------------------------------------------------------------+
| Public          | Sept 14, 2026                                              |
| Disclosure Date |                                                            |
+-----------------+------------------------------------------------------------+
| Versions        | TF-M `v2.3.0`_                                             |
| Affected        |                                                            |
+-----------------+------------------------------------------------------------+
| Configurations  | Only RSE platforms                                         |
+-----------------+------------------------------------------------------------+
| Impact          | An on-die SFCP peer node obtains a 32-byte                 |
|                 | attacker-controlled out-of-bounds write in the bl1_1 boot  |
|                 | ROM during the pre-authentication boot-time session-key    |
|                 | handshake                                                  |
+-----------------+------------------------------------------------------------+
| Fix Version     | `5f592a5fbeb13a2c00ccf3070ce57bb97db213f7`_ and            |
|                 | TF-M `v2.3.1`_                                             |
+-----------------+------------------------------------------------------------+
| Credits         | Mohammad Seet / Rayan Al Garni                             |
+-----------------+------------------------------------------------------------+

Background
----------

Some RSE configurations place nodes in a trusted subnet whose links are
initially untrusted, so the SFCP implementation performs a handshake before
normal traffic is protected with the negotiated session key.

The RSE SFCP encryption-handshake responder uses the remote node id taken
directly from a received packet header as an array index, with no bounds check.
During encrypted packet processing by the responder, the remote node ID is used
directly as an index into the trusted-subnet node array.
A crafted pre-authentication handshake packet could therefore select an out-of-
range node ID and cause SFCP to read or update sequence-tracking state outside
the trusted-subnet node array.

Impact
------

An attacker able to inject SFCP traffic before the trusted-subnet handshake is
complete can trigger an out-of-bounds write in RSE firmware. On affected RSE
systems this can corrupt adjacent state used during early boot. With a suitably
chosen packet sequence, this may allow control-flow corruption in the BL1 boot-
ROM execution context, up to attacker control of BL1 boot-ROM control flow.

Mitigation
----------

Validate SFCP packet node IDs before any packet-type-specific processing, and
reject sender or receiver IDs greater than or equal to ``SFCP_NUMBER_NODES``.


.. _CVE-2026-73065: https://www.cve.org/CVERecord?id=CVE-2026-73065
.. _v2.3.0: https://git.trustedfirmware.org/plugins/gitiles/TF-M/trusted-firmware-m.git/+/refs/tags/TF-Mv2.3.0
.. _v2.3.1: https://git.trustedfirmware.org/plugins/gitiles/TF-M/trusted-firmware-m.git/+/refs/tags/TF-Mv2.3.1
.. _5f592a5fbeb13a2c00ccf3070ce57bb97db213f7: https://review.trustedfirmware.org/plugins/gitiles/TF-M/trusted-firmware-m/+/5f592a5fbeb13a2c00ccf3070ce57bb97db213f7

---------------------

*SPDX-License-Identifier: BSD-3-Clause*

*SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors*
