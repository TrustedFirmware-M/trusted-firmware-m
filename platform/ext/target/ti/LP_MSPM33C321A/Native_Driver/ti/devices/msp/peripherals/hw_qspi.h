/*****************************************************************************

  Copyright (C) 2025 Texas Instruments Incorporated - http://www.ti.com/ 

  Redistribution and use in source and binary forms, with or without 
  modification, are permitted provided that the following conditions 
  are met:

   Redistributions of source code must retain the above copyright 
   notice, this list of conditions and the following disclaimer.

   Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the 
   documentation and/or other materials provided with the   
   distribution.

   Neither the name of Texas Instruments Incorporated nor the names of
   its contributors may be used to endorse or promote products derived
   from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*****************************************************************************/

#ifndef ti_devices_msp_peripherals_hw_qspi__include
#define ti_devices_msp_peripherals_hw_qspi__include

/* Filename: hw_qspi.h */
/* Revised: 2025-04-09 13:57:08 */
/* Revision: f4602b816b1643a266cc7aae6be755d35f394359 */

#ifndef __CORTEX_M
  #ifdef __cplusplus
    #define __I  volatile        /*!< Defines 'read only' permissions */
  #else
    #define __I  volatile const  /*!< Defines 'read only' permissions */
  #endif
  #define __O  volatile          /*!< Defines 'write only' permissions */
  #define __IO  volatile         /*!< Defines 'read / write' permissions */

  /* following defines should be used for structure members */
  #define __IM  volatile const   /*! Defines 'read only' structure member permissions */
  #define __OM  volatile         /*! Defines 'write only' structure member permissions */
  #define __IOM  volatile        /*! Defines 'read / write' structure member permissions */
#endif

/* Use standard integer types with explicit width */
#include <stdint.h>

#ifdef __cplusplus
 extern "C" {
#endif

#if defined ( __CC_ARM )
#pragma anon_unions
#endif

/******************************************************************************
* QSPI Registers
******************************************************************************/
#define QSPI_IPSPECIFIC_QSPI_OFS                 ((uint32_t)0x00001200U)
#define QSPI_DMA_TRIG_TX_OFS                     ((uint32_t)0x00001080U)
#define QSPI_DMA_TRIG_RX_OFS                     ((uint32_t)0x00001050U)
#define QSPI_CPU_INT_OFS                         ((uint32_t)0x00001020U)
#define QSPI_GPRCM_OFS                           ((uint32_t)0x00000800U)


/** @addtogroup QSPI_IPSPECIFIC_QSPI
  @{
*/

typedef struct {
  __IO uint32_t QSPICTL0;                          /* !< (@ 0x00001200) QSPI Control-0 register */
  __IO uint32_t QSPICTL1;                          /* !< (@ 0x00001204) QSPI Control-1 Register */
  __IO uint32_t QSPITIMING;                        /* !< (@ 0x00001208) The register is controls the timing setting for
                                                      chip select assertion and de-assertion with respect to the serial
                                                      clock, sampling delay for the data and chip-select behavior in
                                                      performance mode */
  __O  uint32_t QSPIFIFOCTL;                       /* !< (@ 0x0000120C) The register controls the flush operation in the
                                                      peripheral FIFO */
  __IO uint32_t QSPICSCTL;                         /* !< (@ 0x00001210) The register controls the toggling of chip select */
       uint32_t RESERVED0[3];
  __O  uint32_t QSPIDMACTL;                        /* !< (@ 0x00001220) The register is used to generate a soft trigger
                                                      for the DMA */
       uint32_t RESERVED1[4];
  __I  uint32_t QSPISTATUS;                        /* !< (@ 0x00001234) The register contains the status bits for the QSPI
                                                      controller and the FIFO */
} QSPI_IPSPECIFIC_QSPI_Regs;

/*@}*/ /* end of group QSPI_IPSPECIFIC_QSPI */

/** @addtogroup QSPI_DMA_TRIG_TX
  @{
*/

typedef struct {
  __I  uint32_t IIDX;                              /* !< (@ 0x00001080) Interrupt Index Register */
       uint32_t RESERVED0;
  __IO uint32_t IMASK;                             /* !< (@ 0x00001088) Interrupt mask */
       uint32_t RESERVED1;
  __I  uint32_t RIS;                               /* !< (@ 0x00001090) Raw interrupt status */
       uint32_t RESERVED2;
  __I  uint32_t MIS;                               /* !< (@ 0x00001098) Masked interrupt status */
       uint32_t RESERVED3;
  __O  uint32_t ISET;                              /* !< (@ 0x000010A0) Interrupt set */
       uint32_t RESERVED4;
  __O  uint32_t ICLR;                              /* !< (@ 0x000010A8) Interrupt clear */
} QSPI_DMA_TRIG_TX_Regs;

/*@}*/ /* end of group QSPI_DMA_TRIG_TX */

/** @addtogroup QSPI_DMA_TRIG_RX
  @{
*/

typedef struct {
  __I  uint32_t IIDX;                              /* !< (@ 0x00001050) Interrupt Index Register */
       uint32_t RESERVED0;
  __IO uint32_t IMASK;                             /* !< (@ 0x00001058) Interrupt mask */
       uint32_t RESERVED1;
  __I  uint32_t RIS;                               /* !< (@ 0x00001060) Raw interrupt status */
       uint32_t RESERVED2;
  __I  uint32_t MIS;                               /* !< (@ 0x00001068) Masked interrupt status */
       uint32_t RESERVED3;
  __O  uint32_t ISET;                              /* !< (@ 0x00001070) Interrupt set */
       uint32_t RESERVED4;
  __O  uint32_t ICLR;                              /* !< (@ 0x00001078) Interrupt clear */
} QSPI_DMA_TRIG_RX_Regs;

/*@}*/ /* end of group QSPI_DMA_TRIG_RX */

/** @addtogroup QSPI_CPU_INT
  @{
*/

typedef struct {
  __I  uint32_t IIDX;                              /* !< (@ 0x00001020) Interrupt Index Register */
       uint32_t RESERVED0;
  __IO uint32_t IMASK;                             /* !< (@ 0x00001028) Interrupt mask */
       uint32_t RESERVED1;
  __I  uint32_t RIS;                               /* !< (@ 0x00001030) Raw interrupt status */
       uint32_t RESERVED2;
  __I  uint32_t MIS;                               /* !< (@ 0x00001038) Masked interrupt status */
       uint32_t RESERVED3;
  __O  uint32_t ISET;                              /* !< (@ 0x00001040) Interrupt set */
       uint32_t RESERVED4;
  __O  uint32_t ICLR;                              /* !< (@ 0x00001048) Interrupt clear */
} QSPI_CPU_INT_Regs;

/*@}*/ /* end of group QSPI_CPU_INT */

/** @addtogroup QSPI_GPRCM
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00000800) Power enable */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00000804) Reset Control */
  __IO uint32_t CLKCFG;                            /* !< (@ 0x00000808) Peripheral Clock Configuration Register */
       uint32_t RESERVED0[2];
  __I  uint32_t STAT;                              /* !< (@ 0x00000814) Status Register */
} QSPI_GPRCM_Regs;

/*@}*/ /* end of group QSPI_GPRCM */

/** @addtogroup QSPI
  @{
*/

typedef struct {
       uint32_t RESERVED0[512];
  QSPI_GPRCM_Regs  GPRCM;                             /* !< (@ 0x00000800) */
       uint32_t RESERVED1[506];
  __IO uint32_t CLKDIV;                            /* !< (@ 0x00001000) Clock Divider */
  __IO uint32_t CLKSEL;                            /* !< (@ 0x00001004) Clock Select for Ultra Low Power peripherals */
       uint32_t RESERVED2[4];
  __IO uint32_t PDBGCTL;                           /* !< (@ 0x00001018) Peripheral Debug Control */
       uint32_t RESERVED3;
  QSPI_CPU_INT_Regs  CPU_INT;                           /* !< (@ 0x00001020) */
       uint32_t RESERVED4;
  QSPI_DMA_TRIG_RX_Regs  DMA_TRIG_RX;                       /* !< (@ 0x00001050) */
       uint32_t RESERVED5;
  QSPI_DMA_TRIG_TX_Regs  DMA_TRIG_TX;                       /* !< (@ 0x00001080) */
       uint32_t RESERVED6[13];
  __IO uint32_t EVT_MODE;                          /* !< (@ 0x000010E0) Event Mode */
  __IO uint32_t INTCTL;                            /* !< (@ 0x000010E4) Interrupt control register */
       uint32_t RESERVED7[6];
  __IO uint32_t CTL0;                              /* !< (@ 0x00001100) SPI control register 0 */
  __IO uint32_t CTL1;                              /* !< (@ 0x00001104) SPI control register 1 */
  __IO uint32_t CLKCTL;                            /* !< (@ 0x00001108) Clock prescaler and divider register. */
  __IO uint32_t IFLS;                              /* !< (@ 0x0000110C) Interrupt FIFO Level Select Register */
  __I  uint32_t STAT;                              /* !< (@ 0x00001110) Status Register */
       uint32_t RESERVED8[7];
  __I  uint32_t RXDATA;                            /* !< (@ 0x00001130) RXDATA Register */
       uint32_t RESERVED9[3];
  __IO uint32_t TXDATA;                            /* !< (@ 0x00001140) TXDATA Register */
       uint32_t RESERVED10[47];
  QSPI_IPSPECIFIC_QSPI_Regs  IPSPECIFIC_QSPI;                   /* !< (@ 0x00001200) */
} QSPI_Regs;

/*@}*/ /* end of group QSPI */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* QSPI Register Control Bits
******************************************************************************/

/* QSPI_QSPICTL0 Bits */
/* QSPI_QSPICTL0[QSPIDUMMYCLK] Bits */
#define QSPI_QSPICTL0_QSPIDUMMYCLK_OFS           (0)                             /* !< QSPIDUMMYCLK Offset */
#define QSPI_QSPICTL0_QSPIDUMMYCLK_MASK          ((uint32_t)0x0000000FU)         /* !< The bits provides the number of
                                                                                    dummy clocks to insert during a flash
                                                                                    read operation */
#define QSPI_QSPICTL0_QSPIDUMMYCLK_MINIMUM       ((uint32_t)0x00000000U)         /* !< Smallest value */
#define QSPI_QSPICTL0_QSPIDUMMYCLK_MAXIMUM       ((uint32_t)0x0000000FU)         /* !< Largest possible value */
/* QSPI_QSPICTL0[QSPIDSIZE] Bits */
#define QSPI_QSPICTL0_QSPIDSIZE_OFS              (6)                             /* !< QSPIDSIZE Offset */
#define QSPI_QSPICTL0_QSPIDSIZE_MASK             ((uint32_t)0x000000C0U)         /* !< The register bits provide the
                                                                                    packing and unpacking option from the
                                                                                    FIFO to the flash interface */
#define QSPI_QSPICTL0_QSPIDSIZE__8BITDSIZE       ((uint32_t)0x00000000U)         /* !< Sets 8-bit data write and read from
                                                                                    FIFO */
#define QSPI_QSPICTL0_QSPIDSIZE__16BITDSIZE      ((uint32_t)0x00000080U)         /* !< Sets 16-bit data write and read
                                                                                    from FIFO */
#define QSPI_QSPICTL0_QSPIDSIZE__32BITDSIZE      ((uint32_t)0x000000C0U)         /* !< Sets 32-bit data write and read
                                                                                    from FIFO */
/* QSPI_QSPICTL0[QSPICMDBYTE] Bits */
#define QSPI_QSPICTL0_QSPICMDBYTE_OFS            (8)                             /* !< QSPICMDBYTE Offset */
#define QSPI_QSPICTL0_QSPICMDBYTE_MASK           ((uint32_t)0x0000FF00U)         /* !< The register bits provide the
                                                                                    instruction opcode to be used during
                                                                                    a flash read */
#define QSPI_QSPICTL0_QSPICMDBYTE_MINIMUM        ((uint32_t)0x00000000U)         /* !< Smallest value */
#define QSPI_QSPICTL0_QSPICMDBYTE_MAXIMUM        ((uint32_t)0x0000FF00U)         /* !< Largest value */
/* QSPI_QSPICTL0[QSPIPERFBYTE] Bits */
#define QSPI_QSPICTL0_QSPIPERFBYTE_OFS           (16)                            /* !< QSPIPERFBYTE Offset */
#define QSPI_QSPICTL0_QSPIPERFBYTE_MASK          ((uint32_t)0x00FF0000U)         /* !< The register bits provide the
                                                                                    performance byte to be used during a
                                                                                    flash read */
#define QSPI_QSPICTL0_QSPIPERFBYTE_MINIMUM       ((uint32_t)0x00000000U)         /* !< Samllest value */
#define QSPI_QSPICTL0_QSPIPERFBYTE_MAXIMUM       ((uint32_t)0x00FF0000U)         /* !< Largest value */
/* QSPI_QSPICTL0[QSPIFORMAT] Bits */
#define QSPI_QSPICTL0_QSPIFORMAT_OFS             (24)                            /* !< QSPIFORMAT Offset */
#define QSPI_QSPICTL0_QSPIFORMAT_MASK            ((uint32_t)0x0F000000U)         /* !< The bits provides the bus format to
                                                                                    be used */
#define QSPI_QSPICTL0_QSPIFORMAT_LEGACY_SPI_FULLDUPLEX ((uint32_t)0x00000000U)         /* !< Legacy SPI format full-duplex */
#define QSPI_QSPICTL0_QSPIFORMAT_SPI_HALFDUPLEX  ((uint32_t)0x01000000U)         /* !< SPI format half-duplex when not
                                                                                    sending a data read frame */
#define QSPI_QSPICTL0_QSPIFORMAT_QPI_HALF_DUPLEX ((uint32_t)0x02000000U)         /* !< QPI format half-duplex when not
                                                                                    sending a data read frame */
#define QSPI_QSPICTL0_QSPIFORMAT_SSS_MODE        ((uint32_t)0x08000000U)         /* !< SSS format when sending a data read
                                                                                    frame */
#define QSPI_QSPICTL0_QSPIFORMAT_SSD_MODE        ((uint32_t)0x09000000U)         /* !< SSD format when sending a data read
                                                                                    frame */
#define QSPI_QSPICTL0_QSPIFORMAT_SDD_MODE        ((uint32_t)0x0A000000U)         /* !< SDD format when sending a data read
                                                                                    frame */
#define QSPI_QSPICTL0_QSPIFORMAT_SSQ_MODE        ((uint32_t)0x0B000000U)         /* !< SSQ format when sending a data read
                                                                                    frame */
#define QSPI_QSPICTL0_QSPIFORMAT_SQQ_MODE        ((uint32_t)0x0C000000U)         /* !< SQQ format when sending a data read
                                                                                    frame */
