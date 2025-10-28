######################################################
Communication Between NSPE And SPE In Dual Core System
######################################################

:Author: David Hu
:Modified: Nicola Mazzucato
:Organization: Arm Limited
:Contact: david.hu@arm.com


************
Introduction
************

This document describes the communication design between the Non-secure
Processing Environment (NSPE) and Secure Processing Environment (SPE) in TF-M on
a dual-core system.

The dual-core system has the following characteristics:

- NSPE and SPE are properly isolated and protected following PSA specification.
- An Arm M-profile core hosts SPE and acts as the Secure core.
- Another core hosts NSPE and runs non-secure applications.
- An Inter-Processor Communication hardware module is available in the system
  for communication between NSPE core and SPE core.
- TF-M runs on the Secure core with platform-specific drivers support.

.. note::
  All the concepts for dual-cpu can be extended to multi-cpu without loss of
  generality. Also see the Hybrid Platform section for further details.


Scope
=====

This design document focuses on the dual-core communication design inside TF-M.
Some changes to TF-M core and Secure Partition Manager (SPM) are listed to
support the dual-core communication. This document only discusses the
implementation in TF-M Inter-Process Communication (IPC) model.
The TF-M non-secure interface library depends on the mailbox and NS real-time
operating system (RTOS) implementations. These components are not described in
detail.

This document defines the requirements for mailbox functionality. For detailed
mailbox design, see the dedicated mailbox document [1]_.


Organization of the document
============================

- `Overall workflow in dual-core communication`_ provides an overall workflow of
  dual-core communication between NSPE and SPE.
- `Mailbox communication Requirements`_ lists general requirements of
  mailbox, from the perspective of dual-core communication.
- `PSA client call handling flow in TF-M`_ discusses about the detailed sequence
  and key modules of handling PSA client call in TF-M.


*******************************************
Overall workflow in dual-core communication
*******************************************

The overall workflow in dual-core scenario can be described as follows

1. A non-secure application calls TF-M non-secure interface library to request
   Secure service. The TF-M non-secure interface library translates the Secure
   service into PSA Client calls.
2. TF-M non-secure interface library notifies TF-M of the PSA client call
   request, via mailbox. The HAL must define generic mailbox APIs to support
   various IPC implementations.
3. Inter-Processor Communication interrupt handler and mailbox handling in TF-M
   deal with the inbound mailbox event(s) and deliver the PSA client call
   request to TF-M SPM.
4. TF-M SPM processes the PSA client call request and dispatches it to the
   appropriate secure partition or handler.
5. After the PSA Client call is completed, the return value is sent back to NSPE
   via mailbox.
6. TF-M non-secure interface library fetches return value from mailbox.
7. The return value is returned to non-secure application.

The interfaces between NSPE app and TF-M NSPE interface library are unchanged
so the underlying platform specific details are transparent to NSPE
application.

Step 3-5 are covered in `PSA client call handling flow in TF-M`_ in detail.

.. note::
  This document is partially complete since the introduction of the Hybrid
  Platform Scheduling support, which extends the operation of the mailbox
  communication between local and remote NSPEs with SPE described here.
  For more details see :doc:`/design_docs/multi-cpu/hybrid_platform_solution`.


**********************************
Mailbox communication Requirements
**********************************

The communication between NSPE and SPE relies on mailbox communication
implementation. The mailbox functionalities are eventually implemented by
platform specific Inter-Processor Communication drivers.
This section lists some general requirements on mailbox communication between
NSPE and SPE.


Data exchanged between NPSE and SPE
===================================

A mailbox message contains the information and parameters of a PSA client call.
After SPE is notified by a mailbox event, SPE fetches the parameters from NSPE
for PSA Client call processing.
The mailbox design document [1]_ defines the structure of the mailbox message.

The information and parameters of PSA Client call in the mailbox message include

- PSA Client API

- Parameters required in PSA Client call. The parameters can include the
  following, according to PSA client call type:

  - Service ID (SID)
  - Handle
  - Request type
  - Input vectors and the lengths
  - Output vectors and the lengths
  - Requested version of secure service

