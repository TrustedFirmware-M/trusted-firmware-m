TF-M Power Management Service design (RFC)
==========================================

:Organization: Arm Limited
:Contact: tf-m@lists.trustedfirmware.org

.. contents:: Table of Contents

Abstract
--------

This document describes the design of the TF-M Power Management Secure Service,
abbreviated as PWR-MGMT.
This service is optional.

.. note ::

    This is a Request For Feedback (RFC) and community is encouraged to provide feedback and comments.


Introduction
------------

The PWR-MGMT service provides a secure endpoint to perform power management
operations for the core itself, devices and peripherals, and other cores.

When peripheral power and clock controls are mapped to SPE, then this service
can access such resources and query or change the status of them.

The partition brokers power-management requests from NS/S clients to SPE.


Components
----------

The whole functionality is achieved by combining three parts:
  - Service: secure_fw/partitions/power_mgmt/
  - NS/S client API:
    ``interface/include/power_mgmt/tfm_power_mgmt_api.h`` and
    ``interface/src/tfm_power_mgmt_api.c``
  - Platform code/hooks:
    ``platform/include/tfm_plat_power_mgmt.h`` and
    ``tfm_plat_power_mgmt.c`` and
    ``tfm_plat_power_mgmt_defs.h``


Service description
-------------------

The service provides a generic implementation for some of the CPU power and
operating modes as described by the Cortex-M55 TRM [1]_, Power mgmt section
(the same applies to Cortex-M85).

Note that each individual platform has the flexibility to implement power states
and domains arbitrarily so the generic implementation, albeit functional, may
need to be extended by custom platform code. This can be done via the provided
callback hooks.

The service is implemented as stateless and allows mm-iovec mapping.
Note that for cpu power states the call is blocking as it affects its own
processing, while for custom states, that depends on the hooks' implementation.


Power states groups
^^^^^^^^^^^^^^^^^^^

There are two classes of power states exposed by the service:
  - PWR_STATE_<OFF, SLEEP, DEEPSLEEP, SUSPEND, HIBERNATE>
  - PWR_STATE_CUSTOM_<any>

+---------------------+--------------------------------------------------------+
| Power state group   |                                                        |
| TFM_POWER_MGMT_PWR\_| CPU power state applied                                |
+=====================+========================================================+
| STATE_OFF           | OFF                                                    |
+---------------------+--------------------------------------------------------+
| STATE_SLEEP         | ON (unchanged)                                         |
+---------------------+--------------------------------------------------------+
| STATE_DEEPSLEEP     | ON (unchanged)                                         |
+---------------------+--------------------------------------------------------+
| STATE_SUSPEND       | MEM_RET (Cache)                                        |
+---------------------+--------------------------------------------------------+
| STATE_HIBERNATE     | OFF                                                    |
+---------------------+--------------------------------------------------------+
| STATE_CUSTOM        | CPU power state is unchanged                           |
|                     | This groups is to support custom states i.e. to control|
|                     | power or clocks of peripherals or similar              |
+---------------------+--------------------------------------------------------+


CPU STATES
^^^^^^^^^^

For general cpu power state transitions, the flow is usually as below. The
platform code can be plumbed in to support extra features before and after the
state transition.
This is because the cpu power state transitions are forced through the WFI/WFE
instructions.

Simple flow::

  ┌────────┐      ┌───────────┐      ┌──────────┐      ┌──────────┐
  │ caller │ ---> │ pwr-mgmt  │ ---> │ pwr-mgmt │ ---> │ platform │
  │        │ <--- │ interface │ <--- │ service  │ <--- │ code     │
  └────────┘      └───────────┘      └──────────┘      └──────────┘
                                          ^
                                          |
                                          v
                                      ┌────────┐
                                      │ POWER  │
                                      │ STATE  |
                                      | CHANGE │
                                      └────────┘


