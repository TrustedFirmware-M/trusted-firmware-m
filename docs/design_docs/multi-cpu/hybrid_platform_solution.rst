#########################################
Scheduling for a Hybrid Platform Solution
#########################################

:Organization: Arm Limited
:Contact: tf-m@lists.trustedfirmware.org

.. Warning::
  This feature is completed but documentation, support and testing are limited.

  Please provide any feedback or comments via the TF-M mailing list or submit
  a patch in review.trustedfirmware.org.


************
Introduction
************

The Hybrid Platform solution refers to the more generic support for platforms
with one local NSPE client and one or more NSPE remote client. The local client
resides in the same cpu as the SPE, while the remote clients reside on separate
CPUs.

A Hybrid Platform solution requires applications to run from both local and
remote clients.
This inevitably brings some scheduling trade-offs and limitations on the table.

The implementation provided and explained in this section aims to give a
reference implementation for some use-cases where different systems need to
satisfy various scheduling preferences.

Those are broadly:

- SPE is in charge of scheduling
- NSPE is in charge of scheduling
- a BALANCED combination of the above

and are explained below.


*******************
System Architecture
*******************

A Hybrid Platform is a system topology where there is an instance of SPE and one
or multiple instances of NSPE running at the same time.

A common layout is:

.. code-block:: output

        ┌──────────────────┐cpuN    ┌──────────────────┐cpu0
      ┌──────────────────┐cpu2      │┌────────────────┐│
    ┌──────────────────┐cpu1        ││                ││
    │                  │ │ │        ││                ││
    │                  │ │ │        ││      TF-M      ││
    │                  │ │ │        ││      (SPE)     ││
    │                  │ │ │        ││                ││
    │                  │ │ │        │└────────────────┘│
    │                  │ │ │        │                  │
    │                  │ │ │ >MBOX< │ --TZ boundary--- │
    │                  │ │ │        │                  │
    │                  │ │ │        │┌────────────────┐│
    │                  │ │ │        ││                ││
    │  remote client   │ │ │        ││  local client  ││
    │                  │ │ │        ││     (NSPE)     ││
    │                  │ │ │        │└────────────────┘│
    │                  │ │─┘        └──────────────────┘
    │                  │─┘
    └──────────────────┘

where `local client` refers to the NSPE running on the same core of SPE, while
`remote client` refers to the other instance(s) of NSPE running on other
separate cores (irrespective of whether, or not, the same type of core).

Typically, a Hybrid Platform would fall into two categories:

+---------------+--------------------------------------------------------------+
| Topology      | Description                                                  |
+===============+==============================================================+
| Heterogeneous | M-Class processor running TF-M and secure services.          |
| topology      |                                                              |
|               | Non-secure applications running in both the Normal World of  |
|               | the M-Class and in one or more other (non M-class) different |
|               | cores.                                                       |
+---------------+--------------------------------------------------------------+
| Homogeneous   | M-Class processor running TF-M and secure services.          |
| topology      |                                                              |
|               | Non-secure applications running in both the Normal World of  |
|               | the M-Class and in one or more other identical M-Class cores.|
+---------------+--------------------------------------------------------------+
| Remark:                                                                      |
| When the M-Class core hosting the Secure World does NOT have a Normal World, |
| then the solution is known as "Dual-CPU" System.                             |
+------------------------------------------------------------------------------+


********************
Scheduling Scenarios
********************

There are commonly two classes of scheduling use-cases depending on how the
workload importance is distributed:

- Local NSPE can be interrupted anytime when a secure service is requested by
  the remote clients.
- Local NSPE can NOT be interrupted when a secure service is requested by the
  remote clients.

Usually, it is known at design stage which types of workloads and applications
will run in both local and remote clients, thus it can be decided in advance
which class of clients require to be serviced immediately and/or can be
preempted.
Such knowledge is then used to decide which scheduling option is best for the
whole system.

Those options are generalized and provided with three build choices assigned to
the build config ``CONFIG_TFM_HYBRID_PLAT_SCHED_TYPE``.


