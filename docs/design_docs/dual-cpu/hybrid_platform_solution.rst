#########################################
Scheduling for a Hybrid Platform Solution
#########################################

:Organization: Arm Limited
:Contact: tf-m@lists.trustedfirmware.org

.. Warning::
  This feature is currently in EXPERIMENTAL and DEVELOPMENT stage.
  Documentation, support and testing is limited.

  Please provide any feedback or comments via the TF-M mailing list or in the
  review.trustedfirmware.org topic
  `hybrid-plat-nspe <https://review.trustedfirmware.org/q/topic:%22hybrid-plat-nspe%22>`_


************
Introduction
************

The Hybrid Platform solution is an extension of the Dual-CPU systems [1]_
already supported in TF-M.
A Hybrid Platform solution requires applications to run from both local and
remote clients.
This inevitably brings some scheduling trade-off and limitations on the table.

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

It would usually look like this:

.. code-block:: output

        ┌──────────────────┐        ┌──────────────────┐
      ┌──────────────────┐ │        │┌────────────────┐│
    ┌──────────────────┐ │ │        ││                ││
    │                  │ │ │        ││                ││
    │                  │ │ │        ││      TF-M      ││
    │                  │ │ │        ││                ││
    │                  │ │ │        ││                ││
    │                  │ │ │        │└────────────────┘│
    │                  │ │ │        │                  │
    │                  │ │ │ >MBOX< │ --TZ boundary--- │
    │                  │ │ │        │                  │
    │                  │ │ │        │┌────────────────┐│
    │                  │ │ │        ││                ││
    │  remote client   │ │ │        ││  local client  ││
    │                  │ │ │        ││                ││
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
|               | the M-Class and in one or more other identical M-Class cores |
+---------------+--------------------------------------------------------------+
| Remark:                                                                      |
| When the M-Class core hosting the Secure World does NOT have a Normal World, |
| then the solution is a Dual-CPU System [1]_.                                 |
+------------------------------------------------------------------------------+


********************
Scheduling Scenarios
********************

There are routinely two sets of scheduling use-cases depending on how the
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
|                                   | good time to give up cycles to execute the mailbox       |
|                                   | requests.                                                |
|                                   |                                                          |
|                                   | To do so, NSPE performs a psa_call to a stateless service|
|                                   | in the mailbox partition and let the execution to proceed|
|                                   | in SPE.                                                  |
|                                   | Note that the local NSPE does not have knowledge of any  |
|                                   | pending messages in the mailbox awaiting for processing. |
|                                   | It can only start their processing.                      |
|                                   |                                                          |
+-----------------------------------+----------------------------------------------------------+
| TFM_HYBRID_PLAT_SCHED_BALANCED    | Not yet implemented!                                     |
|                                   |                                                          |
|                                   | It will provide a build-time configurable trade-off      |
|                                   | between the two options above.                           |
|                                   |                                                          |
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
as follow:


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

Such mechanism should drive the main application to initialize either the
interfaces, where the API broker is configured for the correct execution
environment.

See an example below.


.. code-block:: c

  #define EXEC_TARGET_LOCAL  true
  #define EXEC_TARGET_REMOTE false
  bool plat_is_this_client_local(void)
  {
      /*
       * Some implementation-defined mechanism to detect the execution target.
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


Limitations
===========

Currently Hybrid Platform is supported only for the IPC model.


**********
References
**********

.. [1] :doc:`Dual-CPU <index>`

--------------

*SPDX-License-Identifier: BSD-3-Clause*

*SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors*
