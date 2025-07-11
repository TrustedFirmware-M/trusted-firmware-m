Runtime Security Engine (RSE)
=============================

Introduction
------------

Runtime Security Engine (RSE) is an Arm subsystem that serves as a hardware
root-of-trust and isolated attestation enclave in A-profile compute subsystems.
RSE provides a physically-isolated execution environment for security-critical
assets and services, which can be configured according to use case. In systems
that implement the `Arm Confidential Compute Architecture (CCA)
<https://www.arm.com/architecture/security-features/arm-confidential-compute-architecture>`_,
RSE fulfils the requirements of the HES Host. In `DICE
<https://trustedcomputinggroup.org/work-groups/dice-architectures/>`_
attestation schemes, RSE provides a DICE Protection Environment (DPE)
implementation.

On a RSE cold reset, the DMA-350 within the RSE subsystem is the first to boot
whilst the RSE CPU is held in wait state. The DMA-350 is configured by HW to
automatically fetch the first DMA descriptor of the 'Intial Command Sequence'
(ICS) :doc:`(DMA ICS) </platform/arm/rse/dma_ics_readme>`, from a fixed offset
in ROM. The ICS is a sequence of linked DMA descriptors that handle security
critical memory transfers. The final command of the ICS is to release the RSE
CPU out of reset.

RSE CPU initially boots from immutable code :doc:`(BL1_1) </design_docs/booting/bl1>`
in its internal ROM, before jumping to BL1_2, which is provisioned and
hash-locked in RSE OTP. The updatable MCUBoot BL2 boot stage is loaded from host
system flash into RSE SRAM, where it is authenticated using the LMS stateful
hash-based signature scheme. :doc:`BL2 </design_docs/booting/tfm_secure_boot>`
loads and authenticates the TF-M runtime and RSE NS image (if applicable) into
RSE SRAM from host flash. BL2 is also responsible for loading initial boot code
into other subsystems within the host.

The TF-M runtime for RSE supports the TF-M Crypto, ADAC (Authenticated Debug
Access Control) and Platform services, along with the Measured Boot, Initial
Attestation and Delegated Attestation services in the CCA HES use case and the
DICE Protection Environment service in the DICE use case. It supports the TF-M
IPC model with Isolation Level 1 and 2. At runtime, RSE can receive service
requests from the RSE NSPE via the TF-M TrustZone interface and from other
processing elements in the system over MHU using the
:doc:`RSE comms protocol </platform/arm/rse/rse_comms>`.

Building TF-M
-------------

Follow the instructions in :doc:`Build instructions </building/tfm_build_instruction>`.
Build TF-M with platform name: `arm/rse/<rse platform name>`

For example, to build RSE for the Total Compute TC3 platform use:
``-DTFM_PLATFORM=arm/rse/tc/tc3``

Signing host images
-------------------

RSE BL2 can load boot images into other subsystems within the host system. It
expects images to be signed, with the signatures attached to the images in the
MCUBoot metadata format.

The `imgtool Python package <https://pypi.org/project/imgtool/>`_ can be used to
sign images in the required format. To sign a host image using the development
key distributed with TF-M, use the following command::

    imgtool sign \
        -k <TF-M base directory>/bl2/ext/mcuboot/root-EC-P256.pem \
        --public-key-format full \
        --max-align 8 \
        --align 1 \
        -v "0.0.1" \
        -s 1 \
        -H 0x2000 \
        --pad-header \
        -S 0x80000 \
        --pad \
        -L <load address> \
        <binary infile> \
        <signed binary outfile>

The ``load address`` is the logical address in the RSE memory map to which BL2
will load the image. RSE FW expects the first host image to be loaded to address
``0x70000000`` (the beginning of the RSE ATU host access region), and each
subsequent host image to be loaded at an offset of ``0x1000000`` from the
previous image. The RSE ATU should be configured to map these logical addresses
to the physical addresses in the host system that the images need to be loaded
to.

The development key ``root-EC-P256.pem`` corresponds to the default BL2
signature scheme of ECDSA-P256 used by RSE.

For more information on the ``imgtool`` parameters, see the MCUBoot
`imgtool documentation <https://docs.mcuboot.com/imgtool.html>`_.

.. warning::

    The TF-M development key must never be used in production. See the
    :doc:`RSE integration guide </platform/arm/rse/rse_integration_guide>` for
    more information about key management.

Running the code
----------------

To run the built images, first the ROM image must be created from the bl1_1
binary and the ROM DMA Initial Command Sequence (ICS).::

    srec_cat \
        bl1_1.bin -Binary -offset 0x0 \
        rom_dma_ics.bin -Binary -offset 0x1F000 -fill 0x00 0x1F000 0x20000 \
        -o rom.bin -Binary

