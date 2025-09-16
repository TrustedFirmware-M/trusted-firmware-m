/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include <assert.h>
#include <string.h>

#include "kmu_drv.h"

#include "test_framework.h"
#include "device_definition.h"

/* general helpers */
#define ARRAY_SIZE(_arr) (sizeof(_arr) / sizeof((_arr)[0]))

#define TEST_ASSERT(cond, msg) \
    if (!(cond)) {             \
        TEST_FAIL(msg);        \
        return;                \
    }
#define TEST_FMT_ASSERT(cond, fmt, ...) \
    if (!(cond)) {                      \
        TEST_LOG(fmt, __VA_ARGS__);     \
        TEST_FAIL("ASSERT_FAILED");     \
        return;                         \
    }
#define TEST_SETUP(x) TEST_ASSERT((x) == 0, "Test setup failed")
#define TEST_TEARDOWN(x) TEST_ASSERT((x) == 0, "Test teardown failed")

/* an arbitrary keys to lock and unlock */
#define UNSUPPORTED_SLOT (get_max_keyslots())
#define INVALID_SLOT KMU_HW_SLOT_HUK
#define SLOT UNSUPPORTED_SLOT - 1

struct _kmu_reg_map_t {
    volatile uint32_t kmubc;
    volatile uint32_t kmuis;
};

static uint8_t key[32] = {
    128,  57, 201,  33,   9, 245, 172,   6,
    110, 198,  75, 222, 143,  28, 160, 101,
    128,  64,  25, 192,  33,  17,  96, 220,
      7, 150, 210,  10,  55, 137,  88, 201
};
static const struct kmu_key_export_config_t config = {
    .export_address                     = CC3XX_BASE_S + 0x400,                /* CC3XX AES_KEY_0 register */
    .destination_port_write_delay       = 0,                                   /* No delay */
    .destination_port_address_increment = 1,                                   /* Increment by 4 bytes with each write */
    .destination_port_data_width_code   = KMU_DESTINATION_PORT_WIDTH_32_BITS,  /* Write 32 bits with each write */
    .destination_port_data_writes_code  = KMU_DESTINATION_PORT_WIDTH_8_WRITES, /* Perform 8 writes (total 256 bits) */
    .new_mask_for_next_key_writes       = true,                                /* refresh the masking */
    .write_mask_disable                 = false,                               /* Don't disable the masking */
};

/*================================== helpers =================================*/
static uint32_t get_max_keyslots(void)
{
    return KMU_GET_NKS(((struct _kmu_reg_map_t *)KMU_DEV_S.cfg->base));
}

/*========================== test_drivers_kmu_init ===========================*/
static void test_drivers_kmu_init(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    uint8_t prbg_seed[4] = { 1, 2, 3, 4 };

    err = kmu_init(&KMU_DEV_S, prbg_seed);
    TEST_ASSERT(err == KMU_ERROR_NONE, "kmu_init: failed normal operation");

    ret->val = TEST_PASSED;
}

static void test_drivers_kmu_init_alignment_check(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    uint8_t prbg_seed = 5;

    err = kmu_init(&KMU_DEV_S, &prbg_seed);
    TEST_ASSERT(err == KMU_ERROR_INIT_INVALID_ALIGNMENT, "kmu_init: failed alignment check");

    ret->val = TEST_PASSED;
}

static void test_drivers_kmu_init_null_check(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    err = kmu_init(&KMU_DEV_S, NULL);
    TEST_ASSERT(err == KMU_ERROR_NULL_POINTER, "kmu_init: failed NULL check");

    ret->val = TEST_PASSED;
}

/*================== kmu_(get/set)_export_config ===================*/
static void test_drivers_kmu_getset_key_export_config(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    struct kmu_key_export_config_t read;

    TEST_SETUP(kmu_set_slot_invalid(&KMU_DEV_S, SLOT));

    /* write config */
    err = kmu_set_key_export_config(&KMU_DEV_S, SLOT, &config);
    TEST_ASSERT(err == KMU_ERROR_NONE, "kmu_set_key_export_config: failed");

    /* read config */
    err = kmu_get_key_export_config(&KMU_DEV_S, SLOT, &read);
    TEST_ASSERT(err == KMU_ERROR_NONE, "kmu_get_key_export_config: failed");

    /* compare read and write */
    TEST_ASSERT(
        read.export_address                     == config.export_address                     &&
        read.destination_port_data_width_code   == config.destination_port_data_width_code   &&
        read.destination_port_data_writes_code  == config.destination_port_data_writes_code  &&
        read.destination_port_write_delay       == config.destination_port_write_delay       &&
        read.destination_port_address_increment == config.destination_port_address_increment &&
        read.new_mask_for_next_key_writes       == config.new_mask_for_next_key_writes       &&
        read.write_mask_disable                 == config.write_mask_disable,
        "kmu_(get/set)_key_export_config: failed, read and write mismatched");

    ret->val = TEST_PASSED;
}