#define QSPI_QSPICTL0_QSPIFORMAT_QQQ_MODE        ((uint32_t)0x0D000000U)         /* !< QQQ format when sending a data read
                                                                                    frame */
/* QSPI_QSPICTL0[QSPIADDRMODE] Bits */
#define QSPI_QSPICTL0_QSPIADDRMODE_OFS           (28)                            /* !< QSPIADDRMODE Offset */
#define QSPI_QSPICTL0_QSPIADDRMODE_MASK          ((uint32_t)0x10000000U)         /* !< The bit field sets the number of
                                                                                    address byte to be used for
                                                                                    communication with QSPI flash during
                                                                                    a data read */
#define QSPI_QSPICTL0_QSPIADDRMODE__3BYTE_ADDR   ((uint32_t)0x00000000U)         /* !< Use 3-byte address */
#define QSPI_QSPICTL0_QSPIADDRMODE__4BYTE_ADDR   ((uint32_t)0x10000000U)         /* !< Use 4-byte address */
/* QSPI_QSPICTL0[QSPIPERFMODE] Bits */
#define QSPI_QSPICTL0_QSPIPERFMODE_OFS           (29)                            /* !< QSPIPERFMODE Offset */
#define QSPI_QSPICTL0_QSPIPERFMODE_MASK          ((uint32_t)0x20000000U)         /* !< This bit enables or disables the
                                                                                    performance mode byte insertion */
#define QSPI_QSPICTL0_QSPIPERFMODE_DISABLE       ((uint32_t)0x00000000U)         /* !< Performance mode is disabled */
#define QSPI_QSPICTL0_QSPIPERFMODE_ENABLE        ((uint32_t)0x20000000U)         /* !< Performance mode is enabled */
/* QSPI_QSPICTL0[QSPIMODE] Bits */
#define QSPI_QSPICTL0_QSPIMODE_OFS               (31)                            /* !< QSPIMODE Offset */
#define QSPI_QSPICTL0_QSPIMODE_MASK              ((uint32_t)0x80000000U)         /* !< This bits selects which port is
                                                                                    used for QSPI memory access */
#define QSPI_QSPICTL0_QSPIMODE_PERIPH_PORT       ((uint32_t)0x00000000U)         /* !< Selects peripheral port for
                                                                                    external flash access */
#define QSPI_QSPICTL0_QSPIMODE_DIRECT_PORT       ((uint32_t)0x80000000U)         /* !< Selects direct port for external
                                                                                    flash access */

/* QSPI_QSPICTL1 Bits */
/* QSPI_QSPICTL1[TXCOUNT] Bits */
#define QSPI_QSPICTL1_TXCOUNT_OFS                (0)                             /* !< TXCOUNT Offset */
#define QSPI_QSPICTL1_TXCOUNT_MASK               ((uint32_t)0x000001FFU)
#define QSPI_QSPICTL1_TXCOUNT_MINIMUM            ((uint32_t)0x00000000U)         /* !< Smallest possible value */
#define QSPI_QSPICTL1_TXCOUNT_MAXIMUM            ((uint32_t)0x000000FFU)         /* !< Highest possible value */
/* QSPI_QSPICTL1[QSPIPREFETCH] Bits */
#define QSPI_QSPICTL1_QSPIPREFETCH_OFS           (31)                            /* !< QSPIPREFETCH Offset */
#define QSPI_QSPICTL1_QSPIPREFETCH_MASK          ((uint32_t)0x80000000U)         /* !< Controls prefetch of data when the
                                                                                    read transaction is started */
#define QSPI_QSPICTL1_QSPIPREFETCH_DISABLE       ((uint32_t)0x00000000U)         /* !< Prefetch is disabled */
#define QSPI_QSPICTL1_QSPIPREFETCH_ENABLE        ((uint32_t)0x80000000U)         /* !< Prefetch is enabled */
/* QSPI_QSPICTL1[RXCOUNT] Bits */
#define QSPI_QSPICTL1_RXCOUNT_OFS                (16)                            /* !< RXCOUNT Offset */
#define QSPI_QSPICTL1_RXCOUNT_MASK               ((uint32_t)0x00FF0000U)
#define QSPI_QSPICTL1_RXCOUNT_RXFIFOMON          ((uint32_t)0x00000000U)         /* !< Only RXFIFO full level is
                                                                                    monitored. */
#define QSPI_QSPICTL1_RXCOUNT_MINIMUM            ((uint32_t)0x00010000U)         /* !< Smalles possible value */
#define QSPI_QSPICTL1_RXCOUNT_MAXIMUM            ((uint32_t)0x00FF0000U)         /* !< Highest possible value */

/* QSPI_QSPITIMING Bits */
/* QSPI_QSPITIMING[CSDEASSERTDLY] Bits */
#define QSPI_QSPITIMING_CSDEASSERTDLY_OFS        (0)                             /* !< CSDEASSERTDLY Offset */
#define QSPI_QSPITIMING_CSDEASSERTDLY_MASK       ((uint32_t)0x00000001U)         /* !< When in QSPI mode the bit controls
                                                                                    the number of serial clock edge after
                                                                                    last SCLK to deassert the chip select */
#define QSPI_QSPITIMING_CSDEASSERTDLY__0P5SCLKDELAY ((uint32_t)0x00000000U)         /* !< Chip select is deasserted 0.5
                                                                                    internal SCLK after last edge of the
                                                                                    external SCLK */
#define QSPI_QSPITIMING_CSDEASSERTDLY__1P5SCLKDELAY ((uint32_t)0x00000001U)         /* !< Chip select is deasserted 1.5
                                                                                    internal SCLK after last edge of the
                                                                                    external SCLK */
/* QSPI_QSPITIMING[CSASSERTDLY] Bits */
#define QSPI_QSPITIMING_CSASSERTDLY_OFS          (4)                             /* !< CSASSERTDLY Offset */
#define QSPI_QSPITIMING_CSASSERTDLY_MASK         ((uint32_t)0x00000010U)         /* !< When in QSPI mode the bit controls
                                                                                    the number of serial clock edge after
                                                                                    chip select is asserted to start the
                                                                                    SCLK */
#define QSPI_QSPITIMING_CSASSERTDLY__0P5SCLKDELAY ((uint32_t)0x00000000U)         /* !< SCLK is started 0.5 internal SCLK
                                                                                    after CS is asserted */
#define QSPI_QSPITIMING_CSASSERTDLY__1P5SCLKDELAY ((uint32_t)0x00000010U)         /* !< SCLK is started 1.5 internal SCLK
                                                                                    after CS is asserted */
/* QSPI_QSPITIMING[DATASAMPLDLY] Bits */
#define QSPI_QSPITIMING_DATASAMPLDLY_OFS         (8)                             /* !< DATASAMPLDLY Offset */
#define QSPI_QSPITIMING_DATASAMPLDLY_MASK        ((uint32_t)0x00000100U)         /* !< When in QSPI mode, controls the
                                                                                    sampling of the received data */
#define QSPI_QSPITIMING_DATASAMPLDLY_NODELAY     ((uint32_t)0x00000000U)         /* !< Received data is sampled on the
                                                                                    rising edge of SCLK */
#define QSPI_QSPITIMING_DATASAMPLDLY__1CLKDELAY  ((uint32_t)0x00000100U)         /* !< Received data is delayed by 1 SCLK
                                                                                    before being sampled */
/* QSPI_QSPITIMING[CSHIGHTIME] Bits */
#define QSPI_QSPITIMING_CSHIGHTIME_OFS           (16)                            /* !< CSHIGHTIME Offset */
#define QSPI_QSPITIMING_CSHIGHTIME_MASK          ((uint32_t)0x00FF0000U)         /* !< When in performance mode, the
                                                                                    parameter provides the number of bus
                                                                                    clocks for which the CS shgall be
                                                                                    high when an address change is
                                                                                    detected */
#define QSPI_QSPITIMING_CSHIGHTIME_MINIMUM       ((uint32_t)0x00000000U)         /* !< Smallest value */
#define QSPI_QSPITIMING_CSHIGHTIME_MAXIMUM       ((uint32_t)0x00FF0000U)         /* !< Largest value */

/* QSPI_QSPIFIFOCTL Bits */
/* QSPI_QSPIFIFOCTL[RXFIFOFLUSH] Bits */
#define QSPI_QSPIFIFOCTL_RXFIFOFLUSH_OFS         (0)                             /* !< RXFIFOFLUSH Offset */
#define QSPI_QSPIFIFOCTL_RXFIFOFLUSH_MASK        ((uint32_t)0x00000001U)         /* !< The bit is used to reset the RXFIFO
                                                                                    pointers to flush any data from the
                                                                                    preceding transaction. */
#define QSPI_QSPIFIFOCTL_RXFIFOFLUSH_NOEFFECT    ((uint32_t)0x00000000U)         /* !< No effect */
#define QSPI_QSPIFIFOCTL_RXFIFOFLUSH_CLEAR       ((uint32_t)0x00000001U)         /* !< Resets the RXFIFO and any
                                                                                    corresponding status bit. The field
                                                                                    will be auto-cleared after RXFIFO is
                                                                                    reset */
/* QSPI_QSPIFIFOCTL[TXFIFOFLUSH] Bits */
#define QSPI_QSPIFIFOCTL_TXFIFOFLUSH_OFS         (1)                             /* !< TXFIFOFLUSH Offset */
#define QSPI_QSPIFIFOCTL_TXFIFOFLUSH_MASK        ((uint32_t)0x00000002U)         /* !< The bit is used to reset the TXFIFO
                                                                                    pointers to flush any data from the
                                                                                    preceding transaction. */
#define QSPI_QSPIFIFOCTL_TXFIFOFLUSH_NOEFFECT    ((uint32_t)0x00000000U)         /* !< No effect */
#define QSPI_QSPIFIFOCTL_TXFIFOFLUSH_CLEAR       ((uint32_t)0x00000002U)         /* !< Resets the TXFIFO and any
                                                                                    corresponding status bit. The field
                                                                                    will be auto-cleared after TXFIFO is
                                                                                    reset */

/* QSPI_QSPICSCTL Bits */
/* QSPI_QSPICSCTL[CSHOLDCTL] Bits */
#define QSPI_QSPICSCTL_CSHOLDCTL_OFS             (31)                            /* !< CSHOLDCTL Offset */
#define QSPI_QSPICSCTL_CSHOLDCTL_MASK            ((uint32_t)0x80000000U)         /* !< Controls the chip select hold
                                                                                    feature during an active transaction
                                                                                    when QSPIFORMAT is not 0x0 */
#define QSPI_QSPICSCTL_CSHOLDCTL_NOEFFECT        ((uint32_t)0x00000000U)         /* !< No effect */
#define QSPI_QSPICSCTL_CSHOLDCTL_DEASSERT        ((uint32_t)0x80000000U)         /* !< When written as 1, causes the chip
                                                                                    select to be deasserted after the
                                                                                    current bus transaction is completed */

/* QSPI_QSPIDMACTL Bits */
/* QSPI_QSPIDMACTL[DMATRIG] Bits */
#define QSPI_QSPIDMACTL_DMATRIG_OFS              (0)                             /* !< DMATRIG Offset */
#define QSPI_QSPIDMACTL_DMATRIG_MASK             ((uint32_t)0x00000001U)
#define QSPI_QSPIDMACTL_DMATRIG_DMATRIG_NOEFFECT ((uint32_t)0x00000000U)         /* !< Writing the bit as 0 has no effect */
#define QSPI_QSPIDMACTL_DMATRIG_DMATRIG_ENABLE   ((uint32_t)0x00000001U)         /* !< Writing this bit as 1 asserts a DMA
                                                                                    request */

/* QSPI_QSPISTATUS Bits */
/* QSPI_QSPISTATUS[RXFIFOE] Bits */
#define QSPI_QSPISTATUS_RXFIFOE_OFS              (0)                             /* !< RXFIFOE Offset */
#define QSPI_QSPISTATUS_RXFIFOE_MASK             ((uint32_t)0x00000001U)         /* !< Receive FIFO status empty status */
#define QSPI_QSPISTATUS_RXFIFOE_RXFIFOE_NE       ((uint32_t)0x00000000U)         /* !< Receive FIFO is not empty */
#define QSPI_QSPISTATUS_RXFIFOE_RXFIFOE_E        ((uint32_t)0x00000001U)         /* !< Receive FIFO is empty */
/* QSPI_QSPISTATUS[RXFIFONF] Bits */
#define QSPI_QSPISTATUS_RXFIFONF_OFS             (1)                             /* !< RXFIFONF Offset */
#define QSPI_QSPISTATUS_RXFIFONF_MASK            ((uint32_t)0x00000002U)         /* !< Receive FIFO not full status */
#define QSPI_QSPISTATUS_RXFIFONF_RXFIFONF_F      ((uint32_t)0x00000000U)         /* !< Receive FIFO is full */
#define QSPI_QSPISTATUS_RXFIFONF_RXFIFONF_NF     ((uint32_t)0x00000002U)         /* !< Receive FIFO is not full */
/* QSPI_QSPISTATUS[TXFIFOE] Bits */
#define QSPI_QSPISTATUS_TXFIFOE_OFS              (2)                             /* !< TXFIFOE Offset */
#define QSPI_QSPISTATUS_TXFIFOE_MASK             ((uint32_t)0x00000004U)         /* !< Transmit FIFO empty status */
#define QSPI_QSPISTATUS_TXFIFOE_TXFIFOE_NE       ((uint32_t)0x00000000U)         /* !< Transmit FIFO is not empty */
#define QSPI_QSPISTATUS_TXFIFOE_TXFIFOE_E        ((uint32_t)0x00000004U)         /* !< Transmit FIFO is empty */
/* QSPI_QSPISTATUS[TXFIFONF] Bits */
#define QSPI_QSPISTATUS_TXFIFONF_OFS             (3)                             /* !< TXFIFONF Offset */
#define QSPI_QSPISTATUS_TXFIFONF_MASK            ((uint32_t)0x00000008U)         /* !< Transmit FIFO not full status */
#define QSPI_QSPISTATUS_TXFIFONF_TXFIFONF_F      ((uint32_t)0x00000000U)         /* !< Transmit FIFO is full */
#define QSPI_QSPISTATUS_TXFIFONF_TXFIFONF_NF     ((uint32_t)0x00000008U)         /* !< Transmit FIFO is not full */
/* QSPI_QSPISTATUS[QSPISTALL] Bits */
#define QSPI_QSPISTATUS_QSPISTALL_OFS            (6)                             /* !< QSPISTALL Offset */
#define QSPI_QSPISTATUS_QSPISTALL_MASK           ((uint32_t)0x00000040U)         /* !< The bit indicates the state of the
                                                                                    QSPI controller during an active
                                                                                    transaction */
