#######
RD-1 AE
#######

************
Introduction
************

The **Arm Reference Design-1 AE**, or **RD-1 AE**, targets the Automotive
segment and introduces the concept of a high-performance  Arm\ :sup:`®`
Neoverse\ :sup:`TM` V3AE Application Processor (Primary Compute) system
augmented with an Arm\ :sup:`®` Cortex\ :sup:`®`-R82AE based Safety Island for
scenarios where additional system safety monitoring is required. The system
includes a Runtime Security Engine (RSE) used for the secure boot of the system
elements and the runtime Secure Services.

The RSE is the root of trust chain. It is the first booting element when
the system is powered up.

The RSE flash is used to store the images of various components, including:

* RSE BL2 image
* RSE Runtime image
* SCP RAM Firmware (SCP RAMFW) image
* Safety Island Cluster 0 (SI CL0) image
* Safety Island Cluster 1 (SI CL1) image
* Safety Island Cluster 2 (SI CL2) image

The RSE uses the application processor secure flash for:

* Application Processor TF-A BL2 (AP BL2) image

*********
Boot Flow
*********

Major steps of the boot flow:

1. RSE BL1_1:

   * Begins executing in place from ROM when the system is powered up
   * Provisions RSE BL1_2 and various keys and other data from the provisioning
     bundle to the OTP (This step only happens on the system's first boot)
   * Copies the RSE BL1_2 image from the OTP to the SRAM
   * Validates RSE BL1_2 against the hash stored in the OTP
   * Transfers the execution to RSE BL1_2

2. RSE BL1_2:

   * Copies the encrypted RSE BL2 image from the RSE flash into the SRAM
   * Decrypts the RSE BL2 image
   * Transfers the execution to RSE BL2

3. RSE BL2:

   * Copies the SCP RAMFW image from the RSE flash to SCP SRAM and authenticates
     the image
   * Releases the SCP out of reset
   * Copies the SI CL0 image from the RSE flash to SI LLRAM and authenticates
     the image
   * Notifies the SCP to power on the SI CL0
   * Copies the SI CL1 image from the RSE flash to SI LLRAM and authenticates
     the image
   * Notifies the SCP to power on the SI CL1
   * Copies the SI CL2 image from the RSE flash to SI LLRAM and authenticates
     the image
   * Notifies the SCP to power on the SI CL2
   * Copies the AP BL2 image from the AP secure flash to AP SRAM and
     authenticates the image
   * Notifies the SCP to power on the AP

*****
Build
*****

The official method of building the platform binaries is using Yocto. Follow
the instructions in `Arm Automotive Solutions User Guide`_.

You can also build the platform by following the instructions in
:doc:`Build instructions </building/tfm_build_instruction>` and building using
platform name: `arm/rse/automotive_rd/rd1ae`
``-DTFM_PLATFORM=arm/rse/automotive_rd/rd1ae``

**************************************
Arm Automotive Solutions Documentation
**************************************

For more information on **RD-1 AE**, refer to
`Arm Automotive Solutions Documentation`_.

.. note::

    Not all the RSE features and implementation have been upstreamed to
    Trusted Firmware-M yet.

*Copyright (c) 2024, Arm Limited. All rights reserved.*

.. _Arm Automotive Solutions Documentation: https://kronos-ref-stack.docs.arm.com/
.. _Arm Automotive Solutions User Guide: https://arm-auto-solutions.docs.arm.com/en/v1.1.1/user_guide/index.html