static void test_drivers_kmu_get_key_export_config_null_check(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    err = kmu_get_key_export_config(&KMU_DEV_S, SLOT, NULL);
    TEST_ASSERT(err == KMU_ERROR_NULL_POINTER, "kmu_get_key_export_config: failed NULL check");

    ret->val = TEST_PASSED;
}

static void test_drivers_kmu_get_key_export_config_unsupported_slot(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;
    struct kmu_key_export_config_t dummy_config;

    err = kmu_get_key_export_config(&KMU_DEV_S, UNSUPPORTED_SLOT, &dummy_config);
    TEST_FMT_ASSERT(err == KMU_ERROR_INVALID_SLOT,
                    "kmu_get_key_export_config: failed unsupported slot(%d) check\r\n",
                    UNSUPPORTED_SLOT);

    ret->val = TEST_PASSED;
}

static void test_drivers_kmu_get_key_export_config_locked_slot(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_SLOT_LOCKED;

    TEST_SETUP(kmu_set_slot_invalid(&KMU_DEV_S, SLOT));
    TEST_SETUP(kmu_set_key_locked(&KMU_DEV_S, SLOT));

    /* try to access locked key */
    err = kmu_get_key_export_config(&KMU_DEV_S, SLOT, NULL);
    TEST_ASSERT(err != KMU_ERROR_SLOT_LOCKED,
                "kmu_get_key_export_config: failed locked slot check");

    ret->val = TEST_PASSED;
}

static void test_drivers_kmu_set_key_export_config_null_check(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    err = kmu_set_key_export_config(&KMU_DEV_S, SLOT, NULL);
    TEST_ASSERT(err == KMU_ERROR_NULL_POINTER, "kmu_set_key_export_config: failed NULL check");

    ret->val = TEST_PASSED;
}

static void test_drivers_kmu_set_key_export_config_unsupported_slot(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;
    struct kmu_key_export_config_t dummy_config;

    err = kmu_set_key_export_config(&KMU_DEV_S, UNSUPPORTED_SLOT, &dummy_config);
    TEST_FMT_ASSERT(err == KMU_ERROR_INVALID_SLOT,
                    "kmu_set_key_export_config: failed unsupported slot(%d) check\r\n",
                    UNSUPPORTED_SLOT);

    ret->val = TEST_PASSED;
}

static void test_drivers_kmu_set_key_export_config_locked_slot(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;
    struct kmu_key_export_config_t dummy_config;

    TEST_SETUP(kmu_set_slot_invalid(&KMU_DEV_S, SLOT));
    TEST_SETUP(kmu_set_key_export_config_locked(&KMU_DEV_S, SLOT));

    /* try to access locked key */
    err = kmu_set_key_export_config(&KMU_DEV_S, SLOT, &dummy_config);
    TEST_ASSERT(err == KMU_ERROR_SLOT_LOCKED,
                "kmu_set_key_export_config: failed locked slot check");

    ret->val = TEST_PASSED;
}

/*======================== kmu_(get/set)_key_locked =====================*/
static void test_drivers_kmu_getset_key_locked(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    TEST_SETUP(kmu_set_slot_invalid(&KMU_DEV_S, SLOT));

    /* set the status of the key */
    err = kmu_set_key_locked(&KMU_DEV_S, SLOT);
    TEST_ASSERT(err == KMU_ERROR_NONE, "kmu_set_key_locked: failed to lock key");

    /* get the status of the key */
    err = kmu_get_key_locked(&KMU_DEV_S, SLOT);
    TEST_ASSERT(err == KMU_ERROR_SLOT_LOCKED, "kmu_set_key_locked: failed to get locked key");

    ret->val = TEST_PASSED;
}

