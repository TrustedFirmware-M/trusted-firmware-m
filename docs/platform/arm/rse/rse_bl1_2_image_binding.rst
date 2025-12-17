RSE BL1_2 image binding
===========================

Overview
--------

BL1_2 can bind the BL2 image to a device-unique key so that subsequent
boots can authenticate the image without repeating the asymmetric verification
step. A 16-byte binding tag is stored in the ``binding_tag`` field of the BL2
image header. The tag is produced with a key derived from the hardware unique
key (HUK) and kept in the KMU slot ``RSE_KMU_SLOT_SECURE_BINDING_KEY`` (and its
adjacent reserve slot for AEAD).

When ``TFM_BL1_2_IMAGE_BINDING=ON`` the BL1_1 boot flow provisions the binding
key (``rse_setup_image_binding_key()``) and BL1_2 selects a binding mode based
on whether BL2 encryption is enabled.

Configuration
-------------

- ``TFM_BL1_2_IMAGE_BINDING`` (default: OFF) enables the binding flow and
  extends the BL2 header with the binding tag field.
- Binding with encrypted BL2 images also requires
  ``TFM_BL1_2_IMAGE_ENCRYPTION=ON``. In this mode BL1_2 uses AES-CCM for both
  authentication and on-flash ciphertext generation.

Unencrypted BL2 (TFM_BL1_2_IMAGE_ENCRYPTION=OFF)
------------------------------------------------

First boot:

- BL1_2 copies BL2 to SRAM and performs the usual asymmetric verification.
- It hashes the ``protected_values`` structure with SHA-256 and then computes
  an AES-CMAC over that hash using the binding key.
- The 16-byte tag is written to the BL2 header in flash via
  ``bl1_2_store_image_binding_tag()``.

Subsequent boots:

- If the binding tag is non-zero, BL1_2 recomputes the CMAC in SRAM and
  compares it against the stored tag.
- A successful match skips asymmetric verification; BL1_2 proceeds to the
  security counter checks. A mismatch falls back to the standard signature
  verification path.

Encrypted BL2 (TFM_BL1_2_IMAGE_ENCRYPTION=ON)
---------------------------------------------

First boot:

- BL1_2 decrypts BL2, verifies the signature, then re-encrypts the
  ``protected_values`` region in place using AES-CCM with the binding key.
- The CCM nonce comes from ``header.ctr_iv`` (12 bytes) and a 16-byte tag is
  produced. Flash is rewritten in streaming fashion so only a sector-sized
  buffer is needed.
- The CCM tag is stored in the BL2 header's ``binding_tag`` field.

Subsequent boots:

- BL1_2 reads the header, streams the bound ciphertext into SRAM, and performs
  AES-CCM decryption and tag verification with the stored nonce and binding
  key. Asymmetric signature verification is skipped when the tag is valid.
- If CCM authentication fails, boot of that BL2 image is aborted.

Key handling
------------

- ``rse_setup_image_binding_key()`` (``platform/ext/target/arm/rse/common/bl1/rse_kmu_keys.c``)
  derives the binding key from HUK with the label
  ``"BL1_2_IMAGE_BINDING_KEY_DERIVATION"`` and locks it into
  ``RSE_KMU_SLOT_SECURE_BINDING_KEY`` (+1 for AEAD).
- BL1_2 accesses the key via the opaque PSA key ID returned by
  ``cc3xx_get_opaque_key()``.
- A binding tag is considered present when the header field is non-zero;
  otherwise BL1_2 treats the boot as the first binding pass.
