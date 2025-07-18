Release Cadence and Process
===========================

The project aims to do a release once every 9 months.
The planned dates are listed in the :ref:`releases/index:Future release plans`

The releases are to be performed and tagged on a dedicated release branch.
The release process is initiated by an announcement in
`TF-M mailing list <https://lists.trustedfirmware.org/mailman3/lists/tf-m.lists.trustedfirmware.org/>`_
and followed by the creation of a release branch.
Normal development on the main branch is not blocked and can be continued.
The testing will be performed on release candidates and depending on
issues found, additional candidates may be created to fix and retest the issues.

:doc:`The Platform owners </contributing/maintainers>` are expected to
verify their platforms and confirm the correct operations or provide fixes
in a timely manner to include in the release. The release notes will list
all verified platforms. The platforms in Trusted Firmware OpenCI are
automatically tested and any issues found shall be fixed.

After the final tag, the changes from the release branch will be back ported
to the main branch.

.. uml::

    @startuml
    hide time-axis

    concise "main branch" as main
    concise "release branch v1.1.x" as rel1
    concise "release branch v1.2.x" as rel2

    @main
        -3 is development
        @0 <-> @8 : release cadence: ~9 months

    @rel1
        0 is rc1
        main -> rel1 : start
        +1 is rc2
        +1 is v1.1.0
        +1 is {-}
        rel1 -> main : back port
        +1 is v1.1.1 #pink
        +1 is {-}
        rel1 -> main : cherry-pick
        +3 is END #white
        +1 is {hidden}

    @rel2
        8 is rc1
        main -> rel2 : start
        +1 is v1.2.0
        +1 is {-}

        rel2 -> main : back port

        @0 <-> @3 : release process
        @4 <-> @5 : hotfix

    caption Release process

    @enduml

Although this document specifies the release cadence, this does not preclude
an adhoc release for specific project requirements.

.. note::
  When a new release starts the previous release branch obsoletes and is
  a subject for removal as shown for `v1.1.x` on the diagram above.
  At any moment only the latest release branch is maintained.
  The release tags will point to a commit in detached head state.

Release Version Scheme
----------------------

Trusted Firmware-M uses a semantic versioning scheme. A version number is
compiled as a dot separated set of numbers:

**TF-Mv<MAJOR>.<MINOR>.<HOTFIX>**

- <MAJOR>: Major release version for significant feature and API changes.
- <MINOR>: Minor release version for incremental features and API changes.
- <HOTFIX>: Used only for backporting **critical bug fix/security patches**.

Long Term Support (LTS)
-----------------------

From v2.1.0, TF-M project will provide LTS branches. Every alternate release
will be an LTS release maintained for 3 years.
The LTS release will be synchronized with
`Mbed TLS <https://www.trustedfirmware.org/projects/mbed-tls>`_
project to be aligned with LTS releases cadence. Mbed TLS is used as the
default cryptography library by the TF-M Crypto service.

The main purpose of TF-M LTS is to offer a maintained and PSA certified TF-M
codebase for the whole period of LTS. Without LTS, every TF-M based product
has to recall or update PSA certification with changes (especially security
fixes) to the codebase. Some changes like fixes for critical bugs or security
vulnerabilities are essential to keep a product secure with valid
PSA certificates. The recertification is a time and resource-consuming process,
putting extra burden on the platform owners. Moreover, this procedure is inefficient
and unscalable to be done on a huge number of PSA Certified TF-M platforms.

TF-M intends to centralise PSA certification of the common code and carry it on
for an LTS lifetime, ensuring that code is free from known bugs and security
vulnerabilities. For this, each LTS branch will be initially PSA certified for
a selected reference platform and recertified again on every TF-M release.
Please see the process below for the details. All platforms, based on LTS
version can hold PSA certification obtained once without a need for
recertification on updates if no vulnerability is found in a platform specific code.

LTS content
^^^^^^^^^^^

On every TF-M release the following items are backported from the **release**
branch to active LTS branches:

- Critical bugs, registered and tracked in :doc:`/contributing/issue_tracking`
- Security vulnerability fixes
- A new platform port with code changes restricted to the relevant platform folder only.

A full release cycle is performed on each updated LTS branch. If no items above were
delivered to the main branch since the last release, then LTS branches remain
unchanged with valid PSA certificate for that version.

Frequency and duration
^^^^^^^^^^^^^^^^^^^^^^

- A new LTS branch is created on every other TF-M release i.e. every 18 months.
- Each LTS branch is maintained for 3 years.

.. uml::

    @startuml
    hide time-axis

    concise "main branch" as main
    concise "release branch v2.1.x (LTS)" as lts21
    concise "release branch v2.2.x" as rel22
    concise "release branch v2.3.x (LTS)" as lts23
    concise "release branch v2.4.x" as rel24
    concise "release branch v2.5.x (LTS)" as lts25

    @main
        -1 is development
        @0 <-> @6 : release cadence: ~9 months

    @lts21
        0 is v2.1.0
        main -> lts21 : start
        +1 is "PSA cert" #aquamarine
        +2 is "v2.1.0-LTS"
        +2 is {-}
        +19 is END #white

    @rel22
        6 is v2.2.0
        main -> rel22 : start
        +1 is {-}
        +1 is v2.2.1 #pink
        +1 is {-}
        rel22 -> main : back port
        rel22 -> lts21 : back port
        +3 is END #white
        +1 is {hidden}

    @lts23
        12 is v2.3.0
        main -> lts23 : start
        +1 is "PSA cert" #aquamarine
        +2 is "v2.3.0-LTS"
        +2 is {-}

        @8 <-> @9 : hotfix

    @rel24
        18 is v2.4.0
        main -> rel24 : start
        +1 is {-}
        +2 is v2.4.1 #pink
        +1 is {-}
        rel24 -> main : back port
        rel24 -> lts21 : back port
        rel24 -> lts23 : back port
        +2 is END #white

        @0 <-> @12 : LTS release every 18 months

    @lts25
        24 is v2.5.0
        main -> lts25 : start

        @0 <-> @24 : LTS lifetime: 3 years

    caption Long Time Support (LTS) process

    @enduml

LTS usage scenario
^^^^^^^^^^^^^^^^^^

- Once released, the code (ex:*TF-MvX.Y.Z*) is submitted for PSA certification
  using the reference platform :ref:`platform/rpi/rp2350/readme:RP2350`.

- After obtaining PSA certification the release branch is tagged
  *TF-MvX.Y.Z-LTS* creating a base for PSA certification of downstream projects.

- Ad hoc security fixes on the current **release** branch resulting in a new TF-M
  release will be backported to LTS branches under maintenance with consequent
  minor releases on them. Each LTS minor release may be a subject for PSA
  recertification with evaluation of the code changes (delta certification).

- Platform independent TF-M fixes are evaluated once & available to PSA Certified
  platforms on the new LTS release for rebase without the need for individual recertification.

- Bug fixes (other than security fixes) are backported from the main branch to active LTS branches
  and made part of the next regular release. The LTS release will be subject to PSA Certification.

Q&A
---

1. **What if the release (e.g. TF-MvX.Y.Z) fails PSA certification?**

   A failure on PSA certification means a critical bug or vulnerability
   and requires code modification in the form of a hot fix followed by
   a new minor release.

2. **What is time gap between release and LTS tag?**

   It depends on PSA Lab Certification Body but is expected to be about 1 month.

3. **What if a security vulnerability is found in platform-specific code?**

   A vulnerable platform shall provide a fix for it and perform PSA
   certification independently.

--------------

*Copyright (c) 2020-2024, Arm Limited. All rights reserved.*