static void test_drivers_kmu_set_key_locked_unsupported_slot(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    err = kmu_set_key_locked(&KMU_DEV_S, UNSUPPORTED_SLOT);
    TEST_FMT_ASSERT(err == KMU_ERROR_INVALID_SLOT,
                    "kmu_set_key_locked: failed unsupported slot(%d) check\r\n", UNSUPPORTED_SLOT);

    ret->val = TEST_PASSED;
}

static void test_drivers_kmu_get_key_locked_unsupported_slot(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    err = kmu_get_key_locked(&KMU_DEV_S, UNSUPPORTED_SLOT);
    TEST_FMT_ASSERT(err == KMU_ERROR_INVALID_SLOT,
                    "kmu_get_key_locked: failed unsupported slot(%d) check\r\n", UNSUPPORTED_SLOT);

    ret->val = TEST_PASSED;
}

static void test_drivers_kmu_get_key_locked_unlocked_check(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    TEST_SETUP(kmu_set_slot_invalid(&KMU_DEV_S, SLOT));

    err = kmu_get_key_locked(&KMU_DEV_S, SLOT);
    TEST_ASSERT(err == KMU_ERROR_NONE, "kmu_set_key_locked: failed unlocked key check");

    ret->val = TEST_PASSED;
}

/*===================== kmu_(get/set)_key_export_config_locked =====================*/
static void test_drivers_kmu_getset_key_export_config_locked(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    TEST_SETUP(kmu_set_slot_invalid(&KMU_DEV_S, SLOT));

    /* lock the key config */
    err = kmu_set_key_export_config_locked(&KMU_DEV_S, SLOT);
    TEST_ASSERT(err == KMU_ERROR_NONE,
                "kmu_set_key_export_config_locked: failed to lock slot config");

    /* check that the key config is locked */
    err = kmu_get_key_export_config_locked(&KMU_DEV_S, SLOT);
    TEST_ASSERT(err == KMU_ERROR_SLOT_LOCKED,
                "kmu_get_key_export_config_locked: failed locked slot config check");

    ret->val = TEST_PASSED;
}

static void
test_drivers_kmu_set_key_export_config_locked_unsupported_slot(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    err = kmu_set_key_export_config_locked(&KMU_DEV_S, UNSUPPORTED_SLOT);
    TEST_FMT_ASSERT(err == KMU_ERROR_INVALID_SLOT,
                    "kmu_set_key_export_config_locked: failed unsupported slot(%d) check\r\n",
                    UNSUPPORTED_SLOT);

    ret->val = TEST_PASSED;
}

static void
test_drivers_kmu_get_key_export_config_locked_unsupported_slot(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    err = kmu_get_key_export_config_locked(&KMU_DEV_S, UNSUPPORTED_SLOT);
    TEST_FMT_ASSERT(err == KMU_ERROR_INVALID_SLOT,
                    "kmu_get_key_export_config_locked: failed unsupported slot(%d) check\r\n",
                    UNSUPPORTED_SLOT);

    ret->val = TEST_PASSED;
}

static void test_drivers_kmu_get_key_export_config_locked_unlocked_check(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    TEST_SETUP(kmu_set_slot_invalid(&KMU_DEV_S, SLOT));

    err = kmu_get_key_export_config_locked(&KMU_DEV_S, SLOT);
    TEST_ASSERT(err == KMU_ERROR_NONE,
                "kmu_set_key_export_config_locked: failed unlocked slot check");

    ret->val = TEST_PASSED;
}

/*=========================== kmu_(get/set)_slot_invalid ===========================*/
static void test_drivers_kmu_getset_slot_invalid(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    /* invalidate slot */
    err = kmu_set_slot_invalid(&KMU_DEV_S, INVALID_SLOT);
    TEST_ASSERT(err == KMU_ERROR_NONE, "kmu_set_slot_invalid: failed in invalidating slot");

    /* check that slot is invalid */
    err = kmu_get_slot_invalid(&KMU_DEV_S, INVALID_SLOT);
    TEST_ASSERT(err == KMU_ERROR_SLOT_INVALIDATED,
                "kmu_get_slot_invalid: failed to get invalid slot");

    ret->val = TEST_PASSED;
}

static void test_drivers_kmu_set_slot_invalid_unsupported_slot(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    err = kmu_set_slot_invalid(&KMU_DEV_S, UNSUPPORTED_SLOT);
    TEST_FMT_ASSERT(err == KMU_ERROR_INVALID_SLOT,
                    "kmu_set_slot_invalid: failed unsupported slot(%d) check\r\n",
                    UNSUPPORTED_SLOT);

    ret->val = TEST_PASSED;
}

