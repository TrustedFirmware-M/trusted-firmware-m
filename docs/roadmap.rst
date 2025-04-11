#######
Roadmap
#######

TF-M has been under active development since it was launched in Q1'18. It is
being designed to include

1. Secure boot ensuring integrity of runtime images and responsible for firmware upgrade.
2. Runtime firmware consisting of TF-M Core is responsible for secure isolation,
   execution and communication aspects. and a set of Secure Services providing
   services to the Non-Secure and Secure Applications. The secures services
   currently supported are Secure Storage, Cryptography, Firmware Update,
   Attestation and Platform Services

If you are interested in collaborating on any of the roadmap features or other
features, please mail TF-M mailing list

******************
Supported Features
******************
- PSA Firmware Framework v1.0, 1.1 Extension including IPC and SFN modes.
- PSA Level1, 2 and 3 Isolation.
- Secure Boot (mcuboot upstream) including generic fault injection mitigations
- PSA Protected Storage, Internal Trusted Storage v1.0 and Encrypted ITS
- PSA Cryptov1.0 (uses Mbed TLS v3.4.0)
- PSA Initial Attestation Service v1.0
- PSA Firmware Update v1.0
- PSA ADAC Specification Implementation
- Base Config, kconfig based configuration
- Profile Small, Medium, ARoT-less Medium, Large
- Secure Partition Interrupt Handling, Pre-emption of SPE execution
- Dual CPU
- Open Continuous Integration (CI) System
- Boot and Runtime Crypto Hardware Integration
- Fault Injection Handling library to mitigate against physical attacks
- Threat Model
- Arm v8.1-M Privileged Execute Never (PXN) attribute and Thread reentrancy disabled (TRD)
- FPU, MVE Support
- CC-312 PSA Cryptoprocessor Driver Interface
- Secure Storage - Key Diversification Enhancements
- Build System - Separate Secure and Non-Secure builds
- PSA Crypto layer for mcuboot/BL2
- Support LLVM Embedded Toolchain for Arm
- MISRA testing/documentation
- Switch to using upstream t_cose
- Remote Test Infrastructure

******
CQ2'25
******
- Supporting multiple clients (Hybrid Platforms) i.e. TF-M supporting multiple on
  core and off core clients on heterogeneous (e.g. Cortex-A + Cortex-M platforms)
- TF-M v2.2.0 release
- Update to Mbed TLS3.6.3

******
Future
******
- Integrate TF-PSACrypto
- TF-M v2.3.0
- Image encryption via. PSA Crypto in mcuboot
- Implement support for multiple clients (Hybrid Platforms) contd.
- Build System Enhancements - Simplify build scripts
- TF-M Performance - Further Benchmarking and Optimization
- Scheduler - Multiple Secure Context Implementation
- PSA FWU Service Enhancements
- PSA ADAC Spec - Enhancements and Testing
- Arm v8.1-M Unprevileged Debug
- [Secure Storage] Extended PSA APIs
- [Audit Logs] Secure Storage, Policy Manager
- PSA FF Lifecycle API
- Fuzz Testing

--------------

*Copyright (c) 2017-2024, Arm Limited. All rights reserved.*
