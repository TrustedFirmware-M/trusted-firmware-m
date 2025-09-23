/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "cc3xx_pka.h"

#include "cc3xx_dev.h"
#ifndef CC3XX_CONFIG_FILE
#include "cc3xx_config.h"
#else
#include CC3XX_CONFIG_FILE
#endif
#include "cc3xx_rng.h"

#include "endian.h"
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>

#define PKA_WORD_SIZE  8
#define PKA_WORD_BIT_SIZE  (PKA_WORD_SIZE * 8)

#ifdef CC3XX_CONFIG_HW_VERSION_CC310
#define PKA_SRAM_SIZE 0x1000 /* 4KiB */
#else
#define PKA_SRAM_SIZE 0x1800 /* 6KiB */
#endif

/* The hardware requires and extra word and byte to deal with carries etc
 * (which would then later be removed by a reduction operation). The TRM
 * suggests this should be only a word, but the extra byte is required for
 * mod_exp to function correctly.
 */
#define PKA_MAX_OVERFLOW_SIZE     (PKA_WORD_SIZE + 1)
#define PKA_MAX_OVERFLOW_BIT_SIZE (PKA_MAX_OVERFLOW_SIZE * 8)

/* Signed immediates use a two's complement encoding in 5 bits */
#define PKA_MAX_SIGNED_IMMEDIATE 15
#define PKA_MIN_SIGNED_IMMEDIATE (-16)

#define PKA_MAX_UNSIGNED_IMMEDIATE 31

#define PKA_PHYS_REG_TEMP_0 30
#define PKA_PHYS_REG_TEMP_1 31

#define CC3XX_PKA_REG_N_MASK 2

#define CC3XX_PKA_PHYS_REG_AMOUNT 32
#define PKA_RESERVED_PHYS_REG_AMOUNT 5
#define PKA_PHYS_REG_FIRST_MAPPABLE (CC3XX_PKA_REG_N_MASK + 1)
#define PKA_PHYS_REG_LAST_MAPPABLE (PKA_PHYS_REG_TEMP_0 - 1)
#define PKA_VIRT_REG_FIRST_ALLOCATABLE (CC3XX_PKA_REG_N_MASK + 1)

#define CC3XX_PKA_RANDOM_BUF_SIZE 32

#ifdef CC3XX_CONFIG_PKA_INLINE_FOR_PERFORMANCE
#define CC3XX_ATTRIBUTE_INLINE inline __attribute__((always_inline))
#else
#define CC3XX_ATTRIBUTE_INLINE
#endif

enum pka_op_size_t {
    PKA_OP_SIZE_N = 0,
    PKA_OP_SIZE_REGISTER = 1,
};

/* Where an opcode claims it performs multiple operations, that is achieved by
 * using immediate or zero operands, not by any actual switching of the
 * operation being performed.
 */
enum cc3xx_pka_operation_t {
    CC3XX_PKA_OPCODE_TERMINATE = 0x0,
    CC3XX_PKA_OPCODE_ADD_INC = 0x4, /* INC is add immediate */
    CC3XX_PKA_OPCODE_SUB_DEC_NEG = 0x5, /* DEC is add immediate */
    CC3XX_PKA_OPCODE_MODADD_MODINC = 0x6,
    CC3XX_PKA_OPCODE_MODSUB_MODDEC_MODNEG = 0x7,
    CC3XX_PKA_OPCODE_AND_TST0_CLR0 = 0x8,
    CC3XX_PKA_OPCODE_OR_COPY_SET0 = 0x9,
    CC3XX_PKA_OPCODE_XOR_FLIP0_INVERT_COMPARE = 0xA,
    CC3XX_PKA_OPCODE_SHR0 = 0xC,
    CC3XX_PKA_OPCODE_SHR1 = 0xD,
    CC3XX_PKA_OPCODE_SHL0 = 0xE,
    CC3XX_PKA_OPCODE_SHL1 = 0xF,
    CC3XX_PKA_OPCODE_MULLOW = 0x10,
    CC3XX_PKA_OPCODE_MODMUL = 0x11,
    CC3XX_PKA_OPCODE_MODMULN = 0x12,
    CC3XX_PKA_OPCODE_MODEXP = 0x13,
    CC3XX_PKA_OPCODE_DIV = 0x14,
    /* Opcodes below here are not documented in the TRM. */
    CC3XX_PKA_OPCODE_MODINV = 0x15,
    CC3XX_PKA_OPCODE_MODDIV = 0x16,
    CC3XX_PKA_OPCODE_MULHIGH = 0x17U,
    CC3XX_PKA_OPCODE_MODMLAC = 0x18U,
    CC3XX_PKA_OPCODE_MODMLACNR = 0x19U,
    CC3XX_PKA_OPCODE_SEPINT = 0x1AU,
    CC3XX_PKA_OPCODE_REDUCTION = 0x1BU,
};

/* It seems strange that the state that is external is so small, while things
 * like the virtual register allocations are internal to the implementation and
 * therefore not saved in a get_state/set_state operation. In reality,
 * recalculating the sram addresses is fast, and saving them has downsides
 * related to the temporary register sram address swapping, so this is a
 * reasonable approach.
 */
static uint32_t pka_reg_am_max;
uint32_t phys_reg_next_mapped;
static uint32_t virt_reg_sram_addr[CC3XX_CONFIG_PKA_MAX_VIRT_REG_AMOUNT];
#ifdef CC3XX_CONFIG_PKA_ALIGN_FOR_PERFORMANCE
static uint32_t virt_reg_in_use[CC3XX_CONFIG_PKA_MAX_VIRT_REG_AMOUNT];
static uint32_t virt_reg_is_mapped[CC3XX_CONFIG_PKA_MAX_VIRT_REG_AMOUNT];
static uint32_t virt_reg_needs_n_mask[CC3XX_CONFIG_PKA_MAX_VIRT_REG_AMOUNT];
static uint32_t virt_reg_phys_reg[CC3XX_CONFIG_PKA_MAX_VIRT_REG_AMOUNT];
static uint32_t phys_reg_mapping_list[CC3XX_PKA_PHYS_REG_AMOUNT];
#else
static bool virt_reg_in_use[CC3XX_CONFIG_PKA_MAX_VIRT_REG_AMOUNT];
static bool virt_reg_is_mapped[CC3XX_CONFIG_PKA_MAX_VIRT_REG_AMOUNT];
static bool virt_reg_needs_n_mask[CC3XX_CONFIG_PKA_MAX_VIRT_REG_AMOUNT];
static uint8_t virt_reg_phys_reg[CC3XX_CONFIG_PKA_MAX_VIRT_REG_AMOUNT];
static cc3xx_pka_reg_id_t phys_reg_mapping_list[CC3XX_PKA_PHYS_REG_AMOUNT];
#endif /* CC3XX_CONFIG_PKA_ALIGN_FOR_PERFORMANCE */

static struct cc3xx_pka_state_t pka_state;

static inline uint32_t pka_addr_from_byte_addr(uint32_t offset)
{
    return offset / sizeof(uint32_t);
}

static inline uint32_t pad_to_pka_word_size(uint32_t byte_size)
{
    /* round up to the nearest PKA word */
    return (((byte_size + PKA_WORD_SIZE - 1) / PKA_WORD_SIZE) * PKA_WORD_SIZE);
}

uint32_t cc3xx_lowlevel_pka_get_register_size(void)
{
    return pka_state.reg_size;
}

