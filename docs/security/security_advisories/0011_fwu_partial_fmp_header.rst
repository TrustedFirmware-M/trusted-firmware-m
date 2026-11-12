Advisory TFMV-11
================

+-----------------+------------------------------------------------------------+
| Title           | Incorrect FMP Header Fragment Reconstruction Allows        |
|                 | Attacker-Controlled Firmware Version Values                |
+=================+============================================================+
| CVE ID          | `CVE-2026-73063`_                                          |
+-----------------+------------------------------------------------------------+
| Public          | Aug 03, 2026                                               |
| Disclosure Date |                                                            |
+-----------------+------------------------------------------------------------+
| Versions        | TF-M `v2.2.0`_ and `v2.3.0`_ inclusive                     |
| Affected        |                                                            |
+-----------------+------------------------------------------------------------+
| Configurations  | Only Corstone-1000 platform                                |
+-----------------+------------------------------------------------------------+
| Impact          | Fragmented supplied FMP header skips firmware version      |
|                 | checks for firmware updates in some scenarios              |
+-----------------+------------------------------------------------------------+
| Fix Version     | `d92781c5b966ee700ddaa9525230e677789def96`_                |
+-----------------+------------------------------------------------------------+
| Credits         | Undisclosed                                                |
+-----------------+------------------------------------------------------------+


Background
----------

The sequence below applies only for Corstone-1000 platform.
The requester for a firmware update (FWU) provides metadata along with the image
to be used for update.
The FWU implementation checks the candidate firmware version against the current
running version. Only newer versions are allowed.
When carrying out those checks, internal copies of incoming metadata are
performed.
The requester is allowed to supply metadata and data in multiple calls and the
implementation keeps track of the incoming chuncks in the whole sequence.
When the incoming metadata is supplied through multiple calls, the
implementation incorrectly overwrites and reconstruct the FMP header. This FMP
header contains the requested firmware version.
Subsequent calls of partial FMP header lead to overwrite of firmware version
which ultimately can be used as an exploit to bypass version checks.
This mechanism is, however, not the only single point of verification. During
the image loading sequence, further version checks are performed. Counters are
used within the signed image for those verification. When non-volatile counters
are not implemented, then the backup verification checks cannot take place.
Some type of images within the firmware capsule update are susceptible to the
above flaw.


Impact
------

The firmware version checks, combined with missing security counters for some
images, lead to unverified, attacker-controlled firmware updates.


Mitigation
----------

Perform correct storage of the incoming partial FMP header.

See commit `d92781c5b966ee700ddaa9525230e677789def96`_.

.. _CVE-2026-73063: https://www.cve.org/CVERecord?id=CVE-2026-73063
.. _v2.2.0: https://git.trustedfirmware.org/plugins/gitiles/TF-M/trusted-firmware-m/+/refs/tags/TF-Mv2.2.0
.. _v2.3.0: https://git.trustedfirmware.org/plugins/gitiles/TF-M/trusted-firmware-m/+/refs/tags/TF-Mv2.3.0
.. _d92781c5b966ee700ddaa9525230e677789def96: https://git.trustedfirmware.org/plugins/gitiles/TF-M/trusted-firmware-m.git/+/d92781c5b966ee700ddaa9525230e677789def96

---------------------

*SPDX-License-Identifier: BSD-3-Clause*

*SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors*
