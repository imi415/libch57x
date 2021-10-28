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

typedef enum IRQn {
    /* ================   Cortex-M Core Exception Numbers     ================*/
    Reset_IRQn          = -15,
    NonMaskableInt_IRQn = -14,
    HardFault_IRQn      = -13,
    SVCall_IRQn         = -5,
    PendSV_IRQn         = -2,
    SysTick_IRQn        = -1,

    /* ================        CH579 Interrupt Numbers       ================ */
    TMR0_IRQn           = 0,
    GPIO_IRQn           = 1,
    EMSlave_IRQn        = 2,
    SPI0_IRQn           = 3,
    BLE_LLE_IRQn        = 4,
    BLE_BB_IRQn         = 5,
    USB_IRQn            = 6,
    ETH_IRQn            = 7,
    TMR1_IRQn           = 8,
    TMR2_IRQn           = 9,
    UART0_IRQn          = 10,
    UART1_IRQn          = 11,
    RTC_IRQn            = 12,
    ADC_IRQn            = 13,
    SPI1_IRQn           = 14,
    LEDC_IRQn           = 15,
    TMR3_IRQn           = 16,
    UART2_IRQn          = 17,
    UART3_IRQn          = 18,
    WDOG_BATMON_IRQn    = 19,
} IRQn_Type;

/* ========================================================================= */
/* ============      Processor and Core Peripheral Section      ============ */
/* ========================================================================= */

/* ================ Start of section using anonymous unions ================ */
#if defined(__CC_ARM)
    #pragma push
    #pragma anon_unions
#elif defined(__ICCARM__)
    #pragma language = extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wc11-extensions"
    #pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined(__GNUC__)
/* anonymous unions are enabled by default */
#elif defined(__TMS470__)
/* anonymous unions are enabled by default */
#elif defined(__TASKING__)
    #pragma warning 586
#elif defined(__CSMC__)
/* anonymous unions are enabled by default */
#else
    #warning Not supported compiler type
#endif

/* ================    Configuration of Core Peripherals    ================ */
#define __CM0_REV              0x0000U /* Core Revision r0p0 */

#define __Vendor_SysTickConfig 0U /* Set to 1 if different SysTick Config is used */
#define __NVIC_PRIO_BITS       2U /* Number of Bits used for Priority Levels */

#include "core_cm0.h"
#include "system_ch57x.h"

/* ========================================================================= */
/* ============       Device Specific Peripheral Section        ============ */
/* ========================================================================= */

