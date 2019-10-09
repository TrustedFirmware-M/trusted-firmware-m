;/*
; * Copyright (c) 2017-2018 ARM Limited
; * Copyright (c) 2019, Cypress Semiconductor Corporation. All rights reserved.
; *
; * Licensed under the Apache License, Version 2.0 (the "License");
; * you may not use this file except in compliance with the License.
; * You may obtain a copy of the License at
; *
; *     http://www.apache.org/licenses/LICENSE-2.0
; *
; * Unless required by applicable law or agreed to in writing, software
; * distributed under the License is distributed on an "AS IS" BASIS,
; * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
; * See the License for the specific language governing permissions and
; * limitations under the License.
; */
;
; This file is derivative of CMSIS V5.01 startup_ARMv8MML.s
; Git SHA: 8a1d9d6ee18b143ae5befefa14d89fb5b3f99c75

;/*
;//-------- <<< Use Configuration Wizard in Context Menu >>> ------------------
;*/


; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

; Address of the NMI handler in ROM
CY_NMI_HANLDER_ADDR    EQU    0x0000000D

                IMPORT |Image$$ARM_LIB_STACK$$ZI$$Limit|

; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size
                EXPORT  __ramVectors

__Vectors       ;Core Interrupts
                DCD     |Image$$ARM_LIB_STACK$$ZI$$Limit|  ; Top of Stack
                DCD     Reset_Handler             ; Reset Handler
                DCD     CY_NMI_HANLDER_ADDR       ; NMI Handler
                DCD     HardFault_Handler         ; Hard Fault Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV Handler
                DCD     SysTick_Handler           ; SysTick Handler

                ; External interrupts               Description
                DCD     NvicMux0_IRQHandler       ; CM0+ NVIC Mux input 0
                DCD     NvicMux1_IRQHandler       ; CM0+ NVIC Mux input 1
                DCD     NvicMux2_IRQHandler       ; CM0+ NVIC Mux input 2
                DCD     NvicMux3_IRQHandler       ; CM0+ NVIC Mux input 3
                DCD     NvicMux4_IRQHandler       ; CM0+ NVIC Mux input 4
                DCD     NvicMux5_IRQHandler       ; CM0+ NVIC Mux input 5
                DCD     NvicMux6_IRQHandler       ; CM0+ NVIC Mux input 6
                DCD     NvicMux7_IRQHandler       ; CM0+ NVIC Mux input 7
                DCD     NvicMux8_IRQHandler       ; CM0+ NVIC Mux input 8
                DCD     NvicMux9_IRQHandler       ; CM0+ NVIC Mux input 9
                DCD     NvicMux10_IRQHandler      ; CM0+ NVIC Mux input 10
                DCD     NvicMux11_IRQHandler      ; CM0+ NVIC Mux input 11
                DCD     NvicMux12_IRQHandler      ; CM0+ NVIC Mux input 12
                DCD     NvicMux13_IRQHandler      ; CM0+ NVIC Mux input 13
                DCD     NvicMux14_IRQHandler      ; CM0+ NVIC Mux input 14
                DCD     NvicMux15_IRQHandler      ; CM0+ NVIC Mux input 15
                DCD     NvicMux16_IRQHandler      ; CM0+ NVIC Mux input 16
                DCD     NvicMux17_IRQHandler      ; CM0+ NVIC Mux input 17
                DCD     NvicMux18_IRQHandler      ; CM0+ NVIC Mux input 18
                DCD     NvicMux19_IRQHandler      ; CM0+ NVIC Mux input 19
                DCD     NvicMux20_IRQHandler      ; CM0+ NVIC Mux input 20
                DCD     NvicMux21_IRQHandler      ; CM0+ NVIC Mux input 21
                DCD     NvicMux22_IRQHandler      ; CM0+ NVIC Mux input 22
                DCD     NvicMux23_IRQHandler      ; CM0+ NVIC Mux input 23
                DCD     NvicMux24_IRQHandler      ; CM0+ NVIC Mux input 24
                DCD     NvicMux25_IRQHandler      ; CM0+ NVIC Mux input 25
                DCD     NvicMux26_IRQHandler      ; CM0+ NVIC Mux input 26
                DCD     NvicMux27_IRQHandler      ; CM0+ NVIC Mux input 27
                DCD     NvicMux28_IRQHandler      ; CM0+ NVIC Mux input 28
                DCD     NvicMux29_IRQHandler      ; CM0+ NVIC Mux input 29
                DCD     NvicMux30_IRQHandler      ; CM0+ NVIC Mux input 30
                DCD     NvicMux31_IRQHandler      ; CM0+ NVIC Mux input 31


__Vectors_End

__Vectors_Size  EQU     __Vectors_End - __Vectors

                AREA    RESET_RAM, READWRITE, NOINIT
__ramVectors
                SPACE   __Vectors_Size


; Reset Handler
                AREA    |.text|, CODE, READONLY
Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  SystemInit
                IMPORT  __main
                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__main
                BX      R0
                ENDP
End_Of_Main
                B       .


; Dummy Exception Handlers (infinite loops which can be modified)
                MACRO
                Default_Handler $handler_name
$handler_name   PROC
                EXPORT  $handler_name             [WEAK]
                B       .
                ENDP
                MEND

                Default_Handler HardFault_Handler
                Default_Handler SVC_Handler
                Default_Handler PendSV_Handler
                Default_Handler SysTick_Handler
                Default_Handler NvicMux0_IRQHandler
                Default_Handler NvicMux1_IRQHandler
                Default_Handler NvicMux2_IRQHandler
                Default_Handler NvicMux3_IRQHandler
                Default_Handler NvicMux4_IRQHandler
                Default_Handler NvicMux5_IRQHandler
                Default_Handler NvicMux6_IRQHandler
                Default_Handler NvicMux7_IRQHandler
                Default_Handler NvicMux8_IRQHandler
                Default_Handler NvicMux9_IRQHandler
                Default_Handler NvicMux10_IRQHandler
                Default_Handler NvicMux11_IRQHandler
                Default_Handler NvicMux12_IRQHandler
                Default_Handler NvicMux13_IRQHandler
                Default_Handler NvicMux14_IRQHandler
                Default_Handler NvicMux15_IRQHandler
                Default_Handler NvicMux16_IRQHandler
                Default_Handler NvicMux17_IRQHandler
                Default_Handler NvicMux18_IRQHandler
                Default_Handler NvicMux19_IRQHandler
                Default_Handler NvicMux20_IRQHandler
                Default_Handler NvicMux21_IRQHandler
                Default_Handler NvicMux22_IRQHandler
                Default_Handler NvicMux23_IRQHandler
                Default_Handler NvicMux24_IRQHandler
                Default_Handler NvicMux25_IRQHandler
                Default_Handler NvicMux26_IRQHandler
                Default_Handler NvicMux27_IRQHandler
                Default_Handler NvicMux28_IRQHandler
                Default_Handler NvicMux29_IRQHandler
                Default_Handler NvicMux30_IRQHandler
                Default_Handler NvicMux31_IRQHandler

                ALIGN

                END
