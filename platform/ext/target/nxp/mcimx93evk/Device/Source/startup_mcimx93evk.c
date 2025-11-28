/*
 * Copyright (c) 2022 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * This file is derivative of CMSIS V5.9.0 startup_ARMCM33.c
 * Git SHA: 2b7495b8535bdcb306dac29b9ded4cfb679d7e5c
 */

/* NS linker scripts using the default CMSIS style naming conventions, while the
 * secure and bl2 linker scripts remain untouched (region.h compatibility).
 * To be compatible with the untouched files (which using ARMCLANG naming style),
 * we have to override __INITIAL_SP and __STACK_LIMIT labels. */
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
#include "cmsis_override.h"
#endif

#include "cmsis.h"

/*----------------------------------------------------------------------------
  External References
 *----------------------------------------------------------------------------*/
extern uint32_t __INITIAL_SP;
extern uint32_t __STACK_LIMIT;
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
extern uint64_t __STACK_SEAL;
#endif

typedef void(*VECTOR_TABLE_Type)(void);

extern __NO_RETURN void __PROGRAM_START(void);

/*----------------------------------------------------------------------------
  Internal References
 *----------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler(void);

/*----------------------------------------------------------------------------
  Exception / Interrupt Handler
 *----------------------------------------------------------------------------*/
#define DEFAULT_IRQ_HANDLER(handler_name)  \
__NO_RETURN void __WEAK handler_name(void); \
void handler_name(void) { \
    while(1); \
}

/* Exceptions */
DEFAULT_IRQ_HANDLER(NMI_Handler)
DEFAULT_IRQ_HANDLER(HardFault_Handler)
DEFAULT_IRQ_HANDLER(MemManage_Handler)
DEFAULT_IRQ_HANDLER(BusFault_Handler)
DEFAULT_IRQ_HANDLER(UsageFault_Handler)
DEFAULT_IRQ_HANDLER(SecureFault_Handler)
DEFAULT_IRQ_HANDLER(SVC_Handler)
DEFAULT_IRQ_HANDLER(DebugMon_Handler)
DEFAULT_IRQ_HANDLER(PendSV_Handler)
DEFAULT_IRQ_HANDLER(SysTick_Handler)

