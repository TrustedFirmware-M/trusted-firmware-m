##################################
Secure Interrupt Integration Guide
##################################

************
Introduction
************

This document describes how to enable an interrupt in TF-M. The target audiences
are mainly platform integrators and Secure Partition developers.

This document assumes that you have read the PSA Firmware Framework (FF-M) v1.0
[1]_ and the FF-M v1.1 extensions [2]_ thus have knowledge on the terminologies
such as Secure Partitions and manifests.

************************
Interrupt Handling Model
************************

TF-M supports the two interrupt handling models defined by FF-M:

- First-Level Interrupt Handling (FLIH)

  In this model, the interrupt handling is carried out immediately when the
  interrupt exception happens.

  The interrupt handling can optionally set an interrupt signal for the Secure
  Partition Thread to have further data processing.

- Second-Level Interrupt Handling (SLIH)

  In this model, the interrupt handling is deferred after the interrupt
  exception. The handling occurs in the Secure Partition Thread thus is subject
  to scheduling.

The FLIH supports handling an interrupt in a bounded time, but very limited APIs
are allowed in the FLIH handling because the handling occurs in an special
exception context.

The SLIH is deferred and subject to scheduling but all Secure Partition APIs are
allowed as the SLIH handling is in the Secure Partition Thread.

Both the FLIH and the SLIH can be used by Secure Partitions which conform to
Firmware Framework v1.1.

While the SLIH is the only supported model for Secure Partitions which conform
to Firmware Framework v1.0.

Please refer to chapter 6.2 of FF-M v1.1 [1]_ for more details on the interrupt
handling models.

*********************
Enabling an Interrupt
*********************

To enable an interrupt, you need to do the following:

- Binding the interrupt to a Secure Partition.
- Granting the Secure Partition access permissions to the device of the
  interrupt.
- Initializing the interrupt.
- Integrating the interrupt handling function

TF-M has two Test Partitions as good examples for both FLIH [3]_ and SLIH [4]_.
See also `Enabling the Interrupt Tests`_ on how to integrate them to platforms.

Binding an Interrupt to a Secure Partition
==========================================

To bind an interrupt to a Secure Partition, you need to add an item to the
``irqs`` attribute of the Secure Partition manifest.
``irqs`` is a list of Interrupt Request (IRQ) assigned to the Secure Partition.

Secure Partitions are not allowed to share IRQs with other Secure Partitions.

Different Firmware Framework versions have different definitions of manifest.

FF-M v1.0
---------

Here is an example manifest of Secure Partitions conform to Firmware Framework
version 1.0:

.. code-block:: yaml

  {
    "irqs": [
      {
        "source": 5,
        "signal": "DUAL_TIMER_SIGNAL"
      },
      {
        "source": "TIMER_1_SOURCE",
        "signal": "TIMER_1_SIGNAL"
      }
    ]
  }

- source

  Required, Unique.

  The ``source`` is a string that identifies the interrupt source.
  It can be a valid exception number or a symbolic name defined in platform codes.

- signal

  Required, Unique.

  The ``signal`` attribute is a symbolic name used by TF-M to identify which
  interrupt is asserted.
  It is also used by the Secure Partition to receive the interrupt signal by
  calling ``psa_wait`` for interrupt handling.

  It is defined in the Secure Partition header file
  ``<psa_manifest/manifestfilename.h>`` generated by TF-M:

  .. code-block:: c

    #define signal VALUE

The interrupt handling model is SLIH by default as it is the only supported one
for FF-M v1.0.

FF-M v1.1
---------

Here is an example manifest of Secure Partitions conform to Firmware Framework
version 1.1:

.. code-block:: yaml

  {
    "irqs": [
      {
        "source"  : "TIMER_1_SOURCE",
        "name"    : "TIMER_1",
        "handling": "FLIH"
      },
      {
        "source"  : 5,
        "name"    : "DUAL_TIMER",
        "handling": "SLIH"
      }
    ]
  }

