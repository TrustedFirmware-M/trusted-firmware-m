Advisory TFMV-14
================

+-----------------+------------------------------------------------------------+
| Title           | OOB flash write in corstone1000 update bricks the secure   |
|                 | enclave                                                    |
+=================+============================================================+
| CVE ID          | `CVE-2026-73094`_                                          |
+-----------------+------------------------------------------------------------+
| Public          | Sept 14, 2026                                              |
| Disclosure Date |                                                            |
+-----------------+------------------------------------------------------------+
| Versions        | TF-M `v2.3.0`_                                             |
| Affected        |                                                            |
+-----------------+------------------------------------------------------------+
| Configurations  | Only Corstone-1000 platform                                |
+-----------------+------------------------------------------------------------+
| Impact          | A privileged Corstone-1000 host can permanently brick the  |
|                 | Secure Enclave root-of-trust                               |
+-----------------+------------------------------------------------------------+
| Fix Version     | `060ec25948f29f66b026be3c4858c2dbdfe0c443`_ and            |
|                 | TF-M `v2.3.1`_                                             |
+-----------------+------------------------------------------------------------+
| Credits         | animo                                                      |
+-----------------+------------------------------------------------------------+

Background
----------

The Corstone-1000 FWU bootloader backend writes update payload blocks directly
to flash through ``ProgramData()``.

The write address is calculated from the target image partition base plus the
number of image bytes already received. Without validating this calculated
range against the flash address space and the selected update partition size,
a sequence of FWU writes can extend past the end of the intended partition.

Impact
------

Corruption of Secure Enclave owned flash contents and may cause the
root-of-trust boot chain to fail validation on the next reset.

Mitigation
----------

Reject FWU write requests that would exceed the flash address space or the
target image partition size before calling the raw flash driver.


.. _CVE-2026-73094: https://www.cve.org/CVERecord?id=CVE-2026-73094
.. _v2.3.0: https://git.trustedfirmware.org/plugins/gitiles/TF-M/trusted-firmware-m.git/+/refs/tags/TF-Mv2.3.0
.. _v2.3.1: https://git.trustedfirmware.org/plugins/gitiles/TF-M/trusted-firmware-m.git/+/refs/tags/TF-Mv2.3.1
.. _060ec25948f29f66b026be3c4858c2dbdfe0c443: https://review.trustedfirmware.org/plugins/gitiles/TF-M/trusted-firmware-m/+/060ec25948f29f66b026be3c4858c2dbdfe0c443

---------------------

*SPDX-License-Identifier: BSD-3-Clause*

*SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors*
