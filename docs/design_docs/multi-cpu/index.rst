#########
Multi CPU
#########

:Organization: Arm Limited
:Contact: tf-m@lists.trustedfirmware.org

The following documents outline the design and implementation principles of TF-M
for multi-cpu and hybrid platforms, where the Secure Processing Environment
(SPE) and Non-secure Processing Environment (NSPE) execute on separate cores.

During boot, the secure core initializes the hardware and peripherals that the
NSPE uses, establishing an assured execution path.

The cores communicate using a mailbox-based Inter-Processor Communication (IPC)
mechanism.

The framework includes a Remote Procedure Call (RPC) layer and an NS Agent
Mailbox to abstract platform dependencies.
Hybrid platform scheduling extends the original dual-cpu concepts for systems
with a local and multiple remote NSPEs, supporting flexible scheduling policies.

.. toctree::
    :maxdepth: 1

    Booting a multi-cpu      <booting_a_multi_cpu_system.rst>
    Hybrid Platform Topology <hybrid_platform_solution.rst>
    Mailbox Design           <mailbox_design.rst>
    Memory Access Check      <tfm_multi_core_access_check.rst>
    SPE - NSPE communication <communication_between_nspe_and_spe_in_dual_core_systems.rst>


--------------

*SPDX-License-Identifier: BSD-3-Clause*

*SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors*