static void test_drivers_kmu_get_slot_invalid_unsupported_slot(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    err = kmu_get_slot_invalid(&KMU_DEV_S, UNSUPPORTED_SLOT);
    TEST_FMT_ASSERT(err == KMU_ERROR_INVALID_SLOT,
                    "kmu_get_slot_invalid: failed unsupported slot(%d) check\r\n",
                    UNSUPPORTED_SLOT);

    ret->val = TEST_PASSED;
}

static void test_drivers_kmu_get_slot_invalid_unlocked_check(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    TEST_SETUP(kmu_set_slot_invalid(&KMU_DEV_S, SLOT));

    err = kmu_get_slot_invalid(&KMU_DEV_S, SLOT);
    TEST_ASSERT(err == KMU_ERROR_NONE, "kmu_set_slot_invalid: failed unlocked key check");

    ret->val = TEST_PASSED;
}

/*========================= kmu_(get/set)_key ===========================*/
static void test_drivers_kmu_getset_key(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    uint8_t read[sizeof(key)];

    TEST_SETUP(kmu_set_slot_invalid(&KMU_DEV_S, SLOT));

    err = kmu_set_key(&KMU_DEV_S, SLOT, key, sizeof(key));
    TEST_ASSERT(err == KMU_ERROR_NONE, "kmu_set_key: failed to set key");

    err = kmu_get_key(&KMU_DEV_S, SLOT, read, sizeof(read));
    TEST_ASSERT(err == KMU_ERROR_NONE, "kmu_get_key: failed to get key");

    for (uint32_t i = 0; i < sizeof(read); i++) {
        TEST_ASSERT(read[i] == key[i], "kmu_(get/set)_key: read and write mismatch");
    }

    ret->val = TEST_PASSED;
}

static void test_drivers_kmu_set_key_already_written(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    TEST_SETUP(kmu_set_slot_invalid(&KMU_DEV_S, SLOT));

    /* ensure that the slot has a key set, also account for
     * possiblity that the key has been set by a previous test */
    err = kmu_set_key(&KMU_DEV_S, SLOT, key, sizeof(key));
    TEST_ASSERT(err == KMU_ERROR_NONE || err == KMU_ERROR_SET_KEY_SLOT_ALREADY_WRITTEN,
                "kmu_set_key: failed to set key");

    /* check that you cannot set a key in the same slot */
    err = kmu_set_key(&KMU_DEV_S, SLOT, key, sizeof(key));
    TEST_ASSERT(err == KMU_ERROR_SET_KEY_SLOT_ALREADY_WRITTEN, "kmu_set_key: failed to set key");

    ret->val = TEST_PASSED;
}

static void test_drivers_kmu_set_key_null_check(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    TEST_SETUP(kmu_set_slot_invalid(&KMU_DEV_S, SLOT));

    err = kmu_set_key(&KMU_DEV_S, SLOT, NULL, sizeof(key));
    TEST_ASSERT(err == KMU_ERROR_NULL_POINTER, "kmu_set_key: failed NULL check");

    ret->val = TEST_PASSED;
}

static void test_drivers_kmu_set_key_alignment_check(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    uint8_t key = 0;

    TEST_SETUP(kmu_set_slot_invalid(&KMU_DEV_S, SLOT));

    err = kmu_set_key(&KMU_DEV_S, SLOT, &key, sizeof(key));
    TEST_ASSERT(err == KMU_ERROR_SET_KEY_INVALID_ALIGNMENT,
                "kmu_set_key: failed set key alignment check");

    ret->val = TEST_PASSED;
}

static void test_drivers_kmu_set_key_length_check(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    TEST_SETUP(kmu_set_slot_invalid(&KMU_DEV_S, SLOT));

    err = kmu_set_key(&KMU_DEV_S, SLOT, key, 33);
    TEST_ASSERT(err == KMU_ERROR_SET_KEY_INVALID_LENGTH,
                "kmu_set_key: failed set key length check");

    ret->val = TEST_PASSED;
}