void cc3xx_lowlevel_pka_unmap_physical_registers(void)
{
    uint32_t idx;
    cc3xx_pka_reg_id_t virt_reg;

    /* Wait for the pipeline to finish */
    while(!P_CC3XX->pka.pka_done){}

    for (idx = PKA_PHYS_REG_FIRST_MAPPABLE; idx <= PKA_PHYS_REG_LAST_MAPPABLE; idx++) {
        virt_reg = phys_reg_mapping_list[idx];
        if (virt_reg != 0 && virt_reg_is_mapped[virt_reg]) {
            virt_reg_sram_addr[virt_reg] = P_CC3XX->pka.memory_map[idx];
            virt_reg_phys_reg[virt_reg] = 0;
            virt_reg_is_mapped[virt_reg] = false;
        }
    }

    memset(phys_reg_mapping_list, 0, sizeof(phys_reg_mapping_list));

    for (idx = 0; idx < PKA_PHYS_REG_FIRST_MAPPABLE; idx++) {
        phys_reg_mapping_list[idx] = idx;
    }

    phys_reg_next_mapped = PKA_PHYS_REG_FIRST_MAPPABLE;
}

static void pka_init_from_state(void)
{
    uint32_t idx;

    P_CC3XX->misc.pka_clk_enable = 1;
    P_CC3XX->pka.pka_sw_reset = 1;

    /* Wait for SW reset to complete before proceeding */
    while(!P_CC3XX->pka.pka_done) {}

#ifdef CC3XX_CONFIG_PKA_SRAM_ENCRYPTION_SUPPORTED
    /* Enable PKA SRAM encryption */
    P_CC3XX->pka.pka_ram_enc = 0x1U;
#endif /* CC3XX_CONFIG_PKA_SRAM_ENCRYPTION_SUPPORTED */

    /* The TRM says that this register is a byte-size, but it is in fact a
     * bit-size.
     */
    P_CC3XX->pka.pka_l[PKA_OP_SIZE_REGISTER] = pka_state.reg_size * 8;

    assert((pka_state.reg_size & ((PKA_WORD_SIZE) - 1)) == 0);
    assert(pka_state.reg_size >= (PKA_WORD_SIZE));

    pka_reg_am_max = (PKA_SRAM_SIZE) / pka_state.reg_size;
    if (pka_reg_am_max >= CC3XX_CONFIG_PKA_MAX_VIRT_REG_AMOUNT + 2) {
        pka_reg_am_max = CC3XX_CONFIG_PKA_MAX_VIRT_REG_AMOUNT + 2;
    }

    /* We need to allocate 4 special registers (and have at least 1 left for an
     * operation).
     */
    assert(pka_reg_am_max > 4);

    /* Unmap all the physical registers */
    cc3xx_lowlevel_pka_unmap_physical_registers();

    /* Set up the first three regions as N and Np, and N_mask. These are
     * special, so map them now.
     */
    for (idx = 0; idx < PKA_PHYS_REG_FIRST_MAPPABLE; idx++) {
        virt_reg_is_mapped[idx] = true;
        virt_reg_phys_reg[idx] = idx;
        P_CC3XX->pka.memory_map[idx] =
            pka_addr_from_byte_addr(pka_state.reg_size * idx);
        virt_reg_sram_addr[idx] =
            pka_addr_from_byte_addr(pka_state.reg_size * idx);
    }

    /* Then reserve all but two regions for the general purpose registers */
    for (; idx < pka_reg_am_max - 2; idx++) {
        virt_reg_sram_addr[idx] =
            pka_addr_from_byte_addr(pka_state.reg_size * idx);
        virt_reg_is_mapped[idx] = 0;
        virt_reg_phys_reg[idx] = 0;
    }

    P_CC3XX->pka.memory_map[PKA_PHYS_REG_TEMP_0] =
        pka_addr_from_byte_addr(pka_state.reg_size * idx);

    idx++;

    P_CC3XX->pka.memory_map[PKA_PHYS_REG_TEMP_1] =
        pka_addr_from_byte_addr(pka_state.reg_size * idx);

    /* We don't count the temporary registers in reg_am_max, since it's used for
     * verifying parameters of functions, and these should never be used as
     * parameters */
    pka_reg_am_max -= 2;
}

void cc3xx_lowlevel_pka_init(uint32_t size)
{
    cc3xx_lowlevel_pka_uninit();

    /* Minimum size is 16 bytes (128 bits), but just transparently increase it
     * if needed
     */
    if (size < 16) {
        size = 16;
    }

    /* Max size of an operation is 256 bytes (2048 bits). The actual max size is
     * 2112 bits, but 64 bits of overflow are required. */
    assert(size <= 256);

    /* Calculate the register size based on the requested operation size + the
     * size by which operations can overflow */
    pka_state.reg_size = pad_to_pka_word_size(size + PKA_MAX_OVERFLOW_SIZE);
    pka_state.virt_reg_next_mapped = PKA_VIRT_REG_FIRST_ALLOCATABLE;

    pka_init_from_state();

    pka_state.initialized = true;
}

bool cc3xx_lowlevel_pka_is_initialized(void)
{
    return pka_state.initialized;
}

static void allocate_phys_reg(cc3xx_pka_reg_id_t virt_reg)
{
    uint32_t phys_reg;

    assert(phys_reg_next_mapped <= PKA_PHYS_REG_LAST_MAPPABLE);
    assert(phys_reg_mapping_list[PKA_PHYS_REG_TEMP_0] == 0);
    assert(phys_reg_mapping_list[PKA_PHYS_REG_TEMP_1] == 0);

    phys_reg = phys_reg_next_mapped;
    phys_reg_next_mapped += 1;

    while(!P_CC3XX->pka.pka_done) {}
    P_CC3XX->pka.memory_map[phys_reg] = virt_reg_sram_addr[virt_reg];
    while(!P_CC3XX->pka.pka_done) {}

    phys_reg_mapping_list[phys_reg] = virt_reg;
    virt_reg_is_mapped[virt_reg] = true;
    virt_reg_phys_reg[virt_reg] = phys_reg;
}

cc3xx_pka_reg_id_t cc3xx_lowlevel_pka_allocate_reg(void)
{
    cc3xx_pka_reg_id_t reg_id = 0;

    reg_id = pka_state.virt_reg_next_mapped;
    assert(reg_id != pka_reg_am_max);

    pka_state.virt_reg_next_mapped += 1;

    virt_reg_in_use[reg_id] = true;

    return reg_id;
}

/* To make this faster, it's only possible to free the most recently allocated
 * register. Register freeing must match this pattern.
 */
void cc3xx_lowlevel_pka_free_reg(cc3xx_pka_reg_id_t reg_id)
{
    assert(reg_id == pka_state.virt_reg_next_mapped - 1);
    assert(virt_reg_in_use[reg_id]);

    pka_state.virt_reg_next_mapped -= 1;

    virt_reg_in_use[reg_id] = false;
}

static void CC3XX_ATTRIBUTE_INLINE ensure_virt_reg_is_mapped(cc3xx_pka_reg_id_t reg_id)
{
    assert(reg_id <= pka_reg_am_max);

    if (!virt_reg_is_mapped[reg_id]) {
        allocate_phys_reg(reg_id);
    }
}

