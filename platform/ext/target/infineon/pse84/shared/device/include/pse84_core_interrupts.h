/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef PSE84_CORE_INTERRUPTS_H
#define PSE84_CORE_INTERRUPTS_H

/* SPE and cm33 NSPE are on the same core so the vector table is also the same */
#if (IFX_CORE == IFX_CM33)

#define IFX_CORE_DEFINE_EXCEPTIONS_LIST \
    DEFAULT_IRQ_HANDLER(NMI_Handler) \
    DEFAULT_IRQ_HANDLER(HardFault_Handler) \
    DEFAULT_IRQ_HANDLER(MemManage_Handler) \
    DEFAULT_IRQ_HANDLER(BusFault_Handler) \
    DEFAULT_IRQ_HANDLER(UsageFault_Handler) \
    DEFAULT_IRQ_HANDLER(SecureFault_Handler) \
    DEFAULT_IRQ_HANDLER(SVC_Handler) \
    DEFAULT_IRQ_HANDLER(DebugMon_Handler) \
    DEFAULT_IRQ_HANDLER(PendSV_Handler) \
    DEFAULT_IRQ_HANDLER(SysTick_Handler)

#define IFX_CORE_DEFINE_INTERRUPTS_LIST \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_2_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_3_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_5_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_6_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_7_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_8_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_9_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_10_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_11_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_12_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_13_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_14_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_15_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_16_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_17_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_18_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_19_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_20_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_21_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_sec_gpio_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_sec_gpio_2_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_sec_gpio_3_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_sec_gpio_5_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_sec_gpio_6_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_sec_gpio_7_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_sec_gpio_8_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_sec_gpio_9_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_sec_gpio_10_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_sec_gpio_11_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_sec_gpio_12_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_sec_gpio_13_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_sec_gpio_14_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_sec_gpio_15_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_sec_gpio_16_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_sec_gpio_17_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_sec_gpio_18_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_sec_gpio_19_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_sec_gpio_20_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_sec_gpio_21_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupt_vdd_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupt_gpio_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupt_sec_gpio_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(scb_0_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(srss_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(lpcomp_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupts_ipc_dpslp_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupts_ipc_dpslp_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupts_ipc_dpslp_2_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupts_ipc_dpslp_3_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupts_ipc_dpslp_4_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupts_ipc_dpslp_5_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupts_ipc_dpslp_6_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupts_ipc_dpslp_7_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(srss_interrupt_wdt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(srss_interrupt_mcwdt_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(srss_interrupt_rtc_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(pass_interrupt_lppass_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(pass_interrupt_fifo_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_4_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(srss_interrupt_main_ppu_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(srss_interrupt_srss_pd1_ppu_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupt_ppu_sramc0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupt_ppu_sramc1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupt_ppu_cpuss_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(mxu55_interrupt_ppu_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(socmem_interrupt_ppu_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_ipc_dpslp_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_ipc_dpslp_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_ipc_dpslp_2_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_ipc_dpslp_3_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_ipc_dpslp_4_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_ipc_dpslp_5_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_ipc_dpslp_6_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_ipc_dpslp_7_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(mxnnlite_interrupt_mxnnlite_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_cm33_0_cti_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_cm33_0_cti_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupt_cm33_0_fp_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_2_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_3_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_4_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_5_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_6_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_7_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_8_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_9_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_10_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_11_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_12_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_13_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_14_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_15_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupts_axidmac_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupts_axidmac_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupts_axidmac_2_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupts_axidmac_3_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(smif_0_smif0_interrupt_nsec_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(smif_0_smif0_interrupt_sec_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(smif_1_smif0_interrupt_nsec_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(smif_1_smif0_interrupt_sec_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(canfd_0_interrupts0_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(canfd_0_interrupts1_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(canfd_0_interrupts0_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(canfd_0_interrupts1_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_2_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_3_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_4_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_5_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_6_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_7_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_256_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_257_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_258_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_259_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_260_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_261_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_262_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_263_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_264_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_265_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_266_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_267_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_268_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_269_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_270_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_271_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_272_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_273_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_274_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_275_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_276_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_277_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_278_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_279_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(scb_1_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(scb_2_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(scb_3_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(scb_4_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(scb_5_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(scb_6_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(scb_7_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(scb_8_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(scb_9_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(scb_10_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(scb_11_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(mxu55_interrupt_npu_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(sdhc_0_interrupt_general_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(sdhc_0_interrupt_wakeup_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(sdhc_1_interrupt_general_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(sdhc_1_interrupt_wakeup_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tdm_0_interrupts_rx_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tdm_0_interrupts_tx_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tdm_0_interrupts_rx_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tdm_0_interrupts_tx_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(gfxss_interrupt_gpu_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(gfxss_interrupt_dc_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(gfxss_interrupt_mipidsi_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(pdm_0_interrupts_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(pdm_0_interrupts_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(pdm_0_interrupts_2_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(pdm_0_interrupts_3_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(pdm_0_interrupts_4_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(pdm_0_interrupts_5_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(eth_interrupt_eth_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(eth_interrupt_eth_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(eth_interrupt_eth_2_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(usbhs_interrupt_usbhsctrl_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(usbhs_interrupt_usbhsss_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(i3c_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupt_msc_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(crypto_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_fault_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_fault_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_2_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_3_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_4_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_5_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_6_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_7_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_8_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_9_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_10_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_11_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_12_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_13_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_14_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_15_IRQn_Handler)

#define IFX_CORE_EXCEPTIONS_LIST \
    (VECTOR_TABLE_Type)(&__INITIAL_SP),         /*       Initial Stack Pointer */ \
    Reset_Handler,                              /*   -15 Reset Handler */ \
    NMI_Handler,                                /*   -14 NMI Handler */ \
    HardFault_Handler,                          /*   -13 Hard Fault Handler */ \
    MemManage_Handler,                          /*   -12 MPU Fault Handler */ \
    BusFault_Handler,                           /*   -11 Bus Fault Handler */ \
    UsageFault_Handler,                         /*   -10 Usage Fault Handler */ \
    SecureFault_Handler,                        /*    -9 Secure Fault Handler */ \
    0,                                          /*    -8 Reserved */ \
    0,                                          /*    -7 Reserved */ \
    0,                                          /*    -6 Reserved */ \
    SVC_Handler,                                /*    -5 SVCall Handler */ \
    DebugMon_Handler,                           /*    -4 Debug Monitor Handler */ \
    0,                                          /*    -3 Reserved */ \
    PendSV_Handler,                             /*    -2 PendSV Handler */ \
    SysTick_Handler,                            /*    -1 SysTick Handler */

