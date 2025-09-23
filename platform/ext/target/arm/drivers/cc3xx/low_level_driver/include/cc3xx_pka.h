/*
 * Copyright (c) 2023, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef CC3XX_PKA_H
#define CC3XX_PKA_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include "cc3xx_error.h"

#define CC3XX_PKA_REG_N  0
#define CC3XX_PKA_REG_NP 1

#ifdef __cplusplus
extern "C" {
#endif

typedef uint32_t cc3xx_pka_reg_id_t;

struct cc3xx_pka_state_t {
    bool initialized;
    uint32_t reg_size;
    uint32_t virt_reg_next_mapped;
};

/**
 * @brief                       Initialize the PKA engine.
 *
 * @param[in]  size             The size of operations the PKA engine will be
 *                              performing, in bytes. This is a maximum,
 *                              operations on values smaller than this size can
 *                              be carried out. Larger size allocations may
 *                              result in less registers being available. Note
 *                              that register values can exceed this size, but
 *                              operations on values larger than this may
 *                              overflow and produce incorrect results.
 *
 */
void cc3xx_lowlevel_pka_init(uint32_t size);

/**
 * @brief                       Returns PKA initialization state
 *
 * @return                      True if PKA state is initialized, false otherwise
 */
bool cc3xx_lowlevel_pka_is_initialized(void);

/**
 * @brief                       Allocates a PKA register.
 *
 * @return                      A PKA register Identifier. Note that this
 *                              function does not return an error code when
 *                              allocation fails (but will fail an assertion),
 *                              so the amount of registers used in a PKA
 *                              session must be constant, otherwise non-debug
 *                              builds will have silent allocation failures
 *                              leading to unpredictable behaviour.
 */
cc3xx_pka_reg_id_t cc3xx_lowlevel_pka_allocate_reg(void);

/**
 * @brief Unmap all mapped physical registers at once
 *
 */
void cc3xx_lowlevel_pka_unmap_physical_registers(void);

/**
 * @brief                        Free a PKA register, returning it to the pool
 *                               so it can be reallocated.
 *
 * @param[in]  reg_id            The register ID to be freed.
 */
void cc3xx_lowlevel_pka_free_reg(cc3xx_pka_reg_id_t reg_id);

/**
 * @brief                        Write data into a PKA register.
 *
 * @param[in]  reg_id            The register ID to write data into.
 * @param[in]  data              The data to be written to the register.
 * @param[in]  len               The size in bytes of the data. Must be a
 *                               multiple of sizeof(uint32_t). Should be less
 *                               than or equal to the operation size.
 */
void cc3xx_lowlevel_pka_write_reg(cc3xx_pka_reg_id_t reg_id, const uint32_t *data, size_t len);
/**
 * @brief                        Write data into a PKA register, performing an
 *                               endianness swap on each word.
 *
 * @param[in]  reg_id            The register ID to write data into.
 * @param[in]  data              The data to be written to the register.
 * @param[in]  len               The size in bytes of the data. Must be a
 *                               multiple of sizeof(uint32_t). Should be less
 *                               than or equal to the operation size.
 */
void cc3xx_lowlevel_pka_write_reg_swap_endian(cc3xx_pka_reg_id_t reg_id, const uint32_t *data,
                                              size_t len);

/**
 * @brief                        Read data from a PKA register.
 *
 * @param[in]  id                The register ID to write data into.
 * @param[out] data              Buffer the data will be written into.
 * @param[in]  len               The size in bytes of the data to be read. Must
 *                               be a multiple of sizeof(uint32_t). The buffer
 *                               must be of at least this size.
 */
void cc3xx_lowlevel_pka_read_reg(cc3xx_pka_reg_id_t id, uint32_t *data, size_t len);
/**
 * @brief                        Read data from a PKA register, performing an
 *                               endianness swap on each word.
 *
 * @param[in]  id                The register ID to write data into.
 * @param[out] data              Buffer the data will be written into.
 * @param[in]  len               The size in bytes of the data to be read. Must
 *                               be a multiple of sizeof(uint32_t). The buffer
 *                               must be of at least this size.
 */
void cc3xx_lowlevel_pka_read_reg_swap_endian(cc3xx_pka_reg_id_t id, uint32_t *data, size_t len);