- source

  The ``source`` is the same as the one in Firmware Framework Version 1.0.

- name

  Required, Unique.

  The ``name`` is used to construct the following two elements:

  - the interrupt signal symbol: ``{{name}}_SIGNAL``, the equivalent of
    ``signal`` in FF-M v1.0
  - the FLIH Function for handling ``FLIH`` IRQs provided by Secure Partition:

    ``psa_flih_result_t {{name}}_flih(void);``

    It is also declared in ``<psa_manifest/manifestfilename.h>``.

- handling

  Required.

  The ``handling`` attribute specifies the interrupt handling model and must
  have one of the following values:

  - ``FLIH`` - First-Level Interrupt Handling
  - ``SLIH`` - Second-Level Interrupt Handling

Granting Permissions to Devices for Secure Partitions
=====================================================

A secure partition shall be granted two parts of permissions to access a device.
One is the Memory Mapped I/O (MMIO) region of the device. The other is the driver
codes to access the device.

The MMIO Regions
----------------

You need to declare the MMIO region in the ``mmio_regions`` attributes in the
Secure Partition manifest, to enable the Secure Partition to access it.

An MMIO region can be described as either ``numbered_region`` or
``named_region``.
A numbered region consists of a ``base`` address and a ``size``.
A named region consists of a string ``name`` to describe the region.

Here is an example of named region:

.. code-block:: yaml

  {
    "mmio_regions": [
      {
        "name": "TFM_PERIPHERAL_TIMER0",
        "permission": "READ-WRITE"
      }
    ]
  }

- name

  Required.

  The ``name`` attribute is a symbolic name defined by platforms.
  It is a pointer to structure instance that usually includes the base address
  and size of the region and some other platform specific attributes that are
  required to set up permissions to the MMIO region.

  The structure is defined by platforms and the name must be
  ``struct platform_data_t``.

- permission

  Required.

  The ``permission`` attribute must have one of the following values:

  - ``READ-ONLY``
  - ``READ-WRITE``

The Device Drivers
------------------

To give permissions of devices drivers to Secure Partitions, it is recommended
to put the driver codes to the Partition's CMake library:

.. code-block:: bash

  target_sources(some_partition_lib
      PRIVATE
          some_driver_code.c
  )

Initializing the Interrupts
===========================

Platforms must define an interrupt initialization function for each Secure
interrupt.

The prototype of the function is:

.. code-block:: c

  enum tfm_hal_status_t {source_symbol}_init(void *p_pt,
                                             const struct irq_load_info_t *p_ildi)

The ``{source_symbol}`` is:

- ``irq_{source}``, if the ``source`` attribute of the IRQ in Partition manifest
  is a number
- Lowercase of ``source`` attribute, if ``source`` is a symbolic name

For example if the manifest declares ``"source": 5``, then the function name
is ``irq_5_init``.
If the manifest declares ``"source"  : "TIMER_1_IRQ"`` then the function
name is ``timer_1_irq_init``.

The function will be called by the Framework automatically during
initialization. The function can be put in any source file that belongs to SPM,
for example a ``tfm_interrupts.c`` added to the ``tfm_spm`` CMake target.

The initialization of an interrupt must include:

- setting the priority
- ensuring that the interrupt targets the Secure State.
- saving the interrupt information

Setting Priority
----------------

The priority of external interrupts must be in the following range:
``(0, N / 2)``, where ``N`` is the number of configurable priorities.
Smaller values have higher priorities.

For example if the number of configurable priority of your interrupt controller
is 16, you must use the priorities in range ``(0, 8)`` only, boundaries
excluded.

Note that these are not the values set into the interrupt controllers.
Different platforms may have different values for those priorities.
But if you use the ``NVIC_SetPriority`` function provided by CMSIS to set
priorities, you can pass the values directly.

Platforms have the flexibilities on the assignment of priorities.