#define IFX_CORE_INTERRUPTS_LIST \
    ioss_interrupts_gpio_0_IRQn_Handler,              /*!<   0 [DeepSleep] GPIO Port Interrupt #0 */ \
    ioss_interrupts_gpio_2_IRQn_Handler,              /*!<   1 [DeepSleep] GPIO Port Interrupt #2 */ \
    ioss_interrupts_gpio_3_IRQn_Handler,              /*!<   2 [DeepSleep] GPIO Port Interrupt #3 */ \
    ioss_interrupts_gpio_5_IRQn_Handler,              /*!<   3 [DeepSleep] GPIO Port Interrupt #5 */ \
    ioss_interrupts_gpio_6_IRQn_Handler,              /*!<   4 [DeepSleep] GPIO Port Interrupt #6 */ \
    ioss_interrupts_gpio_7_IRQn_Handler,              /*!<   5 [DeepSleep] GPIO Port Interrupt #7 */ \
    ioss_interrupts_gpio_8_IRQn_Handler,              /*!<   6 [DeepSleep] GPIO Port Interrupt #8 */ \
    ioss_interrupts_gpio_9_IRQn_Handler,              /*!<   7 [DeepSleep] GPIO Port Interrupt #9 */ \
    ioss_interrupts_gpio_10_IRQn_Handler,             /*!<   8 [DeepSleep] GPIO Port Interrupt #10 */ \
    ioss_interrupts_gpio_11_IRQn_Handler,             /*!<   9 [DeepSleep] GPIO Port Interrupt #11 */ \
    ioss_interrupts_gpio_12_IRQn_Handler,             /*!<  10 [DeepSleep] GPIO Port Interrupt #12 */ \
    ioss_interrupts_gpio_13_IRQn_Handler,             /*!<  11 [DeepSleep] GPIO Port Interrupt #13 */ \
    ioss_interrupts_gpio_14_IRQn_Handler,             /*!<  12 [DeepSleep] GPIO Port Interrupt #14 */ \
    ioss_interrupts_gpio_15_IRQn_Handler,             /*!<  13 [DeepSleep] GPIO Port Interrupt #15 */ \
    ioss_interrupts_gpio_16_IRQn_Handler,             /*!<  14 [DeepSleep] GPIO Port Interrupt #16 */ \
    ioss_interrupts_gpio_17_IRQn_Handler,             /*!<  15 [DeepSleep] GPIO Port Interrupt #17 */ \
    ioss_interrupts_gpio_18_IRQn_Handler,             /*!<  16 [DeepSleep] GPIO Port Interrupt #18 */ \
    ioss_interrupts_gpio_19_IRQn_Handler,             /*!<  17 [DeepSleep] GPIO Port Interrupt #19 */ \
    ioss_interrupts_gpio_20_IRQn_Handler,             /*!<  18 [DeepSleep] GPIO Port Interrupt #20 */ \
    ioss_interrupts_gpio_21_IRQn_Handler,             /*!<  19 [DeepSleep] GPIO Port Interrupt #21 */ \
    ioss_interrupts_sec_gpio_0_IRQn_Handler,          /*!<  20 [DeepSleep] GPIO Port Secure Interrupt #0 */ \
    ioss_interrupts_sec_gpio_2_IRQn_Handler,          /*!<  21 [DeepSleep] GPIO Port Secure Interrupt #2 */ \
    ioss_interrupts_sec_gpio_3_IRQn_Handler,          /*!<  22 [DeepSleep] GPIO Port Secure Interrupt #3 */ \
    ioss_interrupts_sec_gpio_5_IRQn_Handler,          /*!<  23 [DeepSleep] GPIO Port Secure Interrupt #5 */ \
    ioss_interrupts_sec_gpio_6_IRQn_Handler,          /*!<  24 [DeepSleep] GPIO Port Secure Interrupt #6 */ \
    ioss_interrupts_sec_gpio_7_IRQn_Handler,          /*!<  25 [DeepSleep] GPIO Port Secure Interrupt #7 */ \
    ioss_interrupts_sec_gpio_8_IRQn_Handler,          /*!<  26 [DeepSleep] GPIO Port Secure Interrupt #8 */ \
    ioss_interrupts_sec_gpio_9_IRQn_Handler,          /*!<  27 [DeepSleep] GPIO Port Secure Interrupt #9 */ \
    ioss_interrupts_sec_gpio_10_IRQn_Handler,         /*!<  28 [DeepSleep] GPIO Port Secure Interrupt #10 */ \
    ioss_interrupts_sec_gpio_11_IRQn_Handler,         /*!<  29 [DeepSleep] GPIO Port Secure Interrupt #11 */ \
    ioss_interrupts_sec_gpio_12_IRQn_Handler,         /*!<  30 [DeepSleep] GPIO Port Secure Interrupt #12 */ \
    ioss_interrupts_sec_gpio_13_IRQn_Handler,         /*!<  31 [DeepSleep] GPIO Port Secure Interrupt #13 */ \
    ioss_interrupts_sec_gpio_14_IRQn_Handler,         /*!<  32 [DeepSleep] GPIO Port Secure Interrupt #14 */ \
    ioss_interrupts_sec_gpio_15_IRQn_Handler,         /*!<  33 [DeepSleep] GPIO Port Secure Interrupt #15 */ \
    ioss_interrupts_sec_gpio_16_IRQn_Handler,         /*!<  34 [DeepSleep] GPIO Port Secure Interrupt #16 */ \
    ioss_interrupts_sec_gpio_17_IRQn_Handler,         /*!<  35 [DeepSleep] GPIO Port Secure Interrupt #17 */ \
    ioss_interrupts_sec_gpio_18_IRQn_Handler,         /*!<  36 [DeepSleep] GPIO Port Secure Interrupt #18 */ \
    ioss_interrupts_sec_gpio_19_IRQn_Handler,         /*!<  37 [DeepSleep] GPIO Port Secure Interrupt #19 */ \
    ioss_interrupts_sec_gpio_20_IRQn_Handler,         /*!<  38 [DeepSleep] GPIO Port Secure Interrupt #20 */ \
    ioss_interrupts_sec_gpio_21_IRQn_Handler,         /*!<  39 [DeepSleep] GPIO Port Secure Interrupt #21 */ \
    ioss_interrupt_vdd_IRQn_Handler,                  /*!<  40 [DeepSleep] GPIO Supply Detect Interrupt */ \
    ioss_interrupt_gpio_IRQn_Handler,                 /*!<  41 [DeepSleep] GPIO All Ports */ \
    ioss_interrupt_sec_gpio_IRQn_Handler,             /*!<  42 [DeepSleep] GPIO All Ports - Secured version */ \
    scb_0_interrupt_IRQn_Handler,                     /*!<  43 [DeepSleep] Serial Communication Block #0 (DeepSleep capable) */ \
    srss_interrupt_IRQn_Handler,                      /*!<  44 [DeepSleep] Other combined Interrupts for srss (LVD, CLKCAL) */ \
    lpcomp_interrupt_IRQn_Handler,                    /*!<  45 [DeepSleep] LPCOMP */ \
    m55appcpuss_interrupts_ipc_dpslp_0_IRQn_Handler,  /*!<  46 [DeepSleep] m55appcpuss Inter Process Communication Interrupt #0 */ \
    m55appcpuss_interrupts_ipc_dpslp_1_IRQn_Handler,  /*!<  47 [DeepSleep] m55appcpuss Inter Process Communication Interrupt #1 */ \
    m55appcpuss_interrupts_ipc_dpslp_2_IRQn_Handler,  /*!<  48 [DeepSleep] m55appcpuss Inter Process Communication Interrupt #2 */ \
    m55appcpuss_interrupts_ipc_dpslp_3_IRQn_Handler,  /*!<  49 [DeepSleep] m55appcpuss Inter Process Communication Interrupt #3 */ \
    m55appcpuss_interrupts_ipc_dpslp_4_IRQn_Handler,  /*!<  50 [DeepSleep] m55appcpuss Inter Process Communication Interrupt #4 */ \
    m55appcpuss_interrupts_ipc_dpslp_5_IRQn_Handler,  /*!<  51 [DeepSleep] m55appcpuss Inter Process Communication Interrupt #5 */ \
    m55appcpuss_interrupts_ipc_dpslp_6_IRQn_Handler,  /*!<  52 [DeepSleep] m55appcpuss Inter Process Communication Interrupt #6 */ \
    m55appcpuss_interrupts_ipc_dpslp_7_IRQn_Handler,  /*!<  53 [DeepSleep] m55appcpuss Inter Process Communication Interrupt #7 */ \
    srss_interrupt_wdt_IRQn_Handler,                  /*!<  54 [DeepSleep] Interrupt for WDT */ \
    srss_interrupt_mcwdt_0_IRQn_Handler,              /*!<  55 [DeepSleep] Interrupt for MCWDT[] */ \
    srss_interrupt_rtc_IRQn_Handler,                  /*!<  56 [DeepSleep] Interrupt for RTC */ \
    pass_interrupt_lppass_IRQn_Handler,               /*!<  57 [DeepSleep] LPPASS interrupt */ \
    pass_interrupt_fifo_IRQn_Handler,                 /*!<  58 [DeepSleep] LPPASS FIFO interrupt */ \
    ioss_interrupts_gpio_1_IRQn_Handler,              /*!<  59 [Active] GPIO Port Interrupt #1 (SMIF0) */ \
    ioss_interrupts_gpio_4_IRQn_Handler,              /*!<  60 [Active] GPIO Port Interrupt #4 (SMIF1) */ \
    0,                                                /*!<  61 Unused */ \
    0,                                                /*!<  62 Unused */ \
    srss_interrupt_main_ppu_IRQn_Handler,             /*!<  63 [Active] Interrupt from Main PPU */ \
    srss_interrupt_srss_pd1_ppu_IRQn_Handler,         /*!<  64 [Active] Interrupt from PD1 PPU */ \
    m33syscpuss_interrupt_ppu_sramc0_IRQn_Handler,    /*!<  65 [Active] PPU SRAM0 */ \
    m33syscpuss_interrupt_ppu_sramc1_IRQn_Handler,    /*!<  66 [Active] PPU SRAM1 */ \
    m33syscpuss_interrupt_ppu_cpuss_IRQn_Handler,     /*!<  67 [Active] cpuss[0] PPU Interrupt */ \
    mxu55_interrupt_ppu_IRQn_Handler,                 /*!<  68 [Active] Interrupt requests of mxu55.PPU */ \
    socmem_interrupt_ppu_IRQn_Handler,                /*!<  69 [Active] Interrupt requests of socmem.PPU */ \
    m33syscpuss_interrupts_ipc_dpslp_0_IRQn_Handler,  /*!<  70 [Active] m33syscpuss Inter Process Communication Interrupt #0 */ \
    m33syscpuss_interrupts_ipc_dpslp_1_IRQn_Handler,  /*!<  71 [Active] m33syscpuss Inter Process Communication Interrupt #1 */ \
    m33syscpuss_interrupts_ipc_dpslp_2_IRQn_Handler,  /*!<  72 [Active] m33syscpuss Inter Process Communication Interrupt #2 */ \
    m33syscpuss_interrupts_ipc_dpslp_3_IRQn_Handler,  /*!<  73 [Active] m33syscpuss Inter Process Communication Interrupt #3 */ \
    m33syscpuss_interrupts_ipc_dpslp_4_IRQn_Handler,  /*!<  74 [Active] m33syscpuss Inter Process Communication Interrupt #4 */ \
    m33syscpuss_interrupts_ipc_dpslp_5_IRQn_Handler,  /*!<  75 [Active] m33syscpuss Inter Process Communication Interrupt #5 */ \
    m33syscpuss_interrupts_ipc_dpslp_6_IRQn_Handler,  /*!<  76 [Active] m33syscpuss Inter Process Communication Interrupt #6 */ \
    m33syscpuss_interrupts_ipc_dpslp_7_IRQn_Handler,  /*!<  77 [Active] m33syscpuss Inter Process Communication Interrupt #7 */ \
    mxnnlite_interrupt_mxnnlite_IRQn_Handler,         /*!<  78 [Active] Interrupt of MXNNLITE */ \
    m33syscpuss_interrupts_cm33_0_cti_0_IRQn_Handler, /*!<  79 [Active]  */ \
    m33syscpuss_interrupts_cm33_0_cti_1_IRQn_Handler, /*!<  80 [Active]  */ \
    m33syscpuss_interrupt_cm33_0_fp_IRQn_Handler,     /*!<  81 [Active] CM33 0 Floating Point Interrupt */ \
    m33syscpuss_interrupts_dw0_0_IRQn_Handler,        /*!<  82 [Active] cpuss[0] DataWire #0, Channel #0 */ \
    m33syscpuss_interrupts_dw0_1_IRQn_Handler,        /*!<  83 [Active] cpuss[0] DataWire #0, Channel #1 */ \
    m33syscpuss_interrupts_dw0_2_IRQn_Handler,        /*!<  84 [Active] cpuss[0] DataWire #0, Channel #2 */ \
    m33syscpuss_interrupts_dw0_3_IRQn_Handler,        /*!<  85 [Active] cpuss[0] DataWire #0, Channel #3 */ \
    m33syscpuss_interrupts_dw0_4_IRQn_Handler,        /*!<  86 [Active] cpuss[0] DataWire #0, Channel #4 */ \
    m33syscpuss_interrupts_dw0_5_IRQn_Handler,        /*!<  87 [Active] cpuss[0] DataWire #0, Channel #5 */ \
    m33syscpuss_interrupts_dw0_6_IRQn_Handler,        /*!<  88 [Active] cpuss[0] DataWire #0, Channel #6 */ \
    m33syscpuss_interrupts_dw0_7_IRQn_Handler,        /*!<  89 [Active] cpuss[0] DataWire #0, Channel #7 */ \
    m33syscpuss_interrupts_dw0_8_IRQn_Handler,        /*!<  90 [Active] cpuss[0] DataWire #0, Channel #8 */ \
    m33syscpuss_interrupts_dw0_9_IRQn_Handler,        /*!<  91 [Active] cpuss[0] DataWire #0, Channel #9 */ \
    m33syscpuss_interrupts_dw0_10_IRQn_Handler,       /*!<  92 [Active] cpuss[0] DataWire #0, Channel #10 */ \
    m33syscpuss_interrupts_dw0_11_IRQn_Handler,       /*!<  93 [Active] cpuss[0] DataWire #0, Channel #11 */ \
    m33syscpuss_interrupts_dw0_12_IRQn_Handler,       /*!<  94 [Active] cpuss[0] DataWire #0, Channel #12 */ \
    m33syscpuss_interrupts_dw0_13_IRQn_Handler,       /*!<  95 [Active] cpuss[0] DataWire #0, Channel #13 */ \
    m33syscpuss_interrupts_dw0_14_IRQn_Handler,       /*!<  96 [Active] cpuss[0] DataWire #0, Channel #14 */ \
    m33syscpuss_interrupts_dw0_15_IRQn_Handler,       /*!<  97 [Active] cpuss[0] DataWire #0, Channel #15 */ \
    m55appcpuss_interrupts_axidmac_0_IRQn_Handler,    /*!<  98 [Active]  */ \
    m55appcpuss_interrupts_axidmac_1_IRQn_Handler,    /*!<  99 [Active]  */ \
    m55appcpuss_interrupts_axidmac_2_IRQn_Handler,    /*!< 100 [Active]  */ \
    m55appcpuss_interrupts_axidmac_3_IRQn_Handler,    /*!< 101 [Active]  */ \
    smif_0_smif0_interrupt_nsec_IRQn_Handler,         /*!< 102 [Active] SMIF0 Port0 non-secure interrupt */ \
    smif_0_smif0_interrupt_sec_IRQn_Handler,          /*!< 103 [Active] SMIF0 Port0 secure interrupt */ \
    smif_1_smif0_interrupt_nsec_IRQn_Handler,         /*!< 104 [Active] SMIF1 Port0 non-secure interrupt */ \
    smif_1_smif0_interrupt_sec_IRQn_Handler,          /*!< 105 [Active] SMIF1 Port0 secure interrupt */ \
    canfd_0_interrupts0_0_IRQn_Handler,               /*!< 106 [Active] CAN #0, Interrupt0, Channel#0 */ \
    canfd_0_interrupts1_0_IRQn_Handler,               /*!< 107 [Active] CAN #0, Interrupt1, Channel#0 */ \
    canfd_0_interrupts0_1_IRQn_Handler,               /*!< 108 [Active] CAN #0, Interrupt0, Channel#1 */ \
    canfd_0_interrupts1_1_IRQn_Handler,               /*!< 109 [Active] CAN #0, Interrupt1, Channel#1 */ \
    tcpwm_0_interrupts_0_IRQn_Handler,                /*!< 110 [Active] TCPWM, 32-bit Counter #0 */ \
    tcpwm_0_interrupts_1_IRQn_Handler,                /*!< 111 [Active] TCPWM, 32-bit Counter #1 */ \
    tcpwm_0_interrupts_2_IRQn_Handler,                /*!< 112 [Active] TCPWM, 32-bit Counter #2 */ \
    tcpwm_0_interrupts_3_IRQn_Handler,                /*!< 113 [Active] TCPWM, 32-bit Counter #3 */ \
    tcpwm_0_interrupts_4_IRQn_Handler,                /*!< 114 [Active] TCPWM, 32-bit Counter #4 */ \
    tcpwm_0_interrupts_5_IRQn_Handler,                /*!< 115 [Active] TCPWM, 32-bit Counter #5 */ \
    tcpwm_0_interrupts_6_IRQn_Handler,                /*!< 116 [Active] TCPWM, 32-bit Counter #6 */ \
    tcpwm_0_interrupts_7_IRQn_Handler,                /*!< 117 [Active] TCPWM, 32-bit Counter #7 */ \
    tcpwm_0_interrupts_256_IRQn_Handler,              /*!< 118 [Active] TCPWM, 16-bit Counter #0 */ \
    tcpwm_0_interrupts_257_IRQn_Handler,              /*!< 119 [Active] TCPWM, 16-bit Counter #1 */ \
    tcpwm_0_interrupts_258_IRQn_Handler,              /*!< 120 [Active] TCPWM, 16-bit Counter #2 */ \
    tcpwm_0_interrupts_259_IRQn_Handler,              /*!< 121 [Active] TCPWM, 16-bit Counter #3 */ \
    tcpwm_0_interrupts_260_IRQn_Handler,              /*!< 122 [Active] TCPWM, 16-bit Counter #4 */ \
    tcpwm_0_interrupts_261_IRQn_Handler,              /*!< 123 [Active] TCPWM, 16-bit Counter #5 */ \
    tcpwm_0_interrupts_262_IRQn_Handler,              /*!< 124 [Active] TCPWM, 16-bit Counter #6 */ \
    tcpwm_0_interrupts_263_IRQn_Handler,              /*!< 125 [Active] TCPWM, 16-bit Counter #7 */ \
    tcpwm_0_interrupts_264_IRQn_Handler,              /*!< 126 [Active] TCPWM, 16-bit Counter #8 */ \
    tcpwm_0_interrupts_265_IRQn_Handler,              /*!< 127 [Active] TCPWM, 16-bit Counter #9 */ \
    tcpwm_0_interrupts_266_IRQn_Handler,              /*!< 128 [Active] TCPWM, 16-bit Counter #10 */ \
    tcpwm_0_interrupts_267_IRQn_Handler,              /*!< 129 [Active] TCPWM, 16-bit Counter #11 */ \
    tcpwm_0_interrupts_268_IRQn_Handler,              /*!< 130 [Active] TCPWM, 16-bit Counter #12 */ \
    tcpwm_0_interrupts_269_IRQn_Handler,              /*!< 131 [Active] TCPWM, 16-bit Counter #13 */ \
    tcpwm_0_interrupts_270_IRQn_Handler,              /*!< 132 [Active] TCPWM, 16-bit Counter #14 */ \
    tcpwm_0_interrupts_271_IRQn_Handler,              /*!< 133 [Active] TCPWM, 16-bit Counter #15 */ \
    tcpwm_0_interrupts_272_IRQn_Handler,              /*!< 134 [Active] TCPWM, 16-bit Counter #16 */ \
    tcpwm_0_interrupts_273_IRQn_Handler,              /*!< 135 [Active] TCPWM, 16-bit Counter #17 */ \
    tcpwm_0_interrupts_274_IRQn_Handler,              /*!< 136 [Active] TCPWM, 16-bit Counter #18 */ \
    tcpwm_0_interrupts_275_IRQn_Handler,              /*!< 137 [Active] TCPWM, 16-bit Counter #19 */ \
    tcpwm_0_interrupts_276_IRQn_Handler,              /*!< 138 [Active] TCPWM, 16-bit Counter #20 */ \
    tcpwm_0_interrupts_277_IRQn_Handler,              /*!< 139 [Active] TCPWM, 16-bit Counter #21 */ \
    tcpwm_0_interrupts_278_IRQn_Handler,              /*!< 140 [Active] TCPWM, 16-bit Counter #22 */ \
    tcpwm_0_interrupts_279_IRQn_Handler,              /*!< 141 [Active] TCPWM, 16-bit Counter #23 */ \
    scb_1_interrupt_IRQn_Handler,                     /*!< 142 [Active] SCB#1 Interrupt */ \
    scb_2_interrupt_IRQn_Handler,                     /*!< 143 [Active] SCB#2 Interrupt */ \
    scb_3_interrupt_IRQn_Handler,                     /*!< 144 [Active] SCB#3 Interrupt */ \
    scb_4_interrupt_IRQn_Handler,                     /*!< 145 [Active] SCB#4 Interrupt */ \
    scb_5_interrupt_IRQn_Handler,                     /*!< 146 [Active] SCB#5 Interrupt */ \
    scb_6_interrupt_IRQn_Handler,                     /*!< 147 [Active] SCB#6 Interrupt */ \
    scb_7_interrupt_IRQn_Handler,                     /*!< 148 [Active] SCB#7 Interrupt */ \
    scb_8_interrupt_IRQn_Handler,                     /*!< 149 [Active] SCB#8 Interrupt */ \
    scb_9_interrupt_IRQn_Handler,                     /*!< 150 [Active] SCB#9 Interrupt */ \
    scb_10_interrupt_IRQn_Handler,                    /*!< 151 [Active] SCB#10 Interrupt */ \
    scb_11_interrupt_IRQn_Handler,                    /*!< 152 [Active] SCB#11 Interrupt */ \
    mxu55_interrupt_npu_IRQn_Handler,                 /*!< 153 [Active] Interrupt requests of armu55 (NPU) */ \
    sdhc_0_interrupt_general_IRQn_Handler,            /*!< 154 [Active] SDHC0 */ \
    sdhc_0_interrupt_wakeup_IRQn_Handler,             /*!< 155 [Active] SDHC0 */ \
    sdhc_1_interrupt_general_IRQn_Handler,            /*!< 156 [Active] SDHC1 */ \
    sdhc_1_interrupt_wakeup_IRQn_Handler,             /*!< 157 [Active] SDHC1 */ \
    tdm_0_interrupts_rx_0_IRQn_Handler,               /*!< 158 [Active] TDM0 Audio interrupt RX Structure#0 */ \
    tdm_0_interrupts_tx_0_IRQn_Handler,               /*!< 159 [Active] TDM0 Audio interrupt TX Structure#0 */ \
    tdm_0_interrupts_rx_1_IRQn_Handler,               /*!< 160 [Active] TDM0 Audio interrupt RX Structure#1 */ \
    tdm_0_interrupts_tx_1_IRQn_Handler,               /*!< 161 [Active] TDM0 Audio interrupt TX Structure#1 */ \
    gfxss_interrupt_gpu_IRQn_Handler,                 /*!< 162 [Active] Interrupt from GPU. */ \
    gfxss_interrupt_dc_IRQn_Handler,                  /*!< 163 [Active] Interrupt from DC. */ \
    gfxss_interrupt_mipidsi_IRQn_Handler,             /*!< 164 [Active] Interrupt from MIPIDSI. */ \
    pdm_0_interrupts_0_IRQn_Handler,                  /*!< 165 [Active] PDM interrupt Structure#0 */ \
    pdm_0_interrupts_1_IRQn_Handler,                  /*!< 166 [Active] PDM interrupt Structure#1 */ \
    pdm_0_interrupts_2_IRQn_Handler,                  /*!< 167 [Active] PDM interrupt Structure#2 */ \
    pdm_0_interrupts_3_IRQn_Handler,                  /*!< 168 [Active] PDM interrupt Structure#3 */ \
    pdm_0_interrupts_4_IRQn_Handler,                  /*!< 169 [Active] PDM interrupt Structure#4 */ \
    pdm_0_interrupts_5_IRQn_Handler,                  /*!< 170 [Active] PDM interrupt Structure#5 */ \
    eth_interrupt_eth_0_IRQn_Handler,                 /*!< 171 [Active] ETH Interrupt#0 */ \
    eth_interrupt_eth_1_IRQn_Handler,                 /*!< 172 [Active] ETH Interrupt#1 */ \
    eth_interrupt_eth_2_IRQn_Handler,                 /*!< 173 [Active] ETH Interrupt#2 */ \
    usbhs_interrupt_usbhsctrl_IRQn_Handler,           /*!< 174 [Active] Interrupt of Controller core */ \
    usbhs_interrupt_usbhsss_IRQn_Handler,             /*!< 175 [Active] Interrupt of Subsystem */ \
    i3c_interrupt_IRQn_Handler,                       /*!< 176 [Active] I3C Interrupt */ \
    m33syscpuss_interrupt_msc_IRQn_Handler,           /*!< 177 [Active]  */ \
    crypto_interrupt_IRQn_Handler,                    /*!< 178 [Active] Crypto Interrupt */ \
    m33syscpuss_interrupts_fault_0_IRQn_Handler,      /*!< 179 [Active]  */ \
    m33syscpuss_interrupts_fault_1_IRQn_Handler,      /*!< 180 [Active]  */ \
    m33syscpuss_interrupts_dw1_0_IRQn_Handler,        /*!< 181 [Active] cpuss[0] DataWire #1, Channel #0 */ \
    m33syscpuss_interrupts_dw1_1_IRQn_Handler,        /*!< 182 [Active] cpuss[0] DataWire #1, Channel #1 */ \
    m33syscpuss_interrupts_dw1_2_IRQn_Handler,        /*!< 183 [Active] cpuss[0] DataWire #1, Channel #2 */ \
    m33syscpuss_interrupts_dw1_3_IRQn_Handler,        /*!< 184 [Active] cpuss[0] DataWire #1, Channel #3 */ \
    m33syscpuss_interrupts_dw1_4_IRQn_Handler,        /*!< 185 [Active] cpuss[0] DataWire #1, Channel #4 */ \
    m33syscpuss_interrupts_dw1_5_IRQn_Handler,        /*!< 186 [Active] cpuss[0] DataWire #1, Channel #5 */ \
    m33syscpuss_interrupts_dw1_6_IRQn_Handler,        /*!< 187 [Active] cpuss[0] DataWire #1, Channel #6 */ \
    m33syscpuss_interrupts_dw1_7_IRQn_Handler,        /*!< 188 [Active] cpuss[0] DataWire #1, Channel #7 */ \
    m33syscpuss_interrupts_dw1_8_IRQn_Handler,        /*!< 189 [Active] cpuss[0] DataWire #1, Channel #8 */ \
    m33syscpuss_interrupts_dw1_9_IRQn_Handler,        /*!< 190 [Active] cpuss[0] DataWire #1, Channel #9 */ \
    m33syscpuss_interrupts_dw1_10_IRQn_Handler,       /*!< 191 [Active] cpuss[0] DataWire #1, Channel #10 */ \
    m33syscpuss_interrupts_dw1_11_IRQn_Handler,       /*!< 192 [Active] cpuss[0] DataWire #1, Channel #11 */ \
    m33syscpuss_interrupts_dw1_12_IRQn_Handler,       /*!< 193 [Active] cpuss[0] DataWire #1, Channel #12 */ \
    m33syscpuss_interrupts_dw1_13_IRQn_Handler,       /*!< 194 [Active] cpuss[0] DataWire #1, Channel #13 */ \
    m33syscpuss_interrupts_dw1_14_IRQn_Handler,       /*!< 195 [Active] cpuss[0] DataWire #1, Channel #14 */ \
    m33syscpuss_interrupts_dw1_15_IRQn_Handler,       /*!< 196 [Active] cpuss[0] DataWire #1, Channel #15 */ \