- NSPE Client ID. Optional. The NSPE Client ID is required when NSPE RTOS
  enforces non-secure task isolation.

The mailbox implementation may define additional members in mailbox message to
accomplish mailbox communication between NSPE and SPE.

When the PSA Client call is completed in TF-M, the return result, such as
PSA_SUCCESS or a handle, shall be returned from SPE to NSPE via mailbox.


Synchronization between NSPE and SPE
====================================

The system must protect shared mailbox objects and variables from concurrent
access by NSPE and SPE.

Synchronization mechanisms must prevent race conditions when both cores access
the mailbox.


Support of multiple concurrent calls (informative)
==================================================

If the support of multiple ongoing NS PSA client calls in TF-M is required
in dual-core systems, an optional queue can be maintained in TF-M core to store
multiple mailbox objects received from NSPE.
To identify NS PSA client calls, additional fields can be added in TF-M SPM
objects to store the NS PSA Client request identification.

Note that when just a single outstanding PSA client call is allowed, multiple
NSPE OS threads can run concurrently and call PSA client functions. The first
PSA client call will be processed first, and any other OS threads will be
blocked from submitting PSA client calls until the first is completed.


*************************************
PSA client call handling flow in TF-M
*************************************

This section describes how TF-M processes PSA client call requests:

1. Platform specific Inter-Processor Communication interrupt handler is
   triggered after the mailbox event is asserted by NSPE. The interrupt handler
   calls ``spm_handle_interrupt()``.
2. SPM sends a ``MAILBOX_INTERRUPT_SIGNAL`` to ``ns_agent_mailbox`` partition.
3. ``ns_agent_mailbox`` partition deals with the mailbox message(s) which
   contain(s) the PSA client call information and parameters.
   Then the PSA client call request is dispatched to dedicated PSA client call
   handler in TF-M SPM.
4. After the PSA client call completes, the return value is transmitted to NSPE
   via mailbox.

Key modules and components:

- `Inter-Processor Communication interrupt handler`_ discusses the
  Inter-Processor Communication interrupt handler
- `TF-M Remote Procedure Call (RPC) layer`_ introduces TF-M Remote Procedure
  Call layer to support dual-core communication.
- `ns_agent_mailbox partition`_ describes the mailbox agent partition.
- `Return value response routine in TF-M`_ proposes the routine to send the
  return value to NSPE.


Inter-Processor Communication interrupt handler
===============================================

Platform specific driver must implement the Inter-Processor Communication
interrupt handler to deal with the Inter-Processor Communication interrupt
asserted by NSPE.
The platform specific interrupt handler shall complete the interrupt
operations, such as interrupt EOI or acknowledge.

The interrupt handler calls ``spm_handle_interrupt()`` to notify SPM of the
interrupt.

The platform's ``tfm_peripherals_def.h`` file defines a macro ``MAILBOX_IRQ``
that identifies the interrupt being used. The platform must also provide a
function ``mailbox_irq_init()`` that initialises the interrupt as described
in [2]_.

Platform specific driver puts Inter-Processor Communication interrupt into a
proper exception priority, according to system and application requirements.
The priority setting must guarantee that:

- TF-M may respond to a PSA client call request in time according to system and
  application requirements.
- Other exceptions, which are more latency sensitive or require higher
  priorities, are not blocked by Inter-Processor Communication interrupt ISR.

The exception priority setting is IMPLEMENTATION DEFINED.


TF-M Remote Procedure Call (RPC) layer
======================================

The RPC layer sits between TF-M SPM and mailbox implementation. The purpose of
RPC layer is to decouple mailbox implementation and TF-M SPM and enhance the
generality of entire dual-core communication.

The RPC layer provides a set of APIs to TF-M SPM to handle and reply PSA client
call from NSPE in dual-core scenario.
It hides the details of specific mailbox implementation from TF-M SPM. It avoids
modifying TF-M SPM to fit mailbox development and changes.
It can keep a unified PSA client call process in TF-M SPM in both single
Armv8-M scenario and dual-core scenario.

