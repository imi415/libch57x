/******************************************************************************
 * @file     startup_<Device>.c
 * @brief    CMSIS-Core(M) Device Startup File for
 *           Device <Device>
 * @version  V1.0.0
 * @date     20. January 2021
 ******************************************************************************/
/*
 * Copyright (c) 2009-2021 Arm Limited. All rights reserved.
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

#include <stdint.h>

#include "ch57x.h"

/*---------------------------------------------------------------------------
  External References
 *---------------------------------------------------------------------------*/
extern uint32_t __INITIAL_SP;
extern uint32_t __STACK_LIMIT;
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
extern uint32_t __STACK_SEAL;
#endif

extern __NO_RETURN void __PROGRAM_START(void);

/*---------------------------------------------------------------------------
  Internal References
 *---------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler  (void);
            void Default_Handler(void);

/* ToDo: Add Cortex exception handler according the used Cortex-Core */
/*---------------------------------------------------------------------------
  Exception / Interrupt Handler
 *---------------------------------------------------------------------------*/
/* Exceptions */
void NMI_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler      (void) __attribute__ ((weak));
void SVC_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler         (void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));
void TMR0_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIO_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void EMSLV_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void SPI0_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void BLE_LLE_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));
void BLE_BB_Handler         (void) __attribute__ ((weak, alias("Default_Handler")));
void USB_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void ETH_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void TMR1_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void TMR2_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void UART0_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void UART1_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void RTC_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void SPI1_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void LEDC_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void TMR3_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void UART2_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void UART3_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void WDOG_BATMON_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));


/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined ( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

/* ToDo: Add Cortex exception vectors according the used Cortex-Core */
extern const VECTOR_TABLE_Type __VECTOR_TABLE[48];
       const VECTOR_TABLE_Type __VECTOR_TABLE[48] __VECTOR_TABLE_ATTRIBUTE = {
  (VECTOR_TABLE_Type)(&__INITIAL_SP),  /*     Initial Stack Pointer */
  Reset_Handler,                       /*     Reset Handler */
  NMI_Handler,                         /* -14 NMI Handler */
  HardFault_Handler,                   /* -13 Hard Fault Handler */
  0,                                   /* -12 MPU Fault Handler */
  0,                                   /* -11 Bus Fault Handler */
  0,                                   /* -10 Usage Fault Handler */
  0,                                   /*  -9 Secure Fault Handler */
  0,                                   /*     Reserved */
  0,                                   /*     Reserved */
  0,                                   /*     Reserved */
  SVC_Handler,                         /*  -5 SVCall Handler */
  0,                                   /*  -4 Debug Monitor Handler */
  0,                                   /*     Reserved */
  PendSV_Handler,                      /*  -2 PendSV Handler */
  SysTick_Handler,                     /*  -1 SysTick Handler */
  TMR0_Handler,                        /*   0 TMR 0 Interrupt */
  GPIO_Handler,                        /*   1 GPIO Interrupt */
  EMSLV_Handler,                       /*   2 EMSLV Interrupt */
  SPI0_Handler,                        /*   3 SPI0 Interrupt */
  BLE_LLE_Handler,                     /*   4 BLE LLE Interrupt */
  BLE_BB_Handler,                      /*   5 BLE BB Interrupt */
  USB_Handler,                         /*   6 USB Interrupt */
  ETH_Handler,                         /*   7 ETH Interrupt */
  TMR1_Handler,                        /*   8 TMR1 Interrupt */
  TMR2_Handler,                        /*   9 TMR2 Interrupt */
  UART0_Handler,                       /*  10 UART0 Interrupt */
  UART1_Handler,                       /*  11 UART1 Interrupt */
  RTC_Handler,                         /*  12 RTC Interrupt */
  ADC_Handler,                         /*  13 ADC Interrupt */
  SPI1_Handler,                        /*  14 SPI1 Interrupt */
  LEDC_Handler,                        /*  15 LEDC Interrupt */
  TMR3_Handler,                        /*  16 TMR3 Interrupt */
  UART2_Handler,                       /*  17 UART2 Interrupt */
  UART3_Handler,                       /*  18 UART3 Interrupt */
  WDOG_BATMON_Handler,                 /*  19 WDOG BATMON Interrupt */
};

#if defined ( __GNUC__ )
#pragma GCC diagnostic pop
#endif

/*---------------------------------------------------------------------------
  Reset Handler called on controller reset
 *---------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler(void)
{
  SystemInit();                    /* CMSIS System Initialization */
  __PROGRAM_START();               /* Enter PreMain (C library entry point) */
}


#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wmissing-noreturn"
#endif

/*---------------------------------------------------------------------------
  Hard Fault Handler
 *---------------------------------------------------------------------------*/
void HardFault_Handler(void)
{
  while(1);
}

/*---------------------------------------------------------------------------
  Default Handler for Exceptions / Interrupts
 *---------------------------------------------------------------------------*/
void Default_Handler(void)
{
  while(1);
}

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic pop
#endif