static void pka_write_reg(cc3xx_pka_reg_id_t reg_id, const uint32_t *data,
                          size_t len, bool swap_endian)
{
    size_t idx;
    size_t unaligned_bytes = len & (sizeof(uint32_t) - 1);

#ifdef CC3XX_CONFIG_STRICT_UINT32_T_ALIGNMENT
    /* Check alignment */
    assert(((uintptr_t)data & (sizeof(uint32_t) - 1)) == 0);
    assert((len & (sizeof(uint32_t) - 1)) == 0);
#endif

    /* Check slot */
    assert(reg_id < pka_reg_am_max);
    assert(virt_reg_in_use[reg_id]);
    assert(len <= pka_state.reg_size);

    /* clear the register */
    cc3xx_lowlevel_pka_clear(reg_id);

    /* Make sure we have a physical register mapped for the virtual register */
    ensure_virt_reg_is_mapped(reg_id);

    /* Wait for any outstanding operations to finish before performing reads or
     * writes on the PKA SRAM
     */
    while(!P_CC3XX->pka.pka_done) {}
    P_CC3XX->pka.pka_sram_addr =
        P_CC3XX->pka.memory_map[virt_reg_phys_reg[reg_id]];
    while(!P_CC3XX->pka.pka_done) {}

#ifndef CC3XX_CONFIG_STRICT_UINT32_T_ALIGNMENT
    if (swap_endian && (unaligned_bytes > 0)) {
        uint32_t word;

        /* len = 4 is covered outside this scope */
        while(len > sizeof(uint32_t)) {
            uint8_t *data_b = (uint8_t *) data + len - sizeof(uint32_t);

            word = data_b[0] << 24 | data_b[1] << 16 | data_b[2] << 8 | data_b[3];
            P_CC3XX->pka.pka_sram_wdata = word;
            while(!P_CC3XX->pka.pka_done) {}
            len -= sizeof(uint32_t);
        }

        /* Last unaligned word */
        word = bswap_32(data[0]);
        word >>= (8 * (sizeof(uint32_t) - unaligned_bytes));

        P_CC3XX->pka.pka_sram_wdata = word;
        while(!P_CC3XX->pka.pka_done) {}

        return;
    }
#endif

    /* Write data */
    for (idx = 0; idx < len / sizeof(uint32_t); idx++) {
        P_CC3XX->pka.pka_sram_wdata = swap_endian ? bswap_32(data[(len / sizeof(uint32_t) - 1) - idx])
                                                  : data[idx];
        while(!P_CC3XX->pka.pka_done) {}
    }

#ifndef CC3XX_CONFIG_STRICT_UINT32_T_ALIGNMENT
    /* Unaligned and little endian */
    if (unaligned_bytes > 0) {
        uint32_t word = 0;
        memcpy(&word, data + len / sizeof(uint32_t), unaligned_bytes);

        P_CC3XX->pka.pka_sram_wdata = word;
        while(!P_CC3XX->pka.pka_done) {}
    }
#endif
}

void cc3xx_lowlevel_pka_write_reg_swap_endian(cc3xx_pka_reg_id_t reg_id, const uint32_t *data,
                                     size_t len)
{
    pka_write_reg(reg_id, (uint32_t *)data, len, true);
}

void cc3xx_lowlevel_pka_write_reg(cc3xx_pka_reg_id_t reg_id, const uint32_t *data, size_t len)
{
    pka_write_reg(reg_id, data, len, false);
}

static void pka_read_reg(cc3xx_pka_reg_id_t reg_id, uint32_t *data, size_t len,
                         bool swap_endian)
{
    size_t idx;
    size_t unaligned_bytes = len & (sizeof(uint32_t) - 1);

#ifdef CC3XX_CONFIG_STRICT_UINT32_T_ALIGNMENT
    /* Check alignment */
    assert(((uintptr_t)data & (sizeof(uint32_t) - 1)) == 0);
    assert((len & (sizeof(uint32_t) - 1)) == 0);
#endif

    /* Check slot */
    assert(reg_id < pka_reg_am_max);
    assert(virt_reg_in_use[reg_id]);
    assert(len <= pka_state.reg_size);

    /* Make sure we have a physical register mapped for the virtual register */
    ensure_virt_reg_is_mapped(reg_id);

    /* The PKA registers can be remapped by the hardware (by swapping value
     * values of the memory_map registers), so we need to read the memory_map
     * register to find the correct address.
     */
    while(!P_CC3XX->pka.pka_done) {}
    P_CC3XX->pka.pka_sram_raddr =
        P_CC3XX->pka.memory_map[virt_reg_phys_reg[reg_id]];
    while(!P_CC3XX->pka.pka_done) {}

#ifndef CC3XX_CONFIG_STRICT_UINT32_T_ALIGNMENT
    if (swap_endian && (unaligned_bytes > 0)) {
        uint32_t word;

        /* len = 4 is covered outside this scope */
        while(len > sizeof(uint32_t)) {
            uint8_t *data_b = (uint8_t *) data + len - sizeof(uint32_t);

            word = bswap_32(P_CC3XX->pka.pka_sram_rdata);
            memcpy(data_b, &word, sizeof(uint32_t));
            len -= sizeof(uint32_t);
        }

        /* Last unaligned word */
        word = bswap_32(P_CC3XX->pka.pka_sram_rdata);
        memcpy(data, ((uint8_t *) &word) + (sizeof(uint32_t) - unaligned_bytes), unaligned_bytes);

        return;
    }
#endif

    /* Copy aligned words */
    for (idx = 0; idx < len / sizeof(uint32_t); idx++) {
        if (swap_endian) {
            data[(len / sizeof(uint32_t) -1) - idx] = bswap_32(P_CC3XX->pka.pka_sram_rdata);
        } else {
            data[idx] = P_CC3XX->pka.pka_sram_rdata;
        }
    }

#ifndef CC3XX_CONFIG_STRICT_UINT32_T_ALIGNMENT
    /* Copy remaining unaligned bytes for little endian */
    if (unaligned_bytes > 0) {
        uint32_t word = P_CC3XX->pka.pka_sram_rdata;
        memcpy(data + len / sizeof(uint32_t), &word, unaligned_bytes);
    }
#endif
}

void cc3xx_lowlevel_pka_read_reg(cc3xx_pka_reg_id_t reg_id, uint32_t *data, size_t len)
{
    pka_read_reg(reg_id, data, len, false);
}

void cc3xx_lowlevel_pka_read_reg_swap_endian(cc3xx_pka_reg_id_t reg_id, uint32_t *data, size_t len)
{
    pka_read_reg(reg_id, (uint32_t *)data, len, true);
}

/* Calculate the Barrett Tag (https://en.wikipedia.org/wiki/Barrett_reduction)
 * to enable reduction modulo N. If this tag is not calculated, reduction
 * operations will fail. doi:10.1007/3-540-47721-7_24 is good reference.
 *
 * We are attempting to calculate 2^k / N. In the reference the value k = 2 * n
 * where n is the bit-length of N is chosen due to the max value to be reduced
 * being representable in 2 * n bits. In the previous driver, instead k = n + 64
 * (which is the PKA word size), which means the max value to be reduced must be
 * representable in n + 64 bits. It is assumed, but not certain, that this holds
 * because of how the reduction in hardware is being calculated.
 */
