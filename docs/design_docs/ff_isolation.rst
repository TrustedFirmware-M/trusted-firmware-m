##############
FF-M Isolation
##############

:Organization: Arm Limited
:Contact: tf-m@lists.trustedfirmware.org

This document analyzes the isolation rules of implementing Firmware Framework
for M 1.1 (FF-M 1.1) [2]_ isolation and introduces the reference implementation
in TF-M, which complies with the rules by operating the hardware and software
resources.

.. note::
  Reference the document :doc:`Glossary </glossary>` for terms
  and abbreviations.

************
Introduction
************
This chapter describes the definitions from Firmware Framework for M (FF-M) [1]_
and analyzes the possible implementation keypoints.

Isolation Levels
================
There are 3 isolation levels (1-3) defined in FF-M, the greater level number has
more isolation boundaries.

The definition for Isolation Level 1:

- L1.1 NPSE needs protection from nobody.
- L1.2 SPE needs protection from NSPE.

The definition for Isolation Level 2:

- L2.1 NPSE needs protection from nobody.
- L2.2 Application Root of Trust (ARoT) needs protection from NSPE.
- L2.3 PSA Root of Trust (PRoT) needs protection from NSPE and ARoT.

The definition for Isolation Level 3:

- L3.1 NPSE needs protection from nobody.
- L3.2 Secure Partition needs protection from NSPE and other Secure Partitions.
- L3.3 PSA Root of Trust (RoT) domain needs protection from NSPE and all Secure
  Partitions.

.. important::
  A Secure Partition RoT Service is a Root of Trust Service implemented within
  a Secure Partition. An Application RoT Service must be implemented as
  a Secure Partition RoT Service. But it is implementation-defined whether a
  PSA RoT Service is a Secure Partition RoT Service.

  Here listed several possible PSA RoT Service implementation mechanisms:

  1. Implement PSA RoT Services in Secure Partitions with respective
     boundaries.
  2. Implement PSA RoT Services in Secure Partitions, but no boundaries between
     these Secure Partitions as they are in the PSA RoT Domain.
  3. Implement PSA RoT Services in a customized way instead of Secure
     Partitions, an internal library of PSA RoT domain e.g.

  TF-M chooses the 2nd option to balance performance and complexity.

Isolation Rules
===============
The essence of isolation is to protect the assets of one protection domain from
being accessed from other domains. The isolation levels define where the
isolation boundaries should be placed, the isolation rules define the strength
of the isolation the boundaries should offer.

.. note::
  Refer to chapter *Memory Assets* in FF-M [1]_ to know asset class items.
  Assets are represented by memory addresses in the system memory map, which
  makes assets named *Memory Assets*. The often-seen asset items are ROM, RAM,
  and memory-mapped peripherals.

Memory Asset Class
------------------
There are 3 memory asset classes defined in FF-M:

- Code
- Constant data
- Private data

There are 7 isolation rules for protecting assets described in chapter ``3.1``
of FF-M 1.0 [1]_ and chapters ``8.4`` to ``8.5`` of FF-M 1.1 [2]_. The following
is a summary of the rules:

- I1. (Changed in FF-M 1.1) Private data is not executable.
- I2. Only private data is writable.
- I3. If domain A needs protection from domain B, then Private data in domain A
  cannot be accessed by domain B.
- I4. (Optional, changed in FF-M 1.1) If domain A needs protection from domain
  B, then Code and Constant data in domain A, which is not part of a shared
  library, is not readable or executable by domain B.
- I5. (Optional, changed in FF-M 1.1) Code in a domain, which is not part of a
  shared library, is not executable by any other domain.
- I6. (Optional) All assets in a domain are private to that domain and cannot be
  accessed by any other domain, with the following exception:
  The domain containing the SPM can only access Private data and Constant data
  assets of other domains when required to implement the PSA Firmware Framework
  API.
