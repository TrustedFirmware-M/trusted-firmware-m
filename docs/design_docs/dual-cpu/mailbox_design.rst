#######################
NS Agent Mailbox Design
#######################

:Organization: Arm Limited
:Contact: tf-m@lists.trustedfirmware.org


**********
Background
**********

The SPE communicates with a remote NSPE through the 'NS Agent Mailbox'.
A physical mailbox mechanism is required for this partition to work.

The ``NS Agent Mailbox`` operates like a ``partition``.
The agent has an endless loop and waits for signals, calls the FF-M API based on
the parsed communication messages.

Because it acts as an agent, you must consider several key design details:

- The SPM treats the FF-M Client API caller’s ID as the client ID. However,
  because the NS Agent Mailbox may represent multiple non-secure clients, it
  must inform SPM which client it represents.
  The standard FF-M Client API lacks support for this requirement.
- The FF-M Client API blocks the caller until a reply is received. However,
  the NS Agent Mailbox must respond to non-secure interrupts promptly. Blocking
  can delay the handling of non-secure communication messages.


******
Design
******

The following figure shows the overall design of the relevant components.
NS Agents are implementation-defined components that provide FF-M-compliant
Client APIs to non-secure clients.
From the client’s perspective, these APIs behave according to the FF-M
specification.
However, NS Agents require customization and additional handling in the SPM
because they carry extra requirements compared to standard secure partitions.

.. figure:: /design_docs/media/mailbox_ns_agent1.*
    :align: center
    :name: fig-mailbox2
    :width: 60%

    High-level agents and secure partitions types and the respective callable API sets into SPM

.. note::
  ``NS Agent TrustZone`` is mentioned for the comparison purpose. The
  implementation details are out of scope for this document.

To align with FF-M compliance, the NS Agent Mailbox is designed to:

- operate like a standard Secure Partition under the IPC model, with one single
  thread and the ability to call standard FF-M APIs
- include a manifest file that describes its attributes and resources
- be assigned a positive partition ID

Services rely on the `client_id` for policy enforcement. When the NS Agent
Mailbox calls a Client API, the SPM must know which `client_id` the agent is
representing. Since standard APIs treat the caller as the service client, a
specific API is needed to support identifying the represented non-secure client.

The SPM sets the non-secure `client_id` into the message just before it sends
the message. Until then, it uses the agent’s ID.

This specific `Agent API` is non-blocking, unlike the standard FF-M Client APIs.
It improves communication efficiency between NS clients and NS Agent Mailbox.
This mechanism also requires additional signals and APIs for message
acknowledgments.

.. note::
  A standard Secure Partition cannot use the ``Agent API``. If attempted, an
  error is returned.


********************
Mailbox architecture
********************

The mailbox consists of two components: one in the NSPE and one in the SPE.

The NSPE mailbox handles mailbox functions in the non-secure domain, while the
SPE mailbox performs the same functions within TF-M.

On dual-core systems, the NSPE mailbox implements PSA Client APIs by sending
client requests and receiving results.

Implementations may differ across NSPE operating systems and use cases.

TF-M provides a reference implementation of the NSPE mailbox.

The NSPE mailbox stores data objects in non-secure memory that hold PSA Client
call parameters, return values, and other related data.
The NSPE mailbox uses platform-specific inter-process communication (IPC) to
handle notifications between the NSPE and the SPE.

The SPE mailbox in TF-M receives requests from the NSPE mailbox, parses them,
and invokes the TF-M Remote Procedure Call (RPC) layer.
The RPC layer delivers the requests to the TF-M core and Secure Partition
Manager (SPM).
After the PSA Client call completes, the TF-M core and SPM use the RPC layer to
return results to the NSPE through the mailbox.
The SPE mailbox manages its objects in secure memory.
Both NSPE and SPE mailboxes use platform-specific inter-process communication
(IPC) to exchange notifications.

The figure below shows the architecture.

.. figure:: dual_core_mailbox_arch.png
    :align: center
    :name: fig-mailbox3
    :width: 75%

    High-level architecture for SPE and NSPE with mailbox


