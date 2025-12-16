/*
 *  SPDX-License-Identifier: BSD-3-Clause
 *  SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include <stdint.h>
#include "string.h"

#include "spi/spi.h"
#include "transport/spi.h"
#include "tfm_log.h"

#include "hardware/spi.h"
#include "hardware/gpio.h"

#include "tpm2.h"
#include "platform/tpm_platform.h"

struct spi_priv {
    void *ctx;
    struct spi_gpio_data gpio_data;
};

static struct spi_priv spidev_priv_data;
static struct spi_plat spidev;

static struct tpm_spi_plat tpm_spi_dev;

/* Dummpy counter in place of a real timer countdown timer */
static int dummpy_timer = 0;

static inline void cs_select()
{
    asm volatile("nop \n nop \n nop");
    gpio_put(spidev.priv->gpio_data.cs_gpio, 0);
    asm volatile("nop \n nop \n nop");
}

static inline void cs_deselect()
{
    asm volatile("nop \n nop \n nop");
    gpio_put(spidev.priv->gpio_data.cs_gpio, 1);
    asm volatile("nop \n nop \n nop");
}

static void spi_start(struct spi_priv *context)
{
    (void)context;
    cs_select();
}

static void spi_stop(struct spi_priv *context)
{
    (void)context;
    cs_deselect();
}

static void spi_release_access(struct spi_priv *context)
{
    (void)context;
    spi_deinit(spi_default);
}

static int spi_get_access(struct spi_priv *context)
{
    (void)context;
    uint ret_val;
    /* Initialize to 1Mhz */
    ret_val = spi_init(spi_default, 10 * 1000 * 1000);
    if (ret_val == 0) {
        ERROR("SPI init failed");
    }

    return 0;
}

static int spi_xfer(struct spi_priv *context, unsigned int bytes, const void *out, void *in)
{
    int ret;

    (void)context;

    if ((out == NULL) && (in == NULL)) {
        return -1;
    }

    ret = spi_write_read_blocking(spi_default, out, in, bytes);
    if (ret == 0) {
        return -1;
    }

    return 0;
}

struct tpm_spi_ops spidev_ops = {
    .get_access     = spi_get_access,
    .release_access = spi_release_access,
    .start          = spi_start,
    .stop           = spi_stop,
    .xfer           = spi_xfer,
};

struct spi_plat *spi_platform_init(struct spi_gpio_data *spi_data)
{
    gpio_set_function(spi_data->mosi_gpio, GPIO_FUNC_SPI);
    gpio_set_function(spi_data->miso_gpio, GPIO_FUNC_SPI);
    gpio_set_function(spi_data->sclk_gpio, GPIO_FUNC_SPI);

    /* Chip select is active-low, so we'll initialise it to a driven-high state */
    gpio_init(spi_data->cs_gpio);
    gpio_set_dir(spi_data->cs_gpio, GPIO_OUT);
    gpio_put(spi_data->cs_gpio, 1);

    spidev_priv_data.ctx = NULL;
    memcpy(&spidev_priv_data.gpio_data, spi_data, sizeof(struct spi_gpio_data));

    spidev.priv = &spidev_priv_data;
    spidev.ops = NULL;

    tpm_spi_dev.ops = &spidev_ops;
    tpm_spi_dev.priv = NULL;

    VERBOSE("SPI initialized\n");

    return &spidev;
}

static uint64_t timeout_init_us_impl(uint32_t usec)
{
    (void)usec;

    dummpy_timer = 1000;

    return 0;
}

static bool timeout_elapsed_impl(uint64_t expiry_time_us)
{
    (void)expiry_time_us;

    if (dummpy_timer == 0) {
        return true;
    }

    dummpy_timer -= 1;

    return false;
}

static const struct tpm_timeout_ops tpm_lib_timeout_ops = {
    .timeout_init_us = timeout_init_us_impl,
    .timeout_elapsed = timeout_elapsed_impl
};

int tpm_plat_get_tpm_platform_config(struct tpm_timeout_ops *timeout_ops,
                                    const struct tpm_spi_plat **spi_plat,
                                    uint8_t tpm_instance_id)
{
    if (tpm_instance_id > 0) {
        return -1;
    }

    memcpy(timeout_ops, &tpm_lib_timeout_ops, sizeof(struct tpm_timeout_ops));
    *spi_plat = &tpm_spi_dev;

    return 0;
}