+---------------------+--------------------------------------------------------+
| TFM_POWER_MGMT_PWR\_| Description                                            |
| Power state         |                                                        |
+=====================+========================================================+
| STATE_SLEEP         | Simply performs WFx                                    |
| (shallowest)        | For shallow modes with callbacks                       |
+---------------------+--------------------------------------------------------+
| STATE_DEEPSLEEP     | Performs WFx with SCR.SLEEPDEEP set                    |
|                     | For shallow modes with callbacks & platform-hw         |
|                     | additional intervention                                |
+---------------------+--------------------------------------------------------+
| STATE_SUSPEND       | Performs CPU power-off with memory retention           |
|                     | The service save and restore the context of the CPU.   |
|                     |                                                        |
|                     | This state is described as MEM_RET in the Cortex-M TRM |
|                     | Requires a platform-capable PDRAMS power domain        |
+---------------------+--------------------------------------------------------+
| STATE_HIBERNATE     | Turns OFF the cpu domains. Callbacks are expected to   |
| (deepest)           | enable and re-route the WIC to allow power-up          |
|                     |                                                        |
|                     | Does not return, the CPU starts from reset.            |
+---------------------+--------------------------------------------------------+

Each power state transition can be selected with the choice of either wait for
interrupt or wait for event, via a call parameter.

+----------------------+-------------------------------------------------------+
| TFM_POWER_MGMT_WAIT\_| Description                                           |
|                      |                                                       |
+======================+=======================================================+
| FOR_EVENT            | Performs WFE, then wait for:                          |
|                      | interrupts transitioning from the inactive to the     |
|                      | pending state that target that security state are     |
|                      | wakeup events                                         |
|                      | SEV instruction by any other PE in the same           |
|                      | multiprocessor system                                 |
|                      | Any exception at a priority that would preempt the    |
|                      | current execution priority                            |
|                      | A debug event, any IMP_DEF event, a Warm reset        |
+----------------------+-------------------------------------------------------+
| FOR_INTERRUPT        | Performs WFI, then wait for:                          |
|                      | Any asynchronous exception at a priority that would   |
|                      | preempt any currently active exceptions (see PRIMASK) |
|                      | A debug event, any IMP_DEF event, a Warm reset        |
+----------------------+-------------------------------------------------------+
| FOR_NONE             | Performs neither. Only valid for custom states        |
+----------------------+-------------------------------------------------------+


NON-CPU STATES
^^^^^^^^^^^^^^

These states do not involve any changes in the CPU, they are intended to be
exclusively callback-controlled.

Examples: Crypto HW engine, LCD display, etc.

For non-cpu power state transitions, the platform code will ultimately drive the
power state change, for example via setting registers, PPUs or scaling voltage.

The service will not alter the CPU power states::

  ┌────────┐      ┌───────────┐      ┌──────────┐      ┌──────────┐      ┌────────┐
  │ caller │ ---> │ pwr-mgmt  │ ---> │ pwr-mgmt │ ---> │ platform │ <--> │ POWER  │
  │        │ <--- │ interface │ <--- │ service  │ <--- │ code     │      │ STATE  |
  └────────┘      └───────────┘      └──────────┘      └──────────┘      | CHANGE │
                                                                         └────────┘


CALLBACKS
^^^^^^^^^

For each power state transitions, platform code can be hooked in via the callbacks,
in both pre and post state transitions.

Platform code can provide a table of calbacks on a per-state basis.

Callbacks are *optional*.

