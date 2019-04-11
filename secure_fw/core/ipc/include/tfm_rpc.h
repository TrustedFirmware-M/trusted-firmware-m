/*
 * Copyright (c) 2018-2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#ifndef __TFM_RPC_H__
#define __TFM_RPC_H__

/* Dual core RPC messages */

#define TRPC_MAGIC            0x54525043
#define TRPC_SYNC_CREATING    0x0
#define TRPC_SYNC_READY       0x1
#define TRPC_SYNC_LOCK        0x2
#define TRPC_SYNC_RELEASE     0x3

#define TRPC_PAYLOAD_CTRL     0xFE000000
#define TRPC_PAYLOAD_INPUT    0xFE000001
#define TRPC_PAYLOAD_OUTPUT   0xFE000002
#define TRPC_PAYLOAD_MASK     0xFFFFFFF0
#define TRPC_PAYLOAD_TYPE     0xFE000000

#define TRPC_CTRL_CONNECT     0x00EE0001
#define TRPC_CTRL_CALL        0x00EE0002
#define TRPC_CTRL_CLOSE       0x00EE0003

/*
 * The message format for RPC purpose in shared-memory:
 * [ Header    ]
 * [ Payload 0 ]
 * [ Payload 1 ]
 * [ ...       ]
 *
 * The header format would be:
 * [ Magic     ] -> Magic word = 'TRPC'
 * [ Sync      ] -> Status syncing with two sides
 * [ Len       ] -> Length of whole message with 4 bytes aligned
 * [ Payloads  ] -> Payloads followed
 *
 * The payload format:
 * [ Type      ] -> Payload type
 * [ Ilen      ] -> Original size of payload, no alignment requirement
 * [ Olen      ] -> Updated size of payload (should <= Ilen)
 * [ Data      ] -> Data start
 *
 * Even there is no alignment requirement for payloads' size, the
 * offset of next payload is 4 bytes aligned:
 * Offset += ALIGNED(payload->size)
 */
struct tfm_rpc_msg_header_t {
    uint32_t magic;
    uint32_t sync;
    uint32_t len;
    uint8_t payloads[0];
};

/*
 * Payload type.
 */
struct tfm_rpc_payload_t {
    uint32_t type;
    uint32_t ilen;
    uint32_t olen;
    uint8_t data[0];
};

#define TFM_RPC_ALIGN_32(a)    ((a + 3) & 0xFFFFFFFC)

#define TO_NEXT_PAYLOAD(pld) \
    (struct tfm_rpc_payload_t*)(&pld->data[(pld->ilen + 3) & 0xFFFFFFFC])

int32_t tfm_rpc_client_message(void *buf, size_t size);
int32_t tfm_rpc_client_payload(void *buf, size_t size, uint32_t type,
                               void *p_src, size_t src_sz);
int32_t tfm_rpc_service_process(void *buf, uint32_t size);
int32_t tfm_rpc_service_reply(void *buf, uint32_t size, uint32_t reply, void *outvec);
int32_t tfm_rpc_client_ready(void *buf, size_t size);
void *tfm_rpc_client_recv(void *buf, size_t size, void *start);



#endif