#ifdef CC3XX_CONFIG_PKA_CALC_NP_ENABLE
static inline void calc_Np(void)
{
    cc3xx_pka_reg_id_t reg_temp_0 = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_pka_reg_id_t reg_temp_1 = cc3xx_lowlevel_pka_allocate_reg();
    uint32_t N_bit_size = cc3xx_lowlevel_pka_get_bit_size(CC3XX_PKA_REG_N);
    uint32_t power;

    /* If N is large, we perform a special-case operation to avoid having to
     * generate 2^n, which may be large. In this case, we first divide N by
     * 2^(N_bit_size2 * PKA_WORD_BIT_SIZE) and then divide the constant 2^(3 *
     * PKA_WORD_SIZE) by the result, meaning the largest number we need to
     * synthesize in a register is 2^(3 * PKA_WORD_BIT_SIZE). This is done so
     * that if the modulus size is the maximum 2048 bits, then the largest
     * synthesized number fits into the 2112 bit register+overflow size.
     */
    if (N_bit_size > PKA_MAX_OVERFLOW_BIT_SIZE * 2) {
        power = PKA_MAX_OVERFLOW_BIT_SIZE * 3 - 1;
        cc3xx_lowlevel_pka_set_to_power_of_two(reg_temp_0, power);

        /* Divide N by 2^(N_bit_size - 2 * PKA_MAX_OVERFLOW_BIT_SIZE) */
        power = N_bit_size - 2 * PKA_MAX_OVERFLOW_BIT_SIZE;
        cc3xx_lowlevel_pka_shift_right_fill_0_ui(CC3XX_PKA_REG_N, power, reg_temp_1);

        /* Ceiling */
        cc3xx_lowlevel_pka_add_si(reg_temp_1, 1, reg_temp_1);
        cc3xx_lowlevel_pka_div(reg_temp_0, reg_temp_1, CC3XX_PKA_REG_NP, reg_temp_1);
    } else {
        /* set r0 to 2^(N_bit_size + PKA_WORD_SIZE - 1) */
        power = N_bit_size + PKA_MAX_OVERFLOW_BIT_SIZE - 1;
        cc3xx_lowlevel_pka_set_to_power_of_two(reg_temp_0, power);

        /* Finally, perform the division */
        cc3xx_lowlevel_pka_div(reg_temp_0, CC3XX_PKA_REG_N, CC3XX_PKA_REG_NP, reg_temp_1);
    }

    cc3xx_lowlevel_pka_free_reg(reg_temp_1);
    cc3xx_lowlevel_pka_free_reg(reg_temp_0);
}
#endif /* CC3XX_CONFIG_PKA_CALC_NP_ENABLE */

void cc3xx_lowlevel_pka_set_modulus(cc3xx_pka_reg_id_t modulus, bool calculate_tag,
                                    cc3xx_pka_reg_id_t barrett_tag)
{
    uint32_t N_bit_size;

    assert(modulus < pka_reg_am_max);
    assert(virt_reg_in_use[modulus]);

    virt_reg_in_use[CC3XX_PKA_REG_N] = true;
    cc3xx_lowlevel_pka_copy(modulus, CC3XX_PKA_REG_N);

    /* This operation size must correspond exactly to the bit-size of the
     * modulus, so a bit-counting operation is performed.
     */
    N_bit_size = cc3xx_lowlevel_pka_get_bit_size(CC3XX_PKA_REG_N);
    P_CC3XX->pka.pka_l[PKA_OP_SIZE_N] = N_bit_size;

    virt_reg_in_use[CC3XX_PKA_REG_N_MASK] = true;
    cc3xx_lowlevel_pka_set_to_power_of_two(CC3XX_PKA_REG_N_MASK, N_bit_size);
    cc3xx_lowlevel_pka_sub_si(CC3XX_PKA_REG_N_MASK, 1, CC3XX_PKA_REG_N_MASK);

#ifndef CC3XX_CONFIG_PKA_CALC_NP_ENABLE
    assert(!calculate_tag);
#endif /* !CC3XX_CONFIG_PKA_CALC_NP_ENABLE */

    virt_reg_in_use[CC3XX_PKA_REG_NP] = true;
    if (calculate_tag) {
#ifdef CC3XX_CONFIG_PKA_CALC_NP_ENABLE
        calc_Np();
#endif /* CC3XX_CONFIG_PKA_CALC_NP_ENABLE */
    } else {
        assert(barrett_tag < pka_reg_am_max);
        assert(virt_reg_in_use[barrett_tag]);

        cc3xx_lowlevel_pka_copy(barrett_tag, CC3XX_PKA_REG_NP);
    }
}

void cc3xx_lowlevel_pka_get_state(struct cc3xx_pka_state_t *state, uint32_t save_reg_am,
                                  cc3xx_pka_reg_id_t *save_reg_list,
                                  uint32_t **save_reg_ptr_list,
                                  const size_t *save_reg_size_list)
{
    size_t idx;
    cc3xx_pka_reg_id_t reg_id;

    memcpy(state, &pka_state, sizeof(*state));

    for (idx = 0; idx < save_reg_am; idx++) {
        reg_id = save_reg_list[idx];
        assert(reg_id < pka_reg_am_max);
        assert(virt_reg_in_use[reg_id]);

        cc3xx_lowlevel_pka_read_reg(reg_id, save_reg_ptr_list[idx], save_reg_size_list[idx]);
    }
}

void cc3xx_lowlevel_pka_set_state(const struct cc3xx_pka_state_t *state,
                                  uint32_t load_reg_am, cc3xx_pka_reg_id_t *load_reg_list,
                                  const uint32_t **load_reg_ptr_list,
                                  const size_t *load_reg_size_list)
{
    size_t idx;
    cc3xx_pka_reg_id_t reg_id;

    memcpy(&pka_state, state, sizeof(*state));

    pka_init_from_state();

    for (idx = 0; idx < load_reg_am; idx++) {
        reg_id = load_reg_list[idx];
        assert(reg_id < pka_reg_am_max);
        assert(virt_reg_in_use[reg_id]);

        cc3xx_lowlevel_pka_write_reg(reg_id, load_reg_ptr_list[idx], load_reg_size_list[idx]);
    }
}

void cc3xx_lowlevel_pka_uninit(void)
{
    pka_state.initialized = false;

    memset(&pka_state, 0, sizeof(pka_state));
    memset(virt_reg_in_use, 0, sizeof(virt_reg_in_use));
    memset(virt_reg_is_mapped, 0, sizeof(virt_reg_is_mapped));
    memset(virt_reg_phys_reg, 0, sizeof(virt_reg_phys_reg));
    memset(virt_reg_sram_addr, 0, sizeof(virt_reg_sram_addr));
    memset(virt_reg_needs_n_mask, 0, sizeof(virt_reg_needs_n_mask));
    memset(phys_reg_mapping_list, 0, sizeof(phys_reg_mapping_list));
    phys_reg_next_mapped = 0;

    P_CC3XX->misc.pka_clk_enable = 0;
}