Mailbox communication for PSA Client calls
==========================================

NSPE Mailbox queue
------------------

The NSPE mailbox maintains a queue in non-secure memory.
The queue contains one or more slots, and its size must match that of the SPE
mailbox queue.
Each slot includes a message and a reply structure.
Each slot may also contain fields that identify the non-secure task initiating
the PSA Client request.
The mailbox message stores the parameters for the PSA Client request inside the
slot.
The mailbox reply structure receives the PSA Client result from the SPE.


Mailbox messages
----------------

In the PSA Client API implementation, the NSPE mailbox selects an empty slot in
the queue and writes the parameters into the mailbox message in that slot.
The SPE mailbox parses those parameters from the mailbox message.
The mailbox message can include additional fields to transfer more information
from NSPE to SPE for processing in TF-M.


Mailbox replies
---------------

A mailbox reply structure in non-secure memory receives the PSA Client result
from the SPE mailbox.


SPE Mailbox queue
-----------------

The SPE mailbox maintains a queue to store mailbox objects. The number of slots
in this queue must match the NSPE mailbox queue.
After the SPE is notified of a pending PSA Client request, the mailbox assigns
an empty slot, copies the corresponding parameters from non-secure memory, and
parses them.

Each slot in SPE mailbox queue can contain the following fields:

- An optional field to hold mailbox message content copied from non-secure
  memory.
- Index of NSPE mailbox queue slot containing the mailbox message.
- A handle to the mailbox message. Optional. Identify the owner slot of PSA
  Client result when multiple mailbox messages are under processing.

Additional fields can be included in the slot structure to support mailbox
processing in the SPE.


Mailbox notifications between NSPE and SPE
------------------------------------------

The NSPE mailbox sends a notification to the SPE to signal a pending PSA Client
request.
In turn, the SPE mailbox notifies the NSPE when the PSA Client result is
available.
These notifications use platform-specific Inter-Processor Communication (IPC).

To support *full-duplex* communication between NSPE and SPE, it is recommended
to assign a dedicated IPC channel to each notification routine.
If both routines share the same IPC channel, proper synchronization must be
implemented to prevent conflicts.

In the SPE, the IPC interrupt handler processes notifications from the NSPE and
triggers the agent mailbox handling.
The communication prototype design [1]_ defines the behavior of the IPC
interrupt handler.

The NSPE can use either an interrupt handler or polling to detect IPC
notifications from the SPE.


PSA API and Agent API
=====================

The PSA API has been expanded to include:

- ``agent_psa_connect()``
- ``agent_psa_close()``
- ``agent_psa_call()``

To support the behavior changes in these APIs, new signals such as
`ASYNC_MSG_REPLY` and additional types are introduced.
The RPC layer uses the Agent API to forward calls to the targeted service.

When non-secure clients call ``psa_call()``, a mailbox message containing its
parameters is delivered to the ``NS Agent Mailbox``. The agent extracts the
parameters and calls `agent_psa_call()`.

The `agent_psa_call()` interface takes four arguments, unlike the standard
``psa_call()`` which takes six. Some parameters are combined to align the two
interfaces.

A composition type is used to pack the vectors:

.. code-block:: c

  struct client_params_t {
    int32_t         ns_client_id_stateless;
    const psa_invec *p_invecs;
    psa_outvec      *p_outvecs;
  };


`ns_client_id_stateless` identifies the non-secure client ID when accessing a
stateless service. This value is ignored for connection-based services.

A macro, `PARAM_PACK`, is introduced to pack vector types and message lengths
into a 32-bit `control` variable:


.. code-block:: c

    uint32_t control = PARAM_PACK(params->psa_call_params.type,
                                  params->psa_call_params.in_len,
                                  params->psa_call_params.out_len);

The agent must indicate whether memory sources for input and output vectors are
secure or non-secure. This helps the SPM validate the vectors properly.

To cover the above mentioned scenarios, guidelines are listed for input and
output vector processing:

