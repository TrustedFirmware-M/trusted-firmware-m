RSE BL2 image binding
=====================

Overview
--------

Binding is a post-verification step that shifts authentication from asymmetric
signature checks to symmetric MAC-based checks by embedding authorisation into
the image metadata. Once bound, future boots can validate images with a MAC
instead of re-running the more expensive asymmetric operation.

RSE BL2 can **bind** boot images to a device-specific key so that subsequent
boots can authenticate the image without repeating the asymmetric verification
step. The binding key is stored in the KMU
(slot ``RSE_KMU_SLOT_SECURE_BINDING_KEY``) and referenced through the opaque
PSA key API at boot time. Binding information is recorded in the unprotected
MCUBoot TLV area of each image alongside the existing security counter TLV.

- With ``MCUBOOT_IMAGE_BINDING=ON`` BL2 will compute a binding tag the first
  time an image is loaded, write the tag and metadata TLVs back to flash, and
  reuse them on subsequent boots.
- Images that already carry binding TLVs are verified immediately after the RAM
  load step and before the usual signature verification path is taken.

CMAC binding for unencrypted images
-----------------------------------

When image encryption is disabled, BL2 computes an AES-CMAC over:

- the MCUBoot header fields that influence how the image is loaded
- the protected security counter TLV
- the full image payload

The resulting 16-byte CMAC is written to the ``IMAGE_TLV_BIND_TAG`` TLV and the
metadata TLV is updated to mark the binding as complete (algorithm
``RSE_BIND_CMAC_BOUND``). On subsequent boots, BL2 recomputes the CMAC in SRAM and
aborts booting the image if the recomputed CMAC does not match the stored tag.

CCM binding for encrypted images
--------------------------------

When both ``MCUBOOT_IMAGE_BINDING=ON`` and ``MCUBOOT_ENC_IMAGES=ON`` are set,
BL2 binds images using AES-CCM instead of CMAC:

1. BL2 reads the unprotected binding metadata and tag TLVs. If they are absent,
   BL2 prepares metadata in the ``IN_PROGRESS`` state with the CCM parameters
   (algorithm ``RSE_BIND_CCM_BOUND``, nonce and tag lengths) and writes it back
   to flash.
2. The image payload is re-encrypted in-place in flash using AES-CCM with:
   - Nonce length: 12 bytes (``RSE_BIND_CCM_IV_LEN``)
   - Tag length: 16 bytes (``RSE_BIND_CCM_TAG_LEN``)
   - Associated data: image ID, binding label, MCUBoot flags, version, and security counter
3. The generated CCM tag and final metadata (state ``BOUND``) are written to the
   binding TLVs. This is a one-time operation per image update.
4. On every boot the image is loaded to SRAM, then decrypted and authenticated
   using the stored nonce, associated data, and tag before the usual rollback
   check runs.

This flow keeps encrypted images bound to the device-specific key while avoiding
the cost of re-encrypting them on every boot, improving boot time after the
first run with binding enabled.

Operational notes
-----------------

- Binding operates on images that BL2 loads into SRAM (``MCUBOOT_RAM_LOAD``).
- The binding key must be provisioned in the KMU; builds using dummy
  provisioning will consume the dummy key material.
- If a binding verification fails (tag mismatch or CCM authentication failure),
  BL2 aborts the boot of that image and reports an error.

References
----------

- Implementation: ``platform/ext/target/arm/rse/common/bl2/rse_bl2_binding*.c``
- Boot integration hook: ``platform/ext/target/arm/rse/tc/common/bl2/boot_hal_bl2.c``

------

*SPDX-License-Identifier: BSD-3-Clause*

*SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors*
