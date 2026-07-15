Advisory TFMV-10
================

+-----------------+------------------------------------------------------------+
| Title           | Missing NS pointer validation in platform mailbox init     |
+=================+============================================================+
| CVE ID          | `CVE-2026-54467`_                                          |
+-----------------+------------------------------------------------------------+
| Public          | Jul 27, 2026                                               |
| Disclosure Date |                                                            |
+-----------------+------------------------------------------------------------+
| Versions        | All versions up to TF-M `v2.3.0`_ inclusive                |
| Affected        |                                                            |
+-----------------+------------------------------------------------------------+
| Configurations  | Platforms with standard mailbox dispatcher enabled         |
|                 | (Only PSoc64 and rp2350)                                   |
+-----------------+------------------------------------------------------------+
| Impact          | Non-secure supplied struct mailbox_init_t address ranges   |
|                 | are not validated                                          |
+-----------------+------------------------------------------------------------+
| Fix Version     | `00d1b3e716dc636f7ad4398980ae55427dc1731d`_                |
+-----------------+------------------------------------------------------------+
| Credits         | Abhinav Gaur                                               |
+-----------------+------------------------------------------------------------+


Background
----------

During the boot sequence of the secondary remote cores, the mailbox partition
initialization requires the address of the non-secure mailbox queues.
The platform code implements the mechanism through which the addresses and other
properties are provided by the remote core(s).
Such information is then returned back to the mailbox partition which stores the
pointers in its own memory.
The platform code verifies some parameters but omits the validation of the
addresses given by the non-secure applications.


Impact
------

The common SPE mailbox dispatcher later reads and writes through unvalidated
stored pointers in a secure context. This can enable non-secure-to-secure memory
corruption or persistent secure DoS/reset on affected platforms.


Mitigation
----------

Perform address range validation of the given mailbox queues before storing in
secure partition memory.
Can be done at platform-level although we recommend to be performed at
central-level (tfm_spe_mailbox).

See commit `00d1b3e716dc636f7ad4398980ae55427dc1731d`_.

.. _CVE-2026-54467: https://www.cve.org/CVERecord?id=CVE-2026-54467
.. _v2.3.0: https://git.trustedfirmware.org/plugins/gitiles/TF-M/trusted-firmware-m/+/refs/tags/TF-Mv2.3.0
.. _00d1b3e716dc636f7ad4398980ae55427dc1731d: https://git.trustedfirmware.org/plugins/gitiles/TF-M/trusted-firmware-m.git/+/00d1b3e716dc636f7ad4398980ae55427dc1731d

---------------------

*SPDX-License-Identifier: BSD-3-Clause*

*SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors*