#define QSPI_QSPISTATUS_QSPISTALL_QSPISTALL_ACTIVE ((uint32_t)0x00000000U)         /* !< The QSPI is sending or receiving
                                                                                    data bytes from the memory */
#define QSPI_QSPISTATUS_QSPISTALL_QSPISTALL_STALL ((uint32_t)0x00000040U)         /* !< The QSPI is currently stalled on
                                                                                    the TXFIFO empty to have data or
                                                                                    RXFIFO empty to have space to receive
                                                                                    data */
/* QSPI_QSPISTATUS[QSPIIDLE] Bits */
#define QSPI_QSPISTATUS_QSPIIDLE_OFS             (7)                             /* !< QSPIIDLE Offset */
#define QSPI_QSPISTATUS_QSPIIDLE_MASK            ((uint32_t)0x00000080U)         /* !< Provides the state of the QSPI
                                                                                    controller */
#define QSPI_QSPISTATUS_QSPIIDLE_QSPIIDLE_ACT    ((uint32_t)0x00000000U)         /* !< The QSPI has an active transaction
                                                                                    ongoing or stalled and the chip
                                                                                    select is low */
#define QSPI_QSPISTATUS_QSPIIDLE_QSPIIDLE_IDLE   ((uint32_t)0x00000080U)         /* !< The QSPI does not have an active
                                                                                    transaction and the chip select is
                                                                                    high */

/* QSPI_DMA_TRIG_TX_IIDX Bits */
/* QSPI_DMA_TRIG_TX_IIDX[STAT] Bits */
#define QSPI_DMA_TRIG_TX_IIDX_STAT_OFS           (0)                             /* !< STAT Offset */
#define QSPI_DMA_TRIG_TX_IIDX_STAT_MASK          ((uint32_t)0x000000FFU)         /* !< Interrupt index status */
#define QSPI_DMA_TRIG_TX_IIDX_STAT_NO_INTR       ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define QSPI_DMA_TRIG_TX_IIDX_STAT_TX_EVT        ((uint32_t)0x00000005U)         /* !< Transmit Event/interrupt pending */

/* QSPI_DMA_TRIG_TX_IMASK Bits */
/* QSPI_DMA_TRIG_TX_IMASK[TX] Bits */
#define QSPI_DMA_TRIG_TX_IMASK_TX_OFS            (4)                             /* !< TX Offset */
#define QSPI_DMA_TRIG_TX_IMASK_TX_MASK           ((uint32_t)0x00000010U)         /* !< Transmit FIFO event mask. */
#define QSPI_DMA_TRIG_TX_IMASK_TX_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define QSPI_DMA_TRIG_TX_IMASK_TX_SET            ((uint32_t)0x00000010U)         /* !< Set Interrupt Mask */

/* QSPI_DMA_TRIG_TX_RIS Bits */
/* QSPI_DMA_TRIG_TX_RIS[TX] Bits */
#define QSPI_DMA_TRIG_TX_RIS_TX_OFS              (4)                             /* !< TX Offset */
#define QSPI_DMA_TRIG_TX_RIS_TX_MASK             ((uint32_t)0x00000010U)         /* !< Transmit FIFO event: A read returns
                                                                                    the current mask for transmit FIFO
                                                                                    interrupt. On a write of 1, the mask
                                                                                    for transmit FIFO interrupt is set
                                                                                    which means the interrupt state will
                                                                                    be reflected in MIS.TXMIS. A write of
                                                                                    0 clears the mask which means
                                                                                    MIS.TXMIS will not reflect the
                                                                                    interrupt. */
#define QSPI_DMA_TRIG_TX_RIS_TX_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define QSPI_DMA_TRIG_TX_RIS_TX_SET              ((uint32_t)0x00000010U)         /* !< Interrupt occurred */

/* QSPI_DMA_TRIG_TX_MIS Bits */
/* QSPI_DMA_TRIG_TX_MIS[TX] Bits */
#define QSPI_DMA_TRIG_TX_MIS_TX_OFS              (4)                             /* !< TX Offset */
#define QSPI_DMA_TRIG_TX_MIS_TX_MASK             ((uint32_t)0x00000010U)         /* !< Masked Transmit FIFO event */
#define QSPI_DMA_TRIG_TX_MIS_TX_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define QSPI_DMA_TRIG_TX_MIS_TX_SET              ((uint32_t)0x00000010U)         /* !< Interrupt occurred */

/* QSPI_DMA_TRIG_TX_ISET Bits */
/* QSPI_DMA_TRIG_TX_ISET[TX] Bits */
#define QSPI_DMA_TRIG_TX_ISET_TX_OFS             (4)                             /* !< TX Offset */
#define QSPI_DMA_TRIG_TX_ISET_TX_MASK            ((uint32_t)0x00000010U)         /* !< Set Transmit FIFO event. */
#define QSPI_DMA_TRIG_TX_ISET_TX_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define QSPI_DMA_TRIG_TX_ISET_TX_SET             ((uint32_t)0x00000010U)         /* !< Set Interrupt */

/* QSPI_DMA_TRIG_TX_ICLR Bits */
/* QSPI_DMA_TRIG_TX_ICLR[TX] Bits */
#define QSPI_DMA_TRIG_TX_ICLR_TX_OFS             (4)                             /* !< TX Offset */
#define QSPI_DMA_TRIG_TX_ICLR_TX_MASK            ((uint32_t)0x00000010U)         /* !< Clear Transmit FIFO event. */
#define QSPI_DMA_TRIG_TX_ICLR_TX_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define QSPI_DMA_TRIG_TX_ICLR_TX_CLR             ((uint32_t)0x00000010U)         /* !< Clear Interrupt */

/* QSPI_DMA_TRIG_RX_IIDX Bits */
/* QSPI_DMA_TRIG_RX_IIDX[STAT] Bits */
#define QSPI_DMA_TRIG_RX_IIDX_STAT_OFS           (0)                             /* !< STAT Offset */
#define QSPI_DMA_TRIG_RX_IIDX_STAT_MASK          ((uint32_t)0x000000FFU)         /* !< Interrupt index status */
#define QSPI_DMA_TRIG_RX_IIDX_STAT_NO_INTR       ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define QSPI_DMA_TRIG_RX_IIDX_STAT_RTOUT_EVT     ((uint32_t)0x00000003U)         /* !< SPI receive time-out interrupt */
#define QSPI_DMA_TRIG_RX_IIDX_STAT_RX_EVT        ((uint32_t)0x00000004U)         /* !< Receive Event/interrupt pending */

/* QSPI_DMA_TRIG_RX_IMASK Bits */
/* QSPI_DMA_TRIG_RX_IMASK[RX] Bits */
#define QSPI_DMA_TRIG_RX_IMASK_RX_OFS            (3)                             /* !< RX Offset */
#define QSPI_DMA_TRIG_RX_IMASK_RX_MASK           ((uint32_t)0x00000008U)         /* !< Receive FIFO event mask. */
#define QSPI_DMA_TRIG_RX_IMASK_RX_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define QSPI_DMA_TRIG_RX_IMASK_RX_SET            ((uint32_t)0x00000008U)         /* !< Set Interrupt Mask */
/* QSPI_DMA_TRIG_RX_IMASK[RTOUT] Bits */
#define QSPI_DMA_TRIG_RX_IMASK_RTOUT_OFS         (2)                             /* !< RTOUT Offset */
#define QSPI_DMA_TRIG_RX_IMASK_RTOUT_MASK        ((uint32_t)0x00000004U)         /* !< SPI Receive Time-Out event mask. */
#define QSPI_DMA_TRIG_RX_IMASK_RTOUT_CLR         ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define QSPI_DMA_TRIG_RX_IMASK_RTOUT_SET         ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */

/* QSPI_DMA_TRIG_RX_RIS Bits */
/* QSPI_DMA_TRIG_RX_RIS[RX] Bits */
#define QSPI_DMA_TRIG_RX_RIS_RX_OFS              (3)                             /* !< RX Offset */
#define QSPI_DMA_TRIG_RX_RIS_RX_MASK             ((uint32_t)0x00000008U)         /* !< Receive FIFO event.This interrupt
                                                                                    is set if the selected Receive FIFO
                                                                                    level has been reached */
#define QSPI_DMA_TRIG_RX_RIS_RX_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define QSPI_DMA_TRIG_RX_RIS_RX_SET              ((uint32_t)0x00000008U)         /* !< Interrupt occurred */
/* QSPI_DMA_TRIG_RX_RIS[RTOUT] Bits */
#define QSPI_DMA_TRIG_RX_RIS_RTOUT_OFS           (2)                             /* !< RTOUT Offset */
#define QSPI_DMA_TRIG_RX_RIS_RTOUT_MASK          ((uint32_t)0x00000004U)         /* !< SPI Receive Time-Out Event. */
#define QSPI_DMA_TRIG_RX_RIS_RTOUT_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define QSPI_DMA_TRIG_RX_RIS_RTOUT_SET           ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */

/* QSPI_DMA_TRIG_RX_MIS Bits */
/* QSPI_DMA_TRIG_RX_MIS[RX] Bits */
#define QSPI_DMA_TRIG_RX_MIS_RX_OFS              (3)                             /* !< RX Offset */
#define QSPI_DMA_TRIG_RX_MIS_RX_MASK             ((uint32_t)0x00000008U)         /* !< Receive FIFO event mask. */
#define QSPI_DMA_TRIG_RX_MIS_RX_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define QSPI_DMA_TRIG_RX_MIS_RX_SET              ((uint32_t)0x00000008U)         /* !< Interrupt occurred */
/* QSPI_DMA_TRIG_RX_MIS[RTOUT] Bits */
#define QSPI_DMA_TRIG_RX_MIS_RTOUT_OFS           (2)                             /* !< RTOUT Offset */
#define QSPI_DMA_TRIG_RX_MIS_RTOUT_MASK          ((uint32_t)0x00000004U)         /* !< SPI Receive Time-Out event mask. */
#define QSPI_DMA_TRIG_RX_MIS_RTOUT_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define QSPI_DMA_TRIG_RX_MIS_RTOUT_SET           ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */

/* QSPI_DMA_TRIG_RX_ISET Bits */
/* QSPI_DMA_TRIG_RX_ISET[RX] Bits */
#define QSPI_DMA_TRIG_RX_ISET_RX_OFS             (3)                             /* !< RX Offset */
#define QSPI_DMA_TRIG_RX_ISET_RX_MASK            ((uint32_t)0x00000008U)         /* !< Set Receive FIFO event. */
#define QSPI_DMA_TRIG_RX_ISET_RX_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define QSPI_DMA_TRIG_RX_ISET_RX_SET             ((uint32_t)0x00000008U)         /* !< Set Interrupt */
/* QSPI_DMA_TRIG_RX_ISET[RTOUT] Bits */
#define QSPI_DMA_TRIG_RX_ISET_RTOUT_OFS          (2)                             /* !< RTOUT Offset */
#define QSPI_DMA_TRIG_RX_ISET_RTOUT_MASK         ((uint32_t)0x00000004U)         /* !< Set SPI Receive Time-Out event. */
#define QSPI_DMA_TRIG_RX_ISET_RTOUT_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define QSPI_DMA_TRIG_RX_ISET_RTOUT_SET          ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */

/* QSPI_DMA_TRIG_RX_ICLR Bits */
/* QSPI_DMA_TRIG_RX_ICLR[RX] Bits */
#define QSPI_DMA_TRIG_RX_ICLR_RX_OFS             (3)                             /* !< RX Offset */
#define QSPI_DMA_TRIG_RX_ICLR_RX_MASK            ((uint32_t)0x00000008U)         /* !< Clear Receive FIFO event. */
#define QSPI_DMA_TRIG_RX_ICLR_RX_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define QSPI_DMA_TRIG_RX_ICLR_RX_CLR             ((uint32_t)0x00000008U)         /* !< Clear Interrupt */
/* QSPI_DMA_TRIG_RX_ICLR[RTOUT] Bits */
#define QSPI_DMA_TRIG_RX_ICLR_RTOUT_OFS          (2)                             /* !< RTOUT Offset */
#define QSPI_DMA_TRIG_RX_ICLR_RTOUT_MASK         ((uint32_t)0x00000004U)         /* !< Clear SPI Receive Time-Out event. */
#define QSPI_DMA_TRIG_RX_ICLR_RTOUT_NO_EFFECT    ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define QSPI_DMA_TRIG_RX_ICLR_RTOUT_CLR          ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */

/* QSPI_CPU_INT_IIDX Bits */
/* QSPI_CPU_INT_IIDX[STAT] Bits */
#define QSPI_CPU_INT_IIDX_STAT_OFS               (0)                             /* !< STAT Offset */
#define QSPI_CPU_INT_IIDX_STAT_MASK              ((uint32_t)0x000000FFU)         /* !< Interrupt index status */
#define QSPI_CPU_INT_IIDX_STAT_NO_INTR           ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define QSPI_CPU_INT_IIDX_STAT_RXFIFO_OFV_EVT    ((uint32_t)0x00000001U)         /* !< RX FIFO Overflow Event/interrupt
                                                                                    pending */
#define QSPI_CPU_INT_IIDX_STAT_PER_EVT           ((uint32_t)0x00000002U)         /* !< Transmit Parity Event/interrupt
                                                                                    pending */
#define QSPI_CPU_INT_IIDX_STAT_RTOUT_EVT         ((uint32_t)0x00000003U)         /* !< SPI receive time-out interrupt */
#define QSPI_CPU_INT_IIDX_STAT_RX_EVT            ((uint32_t)0x00000004U)         /* !< Receive Event/interrupt pending */
#define QSPI_CPU_INT_IIDX_STAT_TX_EVT            ((uint32_t)0x00000005U)         /* !< Transmit Event/interrupt pending */
#define QSPI_CPU_INT_IIDX_STAT_TX_EMPTY          ((uint32_t)0x00000006U)         /* !< Transmit Buffer Empty
                                                                                    Event/interrupt pending */
#define QSPI_CPU_INT_IIDX_STAT_IDLE_EVT          ((uint32_t)0x00000007U)         /* !< End of Transmit Event/interrupt
                                                                                    pending */
#define QSPI_CPU_INT_IIDX_STAT_DMA_DONE_RX_EVT   ((uint32_t)0x00000008U)         /* !< DMA Done for Receive
                                                                                    Event/interrupt pending */
#define QSPI_CPU_INT_IIDX_STAT_DMA_DONE_TX_EVT   ((uint32_t)0x00000009U)         /* !< DMA Done for Transmit
                                                                                    Event/interrupt pending */
#define QSPI_CPU_INT_IIDX_STAT_TXFIFO_UNF_EVT    ((uint32_t)0x0000000AU)         /* !< TX FIFO underflow interrupt */
#define QSPI_CPU_INT_IIDX_STAT_RXFULL_EVT        ((uint32_t)0x0000000BU)         /* !< RX FIFO Full Interrupt */