- I7. (Optional, added in FF-M 1.1) Constant data is not executable.

 The first 3 rules from ``I1`` to ``I3`` define the mandatory rules to comply
 with the PSA security model, while ``I4`` to ``I7`` are optional rules to
 enhance the isolation boundaries.

 .. important::
   There is a table in chapter ``3.1.2`` of FF-M 1.0 [1]_ under ``I1`` that
   lists the asset types and allowed access method. Preventing executable access
   to constant data costs more hardware resources, so there is an optional rule
   I7 created in FF-M 1.1 [2]_ to aid implementations with constrained hardware
   resources.

Hardware Infrastructure
=======================
To implement a secure system, the hardware security framework (e.g. TrustZone or
multiple-core) and their auxiliary components (e.g. SAU) are required to ensure
the isolation between SPE and NSPE, as described in Trusted Base System
Architecture for M (TBSA-M) [3]_.

.. important::
  The interface between secure and non-secure states needs to be fully
  enumerated and audited to prove the integrity of the secure state
  isolation.

Besides this SPE and NSPE isolation mechanism, the following analyzes the
implementation rules to find out the hardware requirements for isolation inside
SPE domains:

- I1, I2 and I7: The assets can be categorized into 3 `Memory Asset Class`_,
  each type has the specific access rules.
- I3: The private data access from the prevented domain needs to be blocked.
- I4: All the assets access from the prevented domain needs to be blocked.
- I5: Code execution from all other domains (even the domain not prevented
  from) needs to be blocked.
- I6: All the assets access from all other domains (includes non-prevented
  domain) needs to be blocked, but, SPM is an exception, which can access the
  private data and constant data of the current domain.

The above items list the requirements for memory access, here are two more
points:

- If the memory device or the peripheral are shared between multiple hosts
  (such as multiple CPU or DMA, etc.), specific hardware protection units need
  to be available for validating accesses to that device or peripheral.
- The MMIO range for Secure Partitions is not allowed to be overlapped, which
  means each partition should have exclusive memory-mapped region if they
  require a peripheral device. The memory-mapped region is regarded as
  the private data so access to this area needs to be validated.

************************
Reference Implementation
************************
This chapter describes the isolation implementation inside SPE by using the
Armv8-M architecture component - Memory Protection Unit (MPU). The MPU can
isolate CPU execution and data access.

.. note::
  Previous version M-profile architecture MPU setting is similar in concept but
  the difference in practical register formats, which is not described in this
  document.

The MPU protects memory assets by regions. Each region represents a memory
range with specific access attributes.

.. note::
  The maximum numbers of MPU regions are platform-specific.

The SPM is running under the privileged mode for handling access from services.
The MPU region for SPM needs to be available all the time since SPM controls
the MPU setting while scheduling.

Since partitions are scheduled by SPM, the MPU regions corresponding to the
partitions can be configured dynamically while scheduling. Since there is only
one running at a time and all others are deactivated, the SPM needs to set up
necessary regions for each asset type in one partition only.

There is reusable code like the C-Runtime and RoT Service API which are same
across different partitions. TF-M creates a Secure Partition Runtime Library
(SPRTL) as a specific library shared by the Secure Partition. Please refer to
:doc:`Secure Partition Runtime Library </design_docs/services/secure_partition_runtime_library>`
for more detail.

.. note::
  Enable SPRTL makes it hard to comply with the rules I4, I5 and I6,
  duplicating the library code can be one solution but it is not "shared"
  library anymore.

As mentioned in the last chapter, MMIO needs extra MPU regions as private data.

MPU Region Access Permission
============================
The following content describes the memory access permission to represent the
corresponding asset classes.

These access permissions are available on Armv8-M MPU:

- Privileged Read-Only (RO)
- All RO
- Privileged Read-Write (RW)
- All RW
- Execute Never (XN)

And one more Armv8.1-M access permission:

- Privileged Execute Never (PXN)

The available regions type list:

