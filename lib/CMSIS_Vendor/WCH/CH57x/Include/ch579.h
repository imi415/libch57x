/**
 * @file ch579.h
 * @author imi415 (imi415.public@gmail.com)
 * @brief CMSIS CH579 Device Peripheral Access Layer Header File
 * @version 0.1
 * @date 2021-10-27
 * 
 * @copyright Copyright (c) 2021 imi415
 * 
 */

#ifndef CH579_H
#define CH579_H

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================= */
/* ============           Interrupt Number Definition           ============ */
/* ========================================================================= */

typedef enum IRQn{
/* ================     Cortex-M Core Exception Numbers     ================ */
    Reset_IRQn                 = -15,
    NonMaskableInt_IRQn        = -14,
    HardFault_IRQn             = -13,
    SVCall_IRQn                = -5,
    PendSV_IRQn                = -2,
    SysTick_IRQn               = -1,

/* ================        CH579 Interrupt Numbers       ================ */
    TMR0_IRQn                  = 0,
    GPIO_IRQn                  = 1,
    EMSlave_IRQn               = 2,
    SPI0_IRQn                  = 3,
    BLE_LLE_IRQn               = 4,
    BLE_BB_IRQn                = 5,
    USB_IRQn                   = 6,
    ETH_IRQn                   = 7,
    TMR1_IRQn                  = 8,
    TMR2_IRQn                  = 9,
    UART0_IRQn                 = 10,
    UART1_IRQn                 = 11,
    RTC_IRQn                   = 12,
    ADC_IRQn                   = 13,
    SPI1_IRQn                  = 14,
    LEDC_IRQn                  = 15,
    TMR3_IRQn                  = 16,
    UART2_IRQn                 = 17,
    UART3_IRQn                 = 18,
    WDOG_BATMON_IRQn           = 19,
} IRQn_Type;

/* ========================================================================= */
/* ============      Processor and Core Peripheral Section      ============ */
/* ========================================================================= */

/* ================ Start of section using anonymous unions ================ */
#if   defined (__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined (__ICCARM__)
  #pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wc11-extensions"
  #pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning 586
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif

/* ================    Configuration of Core Peripherals    ================ */
#define __CM0_REV               0x0000U  /* Core Revision r0p0 */

#define __Vendor_SysTickConfig  0U       /* Set to 1 if different SysTick Config is used */
#define __NVIC_PRIO_BITS        2U       /* Number of Bits used for Priority Levels */

#include "core_cm0.h"
#include "system_ch57x.h"

/* ========================================================================= */
/* ============       Device Specific Peripheral Section        ============ */
/* ========================================================================= */

typedef struct {
    __IOM uint8_t  CHANNEL;
    __IOM uint8_t  CONFIG;
    __IOM uint8_t  CONVERT;
    __IOM uint8_t  TEMCONFIG;
    __IM  uint16_t DATA;
    __IOM uint8_t  INTFLAG;
} CH57x_ADC_TypeDef;

/* CH57x_ADC CHANNEL Register Definitions */
#define CH57x_ADC_CHANNEL_INX_Pos       0
#define CH57x_ADC_CHANNEL_INX_Msk       (0xFUL) /*<< CH57x_ADC_CHANNEL_INX_Pos */

/* CH57x_ADC CONFIG Register Definitions */
#define CH57x_ADC_CONFIG_POWER_ON_Pos   0
#define CH57x_ADC_CONFIG_POWER_ON_Msk   (1UL << CH57x_ADC_CONFIG_POWER_ON_Pos)

#define CH57x_ADC_CONFIG_BUF_EN_Pos     1
#define CH57x_ADC_CONFIG_BUF_EN_Msk     (1UL << CH57x_ADC_CONFIG_BUF_EN_Pos)

#define CH57x_ADC_CONFIG_DIFF_EN_Pos    2
#define CH57x_ADC_CONFIG_DIFF_EN_Msk    (1UL << CH57x_ADC_CONFIG_DIFF_EN_Pos)