Callbacks define a policy that applies to each: graceful or forceful.
When the callback is performed but does not complete successfully, the service
needs to know if abort the entire sequence or carry on.
If the policy is ``POLICY_GRACEFUL``, then the sequence carries on.
If the policy is ``POLICY_FORCEFUL```, then the sequence is interrupted and the
power transition does not take place.

This policy is configurable for each callback.

The order of callback is important.

To keep the implementation simple the integrators should ensure that the table
of callbacks is set up correctly and ordered.
The expectation from the service is that the order by which the callbacks are
presented matters.
Assume that for a state change operation A needs to take place before
operation B. When the state change is to be reversed, operation B must take
place before operation A.

Simply::
    custom_power_state_request
        -> ops_A -> ops_B
         -> state_change -> event
             -> ops_B -> ops_A -> call_complete

To achieve the above there is no explicit configuration for the different ops
but rather the order of callbacks inside the table determines it.
Alternatively, the order can be achieved within the same callback(s).

See examples below.


Service API description
-----------------------

The service exposes an interface that secure and non-secure callers can use.

The API interface defines a number of generic power states for the core itself
but also allows custom states to be added for system-wide or platform
peripherals.
Platform code is expected to implement the supported callbacks for the listed
power states.

To request a state transition:

.. code-block:: c

    enum tfm_power_mgmt_err_t tfm_power_mgmt_set_state(
        enum tfm_power_mgmt_power_state_t pwr_state,
        uint32_t wait_for);


The API ``tfm_power_mgmt_set_state()`` validates pwr_state and call_type,
packages struct tfm_power_mgmt_set_params, and calls
`TFM_POWER_MGMT_SERVICE_HANDLE`.

To probe a (custom) power state:

.. code-block:: c

    enum tfm_power_mgmt_err_t tfm_power_mgmt_get_state(
        uint32_t device_id,
        int32_t *state);


The API ``tfm_power_mgmt_get_state()`` validates the device_id against the
platform-defined `PLAT_POWER_MGMT_DEVICE_ID_MAX`, and calls
`TFM_POWER_MGMT_SERVICE_HANDLE`.


Configuration parameters
------------------------

To enable the partition in the build, use TFM_PARTITION_POWER_MGMT so that all
the relevant interface code will be made available to NS callers.

By default, the service is disabled.

The service supports CPU power states only for CM55 & CM85
via the internal build-derived TFM_POWER_MGMT_ARCH_SUPPORTED option.
For other cores, the service only supports CUSTOM power state transitions.

Non-M55/M85 platforms can still use custom/device states through callbacks,
but generic CPU states are not supported.


Examples: Integration
---------------------

  1. Add the partition TFM_PARTITION_POWER_MGMT manifest entry into the
     platform's manifest list
  2. Add tfm_plat_power_mgmt.c source to `platform_s` build target,
     conditionally on TFM_PARTITION_POWER_MGMT
  3. Set TFM_PARTITION_POWER_MGMT to 'ON' in config.cmake
  4. Provide a minimal (at least) implementation of the required APIs in
     platform/ext/target/<platform>/<variant>/ps_service/tfm_plat_power_mgmt.c
  5. Provide a header file with definitions for
     TFM_POWER_MGMT_PWR_STATE_CUSTOM
     TFM_POWER_MGMT_PWR_STATE_DEVICE_CUSTOM
     in platform/ext/target/<platform>/<variant>/tfm_plat_power_mgmt_defs.h
  6. Configure wake sources and secure interrupt routing for needed states.
  7. Validate retained memory placement if SUSPEND is supported.


Examples: Minimal required APIs implementation
----------------------------------------------

.. code-block:: c

    void platform_power_mgmt_get_power_table(
        const struct plat_power_mgmt_set_state_callback_settings_t **callbacks,
        size_t *callbacks_count)
    {
        *callbacks_count = 0;
        return;
    }

    enum tfm_power_mgmt_err_t platform_power_mgmt_get_retention_memory(
        volatile uint32_t **mem_addr,
        size_t mem_size)
    {
    #if PLATFORM_WITH_RETAINED_MEMORY
        mem_size = SIZE_OF_RETAINED_MEMORY;
        *mem_addr = ADDRESS_OF_RETAINED_MEMORY;
    #else
        *mem_addr = NULL;
    #endif
        return TFM_POWER_MGMT_ERR_SUCCESS;
    }


With a header file `tfm_plat_power_mgmt_defs.h``