/* ================                SYS/AUX                  ================ */
typedef __PACKED_STRUCT {
    uint32_t       UNUSED0[2];      /* 0x000 - 0x007 */
    __IOM uint16_t CLK_SYS_CFG;     /* Offset: 0x008 (R/W ) System Clock Configuration Register */
    __IOM uint8_t  HFCK_PWR_CTRL;   /* Offset: 0x00A (R/W ) HF Clock Power Control Register */
    uint8_t        UNUSED1;         /* 0x00B */
    __IOM uint16_t SLP_CLK_OFF;     /* Offset: 0x00C (R/W ) Sleep Mode Clock Control Register */
    __IOM uint8_t  SLP_WAKE_CTRL;   /* Offset: 0x00E (R/W ) Sleep Mode Wakeup Event Control Register */
    __IOM uint8_t  SLP_POWER_CTRL;  /* Offset: 0x00F (R/W ) Sleep Mode Power Control Register */
    uint32_t       UNUSED2[2];      /* 0x010 - 0x017 */
    __IOM uint16_t PIN_ALTERNATE;   /* Offset: 0x018 (R/W ) Pin Alternative Function Control Register */
    __IOM uint16_t PIN_ANALOG_IE;   /* Offset: 0x01A (R/W ) Pin Analog Input Configuration Register */
    __IOM uint8_t  SLV_CONFIG;      /* Offset: 0x01C (R/W ) Passive Parallel Port Configuration Register */
    uint8_t        UNUSED3[3];      /* 0x1D - 0x1F */
    __IOM uint16_t POWER_PLAN;      /* Offset: 0x020 (R/W ) Sleep Mode Power Management Register */
    __IOM uint8_t  AUX_POWER_ADJ;   /* Offset: 0x022 (R/W ) AUX Power Adjustment Register */
    uint8_t        UNUSED4;         /* 0x23 */
    __IOM uint8_t  BAT_DET_CTRL;    /* Offset: 0x024 (R/W ) Battery Detector Control Register */
    __IOM uint8_t  BAT_DET_CFG;     /* Offset: 0x025 (R/W ) Battery Detector Configuration Register */
    __IM uint8_t   BAT_STATUS;      /* Offset: 0x026 (R/  ) Battery Status Register */
    uint8_t        UNUSED5[5];      /* 0x027 - 0x02B */
    __IOM uint16_t INT32K_TUNE;     /* Offset: 0x02C (R/W ) Internal 32kHz Clock Tune Register */
    __IOM uint8_t  XT32K_TUNE;      /* Offset: 0x02E (R/W ) External 32kHz Crystal Tune Register */
    __IOM uint8_t  CK32K_CONFIG;    /* Offset: 0x02F (R/W ) 32kHz Clock Source Configuration Register */
    __IOM uint8_t  RTC_FLAG_CTRL;   /* Offset: 0x030 (R/W ) RTC Flag and Control Register */
    __IOM uint8_t  RTC_MODE_CTRL;   /* Offset: 0x031 (R/W ) RTC Mode Control Register */
    uint16_t       UNUSED6;         /* 0x032 - 0x033 */
    __IOM uint32_t RTC_TRIG;        /* Offset: 0x034 (R/W ) RTC Trigger Register */
    __IOM uint32_t RTC_CNT;         /* Offset: 0x038 (R/  ) RTC Counter Register */
    __IOM uint32_t RTC_CNT_DAY;     /* Offset: 0x03C (R/  ) RTC Day Count Register */
    __IOM uint8_t  SAFE_ACCESS_SIG; /* Offset: 0x040 (R/W ) Safe Access Sign Register */
    __IM uint8_t   CHIP_ID;         /* Offset: 0x041 (R/  ) Chip ID Register */
    __IM uint8_t   SAFE_ACCESS_ID;  /* Offset: 0x042 (R/  ) Safe Access ID Register */
    __IM uint8_t   WDOG_COUNT;      /* Offset: 0x043 (R/  ) Watchdog Counter */
    __IOM uint8_t  RESET_STATUS;    /* Offset: 0x044 (R/W ) Reset Status Register */
    __IM uint8_t   GLOB_CFG_INFO;   /* Offset: 0x045 (R/W ) Global Config Info Register */
    __IOM uint8_t  WDOG_CTRL;       /* Offset: 0x046 (R/W  ) Watchdog Control Register */
    __IOM uint8_t  GLOB_RESET_KEEP; /* Offset: 0x047 (R/W ) Global Reset Keep Register */
    uint16_t       UNUSED7;         /* 0x048 - 0x049 */
    __IOM uint8_t  CFG_FLASH;       /* Offset: 0x04A (R/W ) Flash Configuration Register */
    __IOM uint8_t  PLL_CONFIG;      /* Offset: 0x04B (R/W ) PLL Config Register */
    __IOM uint8_t  INT32M_CALIB;    /* Offset: 0x04C (R/W ) Internal 32MHz Clock Calibration Register */
    uint8_t        UNUSED8;         /* 0x04D */
    __IOM uint8_t  INT32M_TUNE;     /* Offset: 0x04E (R/W ) Internal 32MHz Clock Tune Register */
    uint8_t        UNUSED9;         /* 0x04F */
    __IM uint16_t  OSC_CAL_CNT;     /* Offset: 0x050 (R/W ) Internal 32kHz Clock Calibration Value Register */
    __IOM uint8_t  OSC_CAL_CTRL;    /* Offset: 0x052 (R/W ) Internal 32kHz Clock Calibration Control Register */
    uint8_t        UNUSED10[5];     /* 0x053 - 0x057 */
    __IOM uint8_t  ADC_CHANNEL;     /* Offset: 0x058 (R/W ) ADC Channel Selection Register */
    __IOM uint8_t  ADC_CFG;         /* Offset: 0x059 (R/W ) ADC Configuration Register */
    __IOM uint8_t  ADC_CONVERT;     /* Offset: 0x05A (R/W ) ADC Conversion Control Register */
    __IOM uint8_t  TEM_SENSOR;      /* Offset: 0x05B (R/W ) ADC Temperature Sensor Configuration Register */
    __IOM uint16_t ADC_DATA;        /* Offset: 0x05C (R/W ) ADC Conversion Result Register */
    __IOM uint8_t  ADC_INT_FLAG;    /* Offset: 0x05E (R/WC) ADC Interrupt Flag Register */
    __IOM uint8_t  TKEY_CNT;        /* Offset: 0x05F (R/W ) Touch Key Charge Control Register */
    uint32_t       UNUSED11[12];    /* 0x60 - 0x8F */
    __IOM uint16_t PA_INT_EN;       /* Offset: 0x090 (R/W ) Port A Interrupt Enable Register */
    __IOM uint16_t PB_INT_EN;       /* Offset: 0x092 (R/W ) Port B Interrupt Enable Register */
    __IOM uint16_t PA_INT_MODE;     /* Offset: 0x094 (R/W ) Port A Interrupt Mode Register */
    __IOM uint16_t PB_INT_MODE;     /* Offset: 0x096 (R/W ) Port B Interrupt Mode Register */
    uint16_t       UNUSED12[2];     /* 0x098 - 0x09B */
    __IOM uint16_t PA_INT_FLAG;     /* Offset: 0x09C (R/W1C) Port A Interrupt Flag Register */
    __IOM uint16_t PB_INT_FLAG;     /* Offset: 0x09E (R/W1C) Port B Interrupt Flag Register */
    __IOM uint32_t PA_DIR;          /* Offset: 0x0A0 (R/W ) Port A Direction Register */
    __IM uint32_t  PA_PIN;          /* Offset: 0x0A4 (R/W ) Port A Input Data Register */
    __IOM uint32_t PA_OUT;          /* Offset: 0x0A8 (R/W ) Port A Output Data Register */
    __IOM uint32_t PA_CLR;          /* Offset: 0x0AC (R/W ) Port A Clear Register */
    __IOM uint32_t PA_PU;           /* Offset: 0x0B0 (R/W ) Port A Pull-up Configuration Register */
    __IOM uint32_t PA_PD_DRV;       /* Offset: 0x0B4 (R/W ) Port A Pull-down/Drive Configuration Register */
    uint32_t       UNUSED13[2];     /* 0x0B8 - 0x0BF */
    __IOM uint32_t PB_DIR;          /* Offset: 0x0C0 (R/W ) Port A Direction Register */
    __IM uint32_t  PB_PIN;          /* Offset: 0x0C4 (R/W ) Port A Input Data Register */
    __IOM uint32_t PB_OUT;          /* Offset: 0x0C8 (R/W ) Port A Output Data Register */
    __IOM uint32_t PB_CLR;          /* Offset: 0x0CC (R/W ) Port A Clear Register */
    __IOM uint32_t PB_PU;           /* Offset: 0x0D0 (R/W ) Port A Pull-up Configuration Register */
    __IOM uint32_t PB_PD_DRV;       /* Offset: 0x0D4 (R/W ) Port A Pull-down/Drive Configuration Register */
    // clang-format off
} CH57x_SYSAUX_TypeDef;  // clang-format on

