###########################
Musca-B1 Platform Specifics
###########################

****************
DAPLink Firmware
****************
The code on Musca-B1 is running from embededed flash. Make sure that the DAPLink
FW for eFlash is downloaded to the board. You can find on the
`Arm Community page <https://community.arm.com/developer/tools-software/oss-platforms/w/docs/425/musca-b1-firmware-update-qspi-boot-recovery>`__
A short description of how to update the DAPLink FW can be found there as well.

********************
Platform pin service
********************

This service is designed to perform secure pin services of the platform
(e.g alternate function setting, pin mode setting, etc).
The service uses the IOCTL API of TF-M's Platform Service, which allows the
non-secure application to make pin service requests on Musca B1 based on a
generic service request delivery mechanism.

--------------

*Copyright (c) 2017-2019, Arm Limited. All rights reserved.*
