###################
Security Advisories
###################

.. toctree::
    :maxdepth: 1
    :hidden:

    stack_seal_vulnerability
    svc_caller_sp_fetching_vulnerability
    crypto_multi_part_ops_abort_fail
    profile_small_key_id_encoding_vulnerability
    fwu_write_vulnerability
    cc3xx_partial_tag_compare_on_chacha20_poly1305
    debug_log_vulnerability
    user_pointers_mailbox_vectors_vulnerability
    fwu_tlv_payload_out_of_bounds_vulnerability

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

.. |TFMV-1| replace:: :doc:`TFMV-1 <stack_seal_vulnerability>`
.. |TFMV-2| replace:: :doc:`TFMV-2 <svc_caller_sp_fetching_vulnerability>`
.. |TFMV-3| replace:: :doc:`TFMV-3 <crypto_multi_part_ops_abort_fail>`
.. |TFMV-4| replace:: :doc:`TFMV-4 <profile_small_key_id_encoding_vulnerability>`
.. |TFMV-5| replace:: :doc:`TFMV-5 <fwu_write_vulnerability>`
.. |TFMV-6| replace:: :doc:`TFMV-6 <cc3xx_partial_tag_compare_on_chacha20_poly1305>`
.. |TFMV-7| replace:: :doc:`TFMV-7 <debug_log_vulnerability>`
.. |TFMV-8| replace:: :doc:`TFMV-8 <user_pointers_mailbox_vectors_vulnerability>`
.. |TFMV-9| replace:: :doc:`TFMV-9 <fwu_tlv_payload_out_of_bounds_vulnerability>`

--------------

*SPDX-License-Identifier: BSD-3-Clause*

*SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors*