Then, the flash image must be created by concatenating the images that are
output from the build. To create the flash image, the following ``fiptool``
command should be run. ``fiptool`` documentation can be found `here
<https://trustedfirmware-a.readthedocs.io/en/latest/getting_started/tools-build.html#building-and-using-the-fip-tool>`_.
Note that an up-to-date fiptool that supports the RSE UUIDs must be used.::

    fiptool create \
        --align 8192 --rse-bl2     bl2_signed.bin \
        --align 8192 --rse-ns      tfm_ns_signed.bin \
        --align 8192 --rse-s       tfm_s_signed.bin \
        --align 8192 --rse-scp-bl1 <signed Host SCP BL1 image> \
        --align 8192 --rse-ap-bl1  <signed Host AP BL1 image> \
        fip.bin

If you already have a ``fip.bin`` containing host firmware images, RSE FIP
images can be patched in::

    fiptool update --align 8192 --rse-bl2 bl2_signed.bin fip.bin
    fiptool update --align 8192 --rse-ns  tfm_ns.bin fip.bin
    fiptool update --align 8192 --rse-s   tfm_s.bin fip.bin

If XIP mode is enabled, the following ``fiptool`` command should be run to
create the flash image::

    fiptool create \
        --align 8192 --rse-bl2           bl2_signed.bin \
        --align 8192 --rse-ns            tfm_ns_encrypted.bin \
        --align 8192 --rse-s             tfm_s_encrypted.bin \
        --align 8192 --rse-sic-tables-ns tfm_ns_sic_tables_signed.bin \
        --align 8192 --rse-sic-tables-s  tfm_s_sic_tables_signed.bin \
        --align 8192 --rse-scp-bl1       <signed Host SCP BL1 image> \
        --align 8192 --rse-ap-bl1        <signed Host AP BL1 image> \
        fip.bin

Once the FIP is prepared, a host flash image can be created using ``srec_cat``::

    srec_cat \
            fip.bin -Binary -offset 0x0 \
            -o host_flash.bin -Binary

If GPT support is enabled, and a host ``fip.bin`` and ``fip_gpt.bin`` has been
obtained, RSE images can be inserted by first patching the host FIP and then
inserting that patched FIP into the GPT image::

    sector_size=$(gdisk -l fip_gpt.bin | grep -i "sector size (logical):" | \
                sed 's/.*logical): \([0-9]*\) bytes/\1/')

    fip_label=" FIP_A$"
    fip_start_sector=$(gdisk -l fip_gpt.bin | grep "$fip_label" | awk '{print $2}')
    fip_sector_am=$(gdisk -l fip_gpt.bin | grep "$fip_label" | awk '{print $3 - $2}')

    dd if=fip.bin of=fip_gpt.bin bs=$sector_size seek=$fip_start_sector \
        count=$fip_sector_am conv=notrunc

    fip_label=" FIP_B$"
    fip_start_sector=$(gdisk -l fip_gpt.bin | grep "$fip_label" | awk '{print $2}')
    fip_sector_am=$(gdisk -l fip_gpt.bin | grep "$fip_label" | awk '{print $3 - $2}')

    dd if=fip.bin of=fip_gpt.bin bs=$sector_size seek=$fip_start_sector \
        count=$fip_sector_am conv=notrunc

To patch a ``fip_gpt.bin`` without having an initial ``fip.bin``, the FIP can be
extracted from the GPT image using the following commands (and can then be
patched and reinserted using the above commands)::

    sector_size=$(gdisk -l fip_gpt.bin | grep -i "sector size (logical):" | \
                sed 's/.*logical): \([0-9]*\) bytes/\1/')

    fip_label=" FIP_A$"
    fip_start_sector=$(gdisk -l fip_gpt.bin | grep "$fip_label" | awk '{print $2}')
    fip_sector_am=$(gdisk -l fip_gpt.bin | grep "$fip_label" | awk '{print $3 - $2}')

    dd if=fip_gpt.bin of=fip.bin bs=$sector_size skip=$fip_start_sector \
        count=$fip_sector_am conv=notrunc

Once the ``fip_gpt.bin`` is prepared, it is placed at the base of the host flash
image::

    srec_cat \
            fip_gpt.bin -Binary -offset 0x0 \
            -o host_flash.bin -Binary

The RSE ROM binary should be placed in RSE ROM at ``0x11000000`` and the host
flash binary should be placed at the base of the host flash. For the TC
platform, this is at ``0x80000000``.

The RSE OTP must be provisioned. On a development platform with
``TFM_DUMMY_PROVISIONING`` enabled, BL1_1 expects provisioning bundles to be
preloaded into RSE SRAM. Preload ``encrypted_cm_provisioning_bundle_0.bin`` to
offset ``0x400`` from the base of VM0, and
``encrypted_dm_provisioning_bundle_0.bin`` to the base of VM1.

If ``TFM_DUMMY_PROVISIONING`` is disabled and provisioning is required, then
BL1_1 will first wait for the TP mode to be set by a debugger (setting the
``tp_mode`` variable in the current stack frame is easiest). BL1_1 will then
wait for provisioning bundles to be loaded to VM0 and VM1 in the same way as
when ``TFM_DUMMY_PROVISIONING`` is enabled, except that it will not
automatically perform the reset once each provisioning state is complete. For
more details about provisioning flows, see
:doc:`RSE provisioning </platform/arm/rse/rse_provisioning>`.

--------------

*Copyright (c) 2022-2024, Arm Limited. All rights reserved.*
