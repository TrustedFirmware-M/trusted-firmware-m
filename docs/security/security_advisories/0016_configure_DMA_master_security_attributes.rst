Advisory TFMV-16
================

+-----------------+------------------------------------------------------------+
| Title           | Configure DMA master security attributes                   |
+=================+============================================================+
| CVE ID          | `CVE-2026-118434`_                                         |
+-----------------+------------------------------------------------------------+
| Public          | Nov 24, 2026                                               |
| Disclosure Date |                                                            |
+-----------------+------------------------------------------------------------+
| Versions        | All                                                        |
| Affected        |                                                            |
+-----------------+------------------------------------------------------------+
| Configurations  | an519, an521 platforms                                     |
+-----------------+------------------------------------------------------------+
| Impact          | The vulnerability allows code executing in the privileged  |
|                 | Non-secure Processing Environment (NSPE) to cross the      |
|                 | security boundary into the Secure Processing Environment   |
|                 | (SPE).                                                     |
+-----------------+------------------------------------------------------------+
| Fix Version     | `c6d8e065394566702b6b463d833f3c55f6b2afa4`_ and            |
|                 | TF-M `v2.3.1`_ and `v2.1.6`_                               |
+-----------------+------------------------------------------------------------+
| Credits         | Mohammad Seet                                              |
+-----------------+------------------------------------------------------------+

Background
----------

Trusted Firmware-M contains an incorrect DMA security configuration in the Arm MPS2
AN519 and AN521 platforms implementation. During platform initialization, TF-M grants
Non-secure software access to the DMA controller register interfaces but does not
configure the corresponding DMA Master Security Controllers to issue Non-secure
transactions. Consequently, a privileged Non-secure application can program the
DMA controllers to perform Secure-attributed memory transactions, bypassing the
intended TrustZone isolation boundary. Successful exploitation allows an attacker
to read and modify arbitrary accessible Secure memory, potentially exposing
cryptographic keys and compromising Secure services.

Impact
------

The vulnerability allows code executing in the privileged Non-secure Processing
Environment to cross the security boundary into the Secure Processing Environment.

Mitigation
----------

Match the DMA master security attributes to their NS peripheral access.

.. _CVE-2026-118434: https://www.cve.org/CVERecord?id=CVE-2026-118434
.. _v2.1.6: https://review.trustedfirmware.org/plugins/gitiles/TF-M/trusted-firmware-m/+/0608c10e47c255e3b7354c7ebd341aecdddf0e48
.. _v2.3.1: https://review.trustedfirmware.org/plugins/gitiles/TF-M/trusted-firmware-m/+/94f7b8db6a6b990bbb493bc835a71ba691bfff99
.. _c6d8e065394566702b6b463d833f3c55f6b2afa4: https://review.trustedfirmware.org/plugins/gitiles/TF-M/trusted-firmware-m/+/c6d8e065394566702b6b463d833f3c55f6b2afa4

---------------------

*SPDX-License-Identifier: BSD-3-Clause*

*SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors*
