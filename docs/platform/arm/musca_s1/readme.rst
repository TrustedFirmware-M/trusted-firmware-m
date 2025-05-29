###########################
Musca-S1 Platform Specifics
###########################

****************
DAPLink Firmware
****************
The code on Musca-S1 is running from on-chip eMRAM (2MB non-volatile bootable memory).
Make sure that the DAPLink FW for QSPI/MRAM is downloaded to the board. You can find on the
`Arm Community page <https://community.arm.com/oss-platforms/w/docs/463/musca-s1-firmware-update-qspi-mram-boot-recovery>`__
A short description of how to update the DAPLink FW can be found there as well.

********************
Platform pin service
********************

This service is designed to perform secure pin services of the platform
(e.g alternate function setting, pin mode setting, etc).
The service uses the IOCTL API of TF-M's Platform Service, which allows the
non-secure application to make pin service requests on Musca S1 based on a
generic service request delivery mechanism.

********************
Musca S1 Default CPU
********************

Musca S1 is a dual core platform (being based on the `SSE-200 subsystem <https://developer.arm.com/documentation/101104/0200/introduction/about-the-sse-200>`__),
boot ROM code uses CPU0 running on 50MHz, while TF-M switches to CPU1 running on 200MHz.
An additional benefit to switching the default core is that CPU1 can access SRAM3
as Tightly Coupled Memory (TCM), while CPU0 can't.
When the core switch happens, CPU0 sleeps in a WFI loop to save power.

More information can be found in the following `patchset <https://review.trustedfirmware.org/c/TF-M/trusted-firmware-m/+/38198/3>`__.

--------------

*Copyright (c) 2023, Arm Limited. All rights reserved.*