static uint32_t CC3XX_ATTRIBUTE_INLINE opcode_construct(enum cc3xx_pka_operation_t op,
                                                        enum pka_op_size_t size,
                                                        bool r0_is_immediate, uint32_t r0,
                                                        bool r1_is_immediate, uint32_t r1,
                                                        bool discard_result, uint32_t res)
{
    uint32_t opcode = 0;

    /* The tag part of the opcode register is designed to be used to debug PKA
     * operations, but we don't use this functionality. For some of the opcodes
     * that aren't documented in the TRM, this is used as a third register
     * input.
     */
    /* opcode |= r3 & 0b11111; */

    /* The top bit of the output register select is a field which if set
     * prevents the operation writing the output register (or more accurately,
     * prevents the swapping of the virtual address of the output register and
     * the temporary register). The pka_status register is still set, so flags
     * such as the sign of the result can still be used.
     */
    if (!discard_result) {
        assert(res < pka_reg_am_max);
        assert(virt_reg_in_use[res]);
        /* Make sure we have a physical register mapped for the virtual register */
        ensure_virt_reg_is_mapped(res);
        opcode |= (virt_reg_phys_reg[res] & 0b11111) << 6;
    } else {
        opcode |= (discard_result & 0b1) << 11;
    }

    /* The top bit of the REG_A field is a toggle between being a register ID
     * and an immediate, and the lower 5 bits give us either a 0-31 register ID,
     * a -16-15 signed immediate or a 0-31 unsigned immediate depending on the
     * operation.
     */
    if (r1_is_immediate) {
        opcode |= (r1_is_immediate & 0b1) << 17;
        opcode |= (r1 & 0b11111) << 12;
    } else {
        assert(r1 >= 0);
        assert(r1 < pka_reg_am_max);
        assert(virt_reg_in_use[r1]);
        /* Make sure we have a physical register mapped for the virtual register */
        ensure_virt_reg_is_mapped(r1);
        opcode |= (virt_reg_phys_reg[r1] & 0b11111) << 12;
    }

    /* For unclear reasons, the immediate (shift amount) for shift opcodes
     * doesn't use the upper bit to denote that it isn't a register.
     * Possibly because this opcode doesn't support register input?
     */
    if (op >= CC3XX_PKA_OPCODE_SHR0 && op <= CC3XX_PKA_OPCODE_SHL1) {
        opcode &= ~(0b1 << 17);
    }

    /* The top bit of the REG_B field is a toggle between being a register ID
     * and an immediate, and the lower 5 bits give us either a 0-31 register ID,
     * a -16-15 signed immediate or a 0-31 unsigned immediate depending on the
     * operation.
     */
    if (r0_is_immediate) {
        opcode |= (r0_is_immediate & 0b1) << 23;
        opcode |= (r0 & 0b11111) << 18;
    } else {
        assert(r0 >= 0);
        assert(r0 <= pka_reg_am_max);
        assert(virt_reg_in_use[r0]);
        /* Make sure we have a physical register mapped for the virtual register */
        ensure_virt_reg_is_mapped(r0);
        opcode |= (virt_reg_phys_reg[r0] & 0b11111) << 18;
    }

    if (!r0_is_immediate) {
        assert(virt_reg_is_mapped[r0]);
    }

    if (!r1_is_immediate) {
        assert(virt_reg_is_mapped[r1]);
        if (!r0_is_immediate && r0 != r1) {
            assert(virt_reg_phys_reg[r1] != virt_reg_phys_reg[r0]);
        }
    }

    if (!discard_result) {
        assert(virt_reg_is_mapped[res]);
        if (!r0_is_immediate && r0 != res) {
            assert(virt_reg_phys_reg[res] != virt_reg_phys_reg[r0]);
        }
        if (!r1_is_immediate && r1 != res) {
            assert(virt_reg_phys_reg[res] != virt_reg_phys_reg[r1]);
        }
    }

    /* Select which of the pka_l register is used for the bit-length of the
     * operation.
     */
    opcode |= (size & 0b111) << 24;

    /* Set the actual operation */
    opcode |= (op & 0b11111) << 27;

    /* Wait for a pipeline slot to be free before submitting this operation.
     * Note that the previous operations may still be in progress at this point.
     */
    while(!P_CC3XX->pka.pka_pipe_rdy) {}

    return opcode;
}

uint32_t cc3xx_lowlevel_pka_get_bit_size(cc3xx_pka_reg_id_t r0)
{
    int32_t idx;
    uint32_t word;

    ensure_virt_reg_is_mapped(r0);

    /* This isn't an operation that can use the PKA pipeline, so we need to wait
     * for the pipeline to be finished before reading the SRAM.
     */
    while(!P_CC3XX->pka.pka_done) {}

    for (idx = pka_state.reg_size - sizeof(uint32_t); idx >= 0;
        idx -= sizeof(uint32_t)) {
        P_CC3XX->pka.pka_sram_raddr =
            P_CC3XX->pka.memory_map[virt_reg_phys_reg[r0]] +
            pka_addr_from_byte_addr(idx);
        while(!P_CC3XX->pka.pka_done) {}

        word = P_CC3XX->pka.pka_sram_rdata;

        if (word) {
            break;
        }
    }

    if (idx < 0) {
        return 0;
    } else {
        return idx * 8 + (32 - __builtin_clz(word));
    }
}

void cc3xx_lowlevel_pka_set_to_power_of_two(cc3xx_pka_reg_id_t r0, uint32_t power)
{
    uint32_t final_word = 1 << (power % (sizeof(uint32_t) * 8));
    uint32_t word_offset = power / (8 * sizeof(uint32_t));

    cc3xx_lowlevel_pka_clear(r0);

    ensure_virt_reg_is_mapped(r0);

    /* This isn't an operation that can use the PKA pipeline, so we need to wait
     * for the pipeline to be finished before reading the SRAM.
     */
    while(!P_CC3XX->pka.pka_done) {}

    P_CC3XX->pka.pka_sram_addr =
        P_CC3XX->pka.memory_map[virt_reg_phys_reg[r0]] + word_offset;
    while(!P_CC3XX->pka.pka_done) {}

    P_CC3XX->pka.pka_sram_wdata = final_word;
    while(!P_CC3XX->pka.pka_done) {}
}

#ifdef CC3XX_CONFIG_RNG_ENABLE
cc3xx_err_t cc3xx_lowlevel_pka_set_to_random(cc3xx_pka_reg_id_t r0, size_t bit_len)
{
    uint32_t byte_size = (bit_len + 7) / 8;
    uint32_t word_size = (byte_size + 3) / sizeof(uint32_t);
    uint32_t random_buf[word_size];
    cc3xx_err_t err;

    err = cc3xx_lowlevel_rng_get_random((uint8_t *)random_buf, word_size * sizeof(uint32_t),
                                        CC3XX_RNG_DRBG);
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

    /* Take off any extra bits */
    if ((bit_len % 32) > 0) {
        random_buf[word_size - 1] = random_buf[word_size - 1] >> (32 - (bit_len % 32));
    }

    cc3xx_lowlevel_pka_write_reg(r0, random_buf, sizeof(random_buf));

    /* Clear the generated random words from the stack */
    memset(random_buf, 0 , sizeof(random_buf));

    return CC3XX_ERR_SUCCESS;
}

cc3xx_err_t cc3xx_lowlevel_pka_set_to_random_within_modulus(cc3xx_pka_reg_id_t r0)
{
    cc3xx_err_t err;
    assert(virt_reg_in_use[CC3XX_PKA_REG_N]);

    do {
        /* This uses the simple discard method from SP800-90A, because the modular
         * methods are impractical due to the pka_reduce function not working for
         * numbers significantly greater than OP_SIZE_N.
         */
        err = cc3xx_lowlevel_pka_set_to_random(r0, P_CC3XX->pka.pka_l[PKA_OP_SIZE_N]);
        if (err != CC3XX_ERR_SUCCESS) {
            return err;
        }
    } while (!cc3xx_lowlevel_pka_less_than(r0, CC3XX_PKA_REG_N));

    return CC3XX_ERR_SUCCESS;
}
#endif /* CC3XX_CONFIG_RNG_ENABLE */

void cc3xx_lowlevel_pka_add(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t r1, cc3xx_pka_reg_id_t res)
{
    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_ADD_INC,
                                           PKA_OP_SIZE_REGISTER,
                                           false, r0, false, r1, false, res);
}

void cc3xx_lowlevel_pka_add_si(cc3xx_pka_reg_id_t r0, int32_t imm, cc3xx_pka_reg_id_t res)
{
    assert(imm <= PKA_MAX_SIGNED_IMMEDIATE);
    assert(imm >= PKA_MIN_SIGNED_IMMEDIATE);

    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_ADD_INC,
                                           PKA_OP_SIZE_REGISTER,
                                           false, r0, true, imm, false, res);
}

void cc3xx_lowlevel_pka_sub(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t r1, cc3xx_pka_reg_id_t res)
{
    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_SUB_DEC_NEG,
                                           PKA_OP_SIZE_REGISTER,
                                           false, r0, false, r1, false, res);
}

void cc3xx_lowlevel_pka_sub_si(cc3xx_pka_reg_id_t r0, int32_t imm, cc3xx_pka_reg_id_t res)
{
    assert(imm <= PKA_MAX_SIGNED_IMMEDIATE);
    assert(imm >= PKA_MIN_SIGNED_IMMEDIATE);

    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_SUB_DEC_NEG,
                                           PKA_OP_SIZE_REGISTER,
                                           false, r0, true, imm, false, res);
}

