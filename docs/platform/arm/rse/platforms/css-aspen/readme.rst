#########
CSS-Aspen
#########

************
Introduction
************

The **Arm CSS-Aspen** introduces the concept of a high-performance |Cortex|-A720AE
Application Processor (Primary Compute) system augmented with an |Cortex|-R82AE
based Safety Island and real-time domain for scenarios where additional system
safety monitoring and real-time services are required. The system additionally
includes a Runtime Security Engine (RSE) used for the secure boot of the system
elements and the runtime Secure Services.

RSE is the root of trust chain. It is the first booting element when the system
is powered up.

The RSE flash is used to store the images of various components, including:

* RSE BL2 image
* RSE Runtime image
* SI0 RAMFW image

RSE loads the following image(s) from the application processor secure flash:

* Application Processor BL2 (AP BL2) image

*********
Boot Flow
*********

Major steps of the boot flow:

1. RSE BL1_1:

   * Begins executing in place from ROM when the system is powered up
   * Provisions RSE BL1_2 and various keys and other data from the provisioning
     bundle to the OTP (this step only happens on the system’s first boot)
   * Copies the RSE BL1_2 image from the OTP to the RSE SRAM
   * Validates RSE BL1_2 against the hash stored in the OTP
   * Computes RSE BL1_2 image measurement
   * Transfers the execution to RSE BL1_2

2. RSE BL1_2:

   * Copies the encrypted RSE BL2 image from the RSE flash into the RSE SRAM
   * Decrypts the RSE BL2 image
   * Validates the RSE BL2 image
   * Computes RSE BL2 image measurement
   * Transfers the execution to RSE BL2

3. RSE BL2:

   * Copies the SI CL0 image from the RSE flash to SI LLRAM and authenticates
     the image
   * Computes SI CL0 image measurement
   * Powers on the SI CL0
   * Copies the Application Processor (AP) BL2 image from AP secure flash to AP shared SRAM
   * Computes AP BL2 image measurement
   * Copies RSE Runtime image from the RSE flash to the RSE SRAM
   * Computes RSE Runtime image measurement
   * Sends notification to SI CL0 that SCP-firmware can turn on AP
   * Jumps to RSE Runtime in the RSE SRAM

*****
Build
*****

The official method of building the platform binaries is using Yocto. Follow
the instructions in `Arm Automotive Solutions User Guide`_.

You can also build the platform by following the instructions in
:doc:`Build instructions </building/tfm_build_instruction>` and building using
platform name: `arm/rse/automotive_rd/css-aspen`
``-DTFM_PLATFORM=arm/rse/automotive_rd/css-aspen``

**************************************
Arm Automotive Solutions Documentation
**************************************

For more information on **CSS-Aspen**, refer to
`Arm Automotive Solutions Documentation`_.

.. note::

    Not all RSE features and implementation have been upstreamed to
    Trusted Firmware-M yet.

*Copyright (c) 2025, Arm Limited. All rights reserved.*

.. _Arm Automotive Solutions Documentation: https://arm-auto-solutions.docs.arm.com
.. _Arm Automotive Solutions User Guide: https://arm-auto-solutions.docs.arm.com/en/v2.0/rd-aspen/index.html
.. |Cortex| replace:: Arm :sup:`®` Cortex :sup:`®`