static void test_drivers_kmu_set_key_unsupported_slot(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    TEST_SETUP(kmu_set_slot_invalid(&KMU_DEV_S, SLOT));

    err = kmu_set_key(&KMU_DEV_S, UNSUPPORTED_SLOT, key, sizeof(key));
    TEST_FMT_ASSERT(err == KMU_ERROR_INVALID_SLOT,
                    "kmu_set_key: failed unsupported slot(%d) check\r\n", UNSUPPORTED_SLOT);

    ret->val = TEST_PASSED;
}

static void test_drivers_kmu_set_key_locked_check(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    TEST_SETUP(kmu_set_slot_invalid(&KMU_DEV_S, SLOT));
    TEST_SETUP(kmu_set_key_locked(&KMU_DEV_S, SLOT));

    /* check that slot is locked */
    err = kmu_set_key(&KMU_DEV_S, SLOT, key, sizeof(key));
    TEST_ASSERT(err == KMU_ERROR_SLOT_LOCKED, "kmu_set_key: failed locked slot check");

    ret->val = TEST_PASSED;
}

static void test_drivers_kmu_get_key_null_check(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    TEST_SETUP(kmu_set_slot_invalid(&KMU_DEV_S, SLOT));

    err = kmu_get_key(&KMU_DEV_S, SLOT, NULL, sizeof(key));
    TEST_ASSERT(err == KMU_ERROR_NULL_POINTER, "kmu_get_key: failed NULL check");

    ret->val = TEST_PASSED;
}

static void test_drivers_kmu_get_key_alignment_check(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    uint8_t invalid;

    TEST_SETUP(kmu_set_slot_invalid(&KMU_DEV_S, SLOT));

    err = kmu_get_key(&KMU_DEV_S, SLOT, &invalid, sizeof(invalid));
    TEST_ASSERT(err == KMU_ERROR_GET_KEY_INVALID_ALIGNMENT,
                "kmu_get_key: failed get key alignment check");

    ret->val = TEST_PASSED;
}

static void test_drivers_kmu_get_key_length_check(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    TEST_SETUP(kmu_set_slot_invalid(&KMU_DEV_S, SLOT));

    err = kmu_get_key(&KMU_DEV_S, SLOT, key, 33);
    TEST_ASSERT(err == KMU_ERROR_GET_KEY_INVALID_LENGTH,
                "kmu_get_key: failed get key length check");

    ret->val = TEST_PASSED;
}

static void test_drivers_kmu_get_key_unsupported_slot(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    err = kmu_get_key(&KMU_DEV_S, UNSUPPORTED_SLOT, key, sizeof(key));
    TEST_FMT_ASSERT(err == KMU_ERROR_INVALID_SLOT,
                    "kmu_get_key: failed unsupported slot(%d) check\r\n", UNSUPPORTED_SLOT);

    ret->val = TEST_PASSED;
}

static void test_drivers_kmu_get_key_locked_check(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    TEST_SETUP(kmu_set_slot_invalid(&KMU_DEV_S, SLOT));
    TEST_SETUP(kmu_set_key_locked(&KMU_DEV_S, SLOT));

    /* check that slot is locked */
    err = kmu_get_key(&KMU_DEV_S, SLOT, key, sizeof(key));
    TEST_ASSERT(err == KMU_ERROR_SLOT_LOCKED, "kmu_get_key: failed locked slot check");

    ret->val = TEST_PASSED;
}