======== =========== =============== ========================================
Type     Attributes  Privilege Level Asset
======== =========== =============== ========================================
P_RO     RO          Privileged      PRoT Code
P_ROXN   RO + XN     Privileged      PRoT Constant Data
P_RWXN   RW + XN     Privileged      PRoT Private Data/Peripheral
A_RO     RO          Any privilege   Partition/SPRTL Code
A_ROXN   RO + XN     Any privilege   Partition/SPRTL Constant Data
A_RWXN   RW + XN     Any privilege   Partition/SPRTL Private Data/Peripheral
A_ROPXN  RO + PXN    Any privilege   Armv8.1-M Partition Code
======== =========== =============== ========================================

Example Image Layout
====================
The secure firmware image contains components such as partitions, SPM and the
shared code and data. Each component may have different class assets. There
would be advantages if placing the assets from all components with the same
access attributes into one same region:

- The data relocating or clearing when booting can be done in one step instead
  of breaking into fragments.
- Assets with statically assigned access attribute can share the same MPU
  region which saves regions.

Take the TF-M existing implementation image layout as an example::

   Level 1      Level 2             Level 3
   Boundaries   Boundaries          Boundaries
  +------------+----------+------------------------------------+
  |            |          |    PRoT SPM                Code    |
  |            | PRoT     +------------------------------------+
  |            | Code     |    PRoT Service            Code    |
  |  Code      +----------+------------------------------------+
  |  (ROM)     |          |    Partition 1             Code    |
  |            |          +------------------------------------+
  |            | ARoT     |    Partition N             Code    |
  |            | Code     +------------------------------------+
  |            |          |    SPRTL                   Code    |
  +------------+----------+------------------------------------+
  Check [4] for more details between Code and Constant Data.
  +------------+----------+------------------------------------+
  |            | PRoT     |    PRoT SPM       Constant Data    |
  |            | Constant +------------------------------------+
  |            | Data     |    PRoT Service   Constant Data    |
  |  Constant  +----------+------------------------------------+
  |   Data     | ARoT     |    Partition 1    Constant Data    |
  |   (ROM)    | Constant +------------------------------------+
  |            | Data     |    Partition N    Constant Data    |
  |            |          +------------------------------------+
  |            |          |    SPRTL          Constant Data    |
  +------------+----------+------------------------------------+

  +------------+----------+------------------------------------+
  |            | PRoT     |    PRoT SPM        Private Data    |
  |            | Private  +------------------------------------+
  |            | Data     |    PRoT Service    Private Data    |
  |  Private   +----------+------------------------------------+
  |   Data     |          |    Partition 1     Private Data    |
  |   (RAM)    | ARoT     +------------------------------------+
  |            | Private  |    Partition N     Private Data    |
  |            | Data     +------------------------------------+
  |            |          |    SPRTL           Private Data    |
  +------------+----------+------------------------------------+

.. note::
  1. Multiple binaries image implementation could also reference this layout if
     its hardware protection unit can cover the exact boundaries mentioned
     above.
  2. Private data includes both initialized and zero-initialized (ZI) sections.
     Check chapter ``3.1.1`` of FF-M [1]_ for the details.
  3. This diagram shows the boundaries but not orders. The order of regions
     inside one upper region can be adjusted freely.
  4. As described in the ``important`` of `Memory Asset Class`_, the setting
     between Code and Constant Data can be skipped if the executable access
     method is not applied to constant data. In this case, the groups of Code
     and Constant Data can be combined or even mixed -- but the boundary
     between PRoT and ARoT are still required under level higher than 1.

Example Region Numbers under Isolation Level 3
==============================================
The following table lists the required regions to comply with the rules for
implementing isolation level 3. The level 1 and level 2 can be exported by
simplifying the items in level 3 table.