- The agent needs to tell SPM where vectors and descriptors come from, to
  assist SPM perform proper memory checking. The source information is encoded
  in the parameter ``control``.
- When SPE platforms have the capability to identify the memory sources,
  platforms can decide whether to skip the indication or not, in the HAL.

Guidelines for vector processing:

- The agent must inform SPM of the memory origin for each vector and descriptor
  to enable proper memory checks. This information is encoded in the
  ``control`` parameter.
- If SPE can determine memory sources independently, it may skip the indication
  in the HAL.

The `agent_psa_connect()` and `agent_psa_close()` functions include an extra
``ns_client_id`` parameter to identify the non-secure client.
This value must be negative. If the value is zero or positive, SPM ignores it.

This mechanism allows agents to call APIs asynchronously on behalf of the
services they represent.

To support the Agent API, the following acknowledgment signal is defined:

.. code-block:: c

  #define ASYNC_MSG_REPLY            (0x00000004u)

This signal enables the agent and SPM to manage partition signals, retrieve
messages, and handle replies.


Code Example
============

See the reference implementation of ``secure_fw/partitions/ns_agent_mailbox/ns_agent_mailbox.c``


Custom manifest attributes
==========================
Three custom manifest attributes are added for this agent:

=============== ====================================================
Name            Description
=============== ====================================================
ns_agent        Indicates if this partition is an agent (true/false)
--------------- ----------------------------------------------------
client_id_base  The minimum client ID value (<0)
--------------- ----------------------------------------------------
client_id_limit The maximum client ID value (<0)
=============== ====================================================

``client_id_base`` and ``client_id_limit`` are negative numbers. This means that
``client_id_base <= client_id_limit``, but the absolute value of
``client_id_base`` must be greater than or equal to that of `client_id_limit`.
SPM checks for overlapping IDs when initializes the secure partitions and
agents.

Non-secure callers must provide a negative client ID (<0) when using the PSA API
through their communication layer.
All NS Agents follow a uniform ID mapping:

+---------------------------------------------------+---------------------+
|NS client ID                                       |Transformed client ID|
+===================================================+=====================+
|  -1                                               | client_id_limit     |
+---------------------------------------------------+---------------------+
|  -2                                               | client_id_limit - 1 |
+---------------------------------------------------+---------------------+
| ...                                                                     |
+---------------------------------------------------+---------------------+
|- (abs(client_id_limit) - abs(client_id_base) + 1) | client_id_base      |
+---------------------------------------------------+---------------------+

The functions ``tfm_multi_core_hal_client_id_translate`` and
``tfm_multi_core_register_client_id_range`` perform this translation.

Any other IDs provided by the NSPE will result in ``PSA_ERROR_INVALID_ARGUMENT``
error.

See the reference implementation of ``secure_fw/partitions/ns_agent_mailbox/ns_agent_mailbox.yaml``


Runtime and IDLE processing
===========================

At runtime, the NS Agent Mailbox should not be blocked by Agent-specific APIs.
It may only be blocked when:

- calling standard PSA Client APIs
- calling ``psa_wait()``

Only one component should enter IDLE mode. This depends on system topology:

- If a TrustZone-based NSPE exists, that NSPE should enter IDLE, regardless of
  how many NS Agent Mailbox are in the system.
- If only mailbox-based NSPEs exist, one NS Agent Mailbox can enter IDLE.

The implemented solution:

- SPRTL provides an API for entering IDLE.
- Only partitions with a specific flag can call this API.
- The manifest tooling counts the flagged partitions and returns an error if
  more than one exists.

.. [1] :doc:`Communication prototype between NSPE and SPE in Dual-core systems <./communication_between_nspe_and_spe_in_dual_core_systems>`


--------------

*Copyright (c) 2022-2025, Arm Limited. All rights reserved.*

*Copyright (c) 2023 Cypress Semiconductor Corporation (an Infineon company)
or an affiliate of Cypress Semiconductor Corporation. All rights reserved.*