// UART
typedef __PACKED_STRUCT {
    __IOM uint8_t  MCR; /* Offset: 0x000 (R/W ) Modem Control Register */
    __IOM uint8_t  IER; /* Offset: 0x001 (R/W ) Interrupt Enable Register */
    __IOM uint8_t  FCR; /* Offset: 0x002 (R/W ) FIFO Control Register */
    __IOM uint8_t  LCR; /* Offset: 0x003 (R/W ) Line Control Register */
    __IM uint8_t   IIR; /* Offset: 0x004 (R/  ) Interrupt Identification Register */
    __IM uint8_t   LSR; /* Offset: 0x005 (R/  ) Line Status Register */
    __IM uint8_t   MSR; /* Offset: 0x006 (R/  ) Modem Status Register */
    __IM uint8_t   RBR; /* Offset: 0x007 (R/  ) RX Buffer Register */
    __OM uint8_t   THR; /* Offset: 0x008 ( /W ) TX Hold Register */
    uint8_t        UNUSED0;
    __IM uint8_t   RFC; /* Offset: 0x00A (R/  ) RX FIFO Count Register */
    __IM uint8_t   TFC; /* Offset: 0x00B (R/  ) TX FIFO Count Register */
    __IOM uint16_t DL;  /* Offset: 0x00C (R/W ) Clock Divider Register */
    __IOM uint8_t  DIV; /* Offset: 0x00E (R/W ) Clock Pre-scaler Register */
    __IOM uint8_t  ADR; /* Offset: 0x00F (R/W ) Slave Address Register */
    // clang-format off
} CH57x_UART_TypeDef;     // clang-format on