#define CH57x_ADC_CONFIG_OFS_TEST_Pos   3
#define CH57x_ADC_CONFIG_OFS_TEST_Msk   (1UL << CH57x_ADC_CONFIG_OFS_TEST_Pos)

#define CH57x_ADC_CONFIG_PGA_GAIN_Pos   4
#define CH57x_ADC_CONFIG_PGA_GAIN_Msk   (3UL << CH57x_ADC_CONFIG_PGA_GAIN_Pos)

#define CH57x_ADC_CONFIG_CLK_DIV_Pos    6
#define CH57x_ADC_CONFIG_CLK_DIV_Msk    (3UL << CH57x_ADC_CONFIG_CLK_DIV_Pos)

/* CH57x_ADC_CONVERT Register Definitions */
#define CH57x_ADC_CONVERT_START_Pos         0
#define CH57x_ADC_CONVERT_START_Msk         (1UL) /* << CH57x_ADC_CONVERT_START_Pos */

#define CH57x_ADC_CONVERT_TKEY_POWER_ON_Pos 3
#define CH57x_ADC_CONVERT_TKEY_POWER_ON_Msk (1UL << CH57x_ADC_CONVERT_TKEY_POWER_ON_Pos)

#define CH57x_ADC_CONVERT_TKEY_ACTION_Pos   4
#define CH57x_ADC_CONVERT_TKEY_ACTION_Msk   (1UL << CH57x_ADC_CONVERT_TKEY_ACTION_Pos)

#define CH57x_ADC_CONVERT_TKEY_CHG_ACT_Pos  5
#define CH57x_ADC_CONVERT_TKEY_CHG_ACT_Msk  (1UL << CH57x_ADC_CONVERT_TKEY_CHG_ACT_Pos)

#define CH57x_ADC_CONVERT_EOC_X_Pos         7
#define CH57x_ADC_CONVERT_EOC_X_Msk         (1UL << CH57x_ADC_CONVERT_EOC_X_Pos)

/* CH57x_ADC TEMCONFIG Register Definition */
#define CH57x_ADC_TEMCONFIG_CALIB_Pos       0
#define CH57x_ADC_TEMCONFIG_CALIB_Msk       (7UL) /* << CH57x_TEMCONFIG_CALIB_Pos */

#define CH57x_ADC_TEMCONFIG_PWR_ON_Pos      7
#define CH57x_ADC_TEMCONFIG_PWR_ON_Msk      (1UL << CH57x_ADC_TEMCONFIG_PWR_ON_Pos)

/* CH57x_ADC DATA Register Definition */
#define CH57x_ADC_DATA_Pos                  0
#define CH57x_ADC_DATA_Msk                  (0xFFFUL) /* << CH57x_ADC_DATA_Pos */

/* CH57x_ADC INTFLAG Register Difinition */
#define CH57x_ADC_INTFLAG_EOC_Pos           7
#define CH57x_ADC_INTFLAG_EOC_Msk           (1UL << CH57x_ADC_INTFLAG_EOC_Pos)

/* ================  End of section using anonymous unions  ================ */
#if   defined (__CC_ARM)
  #pragma pop
#elif defined (__ICCARM__)
  /* leave anonymous unions enabled */
#elif (defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050))
  #pragma clang diagnostic pop
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning restore
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif

/* ========================================================================= */
/* ============     Device Specific Peripheral Address Map      ============ */
/* ========================================================================= */

/* Peripheral and SRAM base address */
#define CH57x_FLASH_BASE                (0x00000000U)
#define CH57x_SRAM_BASE                 (0x20000000U)
#define CH57x_PERIPH_BASE               (0x40000000U)

/* Peripheral memory map */
#define CH57x_ADC_BASE                  (CH57x_PERIPH_BASE + 0x1058)    /* ADC Base Address */
/* ToDo: Add more peripherals */

#ifdef __cplusplus
}
#endif

#endif // CH579_H