+-----------------------------------+----------------------------------------------------------+
| CONFIG_TFM_HYBRID_PLAT_SCHED_TYPE | Description                                              |
+===================================+==========================================================+
| TFM_HYBRID_PLAT_SCHED_OFF         | No support for Hybrid Platform is provided.              |
| (Default)                         |                                                          |
+-----------------------------------+----------------------------------------------------------+
| TFM_HYBRID_PLAT_SCHED_SPE         | NSPE has no control over when the request is processed.  |
|                                   |                                                          |
|                                   | SPE preempts NSPE (is scheduled to run) and runs the     |
|                                   | requested secure service (by the remote client).         |
|                                   | Once completed, execution then resumes to NSPE.          |
|                                   |                                                          |
+-----------------------------------+----------------------------------------------------------+
| TFM_HYBRID_PLAT_SCHED_NSPE        | NSPE is in full control over the incoming requests from  |
|                                   | the remote clients.                                      |
|                                   |                                                          |
|                                   | The incoming requests may be queued but execution does   |
|                                   | not switch to SPE.                                       |
|                                   | The local NSPE makes its own decisions on when it is     |
|                                   | an appropriate point to yield execution to execute the   |
|                                   | mailbox requests.                                        |
|                                   |                                                          |
|                                   | To do so, NSPE performs a psa_call to a stateless service|
|                                   | in the mailbox partition and let the execution to proceed|
|                                   | in SPE.                                                  |
|                                   | Note that the local NSPE does not have knowledge of any  |
|                                   | pending messages in the mailbox awaiting processing.     |
|                                   | It can only attempt to start their processing.           |
|                                   |                                                          |
+-----------------------------------+----------------------------------------------------------+
| TFM_HYBRID_PLAT_SCHED_BALANCED    | When multiple mailbox channels, and their respective     |
|                                   | interrupts, are available on a platform, then it is      |
|                                   | possible to schedule independently the different sources.|
|                                   | That is, some messages can be configured to be scheduled |
|                                   | according to the ``SCHED_SPE`` mechanism, while others   |
|                                   | can be configured to be scheduled according to the       |
|                                   | ``SCHED_NSPE`` (deferred to local NSPE) mechanism.       |
|                                   |                                                          |
|                                   | This can be achieved via a special attribute in the      |
|                                   | manifest: ``mbox_flags``.                                |
+-----------------------------------+----------------------------------------------------------+

The definitions for the options above are available in
``secure_fw/spm/include/tfm_hybrid_platform.h``.


********************
Integration examples
********************


Hybrid Platform with SPE scheduling
===================================

In the platform configuration settings file  ``config_tfm_target.h`` choose

.. code-block:: c

  #define CONFIG_TFM_HYBRID_PLAT_SCHED_TYPE   TFM_HYBRID_PLAT_SCHED_SPE


Hybrid Platform with NSPE scheduling
====================================

If your platform implements a custom set of RPC operations, then add the
``process_new_msg`` handler:

.. code-block:: c

  static int32_t platform_process_new_msg(uint32_t *nr_msg)
  {
      /* some optional platform tasks */

      /*
       * Note that it's the platform's choice on whether or not to return the
       * number of mailbox messages processed.
       */
      return platform_handle_req();
  }

  static struct tfm_rpc_ops_t rpc_ops = {
      .handle_req = platform_handle_req,
      .reply = platform_mailbox_reply,
      .handle_req_irq_src = platform_handle_req_irq_src,
      .process_new_msg = platform_process_new_msg,
  };


The platform interrupt handler is already expected to call
``spm_handle_interrupt()``, so to correctly handle the set/clear of IRQs, the
platform shall also call ``tfm_multi_core_set_mbox_irq()`` right after it as
shown below.

.. code-block:: c

  void mailbox_IRQHandler(void)
  {
      /* some optional platform tasks */

      spm_handle_interrupt(p_pt, p_ildi);

  #if (CONFIG_TFM_HYBRID_PLAT_SCHED_TYPE == TFM_HYBRID_PLAT_SCHED_NSPE)
      tfm_multi_core_set_mbox_irq(p_ildi);
  #endif
  }


The counterpart ``tfm_multi_core_clear_mbox_irq()`` is called instead by the
mailbox partition.

In the platform configuration settings file  ``config_tfm_target.h`` choose

.. code-block:: c

  #define CONFIG_TFM_HYBRID_PLAT_SCHED_TYPE   TFM_HYBRID_PLAT_SCHED_NSPE

Then, in the `local client` NSPE, where the scheduling decisions are made,
simply call the auxiliary mailbox service to process any pending mailbox
messages:

.. code-block:: c

  psa_status_t status;
  uint32_t num_msg;

  psa_outvec out_vec[] = {
      {
          .base = &num_msg,
          .len = sizeof(num_msg),
      },
  };

  status = psa_call(
      NS_AGENT_MBOX_PROCESS_NEW_MSG_HANDLE,
      PSA_IPC_CALL,
      NULL, 0,
      out_vec, IOVEC_LEN(out_vec));
  if (status < 0) {
    /* process the error */
  } else {
    /* num_msg contains the number of mailbox slots/messages processed */
  }


