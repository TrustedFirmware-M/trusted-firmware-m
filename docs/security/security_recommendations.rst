########################
Security Recommendations
########################


:Organization: Arm Limited
:Contact: tf-m@lists.trustedfirmware.org

Security recommendations are listed here.

Advice and guidance provided in this document is intended to improve security
overall and prevent vulnerabilities.


Security Recommendation no.1
============================

+-----------------+------------------------------------------------------------+
| Title           | Compiler-induced constant-time violations                  |
|                 |                                                            |
+=================+============================================================+
| Date            | April, 2026                                                |
+-----------------+------------------------------------------------------------+
| Versions        | None. General guidance.                                    |
| Affected        |                                                            |
+-----------------+------------------------------------------------------------+
| Configurations  | General guidance for Clang 18 LLVM compiler.               |
|                 |                                                            |
+-----------------+------------------------------------------------------------+
| Impact          | Some optimizations for modern versions of Clang may defeat |
|                 | the constant-time behaviour, causing a possible timing     |
|                 | side-channel attack.                                       |
+-----------------+------------------------------------------------------------+


Background
----------

Modern versions of Clang introduce timing side-channels into padding validation
code on some platforms when LLVM's select-optimize feature is enabled.

Some compiler optimizations can defeat the constant-time protection, if the
compiler recognizes the functional behavior of the code and emits binary code
that is functionally equivalent, but not constant-time.

For detailed explanation see: https://www.cve.org/CVERecord?id=CVE-2025-66442


Impact
------

If TF-PSA-Crypto or Mbed TLS is built with Clang 18 with the LLVM
select-optimize feature enabled, compiling for 64-bit RISC-V, some features may
be vulnerable to a timing oracle attack.


Mitigation
----------

Force the compiler options with ``--disable-select-optimize=true``.


---------------------

*SPDX-License-Identifier: BSD-3-Clause*

*SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors*