/* CH57x_UART MCR Register Definitions */
#define CH57x_UART_MCR_DTR_Pos        0
#define CH57x_UART_MCR_DTR_Msk        (1UL) /* << CH57x_UART_MCR_DTR_Pos */

#define CH57x_UART_MCR_RTS_Pos        1
#define CH57x_UART_MCR_RTS_Msk        (1UL << CH57x_UART_MCR_RTS_Pos)

#define CH57x_UART_MCR_OUT1_Pos       2
#define CH57x_UART_MCR_OUT1_Msk       (1UL << CH57x_UART_MCR_OUT1_Pos)

#define CH57x_UART_MCR_INT_OE_Pos     3
#define CH57x_UART_MCR_INT_OE_Msk     (1UL << CH57x_UART_MCR_INT_OE_Pos)

#define CH57x_UART_MCR_LOOP_Pos       4
#define CH57x_UART_MCR_LOOP_Msk       (1UL << CH57x_UART_MCR_LOOP_Pos)

#define CH57x_UART_MCR_AU_FLOW_EN_Pos 5
#define CH57x_UART_MCR_AU_FLOW_EN_Msk (1UL << CH57x_UART_MCR_AU_FLOW_EN_Pos)

#define CH57x_UART_MCR_TNOW_Pos       6
#define CH57x_UART_MCR_TNOW_Msk       (1UL << CH57x_UART_MCR_TNOW_Pos)

#define CH57x_UART_MCR_HALF_Pos       7
#define CH57x_UART_MCR_HALF_Msk       (1UL << CH57x_UART_MCR_HALF_Pos)

/* CH57x_UART IER Register Definition */
#define CH57x_UART_IER_RECV_RDY_Pos  0
#define CH57x_UART_IER_RECV_RDY_Msk  (1UL) /* << CH57x_UART_IER_RECV_RDY_Pos */

#define CH57x_UART_IER_THR_EMPTY_Pos 1
#define CH57x_UART_IER_THR_EMPTY_Msk (1UL << CH57x_UART_IER_THR_EMPTY_Pos)

#define CH57x_UART_IER_LINE_STAT_Pos 2
#define CH57x_UART_IER_LINE_STAT_Msk (1UL << CH57x_UART_IER_LINE_STAT_Pos)

#define CH57x_UART_IER_MODEM_CHG_Pos 3
#define CH57x_UART_IER_MODEM_CHG_Msk (1UL << CH57x_UART_IER_MODEM_CHG_Pos)

#define CH57x_UART_IER_DTR_EN_Pos    4
#define CH57x_UART_IER_DTR_EN_Msk    (1UL << CH57x_UART_IER_DTR_EN_Pos)

#define CH57x_UART_IER_RTS_EN_Pos    5
#define CH57x_UART_IER_RTS_EN_Msk    (1UL << CH57x_UART_IER_RTS_EN_Pos)

#define CH57x_UART_IER_TXD_EN_Pos    6
#define CH57x_UART_IER_TXD_EN_Msk    (1UL << CH57x_UART_IER_TXD_EN_Pos)

#define CH57x_UART_IER_RESET_Pos     7
#define CH57x_UART_IER_RESET_Msk     (1UL << CH57x_UART_IER_RESET_Pos)

/* CH57x_UART FCR Register Definition */
#define CH57x_UART_FCR_FIFO_EN_Pos     0
#define CH57x_UART_FCR_FIFO_EN_Msk     (1UL) /* << CH57x_UART_FCR_FIFO_EN_Pos */

#define CH57x_UART_FCR_RX_FIFO_CLR_Pos 1
#define CH57x_UART_FCR_RX_FIFO_CLR_Msk (1UL << CH57x_UART_FCR_RX_FIFO_CLR_Pos)

#define CH57x_UART_FCR_TX_FIFO_CLR_Pos 2
#define CH57x_UART_FCR_TX_FIFO_CLR_Msk (1UL << CH57x_UART_FCR_TX_FIFO_CLR_Pos)

#define CH57x_UART_FCR_FIFO_TRIG_Pos   6
#define CH57x_UART_FCR_FIFO_TRIG_Msk   (0x3UL << CH57x_UART_FCR_FIFO_TRIG_Pos)