Hybrid Platform with BALANCED scheduling
========================================

All the above for ``TFM_HYBRID_PLAT_SCHED_NSPE`` plus the following changes,
where required, for the mailbox manifest.

.. code-block:: c

  "services": [
    {
      "<attribute>" : "<value>"
      ...
    },
  ],
  "irqs": [
    {
      "<attribute>" : "<value>"
      ...
      "mbox_flags": MBOX_IRQ_FLAGS_<DEFAULT|DEFER>_SCHEDULE,
    },
    ...
  ],

Currently, the mailbox flags ``mbox_flags`` supported are:

- MBOX_IRQ_FLAGS_DEFAULT_SCHEDULE: the requests via mailbox transport are managed
  accordingly to the default hybrid platform scheduling options (this is always
  the default option)

- MBOX_IRQ_FLAGS_DEFER_SCHEDULE: the requests via mailbox transport are deferred
  until the local NSPE calls the mailbox partition auxiliary service
  ``NS_AGENT_MBOX_PROCESS_NEW_MSG``

The ``mbox_flags`` is optional, it can be omitted when this feature is not
required.

In the platform configuration settings file  ``config_tfm_target.h`` choose

.. code-block:: c

  #define CONFIG_TFM_HYBRID_PLAT_SCHED_TYPE   TFM_HYBRID_PLAT_SCHED_BALANCED


Hybrid Platform and common binary image
=======================================

For homogeneous hybrid platform topology, the same binary image is likely to be
deployed across cores. In that case, both mailbox and TrustZone agents will be
in use. Therefore, the API for PSA calls would be, from each client's
perspective, virtually the same.
In that event, the APIs provided by both agents need to be available
simultaneously, and thus, a component that coordinates the redirection is
required.

To achieve this, a ``TFM_HYBRID_PLATFORM_API_BROKER`` is supplied. This
component simply redirects the standard PSA calls from the client to the correct
interface.
The redirection choice is made at initialization time, where the local or remote
NSPE sets the respective interface API.

For such hybrid platforms, the common build flags configuration would be
as follows:


+---------------------------------------+---------------------+
| Config Option                         | Set to              |
+=======================================+=====================+
| CONFIG_TFM_USE_TRUSTZONE              | ON                  |
+---------------------------------------+---------------------+
| TFM_HYBRID_PLATFORM_API_BROKER        | ON                  |
+---------------------------------------+---------------------+
| TFM_MULTI_CORE_TOPOLOGY               | ON                  |
+---------------------------------------+---------------------+
| TFM_MULTI_CORE_NS_OS                  | user's requirements |
+---------------------------------------+---------------------+
| TFM_MULTI_CORE_NS_OS_MAILBOX_THREAD   | user's requirements |
+---------------------------------------+---------------------+
| TFM_MULTI_CORE_TEST                   | user's requirements |
+---------------------------------------+---------------------+


The NSPE is expected to have a mechanism to detect its execution target, that is
being remote or local. This is *IMPLEMENTATION DEFINED*.

This mechanism should drive the main application to initialize the appropriate
interface, where the API broker is configured for the correct execution
environment.

See an example below.


.. code-block:: c

  #define EXEC_TARGET_LOCAL  true
  #define EXEC_TARGET_REMOTE false
  bool plat_is_this_client_local(void)
  {
      /*
       * An implementation-defined mechanism to detect the execution target.
       * For example, a RO memory location could hold such information.
       */

      return <EXEC_TARGET_LOCAL | EXEC_TARGET_REMOTE>;
  }

Then, the main implementation simply calls the mechanism logic function and
calls either the interface for TrustZone or Mailbox.
Subsequently, the interface sets the execution environment within the API
broker.

.. code-block:: c

  /*
   * The corresponding init function sets the execution environment via the API
   * broker.
   */
  if (plat_is_this_client_remote()) {
      tfm_ns_multi_core_boot();
  } else {
      tfm_ns_interface_init();
  }


Hybrid Platform and NSPE reentrancy
===================================