/* QSPI_CPU_INT_IMASK Bits */
/* QSPI_CPU_INT_IMASK[RX] Bits */
#define QSPI_CPU_INT_IMASK_RX_OFS                (3)                             /* !< RX Offset */
#define QSPI_CPU_INT_IMASK_RX_MASK               ((uint32_t)0x00000008U)         /* !< Receive FIFO event.This interrupt
                                                                                    is set if the selected Receive FIFO
                                                                                    level has been reached */
#define QSPI_CPU_INT_IMASK_RX_CLR                ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define QSPI_CPU_INT_IMASK_RX_SET                ((uint32_t)0x00000008U)         /* !< Set Interrupt Mask */
/* QSPI_CPU_INT_IMASK[TX] Bits */
#define QSPI_CPU_INT_IMASK_TX_OFS                (4)                             /* !< TX Offset */
#define QSPI_CPU_INT_IMASK_TX_MASK               ((uint32_t)0x00000010U)         /* !< Transmit FIFO event mask. */
#define QSPI_CPU_INT_IMASK_TX_CLR                ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define QSPI_CPU_INT_IMASK_TX_SET                ((uint32_t)0x00000010U)         /* !< Set Interrupt Mask */
/* QSPI_CPU_INT_IMASK[TXEMPTY] Bits */
#define QSPI_CPU_INT_IMASK_TXEMPTY_OFS           (5)                             /* !< TXEMPTY Offset */
#define QSPI_CPU_INT_IMASK_TXEMPTY_MASK          ((uint32_t)0x00000020U)         /* !< Transmit FIFO Empty event mask. */
#define QSPI_CPU_INT_IMASK_TXEMPTY_CLR           ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define QSPI_CPU_INT_IMASK_TXEMPTY_SET           ((uint32_t)0x00000020U)         /* !< Set Interrupt Mask */
/* QSPI_CPU_INT_IMASK[PER] Bits */
#define QSPI_CPU_INT_IMASK_PER_OFS               (1)                             /* !< PER Offset */
#define QSPI_CPU_INT_IMASK_PER_MASK              ((uint32_t)0x00000002U)         /* !< Parity error event mask. */
#define QSPI_CPU_INT_IMASK_PER_CLR               ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define QSPI_CPU_INT_IMASK_PER_SET               ((uint32_t)0x00000002U)         /* !< Set Interrupt Mask */
/* QSPI_CPU_INT_IMASK[DMA_DONE_RX] Bits */
#define QSPI_CPU_INT_IMASK_DMA_DONE_RX_OFS       (7)                             /* !< DMA_DONE_RX Offset */
#define QSPI_CPU_INT_IMASK_DMA_DONE_RX_MASK      ((uint32_t)0x00000080U)         /* !< DMA Done 1 event for RX event mask. */
#define QSPI_CPU_INT_IMASK_DMA_DONE_RX_CLR       ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define QSPI_CPU_INT_IMASK_DMA_DONE_RX_SET       ((uint32_t)0x00000080U)         /* !< Set Interrupt Mask */
/* QSPI_CPU_INT_IMASK[RXFIFO_OVF] Bits */
#define QSPI_CPU_INT_IMASK_RXFIFO_OVF_OFS        (0)                             /* !< RXFIFO_OVF Offset */
#define QSPI_CPU_INT_IMASK_RXFIFO_OVF_MASK       ((uint32_t)0x00000001U)         /* !< RXFIFO overflow event mask. */
#define QSPI_CPU_INT_IMASK_RXFIFO_OVF_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define QSPI_CPU_INT_IMASK_RXFIFO_OVF_SET        ((uint32_t)0x00000001U)         /* !< Set Interrupt Mask */
/* QSPI_CPU_INT_IMASK[DMA_DONE_TX] Bits */
#define QSPI_CPU_INT_IMASK_DMA_DONE_TX_OFS       (8)                             /* !< DMA_DONE_TX Offset */
#define QSPI_CPU_INT_IMASK_DMA_DONE_TX_MASK      ((uint32_t)0x00000100U)         /* !< DMA Done 1 event for TX event mask. */
#define QSPI_CPU_INT_IMASK_DMA_DONE_TX_CLR       ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define QSPI_CPU_INT_IMASK_DMA_DONE_TX_SET       ((uint32_t)0x00000100U)         /* !< Set Interrupt Mask */
/* QSPI_CPU_INT_IMASK[IDLE] Bits */
#define QSPI_CPU_INT_IMASK_IDLE_OFS              (6)                             /* !< IDLE Offset */
#define QSPI_CPU_INT_IMASK_IDLE_MASK             ((uint32_t)0x00000040U)         /* !< SPI Idle event mask. */
#define QSPI_CPU_INT_IMASK_IDLE_CLR              ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define QSPI_CPU_INT_IMASK_IDLE_SET              ((uint32_t)0x00000040U)         /* !< Set Interrupt Mask */
/* QSPI_CPU_INT_IMASK[RTOUT] Bits */
#define QSPI_CPU_INT_IMASK_RTOUT_OFS             (2)                             /* !< RTOUT Offset */
#define QSPI_CPU_INT_IMASK_RTOUT_MASK            ((uint32_t)0x00000004U)         /* !< Enable SPI Receive Time-Out event
                                                                                    mask. */
#define QSPI_CPU_INT_IMASK_RTOUT_CLR             ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define QSPI_CPU_INT_IMASK_RTOUT_SET             ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */
/* QSPI_CPU_INT_IMASK[RXFULL] Bits */
#define QSPI_CPU_INT_IMASK_RXFULL_OFS            (10)                            /* !< RXFULL Offset */
#define QSPI_CPU_INT_IMASK_RXFULL_MASK           ((uint32_t)0x00000400U)         /* !< RX FIFO Full Interrupt Mask */
#define QSPI_CPU_INT_IMASK_RXFULL_CLR            ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define QSPI_CPU_INT_IMASK_RXFULL_SET            ((uint32_t)0x00000400U)         /* !< Set Interrupt Mask */
/* QSPI_CPU_INT_IMASK[TXFIFO_UNF] Bits */
#define QSPI_CPU_INT_IMASK_TXFIFO_UNF_OFS        (9)                             /* !< TXFIFO_UNF Offset */
#define QSPI_CPU_INT_IMASK_TXFIFO_UNF_MASK       ((uint32_t)0x00000200U)         /* !< TX FIFO underflow interrupt mask */
#define QSPI_CPU_INT_IMASK_TXFIFO_UNF_CLR        ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define QSPI_CPU_INT_IMASK_TXFIFO_UNF_SET        ((uint32_t)0x00000200U)         /* !< Set Interrupt Mask */

/* QSPI_CPU_INT_RIS Bits */
/* QSPI_CPU_INT_RIS[RX] Bits */
#define QSPI_CPU_INT_RIS_RX_OFS                  (3)                             /* !< RX Offset */
#define QSPI_CPU_INT_RIS_RX_MASK                 ((uint32_t)0x00000008U)         /* !< Receive FIFO event.This interrupt
                                                                                    is set if the selected Receive FIFO
                                                                                    level has been reached */
#define QSPI_CPU_INT_RIS_RX_CLR                  ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define QSPI_CPU_INT_RIS_RX_SET                  ((uint32_t)0x00000008U)         /* !< Interrupt occurred */
/* QSPI_CPU_INT_RIS[TX] Bits */
#define QSPI_CPU_INT_RIS_TX_OFS                  (4)                             /* !< TX Offset */
#define QSPI_CPU_INT_RIS_TX_MASK                 ((uint32_t)0x00000010U)         /* !< Transmit FIFO event..This interrupt
                                                                                    is set if the selected Transmit FIFO
                                                                                    level has been reached. */
#define QSPI_CPU_INT_RIS_TX_CLR                  ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define QSPI_CPU_INT_RIS_TX_SET                  ((uint32_t)0x00000010U)         /* !< Interrupt occurred */
/* QSPI_CPU_INT_RIS[TXEMPTY] Bits */
#define QSPI_CPU_INT_RIS_TXEMPTY_OFS             (5)                             /* !< TXEMPTY Offset */
#define QSPI_CPU_INT_RIS_TXEMPTY_MASK            ((uint32_t)0x00000020U)         /* !< Transmit FIFO Empty interrupt mask.
                                                                                    This interrupt is set if all data in
                                                                                    the Transmit FIFO have been move to
                                                                                    the shift register. */
#define QSPI_CPU_INT_RIS_TXEMPTY_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define QSPI_CPU_INT_RIS_TXEMPTY_SET             ((uint32_t)0x00000020U)         /* !< Interrupt occurred */
/* QSPI_CPU_INT_RIS[PER] Bits */
#define QSPI_CPU_INT_RIS_PER_OFS                 (1)                             /* !< PER Offset */
#define QSPI_CPU_INT_RIS_PER_MASK                ((uint32_t)0x00000002U)         /* !< Parity error event: this bit is set
                                                                                    if a Parity error has been detected */
#define QSPI_CPU_INT_RIS_PER_CLR                 ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define QSPI_CPU_INT_RIS_PER_SET                 ((uint32_t)0x00000002U)         /* !< Interrupt occurred */
/* QSPI_CPU_INT_RIS[DMA_DONE_RX] Bits */
#define QSPI_CPU_INT_RIS_DMA_DONE_RX_OFS         (7)                             /* !< DMA_DONE_RX Offset */
#define QSPI_CPU_INT_RIS_DMA_DONE_RX_MASK        ((uint32_t)0x00000080U)         /* !< DMA Done 1 event for RX. This
                                                                                    interrupt is set if the RX DMA
                                                                                    channel sends the DONE signal. This
                                                                                    allows the handling of the DMA event
                                                                                    inside the mapped peripheral. */
#define QSPI_CPU_INT_RIS_DMA_DONE_RX_CLR         ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define QSPI_CPU_INT_RIS_DMA_DONE_RX_SET         ((uint32_t)0x00000080U)         /* !< Interrupt occurred */
/* QSPI_CPU_INT_RIS[RXFIFO_OVF] Bits */
#define QSPI_CPU_INT_RIS_RXFIFO_OVF_OFS          (0)                             /* !< RXFIFO_OVF Offset */
#define QSPI_CPU_INT_RIS_RXFIFO_OVF_MASK         ((uint32_t)0x00000001U)         /* !< RXFIFO overflow event. This
                                                                                    interrupt is set if an RX FIFO
                                                                                    overflow has been detected. */
#define QSPI_CPU_INT_RIS_RXFIFO_OVF_CLR          ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define QSPI_CPU_INT_RIS_RXFIFO_OVF_SET          ((uint32_t)0x00000001U)         /* !< Interrupt occurred */
/* QSPI_CPU_INT_RIS[DMA_DONE_TX] Bits */
#define QSPI_CPU_INT_RIS_DMA_DONE_TX_OFS         (8)                             /* !< DMA_DONE_TX Offset */
#define QSPI_CPU_INT_RIS_DMA_DONE_TX_MASK        ((uint32_t)0x00000100U)         /* !< DMA Done 1 event for TX. This
                                                                                    interrupt is set if the TX DMA
                                                                                    channel sends the DONE signal. This
                                                                                    allows the handling of the DMA event
                                                                                    inside the mapped peripheral. */
#define QSPI_CPU_INT_RIS_DMA_DONE_TX_CLR         ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define QSPI_CPU_INT_RIS_DMA_DONE_TX_SET         ((uint32_t)0x00000100U)         /* !< Interrupt occurred */
/* QSPI_CPU_INT_RIS[IDLE] Bits */
#define QSPI_CPU_INT_RIS_IDLE_OFS                (6)                             /* !< IDLE Offset */
#define QSPI_CPU_INT_RIS_IDLE_MASK               ((uint32_t)0x00000040U)         /* !< SPI has done finished transfers and
                                                                                    changed into IDLE mode. This bit is
                                                                                    set when BUSY goes low. */
#define QSPI_CPU_INT_RIS_IDLE_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define QSPI_CPU_INT_RIS_IDLE_SET                ((uint32_t)0x00000040U)         /* !< Interrupt occurred */
/* QSPI_CPU_INT_RIS[RTOUT] Bits */
#define QSPI_CPU_INT_RIS_RTOUT_OFS               (2)                             /* !< RTOUT Offset */
#define QSPI_CPU_INT_RIS_RTOUT_MASK              ((uint32_t)0x00000004U)         /* !< SPI Receive Time-Out event. */
#define QSPI_CPU_INT_RIS_RTOUT_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define QSPI_CPU_INT_RIS_RTOUT_SET               ((uint32_t)0x00000004U)         /* !< Interrupt occurred */
/* QSPI_CPU_INT_RIS[TXFIFO_UNF] Bits */
#define QSPI_CPU_INT_RIS_TXFIFO_UNF_OFS          (9)                             /* !< TXFIFO_UNF Offset */
#define QSPI_CPU_INT_RIS_TXFIFO_UNF_MASK         ((uint32_t)0x00000200U)         /* !< TX FIFO Underflow Interrupt */
#define QSPI_CPU_INT_RIS_TXFIFO_UNF_CLR          ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define QSPI_CPU_INT_RIS_TXFIFO_UNF_SET          ((uint32_t)0x00000200U)         /* !< Interrupt occurred */
/* QSPI_CPU_INT_RIS[RXFULL] Bits */
#define QSPI_CPU_INT_RIS_RXFULL_OFS              (10)                            /* !< RXFULL Offset */
#define QSPI_CPU_INT_RIS_RXFULL_MASK             ((uint32_t)0x00000400U)         /* !< RX FIFO Full Interrupt */
#define QSPI_CPU_INT_RIS_RXFULL_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define QSPI_CPU_INT_RIS_RXFULL_SET              ((uint32_t)0x00000400U)         /* !< Interrupt occurred */

/* QSPI_CPU_INT_MIS Bits */
/* QSPI_CPU_INT_MIS[RX] Bits */
#define QSPI_CPU_INT_MIS_RX_OFS                  (3)                             /* !< RX Offset */
#define QSPI_CPU_INT_MIS_RX_MASK                 ((uint32_t)0x00000008U)         /* !< Masked receive FIFO event.This
                                                                                    interrupt is set if the selected
                                                                                    Receive FIFO level has been reached */
#define QSPI_CPU_INT_MIS_RX_CLR                  ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define QSPI_CPU_INT_MIS_RX_SET                  ((uint32_t)0x00000008U)         /* !< Interrupt occurred */
/* QSPI_CPU_INT_MIS[TX] Bits */
#define QSPI_CPU_INT_MIS_TX_OFS                  (4)                             /* !< TX Offset */
#define QSPI_CPU_INT_MIS_TX_MASK                 ((uint32_t)0x00000010U)         /* !< Masked Transmit FIFO event. This
                                                                                    interrupt is set if the selected
                                                                                    Transmit FIFO level has been reached. */