/*==========test_drivers_kmu_export_key=======================================*/
static void test_drivers_kmu_export_key(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    /* invalidate the previous contents of the SLOT */
    err = kmu_set_slot_invalid(&KMU_DEV_S, SLOT);
    TEST_ASSERT(err == KMU_ERROR_NONE, "kmu_set_slot_invalid: failed to invalidate slot");

    err = kmu_set_key(&KMU_DEV_S, SLOT, key, sizeof(key));
    TEST_ASSERT(err == KMU_ERROR_NONE, "kmu_set_key: failed to set key");

    /* lock the slot */
    err = kmu_set_key_locked(&KMU_DEV_S, SLOT);
    TEST_ASSERT(err == KMU_ERROR_NONE, "kmu_set_key_locked: failed to set locked slot");

    err = kmu_set_key_export_config(&KMU_DEV_S, SLOT, &config);
    TEST_ASSERT(err == KMU_ERROR_NONE, "kmu_set_key_export_config: Failed to set export config");

    /* lock the export config  */
    err = kmu_set_key_export_config_locked(&KMU_DEV_S, SLOT);
    TEST_ASSERT(err == KMU_ERROR_NONE, "kmu_set_key_export_config_locked: failed to lock key");

    /* export the key */
    err = kmu_export_key(&KMU_DEV_S, SLOT);
    TEST_ASSERT(err == KMU_ERROR_NONE, "kmu_export_key: failed to export slot");

    ret->val = TEST_PASSED;
}
static void test_drivers_kmu_export_key_invalid_length(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    TEST_SETUP(kmu_set_slot_invalid(&KMU_DEV_S, SLOT));
    TEST_SETUP(kmu_set_key(&KMU_DEV_S, SLOT, key, sizeof(key)));
    TEST_SETUP(kmu_set_key_locked(&KMU_DEV_S, SLOT));

    /* set the export config */
    struct kmu_key_export_config_t invalid = config;

    /* The following field causes this error to be reached, not all of the
     * 32 bytes needed to successfully export the key will be written causing
     * the key export to fail giving the error: KMU_ERROR_EXPORT_KEY_INVALID_LENGTH
     */
    invalid.destination_port_data_writes_code = KMU_DESTINATION_PORT_WIDTH_16_WRITES,

    err = kmu_set_key_export_config(&KMU_DEV_S, SLOT, &invalid);
    TEST_ASSERT(err == KMU_ERROR_NONE, "kmu_set_key_export_config: Failed to set export config");

    /* lock the export config  */
    err = kmu_set_key_export_config_locked(&KMU_DEV_S, SLOT);
    TEST_ASSERT(err == KMU_ERROR_NONE, "kmu_set_key_export_config_locked: failed to lock key");

    /* check for invalid length */
    err = kmu_export_key(&KMU_DEV_S, SLOT);
    TEST_ASSERT(err == KMU_ERROR_EXPORT_KEY_INVALID_LENGTH,
                "kmu_export_key: failed to export slot");

    ret->val = TEST_PASSED;
}
static void test_drivers_kmu_export_key_invalid_address(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    TEST_SETUP(kmu_set_slot_invalid(&KMU_DEV_S, SLOT));
    TEST_SETUP(kmu_set_key(&KMU_DEV_S, SLOT, key, sizeof(key)));
    TEST_SETUP(kmu_set_key_locked(&KMU_DEV_S, SLOT));

    /* set the export config */
    struct kmu_key_export_config_t invalid = config;

    /* The following field causes this error to be reached, if the
     * address specified in the export address is illegal the hardware
     * will cause an exception, giving the error: KMU_ERROR_EXPORT_KEY_INVALID_ADDR
     */
    invalid.export_address = 0;

    err = kmu_set_key_export_config(&KMU_DEV_S, SLOT, &invalid);
    TEST_ASSERT(err == KMU_ERROR_NONE, "kmu_set_key_export_config: Failed to set export config");

    /* lock the export config  */
    err = kmu_set_key_export_config_locked(&KMU_DEV_S, SLOT);
    TEST_ASSERT(err == KMU_ERROR_NONE, "kmu_set_key_export_config_locked: failed to lock key");

    /* check for invalid length */
    err = kmu_export_key(&KMU_DEV_S, SLOT);
    TEST_ASSERT(err == KMU_ERROR_EXPORT_KEY_INVALID_ADDR, "kmu_export_key: failed to export slot");

    ret->val = TEST_PASSED;
}
static void test_drivers_kmu_export_key_unlocked_check(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    TEST_SETUP(kmu_set_slot_invalid(&KMU_DEV_S, SLOT));

    err = kmu_export_key(&KMU_DEV_S, SLOT);
    TEST_ASSERT(err == KMU_ERROR_EXPORT_KEY_SLOT_NOT_LOCKED,
                "kmu_export_key: failed to export slot");

    ret->val = TEST_PASSED;
}
static void test_drivers_kmu_export_key_unsupported_check(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    err = kmu_export_key(&KMU_DEV_S, UNSUPPORTED_SLOT);
    TEST_FMT_ASSERT(err != KMU_ERROR_NONE, "kmu_export_key: failed to export slot(%d)\r\n",
                    UNSUPPORTED_SLOT);

    ret->val = TEST_PASSED;
}