/* Driver Exceptions */
DEFAULT_IRQ_HANDLER(Reserved16_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved17_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved18_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved19_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved20_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved21_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved22_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved23_IRQHandler)
DEFAULT_IRQ_HANDLER(CAN1_IRQHandler)
DEFAULT_IRQ_HANDLER(CAN1_ERROR_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved26_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved27_IRQHandler)
DEFAULT_IRQ_HANDLER(I3C1_IRQHandler)
DEFAULT_IRQ_HANDLER(LPI2C1_IRQHandler)
DEFAULT_IRQ_HANDLER(LPI2C2_IRQHandler)
DEFAULT_IRQ_HANDLER(LPIT1_IRQHandler)
DEFAULT_IRQ_HANDLER(LPSPI1_IRQHandler)
DEFAULT_IRQ_HANDLER(LPSPI2_IRQHandler)
DEFAULT_IRQ_HANDLER(LPTMR1_IRQHandler)
DEFAULT_IRQ_HANDLER(LPUART1_IRQHandler)
DEFAULT_IRQ_HANDLER(LPUART2_IRQHandler)
DEFAULT_IRQ_HANDLER(MU1_A_IRQHandler)
DEFAULT_IRQ_HANDLER(MU1_B_IRQHandler)
DEFAULT_IRQ_HANDLER(MU2_A_IRQHandler)
DEFAULT_IRQ_HANDLER(MU2_B_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved41_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved42_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved43_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved44_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved45_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved46_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved47_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved48_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved49_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved50_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved51_IRQHandler)
DEFAULT_IRQ_HANDLER(TPM1_IRQHandler)
DEFAULT_IRQ_HANDLER(TPM2_IRQHandler)
DEFAULT_IRQ_HANDLER(WDOG1_IRQHandler)
DEFAULT_IRQ_HANDLER(WDOG2_IRQHandler)
DEFAULT_IRQ_HANDLER(TRDC_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved57_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved58_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved59_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved60_IRQHandler)
DEFAULT_IRQ_HANDLER(SAI1_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved62_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved63_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved64_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved65_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved66_IRQHandler)
DEFAULT_IRQ_HANDLER(CAN2_IRQHandler)
DEFAULT_IRQ_HANDLER(CAN2_ERROR_IRQHandler)
DEFAULT_IRQ_HANDLER(FLEXIO1_IRQHandler)
DEFAULT_IRQ_HANDLER(FLEXIO2_IRQHandler)
DEFAULT_IRQ_HANDLER(FlexSPI1_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved72_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved73_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved74_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved75_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved76_IRQHandler)
DEFAULT_IRQ_HANDLER(I3C2_IRQHandler)
DEFAULT_IRQ_HANDLER(LPI2C3_IRQHandler)
DEFAULT_IRQ_HANDLER(LPI2C4_IRQHandler)
DEFAULT_IRQ_HANDLER(LPIT2_IRQHandler)
DEFAULT_IRQ_HANDLER(LPSPI3_IRQHandler)
DEFAULT_IRQ_HANDLER(LPSPI4_IRQHandler)
DEFAULT_IRQ_HANDLER(LPTMR2_IRQHandler)
DEFAULT_IRQ_HANDLER(LPUART3_IRQHandler)
DEFAULT_IRQ_HANDLER(LPUART4_IRQHandler)
DEFAULT_IRQ_HANDLER(LPUART5_IRQHandler)
DEFAULT_IRQ_HANDLER(LPUART6_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved88_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved89_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved90_IRQHandler)
DEFAULT_IRQ_HANDLER(TPM3_IRQHandler)
DEFAULT_IRQ_HANDLER(TPM4_IRQHandler)
DEFAULT_IRQ_HANDLER(TPM5_IRQHandler)
DEFAULT_IRQ_HANDLER(TPM6_IRQHandler)
DEFAULT_IRQ_HANDLER(WDOG3_IRQHandler)
DEFAULT_IRQ_HANDLER(WDOG4_IRQHandler)
DEFAULT_IRQ_HANDLER(WDOG5_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved98_IRQHandler)
DEFAULT_IRQ_HANDLER(TEMPMON_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved100_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved101_IRQHandler)
DEFAULT_IRQ_HANDLER(uSDHC1_IRQHandler)
DEFAULT_IRQ_HANDLER(uSDHC2_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved104_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved105_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved106_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved107_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved108_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved109_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_ERROR_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_0_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_1_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_2_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_3_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_4_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_5_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_6_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_7_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_8_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_9_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_10_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_11_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_12_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_13_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_14_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_15_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_16_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_17_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_18_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_19_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_20_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_21_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_22_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_23_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_24_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_25_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_26_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_27_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_28_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_29_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA3_30_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved142_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_ERROR_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_0_1_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_2_3_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_4_5_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_6_7_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_8_9_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_10_11_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_12_13_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_14_15_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_16_17_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_18_19_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_20_21_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_22_23_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_24_25_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_26_27_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_28_29_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_30_31_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_32_33_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_34_35_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_36_37_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_38_39_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_40_41_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_42_43_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_44_45_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_46_47_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_48_49_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_50_51_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_52_53_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_54_55_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_56_57_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_58_59_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_60_61_IRQHandler)
DEFAULT_IRQ_HANDLER(DMA4_62_63_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved176_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved177_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved178_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved179_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved180_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved181_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved182_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved183_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved184_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved185_IRQHandler)
DEFAULT_IRQ_HANDLER(SAI2_IRQHandler)
DEFAULT_IRQ_HANDLER(SAI3_IRQHandler)
DEFAULT_IRQ_HANDLER(ISI_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved189_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved190_IRQHandler)
DEFAULT_IRQ_HANDLER(CSI_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved192_IRQHandler)
DEFAULT_IRQ_HANDLER(DSI_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved194_IRQHandler)
DEFAULT_IRQ_HANDLER(ENET_MAC0_Rx_Tx_Done1_IRQHandler)
DEFAULT_IRQ_HANDLER(ENET_MAC0_Rx_Tx_Done2_IRQHandler)
DEFAULT_IRQ_HANDLER(ENET_IRQHandler)
DEFAULT_IRQ_HANDLER(ENET_1588_IRQHandler)
DEFAULT_IRQ_HANDLER(ENET_QOS_PMT_IRQHandler)
DEFAULT_IRQ_HANDLER(ENET_QOS_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved201_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved202_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved203_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved204_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved205_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved206_IRQHandler)
DEFAULT_IRQ_HANDLER(LPSPI5_IRQHandler)
DEFAULT_IRQ_HANDLER(LPSPI6_IRQHandler)
DEFAULT_IRQ_HANDLER(LPSPI7_IRQHandler)
DEFAULT_IRQ_HANDLER(LPSPI8_IRQHandler)
DEFAULT_IRQ_HANDLER(LPI2C5_IRQHandler)
DEFAULT_IRQ_HANDLER(LPI2C6_IRQHandler)
DEFAULT_IRQ_HANDLER(LPI2C7_IRQHandler)
DEFAULT_IRQ_HANDLER(LPI2C8_IRQHandler)
DEFAULT_IRQ_HANDLER(PDM_HWVAD_ERROR_IRQHandler)
DEFAULT_IRQ_HANDLER(PDM_HWVAD_EVENT_IRQHandler)
DEFAULT_IRQ_HANDLER(PDM_ERROR_IRQHandler)
DEFAULT_IRQ_HANDLER(PDM_EVENT_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved219_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved220_IRQHandler)
DEFAULT_IRQ_HANDLER(uSDHC3_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved222_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved223_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved224_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved225_IRQHandler)
DEFAULT_IRQ_HANDLER(LPUART7_IRQHandler)
DEFAULT_IRQ_HANDLER(LPUART8_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved228_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved229_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved230_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved231_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved232_IRQHandler)
DEFAULT_IRQ_HANDLER(ADC_ER_IRQHandler)
DEFAULT_IRQ_HANDLER(ADC_WD_IRQHandler)
DEFAULT_IRQ_HANDLER(ADC_EOC_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved236_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved237_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved238_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved239_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved240_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved241_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved242_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved243_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved244_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved245_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved246_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved247_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved248_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved249_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved250_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved251_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved252_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved253_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved254_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved255_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved256_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved257_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved258_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved259_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved260_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved261_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved262_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved263_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved264_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved265_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved266_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved267_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved268_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved269_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved270_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved271_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved272_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved273_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved274_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved275_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved276_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved277_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved278_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved279_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved280_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved281_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved282_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved283_IRQHandler)
DEFAULT_IRQ_HANDLER(Reserved284_IRQHandler)