#define QSPI_CPU_INT_MIS_TX_CLR                  ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define QSPI_CPU_INT_MIS_TX_SET                  ((uint32_t)0x00000010U)         /* !< Interrupt occurred */
/* QSPI_CPU_INT_MIS[TXEMPTY] Bits */
#define QSPI_CPU_INT_MIS_TXEMPTY_OFS             (5)                             /* !< TXEMPTY Offset */
#define QSPI_CPU_INT_MIS_TXEMPTY_MASK            ((uint32_t)0x00000020U)         /* !< Masked Transmit FIFO Empty event. */
#define QSPI_CPU_INT_MIS_TXEMPTY_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define QSPI_CPU_INT_MIS_TXEMPTY_SET             ((uint32_t)0x00000020U)         /* !< Interrupt occurred */
/* QSPI_CPU_INT_MIS[PER] Bits */
#define QSPI_CPU_INT_MIS_PER_OFS                 (1)                             /* !< PER Offset */
#define QSPI_CPU_INT_MIS_PER_MASK                ((uint32_t)0x00000002U)         /* !< Masked Parity error event: this bit
                                                                                    if a Parity error has been detected */
#define QSPI_CPU_INT_MIS_PER_CLR                 ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define QSPI_CPU_INT_MIS_PER_SET                 ((uint32_t)0x00000002U)         /* !< Interrupt occurred */
/* QSPI_CPU_INT_MIS[DMA_DONE_RX] Bits */
#define QSPI_CPU_INT_MIS_DMA_DONE_RX_OFS         (7)                             /* !< DMA_DONE_RX Offset */
#define QSPI_CPU_INT_MIS_DMA_DONE_RX_MASK        ((uint32_t)0x00000080U)         /* !< Masked DMA Done 1 event for RX. */
#define QSPI_CPU_INT_MIS_DMA_DONE_RX_CLR         ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define QSPI_CPU_INT_MIS_DMA_DONE_RX_SET         ((uint32_t)0x00000080U)         /* !< Interrupt occurred */
/* QSPI_CPU_INT_MIS[RXFIFO_OVF] Bits */
#define QSPI_CPU_INT_MIS_RXFIFO_OVF_OFS          (0)                             /* !< RXFIFO_OVF Offset */
#define QSPI_CPU_INT_MIS_RXFIFO_OVF_MASK         ((uint32_t)0x00000001U)         /* !< Masked RXFIFO overflow event. This
                                                                                    interrupt is set if an RX FIFO
                                                                                    overflow has been detected. */
#define QSPI_CPU_INT_MIS_RXFIFO_OVF_CLR          ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define QSPI_CPU_INT_MIS_RXFIFO_OVF_SET          ((uint32_t)0x00000001U)         /* !< Interrupt occurred */
/* QSPI_CPU_INT_MIS[DMA_DONE_TX] Bits */
#define QSPI_CPU_INT_MIS_DMA_DONE_TX_OFS         (8)                             /* !< DMA_DONE_TX Offset */
#define QSPI_CPU_INT_MIS_DMA_DONE_TX_MASK        ((uint32_t)0x00000100U)         /* !< Masked DMA Done 1 event for TX. */
#define QSPI_CPU_INT_MIS_DMA_DONE_TX_CLR         ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define QSPI_CPU_INT_MIS_DMA_DONE_TX_SET         ((uint32_t)0x00000100U)         /* !< Interrupt occurred */
/* QSPI_CPU_INT_MIS[IDLE] Bits */
#define QSPI_CPU_INT_MIS_IDLE_OFS                (6)                             /* !< IDLE Offset */
#define QSPI_CPU_INT_MIS_IDLE_MASK               ((uint32_t)0x00000040U)         /* !< Masked SPI IDLE mode event. */
#define QSPI_CPU_INT_MIS_IDLE_CLR                ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define QSPI_CPU_INT_MIS_IDLE_SET                ((uint32_t)0x00000040U)         /* !< Interrupt occurred */
/* QSPI_CPU_INT_MIS[RTOUT] Bits */
#define QSPI_CPU_INT_MIS_RTOUT_OFS               (2)                             /* !< RTOUT Offset */
#define QSPI_CPU_INT_MIS_RTOUT_MASK              ((uint32_t)0x00000004U)         /* !< Masked SPI Receive Time-Out
                                                                                    Interrupt. */
#define QSPI_CPU_INT_MIS_RTOUT_CLR               ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define QSPI_CPU_INT_MIS_RTOUT_SET               ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */
/* QSPI_CPU_INT_MIS[RXFULL] Bits */
#define QSPI_CPU_INT_MIS_RXFULL_OFS              (10)                            /* !< RXFULL Offset */
#define QSPI_CPU_INT_MIS_RXFULL_MASK             ((uint32_t)0x00000400U)         /* !< RX FIFO Full Interrupt */
#define QSPI_CPU_INT_MIS_RXFULL_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define QSPI_CPU_INT_MIS_RXFULL_SET              ((uint32_t)0x00000400U)         /* !< Interrupt occurred */
/* QSPI_CPU_INT_MIS[TXFIFO_UNF] Bits */
#define QSPI_CPU_INT_MIS_TXFIFO_UNF_OFS          (9)                             /* !< TXFIFO_UNF Offset */
#define QSPI_CPU_INT_MIS_TXFIFO_UNF_MASK         ((uint32_t)0x00000200U)         /* !< TX FIFO underflow interrupt */
#define QSPI_CPU_INT_MIS_TXFIFO_UNF_CLR          ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define QSPI_CPU_INT_MIS_TXFIFO_UNF_SET          ((uint32_t)0x00000200U)         /* !< Interrupt occurred */

/* QSPI_CPU_INT_ISET Bits */
/* QSPI_CPU_INT_ISET[RX] Bits */
#define QSPI_CPU_INT_ISET_RX_OFS                 (3)                             /* !< RX Offset */
#define QSPI_CPU_INT_ISET_RX_MASK                ((uint32_t)0x00000008U)         /* !< Set Receive FIFO event. */
#define QSPI_CPU_INT_ISET_RX_NO_EFFECT           ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define QSPI_CPU_INT_ISET_RX_SET                 ((uint32_t)0x00000008U)         /* !< Set Interrupt */
/* QSPI_CPU_INT_ISET[TX] Bits */
#define QSPI_CPU_INT_ISET_TX_OFS                 (4)                             /* !< TX Offset */
#define QSPI_CPU_INT_ISET_TX_MASK                ((uint32_t)0x00000010U)         /* !< Set Transmit FIFO event. */
#define QSPI_CPU_INT_ISET_TX_NO_EFFECT           ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define QSPI_CPU_INT_ISET_TX_SET                 ((uint32_t)0x00000010U)         /* !< Set Interrupt */
/* QSPI_CPU_INT_ISET[TXEMPTY] Bits */
#define QSPI_CPU_INT_ISET_TXEMPTY_OFS            (5)                             /* !< TXEMPTY Offset */
#define QSPI_CPU_INT_ISET_TXEMPTY_MASK           ((uint32_t)0x00000020U)         /* !< Set Transmit FIFO Empty event. */
#define QSPI_CPU_INT_ISET_TXEMPTY_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define QSPI_CPU_INT_ISET_TXEMPTY_SET            ((uint32_t)0x00000020U)         /* !< Set Interrupt */
/* QSPI_CPU_INT_ISET[PER] Bits */
#define QSPI_CPU_INT_ISET_PER_OFS                (1)                             /* !< PER Offset */
#define QSPI_CPU_INT_ISET_PER_MASK               ((uint32_t)0x00000002U)         /* !< Set Parity error event. */
#define QSPI_CPU_INT_ISET_PER_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define QSPI_CPU_INT_ISET_PER_SET                ((uint32_t)0x00000002U)         /* !< Set Interrupt */
/* QSPI_CPU_INT_ISET[DMA_DONE_RX] Bits */
#define QSPI_CPU_INT_ISET_DMA_DONE_RX_OFS        (7)                             /* !< DMA_DONE_RX Offset */
#define QSPI_CPU_INT_ISET_DMA_DONE_RX_MASK       ((uint32_t)0x00000080U)         /* !< Set DMA Done 1 event for RX. */
#define QSPI_CPU_INT_ISET_DMA_DONE_RX_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define QSPI_CPU_INT_ISET_DMA_DONE_RX_SET        ((uint32_t)0x00000080U)         /* !< Set Interrupt */
/* QSPI_CPU_INT_ISET[RXFIFO_OVF] Bits */
#define QSPI_CPU_INT_ISET_RXFIFO_OVF_OFS         (0)                             /* !< RXFIFO_OVF Offset */
#define QSPI_CPU_INT_ISET_RXFIFO_OVF_MASK        ((uint32_t)0x00000001U)         /* !< Set RXFIFO overflow event. */
#define QSPI_CPU_INT_ISET_RXFIFO_OVF_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define QSPI_CPU_INT_ISET_RXFIFO_OVF_SET         ((uint32_t)0x00000001U)         /* !< Set Interrupt */
/* QSPI_CPU_INT_ISET[DMA_DONE_TX] Bits */
#define QSPI_CPU_INT_ISET_DMA_DONE_TX_OFS        (8)                             /* !< DMA_DONE_TX Offset */
#define QSPI_CPU_INT_ISET_DMA_DONE_TX_MASK       ((uint32_t)0x00000100U)         /* !< Set DMA Done 1 event for TX. */
#define QSPI_CPU_INT_ISET_DMA_DONE_TX_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define QSPI_CPU_INT_ISET_DMA_DONE_TX_SET        ((uint32_t)0x00000100U)         /* !< Set Interrupt */
/* QSPI_CPU_INT_ISET[IDLE] Bits */
#define QSPI_CPU_INT_ISET_IDLE_OFS               (6)                             /* !< IDLE Offset */
#define QSPI_CPU_INT_ISET_IDLE_MASK              ((uint32_t)0x00000040U)         /* !< Set SPI IDLE mode event. */
#define QSPI_CPU_INT_ISET_IDLE_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define QSPI_CPU_INT_ISET_IDLE_SET               ((uint32_t)0x00000040U)         /* !< Set Interrupt */
/* QSPI_CPU_INT_ISET[RTOUT] Bits */
#define QSPI_CPU_INT_ISET_RTOUT_OFS              (2)                             /* !< RTOUT Offset */
#define QSPI_CPU_INT_ISET_RTOUT_MASK             ((uint32_t)0x00000004U)         /* !< Set SPI Receive Time-Out Event. */
#define QSPI_CPU_INT_ISET_RTOUT_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define QSPI_CPU_INT_ISET_RTOUT_SET              ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */
/* QSPI_CPU_INT_ISET[TXFIFO_UNF] Bits */
#define QSPI_CPU_INT_ISET_TXFIFO_UNF_OFS         (9)                             /* !< TXFIFO_UNF Offset */
#define QSPI_CPU_INT_ISET_TXFIFO_UNF_MASK        ((uint32_t)0x00000200U)         /* !< Set TX FIFO Underflow Event */
#define QSPI_CPU_INT_ISET_TXFIFO_UNF_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing has no effect */
#define QSPI_CPU_INT_ISET_TXFIFO_UNF_SET         ((uint32_t)0x00000200U)         /* !< Set interrupt */
/* QSPI_CPU_INT_ISET[RXFULL] Bits */
#define QSPI_CPU_INT_ISET_RXFULL_OFS             (10)                            /* !< RXFULL Offset */
#define QSPI_CPU_INT_ISET_RXFULL_MASK            ((uint32_t)0x00000400U)         /* !< Set RX FIFO Full Event */
#define QSPI_CPU_INT_ISET_RXFULL_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing has no effect */
#define QSPI_CPU_INT_ISET_RXFULL_SET             ((uint32_t)0x00000400U)         /* !< Set Interrupt */