With scheduling set to ``TFM_HYBRID_PLAT_SCHED_SPE``, the non-secure state can
be interrupted, allowing execution to switch to the secure side until it
completes.
In systems where NSPE has no knowledge on when - or even if - there is a secure
service in action, a non-secure application can interrupt and take over
execution.
This is the case, for example, when a standard RTOS runs its scheduler (by
pre-empting the secure side) and later a new task runs.
That task can attempt to request services from the secure state, which could
lead to an intentional system panic.
To safely deal with such scenario, NSPE has a way to detect if reentrancy is
allowed. To do so, enable ``TFM_TZ_REENTRANCY_CHECK`` in the build and
include a validation check at run-time.
The following diagram illustrates an example for a NSPE with an RTOS and a
possible scenario of a secure service pre-empted by a new task.


.. uml::

    @startuml
    skinparam ParticipantPadding 15

    participant task1
    participant task2
    participant task3
    participant RTOS2
    participant TZ #119911
    participant Sec

    [-> task1 : App
    activate task1

    participant SRV
    participant mbox

    task1 --[#red]> mbox : S-irq
    deactivate task1
    activate mbox

    mbox -> SRV
    deactivate mbox
    activate SRV

    SRV --[#blue]> RTOS2 : SysTick_NS
    deactivate SRV
    activate RTOS2 #FF22BB
    ||5||
    note left: OS ctx switch

    RTOS2 -[#grey]>> task2
    deactivate RTOS2

    activate task2

    task2 -> Sec: tfm_ns_check_safe_entry
    activate Sec #FFBBBB
    Sec -> task2: ret != SUCCESS
    deactivate Sec
    task2 -> task2: **yield**
    task2 -[#grey]>> RTOS2: c/s

    deactivate task2

    activate RTOS2 #FF22BB
    ||5||
    note right: OS ctx switch

    RTOS2 -[#grey]>> task3
    deactivate RTOS2
    activate task3
    task3 -> task3 : do_work
    task3 --[#blue]> RTOS2 : SysTick_NS
    deactivate task3
    activate RTOS2 #FF22BB
    ||5||
    note right: OS ctx switch

    RTOS2 -> SRV
    deactivate RTOS2
    activate SRV

    SRV -> mbox
    deactivate SRV
    activate mbox

    mbox --[#red]> task1 : return
    deactivate mbox

    activate task1

    task1 --[#blue]> RTOS2 : SysTick_NS
    deactivate task1
    activate RTOS2 #FF22BB
    ||5||
    note right: OS ctx switch
    RTOS2 -[#grey]>> task2
    deactivate RTOS2
    activate task2

    task2 -> Sec: tfm_ns_check_safe_entry
    activate Sec #FFBBBB
    Sec -> task2: ret == SUCCESS
    deactivate Sec
    task2 -> SRV: do_work
    activate SRV
    SRV -> task2
    deactivate SRV
    task2 --[#blue]> RTOS2 : SysTick_NS
    deactivate task2

    activate RTOS2 #FF22BB
    ||5||
    note right: OS ctx switch
    RTOS2 -[#grey]>> task3
    deactivate RTOS2
    activate task3

    @enduml


.. note::

   The sequence diagram above demonstrates the denial of re-entry until the secure
   service completes; non-secure applications must check tfm_ns_check_safe_entry()
   and yield otherwise.


For the task in the non-secure side that makes a request to a secure service
(attempting to reenter), below is a possible use case of the reentrancy check:


.. code-block:: c

  psa_status_t ns_status = PSA_ERROR_CONNECTION_REFUSED;
  enum tfm_reenter_check_err_t reenter_status;
  os_status_t os_status;

  reenter_status = tfm_ns_check_safe_entry();
  if (reenter_status == TFM_REENTRANCY_CHECK_SUCCESS) {
      ns_status = psa_call(
          SERVICE_HANDLE,
          SERVICE_ID,
          in_vec, IOVEC_LEN(in_vec),
          out_vec, IOVEC_LEN(in_vec));
      if (ns_status != PSA_SUCCESS) {
          /* handle error */
      }

      /*
       * Release re-entry guard.
       * Must be called on the same call path after a successful secure entry.
       */
      tfm_ns_check_exit();
  } else {
      os_status = osThreadYield(); /* also possible osDelay(delayTime); */
      if (os_status != osOK) {
          /* handle error */
      }
  }

The RTOS yielding mechanism directly influences task scheduling and the
continuation of preempted secure services.
There may be better functions than the one shown above that allow to achieve the
sought scheduling sequence.


Limitations
===========

Currently Hybrid Platform is supported only for the IPC model.
Testing is limited.


--------------

*SPDX-License-Identifier: BSD-3-Clause*

*SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors*