.. important::
  The table described below is trying to be shared between all supported
  platforms in Trusted Firmware-M. It is obvious that some platforms have
  special characteristics. In that case, the specific layout table for a
  particular platform can be totally redesigned but need to fulfil the
  isolation level requirements.

- Only the running partition's assets are covered since the inactive partitions
  do not need regions.
- ``X`` indicates the existence of this region can't comply with the rule.
- An ``ATTR + n`` represent extra ``n`` regions are necessary.
- The table assumes each rule is in addition to the rules in previous columns
  (but the FF-M permits any combination of optional rules).

The following table lists the required regions to comply with the rules:

+-------------------+-------------+-------------+-------------+-------------+
| Region Purpose    | I1 I2 I3 I7 | I4          | I5          | I6          |
+===================+=============+=============+=============+=============+
| PRoT SPM Code     | A_RO        | P_RO        | P_RO        | P_RO        |
+-------------------+             |             |             +-------------+
| PRoT Service Code |             |             |             | A_ROPXN     |
+-------------------+             +-------------+-------------+             |
| Active Partition  |             | A_RO        | A_ROPXN     |             |
| Code              |             |             |             |             |
+-------------------+             +-------------+-------------+-------------+
| SPRTL Code        |             | A_RO        | A_RO        | ``X``       |
+-------------------+-------------+-------------+-------------+-------------+
| PRoT SPM RO       | A_ROXN      | P_ROXN      | P_ROXN      | P_ROXN      |
+-------------------+             |             |             +-------------+
| PRoT Service RO   |             |             |             | A_ROXN      |
+-------------------+             +-------------+-------------+             |
| Active Partition  |             | A_ROXN      | A_ROXN      |             |
| RO                |             |             |             |             |
+-------------------+             +-------------+-------------+-------------+
| SPRTL RO          |             | A_ROXN      | A_ROXN      | ``X``       |
+-------------------+-------------+-------------+-------------+-------------+
| PRoT SPM RW       | P_RWXN      | P_RWXN      | P_RWXN      | P_RWXN      |
+-------------------+             |             |             +-------------+
| PRoT Service RW   |             |             |             | A_RWXN      |
+-------------------+-------------+-------------+-------------+             |
| Active Partition  | A_RWXN      | A_RWXN      | A_RWXN      |             |
| RW                |             |             |             |             |
+-------------------+-------------+-------------+-------------+-------------+
| SPRTL RW [5]      | A_RWXN + 1  | A_RWXN + 1  | A_RWXN + 1  | ``X``       |
+-------------------+-------------+-------------+-------------+-------------+
| Partition Periph  | A_RWXN + n  | A_RWXN + n  | A_RWXN + n  | A_RWXN + n  |
+-------------------+-------------+-------------+-------------+-------------+
| Total Numbers     | [1]         | [2]         | [3]         | [4]         |
+-------------------+-------------+-------------+-------------+-------------+

.. note::
  1. Total number = A_RO + A_ROXN + P_RWXN + (2 + n)A_RWXN = ``5 + n``, where
     ``n`` is the maximum number of peripherals needed by one partition.
  2. Total number = [1] + P_RO + A_RO + P_ROXN + A_ROXN = ``9 + n`` (or
     ``6 + n`` without SPRTL).
  3. Total number = [2] = ``9 + n``, and Armv8.1-M PXN is required.
  4. Total number = P_RO + A_ROPXN + P_ROXN + A_ROXN + P_RWXN + (1 + n)A_RWXN =
     ``6 + n``, but SPRTL cannot be used, and Armv8.1-M PXN is required. To
     comply with this rule, the PSA RoT Services need to be implemented as
     Secure Partitions.
  5. This data belongs to SPRTL RW but it is set as Read-Only and only SPM
     can update this region with the active partition's metadata for
     implementing functions with owner SP's context, such as heap functions.
     This region can be skipped if there is no metadata required (such as no
     heap functionalities required).

  The memory-mapped regions for peripherals have different memory access
  attributes in general, they are standalone regions in the MPU even though
  their attributes covers 'A_RWXN'.