void cc3xx_lowlevel_pka_neg(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t res)
{
    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_SUB_DEC_NEG,
                                           PKA_OP_SIZE_REGISTER,
                                           true, 0, false, r0, false, res);
}

void cc3xx_lowlevel_pka_mod_add(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t r1, cc3xx_pka_reg_id_t res)
{
    assert(virt_reg_in_use[CC3XX_PKA_REG_N]);
    assert(cc3xx_lowlevel_pka_less_than(r0, CC3XX_PKA_REG_N));
    assert(cc3xx_lowlevel_pka_less_than(r1, CC3XX_PKA_REG_N));

    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_MODADD_MODINC,
                                           PKA_OP_SIZE_REGISTER,
                                           false, r0, false, r1, false, res);
}

void cc3xx_lowlevel_pka_mod_add_si(cc3xx_pka_reg_id_t r0, int32_t imm, cc3xx_pka_reg_id_t res)
{
    assert(virt_reg_in_use[CC3XX_PKA_REG_N]);

    assert(imm <= PKA_MAX_SIGNED_IMMEDIATE);
    assert(imm >= PKA_MIN_SIGNED_IMMEDIATE);

    assert(cc3xx_lowlevel_pka_less_than(r0, CC3XX_PKA_REG_N));
    assert(cc3xx_lowlevel_pka_greater_than_si(CC3XX_PKA_REG_N, imm));

    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_MODADD_MODINC,
                                           PKA_OP_SIZE_REGISTER,
                                           false, r0, true, imm, false, res);
}

void cc3xx_lowlevel_pka_mod_sub(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t r1, cc3xx_pka_reg_id_t res)
{
    assert(virt_reg_in_use[CC3XX_PKA_REG_N]);
    assert(cc3xx_lowlevel_pka_less_than(r0, CC3XX_PKA_REG_N));
    assert(cc3xx_lowlevel_pka_less_than(r1, CC3XX_PKA_REG_N));

    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_MODSUB_MODDEC_MODNEG,
                                           PKA_OP_SIZE_REGISTER,
                                           false, r0, false, r1, false, res);
}

void cc3xx_lowlevel_pka_mod_sub_si(cc3xx_pka_reg_id_t r0, int32_t imm, cc3xx_pka_reg_id_t res)
{
    assert(virt_reg_in_use[CC3XX_PKA_REG_N]);

    assert(imm <= PKA_MAX_SIGNED_IMMEDIATE);
    assert(imm >= PKA_MIN_SIGNED_IMMEDIATE);

    assert(cc3xx_lowlevel_pka_less_than(r0, CC3XX_PKA_REG_N));
    assert(cc3xx_lowlevel_pka_greater_than_si(CC3XX_PKA_REG_N, imm));

    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_MODSUB_MODDEC_MODNEG,
                                           PKA_OP_SIZE_REGISTER,
                                           false, r0, true, imm, false, res);
}

void cc3xx_lowlevel_pka_mod_neg(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t res)
{
    assert(virt_reg_in_use[CC3XX_PKA_REG_N]);
    assert(cc3xx_lowlevel_pka_less_than(r0, CC3XX_PKA_REG_N));

    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_MODSUB_MODDEC_MODNEG,
                                           PKA_OP_SIZE_REGISTER,
                                           true, 0, false, r0, false, res);
}

void cc3xx_lowlevel_pka_and(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t r1, cc3xx_pka_reg_id_t res)
{
    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_AND_TST0_CLR0,
                                           PKA_OP_SIZE_REGISTER,
                                           false, r0, false, r1, false, res);
}

void cc3xx_lowlevel_pka_and_si(cc3xx_pka_reg_id_t r0, uint32_t mask, cc3xx_pka_reg_id_t res)
{
    assert(mask <= PKA_MAX_UNSIGNED_IMMEDIATE);

    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_AND_TST0_CLR0,
                                           PKA_OP_SIZE_REGISTER,
                                           false, r0, true, mask, false, res);
}

uint32_t cc3xx_lowlevel_pka_test_bits_ui(cc3xx_pka_reg_id_t r0, uint32_t idx, uint32_t bit_am)
{
    uint32_t bits;
    uint32_t word_offset = idx / (8 * sizeof(uint32_t));

    assert(bit_am <= 4);
    /* This prevents us from needing to read two words */
    assert(idx % bit_am == 0);

    ensure_virt_reg_is_mapped(r0);

    while(!P_CC3XX->pka.pka_done) {}
    P_CC3XX->pka.pka_sram_raddr =
        P_CC3XX->pka.memory_map[virt_reg_phys_reg[r0]] + word_offset;
    while(!P_CC3XX->pka.pka_done) {}

    bits = (P_CC3XX->pka.pka_sram_rdata >> (idx % 32)) & ((1 << bit_am) - 1);
    while(!P_CC3XX->pka.pka_done) {}

    /* Return the inverted value of ALU_OUT_ZERO */
    return bits;
}

void cc3xx_lowlevel_pka_clear_bit(cc3xx_pka_reg_id_t r0, uint32_t idx, cc3xx_pka_reg_id_t res)
{
    /* Check that we can construct the required mask */
    assert((0x1 << idx) <= PKA_MAX_UNSIGNED_IMMEDIATE);

    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_AND_TST0_CLR0,
                                           PKA_OP_SIZE_REGISTER,
                                           false, r0, true, ~(1 << idx), false, res);
}

/* When PKA SRAM parity is enabled. CC3XX_PKA_OPCODE_AND_TST0_CLR0 opcode should not be used
 * to clear a PKA SRAM region, associated with the input register. Such opcode performs
 * a read-modify-write sequence which may trigger a parity error if the SRAM region
 * was never written to before.
 */
void cc3xx_lowlevel_pka_clear(cc3xx_pka_reg_id_t r0)
{
    /* The TRM says that this register is a byte-size, but it is in fact a
     * bit-size.
     */
    size_t reg_size = P_CC3XX->pka.pka_l[PKA_OP_SIZE_REGISTER] / 8;

    ensure_virt_reg_is_mapped(r0);

    /* Wait for any outstanding operations to finish before performing reads or
     * writes on the PKA SRAM
     */
    while(!P_CC3XX->pka.pka_done) {}
    P_CC3XX->pka.pka_sram_addr =
        P_CC3XX->pka.memory_map[virt_reg_phys_reg[r0]];
    while(!P_CC3XX->pka.pka_done) {}

    for (size_t idx = 0; idx < reg_size / sizeof(uint32_t); idx++) {
        P_CC3XX->pka.pka_sram_wdata = 0x0;
        while(!P_CC3XX->pka.pka_done) {}
    }
}

void cc3xx_lowlevel_pka_or(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t r1, cc3xx_pka_reg_id_t res)
{
    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_OR_COPY_SET0,
                                           PKA_OP_SIZE_REGISTER,
                                           false, r0, false, r1, false, res);
}

void cc3xx_lowlevel_pka_or_si(cc3xx_pka_reg_id_t r0, uint32_t mask, cc3xx_pka_reg_id_t res)
{
    assert(mask <= PKA_MAX_UNSIGNED_IMMEDIATE);

    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_OR_COPY_SET0,
                                           PKA_OP_SIZE_REGISTER,
                                           false, r0, true, mask, false, res);
}

void cc3xx_lowlevel_pka_copy(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t res)
{
    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_OR_COPY_SET0,
                                           PKA_OP_SIZE_REGISTER,
                                           false, r0, true, 0, false, res);
}