/* QSPI_CPU_INT_ICLR Bits */
/* QSPI_CPU_INT_ICLR[RX] Bits */
#define QSPI_CPU_INT_ICLR_RX_OFS                 (3)                             /* !< RX Offset */
#define QSPI_CPU_INT_ICLR_RX_MASK                ((uint32_t)0x00000008U)         /* !< Clear Receive FIFO event. */
#define QSPI_CPU_INT_ICLR_RX_NO_EFFECT           ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define QSPI_CPU_INT_ICLR_RX_CLR                 ((uint32_t)0x00000008U)         /* !< Clear Interrupt */
/* QSPI_CPU_INT_ICLR[TX] Bits */
#define QSPI_CPU_INT_ICLR_TX_OFS                 (4)                             /* !< TX Offset */
#define QSPI_CPU_INT_ICLR_TX_MASK                ((uint32_t)0x00000010U)         /* !< Clear Transmit FIFO event. */
#define QSPI_CPU_INT_ICLR_TX_NO_EFFECT           ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define QSPI_CPU_INT_ICLR_TX_CLR                 ((uint32_t)0x00000010U)         /* !< Clear Interrupt */
/* QSPI_CPU_INT_ICLR[TXEMPTY] Bits */
#define QSPI_CPU_INT_ICLR_TXEMPTY_OFS            (5)                             /* !< TXEMPTY Offset */
#define QSPI_CPU_INT_ICLR_TXEMPTY_MASK           ((uint32_t)0x00000020U)         /* !< Clear Transmit FIFO Empty event. */
#define QSPI_CPU_INT_ICLR_TXEMPTY_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define QSPI_CPU_INT_ICLR_TXEMPTY_CLR            ((uint32_t)0x00000020U)         /* !< Clear Interrupt */
/* QSPI_CPU_INT_ICLR[PER] Bits */
#define QSPI_CPU_INT_ICLR_PER_OFS                (1)                             /* !< PER Offset */
#define QSPI_CPU_INT_ICLR_PER_MASK               ((uint32_t)0x00000002U)         /* !< Clear Parity error event. */
#define QSPI_CPU_INT_ICLR_PER_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define QSPI_CPU_INT_ICLR_PER_CLR                ((uint32_t)0x00000002U)         /* !< Clear Interrupt */
/* QSPI_CPU_INT_ICLR[DMA_DONE_RX] Bits */
#define QSPI_CPU_INT_ICLR_DMA_DONE_RX_OFS        (7)                             /* !< DMA_DONE_RX Offset */
#define QSPI_CPU_INT_ICLR_DMA_DONE_RX_MASK       ((uint32_t)0x00000080U)         /* !< Clear DMA Done 1 event for RX. */
#define QSPI_CPU_INT_ICLR_DMA_DONE_RX_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define QSPI_CPU_INT_ICLR_DMA_DONE_RX_CLR        ((uint32_t)0x00000080U)         /* !< Clear Interrupt */
/* QSPI_CPU_INT_ICLR[RXFIFO_OVF] Bits */
#define QSPI_CPU_INT_ICLR_RXFIFO_OVF_OFS         (0)                             /* !< RXFIFO_OVF Offset */
#define QSPI_CPU_INT_ICLR_RXFIFO_OVF_MASK        ((uint32_t)0x00000001U)         /* !< Clear RXFIFO overflow event. */
#define QSPI_CPU_INT_ICLR_RXFIFO_OVF_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define QSPI_CPU_INT_ICLR_RXFIFO_OVF_CLR         ((uint32_t)0x00000001U)         /* !< Clear Interrupt */
/* QSPI_CPU_INT_ICLR[DMA_DONE_TX] Bits */
#define QSPI_CPU_INT_ICLR_DMA_DONE_TX_OFS        (8)                             /* !< DMA_DONE_TX Offset */
#define QSPI_CPU_INT_ICLR_DMA_DONE_TX_MASK       ((uint32_t)0x00000100U)         /* !< Clear DMA Done 1 event for TX. */
#define QSPI_CPU_INT_ICLR_DMA_DONE_TX_NO_EFFECT  ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define QSPI_CPU_INT_ICLR_DMA_DONE_TX_CLR        ((uint32_t)0x00000100U)         /* !< Clear Interrupt */
/* QSPI_CPU_INT_ICLR[IDLE] Bits */
#define QSPI_CPU_INT_ICLR_IDLE_OFS               (6)                             /* !< IDLE Offset */
#define QSPI_CPU_INT_ICLR_IDLE_MASK              ((uint32_t)0x00000040U)         /* !< Clear SPI IDLE mode event. */
#define QSPI_CPU_INT_ICLR_IDLE_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define QSPI_CPU_INT_ICLR_IDLE_CLR               ((uint32_t)0x00000040U)         /* !< Clear Interrupt */
/* QSPI_CPU_INT_ICLR[RTOUT] Bits */
#define QSPI_CPU_INT_ICLR_RTOUT_OFS              (2)                             /* !< RTOUT Offset */
#define QSPI_CPU_INT_ICLR_RTOUT_MASK             ((uint32_t)0x00000004U)         /* !< Clear SPI Receive Time-Out Event. */
#define QSPI_CPU_INT_ICLR_RTOUT_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define QSPI_CPU_INT_ICLR_RTOUT_CLR              ((uint32_t)0x00000004U)         /* !< Set Interrupt Mask */
/* QSPI_CPU_INT_ICLR[TXFIFO_UNF] Bits */
#define QSPI_CPU_INT_ICLR_TXFIFO_UNF_OFS         (9)                             /* !< TXFIFO_UNF Offset */
#define QSPI_CPU_INT_ICLR_TXFIFO_UNF_MASK        ((uint32_t)0x00000200U)         /* !< Clear TXFIFO underflow event */
#define QSPI_CPU_INT_ICLR_TXFIFO_UNF_NO_EFFECT   ((uint32_t)0x00000000U)         /* !< Writing has no effect */
#define QSPI_CPU_INT_ICLR_TXFIFO_UNF_CLR         ((uint32_t)0x00000200U)         /* !< Clear interrupt */
/* QSPI_CPU_INT_ICLR[RXFULL] Bits */
#define QSPI_CPU_INT_ICLR_RXFULL_OFS             (10)                            /* !< RXFULL Offset */
#define QSPI_CPU_INT_ICLR_RXFULL_MASK            ((uint32_t)0x00000400U)         /* !< Clear RX FIFO underflow event */
#define QSPI_CPU_INT_ICLR_RXFULL_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing has no effect */
#define QSPI_CPU_INT_ICLR_RXFULL_CLR             ((uint32_t)0x00000400U)         /* !< Clear interrupt */

/* QSPI_PWREN Bits */
/* QSPI_PWREN[ENABLE] Bits */
#define QSPI_PWREN_ENABLE_OFS                    (0)                             /* !< ENABLE Offset */
#define QSPI_PWREN_ENABLE_MASK                   ((uint32_t)0x00000001U)         /* !< Enable the power */
#define QSPI_PWREN_ENABLE_DISABLE                ((uint32_t)0x00000000U)         /* !< Disable Power */
#define QSPI_PWREN_ENABLE_ENABLE                 ((uint32_t)0x00000001U)         /* !< Enable Power */
/* QSPI_PWREN[KEY] Bits */
#define QSPI_PWREN_KEY_OFS                       (24)                            /* !< KEY Offset */
#define QSPI_PWREN_KEY_MASK                      ((uint32_t)0xFF000000U)         /* !< KEY to allow Power State Change */
#define QSPI_PWREN_KEY_UNLOCK_W                  ((uint32_t)0x26000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* QSPI_RSTCTL Bits */
/* QSPI_RSTCTL[RESETSTKYCLR] Bits */
#define QSPI_RSTCTL_RESETSTKYCLR_OFS             (1)                             /* !< RESETSTKYCLR Offset */
#define QSPI_RSTCTL_RESETSTKYCLR_MASK            ((uint32_t)0x00000002U)         /* !< Clear the RESETSTKY bit in the STAT
                                                                                    register */
#define QSPI_RSTCTL_RESETSTKYCLR_NOP             ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define QSPI_RSTCTL_RESETSTKYCLR_CLR             ((uint32_t)0x00000002U)         /* !< Clear reset sticky bit */
/* QSPI_RSTCTL[RESETASSERT] Bits */
#define QSPI_RSTCTL_RESETASSERT_OFS              (0)                             /* !< RESETASSERT Offset */
#define QSPI_RSTCTL_RESETASSERT_MASK             ((uint32_t)0x00000001U)         /* !< Assert reset to the peripheral */
#define QSPI_RSTCTL_RESETASSERT_NOP              ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define QSPI_RSTCTL_RESETASSERT_ASSERT           ((uint32_t)0x00000001U)         /* !< Assert reset */
/* QSPI_RSTCTL[KEY] Bits */
#define QSPI_RSTCTL_KEY_OFS                      (24)                            /* !< KEY Offset */
#define QSPI_RSTCTL_KEY_MASK                     ((uint32_t)0xFF000000U)         /* !< Unlock key */
#define QSPI_RSTCTL_KEY_UNLOCK_W                 ((uint32_t)0xB1000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* QSPI_CLKCFG Bits */
/* QSPI_CLKCFG[KEY] Bits */
#define QSPI_CLKCFG_KEY_OFS                      (24)                            /* !< KEY Offset */
#define QSPI_CLKCFG_KEY_MASK                     ((uint32_t)0xFF000000U)         /* !< KEY to Allow State Change -- 0xA9 */
#define QSPI_CLKCFG_KEY_UNLOCK                   ((uint32_t)0xA9000000U)         /* !< key value to allow change field of
                                                                                    GPRCM */
/* QSPI_CLKCFG[BLOCKASYNC] Bits */
#define QSPI_CLKCFG_BLOCKASYNC_OFS               (8)                             /* !< BLOCKASYNC Offset */
#define QSPI_CLKCFG_BLOCKASYNC_MASK              ((uint32_t)0x00000100U)         /* !< Async Clock Request is blocked from
                                                                                    starting SYSOSC or forcing bus clock
                                                                                    to 32MHz */
#define QSPI_CLKCFG_BLOCKASYNC_DISABLE           ((uint32_t)0x00000000U)         /* !< Not block async clock request */
#define QSPI_CLKCFG_BLOCKASYNC_ENABLE            ((uint32_t)0x00000100U)         /* !< Block async clock request */

/* QSPI_GPRCM_STAT Bits */
/* QSPI_GPRCM_STAT[RESETSTKY] Bits */
#define QSPI_GPRCM_STAT_RESETSTKY_OFS            (16)                            /* !< RESETSTKY Offset */
#define QSPI_GPRCM_STAT_RESETSTKY_MASK           ((uint32_t)0x00010000U)         /* !< This bit indicates, if the
                                                                                    peripheral was reset, since this bit
                                                                                    was cleared by RESETSTKYCLR in the
                                                                                    RSTCTL register */
#define QSPI_GPRCM_STAT_RESETSTKY_NORES          ((uint32_t)0x00000000U)         /* !< The peripheral has not been reset
                                                                                    since this bit was last cleared by
                                                                                    RESETSTKYCLR in the RSTCTL register */
#define QSPI_GPRCM_STAT_RESETSTKY_RESET          ((uint32_t)0x00010000U)         /* !< The peripheral was reset since the
                                                                                    last bit clear */

/* QSPI_CLKDIV Bits */
/* QSPI_CLKDIV[RATIO] Bits */
#define QSPI_CLKDIV_RATIO_OFS                    (0)                             /* !< RATIO Offset */
#define QSPI_CLKDIV_RATIO_MASK                   ((uint32_t)0x00000007U)         /* !< Selects divide ratio of module
                                                                                    clock */
#define QSPI_CLKDIV_RATIO_DIV_BY_1               ((uint32_t)0x00000000U)         /* !< Do not divide clock source */
#define QSPI_CLKDIV_RATIO_DIV_BY_2               ((uint32_t)0x00000001U)         /* !< Divide clock source by 2 */
#define QSPI_CLKDIV_RATIO_DIV_BY_3               ((uint32_t)0x00000002U)         /* !< Divide clock source by 3 */
#define QSPI_CLKDIV_RATIO_DIV_BY_4               ((uint32_t)0x00000003U)         /* !< Divide clock source by 4 */
#define QSPI_CLKDIV_RATIO_DIV_BY_5               ((uint32_t)0x00000004U)         /* !< Divide clock source by 5 */
#define QSPI_CLKDIV_RATIO_DIV_BY_6               ((uint32_t)0x00000005U)         /* !< Divide clock source by 6 */
#define QSPI_CLKDIV_RATIO_DIV_BY_7               ((uint32_t)0x00000006U)         /* !< Divide clock source by 7 */
#define QSPI_CLKDIV_RATIO_DIV_BY_8               ((uint32_t)0x00000007U)         /* !< Divide clock source by 8 */

/* QSPI_CLKSEL Bits */
/* QSPI_CLKSEL[LFCLK_SEL] Bits */
#define QSPI_CLKSEL_LFCLK_SEL_OFS                (1)                             /* !< LFCLK_SEL Offset */
#define QSPI_CLKSEL_LFCLK_SEL_MASK               ((uint32_t)0x00000002U)         /* !< Selects LFCLK as clock source if
                                                                                    enabled */
#define QSPI_CLKSEL_LFCLK_SEL_DISABLE            ((uint32_t)0x00000000U)         /* !< Does not select this clock as a
                                                                                    source */
#define QSPI_CLKSEL_LFCLK_SEL_ENABLE             ((uint32_t)0x00000002U)         /* !< Select this clock as a source */
/* QSPI_CLKSEL[MFCLK_SEL] Bits */
#define QSPI_CLKSEL_MFCLK_SEL_OFS                (2)                             /* !< MFCLK_SEL Offset */
#define QSPI_CLKSEL_MFCLK_SEL_MASK               ((uint32_t)0x00000004U)         /* !< Selects MFCLK as clock source if
                                                                                    enabled */
#define QSPI_CLKSEL_MFCLK_SEL_DISABLE            ((uint32_t)0x00000000U)         /* !< Does not select this clock as a
                                                                                    source */
#define QSPI_CLKSEL_MFCLK_SEL_ENABLE             ((uint32_t)0x00000004U)         /* !< Select this clock as a source */
/* QSPI_CLKSEL[SYSCLK_SEL] Bits */
#define QSPI_CLKSEL_SYSCLK_SEL_OFS               (3)                             /* !< SYSCLK_SEL Offset */
#define QSPI_CLKSEL_SYSCLK_SEL_MASK              ((uint32_t)0x00000008U)         /* !< Selects SYSCLK as clock source if
                                                                                    enabled */
#define QSPI_CLKSEL_SYSCLK_SEL_DISABLE           ((uint32_t)0x00000000U)         /* !< Does not select this clock as a
                                                                                    source */
#define QSPI_CLKSEL_SYSCLK_SEL_ENABLE            ((uint32_t)0x00000008U)         /* !< Select this clock as a source */

/* QSPI_PDBGCTL Bits */
/* QSPI_PDBGCTL[FREE] Bits */
#define QSPI_PDBGCTL_FREE_OFS                    (0)                             /* !< FREE Offset */
#define QSPI_PDBGCTL_FREE_MASK                   ((uint32_t)0x00000001U)         /* !< Free run control */
#define QSPI_PDBGCTL_FREE_STOP                   ((uint32_t)0x00000000U)         /* !< The peripheral freezes
                                                                                    functionality while the Core Halted
                                                                                    input is asserted and resumes when it
                                                                                    is deasserted. */
#define QSPI_PDBGCTL_FREE_RUN                    ((uint32_t)0x00000001U)         /* !< The peripheral ignores the state of
                                                                                    the Core Halted input */
/* QSPI_PDBGCTL[SOFT] Bits */
#define QSPI_PDBGCTL_SOFT_OFS                    (1)                             /* !< SOFT Offset */
#define QSPI_PDBGCTL_SOFT_MASK                   ((uint32_t)0x00000002U)         /* !< Soft halt boundary control. This
                                                                                    function is only available, if [FREE]
                                                                                    is set to 'STOP' */
#define QSPI_PDBGCTL_SOFT_IMMEDIATE              ((uint32_t)0x00000000U)         /* !< The peripheral will halt
                                                                                    immediately, even if the resultant
                                                                                    state will result in corruption if
                                                                                    the system is restarted */
#define QSPI_PDBGCTL_SOFT_DELAYED                ((uint32_t)0x00000002U)         /* !< The peripheral blocks the debug
                                                                                    freeze until it has reached a
                                                                                    boundary where it can resume without
                                                                                    corruption */

/* QSPI_EVT_MODE Bits */
/* QSPI_EVT_MODE[INT0_CFG] Bits */
#define QSPI_EVT_MODE_INT0_CFG_OFS               (0)                             /* !< INT0_CFG Offset */
#define QSPI_EVT_MODE_INT0_CFG_MASK              ((uint32_t)0x00000003U)         /* !< Event line mode select for event
                                                                                    corresponding to
                                                                                    [IPSTANDARD.INT_EVENT0] */
#define QSPI_EVT_MODE_INT0_CFG_DISABLE           ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define QSPI_EVT_MODE_INT0_CFG_SOFTWARE          ((uint32_t)0x00000001U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define QSPI_EVT_MODE_INT0_CFG_HARDWARE          ((uint32_t)0x00000002U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */
/* QSPI_EVT_MODE[INT1_CFG] Bits */
#define QSPI_EVT_MODE_INT1_CFG_OFS               (2)                             /* !< INT1_CFG Offset */
#define QSPI_EVT_MODE_INT1_CFG_MASK              ((uint32_t)0x0000000CU)         /* !< Event line mode select for event
                                                                                    corresponding to
                                                                                    [IPSTANDARD.INT_EVENT1] */
