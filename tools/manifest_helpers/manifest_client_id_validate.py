#!/usr/bin/env python3
#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

import logging


ns_agent_list = []

def _client_id_validate(name, client_id_str):

    try:
        client_id = int(client_id_str, 0)
    except Exception as e:
        logging.error(f"{name}: Failed to convert client ID ({client_id_str}) to int:", e)
        exit(1)

    if client_id_str[0] == '-':
        minus_sign = True
    else:
        minus_sign = False

    # Shall not be wider than 32-bit
    if abs(client_id) > 0xFFFFFFFF:
        raise RuntimeError(f"{name}: Client ID ({client_id_str}) is not a 32-bit negative integer")

    # When minus sign is added, the MSB of digits shall be 0b0. Otherwise, a
    # 32-bit positive integer (such as -0x8xxxxxxx) can be recognized as a valid
    # 64-bit negative value on a host machine.
    # When minus sign is not added, the MSB of digits shall be 0b1
    if (minus_sign and abs(client_id) >= 0x80000000) or \
       (not minus_sign and client_id < 0x80000000):
        raise RuntimeError(f"{name}: Client ID ({client_id_str}) is not a 32-bit negative integer")

    # A valid 32-bit negative integer with MSB set can be recognized as a 64-bit
    # positive integer. Convert it back to a negative value.
    if client_id >= 0x80000000:
        client_id = - (~(client_id - 1) & 0xFFFFFFFF)

    return client_id

def ns_agent_client_id_validate(ns_agent, base, limit):
    """
    Validate the Client ID range set in the NS Agent Secure Partition manifest

    Parameters
    ----------
    ns_agent:
        The name string of the NS Agent Secure Partition
    base:
        The client_id_base value in manifest
    limit:
        The client_id_limit value in manifest
    """

    sp_name = ns_agent.upper()

    base_val = _client_id_validate(sp_name, base)
    limit_val = _client_id_validate(sp_name, limit)

    if base_val > limit_val:
        raise RuntimeError(f"{sp_name}: Client ID base must <= Client ID limit")

    # Validate whether overlapped with other NS Agent's Client ID range
    for sp in ns_agent_list:
        if base_val <= sp.get("client_id_limit") and \
           limit_val >= sp.get("client_id_base"):
            raise RuntimeError(f"{sp_name} and {sp.get('name')} have overlapped Client ID ranges")

    # Validation passed. Record this NS Agent's Client ID range
    manifest = {}
    manifest["name"] = sp_name
    manifest["client_id_base"] = base_val
    manifest["client_id_limit"] = limit_val
    ns_agent_list.append(manifest)

def irq_client_id_validate(ns_agent, irq, base, limit):
    """
    Validate the Client ID range of the IRQ source set in the NS Agent Secure
    Partition manifest

    Parameters
    ----------
    ns_agent:
        The name string of the NS Agent Secure Partition
    irq:
        The string of the IRQ name/signal
    base:
        The IRQ client_id_base value in manifest
    limit:
        The IRQ client_id_limit value in manifest
    """

    sp_name = ns_agent.upper()
    irq_name = irq.upper()

    base_val = _client_id_validate(irq, base)
    limit_val = _client_id_validate(irq, limit)

    if base_val > limit_val:
        raise RuntimeError(f"{irq_name}: Client ID base must <= Client ID limit")

    # Validate whether the IRQ Client ID ranges exceeds its Secure Partition
    # Client ID range. The Secure Partition should be the last one in the array.
    sp = next((d for d in reversed(ns_agent_list) if d.get("name") == sp_name), None)

    if sp is None:
        raise RuntimeError(f"Unable to find {sp_name} manifest")

    if base_val < sp.get("client_id_base") or limit_val > sp["client_id_limit"]:
        raise RuntimeError(f"{irq_name} Client ID range exceeds {sp_name} range")
