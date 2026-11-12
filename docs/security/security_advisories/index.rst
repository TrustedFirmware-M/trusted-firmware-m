###################
Security Advisories
###################

.. toctree::
    :maxdepth: 1
    :hidden:

    0001_stack_seal_vulnerability
    0002_svc_caller_sp_fetching_vulnerability
    0003_crypto_multi_part_ops_abort_fail
    0004_profile_small_key_id_encoding_vulnerability
    0005_fwu_write_vulnerability
    0006_cc3xx_partial_tag_compare_on_chacha20_poly1305
    0007_debug_log_vulnerability
    0008_user_pointers_mailbox_vectors_vulnerability
    0009_fwu_tlv_payload_out_of_bounds_vulnerability
    0010_missing_ns_pointer_validation_mailbox_init
    0011_fwu_partial_fmp_header
    0012_rse_sfcp_pre_auth_oob_write
    0013_rse_sfcp_plaintext_packets
    0014_cs1k_oob_flash_write_secure_enclave
    0015_aead_oob_read

+------------+-----------------------------------------------------------------+
| ID         | Title                                                           |
+============+=================================================================+
|  |TFMV-1|  | NS world may cause the CPU to perform an unexpected return      |
|            | operation due to unsealed stacks.                               |
+------------+-----------------------------------------------------------------+
|  |TFMV-2|  | Invoking Secure functions from handler mode may cause TF-M IPC  |
|            | model to behave unexpectedly.                                   |
+------------+-----------------------------------------------------------------+
|  |TFMV-3|  | ``abort()`` function may not take effect in TF-M Crypto         |
|            | multi-part MAC/hashing/cipher operations.                       |
+------------+-----------------------------------------------------------------+
|  |TFMV-4|  | NSPE may access secure keys stored in TF-M Crypto service       |
|            | in Profile Small with Crypto key ID encoding disabled.          |
+------------+-----------------------------------------------------------------+
|  |TFMV-5|  | ``psa_fwu_write()`` may cause buffer overflow in SPE.           |
+------------+-----------------------------------------------------------------+
|  |TFMV-6|  | Partial tag comparison when using Chacha20-Poly1305 on the PSA  |
|            | driver API interface in CryptoCell enabled platforms            |
+------------+-----------------------------------------------------------------+
|  |TFMV-7|  | ARoT can access PRoT data via debug logging functionality       |
+------------+-----------------------------------------------------------------+
|  |TFMV-8|  | Unchecked user-supplied pointer via mailbox messages may cause  |
|            | write of arbitrary address                                      |
+------------+-----------------------------------------------------------------+
|  |TFMV-9|  | FWU does not check the length of the TLV's payload              |
+------------+-----------------------------------------------------------------+
|  |TFMV-10| | Missing NS pointer validation in platform mailbox init          |
+------------+-----------------------------------------------------------------+
|  |TFMV-11| | Incorrect FMP Header Fragment Reconstruction Allows             |
|            | Attacker-Controlled Firmware Version Values                     |
+------------+-----------------------------------------------------------------+
|  |TFMV-12| | Pre-auth OOB write in RSE SFCP handshake hijacks BL1            |
|            | boot-ROM control flow                                           |
+------------+-----------------------------------------------------------------+
|  |TFMV-13| | Plaintext SFCP packet on RSE returns delegated-attestation      |
|            | private key                                                     |
+------------+-----------------------------------------------------------------+
|  |TFMV-14| | OOB flash write in corstone1000 update bricks the secure        |
|            | enclave                                                         |
+------------+-----------------------------------------------------------------+
|  |TFMV-15| | Out-of-bounds read in crypto AEAD service                       |
+------------+-----------------------------------------------------------------+

.. |TFMV-1| replace:: :doc:`TFMV-1 <0001_stack_seal_vulnerability>`
.. |TFMV-2| replace:: :doc:`TFMV-2 <0002_svc_caller_sp_fetching_vulnerability>`
.. |TFMV-3| replace:: :doc:`TFMV-3 <0003_crypto_multi_part_ops_abort_fail>`
.. |TFMV-4| replace:: :doc:`TFMV-4 <0004_profile_small_key_id_encoding_vulnerability>`
.. |TFMV-5| replace:: :doc:`TFMV-5 <0005_fwu_write_vulnerability>`
.. |TFMV-6| replace:: :doc:`TFMV-6 <0006_cc3xx_partial_tag_compare_on_chacha20_poly1305>`
.. |TFMV-7| replace:: :doc:`TFMV-7 <0007_debug_log_vulnerability>`
.. |TFMV-8| replace:: :doc:`TFMV-8 <0008_user_pointers_mailbox_vectors_vulnerability>`
.. |TFMV-9| replace:: :doc:`TFMV-9 <0009_fwu_tlv_payload_out_of_bounds_vulnerability>`
.. |TFMV-10| replace:: :doc:`TFMV-10 <0010_missing_ns_pointer_validation_mailbox_init>`
.. |TFMV-11| replace:: :doc:`TFMV-11 <0011_fwu_partial_fmp_header>`
.. |TFMV-12| replace:: :doc:`TFMV-12 <0012_rse_sfcp_pre_auth_oob_write>`
.. |TFMV-13| replace:: :doc:`TFMV-13 <0013_rse_sfcp_plaintext_packets>`
.. |TFMV-14| replace:: :doc:`TFMV-14 <0014_cs1k_oob_flash_write_secure_enclave>`
.. |TFMV-15| replace:: :doc:`TFMV-15 <0015_aead_oob_read>`

--------------

*SPDX-License-Identifier: BSD-3-Clause*

*SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors*