#define QSPI_EVT_MODE_INT1_CFG_DISABLE           ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define QSPI_EVT_MODE_INT1_CFG_SOFTWARE          ((uint32_t)0x00000004U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define QSPI_EVT_MODE_INT1_CFG_HARDWARE          ((uint32_t)0x00000008U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */
/* QSPI_EVT_MODE[INT2_CFG] Bits */
#define QSPI_EVT_MODE_INT2_CFG_OFS               (4)                             /* !< INT2_CFG Offset */
#define QSPI_EVT_MODE_INT2_CFG_MASK              ((uint32_t)0x00000030U)         /* !< Event line mode select for event
                                                                                    corresponding to
                                                                                    [IPSTANDARD.INT_EVENT2] */
#define QSPI_EVT_MODE_INT2_CFG_DISABLE           ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define QSPI_EVT_MODE_INT2_CFG_SOFTWARE          ((uint32_t)0x00000010U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define QSPI_EVT_MODE_INT2_CFG_HARDWARE          ((uint32_t)0x00000020U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */

/* QSPI_INTCTL Bits */
/* QSPI_INTCTL[INTEVAL] Bits */
#define QSPI_INTCTL_INTEVAL_OFS                  (0)                             /* !< INTEVAL Offset */
#define QSPI_INTCTL_INTEVAL_MASK                 ((uint32_t)0x00000001U)         /* !< Writing a 1 to this field
                                                                                    re-evaluates the interrupt sources. */
#define QSPI_INTCTL_INTEVAL_DISABLE              ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define QSPI_INTCTL_INTEVAL_EVAL                 ((uint32_t)0x00000001U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */

/* QSPI_CTL0 Bits */
/* QSPI_CTL0[DSS] Bits */
#define QSPI_CTL0_DSS_OFS                        (0)                             /* !< DSS Offset */
#define QSPI_CTL0_DSS_MASK                       ((uint32_t)0x0000001FU)         /* !< Data Size Select. Values 0 - 2 are
                                                                                    reserved and shall not be used. 3h =
                                                                                    4_BIT : 4-bit data SPI allows only
                                                                                    values up to 16 Bit */
#define QSPI_CTL0_DSS_DSS_4                      ((uint32_t)0x00000003U)         /* !< Data Size Select bits: 4 */
#define QSPI_CTL0_DSS_DSS_5                      ((uint32_t)0x00000004U)         /* !< Data Size Select bits: 5 */
#define QSPI_CTL0_DSS_DSS_6                      ((uint32_t)0x00000005U)         /* !< Data Size Select bits: 6 */
#define QSPI_CTL0_DSS_DSS_7                      ((uint32_t)0x00000006U)         /* !< Data Size Select bits: 7 */
#define QSPI_CTL0_DSS_DSS_8                      ((uint32_t)0x00000007U)         /* !< Data Size Select bits: 8 */
#define QSPI_CTL0_DSS_DSS_9                      ((uint32_t)0x00000008U)         /* !< Data Size Select bits: 9 */
#define QSPI_CTL0_DSS_DSS_10                     ((uint32_t)0x00000009U)         /* !< Data Size Select bits: 10 */
#define QSPI_CTL0_DSS_DSS_11                     ((uint32_t)0x0000000AU)         /* !< Data Size Select bits: 11 */
#define QSPI_CTL0_DSS_DSS_12                     ((uint32_t)0x0000000BU)         /* !< Data Size Select bits: 12 */
#define QSPI_CTL0_DSS_DSS_13                     ((uint32_t)0x0000000CU)         /* !< Data Size Select bits: 13 */
#define QSPI_CTL0_DSS_DSS_14                     ((uint32_t)0x0000000DU)         /* !< Data Size Select bits: 14 */
#define QSPI_CTL0_DSS_DSS_15                     ((uint32_t)0x0000000EU)         /* !< Data Size Select bits: 15 */
#define QSPI_CTL0_DSS_DSS_16                     ((uint32_t)0x0000000FU)         /* !< Data Size Select bits: 16 */
/* QSPI_CTL0[FRF] Bits */
#define QSPI_CTL0_FRF_OFS                        (5)                             /* !< FRF Offset */
#define QSPI_CTL0_FRF_MASK                       ((uint32_t)0x00000060U)         /* !< Frame format Select */
#define QSPI_CTL0_FRF_MOTOROLA_3WIRE             ((uint32_t)0x00000000U)         /* !< Motorola SPI frame format (3 wire
                                                                                    mode) */
#define QSPI_CTL0_FRF_MOTOROLA_4WIRE             ((uint32_t)0x00000020U)         /* !< Motorola SPI frame format (4 wire
                                                                                    mode) */
#define QSPI_CTL0_FRF_TI_SYNC                    ((uint32_t)0x00000040U)         /* !< TI synchronous serial frame format */
#define QSPI_CTL0_FRF_MIRCOWIRE                  ((uint32_t)0x00000060U)         /* !< National Microwire frame format */
/* QSPI_CTL0[SPO] Bits */
#define QSPI_CTL0_SPO_OFS                        (8)                             /* !< SPO Offset */
#define QSPI_CTL0_SPO_MASK                       ((uint32_t)0x00000100U)         /* !< CLKOUT polarity (Motorola SPI frame
                                                                                    format only) */
#define QSPI_CTL0_SPO_LOW                        ((uint32_t)0x00000000U)         /* !< SPI produces a steady state LOW
                                                                                    value on the CLKOUT */
#define QSPI_CTL0_SPO_HIGH                       ((uint32_t)0x00000100U)         /* !< SPI produces a steady state HIGH
                                                                                    value on the CLKOUT */
/* QSPI_CTL0[SPH] Bits */
#define QSPI_CTL0_SPH_OFS                        (9)                             /* !< SPH Offset */
#define QSPI_CTL0_SPH_MASK                       ((uint32_t)0x00000200U)         /* !< CLKOUT phase (Motorola SPI frame
                                                                                    format only) This bit selects the
                                                                                    clock edge that captures data and
                                                                                    enables it to change state. It has
                                                                                    the most impact on the first bit
                                                                                    transmitted by either permitting or
                                                                                    not permitting a clock transition
                                                                                    before the first data capture edge. */
#define QSPI_CTL0_SPH_FIRST                      ((uint32_t)0x00000000U)         /* !< Data is captured on the first clock
                                                                                    edge transition. */
#define QSPI_CTL0_SPH_SECOND                     ((uint32_t)0x00000200U)         /* !< Data is captured on the second
                                                                                    clock edge transition. */
/* QSPI_CTL0[CSSEL] Bits */
#define QSPI_CTL0_CSSEL_OFS                      (12)                            /* !< CSSEL Offset */
#define QSPI_CTL0_CSSEL_MASK                     ((uint32_t)0x00003000U)         /* !< Select the CS line to control on
                                                                                    data transfer This bit is applicable
                                                                                    for both controller/target mode */
#define QSPI_CTL0_CSSEL_CSSEL_0                  ((uint32_t)0x00000000U)         /* !< CS line select: 0 */
#define QSPI_CTL0_CSSEL_CSSEL_1                  ((uint32_t)0x00001000U)         /* !< CS line select: 1 */
#define QSPI_CTL0_CSSEL_CSSEL_2                  ((uint32_t)0x00002000U)         /* !< CS line select: 2 */
#define QSPI_CTL0_CSSEL_CSSEL_3                  ((uint32_t)0x00003000U)         /* !< CS line select: 3 */
/* QSPI_CTL0[CSCLR] Bits */
#define QSPI_CTL0_CSCLR_OFS                      (14)                            /* !< CSCLR Offset */
#define QSPI_CTL0_CSCLR_MASK                     ((uint32_t)0x00004000U)         /* !< Clear shift register counter on CS
                                                                                    inactive This bit is relevant only in
                                                                                    the peripheral, CTL1.CP=0. */
#define QSPI_CTL0_CSCLR_DISABLE                  ((uint32_t)0x00000000U)         /* !< Disable automatic clear of shift
                                                                                    register when CS goes to disable. */
#define QSPI_CTL0_CSCLR_ENABLE                   ((uint32_t)0x00004000U)         /* !< Enable automatic clear of shift
                                                                                    register when CS goes to disable. */
/* QSPI_CTL0[PACKEN] Bits */
#define QSPI_CTL0_PACKEN_OFS                     (7)                             /* !< PACKEN Offset */
#define QSPI_CTL0_PACKEN_MASK                    ((uint32_t)0x00000080U)         /* !< Packing Enable. When 1, packing
                                                                                    feature is enabled inside the IP When
                                                                                    0, packing feature is disabled inside
                                                                                    the IP */
#define QSPI_CTL0_PACKEN_DISABLED                ((uint32_t)0x00000000U)         /* !< Packing feature disabled */
#define QSPI_CTL0_PACKEN_ENABLED                 ((uint32_t)0x00000080U)         /* !< Packing feature enabled */

/* QSPI_CTL1 Bits */
/* QSPI_CTL1[LBM] Bits */
#define QSPI_CTL1_LBM_OFS                        (1)                             /* !< LBM Offset */
#define QSPI_CTL1_LBM_MASK                       ((uint32_t)0x00000002U)         /* !< Loop back mode */
#define QSPI_CTL1_LBM_DISABLE                    ((uint32_t)0x00000000U)         /* !< Disable loopback mode */
#define QSPI_CTL1_LBM_ENABLE                     ((uint32_t)0x00000002U)         /* !< Enable loopback mode */
/* QSPI_CTL1[CP] Bits */
#define QSPI_CTL1_CP_OFS                         (2)                             /* !< CP Offset */
#define QSPI_CTL1_CP_MASK                        ((uint32_t)0x00000004U)         /* !< Controller or peripheral mode
                                                                                    select. This bit can be modified only
                                                                                    when SPI is disabled, CTL1.ENABLE=0. */
#define QSPI_CTL1_CP_DISABLE                     ((uint32_t)0x00000000U)         /* !< Select Peripheral mode */
#define QSPI_CTL1_CP_ENABLE                      ((uint32_t)0x00000004U)         /* !< Select Controller Mode */
/* QSPI_CTL1[POD] Bits */
#define QSPI_CTL1_POD_OFS                        (3)                             /* !< POD Offset */
#define QSPI_CTL1_POD_MASK                       ((uint32_t)0x00000008U)         /* !< Peripheral-mode: Data output
                                                                                    disabled This bit is relevant only in
                                                                                    Peripheral mode. In
                                                                                    multiple-peripheral system
                                                                                    topologies, SPI controller can
                                                                                    broadcast a message to all
                                                                                    peripherals, while only one
                                                                                    peripheral drives the line.  POD can
                                                                                    be used by the SPI peripheral to
                                                                                    disable driving data on the line. */
#define QSPI_CTL1_POD_DISABLE                    ((uint32_t)0x00000000U)         /* !< SPI can drive the MISO output in
                                                                                    peripheral mode. */
#define QSPI_CTL1_POD_ENABLE                     ((uint32_t)0x00000008U)         /* !< SPI cannot drive the MISO output in
                                                                                    peripheral mode. */
/* QSPI_CTL1[MSB] Bits */
#define QSPI_CTL1_MSB_OFS                        (4)                             /* !< MSB Offset */
#define QSPI_CTL1_MSB_MASK                       ((uint32_t)0x00000010U)         /* !< MSB first select. Controls the
                                                                                    direction of the receive and transmit
                                                                                    shift register. */
#define QSPI_CTL1_MSB_DISABLE                    ((uint32_t)0x00000000U)         /* !< LSB first */
#define QSPI_CTL1_MSB_ENABLE                     ((uint32_t)0x00000010U)         /* !< MSB first */
/* QSPI_CTL1[PREN] Bits */
#define QSPI_CTL1_PREN_OFS                       (5)                             /* !< PREN Offset */
#define QSPI_CTL1_PREN_MASK                      ((uint32_t)0x00000020U)         /* !< Parity receive enable If enabled,
                                                                                    parity reception check will be done
                                                                                    for both controller and peripheral
                                                                                    modes In case of a parity miss-match
                                                                                    the parity error flag RIS.PER will be
                                                                                    set. */
#define QSPI_CTL1_PREN_DISABLE                   ((uint32_t)0x00000000U)         /* !< Disable Parity receive function */
#define QSPI_CTL1_PREN_ENABLE                    ((uint32_t)0x00000020U)         /* !< Enable Parity receive function */
/* QSPI_CTL1[REPEATTX] Bits */
#define QSPI_CTL1_REPEATTX_OFS                   (16)                            /* !< REPEATTX Offset */
#define QSPI_CTL1_REPEATTX_MASK                  ((uint32_t)0x00FF0000U)         /* !< Counter to repeat last transfer 0:
                                                                                    repeat last transfer is disabled. x:
                                                                                    repeat the last transfer with the
                                                                                    given number. The transfer will be
                                                                                    started with writing a data into the
                                                                                    TX Buffer. Sending the data will be
                                                                                    repeated with the given value, so the
                                                                                    data will be transferred X+1 times in
                                                                                    total. The behavior is identical as
                                                                                    if the data would be written into the
                                                                                    TX Buffer that many times as defined
                                                                                    by the value here. It can be used to
                                                                                    clean a transfer or to pull a certain
                                                                                    amount of data by a peripheral. */
#define QSPI_CTL1_REPEATTX_DISABLE               ((uint32_t)0x00000000U)         /* !< REPEATTX disable */
#define QSPI_CTL1_REPEATTX_MINIMUM               ((uint32_t)0x00000000U)         /* !< Smallest value */
#define QSPI_CTL1_REPEATTX_MAXIMUM               ((uint32_t)0x00FF0000U)         /* !< Highest possible value */
/* QSPI_CTL1[PES] Bits */
#define QSPI_CTL1_PES_OFS                        (6)                             /* !< PES Offset */
#define QSPI_CTL1_PES_MASK                       ((uint32_t)0x00000040U)         /* !< Even Parity Select */
#define QSPI_CTL1_PES_DISABLE                    ((uint32_t)0x00000000U)         /* !< Odd Parity mode */
#define QSPI_CTL1_PES_ENABLE                     ((uint32_t)0x00000040U)         /* !< Even Parity mode */
/* QSPI_CTL1[CDMODE] Bits */
#define QSPI_CTL1_CDMODE_OFS                     (12)                            /* !< CDMODE Offset */
#define QSPI_CTL1_CDMODE_MASK                    ((uint32_t)0x0000F000U)         /* !< Command/Data Mode Value  When
                                                                                    CTL1.CDENABLE is 1, CS3 line is used
                                                                                    as C/D signal to distinguish between
                                                                                    Command (C/D low) and Data (C/D high)
                                                                                    information.  When a value is written
                                                                                    into the CTL1.CDMODE bits, the C/D
                                                                                    (CS3) line will go low for the given
                                                                                    numbers of byte which are sent by the
                                                                                    SPI, starting with the next value to
                                                                                    be transmitted after which, C/D line
                                                                                    will go high automatically  0: Manual
                                                                                    mode with C/D signal as High 1-14:
                                                                                    C/D is low while this number of bytes
                                                                                    are being sent after which, this
                                                                                    field sets to 0 and C/D goes high.
                                                                                    Reading this field at any time
                                                                                    returns the remaining number of
                                                                                    command bytes. 15: Manual mode with
                                                                                    C/D signal as Low. */