void cc3xx_lowlevel_pka_set_bit(cc3xx_pka_reg_id_t r0, uint32_t idx, cc3xx_pka_reg_id_t res)
{
    assert(idx < 32);

    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_AND_TST0_CLR0,
                                           PKA_OP_SIZE_REGISTER,
                                           false, r0, true, 1 << idx, false, res);
}

void cc3xx_lowlevel_pka_xor(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t r1, cc3xx_pka_reg_id_t res)
{
    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_XOR_FLIP0_INVERT_COMPARE,
                                           PKA_OP_SIZE_REGISTER,
                                           false, r0, false, r1, false, res);
}

void cc3xx_lowlevel_pka_xor_si(cc3xx_pka_reg_id_t r0, uint32_t mask, cc3xx_pka_reg_id_t res)
{
    assert(mask <= PKA_MAX_UNSIGNED_IMMEDIATE);

    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_XOR_FLIP0_INVERT_COMPARE,
                                           PKA_OP_SIZE_REGISTER,
                                           false, r0, true, mask, false, res);
}

void cc3xx_lowlevel_pka_flip_bit(cc3xx_pka_reg_id_t r0, uint32_t idx, cc3xx_pka_reg_id_t res)
{
    assert(idx < 32);

    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_XOR_FLIP0_INVERT_COMPARE,
                                           PKA_OP_SIZE_REGISTER,
                                           false, r0, true, 1 << idx, false, res);
}

bool cc3xx_lowlevel_pka_are_equal(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t r1)
{
    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_XOR_FLIP0_INVERT_COMPARE,
                                           PKA_OP_SIZE_REGISTER,
                                           false, r0, false, r1, true, 0);


    /* We need the pipeline to finish before we read the status register for the
     * result.
     */
    while(!P_CC3XX->pka.pka_done) {}

    /* Return ALU_OUT_ZERO */
    return P_CC3XX->pka.pka_status & (0b1 << 12);
}

bool cc3xx_lowlevel_pka_are_equal_si(cc3xx_pka_reg_id_t r0, int32_t imm)
{
    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_XOR_FLIP0_INVERT_COMPARE,
                                           PKA_OP_SIZE_REGISTER,
                                           false, r0, true, imm, true, 0);


    /* We need the pipeline to finish before we read the status register for the
     * result.
     */
    while(!P_CC3XX->pka.pka_done) {}

    /* Return ALU_OUT_ZERO */
    return P_CC3XX->pka.pka_status & (0b1 << 12);
}

bool cc3xx_lowlevel_pka_less_than(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t r1)
{
    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_SUB_DEC_NEG,
                                           PKA_OP_SIZE_REGISTER,
                                           false, r0, false, r1, true, 0);

    /* Wait for the pipeline to be finished before reading the pka status
     * register.
     */
    while(!P_CC3XX->pka.pka_done) {}

    /* Return the value of ALU_SIGN_OUT */
    return P_CC3XX->pka.pka_status & (0b1 << 8);
}

bool cc3xx_lowlevel_pka_less_than_si(cc3xx_pka_reg_id_t r0, int32_t imm)
{
    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_SUB_DEC_NEG,
                                           PKA_OP_SIZE_REGISTER,
                                           false, r0, true, imm, true, 0);

    /* Wait for the pipeline to be finished before reading the pka status
     * register.
     */
    while(!P_CC3XX->pka.pka_done) {}

    /* Return the value of ALU_SIGN_OUT */
    return P_CC3XX->pka.pka_status & (0b1 << 8);
}

bool cc3xx_lowlevel_pka_greater_than(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t r1)
{
    return !cc3xx_lowlevel_pka_less_than(r0, r1)
        && !cc3xx_lowlevel_pka_are_equal(r0, r1);
}

bool cc3xx_lowlevel_pka_greater_than_si(cc3xx_pka_reg_id_t r0, int32_t imm)
{
    return !cc3xx_lowlevel_pka_less_than_si(r0, imm)
        && !cc3xx_lowlevel_pka_are_equal_si(r0, imm);
}

void cc3xx_lowlevel_pka_shift_right_fill_0_ui(cc3xx_pka_reg_id_t r0, uint32_t shift, cc3xx_pka_reg_id_t res)
{
    uint32_t shift_am;

    /* The shift operations shifts by 1 more than the number requested, so for
     * the sake of sensible semantics we decrease the shift number by 1.
     * Shifting by 0 is technically reasonable, but we can decrease code-size by
     * disallowing it via this assert.
     */

    if (shift == 0) {
        cc3xx_lowlevel_pka_copy(r0, res);
    }

    while(shift > 0) {
        shift_am = shift <= (PKA_MAX_UNSIGNED_IMMEDIATE + 1) ? shift : (PKA_MAX_UNSIGNED_IMMEDIATE + 1);

        P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_SHR0,
                                               PKA_OP_SIZE_REGISTER,
                                               false, r0, true, shift_am - 1, false, res);
        shift -= shift_am;
        r0 = res;
    }
}

void cc3xx_lowlevel_pka_shift_right_fill_1_ui(cc3xx_pka_reg_id_t r0, uint32_t shift, cc3xx_pka_reg_id_t res)
{
    uint32_t shift_am;

    if (shift == 0) {
        cc3xx_lowlevel_pka_copy(r0, res);
    }

    while(shift > 0) {
        shift_am = shift <= (PKA_MAX_UNSIGNED_IMMEDIATE + 1) ? shift : (PKA_MAX_UNSIGNED_IMMEDIATE + 1);

        P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_SHR1,
                                               PKA_OP_SIZE_REGISTER,
                                               false, r0, true, shift_am - 1, false, res);
        shift -= shift_am;
        r0 = res;
    }
}

void cc3xx_lowlevel_pka_shift_left_fill_0_ui(cc3xx_pka_reg_id_t r0, uint32_t shift, cc3xx_pka_reg_id_t res)
{
    uint32_t shift_am;

    if (shift == 0) {
        cc3xx_lowlevel_pka_copy(r0, res);
    }

    while(shift > 0) {
        shift_am = shift <= (PKA_MAX_UNSIGNED_IMMEDIATE + 1) ? shift : (PKA_MAX_UNSIGNED_IMMEDIATE + 1);

        P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_SHL0,
                                               PKA_OP_SIZE_REGISTER,
                                               false, r0, true, shift_am - 1, false, res);
        shift -= shift_am;
        r0 = res;
    }
}

void cc3xx_lowlevel_pka_shift_left_fill_1_ui(cc3xx_pka_reg_id_t r0, uint32_t shift, cc3xx_pka_reg_id_t res)
{
    uint32_t shift_am;

    if (shift == 0) {
        cc3xx_lowlevel_pka_copy(r0, res);
    }

    while(shift > 0) {
        shift_am = shift <= (PKA_MAX_UNSIGNED_IMMEDIATE + 1) ? shift : (PKA_MAX_UNSIGNED_IMMEDIATE + 1);

        P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_SHL1,
                                               PKA_OP_SIZE_REGISTER,
                                               false, r0, true, shift_am - 1, false, res);
        shift -= shift_am;
        r0 = res;
    }
}

void cc3xx_lowlevel_pka_mul_low_half(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t r1, cc3xx_pka_reg_id_t res)
{
    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_MULLOW,
                                           PKA_OP_SIZE_REGISTER,
                                           false, r0, false, r1, false, res);
}

void cc3xx_lowlevel_pka_mul_high_half(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t r1, cc3xx_pka_reg_id_t res)
{
    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_MULHIGH,
                                           PKA_OP_SIZE_REGISTER,
                                           false, r0, false, r1, false, res);
}