/**
 * @brief                       Set the modulus of a PKA session. This must be
 *                              called before any pka_mod_* operations are used.
 *                              For PKA sessions which do not use any of the
 *                              pka_mod_* operations, this function does not
 *                              need to be called.
 *
 * @param[in]  modulus          The register that will be used as the modulus.
 * @param[in]  calculate_tag    Whether the barrett tag should be calculated. If
 *                              this is set then the barrett_tag argument will
 *                              be ignored.
 * @param[in]  barrett_tag      The register that will be used as the barrett
 *                              tag.
 */
void cc3xx_lowlevel_pka_set_modulus(cc3xx_pka_reg_id_t modulus, bool calculate_tag,
                                    cc3xx_pka_reg_id_t barrett_tag);

/**
 * @brief                       Get the state of the PKA engine, and save the
 *                              contents of a selected subset of the PKA
 *                              registers.
 *
 * @param[out] state              A pointer to which the state of the PKA engine
 *                                will be written
 * @param[in]  save_reg_am        The amount of registers which will be saved.
 * @param[in]  save_reg_list      A list of registers IDs which will be saved.
 *                                Must be ``save_reg_am`` elements long.
 * @param[in]  save_reg_ptr_list  A list of pointers to which the register
 *                                contents will be written. The order must
 *                                correspond to the order of ``save_reg_list``.
 *                                Must be ``save_reg_am`` elements long.
 * @param[in]  save_reg_size_list A list of sizes of the registers which will be
 *                                saved. Each buffer pointed to by
 *                                ``save_reg_ptr_list`` must be at least the
 *                                size of the corresponding element of this
 *                                list. The order must correspond to the order
 *                                of ``save_reg_list``. Must be ``save_reg_am``
 *                                elements long.
 */
void cc3xx_lowlevel_pka_get_state(struct cc3xx_pka_state_t *state, uint32_t save_reg_am,
                                  cc3xx_pka_reg_id_t *save_reg_list,
                                  uint32_t **save_reg_ptr_list,
                                  const size_t *save_reg_size_list);
/**
 * @brief                       Set the state of the PKA engine, and load the
 *                              contents of a selected subset of the PKA
 *                              registers.
 *
 * @param[out] state              A pointer to which the state of the PKA engine
 *                                will be read from
 * @param[in]  load_reg_am        The amount of registers which will be loaded.
 * @param[in]  load_reg_list      A list of registers IDs which will be loaded.
 *                                Must be ``load_reg_am`` elements long.
 * @param[in]  load_reg_ptr_list  A list of pointers from which the register
 *                                contents will be read. The order must
 *                                correspond to the order of ``load_reg_list``.
 *                                Must be ``load_reg_am`` elements long.
 * @param[in]  load_reg_size_list A list of sizes of the registers which will be
 *                                loaded. Each buffer pointed to by
 *                                ``load_reg_ptr_list`` must be at least the
 *                                size of the corresponding element of this
 *                                list. The order must correspond to the order
 *                                of ``load_reg_list``. Must be ``load_reg_am``
 *                                elements long.
 *
 * @note                        This function also initializes the PKA engine,
 *                              so it can be used once this function has been
 *                              called.
 */
void cc3xx_lowlevel_pka_set_state(const struct cc3xx_pka_state_t *state,
                                  uint32_t load_reg_am, cc3xx_pka_reg_id_t *load_reg_list,
                                  const uint32_t **load_reg_ptr_list,
                                  const size_t *load_reg_size_list);
/**
 * @brief Getter function to return the value of the register size currently
 *        configured on the PKA engine
 *
 * @return uint32_t Register size in bytes currently configured on the PKA engine
 */
uint32_t cc3xx_lowlevel_pka_get_register_size(void);

/**
 * @brief                       Uninitialize the PKA engine.
 */
void cc3xx_lowlevel_pka_uninit(void);

/**
 * @brief                       Get the size in bits of the contents of a
 *                              register.
 *
 * @param[in]  r0               The register ID to count the bits of.
 *
 * @note                        This does not return the register size, but the
 *                              size of the number it contains.
 *
 * @return                      The number of bits.
 */
uint32_t cc3xx_lowlevel_pka_get_bit_size(cc3xx_pka_reg_id_t r0);

/**
 * @brief                       Set a register to a power of 2.
 *
 * @param[in]  r0               The register ID to set.
 * @param[in]  power            The power to set the register to.
 */