#elif (IFX_CORE == IFX_CM55)

#define IFX_CORE_DEFINE_EXCEPTIONS_LIST \
    DEFAULT_IRQ_HANDLER(NMI_Handler) \
    DEFAULT_IRQ_HANDLER(HardFault_Handler) \
    DEFAULT_IRQ_HANDLER(MemManage_Handler) \
    DEFAULT_IRQ_HANDLER(BusFault_Handler) \
    DEFAULT_IRQ_HANDLER(UsageFault_Handler) \
    DEFAULT_IRQ_HANDLER(SecureFault_Handler) \
    DEFAULT_IRQ_HANDLER(SVC_Handler) \
    DEFAULT_IRQ_HANDLER(DebugMon_Handler) \
    DEFAULT_IRQ_HANDLER(PendSV_Handler) \
    DEFAULT_IRQ_HANDLER(SysTick_Handler)

#define IFX_CORE_DEFINE_INTERRUPTS_LIST \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_2_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_3_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_5_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_6_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_7_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_8_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_9_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_10_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_11_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_12_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_13_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_14_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_15_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_16_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_17_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_18_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_19_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_20_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_21_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupt_vdd_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupt_gpio_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(scb_0_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(srss_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(lpcomp_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_ipc_dpslp_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_ipc_dpslp_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_ipc_dpslp_2_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_ipc_dpslp_3_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_ipc_dpslp_4_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_ipc_dpslp_5_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_ipc_dpslp_6_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_ipc_dpslp_7_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(srss_interrupt_wdt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(srss_interrupt_mcwdt_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(srss_interrupt_rtc_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(pass_interrupt_lppass_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(pass_interrupt_fifo_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(mxu55_interrupt_npu_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(ioss_interrupts_gpio_4_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(srss_interrupt_main_ppu_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(srss_interrupt_srss_pd1_ppu_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupt_ppu_appcpuss_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupt_ppu_cm55_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(mxu55_interrupt_ppu_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(socmem_interrupt_ppu_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupts_ipc_dpslp_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupts_ipc_dpslp_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupts_ipc_dpslp_2_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupts_ipc_dpslp_3_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupts_ipc_dpslp_4_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupts_ipc_dpslp_5_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupts_ipc_dpslp_6_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupts_ipc_dpslp_7_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(mxnnlite_interrupt_mxnnlite_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupt_cm55_0_fp_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupts_cm55_0_cti_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupts_cm55_0_cti_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupt_msc_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_2_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_3_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_4_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_5_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_6_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_7_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_8_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_9_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_10_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_11_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_12_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_13_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_14_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw0_15_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupts_axidmac_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupts_axidmac_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupts_axidmac_2_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupts_axidmac_3_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(smif_0_smif0_interrupt_nsec_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(smif_0_smif0_interrupt_sec_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(smif_1_smif0_interrupt_nsec_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(smif_1_smif0_interrupt_sec_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(canfd_0_interrupts0_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(canfd_0_interrupts1_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(canfd_0_interrupts0_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(canfd_0_interrupts1_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_2_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_3_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_4_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_5_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_6_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_7_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_256_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_257_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_258_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_259_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_260_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_261_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_262_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_263_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_264_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_265_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_266_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_267_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_268_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_269_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_270_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_271_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_272_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_273_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_274_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_275_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_276_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_277_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_278_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tcpwm_0_interrupts_279_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(scb_1_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(scb_2_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(scb_3_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(scb_4_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(scb_5_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(scb_6_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(scb_7_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(scb_8_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(scb_9_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(scb_10_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(scb_11_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(sdhc_0_interrupt_general_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(sdhc_0_interrupt_wakeup_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(sdhc_1_interrupt_general_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(sdhc_1_interrupt_wakeup_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tdm_0_interrupts_rx_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tdm_0_interrupts_tx_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tdm_0_interrupts_rx_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(tdm_0_interrupts_tx_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(gfxss_interrupt_gpu_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(gfxss_interrupt_dc_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(gfxss_interrupt_mipidsi_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(pdm_0_interrupts_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(pdm_0_interrupts_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(pdm_0_interrupts_2_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(pdm_0_interrupts_3_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(pdm_0_interrupts_4_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(pdm_0_interrupts_5_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(eth_interrupt_eth_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(eth_interrupt_eth_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(eth_interrupt_eth_2_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(usbhs_interrupt_usbhsctrl_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(usbhs_interrupt_usbhsss_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(i3c_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(crypto_interrupt_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_fault_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_fault_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m55appcpuss_interrupt_ahb2axi_buff_err_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_0_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_1_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_2_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_3_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_4_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_5_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_6_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_7_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_8_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_9_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_10_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_11_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_12_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_13_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_14_IRQn_Handler) \
    DEFAULT_IRQ_HANDLER(m33syscpuss_interrupts_dw1_15_IRQn_Handler)