void cc3xx_lowlevel_pka_div(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t r1, cc3xx_pka_reg_id_t quotient,
                   cc3xx_pka_reg_id_t remainder)
{
    cc3xx_pka_reg_id_t temp_r0 = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_pka_reg_id_t temp_r1;

    /* Since the div operation uses r0 to store the remainder, and we want to
     * avoid clobbering input registers, perform a copy first.
     */
    cc3xx_lowlevel_pka_copy(r0, temp_r0);

    /* If r1 is also the quotient register, this produces no result. In this
     * case, copy to a temporary register.
     */
    if (r1 == quotient) {
        temp_r1 = cc3xx_lowlevel_pka_allocate_reg();
        cc3xx_lowlevel_pka_copy(r1, temp_r1);
    } else {
        temp_r1 = r1;
    }

    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_DIV,
                                           PKA_OP_SIZE_REGISTER,
                                           false, temp_r0, false, temp_r1,
                                           false, quotient);

    /* Now clobber the remainder register */
    cc3xx_lowlevel_pka_copy(temp_r0, remainder);

    if (temp_r1 != r1) {
        cc3xx_lowlevel_pka_free_reg(temp_r1);
    }
    cc3xx_lowlevel_pka_free_reg(temp_r0);
}

void cc3xx_lowlevel_pka_mod_mul(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t r1, cc3xx_pka_reg_id_t res)
{
    assert(virt_reg_in_use[CC3XX_PKA_REG_N]);
    assert(cc3xx_lowlevel_pka_less_than(r0, CC3XX_PKA_REG_N));
    assert(cc3xx_lowlevel_pka_less_than(r1, CC3XX_PKA_REG_N));

    /* This operation uses PKA_OP_SIZE_N, instead of _REGISTER. This is not
     * because it performs reduction, since mod_add uses _REGISTER, but because
     * it does not use the ALU, but the special-purpose modular multiplier.
     */
    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_MODMUL,
                                           PKA_OP_SIZE_N,
                                           false, r0, false, r1, false, res);


    /* Because this uses use OP_SIZE_N, it sometime leaves garbage bits in the
     * top words. Do a mask operation to clear these
     */
    cc3xx_lowlevel_pka_and(res, CC3XX_PKA_REG_N_MASK, res);
}

void cc3xx_lowlevel_pka_mod_mul_si(cc3xx_pka_reg_id_t r0, int32_t imm, cc3xx_pka_reg_id_t res)
{
    cc3xx_pka_reg_id_t temp_reg = cc3xx_lowlevel_pka_allocate_reg();

    assert(virt_reg_in_use[CC3XX_PKA_REG_N]);
    assert(cc3xx_lowlevel_pka_less_than(r0, CC3XX_PKA_REG_N));

    /* This operation doesn't work with negative numbers */
    assert(imm >= 0);

    /* temp_reg starts at 0, so this is effectively a set */
    cc3xx_lowlevel_pka_clear(temp_reg);
    cc3xx_lowlevel_pka_add_si(temp_reg, imm, temp_reg);

    cc3xx_lowlevel_pka_mod_mul(r0, temp_reg, res);

    cc3xx_lowlevel_pka_free_reg(temp_reg);
}

void cc3xx_lowlevel_pka_mod_exp(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t r1, cc3xx_pka_reg_id_t res)
{
    assert(virt_reg_in_use[CC3XX_PKA_REG_N]);
    assert(cc3xx_lowlevel_pka_less_than(r0, CC3XX_PKA_REG_N));
    assert(cc3xx_lowlevel_pka_less_than(r1, CC3XX_PKA_REG_N));

    /* This operation uses PKA_OP_SIZE_N, instead of _REGISTER. This is not
     * because it performs reduction, since mod_add uses _REGISTER, but because
     * it does not use the ALU, but the special-purpose modular multiplier.
     */
    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_MODEXP,
                                           PKA_OP_SIZE_N,
                                           false, r0, false, r1, false, res);

    /* Because this uses use OP_SIZE_N, it sometime leaves garbage bits in the
     * top words. Do a mask operation to clear these
     */
    cc3xx_lowlevel_pka_and(res, CC3XX_PKA_REG_N_MASK, res);
}

void cc3xx_lowlevel_pka_mod_exp_si(cc3xx_pka_reg_id_t r0, int32_t imm, cc3xx_pka_reg_id_t res)
{
    cc3xx_pka_reg_id_t temp_reg = cc3xx_lowlevel_pka_allocate_reg();

    assert(virt_reg_in_use[CC3XX_PKA_REG_N]);
    assert(cc3xx_lowlevel_pka_less_than(r0, CC3XX_PKA_REG_N));
    assert(imm <= PKA_MAX_SIGNED_IMMEDIATE);
    assert(imm >= PKA_MIN_SIGNED_IMMEDIATE);

    /* This operation doesn't work with negative numbers */
    assert(imm >= 0);

    /* temp_reg starts at 0, so this is effectively a set */
    cc3xx_lowlevel_pka_clear(temp_reg);
    cc3xx_lowlevel_pka_add_si(temp_reg, imm, temp_reg);

    cc3xx_lowlevel_pka_mod_exp(r0, temp_reg, res);

    cc3xx_lowlevel_pka_free_reg(temp_reg);
}

void cc3xx_lowlevel_pka_mod_inv(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t res)
{
    assert(virt_reg_in_use[CC3XX_PKA_REG_N]);
    assert(cc3xx_lowlevel_pka_less_than(r0, CC3XX_PKA_REG_N));

    /* MODINV changes the content of r0, therefore work on copy of r0 */
    cc3xx_pka_reg_id_t r0_copy = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_lowlevel_pka_copy(r0, r0_copy);

    /* This operation uses PKA_OP_SIZE_N, instead of _REGISTER. This is not
     * because it performs reduction, since mod_add uses _REGISTER, but because
     * it does not use the ALU, but the special-purpose modular multiplier.
     */
    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_MODINV,
                                           PKA_OP_SIZE_N,
                                           false, 0, false, r0_copy, false, res);

    /* Because this uses use OP_SIZE_N, it sometime leaves garbage bits in the
     * top words. Do a mask operation to clear these
     */
    cc3xx_lowlevel_pka_and(res, CC3XX_PKA_REG_N_MASK, res);

    cc3xx_lowlevel_pka_free_reg(r0_copy);
}

void cc3xx_lowlevel_pka_mod_inv_prime_modulus(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t res)
{
    cc3xx_pka_reg_id_t n_minus_2 = cc3xx_lowlevel_pka_allocate_reg();

    /* Use the special-case Euler theorem  a^-1 = a^N-2 mod N */
    assert(virt_reg_in_use[CC3XX_PKA_REG_N]);
    assert(cc3xx_lowlevel_pka_less_than(r0, CC3XX_PKA_REG_N));

    cc3xx_lowlevel_pka_sub_si(CC3XX_PKA_REG_N, 2, n_minus_2);
    cc3xx_lowlevel_pka_mod_exp(r0, n_minus_2, res);

    cc3xx_lowlevel_pka_free_reg(n_minus_2);
}

void cc3xx_lowlevel_pka_reduce(cc3xx_pka_reg_id_t r0)
{
    assert(virt_reg_in_use[CC3XX_PKA_REG_N]);

    /* This operation uses PKA_OP_SIZE_N, instead of _REGISTER. This is not
     * because it performs reduction, since mod_add uses _REGISTER, but because
     * it does not use the ALU, but the special-purpose modular multiplier.
     */
    P_CC3XX->pka.opcode = opcode_construct(CC3XX_PKA_OPCODE_REDUCTION,
                                           PKA_OP_SIZE_N,
                                           false, r0, false, 0, false, r0);

    /* Because this uses use OP_SIZE_N, it sometime leaves garbage bits in the
     * top words. Do a mask operation to clear these
     */
    cc3xx_lowlevel_pka_and(r0, CC3XX_PKA_REG_N_MASK, r0);
}