void cc3xx_lowlevel_pka_set_to_power_of_two(cc3xx_pka_reg_id_t r0, uint32_t power);

/**
 * @brief                       Set a register to a random value. All words in
 *                              the register will be set to random values.
 *
 * @param[in]  r0               The register ID to set.
 * @param[in]  bit_len          Amount of bits of randomness to input. Must not
 *                              be larger than the size the PKA operation was
 *                              instantiated with.
 *
 * @return                      CC3XX_ERR_SUCCESS on success, another
 *                              cc3xx_err_t on error.
 */
cc3xx_err_t cc3xx_lowlevel_pka_set_to_random(cc3xx_pka_reg_id_t r0, size_t bit_len);

/**
 * @brief                       Set a register to a random value which is less
 *                              than the modulus register. Will retry to avoid
 *                              bias.
 *
 * @param[in]  r0               The register ID to set.
 *
 * @return                      CC3XX_ERR_SUCCESS on success, another
 *                              cc3xx_err_t on error.
 */
cc3xx_err_t cc3xx_lowlevel_pka_set_to_random_within_modulus(cc3xx_pka_reg_id_t r0);

/**
 * @brief                       Add the values in two registers. res = r0 + r1.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  r1               The register ID of the second operand.
 * @param[out] res              The register ID the result will be stored in.
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical.
 */
void cc3xx_lowlevel_pka_add(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t r1, cc3xx_pka_reg_id_t res);
/**
 * @brief                       Add the values in a register with a signed
 *                              immediate. res = r0 + imm.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  imm              The signed immediate, which must be in the range
 *                              -16 to 15 inclusive.
 * @param[out] res              The register ID the result will be stored in.
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical.
 */
void cc3xx_lowlevel_pka_add_si(cc3xx_pka_reg_id_t r0, int32_t imm, cc3xx_pka_reg_id_t res);

/**
 * @brief                       Subtract the value in one register from the
 *                              other. res = r0 - r1.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  r1               The register ID of the second operand.
 * @param[out] res              The register ID the result will be stored in.
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical.
 */
void cc3xx_lowlevel_pka_sub(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t r1, cc3xx_pka_reg_id_t res);
/**
 * @brief                       Subtract a signed immediate from the value in a
 *                              register. res = r0 - imm.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  imm              The signed immediate, which must be in the range
 *                              -16 to 15 inclusive.
 * @param[out] res              The register ID the result will be stored in.
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical.
 */
void cc3xx_lowlevel_pka_sub_si(cc3xx_pka_reg_id_t r0, int32_t imm, cc3xx_pka_reg_id_t res);

/**
 * @brief                       Negate the value in a register. res = 0 - r0.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[out] res              The register ID the result will be stored in.
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical.
 */
void cc3xx_lowlevel_pka_neg(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t res);

/**
 * @brief                       Add the values in two registers, and perform
 *                              modular reduction. res = (r0 + r1) mod N.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  r1               The register ID of the second operand.
 * @param[out] res              The register ID the result will be stored in.
 *
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical.
 *
 * @note                        r0 and r1 must be less than the modulus N.
 */
void cc3xx_lowlevel_pka_mod_add(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t r1,
                                cc3xx_pka_reg_id_t res);
/**
 * @brief                       Add the values in a register with a signed
 *                              immediate, and perform modular reduction.
 *                              res = (r0 + imm) mod N.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  imm              The signed immediate, which must be in the range
 *                              -16 to 15 inclusive.
 * @param[out] res              The register ID the result will be stored in.
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical.
 *
 * @note                        r0 must be less than the modulus N.
 */
void cc3xx_lowlevel_pka_mod_add_si(cc3xx_pka_reg_id_t r0, int32_t imm, cc3xx_pka_reg_id_t res);

/**
 * @brief                       Subtract the value in one register from the
 *                              other, performing modular reduction.
 *                              res = (r0 - r1) mod N.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  r1               The register ID of the second operand.
 * @param[out] res              The register ID the result will be stored in.
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical.
 *
 * @note                        r0 and r1 must be less than the modulus N.
 */
void cc3xx_lowlevel_pka_mod_sub(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t r1,
                                cc3xx_pka_reg_id_t res);