/* CH57x_UART LCR Register Definition */
#define CH57x_UART_LCR_WORD_SZ_Pos  0
#define CH57x_UART_LCR_WORD_SZ_Msk  (0x3UL) /* << CH57x_UART_LCR_WORD_SZ_Pos */

#define CH57x_UART_LCR_STOP_BIT_Pos 2
#define CH57x_UART_LCR_STOP_BIT_Msk (1UL << CH57x_UART_LCR_STOP_BIT_Pos)

#define CH57x_UART_LCR_PAR_EN_Pos   3
#define CH57x_UART_LCR_PAR_EN_Msk   (1UL << CH57x_UART_LCR_PAR_EN_Pos)

#define CH57x_UART_LCR_PAR_MOD_Pos  4
#define CH57x_UART_LCR_PAR_MOD_Msk  (0x3UL << CH57x_UART_LCR_PAR_MOD_Pos)

#define CH57x_UART_LCR_BREAK_EN_Pos 6
#define CH57x_UART_LCR_BREAK_EN_Msk (1UL << CH57x_UART_LCR_BREAK_EN_Pos)

#define CH57x_UART_LCR_GP_BIT_Pos   7
#define CH57x_UART_LCR_GP_BIT_Msk   (1UL << CH57x_UART_LCR_GP_BIT_Pos)

/* CH57x_UART IIR Register Definition */
#define CH57x_UART_IIR_NO_INT_Pos   0
#define CH57x_UART_IIR_NO_INT_Msk   (1UL) /* << CH57x_UART_IIR_NO_INT_Pos */

#define CH57x_UART_IIR_INT_MASK_Pos 1
#define CH57x_UART_IIR_INT_MASK_Msk (0x4UL << CH57x_UART_IIR_INT_MASK_Pos)

#define CH57x_UART_IIR_FIFO_ID_Pos  6
#define CH57x_UART_IIR_FIFO_ID_Msk  (0x2UL << CH57x_UART_IIR_FIFO_ID_Pos)

/* CH57x_UART LSR Register Definition */
#define CH57x_UART_LSR_DATA_RDY_Pos    0
#define CH57x_UART_LSR_DATA_RDY_Msk    (1UL) /* << CH57x_UART_LSR_DATA_RDY_Pos */

#define CH57x_UART_LSR_OVER_ERR_Pos    1
#define CH57x_UART_LSR_OVER_ERR_Msk    (1UL << CH57x_UART_LSR_OVER_ERR_Pos)

#define CH57x_UART_LSR_PAR_ERR_Pos     2
#define CH57x_UART_LSR_PAR_ERR_Msk     (1UL << CH57x_UART_LSR_PAR_ERR_Pos)

#define CH57x_UART_LSR_FRAME_ERR_Pos   3
#define CH57x_UART_LSR_FRAME_ERR_Msk   (1UL << CH57x_UART_LSR_FRAME_ERR_Pos)

#define CH57x_UART_LSR_BREAK_ERR_Pos   4
#define CH57x_UART_LSR_BREAK_ERR_Msk   (1UL << CH57x_UART_LSR_BREAK_ERR_Pos)

#define CH57x_UART_LSR_TX_FIFO_EMP_Pos 5
#define CH57x_UART_LSR_TX_FIFO_EMP_Msk (1UL << CH57x_UART_LSR_TX_FIFO_EMP_Pos)

#define CH57x_UART_LSR_TX_ALL_EMP_Pos  6
#define CH57x_UART_LSR_TX_ALL_EMP_Msk  (1UL << CH57x_UART_LSR_TX_ALL_EMP_Pos)

#define CH57x_UART_LSR_RX_FIFO_ERR_Pos 7
#define CH57x_UART_LSR_RX_FIFO_ERR_Msk (1UL << CH57x_UART_LSR_RX_FIFO_ERR_Pos)

/* CH57x_UART MSR Register Definition */
#define CH57x_UART_MSR_CTS_CHG_Pos 0
#define CH57x_UART_MSR_CTS_CHG_Msk (1UL) /* << CH57x_UART_MSR_CTS_CHG_Pos */

#define CH57x_UART_MSR_DSR_CHG_Pos 1
#define CH57x_UART_MSR_DSR_CHG_Msk (1UL << CH57x_UART_MSR_DSR_CHG_Pos)