#define QSPI_CTL1_CDMODE_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Smallest value */
#define QSPI_CTL1_CDMODE_DATA                    ((uint32_t)0x00000000U)         /* !< Manual mode: Data */
#define QSPI_CTL1_CDMODE_MAXIMUM                 ((uint32_t)0x0000F000U)         /* !< Highest possible value */
#define QSPI_CTL1_CDMODE_COMMAND                 ((uint32_t)0x0000F000U)         /* !< Manual mode: Command */
/* QSPI_CTL1[ENABLE] Bits */
#define QSPI_CTL1_ENABLE_OFS                     (0)                             /* !< ENABLE Offset */
#define QSPI_CTL1_ENABLE_MASK                    ((uint32_t)0x00000001U)         /* !< SPI enable */
#define QSPI_CTL1_ENABLE_DISABLE                 ((uint32_t)0x00000000U)         /* !< Disable module function */
#define QSPI_CTL1_ENABLE_ENABLE                  ((uint32_t)0x00000001U)         /* !< Enable module function */
/* QSPI_CTL1[RXTIMEOUT] Bits */
#define QSPI_CTL1_RXTIMEOUT_OFS                  (24)                            /* !< RXTIMEOUT Offset */
#define QSPI_CTL1_RXTIMEOUT_MASK                 ((uint32_t)0x3F000000U)         /* !< Receive Timeout (only for
                                                                                    Peripheral mode) Defines the number
                                                                                    of Clock Cycles before after which
                                                                                    the Receive Timeout flag RTOUT is
                                                                                    set. The time is calculated using the
                                                                                    control register for the clock
                                                                                    selection and divider in the
                                                                                    Controller mode configuration. A
                                                                                    value of 0 disables this function. */
#define QSPI_CTL1_RXTIMEOUT_MINIMUM              ((uint32_t)0x00000000U)         /* !< Smallest value */
#define QSPI_CTL1_RXTIMEOUT_MAXIMUM              ((uint32_t)0x3F000000U)         /* !< Highest possible value */
/* QSPI_CTL1[CDENABLE] Bits */
#define QSPI_CTL1_CDENABLE_OFS                   (11)                            /* !< CDENABLE Offset */
#define QSPI_CTL1_CDENABLE_MASK                  ((uint32_t)0x00000800U)         /* !< Command/Data Mode enable */
#define QSPI_CTL1_CDENABLE_DISABLE               ((uint32_t)0x00000000U)         /* !< CS3 is used for Chip Select */
#define QSPI_CTL1_CDENABLE_ENABLE                ((uint32_t)0x00000800U)         /* !< CS3 is used as CD signal */
/* QSPI_CTL1[PTEN] Bits */
#define QSPI_CTL1_PTEN_OFS                       (8)                             /* !< PTEN Offset */
#define QSPI_CTL1_PTEN_MASK                      ((uint32_t)0x00000100U)         /* !< Parity transmit enable If enabled,
                                                                                    parity transmission will be done for
                                                                                    both controller and peripheral modes. */
#define QSPI_CTL1_PTEN_DISABLE                   ((uint32_t)0x00000000U)         /* !< Parity transmission is disabled */
#define QSPI_CTL1_PTEN_ENABLE                    ((uint32_t)0x00000100U)         /* !< Parity transmission is enabled */

/* QSPI_CLKCTL Bits */
/* QSPI_CLKCTL[SCR] Bits */
#define QSPI_CLKCTL_SCR_OFS                      (0)                             /* !< SCR Offset */
#define QSPI_CLKCTL_SCR_MASK                     ((uint32_t)0x000003FFU)         /* !< Serial clock divider: This is used
                                                                                    to generate the transmit and receive
                                                                                    bit rate of the SPI. The SPI bit rate
                                                                                    is (SPI's functional clock
                                                                                    frequency)/((SCR+1)*2). SCR is a
                                                                                    value from 0-1023. */
#define QSPI_CLKCTL_SCR_MINIMUM                  ((uint32_t)0x00000000U)         /* !< Smallest value */
#define QSPI_CLKCTL_SCR_MAXIMUM                  ((uint32_t)0x000003FFU)         /* !< Highest possible value */
/* QSPI_CLKCTL[DSAMPLE] Bits */
#define QSPI_CLKCTL_DSAMPLE_OFS                  (28)                            /* !< DSAMPLE Offset */
#define QSPI_CLKCTL_DSAMPLE_MASK                 ((uint32_t)0xF0000000U)         /* !< Delayed sampling value.  In
                                                                                    controller mode the data on the input
                                                                                    pin will be delayed sampled by the
                                                                                    defined clock cycles of internal
                                                                                    functional clock hence relaxing the
                                                                                    setup time of input data. This
                                                                                    setting is useful in systems where
                                                                                    the board delays and external
                                                                                    peripheral delays are more than the
                                                                                    input setup time of the controller.
                                                                                    Please refer to the datasheet for
                                                                                    values of controller input setup time
                                                                                    and assess what DSAMPLE value meets
                                                                                    the requirement of the system. Note:
                                                                                    High values of DSAMPLE can cause HOLD
                                                                                    time violations and must be factored
                                                                                    in the calculations. */
#define QSPI_CLKCTL_DSAMPLE_MINIMUM              ((uint32_t)0x00000000U)         /* !< Smallest value */
#define QSPI_CLKCTL_DSAMPLE_MAXIMUM              ((uint32_t)0xF0000000U)         /* !< Highest possible value */

/* QSPI_IFLS Bits */
/* QSPI_IFLS[TXIFLSEL] Bits */
#define QSPI_IFLS_TXIFLSEL_OFS                   (0)                             /* !< TXIFLSEL Offset */
#define QSPI_IFLS_TXIFLSEL_MASK                  ((uint32_t)0x00000007U)         /* !< SPI Transmit Interrupt FIFO Level
                                                                                    Select  The trigger points for the
                                                                                    transmit interrupt are as follows: */
#define QSPI_IFLS_TXIFLSEL_LVL_OFF               ((uint32_t)0x00000000U)         /* !< Reserved */
#define QSPI_IFLS_TXIFLSEL_LVL_3_4               ((uint32_t)0x00000001U)         /* !< TX FIFO <= 3/4 empty */
#define QSPI_IFLS_TXIFLSEL_LVL_1_2               ((uint32_t)0x00000002U)         /* !< TX FIFO <= 1/2 empty (default) */
#define QSPI_IFLS_TXIFLSEL_LVL_1_4               ((uint32_t)0x00000003U)         /* !< TX FIFO <= 1/4 empty */
#define QSPI_IFLS_TXIFLSEL_LVL_RES4              ((uint32_t)0x00000004U)         /* !< Reserved */
#define QSPI_IFLS_TXIFLSEL_LVL_EMPTY             ((uint32_t)0x00000005U)         /* !< TX FIFO is empty */
#define QSPI_IFLS_TXIFLSEL_LVL_RES6              ((uint32_t)0x00000006U)         /* !< Reserved */
#define QSPI_IFLS_TXIFLSEL_LEVEL_1               ((uint32_t)0x00000007U)         /* !< Trigger when TX FIFO has >= 1 frame
                                                                                    free Should be used with DMA */
/* QSPI_IFLS[RXIFLSEL] Bits */
#define QSPI_IFLS_RXIFLSEL_OFS                   (3)                             /* !< RXIFLSEL Offset */
#define QSPI_IFLS_RXIFLSEL_MASK                  ((uint32_t)0x00000038U)         /* !< SPI Receive Interrupt FIFO Level
                                                                                    Select  The trigger points for the
                                                                                    receive interrupt are as follows: */
#define QSPI_IFLS_RXIFLSEL_LVL_OFF               ((uint32_t)0x00000000U)         /* !< Reserved */
#define QSPI_IFLS_RXIFLSEL_LVL_1_4               ((uint32_t)0x00000008U)         /* !< RX FIFO >= 1/4 full */
#define QSPI_IFLS_RXIFLSEL_LVL_1_2               ((uint32_t)0x00000010U)         /* !< RX FIFO >= 1/2 full (default) */
#define QSPI_IFLS_RXIFLSEL_LVL_3_4               ((uint32_t)0x00000018U)         /* !< RX FIFO >= 3/4 full */
#define QSPI_IFLS_RXIFLSEL_LVL_RES4              ((uint32_t)0x00000020U)         /* !< Reserved */
#define QSPI_IFLS_RXIFLSEL_LVL_FULL              ((uint32_t)0x00000028U)         /* !< RX FIFO is full */
#define QSPI_IFLS_RXIFLSEL_LVL_RES6              ((uint32_t)0x00000030U)         /* !< Reserved */
#define QSPI_IFLS_RXIFLSEL_LEVEL_1               ((uint32_t)0x00000038U)         /* !< Trigger when RX FIFO contains >= 1
                                                                                    frame */

/* QSPI_STAT Bits */
/* QSPI_STAT[TFE] Bits */
#define QSPI_STAT_TFE_OFS                        (0)                             /* !< TFE Offset */
#define QSPI_STAT_TFE_MASK                       ((uint32_t)0x00000001U)         /* !< Transmit FIFO empty. */
#define QSPI_STAT_TFE_NOT_EMPTY                  ((uint32_t)0x00000000U)         /* !< Transmit FIFO is not empty. */
#define QSPI_STAT_TFE_EMPTY                      ((uint32_t)0x00000001U)         /* !< Transmit FIFO is empty. */
/* QSPI_STAT[TNF] Bits */
#define QSPI_STAT_TNF_OFS                        (1)                             /* !< TNF Offset */
#define QSPI_STAT_TNF_MASK                       ((uint32_t)0x00000002U)         /* !< Transmit FIFO not full */
#define QSPI_STAT_TNF_FULL                       ((uint32_t)0x00000000U)         /* !< Transmit FIFO is full. */
#define QSPI_STAT_TNF_NOT_FULL                   ((uint32_t)0x00000002U)         /* !< Transmit FIFO is not full. */
/* QSPI_STAT[RFE] Bits */
#define QSPI_STAT_RFE_OFS                        (2)                             /* !< RFE Offset */
#define QSPI_STAT_RFE_MASK                       ((uint32_t)0x00000004U)         /* !< Receive FIFO empty. */
#define QSPI_STAT_RFE_NOT_EMPTY                  ((uint32_t)0x00000000U)         /* !< Receive FIFO is not empty. */
#define QSPI_STAT_RFE_EMPTY                      ((uint32_t)0x00000004U)         /* !< Receive FIFO is empty. */
/* QSPI_STAT[RNF] Bits */
#define QSPI_STAT_RNF_OFS                        (3)                             /* !< RNF Offset */
#define QSPI_STAT_RNF_MASK                       ((uint32_t)0x00000008U)         /* !< Receive FIFO not full */
#define QSPI_STAT_RNF_FULL                       ((uint32_t)0x00000000U)         /* !< Receive FIFO is full. */
#define QSPI_STAT_RNF_NOT_FULL                   ((uint32_t)0x00000008U)         /* !< Receive FIFO is not full. */
/* QSPI_STAT[BUSY] Bits */
#define QSPI_STAT_BUSY_OFS                       (4)                             /* !< BUSY Offset */
#define QSPI_STAT_BUSY_MASK                      ((uint32_t)0x00000010U)         /* !< Busy */
#define QSPI_STAT_BUSY_IDLE                      ((uint32_t)0x00000000U)         /* !< SPI is in idle mode. */
#define QSPI_STAT_BUSY_ACTIVE                    ((uint32_t)0x00000010U)         /* !< SPI is currently transmitting
                                                                                    and/or receiving data, or transmit
                                                                                    FIFO is not empty. */

/* QSPI_RXDATA Bits */
/* QSPI_RXDATA[DATA] Bits */
#define QSPI_RXDATA_DATA_OFS                     (0)                             /* !< DATA Offset */
#define QSPI_RXDATA_DATA_MASK                    ((uint32_t)0x0000FFFFU)         /* !< Received Data When PACKEN=1,two
                                                                                    entries of the FIFO are returned as a
                                                                                    32-bit value. When PACKEN=0, 1 entry
                                                                                    of FIFO is returned as 16-bit value.
                                                                                    As data values are removed by the
                                                                                    receive logic from the incoming data
                                                                                    frame, they are placed into the entry
                                                                                    in the receive FIFO, pointed to by
                                                                                    the current FIFO write pointer.
                                                                                    Received data less than 16 bits is
                                                                                    automatically right justified in the
                                                                                    receive buffer. */
#define QSPI_RXDATA_DATA_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Smallest value */
#define QSPI_RXDATA_DATA_MAXIMUM                 ((uint32_t)0xFFFFFFFFU)         /* !< Highest possible value */

/* QSPI_TXDATA Bits */
/* QSPI_TXDATA[DATA] Bits */
#define QSPI_TXDATA_DATA_OFS                     (0)                             /* !< DATA Offset */
#define QSPI_TXDATA_DATA_MASK                    ((uint32_t)0x0000FFFFU)         /* !< Transmit Data  When read, last
                                                                                    written value will be returned. If
                                                                                    the last write to this field was a
                                                                                    32-bit write (with PACKEN=1), 32-bits
                                                                                    will be returned and if the last
                                                                                    write was a 16-bit write (PACKEN=0),
                                                                                    those 16-bits will be returned.
                                                                                    When written, one or two FIFO entries
                                                                                    will be written depending on PACKEN
                                                                                    value. Data values are removed from
                                                                                    the transmit FIFO one value at a time
                                                                                    by the transmit logic. It is loaded
                                                                                    into the transmit serial shifter,
                                                                                    then serially shifted out onto the
                                                                                    TXD output pin at the programmed bit
                                                                                    rate.   When a data size of less than
                                                                                    16 bits is selected, the user must
                                                                                    right-justify data written to the
                                                                                    transmit FIFO. The transmit logic
                                                                                    ignores the unused bits. */
#define QSPI_TXDATA_DATA_MINIMUM                 ((uint32_t)0x00000000U)         /* !< Smallest value */
#define QSPI_TXDATA_DATA_MAXIMUM                 ((uint32_t)0xFFFFFFFFU)         /* !< Highest possible value */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_qspi__include */