/**
 * @brief                       Subtract a signed immediate from the value in a
 *                              register, performing modular reduction.
 *                              res = (r0 - imm) mod N.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  imm              The signed immediate, which must be in the range
 *                              -16 to 15 inclusive.
 * @param[out] res              The register ID the result will be stored in.
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical.
 *
 * @note                        r0 must be less than the modulus N.
 */
void cc3xx_lowlevel_pka_mod_sub_si(cc3xx_pka_reg_id_t r0, int32_t imm, cc3xx_pka_reg_id_t res);

/**
 * @brief                       Negate the value in a register, and perform
 *                              modular reduction. res = (0 - r0) mod N.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[out] res              The register ID the result will be stored in.
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical.
 *
 * @note                        r0 must be less than the modulus N.
 */
void cc3xx_lowlevel_pka_mod_neg(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t res);

/**
 * @brief                       Set the output register to the bitwise AND of
 *                              two input registers. res = r0 & r1.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  r1               The register ID of the second operand.
 * @param[out] res              The register ID the result will be stored in.
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical.
 */
void cc3xx_lowlevel_pka_and(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t r1, cc3xx_pka_reg_id_t res);
/**
 * @brief                       Set the output register to the bitwise AND of
 *                              a register and an unsigned mask. res = r0 & imm.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  mask             The unsigned mask, which must be in the range
 *                              0 to 32 inclusive.
 * @param[out] res              The register ID the result will be stored in.
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical.
 */
void cc3xx_lowlevel_pka_and_si(cc3xx_pka_reg_id_t r0, uint32_t mask, cc3xx_pka_reg_id_t res);

/**
 * @brief                       Check if a bits are set in a register.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  idx              The index of the bits to check.
 * @param[in]  bit_am           The amount of bits to check.
 *
 * @return                      The bits requested.
 */
uint32_t cc3xx_lowlevel_pka_test_bits_ui(cc3xx_pka_reg_id_t r0, uint32_t idx, uint32_t bit_am);

/**
 * @brief                       Clear a bit in a register.
 *                              res = r0 & (1 << idx).
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  idx              The index of the bit to be cleared.
 * @param[out] res              The register ID the result will be stored in.
 */
void cc3xx_lowlevel_pka_clear_bit(cc3xx_pka_reg_id_t r0, uint32_t idx, cc3xx_pka_reg_id_t res);

/**
 * @brief                       Clear a register. r0 = 0.
 *
 * @param[in]  r0               The register ID of the first operand.
 */
void cc3xx_lowlevel_pka_clear(cc3xx_pka_reg_id_t r0);

/**
 * @brief                       Set the output register to the bitwise OR of
 *                              two input registers. res = r0 | r1.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  r1               The register ID of the second operand.
 * @param[out] res              The register ID the result will be stored in.
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical.
 */
void cc3xx_lowlevel_pka_or(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t r1, cc3xx_pka_reg_id_t res);
/**
 * @brief                       Set the output register to the bitwise OR of
 *                              a register and an unsigned mask. res = r0 | imm.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  mask             The unsigned mask, which must be in the range
 *                              0 to 32 inclusive.
 * @param[out] res              The register ID the result will be stored in.
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical.
 */
void cc3xx_lowlevel_pka_or_si(cc3xx_pka_reg_id_t r0, uint32_t mask, cc3xx_pka_reg_id_t res);

/**
 * @brief                       Copy a register into another one. res = r0.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[out] res              The register ID the result will be stored in.
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical.
 */
void cc3xx_lowlevel_pka_copy(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t res);

/**
 * @brief                       Set a bit in a register.
 *                              res = r0 | (1 << idx).
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  idx              The index of the bit to be set.
 * @param[out] res              The register ID the result will be stored in.
 */
void cc3xx_lowlevel_pka_set_bit(cc3xx_pka_reg_id_t r0, uint32_t idx, cc3xx_pka_reg_id_t res);

/**
 * @brief                       Set the output register to the bitwise XOR of
 *                              two input registers. res = r0 ^ r1.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  r1               The register ID of the second operand.
 * @param[out] res              The register ID the result will be stored in.
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical.
 */
void cc3xx_lowlevel_pka_xor(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t r1, cc3xx_pka_reg_id_t res);
/**
 * @brief                       Set the output register to the bitwise XOR of
 *                              a register and an unsigned mask. res = r0 ^ imm.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  mask             The unsigned mask, which must be in the range
 *                              0 to 32 inclusive.
 * @param[out] res              The register ID the result will be stored in.
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical.
 */