/*==========test_drivers_kmu_random_delay=====================================*/
static void test_drivers_kmu_random_delay_8(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    err = kmu_random_delay(&KMU_DEV_S, KMU_DELAY_LIMIT_8_CYCLES);
    TEST_ASSERT(err == KMU_ERROR_NONE, "kmu_random_delay: Failed random delay (8 cycle)");

    ret->val = TEST_PASSED;
}
static void test_drivers_kmu_random_delay_16(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    err = kmu_random_delay(&KMU_DEV_S, KMU_DELAY_LIMIT_16_CYCLES);
    TEST_ASSERT(err == KMU_ERROR_NONE, "kmu_random_delay: Failed random delay (16 cycle)");

    ret->val = TEST_PASSED;
}
static void test_drivers_kmu_random_delay_32(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    err = kmu_random_delay(&KMU_DEV_S, KMU_DELAY_LIMIT_32_CYCLES);
    TEST_ASSERT(err == KMU_ERROR_NONE, "kmu_random_delay: Failed random delay (32 cycle)");

    ret->val = TEST_PASSED;
}
static void test_drivers_kmu_random_delay_invalid(struct test_result_t *ret)
{
    enum kmu_error_t err = KMU_ERROR_FORCE_UINT_SIZE;

    err = kmu_random_delay(&KMU_DEV_S, 64);
    TEST_ASSERT(err == KMU_ERROR_INVALID_DELAY_LENGTH,
                "kmu_random_delay: Failed invalid random delay");

    ret->val = TEST_PASSED;
}