/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined ( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

extern const VECTOR_TABLE_Type __VECTOR_TABLE[];
       const VECTOR_TABLE_Type __VECTOR_TABLE[] __VECTOR_TABLE_ATTRIBUTE = {
  (VECTOR_TABLE_Type)(&__INITIAL_SP),            /*      Initial Stack Pointer */
  Reset_Handler,                     /* Reset Handler */
  NMI_Handler,                       /* NMI Handler*/
  HardFault_Handler,                 /* Hard Fault Handler*/
  MemManage_Handler,                 /* MPU Fault Handler*/
  BusFault_Handler,                  /* Bus Fault Handler*/
  UsageFault_Handler,                /* Usage Fault Handler*/
  SecureFault_Handler,               /* Secure Fault Handler */
  0,                                 /* Reserved*/
  0,                                 /* Reserved*/
  0,                                 /* Reserved*/
  SVC_Handler,                       /* SVCall Handler*/
  DebugMon_Handler,                  /* Debug Monitor Handler*/
  0,                                 /* Reserved*/
  PendSV_Handler,                    /* PendSV Handler*/
  SysTick_Handler,                   /* SysTick Handler*/

  /* External Interrupts*/
  Reserved16_IRQHandler,
  Reserved17_IRQHandler,
  Reserved18_IRQHandler,
  Reserved19_IRQHandler,
  Reserved20_IRQHandler,
  Reserved21_IRQHandler,
  Reserved22_IRQHandler,
  Reserved23_IRQHandler,
  CAN1_IRQHandler,
  CAN1_ERROR_IRQHandler,
  Reserved26_IRQHandler,
  Reserved27_IRQHandler,
  I3C1_IRQHandler,
  LPI2C1_IRQHandler,
  LPI2C2_IRQHandler,
  LPIT1_IRQHandler,
  LPSPI1_IRQHandler,
  LPSPI2_IRQHandler,
  LPTMR1_IRQHandler,
  LPUART1_IRQHandler,
  LPUART2_IRQHandler,
  MU1_A_IRQHandler,
  MU1_B_IRQHandler,
  MU2_A_IRQHandler,
  MU2_B_IRQHandler,
  Reserved41_IRQHandler,
  Reserved42_IRQHandler,
  Reserved43_IRQHandler,
  Reserved44_IRQHandler,
  Reserved45_IRQHandler,
  Reserved46_IRQHandler,
  Reserved47_IRQHandler,
  Reserved48_IRQHandler,
  Reserved49_IRQHandler,
  Reserved50_IRQHandler,
  Reserved51_IRQHandler,
  TPM1_IRQHandler,
  TPM2_IRQHandler,
  WDOG1_IRQHandler,
  WDOG2_IRQHandler,
  TRDC_IRQHandler,
  Reserved57_IRQHandler,
  Reserved58_IRQHandler,
  Reserved59_IRQHandler,
  Reserved60_IRQHandler,
  SAI1_IRQHandler,
  Reserved62_IRQHandler,
  Reserved63_IRQHandler,
  Reserved64_IRQHandler,
  Reserved65_IRQHandler,
  Reserved66_IRQHandler,
  CAN2_IRQHandler,
  CAN2_ERROR_IRQHandler,
  FLEXIO1_IRQHandler,
  FLEXIO2_IRQHandler,
  FlexSPI1_IRQHandler,
  Reserved72_IRQHandler,
  Reserved73_IRQHandler,
  Reserved74_IRQHandler,
  Reserved75_IRQHandler,
  Reserved76_IRQHandler,
  I3C2_IRQHandler,
  LPI2C3_IRQHandler,
  LPI2C4_IRQHandler,
  LPIT2_IRQHandler,
  LPSPI3_IRQHandler,
  LPSPI4_IRQHandler,
  LPTMR2_IRQHandler,
  LPUART3_IRQHandler,
  LPUART4_IRQHandler,
  LPUART5_IRQHandler,
  LPUART6_IRQHandler,
  Reserved88_IRQHandler,
  Reserved89_IRQHandler,
  Reserved90_IRQHandler,
  TPM3_IRQHandler,
  TPM4_IRQHandler,
  TPM5_IRQHandler,
  TPM6_IRQHandler,
  WDOG3_IRQHandler,
  WDOG4_IRQHandler,
  WDOG5_IRQHandler,
  Reserved98_IRQHandler,
  TEMPMON_IRQHandler,
  Reserved100_IRQHandler,
  Reserved101_IRQHandler,
  uSDHC1_IRQHandler,
  uSDHC2_IRQHandler,
  Reserved104_IRQHandler,
  Reserved105_IRQHandler,
  Reserved106_IRQHandler,
  Reserved107_IRQHandler,
  Reserved108_IRQHandler,
  Reserved109_IRQHandler,
  DMA3_ERROR_IRQHandler,
  DMA3_0_IRQHandler,
  DMA3_1_IRQHandler,
  DMA3_2_IRQHandler,
  DMA3_3_IRQHandler,
  DMA3_4_IRQHandler,
  DMA3_5_IRQHandler,
  DMA3_6_IRQHandler,
  DMA3_7_IRQHandler,
  DMA3_8_IRQHandler,
  DMA3_9_IRQHandler,
  DMA3_10_IRQHandler,
  DMA3_11_IRQHandler,
  DMA3_12_IRQHandler,
  DMA3_13_IRQHandler,
  DMA3_14_IRQHandler,
  DMA3_15_IRQHandler,
  DMA3_16_IRQHandler,
  DMA3_17_IRQHandler,
  DMA3_18_IRQHandler,
  DMA3_19_IRQHandler,
  DMA3_20_IRQHandler,
  DMA3_21_IRQHandler,
  DMA3_22_IRQHandler,
  DMA3_23_IRQHandler,
  DMA3_24_IRQHandler,
  DMA3_25_IRQHandler,
  DMA3_26_IRQHandler,
  DMA3_27_IRQHandler,
  DMA3_28_IRQHandler,
  DMA3_29_IRQHandler,
  DMA3_30_IRQHandler,
  Reserved142_IRQHandler,
  DMA4_ERROR_IRQHandler,
  DMA4_0_1_IRQHandler,
  DMA4_2_3_IRQHandler,
  DMA4_4_5_IRQHandler,
  DMA4_6_7_IRQHandler,
  DMA4_8_9_IRQHandler,
  DMA4_10_11_IRQHandler,
  DMA4_12_13_IRQHandler,
  DMA4_14_15_IRQHandler,
  DMA4_16_17_IRQHandler,
  DMA4_18_19_IRQHandler,
  DMA4_20_21_IRQHandler,
  DMA4_22_23_IRQHandler,
  DMA4_24_25_IRQHandler,
  DMA4_26_27_IRQHandler,
  DMA4_28_29_IRQHandler,
  DMA4_30_31_IRQHandler,
  DMA4_32_33_IRQHandler,
  DMA4_34_35_IRQHandler,
  DMA4_36_37_IRQHandler,
  DMA4_38_39_IRQHandler,
  DMA4_40_41_IRQHandler,
  DMA4_42_43_IRQHandler,
  DMA4_44_45_IRQHandler,
  DMA4_46_47_IRQHandler,
  DMA4_48_49_IRQHandler,
  DMA4_50_51_IRQHandler,
  DMA4_52_53_IRQHandler,
  DMA4_54_55_IRQHandler,
  DMA4_56_57_IRQHandler,
  DMA4_58_59_IRQHandler,
  DMA4_60_61_IRQHandler,
  DMA4_62_63_IRQHandler,
  Reserved176_IRQHandler,
  Reserved177_IRQHandler,
  Reserved178_IRQHandler,
  Reserved179_IRQHandler,
  Reserved180_IRQHandler,
  Reserved181_IRQHandler,
  Reserved182_IRQHandler,
  Reserved183_IRQHandler,
  Reserved184_IRQHandler,
  Reserved185_IRQHandler,
  SAI2_IRQHandler,
  SAI3_IRQHandler,
  ISI_IRQHandler,
  Reserved189_IRQHandler,
  Reserved190_IRQHandler,
  CSI_IRQHandler,
  Reserved192_IRQHandler,
  DSI_IRQHandler,
  Reserved194_IRQHandler,
  ENET_MAC0_Rx_Tx_Done1_IRQHandler,
  ENET_MAC0_Rx_Tx_Done2_IRQHandler,
  ENET_IRQHandler,
  ENET_1588_IRQHandler,
  ENET_QOS_PMT_IRQHandler,
  ENET_QOS_IRQHandler,
  Reserved201_IRQHandler,
  Reserved202_IRQHandler,
  Reserved203_IRQHandler,
  Reserved204_IRQHandler,
  Reserved205_IRQHandler,
  Reserved206_IRQHandler,
  LPSPI5_IRQHandler,
  LPSPI6_IRQHandler,
  LPSPI7_IRQHandler,
  LPSPI8_IRQHandler,
  LPI2C5_IRQHandler,
  LPI2C6_IRQHandler,
  LPI2C7_IRQHandler,
  LPI2C8_IRQHandler,
  PDM_HWVAD_ERROR_IRQHandler,
  PDM_HWVAD_EVENT_IRQHandler,
  PDM_ERROR_IRQHandler,
  PDM_EVENT_IRQHandler,
  Reserved219_IRQHandler,
  Reserved220_IRQHandler,
  uSDHC3_IRQHandler,
  Reserved222_IRQHandler,
  Reserved223_IRQHandler,
  Reserved224_IRQHandler,
  Reserved225_IRQHandler,
  LPUART7_IRQHandler,
  LPUART8_IRQHandler,
  Reserved228_IRQHandler,
  Reserved229_IRQHandler,
  Reserved230_IRQHandler,
  Reserved231_IRQHandler,
  Reserved232_IRQHandler,
  ADC_ER_IRQHandler,
  ADC_WD_IRQHandler,
  ADC_EOC_IRQHandler,
  Reserved236_IRQHandler,
  Reserved237_IRQHandler,
  Reserved238_IRQHandler,
  Reserved239_IRQHandler,
  Reserved240_IRQHandler,
  Reserved241_IRQHandler,
  Reserved242_IRQHandler,
  Reserved243_IRQHandler,
  Reserved244_IRQHandler,
  Reserved245_IRQHandler,
  Reserved246_IRQHandler,
  Reserved247_IRQHandler,
  Reserved248_IRQHandler,
  Reserved249_IRQHandler,
  Reserved250_IRQHandler,
  Reserved251_IRQHandler,
  Reserved252_IRQHandler,
  Reserved253_IRQHandler,
  Reserved254_IRQHandler,
  Reserved255_IRQHandler,
  Reserved256_IRQHandler,
  Reserved257_IRQHandler,
  Reserved258_IRQHandler,
  Reserved259_IRQHandler,
  Reserved260_IRQHandler,
  Reserved261_IRQHandler,
  Reserved262_IRQHandler,
  Reserved263_IRQHandler,
  Reserved264_IRQHandler,
  Reserved265_IRQHandler,
  Reserved266_IRQHandler,
  Reserved267_IRQHandler,
  Reserved268_IRQHandler,
  Reserved269_IRQHandler,
  Reserved270_IRQHandler,
  Reserved271_IRQHandler,
  Reserved272_IRQHandler,
  Reserved273_IRQHandler,
  Reserved274_IRQHandler,
  Reserved275_IRQHandler,
  Reserved276_IRQHandler,
  Reserved277_IRQHandler,
  Reserved278_IRQHandler,
  Reserved279_IRQHandler,
  Reserved280_IRQHandler,
  Reserved281_IRQHandler,
  Reserved282_IRQHandler,
  Reserved283_IRQHandler,
  Reserved284_IRQHandler
};

#if defined ( __GNUC__ )
#pragma GCC diagnostic pop
#endif

/*----------------------------------------------------------------------------
  Reset Handler called on controller reset
 *----------------------------------------------------------------------------*/

void Reset_Handler(void)
{
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    __disable_irq();
#endif
    __set_PSP((uint32_t)(&__INITIAL_SP));

    __set_MSPLIM((uint32_t)(&__STACK_LIMIT));
    __set_PSPLIM((uint32_t)(&__STACK_LIMIT));

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    __TZ_set_STACKSEAL_S((uint32_t *)(&__STACK_SEAL));
#endif

    SystemInit();                             /* CMSIS System Initialization */
    __PROGRAM_START();                        /* Enter PreMain (C library entry point) */
}