TF-M provides the reference linker scripts ``tfm_isolation_s.sct.template``,
``tfm_isolation_s.ld.template``, and ``tfm_isolation_s.icf.template`` for the
Armclang, GCC, and IAR compilers in the ``platform/ext/common`` directory. These
linker scripts arrange the SPE's memory by attribute to aid the implementation
of the isolation rules.

The reference isolation HAL for Armv8-M and Armv8.1-M platforms in
``platform/ext/common/tfm_hal_isolation_v8m.c`` uses the memory position tags
defined by the linker scripts to set up the MPU region base and limit addresses.
It implements isolation rules I1, I2, I3 and I7 for isolation levels 1 to 3. It
partially implements rule I4 by statically partitioning code into privileged and
unprivileged read-only regions but collecting all constant data into a single
unprivileged, read-only, execute-never region, which provides a good level
of protection against ROP attacks by limiting the amount of executable memory.
On Armv8.1-M targets, it statically configures all Application RoT Partition
code as PXN, which is sufficient to satisfy rule I5 in isolation level 2, but
not in isolation level 3, where it would require dynamically mapping only the
active partition's code region.

TF-M platforms may replace the reference linker scripts and/or isolation HAL
with a customized implementation, but it must meet at least isolation rules I1,
I2 and I3 to comply with the PSA security model.

Default access rules
====================
Hardware protection components MAY have the capability to collect regions
not explicitly configured in static or runtime settings, and then apply
default access rules to these regions. Furthermore, one default rule can be
applied to multiple non-contiguous regions which makes them share a common
boundary. This operation sets up a standalone 'region' the same as other
explicitly configured regions. And it doesn't affect the analysis summary
above - just be aware that some regions listed in the table MAY not be
explicitly configured.

Take the MPU as an example, MPU can assign a default privileged access
attribute to the regions (e.g. SPM and PRoT regions) not explicitly configured.
This feature can reduce required MPU regions and ease the programming because
regions can be put non-address-contiguous and skip the explicit configuration.

.. important::
  When this default access rules mechanism is applied, the implicitly configured
  regions must be reviewed to ensure the isolation boundaries are set correctly.

Interfaces
==========
The isolation implementation is based on the HAL framework. The SPM relies on
the HAL API to perform the necessary isolation related operations.

The requirement the software need to do are these:

- Create enough isolation protection at the early stage of system booting, just
  need to focus on the SPM domain.
- Create an isolation domain between secure and non-secure before the jump to
  the non-secure world.
- Create an isolation domain for each Secure Partition after the Secure
  Partition is loaded and before jumping to its entry point. The isolation
  domain should cover all the assets of the Secure Partition, include all its
  memory, interrupts, and peripherals.
- Switch isolation domains when scheduling different Secure Partitions.
- It is also a requirement that the platform needs to help to check if the
  caller of the PSA APIs is permitted to access some memory ranges.

The design document
:doc:`TF-M Hardware Abstraction Layer </design_docs/software/hardware_abstraction_layer>`
gives a detail design, include the platform initialization, isolation
interfaces. Please refer to it for more detail.

**********
References
**********

.. [1] `Arm PSA Firmware Framework for M 1.0 (FF-M 1.0) <https://developer.arm.com/documentation/den0063/latest/>`_
.. [2] `Arm Firmware Framework for M 1.1 Extension (FF-M 1.1) <https://developer.arm.com/documentation/aes0039/latest/>`_
.. [3] `Arm Trusted Base System Architecture for M (TBSA-M) <https://developer.arm.com/-/media/Arm%20Developer%20Community/PDF/PSA/DEN0083_PSA_TBSA-M_1.0-bet2.pdf?revision=5f9de99f-a7b5-4851-b041-f698521bf6bf>`_

--------------

*Copyright (c) 2020-2024, Arm Limited. All rights reserved.*
