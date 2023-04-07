/**
 * @file system_ch57x.c
 * @author imi415 (imi415.public@gmail.com)
 * @brief CMSIS CH57x System Header File
 * @version 0.1
 * @date 2022-01-07
 *
 * @copyright Copyright (c) 2022 imi415
 *
 */

#include "ch57x.h"

/*----------------------------------------------------------------------------
  Define clocks
 *----------------------------------------------------------------------------*/
#define CK32K (32768UL)
#define CK32M (32000000UL)  /* HS frequency */
#define CKPLL (480000000UL) /* PLL */

/*----------------------------------------------------------------------------
  System Core Clock Variable
 *----------------------------------------------------------------------------*/
uint32_t SystemCoreClock; /* System Core Clock Frequency */

/*----------------------------------------------------------------------------
  System Core Clock update function
 *----------------------------------------------------------------------------*/
void SystemCoreClockUpdate(void) {
    // Check system clock status and update SystemCoreClock.
    uint32_t hclk_src;
    uint16_t clk_sys_cfg = SYS->R16_CLK_SYS_CFG;
    uint8_t  clk_sys_mod =
        (clk_sys_cfg & SYS_R16_CLK_SYS_CFG_RB_CLK_SYS_MOD_Msk) >> SYS_R16_CLK_SYS_CFG_RB_CLK_SYS_MOD_Pos;
    uint8_t clk_pll_div =
        (clk_sys_cfg & SYS_R16_CLK_SYS_CFG_RB_CLK_PLL_DIV_Msk) >> SYS_R16_CLK_SYS_CFG_RB_CLK_PLL_DIV_Pos;

    /* 0: CK32M divide by PLL divider
     * 1: CKPLL divide by PLL divider
     * 2: CK32M as HCLK
     * 3: CK32K as HCLK
     */
    switch (clk_sys_mod) {
        case 0:
        case 2:
            hclk_src = CK32M;
            break;
        case 1:
            hclk_src = CKPLL;
            break;
        case 3:
            hclk_src = CK32K;
            break;
        default:
            hclk_src = CK32M;
            break;
    }

    /* Calculate divide factor
     * 0: divided by 32
     * 1: OFF (INVALID)
     * 2-31: factor
     */
    if (clk_sys_mod == 0 || clk_sys_mod == 1) {
        switch (clk_pll_div) {
            case 0:
                SystemCoreClock = hclk_src / 32;
                break;
            case 1:
                SystemCoreClock = 0;
                break;
            default:
                SystemCoreClock = hclk_src / clk_pll_div;
                break;
        }
    }
}

/*----------------------------------------------------------------------------
  System initialization function
 *----------------------------------------------------------------------------*/
void SystemInit(void) {
    // Init system
}