void cc3xx_lowlevel_pka_xor_si(cc3xx_pka_reg_id_t r0, uint32_t mask, cc3xx_pka_reg_id_t res);

/**
 * @brief                       Flip a bit in a register.
 *                              res = r0 ^ (1 << idx).
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  idx              The index of the bit to be flipped.
 * @param[out] res              The register ID the result will be stored in.
 */
void cc3xx_lowlevel_pka_flip_bit(cc3xx_pka_reg_id_t r0, uint32_t idx, cc3xx_pka_reg_id_t res);

/**
 * @brief                       Check if two registers are equal.
 *                              retval = r0 == r1.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  r1               The register ID of the second operand.
 *
 * @return                      true if registers are equal, false otherwise.
 */
bool cc3xx_lowlevel_pka_are_equal(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t r1);
/**
 * @brief                       Check if a register is equal to n signed
 *                              immediate. retval = r0 == imm.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  imm              The signed immediate, which must be in the range
 *                              -16 to 15 inclusive.
 *
 * @return                      true if register and immediate are equal, false
 *                              otherwise.
 */
bool cc3xx_lowlevel_pka_are_equal_si(cc3xx_pka_reg_id_t r0, int32_t imm);

/**
 * @brief                       Check if a register is less than another
 *                              register. retval = r0 < r1.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  r1               The register ID of the second operand.
 *
 * @return                      true if r0 is less than r1, false otherwise.
 */
bool cc3xx_lowlevel_pka_less_than(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t r1);
/**
 * @brief                       Check if a register is less than a signed
 *                              immediate. retval = r0 < imm.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  imm              The signed immediate, which must be in the range
 *                              -16 to 15 inclusive.
 *
 * @return                      true if r0 is less than imm, false otherwise.
 */
bool cc3xx_lowlevel_pka_less_than_si(cc3xx_pka_reg_id_t r0, int32_t imm);

/**
 * @brief                       Check if a register is greater than another
 *                              register. retval = r0 > r1.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  r1               The register ID of the second operand.
 *
 * @return                      true if r0 is greater than r1, false otherwise.
 */
bool cc3xx_lowlevel_pka_greater_than(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t r1);
/**
 * @brief                       Check if a register is greater than a signed
 *                              immediate. retval = r0 > imm.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  imm              The signed immediate, which must be in the range
 *                              -16 to 15 inclusive.
 *
 * @return                      true if r0 is greater than imm, false otherwise.
 */
bool cc3xx_lowlevel_pka_greater_than_si(cc3xx_pka_reg_id_t r0, int32_t imm);

/**
 * @brief                       Shift a register to the right, and fill any new
 *                              bits with zeros. res = r0 >> shift.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  shift            The amount the register should be shifted by.
 *                              This must not be 0.
 * @param[out] res              The register ID the result will be stored in.
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical.
 */
void cc3xx_lowlevel_pka_shift_right_fill_0_ui(cc3xx_pka_reg_id_t r0, uint32_t shift,
                                              cc3xx_pka_reg_id_t res);
/**
 * @brief                       Shift a register to the right, and fill any new
 *                              bits with ones. res = r0 >> shift.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  shift            The amount the register should be shifted by.
 *                              This must not be 0.
 * @param[out] res              The register ID the result will be stored in.
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical.
 */
void cc3xx_lowlevel_pka_shift_right_fill_1_ui(cc3xx_pka_reg_id_t r0, uint32_t shift,
                                              cc3xx_pka_reg_id_t res);

/**
 * @brief                       Shift a register to the left, and fill any new
 *                              bits with zeros. res = r0 << shift.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  shift            The amount the register should be shifted by.
 *                              This must not be 0.
 * @param[out] res              The register ID the result will be stored in.
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical.
 */
void cc3xx_lowlevel_pka_shift_left_fill_0_ui(cc3xx_pka_reg_id_t r0, uint32_t shift,
                                             cc3xx_pka_reg_id_t res);
/**
 * @brief                       Shift a register to the left, and fill any new
 *                              bits with ones. res = r0 << shift.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  shift            The amount the register should be shifted by.
 *                              This must not be 0.
 * @param[out] res              The register ID the result will be stored in.
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical.
 */