.. code-block:: c

    #define TFM_POWER_MGMT_PWR_STATE_CUSTOM         0

    #define SIZE_OF_RETAINED_MEMORY                 0

    #define PLAT_POWER_MGMT_DEVICE_ID_MAX           0


Examples: APIs implementation and order of execution
----------------------------------------------------

.. code-block:: c

    /* callbacks need to be sorted per-state */
    static const struct plat_power_mgmt_set_state_callback_settings_t
        plat_callbacks[] = {
        {
            .state = TFM_POWER_MGMT_PWR_STATE_CUSTOM_1,
            .pre_cb = &pre_state_custom_1a,
            .post_cb = &post_state_custom_1b,
            .policy = TFM_POWER_MGMT_PWR_POLICY_GRACEFUL,
        },
        {
            .state = TFM_POWER_MGMT_PWR_STATE_CUSTOM_1,
            .pre_cb = &pre_state_custom_1b,
            .post_cb = &post_state_custom_1b,
            .policy = TFM_POWER_MGMT_PWR_POLICY_FORCEFUL,
        },
    };

In the example above, entering the power state transition pre_state_custom_1b
follows pre_state_custom_1a, while exiting the state post_state_custom_1b
preceeds post_state_custom_1b.


Examples: Call through TZ
-------------------------

.. code-block:: c

    #include "power_mgmt/tfm_power_mgmt_api.h"

    enum tfm_power_mgmt_err_t err;
    int32_t device_state;

    err = tfm_power_mgmt_set_state(
        TFM_POWER_MGMT_PWR_STATE_SUSPEND,
        TFM_POWER_MGMT_WAIT_FOR_INTERRUPT);
    if (err != TFM_POWER_MGMT_ERR_SUCCESS) {
        /* handle error */
    }

    /* custom state */
    err = tfm_power_mgmt_set_state(
        PLATFORM_CUSTOM_STATE_1,
        TFM_POWER_MGMT_WAIT_FOR_NONE);
    if (err != TFM_POWER_MGMT_ERR_SUCCESS) {
        /* handle error */
    }

    err = tfm_power_mgmt_get_state(
        plat_device_id,
        &device_state);
    if (err != TFM_POWER_MGMT_ERR_SUCCESS) {
        /* handle error */
    }

Examples: Call through MAILBOX (direct call)
--------------------------------------------

.. code-block:: c

    #include <psa_manifest/sid.h>

    struct psa_invec pm_in_vec[1];
    size_t pm_inlen = 1;
    struct tfm_power_mgmt_set_params pm_params = {
        .call_type = TFM_POWER_MGMT_SET,
        .pwr_state = TFM_POWER_MGMT_PWR_STATE_<STATE>,
        .wait_for = TFM_POWER_MGMT_WAIT_FOR_EVENT,
    };
    pm_in_vec[0].base = &pm_params;
    pm_in_vec[0].len = sizeof(pm_params);

    status = psa_call(
            TFM_POWER_MGMT_SERVICE_HANDLE,
            TFM_MAILBOX_PSA_CALL,
            pm_in_vec, pm_inlen,
            NULL, 0);
    if (status != PSA_SUCCESS) {
        /* handle error */
    }

The internal implementation of psa_call to TF-M will need to set
psa_call_params.type to PSA_IPC_CALL.


THREAT MODEL REVIEW
-------------------

TODO once implementation has consolidated.

Assets
^^^^^^

Trust boundary
^^^^^^^^^^^^^^

Risks
^^^^^

Mitigations
^^^^^^^^^^^


References
----------

.. [1] `Arm® Cortex®-M55 Processor Technical Reference Manual <https://support.arm.com/documentation/101051/0101/?lang=en>`_


--------------

*SPDX-License-Identifier: BSD-3-Clause*

*SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors*
