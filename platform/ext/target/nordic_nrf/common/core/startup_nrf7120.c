/*
 * Copyright (c) 2025 Arm Limited. All rights reserved.
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

/*
 * Define __VECTOR_TABLE_ATTRIBUTE (which can be provided by cmsis.h)
 * before including cmsis.h because TF-M's linker script
 * tfm_common_s.ld assumes the vector table section is called .vectors
 * while cmsis.h will sometimes (e.g. when cmsis is provided by nrfx)
 * default to using the name .isr_vector.
 */
#define __VECTOR_TABLE_ATTRIBUTE  __attribute__((used, section(".vectors")))

#include "cmsis.h"
#include "startup.h"
#include "exception_info.h"

__NO_RETURN __attribute__((naked)) void default_tfm_IRQHandler(void) {
	EXCEPTION_INFO();

	__ASM volatile(
        "BL        default_irq_handler     \n"
        "B         .                       \n"
    );
}

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

DEFAULT_IRQ_HANDLER(SWI00_IRQHandler)
DEFAULT_IRQ_HANDLER(SWI01_IRQHandler)
DEFAULT_IRQ_HANDLER(SWI02_IRQHandler)
DEFAULT_IRQ_HANDLER(SWI03_IRQHandler)
DEFAULT_IRQ_HANDLER(AAR00_CCM00_IRQHandler)
DEFAULT_IRQ_HANDLER(ECB00_IRQHandler)
DEFAULT_IRQ_HANDLER(VPR00_IRQHandler)
DEFAULT_IRQ_HANDLER(SERIAL00_IRQHandler)
DEFAULT_IRQ_HANDLER(MRAMC_IRQHandler)
DEFAULT_IRQ_HANDLER(CTRLAP_IRQHandler)
DEFAULT_IRQ_HANDLER(CM33SS_IRQHandler)
DEFAULT_IRQ_HANDLER(TIMER00_IRQHandler)
DEFAULT_IRQ_HANDLER(EGU00_IRQHandler)
DEFAULT_IRQ_HANDLER(USBHS_IRQHandler)
DEFAULT_IRQ_HANDLER(QSPI00_IRQHandler)
DEFAULT_IRQ_HANDLER(QSPI01_IRQHandler)
DEFAULT_IRQ_HANDLER(SERIAL01_IRQHandler)
DEFAULT_IRQ_HANDLER(BELLBOARD_0_IRQHandler)
DEFAULT_IRQ_HANDLER(BELLBOARD_1_IRQHandler)
DEFAULT_IRQ_HANDLER(TIMER10_IRQHandler)
DEFAULT_IRQ_HANDLER(EGU10_IRQHandler)
DEFAULT_IRQ_HANDLER(RADIO_0_IRQHandler)
DEFAULT_IRQ_HANDLER(RADIO_1_IRQHandler)
DEFAULT_IRQ_HANDLER(IPCT10_0_IRQHandler)
DEFAULT_IRQ_HANDLER(IPCT10_1_IRQHandler)
DEFAULT_IRQ_HANDLER(IPCT10_2_IRQHandler)
DEFAULT_IRQ_HANDLER(IPCT10_3_IRQHandler)
DEFAULT_IRQ_HANDLER(SERIAL20_IRQHandler)
DEFAULT_IRQ_HANDLER(SERIAL21_IRQHandler)
DEFAULT_IRQ_HANDLER(SERIAL22_IRQHandler)
DEFAULT_IRQ_HANDLER(EGU20_IRQHandler)
DEFAULT_IRQ_HANDLER(TIMER20_IRQHandler)
DEFAULT_IRQ_HANDLER(TIMER21_IRQHandler)
DEFAULT_IRQ_HANDLER(TIMER22_IRQHandler)
DEFAULT_IRQ_HANDLER(TIMER23_IRQHandler)
DEFAULT_IRQ_HANDLER(TIMER24_IRQHandler)
DEFAULT_IRQ_HANDLER(PDM20_IRQHandler)
DEFAULT_IRQ_HANDLER(PDM21_IRQHandler)
DEFAULT_IRQ_HANDLER(PWM20_IRQHandler)
DEFAULT_IRQ_HANDLER(PWM21_IRQHandler)
DEFAULT_IRQ_HANDLER(PWM22_IRQHandler)
DEFAULT_IRQ_HANDLER(SAADC_IRQHandler)
DEFAULT_IRQ_HANDLER(NFCT_IRQHandler)
DEFAULT_IRQ_HANDLER(TEMP_IRQHandler)
DEFAULT_IRQ_HANDLER(GPIOTE20_0_IRQHandler)
DEFAULT_IRQ_HANDLER(GPIOTE20_1_IRQHandler)
DEFAULT_IRQ_HANDLER(QDEC20_IRQHandler)
DEFAULT_IRQ_HANDLER(QDEC21_IRQHandler)
DEFAULT_IRQ_HANDLER(GRTC_0_IRQHandler)
DEFAULT_IRQ_HANDLER(GRTC_1_IRQHandler)
DEFAULT_IRQ_HANDLER(GRTC_2_IRQHandler)
DEFAULT_IRQ_HANDLER(GRTC_3_IRQHandler)
DEFAULT_IRQ_HANDLER(GRTC_4_IRQHandler)
DEFAULT_IRQ_HANDLER(GRTC_5_IRQHandler)
DEFAULT_IRQ_HANDLER(TDM_IRQHandler)
DEFAULT_IRQ_HANDLER(SERIAL23_IRQHandler)
DEFAULT_IRQ_HANDLER(SERIAL24_IRQHandler)
DEFAULT_IRQ_HANDLER(TAMPC_IRQHandler)
DEFAULT_IRQ_HANDLER(SERIAL30_IRQHandler)
DEFAULT_IRQ_HANDLER(COMP_LPCOMP_IRQHandler)
DEFAULT_IRQ_HANDLER(WDT30_IRQHandler)
DEFAULT_IRQ_HANDLER(WDT31_IRQHandler)
DEFAULT_IRQ_HANDLER(GPIOTE30_0_IRQHandler)
DEFAULT_IRQ_HANDLER(GPIOTE30_1_IRQHandler)
DEFAULT_IRQ_HANDLER(CLOCK_POWER_IRQHandler)
DEFAULT_IRQ_HANDLER(VREGUSB_IRQHandler)
DEFAULT_IRQ_HANDLER(LFXO_IRQHandler)
DEFAULT_IRQ_HANDLER(LFRC_IRQHandler)
DEFAULT_IRQ_HANDLER(HFXO64M_IRQHandler)
DEFAULT_IRQ_HANDLER(VREGMRAM_IRQHandler)
DEFAULT_IRQ_HANDLER(VREGVBAT1V8_IRQHandler)
DEFAULT_IRQ_HANDLER(LDOHLP0V8_IRQHandler)
DEFAULT_IRQ_HANDLER(LDOBUCK0V8_IRQHandler)
DEFAULT_IRQ_HANDLER(VDETAO1V8_IRQHandler)
DEFAULT_IRQ_HANDLER(VDETAO0V8_IRQHandler)
DEFAULT_IRQ_HANDLER(HVBUCK_IRQHandler)
DEFAULT_IRQ_HANDLER(AUDIOPLL_AUDIOPLLM_IRQHandler)