#define CH57x_UART_MSR_RI_CHG_Pos  2
#define CH57x_UART_MSR_RI_CHG_Msk  (1UL << CH57x_UART_MSR_RI_CHG_Pos)

#define CH57x_UART_MSR_DCD_CHG_Pos 3
#define CH57x_UART_MSR_DCD_CHG_Msk (1UL << CH57x_UART_MSR_DCD_CHG_Pos)

#define CH57x_UART_MSR_CTS_Pos     4
#define CH57x_UART_MSR_CTS_Msk     (1UL << CH57x_UART_MSR_CTS_Pos)

#define CH57x_UART_MSR_DSR_Pos     5
#define CH57x_UART_MSR_DSR_Msk     (1UL << CH57x_UART_MSR_DSR_Pos)

#define CH57x_UART_MSR_RI_Pos      6
#define CH57x_UART_MSR_RI_Msk      (1UL << CH57x_UART_MSR_RI_Pos)

#define CH57x_UART_MSR_DCD_Pos     7
#define CH57x_UART_MSR_DCD_Msk     (1UL << CH57x_UART_MSR_DCD_Pos)

/* CH57x_UART RBR Register Definition */
#define CH57x_UART_RBR_Pos 0
#define CH57x_UART_RBR_Msk (0xFFUL) /* << CH57x_UART_RBR_DATA_Pos */

/* CH57x_UART THR Register Definition */
#define CH57x_UART_THR_Pos 0
#define CH57x_UART_THR_Msk (0xFFUL) /* << CH57x_UART_THR_Pos */

/* CH57x_UART RFC Register Definition */
#define CH57x_UART_RFC_Pos 0
#define CH57x_UART_RFC_Msk (0xFFUL) /* << CH57x_UART_RFC__Pos */

/* CH57x_UART TFC Register Definition */
#define CH57x_UART_TFC_Pos 0
#define CH57x_UART_TFC_Msk (0xFFUL) /* << CH57x_UART_TFC__Pos */

/* CH57x_UART DL Register Definition */
#define CH57x_UART_DL_Pos 0
#define CH57x_UART_DL_Msk (0xFFFFUL) /* << CH57x_UART_DL_Pos */

/* CH57x_UART DIV Register Definition */
#define CH57x_UART_DIV_Pos 0
#define CH57x_UART_DIV_Msk (0xFFUL) /* << CH57x_UART_DIV_Pos */

/* CH57x_UART ADR Register Definition */
#define CH57x_UART_ADR_Pos 0
#define CH57x_UART_ADR_Msk (0xFFUL) /* << CH57x_UART_ADR_Pos */

/* ================  End of section using anonymous unions  ================ */
#if defined(__CC_ARM)
    #pragma pop
#elif defined(__ICCARM__)
/* leave anonymous unions enabled */
#elif (defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050))
    #pragma clang diagnostic pop
#elif defined(__GNUC__)
/* anonymous unions are enabled by default */
#elif defined(__TMS470__)
/* anonymous unions are enabled by default */
#elif defined(__TASKING__)
    #pragma warning restore
#elif defined(__CSMC__)
/* anonymous unions are enabled by default */
#else
    #warning Not supported compiler type
#endif

/* ========================================================================= */
/* ============     Device Specific Peripheral Address Map      ============ */
/* ========================================================================= */

/* Peripheral and SRAM base address */
#define CH57x_FLASH_BASE  (0x00000000U)
#define CH57x_SRAM_BASE   (0x20000000U)
#define CH57x_PERIPH_BASE (0x40000000U)

/* Peripheral memory map */
#define CH57x_SYSAUX_BASE (CH57x_PERIPH_BASE + 0x1000) /* SYS/AUX Base Address */
#define CH57x_UART0_BASE  (CH57x_PERIPH_BASE + 0x3000) /* UART0 Base Address */
#define CH57x_UART1_BASE  (CH57x_PERIPH_BASE + 0x3400) /* UART1 Base Address */
#define CH57x_UART2_BASE  (CH57x_PERIPH_BASE + 0x3800) /* UART2 Base Address */
#define CH57x_UART3_BASE  (CH57x_PERIPH_BASE + 0x3C00) /* UART3 Base Address */
                                                       /* ToDo: Add more peripherals */

#ifdef __cplusplus
}
#endif

#endif  // CH579_H