/*============================================================================*/
static struct test_t tests[] = {
    { &test_drivers_kmu_init,
        "KMU_DRV_TEST_0",  "test_drivers_kmu_init", },
    { &test_drivers_kmu_init_alignment_check,
        "KMU_DRV_TEST_1",  "test_drivers_kmu_init_alignment_check", },
    { &test_drivers_kmu_init_null_check,
        "KMU_DRV_TEST_2",  "test_drivers_kmu_init_null_check", },
    { &test_drivers_kmu_getset_key_export_config,
        "KMU_DRV_TEST_3",  "test_drivers_kmu_(get/set)_key_export_config", },
    { &test_drivers_kmu_get_key_export_config_null_check,
        "KMU_DRV_TEST_4",  "test_drivers_kmu_get_key_export_config_null_check", },
    { &test_drivers_kmu_get_key_export_config_unsupported_slot,
        "KMU_DRV_TEST_5",  "test_drivers_kmu_get_key_export_config_unsupported_slot", },
    { &test_drivers_kmu_get_key_export_config_locked_slot,
        "KMU_DRV_TEST_6",  "test_drivers_kmu_get_key_export_config_locked_slot", },
    { &test_drivers_kmu_set_key_export_config_null_check,
        "KMU_DRV_TEST_7",  "test_drivers_kmu_set_key_export_config_null_check", },
    { &test_drivers_kmu_set_key_export_config_unsupported_slot,
        "KMU_DRV_TEST_8",  "test_drivers_kmu_set_key_export_config_unsupported_slot", },
    { &test_drivers_kmu_set_key_export_config_locked_slot,
        "KMU_DRV_TEST_9",  "test_drivers_kmu_set_key_export_config_locked_slot", },
    { &test_drivers_kmu_getset_key_locked,
        "KMU_DRV_TEST_10", "test_drivers_kmu_(get/set)_key_locked", },
    { &test_drivers_kmu_set_key_locked_unsupported_slot,
        "KMU_DRV_TEST_11", "test_drivers_kmu_set_key_locked_unsupported_slot", },
    { &test_drivers_kmu_get_key_locked_unsupported_slot,
        "KMU_DRV_TEST_12", "test_drivers_kmu_get_key_locked_unsupported_slot", },
    { &test_drivers_kmu_get_key_locked_unlocked_check,
        "KMU_DRV_TEST_13", "test_drivers_kmu_get_key_locked_unlocked_check", },
    { &test_drivers_kmu_getset_key_export_config_locked,
        "KMU_DRV_TEST_14", "test_drivers_kmu_(get/set)_key_export_config_locked", },
    { &test_drivers_kmu_get_key_export_config_locked_unsupported_slot,
        "KMU_DRV_TEST_15", "test_drivers_kmu_set_key_export_config_locked_unsupported_slot", },
    { &test_drivers_kmu_set_key_export_config_locked_unsupported_slot,
        "KMU_DRV_TEST_15", "test_drivers_kmu_get_key_export_config_locked_unlocked_check", },
    { &test_drivers_kmu_get_key_export_config_locked_unlocked_check,
        "KMU_DRV_TEST_15", "test_drivers_kmu_getset_slot_invalid", },
    { &test_drivers_kmu_getset_slot_invalid,
        "KMU_DRV_TEST_16", "test_drivers_kmu_(get/set)_slot_invalid", },
    { &test_drivers_kmu_set_slot_invalid_unsupported_slot,
        "KMU_DRV_TEST_17", "test_drivers_kmu_set_slot_invalid_unsupported_slot", },
    { &test_drivers_kmu_get_slot_invalid_unsupported_slot,
        "KMU_DRV_TEST_18", "test_drivers_kmu_get_slot_invalid_unsupported_slot", },
    { &test_drivers_kmu_get_slot_invalid_unlocked_check,
        "KMU_DRV_TEST_19", "test_drivers_kmu_get_slot_invalid_unlocked_check", },
    { &test_drivers_kmu_export_key,
        "KMU_DRV_TEST_20", "test_drivers_kmu_export_key", },
    { &test_drivers_kmu_export_key_invalid_length,
        "KMU_DRV_TEST_21", "test_drivers_kmu_export_key_invalid_length", },
    { &test_drivers_kmu_export_key_invalid_address,
        "KMU_DRV_TEST_22", "test_drivers_kmu_export_key_invalid_address", },
    { &test_drivers_kmu_export_key_unlocked_check,
        "KMU_DRV_TEST_23", "test_drivers_kmu_export_key_unlocked_check", },
    { &test_drivers_kmu_export_key_unsupported_check,
        "KMU_DRV_TEST_24", "test_drivers_kmu_export_key_unsupported_check", },
    { &test_drivers_kmu_getset_key,
        "KMU_DRV_TEST_25", "test_drivers_kmu_(get/set)_key", },
    { &test_drivers_kmu_set_key_null_check,
        "KMU_DRV_TEST_26", "test_drivers_kmu_set_key_null_check", },
    { &test_drivers_kmu_set_key_already_written,
        "KMU_DRV_TEST_27", "test_drivers_kmu_set_key_already_written", },
    { &test_drivers_kmu_set_key_alignment_check,
        "KMU_DRV_TEST_28", "test_drivers_kmu_set_key_alignment_check", },
    { &test_drivers_kmu_set_key_length_check,
        "KMU_DRV_TEST_29", "test_drivers_kmu_set_key_length_check", },
    { &test_drivers_kmu_set_key_unsupported_slot,
        "KMU_DRV_TEST_30", "test_drivers_kmu_set_key_unsupported_slot", },
    { &test_drivers_kmu_set_key_locked_check,
        "KMU_DRV_TEST_31", "test_drivers_kmu_set_key_locked_check", },
    { &test_drivers_kmu_get_key_null_check,
        "KMU_DRV_TEST_32", "test_drivers_kmu_get_key_null_check", },
    { &test_drivers_kmu_get_key_alignment_check,
        "KMU_DRV_TEST_33", "test_drivers_kmu_get_key_alignment_check", },
    { &test_drivers_kmu_get_key_length_check,
        "KMU_DRV_TEST_34", "test_drivers_kmu_get_key_length_check", },
    { &test_drivers_kmu_get_key_unsupported_slot,
        "KMU_DRV_TEST_35", "test_drivers_kmu_get_key_unsupported_slot", },
    { &test_drivers_kmu_get_key_locked_check,
        "KMU_DRV_TEST_36", "test_drivers_kmu_get_key_locked_check", },
    { &test_drivers_kmu_random_delay_8,
        "KMU_DRV_TEST_37", "test_drivers_kmu_random_delay_8", },
    { &test_drivers_kmu_random_delay_16,
        "KMU_DRV_TEST_38", "test_drivers_kmu_random_delay_16", },
    { &test_drivers_kmu_random_delay_32,
        "KMU_DRV_TEST_39", "test_drivers_kmu_random_delay_32", },
    { &test_drivers_kmu_random_delay_invalid,
        "KMU_DRV_TEST_40", "test_drivers_kmu_random_delay_invalid", },
};
static uint32_t tests_size = ARRAY_SIZE(tests);

void add_drivers_kmu_tests(struct test_suite_t *suite, uint32_t size)
{
    assert(suite->list_size + tests_size < size);
    memcpy(&(suite->test_list[suite->list_size]), tests, tests_size * sizeof(struct test_t));
    suite->list_size += tests_size;
}