The RPC layer defines a set callback functions for mailbox implementation to
hook its specific mailbox operations. When TF-M SPM invokes RPC APIs to deal
with NSPE PSA client call, RPC layer eventually calls the callbacks to execute
mailbox operations.
RPC layer also defines a set of PSA client call handler APIs for mailbox
implementation. RPC specific client call handlers parse the PSA client call
parameters and invoke common TF-M PSA client call handlers.


ns_agent_mailbox partition
==========================

A dedicated agent acts as a partition and interacts with the NSPE through the
mailbox.

First, the agent calls ``tfm_hal_boot_ns_cpu()`` and
``tfm_hal_wait_for_ns_cpu_ready()`` to prepare the non-secure core.
Then it initialises the SPE mailbox and enable the IPC interrupt.

Once these tasks are complete, it enters an infinite loop waiting for a
``MAILBOX_INTERRUPT_SIGNAL`` signal indicating that a mailbox message has
arrived.

Mailbox handling is performed in the context of the ``ns_agent_mailbox``
partition, which makes any necessary calls to other partitions on behalf of
the non-secure code.

``ns_agent_mailbox`` calls RPC API ``tfm_rpc_client_call_handler()`` to check
and handle PSA client call requests from NSPE.

``tfm_rpc_client_call_handler()`` invokes request handling callback function to
execute specific mailbox message handling operations.
More details in document [1]_.

The handling process in mailbox operation consists of the following steps:

1. SPE mailbox fetches the PSA client call parameters from NSPE mailbox.
   Proper protection and synchronization must be implemented in mailbox to
   guarantee that the operations are not interfered with by NSPE mailbox
   operations or Inter-Processor Communication interrupt handler.
   If a queue is maintained inside TF-M core, SPE mailbox can fetch multiple
   PSA client calls together into the queue, to save the time of synchronization
   between two cores.

2. SPE mailbox parses the PSA client call parameters copied from NSPE, including
   the PSA client call type.

3. The PSA client call request is dispatched to the dedicated TF-M RPC PSA
   client call handler. The PSA client call request is processed in the
   corresponding handler based on PSA call types.

The dual-core scenario and single Armv8-M scenario in TF-M IPC implementation
shares the same PSA client call routines inside TF-M SPM. The current
handler definitions can be adjusted to be more generic for dual-core scenario
and single Armv8-M implementation.

If multiple requests are pending, the mailbox processes them one by one.


Return value response routine in TF-M
=====================================

Diverse PSA client calls can be implemented with different return value replying
routines.


Replying routine for psa_framework_version() and psa_version()
--------------------------------------------------------------

For ``psa_framework_version()`` and ``psa_version()``, handlers return values
directly during mailbox processing.
A compile flag can enable this routine for dual-core builds.

For ``psa_connect()``, ``psa_call()``, and ``psa_close()``, the target secure
partition completes the client call and invokes ``psa_reply()``.
The SVC handler in TF-M SPM then calls ``tfm_rpc_client_call_reply()`` to return
the result via mailbox.

Mailbox reply functions must not trigger context switches inside the SVC
handler.

If errors occur, the RPC handlers return the error without invoking the secure
partition. The mailbox transmits the error code to NSPE.


Build options
=============

The feature is enabled by ``TFM_MULTI_CORE_TOPOLOGY``.


*********
Reference
*********

.. [1] :doc:`Mailbox Design in TF-M on Dual-core System <./mailbox_design>`
.. [2] :doc:`Secure Interrupt Integration Guide </integration_guide/tfm_secure_irq_integration_guide>`

----------------

*Copyright (c) 2019-2025 Arm Limited. All Rights Reserved.*

*Copyright (c) 2020-2023 Cypress Semiconductor Corporation (an Infineon company)
or an affiliate of Cypress Semiconductor Corporation. All rights reserved.*