#define IFX_CORE_EXCEPTIONS_LIST \
    (VECTOR_TABLE_Type)(&__INITIAL_SP),         /*       Initial Stack Pointer */ \
    Reset_Handler,                              /*   -15 Reset Handler */ \
    NMI_Handler,                                /*   -14 NMI Handler */ \
    HardFault_Handler,                          /*   -13 Hard Fault Handler */ \
    MemManage_Handler,                          /*   -12 MPU Fault Handler */ \
    BusFault_Handler,                           /*   -11 Bus Fault Handler */ \
    UsageFault_Handler,                         /*   -10 Usage Fault Handler */ \
    SecureFault_Handler,                        /*    -9 Secure Fault Handler */ \
    0,                                          /*    -8 Reserved */ \
    0,                                          /*    -7 Reserved */ \
    0,                                          /*    -6 Reserved */ \
    SVC_Handler,                                /*    -5 SVCall Handler */ \
    DebugMon_Handler,                           /*    -4 Debug Monitor Handler */ \
    0,                                          /*    -3 Reserved */ \
    PendSV_Handler,                             /*    -2 PendSV Handler */ \
    SysTick_Handler,                            /*    -1 SysTick Handler */

#define IFX_CORE_INTERRUPTS_LIST \
    ioss_interrupts_gpio_0_IRQn_Handler,                  /*!<   0 [DeepSleep] GPIO Port Interrupt #0 */ \
    ioss_interrupts_gpio_2_IRQn_Handler,                  /*!<   1 [DeepSleep] GPIO Port Interrupt #2 */ \
    ioss_interrupts_gpio_3_IRQn_Handler,                  /*!<   2 [DeepSleep] GPIO Port Interrupt #3 */ \
    ioss_interrupts_gpio_5_IRQn_Handler,                  /*!<   3 [DeepSleep] GPIO Port Interrupt #5 */ \
    ioss_interrupts_gpio_6_IRQn_Handler,                  /*!<   4 [DeepSleep] GPIO Port Interrupt #6 */ \
    ioss_interrupts_gpio_7_IRQn_Handler,                  /*!<   5 [DeepSleep] GPIO Port Interrupt #7 */ \
    ioss_interrupts_gpio_8_IRQn_Handler,                  /*!<   6 [DeepSleep] GPIO Port Interrupt #8 */ \
    ioss_interrupts_gpio_9_IRQn_Handler,                  /*!<   7 [DeepSleep] GPIO Port Interrupt #9 */ \
    ioss_interrupts_gpio_10_IRQn_Handler,                 /*!<   8 [DeepSleep] GPIO Port Interrupt #10 */ \
    ioss_interrupts_gpio_11_IRQn_Handler,                 /*!<   9 [DeepSleep] GPIO Port Interrupt #11 */ \
    ioss_interrupts_gpio_12_IRQn_Handler,                 /*!<  10 [DeepSleep] GPIO Port Interrupt #12 */ \
    ioss_interrupts_gpio_13_IRQn_Handler,                 /*!<  11 [DeepSleep] GPIO Port Interrupt #13 */ \
    ioss_interrupts_gpio_14_IRQn_Handler,                 /*!<  12 [DeepSleep] GPIO Port Interrupt #14 */ \
    ioss_interrupts_gpio_15_IRQn_Handler,                 /*!<  13 [DeepSleep] GPIO Port Interrupt #15 */ \
    ioss_interrupts_gpio_16_IRQn_Handler,                 /*!<  14 [DeepSleep] GPIO Port Interrupt #16 */ \
    ioss_interrupts_gpio_17_IRQn_Handler,                 /*!<  15 [DeepSleep] GPIO Port Interrupt #17 */ \
    ioss_interrupts_gpio_18_IRQn_Handler,                 /*!<  16 [DeepSleep] GPIO Port Interrupt #18 */ \
    ioss_interrupts_gpio_19_IRQn_Handler,                 /*!<  17 [DeepSleep] GPIO Port Interrupt #19 */ \
    ioss_interrupts_gpio_20_IRQn_Handler,                 /*!<  18 [DeepSleep] GPIO Port Interrupt #20 */ \
    ioss_interrupts_gpio_21_IRQn_Handler,                 /*!<  19 [DeepSleep] GPIO Port Interrupt #21 */ \
    ioss_interrupt_vdd_IRQn_Handler,                      /*!<  20 [DeepSleep] GPIO Supply Detect Interrupt */ \
    ioss_interrupt_gpio_IRQn_Handler,                     /*!<  21 [DeepSleep] GPIO All Ports */ \
    scb_0_interrupt_IRQn_Handler,                         /*!<  22 [DeepSleep] Serial Communication Block #0 (DeepSleep capable) */ \
    srss_interrupt_IRQn_Handler,                          /*!<  23 [DeepSleep] Other combined Interrupts for srss (LVD, CLKCAL) */ \
    lpcomp_interrupt_IRQn_Handler,                        /*!<  24 [DeepSleep] LPCOMP */ \
    m33syscpuss_interrupts_ipc_dpslp_0_IRQn_Handler,      /*!<  25 [DeepSleep] m33syscpuss Inter Process Communication Interrupt #0 */ \
    m33syscpuss_interrupts_ipc_dpslp_1_IRQn_Handler,      /*!<  26 [DeepSleep] m33syscpuss Inter Process Communication Interrupt #1 */ \
    m33syscpuss_interrupts_ipc_dpslp_2_IRQn_Handler,      /*!<  27 [DeepSleep] m33syscpuss Inter Process Communication Interrupt #2 */ \
    m33syscpuss_interrupts_ipc_dpslp_3_IRQn_Handler,      /*!<  28 [DeepSleep] m33syscpuss Inter Process Communication Interrupt #3 */ \
    m33syscpuss_interrupts_ipc_dpslp_4_IRQn_Handler,      /*!<  29 [DeepSleep] m33syscpuss Inter Process Communication Interrupt #4 */ \
    m33syscpuss_interrupts_ipc_dpslp_5_IRQn_Handler,      /*!<  30 [DeepSleep] m33syscpuss Inter Process Communication Interrupt #5 */ \
    m33syscpuss_interrupts_ipc_dpslp_6_IRQn_Handler,      /*!<  31 [DeepSleep] m33syscpuss Inter Process Communication Interrupt #6 */ \
    m33syscpuss_interrupts_ipc_dpslp_7_IRQn_Handler,      /*!<  32 [DeepSleep] m33syscpuss Inter Process Communication Interrupt #7 */ \
    srss_interrupt_wdt_IRQn_Handler,                      /*!<  33 [DeepSleep] Interrupt for WDT */ \
    srss_interrupt_mcwdt_1_IRQn_Handler,                  /*!<  34 [DeepSleep] Interrupt for MCWDT[] */ \
    srss_interrupt_rtc_IRQn_Handler,                      /*!<  35 [DeepSleep] Interrupt from RTC */ \
    pass_interrupt_lppass_IRQn_Handler,                   /*!<  36 [DeepSleep] LPPASS interrupt */ \
    pass_interrupt_fifo_IRQn_Handler,                     /*!<  37 [DeepSleep] LPPASS FIFO interrupt */ \
    mxu55_interrupt_npu_IRQn_Handler,                     /*!<  38 [DeepSleep] Interrupt requests of armu55 (NPU) */ \
    ioss_interrupts_gpio_1_IRQn_Handler,                  /*!<  39 [Active] GPIO Port Interrupt #1 */ \
    ioss_interrupts_gpio_4_IRQn_Handler,                  /*!<  40 [Active] GPIO Port Interrupt #4 */ \
    srss_interrupt_main_ppu_IRQn_Handler,                 /*!<  41 [Active] Interrupt from Main PPU */ \
    srss_interrupt_srss_pd1_ppu_IRQn_Handler,             /*!<  42 [Active] Interrupt from PD1 PPU */ \
    m55appcpuss_interrupt_ppu_appcpuss_IRQn_Handler,      /*!<  43 [Active] PPU APPCPUSS */ \
    m55appcpuss_interrupt_ppu_cm55_0_IRQn_Handler,        /*!<  44 [Active] PPU CM55 */ \
    mxu55_interrupt_ppu_IRQn_Handler,                     /*!<  45 [Active] Interrupt requests of mxu55.PPU */ \
    socmem_interrupt_ppu_IRQn_Handler,                    /*!<  46 [Active] Interrupt requests of socmem.PPU */ \
    m55appcpuss_interrupts_ipc_dpslp_0_IRQn_Handler,      /*!<  47 [Active] m55appcpuss Inter Process Communication Interrupt #0 */ \
    m55appcpuss_interrupts_ipc_dpslp_1_IRQn_Handler,      /*!<  48 [Active] m55appcpuss Inter Process Communication Interrupt #1 */ \
    m55appcpuss_interrupts_ipc_dpslp_2_IRQn_Handler,      /*!<  49 [Active] m55appcpuss Inter Process Communication Interrupt #2 */ \
    m55appcpuss_interrupts_ipc_dpslp_3_IRQn_Handler,      /*!<  50 [Active] m55appcpuss Inter Process Communication Interrupt #3 */ \
    m55appcpuss_interrupts_ipc_dpslp_4_IRQn_Handler,      /*!<  51 [Active] m55appcpuss Inter Process Communication Interrupt #4 */ \
    m55appcpuss_interrupts_ipc_dpslp_5_IRQn_Handler,      /*!<  52 [Active] m55appcpuss Inter Process Communication Interrupt #5 */ \
    m55appcpuss_interrupts_ipc_dpslp_6_IRQn_Handler,      /*!<  53 [Active] m55appcpuss Inter Process Communication Interrupt #6 */ \
    m55appcpuss_interrupts_ipc_dpslp_7_IRQn_Handler,      /*!<  54 [Active] m55appcpuss Inter Process Communication Interrupt #7 */ \
    mxnnlite_interrupt_mxnnlite_IRQn_Handler,             /*!<  55 [Active] Interrupt of MXNNLITE */ \
    m55appcpuss_interrupt_cm55_0_fp_IRQn_Handler,         /*!<  56 [Active] CM33 0 Floating Point Interrupt */ \
    m55appcpuss_interrupts_cm55_0_cti_0_IRQn_Handler,     /*!<  57 [Active]  */ \
    m55appcpuss_interrupts_cm55_0_cti_1_IRQn_Handler,     /*!<  58 [Active]  */ \
    m55appcpuss_interrupt_msc_IRQn_Handler,               /*!<  59 [Active]  */ \
    m33syscpuss_interrupts_dw0_0_IRQn_Handler,            /*!<  60 [Active] cpuss[0] DataWire #0, Channel #0 */ \
    m33syscpuss_interrupts_dw0_1_IRQn_Handler,            /*!<  61 [Active] cpuss[0] DataWire #0, Channel #1 */ \
    m33syscpuss_interrupts_dw0_2_IRQn_Handler,            /*!<  62 [Active] cpuss[0] DataWire #0, Channel #2 */ \
    m33syscpuss_interrupts_dw0_3_IRQn_Handler,            /*!<  63 [Active] cpuss[0] DataWire #0, Channel #3 */ \
    m33syscpuss_interrupts_dw0_4_IRQn_Handler,            /*!<  64 [Active] cpuss[0] DataWire #0, Channel #4 */ \
    m33syscpuss_interrupts_dw0_5_IRQn_Handler,            /*!<  65 [Active] cpuss[0] DataWire #0, Channel #5 */ \
    m33syscpuss_interrupts_dw0_6_IRQn_Handler,            /*!<  66 [Active] cpuss[0] DataWire #0, Channel #6 */ \
    m33syscpuss_interrupts_dw0_7_IRQn_Handler,            /*!<  67 [Active] cpuss[0] DataWire #0, Channel #7 */ \
    m33syscpuss_interrupts_dw0_8_IRQn_Handler,            /*!<  68 [Active] cpuss[0] DataWire #0, Channel #8 */ \
    m33syscpuss_interrupts_dw0_9_IRQn_Handler,            /*!<  69 [Active] cpuss[0] DataWire #0, Channel #9 */ \
    m33syscpuss_interrupts_dw0_10_IRQn_Handler,           /*!<  70 [Active] cpuss[0] DataWire #0, Channel #10 */ \
    m33syscpuss_interrupts_dw0_11_IRQn_Handler,           /*!<  71 [Active] cpuss[0] DataWire #0, Channel #11 */ \
    m33syscpuss_interrupts_dw0_12_IRQn_Handler,           /*!<  72 [Active] cpuss[0] DataWire #0, Channel #12 */ \
    m33syscpuss_interrupts_dw0_13_IRQn_Handler,           /*!<  73 [Active] cpuss[0] DataWire #0, Channel #13 */ \
    m33syscpuss_interrupts_dw0_14_IRQn_Handler,           /*!<  74 [Active] cpuss[0] DataWire #0, Channel #14 */ \
    m33syscpuss_interrupts_dw0_15_IRQn_Handler,           /*!<  75 [Active] cpuss[0] DataWire #0, Channel #15 */ \
    m55appcpuss_interrupts_axidmac_0_IRQn_Handler,        /*!<  76 [Active]  */ \
    m55appcpuss_interrupts_axidmac_1_IRQn_Handler,        /*!<  77 [Active]  */ \
    m55appcpuss_interrupts_axidmac_2_IRQn_Handler,        /*!<  78 [Active]  */ \
    m55appcpuss_interrupts_axidmac_3_IRQn_Handler,        /*!<  79 [Active]  */ \
    smif_0_smif0_interrupt_nsec_IRQn_Handler,             /*!<  80 [Active] SMIF0 Port0 non-secure interrupt */ \
    smif_0_smif0_interrupt_sec_IRQn_Handler,              /*!<  81 [Active] SMIF0 Port0 secure interrupt */ \
    smif_1_smif0_interrupt_nsec_IRQn_Handler,             /*!<  82 [Active] SMIF1 Port0 non-secure interrupt */ \
    smif_1_smif0_interrupt_sec_IRQn_Handler,              /*!<  83 [Active] SMIF1 Port0 secure interrupt */ \
    canfd_0_interrupts0_0_IRQn_Handler,                   /*!<  84 [Active] CAN #0, Interrupt0, Channel#0 */ \
    canfd_0_interrupts1_0_IRQn_Handler,                   /*!<  85 [Active] CAN #0, Interrupt1, Channel#0 */ \
    canfd_0_interrupts0_1_IRQn_Handler,                   /*!<  86 [Active] CAN #0, Interrupt0, Channel#1 */ \
    canfd_0_interrupts1_1_IRQn_Handler,                   /*!<  87 [Active] CAN #0, Interrupt1, Channel#1 */ \
    tcpwm_0_interrupts_0_IRQn_Handler,                    /*!<  88 [Active] TCPWM, 32-bit Counter #0 */ \
    tcpwm_0_interrupts_1_IRQn_Handler,                    /*!<  89 [Active] TCPWM, 32-bit Counter #1 */ \
    tcpwm_0_interrupts_2_IRQn_Handler,                    /*!<  90 [Active] TCPWM, 32-bit Counter #2 */ \
    tcpwm_0_interrupts_3_IRQn_Handler,                    /*!<  91 [Active] TCPWM, 32-bit Counter #3 */ \
    tcpwm_0_interrupts_4_IRQn_Handler,                    /*!<  92 [Active] TCPWM, 32-bit Counter #4 */ \
    tcpwm_0_interrupts_5_IRQn_Handler,                    /*!<  93 [Active] TCPWM, 32-bit Counter #5 */ \
    tcpwm_0_interrupts_6_IRQn_Handler,                    /*!<  94 [Active] TCPWM, 32-bit Counter #6 */ \
    tcpwm_0_interrupts_7_IRQn_Handler,                    /*!<  95 [Active] TCPWM, 32-bit Counter #7 */ \
    tcpwm_0_interrupts_256_IRQn_Handler,                  /*!<  96 [Active] TCPWM, 16-bit Counter #0 */ \
    tcpwm_0_interrupts_257_IRQn_Handler,                  /*!<  97 [Active] TCPWM, 16-bit Counter #1 */ \
    tcpwm_0_interrupts_258_IRQn_Handler,                  /*!<  98 [Active] TCPWM, 16-bit Counter #2 */ \
    tcpwm_0_interrupts_259_IRQn_Handler,                  /*!<  99 [Active] TCPWM, 16-bit Counter #3 */ \
    tcpwm_0_interrupts_260_IRQn_Handler,                  /*!< 100 [Active] TCPWM, 16-bit Counter #4 */ \
    tcpwm_0_interrupts_261_IRQn_Handler,                  /*!< 101 [Active] TCPWM, 16-bit Counter #5 */ \
    tcpwm_0_interrupts_262_IRQn_Handler,                  /*!< 102 [Active] TCPWM, 16-bit Counter #6 */ \
    tcpwm_0_interrupts_263_IRQn_Handler,                  /*!< 103 [Active] TCPWM, 16-bit Counter #7 */ \
    tcpwm_0_interrupts_264_IRQn_Handler,                  /*!< 104 [Active] TCPWM, 16-bit Counter #8 */ \
    tcpwm_0_interrupts_265_IRQn_Handler,                  /*!< 105 [Active] TCPWM, 16-bit Counter #9 */ \
    tcpwm_0_interrupts_266_IRQn_Handler,                  /*!< 106 [Active] TCPWM, 16-bit Counter #10 */ \
    tcpwm_0_interrupts_267_IRQn_Handler,                  /*!< 107 [Active] TCPWM, 16-bit Counter #11 */ \
    tcpwm_0_interrupts_268_IRQn_Handler,                  /*!< 108 [Active] TCPWM, 16-bit Counter #12 */ \
    tcpwm_0_interrupts_269_IRQn_Handler,                  /*!< 109 [Active] TCPWM, 16-bit Counter #13 */ \
    tcpwm_0_interrupts_270_IRQn_Handler,                  /*!< 110 [Active] TCPWM, 16-bit Counter #14 */ \
    tcpwm_0_interrupts_271_IRQn_Handler,                  /*!< 111 [Active] TCPWM, 16-bit Counter #15 */ \
    tcpwm_0_interrupts_272_IRQn_Handler,                  /*!< 112 [Active] TCPWM, 16-bit Counter #16 */ \
    tcpwm_0_interrupts_273_IRQn_Handler,                  /*!< 113 [Active] TCPWM, 16-bit Counter #17 */ \
    tcpwm_0_interrupts_274_IRQn_Handler,                  /*!< 114 [Active] TCPWM, 16-bit Counter #18 */ \
    tcpwm_0_interrupts_275_IRQn_Handler,                  /*!< 115 [Active] TCPWM, 16-bit Counter #19 */ \
    tcpwm_0_interrupts_276_IRQn_Handler,                  /*!< 116 [Active] TCPWM, 16-bit Counter #20 */ \
    tcpwm_0_interrupts_277_IRQn_Handler,                  /*!< 117 [Active] TCPWM, 16-bit Counter #21 */ \
    tcpwm_0_interrupts_278_IRQn_Handler,                  /*!< 118 [Active] TCPWM, 16-bit Counter #22 */ \
    tcpwm_0_interrupts_279_IRQn_Handler,                  /*!< 119 [Active] TCPWM, 16-bit Counter #23 */ \
    scb_1_interrupt_IRQn_Handler,                         /*!< 120 [Active] SCB#1 Interrupt */ \
    scb_2_interrupt_IRQn_Handler,                         /*!< 121 [Active] SCB#2 Interrupt */ \
    scb_3_interrupt_IRQn_Handler,                         /*!< 122 [Active] SCB#3 Interrupt */ \
    scb_4_interrupt_IRQn_Handler,                         /*!< 123 [Active] SCB#4 Interrupt */ \
    scb_5_interrupt_IRQn_Handler,                         /*!< 124 [Active] SCB#5 Interrupt */ \
    scb_6_interrupt_IRQn_Handler,                         /*!< 125 [Active] SCB#6 Interrupt */ \
    scb_7_interrupt_IRQn_Handler,                         /*!< 126 [Active] SCB#7 Interrupt */ \
    scb_8_interrupt_IRQn_Handler,                         /*!< 127 [Active] SCB#8 Interrupt */ \
    scb_9_interrupt_IRQn_Handler,                         /*!< 128 [Active] SCB#9 Interrupt */ \
    scb_10_interrupt_IRQn_Handler,                        /*!< 129 [Active] SCB#10 Interrupt */ \
    scb_11_interrupt_IRQn_Handler,                        /*!< 130 [Active] SCB#11 Interrupt */ \
    sdhc_0_interrupt_general_IRQn_Handler,                /*!< 131 [Active] SDHC0 */ \
    sdhc_0_interrupt_wakeup_IRQn_Handler,                 /*!< 132 [Active] SDHC0 */ \
    sdhc_1_interrupt_general_IRQn_Handler,                /*!< 133 [Active] SDHC1 */ \
    sdhc_1_interrupt_wakeup_IRQn_Handler,                 /*!< 134 [Active] SDHC1 */ \
    tdm_0_interrupts_rx_0_IRQn_Handler,                   /*!< 135 [Active] TDM0 Audio interrupt RX Structure#0 */ \
    tdm_0_interrupts_tx_0_IRQn_Handler,                   /*!< 136 [Active] TDM0 Audio interrupt TX Structure#0 */ \
    tdm_0_interrupts_rx_1_IRQn_Handler,                   /*!< 137 [Active] TDM0 Audio interrupt RX Structure#1 */ \
    tdm_0_interrupts_tx_1_IRQn_Handler,                   /*!< 138 [Active] TDM0 Audio interrupt TX Structure#1 */ \
    gfxss_interrupt_gpu_IRQn_Handler,                     /*!< 139 [Active] Interrupt from GPU. */ \
    gfxss_interrupt_dc_IRQn_Handler,                      /*!< 140 [Active] Interrupt from DC. */ \
    gfxss_interrupt_mipidsi_IRQn_Handler,                 /*!< 141 [Active] Interrupt from MIPIDSI. */ \
    pdm_0_interrupts_0_IRQn_Handler,                      /*!< 142 [Active] PDM interrupt Structure#0 */ \
    pdm_0_interrupts_1_IRQn_Handler,                      /*!< 143 [Active] PDM interrupt Structure#1 */ \
    pdm_0_interrupts_2_IRQn_Handler,                      /*!< 144 [Active] PDM interrupt Structure#2 */ \
    pdm_0_interrupts_3_IRQn_Handler,                      /*!< 145 [Active] PDM interrupt Structure#3 */ \
    pdm_0_interrupts_4_IRQn_Handler,                      /*!< 146 [Active] PDM interrupt Structure#4 */ \
    pdm_0_interrupts_5_IRQn_Handler,                      /*!< 147 [Active] PDM interrupt Structure#5 */ \
    eth_interrupt_eth_0_IRQn_Handler,                     /*!< 148 [Active] ETH Interrupt#0 */ \
    eth_interrupt_eth_1_IRQn_Handler,                     /*!< 149 [Active] ETH Interrupt#1 */ \
    eth_interrupt_eth_2_IRQn_Handler,                     /*!< 150 [Active] ETH Interrupt#2 */ \
    usbhs_interrupt_usbhsctrl_IRQn_Handler,               /*!< 151 [Active] Interrupt of Controller core */ \
    usbhs_interrupt_usbhsss_IRQn_Handler,                 /*!< 152 [Active] Interrupt of Subsystem */ \
    i3c_interrupt_IRQn_Handler,                           /*!< 153 [Active] I3C Interrupt */ \
    crypto_interrupt_IRQn_Handler,                        /*!< 154 [Active] Crypto Interrupt */ \
    m33syscpuss_interrupts_fault_0_IRQn_Handler,          /*!< 155 [Active]  */ \
    m33syscpuss_interrupts_fault_1_IRQn_Handler,          /*!< 156 [Active]  */ \
    m55appcpuss_interrupt_ahb2axi_buff_err_IRQn_Handler,  /*!< 157 [Active] Interrupt from xhb500 ahb to axi bridge */ \
    m33syscpuss_interrupts_dw1_0_IRQn_Handler,            /*!< 158 [Active] cpuss[0] DataWire #1, Channel #0 */ \
    m33syscpuss_interrupts_dw1_1_IRQn_Handler,            /*!< 159 [Active] cpuss[0] DataWire #1, Channel #1 */ \
    m33syscpuss_interrupts_dw1_2_IRQn_Handler,            /*!< 160 [Active] cpuss[0] DataWire #1, Channel #2 */ \
    m33syscpuss_interrupts_dw1_3_IRQn_Handler,            /*!< 161 [Active] cpuss[0] DataWire #1, Channel #3 */ \
    m33syscpuss_interrupts_dw1_4_IRQn_Handler,            /*!< 162 [Active] cpuss[0] DataWire #1, Channel #4 */ \
    m33syscpuss_interrupts_dw1_5_IRQn_Handler,            /*!< 163 [Active] cpuss[0] DataWire #1, Channel #5 */ \
    m33syscpuss_interrupts_dw1_6_IRQn_Handler,            /*!< 164 [Active] cpuss[0] DataWire #1, Channel #6 */ \
    m33syscpuss_interrupts_dw1_7_IRQn_Handler,            /*!< 165 [Active] cpuss[0] DataWire #1, Channel #7 */ \
    m33syscpuss_interrupts_dw1_8_IRQn_Handler,            /*!< 166 [Active] cpuss[0] DataWire #1, Channel #8 */ \
    m33syscpuss_interrupts_dw1_9_IRQn_Handler,            /*!< 167 [Active] cpuss[0] DataWire #1, Channel #9 */ \
    m33syscpuss_interrupts_dw1_10_IRQn_Handler,           /*!< 168 [Active] cpuss[0] DataWire #1, Channel #10 */ \
    m33syscpuss_interrupts_dw1_11_IRQn_Handler,           /*!< 169 [Active] cpuss[0] DataWire #1, Channel #11 */ \
    m33syscpuss_interrupts_dw1_12_IRQn_Handler,           /*!< 170 [Active] cpuss[0] DataWire #1, Channel #12 */ \
    m33syscpuss_interrupts_dw1_13_IRQn_Handler,           /*!< 171 [Active] cpuss[0] DataWire #1, Channel #13 */ \
    m33syscpuss_interrupts_dw1_14_IRQn_Handler,           /*!< 172 [Active] cpuss[0] DataWire #1, Channel #14 */ \
    m33syscpuss_interrupts_dw1_15_IRQn_Handler,           /*!< 173 [Active] cpuss[0] DataWire #1, Channel #15 */

#else
    #error "This file should only be used for CM33 or CM55 cores"
#endif /* (IFX_CORE == IFX_CM33) */

#endif /* PSE84_CORE_INTERRUPTS_H */