void cc3xx_lowlevel_pka_shift_left_fill_1_ui(cc3xx_pka_reg_id_t r0, uint32_t shift,
                                             cc3xx_pka_reg_id_t res);

/**
 * @brief                       Set the output register low half of the result
 *                              of the multiplication of the two input
 *                              registers. res = (r0 * r1) & reg_size_mask.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  r1               The register ID of the second operand.
 * @param[out] res              The register ID the result will be stored in.
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical.
 */
void cc3xx_lowlevel_pka_mul_low_half(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t r1,
                                     cc3xx_pka_reg_id_t res);
/**
 * @brief                       Set the output register high half of the result
 *                              of the multiplication of the two input
 *                              registers. res = (r0 * r1) >> reg_size.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  r1               The register ID of the second operand.
 * @param[out] res              The register ID the result will be stored in.
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical.
 */
void cc3xx_lowlevel_pka_mul_high_half(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t r1,
                                      cc3xx_pka_reg_id_t res);

/**
 * @brief                       Set the quotient and remainder registers by
 *                              dividing one input register by another. Division
 *                              is integer division. quotient = r0 / r1.
 *                              Remainder = r0 mod r1.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  r1               The register ID of the second operand.
 * @param[out] quotient         The register ID the quotient will be stored in.
 * @param[out] remainder        The register ID the remainder will be stored in.
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical. This function may
 *                              perform transparent copying to achieve this.
 */
void cc3xx_lowlevel_pka_div(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t r1,
                            cc3xx_pka_reg_id_t quotient, cc3xx_pka_reg_id_t remainder);

/**
 * @brief                       Perform multiplication of the input registers,
 *                              and then modular reduction.
 *                              res = (r0 * r1) mod N.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  r1               The register ID of the second operand.
 * @param[out] res              The register ID the result will be stored in.
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical.
 */
void cc3xx_lowlevel_pka_mod_mul(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t r1,
                                cc3xx_pka_reg_id_t res);

/**
 * @brief                       Perform multiplication of the input register and
 *                              a signed immediate, and then modular reduction.
 *                              res = (r0 * imm) mod N.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  imm              The signed immediate, which must be in the range
 *                              0 to 15 inclusive.
 * @param[out] res              The register ID the result will be stored in.
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical.
 */
void cc3xx_lowlevel_pka_mod_mul_si(cc3xx_pka_reg_id_t r0, int32_t imm, cc3xx_pka_reg_id_t res);

/**
 * @brief                       Perform exponentiation and then modular
 *                              reduction. res = (r0 ^ r1) mod N.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  r1               The register ID of the second operand.
 * @param[out] res              The register ID the result will be stored in.
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical.
 */
void cc3xx_lowlevel_pka_mod_exp(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t r1,
                                cc3xx_pka_reg_id_t res);
/**
 * @brief                       Perform exponentiation by a signed immediate and
 *                              then modular reduction. res = (r0 ^ imm) mod N.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[in]  imm              The signed immediate, which must be in the range
 *                              0 to 15 inclusive.
 * @param[out] res              The register ID the result will be stored in.
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical.
 */
void cc3xx_lowlevel_pka_mod_exp_si(cc3xx_pka_reg_id_t r0, int32_t imm, cc3xx_pka_reg_id_t res);

/**
 * @brief                       Perform modular inversion.
 *                              res = x where (r0 * x mod N) == 1.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[out] res              The register ID the result will be stored in.
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical.
 */
void cc3xx_lowlevel_pka_mod_inv(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t res);

/**
 * @brief                       Perform modular inversion for prime modulus.
 *                              res = x where (r0 * x mod N) == 1, if N is prime.
 *
 * @param[in]  r0               The register ID of the first operand.
 * @param[out] res              The register ID the result will be stored in.
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical.
 */
void cc3xx_lowlevel_pka_mod_inv_prime_modulus(cc3xx_pka_reg_id_t r0, cc3xx_pka_reg_id_t res);

/**
 * @brief                       Perform modular reduction. res = r0 mod N.
 *
 * @param[in,out]  r0           The register ID of the first operand.
 *
 * @note                        It is acceptable to have some or all of the
 *                              register IDs be identical.
 */
void cc3xx_lowlevel_pka_reduce(cc3xx_pka_reg_id_t r0);

#ifdef __cplusplus
}
#endif

#endif /* CC3XX_PKA_H */
