###########################
Musca-B1 Platform Specifics
###########################

****************
DAPLink Firmware
****************
The code on Musca-B1 is running from embedded flash. Make sure that the DAPLink
FW for eFlash is downloaded to the board. You can find on the
`Arm Developer page <https://developer.arm.com/documentation/110409/0100/Musca-B1-firmware-update-and-boot-recovery>`__
A short description of how to update the DAPLink FW can be found there as well.

.. Note::
    Warm reset of eFlash is not supported on Musca_B1. TF-M may not boot after
    a warm reset. Further information on the hardware limitation can be
    found on `Arm Developer page <https://developer.arm.com/documentation/110409/0100/Musca-B1-warm-reset-of-eFlash>`__.

********************
Platform pin service
********************

This service is designed to perform secure pin services of the platform
(e.g alternate function setting, pin mode setting, etc).
The service uses the IOCTL API of TF-M's Platform Service, which allows the
non-secure application to make pin service requests on Musca B1 based on a
generic service request delivery mechanism.

********************
Musca B1 Default CPU
********************

Musca B1 is a dual core platform (being based on the `SSE-200 subsystem <https://developer.arm.com/documentation/101104/0200/introduction/about-the-sse-200>`__),
boot ROM code uses CPU0 running on 40.96MHz, while TF-M switches to CPU1 running on 163.84MHz.
An additional benefit to switching the default core is that CPU1 can access SRAM3
as Tightly Coupled Memory (TCM), while CPU0 can't.
When the core switch happens, CPU0 sleeps in a WFI loop to save power.

More information can be found in the following `patchset <https://review.trustedfirmware.org/c/TF-M/trusted-firmware-m/+/39616>`__.

--------------

*Copyright (c) 2017-2025, Arm Limited. All rights reserved.*