Targeting Interrupts to Secure
------------------------------

In single core systems, platform integrators must ensure that the Secure
interrupts target to Secure State by setting the Interrupt Controller.

In multi-core systems, this might be optional.

Saving the Interrupt Information
--------------------------------

The initialization function is called during Partition loading with the
following information:

- ``p_pt`` - pointer to Partition runtime struct of the owner Partition
- ``p_ildi`` - pointer to ``irq_load_info_t`` struct of the interrupt

Platforms must save the information for the future use.
See `Integrating the Interrupt Handling Function`_ for the usage.

The easiest way is to save them in global variables for each interrupt.
TF-M provides a struct for saving the information:

.. code-block:: c

  struct irq_t {
      void                         *p_pt;
      const struct irq_load_info_t *p_ildi;
  };

Integrating the Interrupt Handling Function
===========================================

TF-M provides an interrupt handling entry for Secure interrupts:

.. code-block:: c

  void spm_handle_interrupt(void *p_pt, const struct irq_load_info_t *p_ildi)

The ``p_pt`` and ``p_ildi`` are the information passed to interrupt
initialization functions and saved by platforms.

Platforms should call this entry function in the interrupt handlers held in
Vector Table with the information saved by the interrupt initialization
functions.
If the information is saved as global variables, then the interrupt handlers can
be put in the same source file that contains the initialization functions.

Here is an example:

.. code-block:: c

  void TFM_TIMER0_IRQ_Handler(void) /* The handler in Vector Table */
  {
      spm_handle_interrupt(p_timer0_pt, p_tfm_timer0_irq_ldinf);
  }

****************************
Enabling the Interrupt Tests
****************************

TF-M provides test suites for FLIH and SLIH interrupts respectively.
They are disabled by default.

.. note::

  FLIH interrupt test and SLIH interrupt test share the same timer
  ``TFM_TIMER0_IRQ`` thus cannot be enabled at the same time.

To enable the tests, please follow steps in the previous sections.
In addition, you need to implement the following APIs of timer control:

- ``void tfm_plat_test_secure_timer_start(void)``
- ``void tfm_plat_test_secure_timer_clear_intr(void)``
- ``void tfm_plat_test_secure_timer_stop(void)``

You shall also select the following flags in platform specific ``config.cmake``
to indicate that FLIH and SLIH interrupt tests are supported respectively.

- ``PLATFORM_FLIH_IRQ_TEST_SUPPORT``: platform implements support of FLIH
  interrupt tests
- ``PLATFORM_SLIH_IRQ_TEST_SUPPORT``: platform implements support of SLIH
  interrupt tests

The following configurations control SLIH and FLIH interrupt tests:

- ``TEST_NS_FLIH_IRQ``
- ``TEST_NS_SLIH_IRQ``

They can be enabled via build command line or via ``TEST_NS``.

************************************
Migrating to Firmware Framework v1.1
************************************

Please refer to ``Migrating Secure Partitions to version 1.1`` of FF-M v1.1 [1]_
.

**********
References
**********

.. [1] `FF-M v1.0 Specification <https://developer.arm.com/documentation/den0063/latest/>`__

.. [2] `FF-M v1.1 Extension <https://developer.arm.com/documentation/aes0039/latest/>`__

.. [3] https://git.trustedfirmware.org/plugins/gitiles/TF-M/tf-m-tests.git/+/HEAD/tests_reg/test/secure_fw/suites/spm/irq/service/tfm_flih_test_service/

.. [4] https://git.trustedfirmware.org/plugins/gitiles/TF-M/tf-m-tests.git/+/HEAD/tests_reg/test/secure_fw/suites/spm/irq/service/tfm_slih_test_service/

--------------

*Copyright (c) 2021-2024, Arm Limited. All rights reserved.*
*Copyright (c) 2022 Cypress Semiconductor Corporation (an Infineon company)
or an affiliate of Cypress Semiconductor Corporation. All rights reserved.*
