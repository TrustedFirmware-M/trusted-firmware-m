/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __PLATFORM_IRQ_H__
#define __PLATFORM_IRQ_H__

typedef enum _IRQn_Type {
    NonMaskableInt_IRQn                = -14,  /* Non Maskable Interrupt */
    HardFault_IRQn                     = -13,  /* HardFault Interrupt */
    MemoryManagement_IRQn              = -12,  /* Memory Management Interrupt */
    BusFault_IRQn                      = -11,  /* Bus Fault Interrupt */
    UsageFault_IRQn                    = -10,  /* Usage Fault Interrupt */
    SecureFault_IRQn                   = -9,   /* Secure Fault Interrupt */
    SVCall_IRQn                        = -5,   /* SV Call Interrupt */
    DebugMonitor_IRQn                  = -4,   /* Debug Monitor Interrupt */
    PendSV_IRQn                        = -2,   /* Pend SV Interrupt */
    SysTick_IRQn                       = -1,   /* System Tick Interrupt */
    NONSEC_WATCHDOG_RESET_REQ_IRQn     = 0,    /* Non-Secure Watchdog Reset Request Interrupt */
    NONSEC_WATCHDOG_IRQn               = 1,    /* Non-Secure Watchdog Interrupt */
    SLOWCLK_TIMER_IRQn                 = 2,    /* SLOWCLK Timer Interrupt */
    TIMER0_IRQn                        = 3,    /* TIMER 0 Interrupt */
    TIMER1_IRQn                        = 4,    /* TIMER 1 Interrupt */
    TIMER2_IRQn                        = 5,    /* TIMER 2 Interrupt */
    /* Reserved                        = 6:8      Reserved */
    MPC_IRQn                           = 9,    /* MPC Combined (Secure) Interrupt */
    PPC_IRQn                           = 10,   /* PPC Combined (Secure) Interrupt */
    MSC_IRQn                           = 11,   /* MSC Combined (Secure) Interrupt */
    BRIDGE_ERROR_IRQn                  = 12,   /* Bridge Error Combined (Secure) Interrupt */
    /* Reserved                        = 13,      Reserved */
    Combined_PPU_IRQn                  = 14,   /* Combined PPU */
    SDC_IRQn                           = 15,   /* Secure Debug channel Interrupt */
    NPU0_IRQn                          = 16,   /* NPU0 */
    /* Reserved                        = 17:19    Reserved */
    KMU_IRQn                           = 20,   /* KMU Interrupt */
    /* Reserved                        = 21:23    Reserved */
    DMA_SEC_Combined_IRQn              = 24,   /* DMA Secure Combined Interrupt */
    DMA_NONSEC_Combined_IRQn           = 25,   /* DMA Non-Secure Combined Interrupt */
    DMA_SECURITY_VIOLATION_IRQn        = 26,   /* DMA Security Violation Interrupt */
    TIMER3_AON_IRQn                    = 27,   /* TIMER 3 AON Interrupt */
    CPU0_CTI_0_IRQn                    = 28,   /* CPU0 CTI IRQ 0 */
    CPU0_CTI_1_IRQn                    = 29,   /* CPU0 CTI IRQ 1 */
    SAM_CRITICAL_SEVERITY_FAULT_IRQn   = 30,   /* SAM Critical Severity Fault Interrupt */
    SAM_SEVERITY_FAULT_HANDLER_IRQn    = 31,   /* SAM Severity Fault Handler Interrupt */
    SYSCOUNTER_IRQn                    = 32,   /* System Counter */
    ISP_IRQn                           = 33,   /* Image Signal Processor */
    UARTTX0_IRQn                       = 34,   /* UART 0 TX Interrupt */
    UARTRX1_IRQn                       = 35,   /* UART 1 RX Interrupt */
    UARTTX1_IRQn                       = 36,   /* UART 1 TX Interrupt */
    UARTRX2_IRQn                       = 37,   /* UART 2 RX Interrupt */
    UARTTX2_IRQn                       = 38,   /* UART 2 TX Interrupt */
    UARTRX3_IRQn                       = 39,   /* UART 3 RX Interrupt */
    UARTTX3_IRQn                       = 40,   /* UART 3 TX Interrupt */
    UARTRX4_IRQn                       = 41,   /* UART 4 RX Interrupt */
    UARTTX4_IRQn                       = 42,   /* UART 4 TX Interrupt */
    UART0_Combined_IRQn                = 43,   /* UART 0 Combined Interrupt */
    UART1_Combined_IRQn                = 44,   /* UART 1 Combined Interrupt */
    UART2_Combined_IRQn                = 45,   /* UART 2 Combined Interrupt */
    UART3_Combined_IRQn                = 46,   /* UART 3 Combined Interrupt */
    UART4_Combined_IRQn                = 47,   /* UART 4 Combined Interrupt */
    UARTOVF_IRQn                       = 48,   /* UART 0, 1, 2, 3, 4 & 5 Overflow Interrupt */
    UARTRX0_IRQn                       = 49,   /* UART 0 RX Interrupt */
    /* Reserved                        = 50:52    Reserved */
    SPI_SHIELD_ADC_IRQn                = 53,   /* Shield ADC */
    SPI_SHIELD_0_IRQn                  = 54,   /* Shield 0 SPI */
    SPI_SHIELD_1_IRQn                  = 55,   /* Shield 1 SPI */
    /* Reserved                        = 56:62    Reserved */
    RX_FORMATTER_IRQn                  = 63,   /* Audio Formatter - Receiver */
    RX_IRQn                            = 64,   /* Audio Receiver */
    TX_FORMATTER_IRQn                  = 65,   /* Audio Formatter - Transmitter */
    TX_IRQn                            = 66,   /* Audio Transmitter */
    HDMI_AUD_TX_IRQn                   = 67,   /* HDMI Audio Transmitter */
    HDMI_AUD_TX_FMT_IRQn               = 68,   /* HDMI Audio Formatter - Transmitter */
    GPIO0_Combined_IRQn                = 69,   /* GPIO 0 Combined Interrupt */
    GPIO1_Combined_IRQn                = 70,   /* GPIO 1 Combined Interrupt */
    /* Reserved                        = 71:72    Reserved */
    GPIO0_0_IRQn                       = 73,   /* GPIO 0 line 0 Individual Interrupt */
    GPIO0_1_IRQn                       = 74,   /* GPIO 0 line 1 Individual Interrupt */ 
    GPIO0_2_IRQn                       = 75,   /* GPIO 0 line 2 Individual Interrupt */
    GPIO0_3_IRQn                       = 76,   /* GPIO 0 line 3 Individual Interrupt */ 
    GPIO0_4_IRQn                       = 77,   /* GPIO 0 line 4 Individual Interrupt */
    GPIO0_5_IRQn                       = 78,   /* GPIO 0 line 5 Individual Interrupt */
    GPIO0_6_IRQn                       = 79,   /* GPIO 0 line 6 Individual Interrupt */
    GPIO0_7_IRQn                       = 80,   /* GPIO 0 line 7 Individual Interrupt */
    GPIO0_8_IRQn                       = 81,   /* GPIO 0 line 8 Individual Interrupt */
    GPIO0_9_IRQn                       = 82,   /* GPIO 0 line 9 Individual Interrupt */
    GPIO0_10_IRQn                      = 83,   /* GPIO 0 line 10 Individual Interrupt */
    GPIO0_11_IRQn                      = 84,   /* GPIO 0 line 11 Individual Interrupt */
    GPIO0_12_IRQn                      = 85,   /* GPIO 0 line 12 Individual Interrupt */
    GPIO0_13_IRQn                      = 86,   /* GPIO 0 line 13 Individual Interrupt */
    GPIO0_14_IRQn                      = 87,   /* GPIO 0 line 14 Individual Interrupt */
    GPIO0_15_IRQn                      = 88,   /* GPIO 0 line 15 Individual Interrupt */
    GPIO1_0_IRQn                       = 89,   /* GPIO 1 line 0 Individual Interrupt */
    GPIO1_1_IRQn                       = 90,   /* GPIO 1 line 1 Individual Interrupt */ 
    GPIO1_2_IRQn                       = 91,   /* GPIO 1 line 2 Individual Interrupt */
    GPIO1_3_IRQn                       = 92,   /* GPIO 1 line 3 Individual Interrupt */ 
    GPIO1_4_IRQn                       = 93,   /* GPIO 1 line 4 Individual Interrupt */
    GPIO1_5_IRQn                       = 94,   /* GPIO 1 line 5 Individual Interrupt */
    GPIO1_6_IRQn                       = 95,   /* GPIO 1 line 6 Individual Interrupt */
    GPIO1_7_IRQn                       = 96,   /* GPIO 1 line 7 Individual Interrupt */
    GPIO1_8_IRQn                       = 97,   /* GPIO 1 line 8 Individual Interrupt */
    GPIO1_9_IRQn                       = 98,   /* GPIO 1 line 9 Individual Interrupt */
    GPIO1_10_IRQn                      = 99,   /* GPIO 1 line 10 Individual Interrupt */
    GPIO1_11_IRQn                      = 100,  /* GPIO 1 line 11 Individual Interrupt */
    GPIO1_12_IRQn                      = 101,  /* GPIO 1 line 12 Individual Interrupt */
    GPIO1_13_IRQn                      = 102,  /* GPIO 1 line 13 Individual Interrupt */
    GPIO1_14_IRQn                      = 103,  /* GPIO 1 line 14 Individual Interrupt */
    GPIO1_15_IRQn                      = 104,  /* GPIO 1 line 15 Individual Interrupt */
    /* Reserved                        = 106:124   Reserved */
    UARTRX5_IRQn                       = 125,  /* UART 5 RX Interrupt */
    UARTTX5_IRQn                       = 126,  /* UART 5 TX Interrupt */
    UART5_Combined_IRQn                = 127,  /* UART 5 Combined Interrupt */
    HDLCD_IRQn                         = 128,  /* HDMI HDLCD Interrupt */
    /* Reserved                        = 129      Reserved */
    CSIRXSS_CSI_IRQn                   = 130,  /* CSI Receiver Interrupt */
    /* Reserved                        = 131      Reserved */
    /* Reserved                        = 132:223   Reserved */
    ARM_VSI0_IRQn                      = 224,  /* VSI 0 Interrupt */
    ARM_VSI1_IRQn                      = 225,  /* VSI 1 Interrupt */
    ARM_VSI2_IRQn                      = 226,  /* VSI 2 Interrupt */
    ARM_VSI3_IRQn                      = 227,  /* VSI 3 Interrupt */
    ARM_VSI4_IRQn                      = 228,  /* VSI 4 Interrupt */
    ARM_VSI5_IRQn                      = 229,  /* VSI 5 Interrupt */
    ARM_VSI6_IRQn                      = 230,  /* VSI 6 Interrupt */
    ARM_VSI7_IRQn                      = 231,  /* VSI 7 Interrupt */
} IRQn_Type;

#endif  /* __PLATFORM_IRQ_H__ */
