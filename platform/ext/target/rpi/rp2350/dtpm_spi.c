/*
 *  SPDX-License-Identifier: BSD-3-Clause
 *  SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include <stdint.h>

#include "spi/spi.h"
#include "tfm_log.h"

#include "hardware/spi.h"
#include "hardware/gpio.h"

static struct spi_plat spidev;

static inline void cs_select()
{
    asm volatile("nop \n nop \n nop");
    gpio_put(spidev.gpio_data.cs_gpio, 0);
    asm volatile("nop \n nop \n nop");
}

static inline void cs_deselect()
{
    asm volatile("nop \n nop \n nop");
    gpio_put(spidev.gpio_data.cs_gpio, 1);
    asm volatile("nop \n nop \n nop");
}

static void spi_start(void)
{
    cs_select();
}

static void spi_stop(void)
{
    cs_deselect();
    spi_deinit(spi_default);
}

static void spi_get_access(void)
{
    uint ret_val;
    /* Initialize to 1Mhz */
    ret_val = spi_init(spi_default, 10 * 1000 * 1000);
    if (ret_val == 0) {
        ERROR("SPI init failed");
    }
}

static int spi_xfer(unsigned int bytes, const void *out, void *in)
{

    int ret;

    if ((out == NULL) && (in == NULL)) {
        return -1;
    }

    ret = spi_write_read_blocking(spi_default, out, in, bytes);
    if (ret == 0) {
        return -1;
    }

    return 0;
}

struct spi_ops spidev_ops = {
    .get_access = spi_get_access,
    .start      = spi_start,
    .stop       = spi_stop,
    .xfer       = spi_xfer,
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

    spidev.gpio_data = *spi_data;
    spidev.ops = &spidev_ops;

    VERBOSE("SPI initialized\n");

    return &spidev;
}