#if defined(DOMAIN_NS) || defined(BL2)
DEFAULT_IRQ_HANDLER(MPC00_IRQHandler)
DEFAULT_IRQ_HANDLER(SPU00_IRQHandler)
DEFAULT_IRQ_HANDLER(SPU10_IRQHandler)
DEFAULT_IRQ_HANDLER(SPU20_IRQHandler)
DEFAULT_IRQ_HANDLER(SPU30_IRQHandler)
DEFAULT_IRQ_HANDLER(CRACEN_IRQHandler)
#endif

#if defined ( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

const VECTOR_TABLE_Type __VECTOR_TABLE[] __VECTOR_TABLE_ATTRIBUTE = {
  (VECTOR_TABLE_Type)(&__INITIAL_SP),     /*      Initial Stack Pointer */
/* Exceptions */
    Reset_Handler,
    NMI_Handler,
    HardFault_Handler,
    MemManage_Handler,           /* MPU Fault Handler */
    BusFault_Handler,
    UsageFault_Handler,
    SecureFault_Handler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    SVC_Handler,
    DebugMon_Handler,
    default_tfm_IRQHandler,
    PendSV_Handler,
    SysTick_Handler,
/* Device specific interrupt handlers */
    default_tfm_IRQHandler,        // 0
    default_tfm_IRQHandler,        // 1
    default_tfm_IRQHandler,        // 2
    default_tfm_IRQHandler,        // 3
    default_tfm_IRQHandler,        // 4
    default_tfm_IRQHandler,        // 5
    default_tfm_IRQHandler,        // 6
    default_tfm_IRQHandler,        // 7
    default_tfm_IRQHandler,        // 8
    default_tfm_IRQHandler,        // 9
    default_tfm_IRQHandler,        // 10
    default_tfm_IRQHandler,        // 11
    default_tfm_IRQHandler,        // 12
    default_tfm_IRQHandler,        // 13
    default_tfm_IRQHandler,        // 14
    default_tfm_IRQHandler,        // 15
    default_tfm_IRQHandler,        // 16
    default_tfm_IRQHandler,        // 17
    default_tfm_IRQHandler,        // 18
    default_tfm_IRQHandler,        // 19
    default_tfm_IRQHandler,        // 20
    default_tfm_IRQHandler,        // 21
    default_tfm_IRQHandler,        // 22
    default_tfm_IRQHandler,        // 23
    default_tfm_IRQHandler,        // 24
    default_tfm_IRQHandler,        // 25
    default_tfm_IRQHandler,        // 26
    default_tfm_IRQHandler,        // 27
    SWI00_IRQHandler,              // 28
    SWI01_IRQHandler,              // 29
    SWI02_IRQHandler,              // 30
    SWI03_IRQHandler,              // 31
    default_tfm_IRQHandler,        // 32
    default_tfm_IRQHandler,        // 33
    default_tfm_IRQHandler,        // 34
    default_tfm_IRQHandler,        // 35
    default_tfm_IRQHandler,        // 36
    default_tfm_IRQHandler,        // 37
    default_tfm_IRQHandler,        // 38
    default_tfm_IRQHandler,        // 39
    default_tfm_IRQHandler,        // 40
    default_tfm_IRQHandler,        // 41
    default_tfm_IRQHandler,        // 42
    default_tfm_IRQHandler,        // 43
    default_tfm_IRQHandler,        // 44
    default_tfm_IRQHandler,        // 45
    default_tfm_IRQHandler,        // 46
    default_tfm_IRQHandler,        // 47
    default_tfm_IRQHandler,        // 48
    default_tfm_IRQHandler,        // 49
    default_tfm_IRQHandler,        // 50
    default_tfm_IRQHandler,        // 51
    default_tfm_IRQHandler,        // 52
    default_tfm_IRQHandler,        // 53
    default_tfm_IRQHandler,        // 54
    default_tfm_IRQHandler,        // 55
    default_tfm_IRQHandler,        // 56
    default_tfm_IRQHandler,        // 57
    default_tfm_IRQHandler,        // 58
    default_tfm_IRQHandler,        // 59
    default_tfm_IRQHandler,        // 60
    default_tfm_IRQHandler,        // 61
    default_tfm_IRQHandler,        // 62
    default_tfm_IRQHandler,        // 63
    SPU00_IRQHandler,              // 64
    MPC00_IRQHandler,              // 65
    default_tfm_IRQHandler,        // 66
    default_tfm_IRQHandler,        // 67
    default_tfm_IRQHandler,        // 68
    default_tfm_IRQHandler,        // 69
    default_tfm_IRQHandler,        // 70
    default_tfm_IRQHandler,        // 71
    default_tfm_IRQHandler,        // 72
    default_tfm_IRQHandler,        // 73
    AAR00_CCM00_IRQHandler,        // 74
    ECB00_IRQHandler,              // 75
    VPR00_IRQHandler,              // 76
    SERIAL00_IRQHandler,           // 77
    MRAMC_IRQHandler,              // 78
    default_tfm_IRQHandler,        // 79
    default_tfm_IRQHandler,        // 80
    default_tfm_IRQHandler,        // 81
    CTRLAP_IRQHandler,             // 82
    default_tfm_IRQHandler,        // 83
    CM33SS_IRQHandler,             // 84
    TIMER00_IRQHandler,            // 85
    default_tfm_IRQHandler,        // 86
    default_tfm_IRQHandler,        // 87
    EGU00_IRQHandler,              // 88
    CRACEN_IRQHandler,             // 89
    USBHS_IRQHandler,              // 90
    QSPI00_IRQHandler,             // 91
    QSPI01_IRQHandler,             // 92
    SERIAL01_IRQHandler,           // 93
    default_tfm_IRQHandler,        // 94
    default_tfm_IRQHandler,        // 95
    default_tfm_IRQHandler,        // 96
    default_tfm_IRQHandler,        // 97
    default_tfm_IRQHandler,        // 98
    default_tfm_IRQHandler,        // 99
    default_tfm_IRQHandler,        // 100
    default_tfm_IRQHandler,        // 101
    default_tfm_IRQHandler,        // 102
    default_tfm_IRQHandler,        // 103
    default_tfm_IRQHandler,        // 104
    default_tfm_IRQHandler,        // 105
    default_tfm_IRQHandler,        // 106
    default_tfm_IRQHandler,        // 107
    default_tfm_IRQHandler,        // 108
    default_tfm_IRQHandler,        // 109
    default_tfm_IRQHandler,        // 110
    default_tfm_IRQHandler,        // 111
    default_tfm_IRQHandler,        // 112
    default_tfm_IRQHandler,        // 113
    default_tfm_IRQHandler,        // 114
    default_tfm_IRQHandler,        // 115
    default_tfm_IRQHandler,        // 116
    default_tfm_IRQHandler,        // 117
    default_tfm_IRQHandler,        // 118
    default_tfm_IRQHandler,        // 119
    BELLBOARD_0_IRQHandler,        // 120
    BELLBOARD_1_IRQHandler,        // 121
    default_tfm_IRQHandler,        // 122
    default_tfm_IRQHandler,        // 123
    default_tfm_IRQHandler,        // 124
    default_tfm_IRQHandler,        // 125
    default_tfm_IRQHandler,        // 126
    default_tfm_IRQHandler,        // 127
    SPU10_IRQHandler,              // 128
    default_tfm_IRQHandler,        // 129
    default_tfm_IRQHandler,        // 130
    default_tfm_IRQHandler,        // 131
    default_tfm_IRQHandler,        // 132
    TIMER10_IRQHandler,            // 133
    default_tfm_IRQHandler,        // 134
    EGU10_IRQHandler,              // 135
    default_tfm_IRQHandler,        // 136
    default_tfm_IRQHandler,        // 137
    RADIO_0_IRQHandler,            // 138
    RADIO_1_IRQHandler,            // 139
    default_tfm_IRQHandler,        // 140
    IPCT10_0_IRQHandler,           // 141
    IPCT10_1_IRQHandler,           // 142
    IPCT10_2_IRQHandler,           // 143
    IPCT10_3_IRQHandler,           // 144
    default_tfm_IRQHandler,        // 145
    default_tfm_IRQHandler,        // 146
    default_tfm_IRQHandler,        // 147
    default_tfm_IRQHandler,        // 148
    default_tfm_IRQHandler,        // 149
    default_tfm_IRQHandler,        // 150
    default_tfm_IRQHandler,        // 151
    default_tfm_IRQHandler,        // 152
    default_tfm_IRQHandler,        // 153
    default_tfm_IRQHandler,        // 154
    default_tfm_IRQHandler,        // 155
    default_tfm_IRQHandler,        // 156
    default_tfm_IRQHandler,        // 157
    default_tfm_IRQHandler,        // 158
    default_tfm_IRQHandler,        // 159
    default_tfm_IRQHandler,        // 160
    default_tfm_IRQHandler,        // 161
    default_tfm_IRQHandler,        // 162
    default_tfm_IRQHandler,        // 163
    default_tfm_IRQHandler,        // 164
    default_tfm_IRQHandler,        // 165
    default_tfm_IRQHandler,        // 166
    default_tfm_IRQHandler,        // 167
    default_tfm_IRQHandler,        // 168
    default_tfm_IRQHandler,        // 169
    default_tfm_IRQHandler,        // 170
    default_tfm_IRQHandler,        // 171
    default_tfm_IRQHandler,        // 172
    default_tfm_IRQHandler,        // 173
    default_tfm_IRQHandler,        // 174
    default_tfm_IRQHandler,        // 175
    default_tfm_IRQHandler,        // 176
    default_tfm_IRQHandler,        // 177
    default_tfm_IRQHandler,        // 178
    default_tfm_IRQHandler,        // 179
    default_tfm_IRQHandler,        // 180
    default_tfm_IRQHandler,        // 181
    default_tfm_IRQHandler,        // 182
    default_tfm_IRQHandler,        // 183
    default_tfm_IRQHandler,        // 184
    default_tfm_IRQHandler,        // 185
    default_tfm_IRQHandler,        // 186
    default_tfm_IRQHandler,        // 187
    default_tfm_IRQHandler,        // 188
    default_tfm_IRQHandler,        // 189
    default_tfm_IRQHandler,        // 190
    default_tfm_IRQHandler,        // 191
    SPU20_IRQHandler,              // 192
    default_tfm_IRQHandler,        // 193
    default_tfm_IRQHandler,        // 194
    default_tfm_IRQHandler,        // 195
    default_tfm_IRQHandler,        // 196
    default_tfm_IRQHandler,        // 197
    SERIAL20_IRQHandler,           // 198
    SERIAL21_IRQHandler,           // 199
    SERIAL22_IRQHandler,           // 200
    EGU20_IRQHandler,              // 201
    TIMER20_IRQHandler,            // 202
    TIMER21_IRQHandler,            // 203
    TIMER22_IRQHandler,            // 204
    TIMER23_IRQHandler,            // 205
    TIMER24_IRQHandler,            // 206
    default_tfm_IRQHandler,        // 207
    PDM20_IRQHandler,              // 208
    PDM21_IRQHandler,              // 209
    PWM20_IRQHandler,              // 210
    PWM21_IRQHandler,              // 211
    PWM22_IRQHandler,              // 212
    SAADC_IRQHandler,              // 213
    NFCT_IRQHandler,               // 214
    TEMP_IRQHandler,               // 215
    default_tfm_IRQHandler,        // 216
    default_tfm_IRQHandler,        // 217
    GPIOTE20_0_IRQHandler,         // 218
    GPIOTE20_1_IRQHandler,         // 219
    default_tfm_IRQHandler,        // 220
    default_tfm_IRQHandler,        // 221
    default_tfm_IRQHandler,        // 222
    default_tfm_IRQHandler,        // 223
    QDEC20_IRQHandler,             // 224
    QDEC21_IRQHandler,             // 225
    GRTC_0_IRQHandler,             // 226
    GRTC_1_IRQHandler,             // 227
    GRTC_2_IRQHandler,             // 228
    GRTC_3_IRQHandler,             // 229
    GRTC_4_IRQHandler,             // 230
    GRTC_5_IRQHandler,             // 231
    TDM_IRQHandler,                // 232
    default_tfm_IRQHandler,        // 233
    default_tfm_IRQHandler,        // 234
    default_tfm_IRQHandler,        // 235
    default_tfm_IRQHandler,        // 236
    SERIAL23_IRQHandler,           // 237
    SERIAL24_IRQHandler,           // 238
    TAMPC_IRQHandler,              // 239
    default_tfm_IRQHandler,        // 240
    default_tfm_IRQHandler,        // 241
    default_tfm_IRQHandler,        // 242
    default_tfm_IRQHandler,        // 243
    default_tfm_IRQHandler,        // 244
    default_tfm_IRQHandler,        // 245
    default_tfm_IRQHandler,        // 246
    default_tfm_IRQHandler,        // 247
    default_tfm_IRQHandler,        // 248
    default_tfm_IRQHandler,        // 249
    default_tfm_IRQHandler,        // 250
    default_tfm_IRQHandler,        // 251
    default_tfm_IRQHandler,        // 252
    default_tfm_IRQHandler,        // 253
    default_tfm_IRQHandler,        // 254
    default_tfm_IRQHandler,        // 255
    SPU30_IRQHandler,              // 256
    default_tfm_IRQHandler,        // 257
    default_tfm_IRQHandler,        // 258
    default_tfm_IRQHandler,        // 259
    SERIAL30_IRQHandler,           // 260
    default_tfm_IRQHandler,        // 261
    COMP_LPCOMP_IRQHandler,        // 262
    default_tfm_IRQHandler,        // 263
    WDT30_IRQHandler,              // 264
    WDT31_IRQHandler,              // 265
    default_tfm_IRQHandler,        // 266
    default_tfm_IRQHandler,        // 267
    GPIOTE30_0_IRQHandler,         // 268
    GPIOTE30_1_IRQHandler,         // 269
    CLOCK_POWER_IRQHandler,        // 270
    default_tfm_IRQHandler,        // 271
    default_tfm_IRQHandler,        // 272
    default_tfm_IRQHandler,        // 273
    default_tfm_IRQHandler,        // 274
    default_tfm_IRQHandler,        // 275
    default_tfm_IRQHandler,        // 276
    default_tfm_IRQHandler,        // 277
    default_tfm_IRQHandler,        // 278
    default_tfm_IRQHandler,        // 279
    default_tfm_IRQHandler,        // 280
    default_tfm_IRQHandler,        // 281
    default_tfm_IRQHandler,        // 282
    default_tfm_IRQHandler,        // 283
    default_tfm_IRQHandler,        // 284
    default_tfm_IRQHandler,        // 285
    default_tfm_IRQHandler,        // 286
    default_tfm_IRQHandler,        // 287
    default_tfm_IRQHandler,        // 288
    VREGUSB_IRQHandler,            // 289
    LFXO_IRQHandler,               // 290
    LFRC_IRQHandler,               // 291
    HFXO64M_IRQHandler,            // 292
    VREGMRAM_IRQHandler,           // 293
    VREGVBAT1V8_IRQHandler,        // 294
    LDOHLP0V8_IRQHandler,          // 295
    LDOBUCK0V8_IRQHandler,         // 296
    default_tfm_IRQHandler,        // 297
    default_tfm_IRQHandler,        // 298
    VDETAO1V8_IRQHandler,          // 299
    VDETAO0V8_IRQHandler,          // 300
    HVBUCK_IRQHandler,             // 301
    default_tfm_IRQHandler,        // 302
    default_tfm_IRQHandler,        // 303
    AUDIOPLL_AUDIOPLLM_IRQHandler, // 304
};

#if defined ( __GNUC__ )
#pragma GCC diagnostic pop
#endif