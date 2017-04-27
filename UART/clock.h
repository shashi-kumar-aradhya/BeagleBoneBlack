
#ifndef __CLOCK_H_
#define __CLOCK_H_

#include "types.h"

/*
 * @brief Clock Modules bases memory map : TRM 2.1
 */
typedef enum
{
   CM_PER     = 0x44E00000,
   CM_WKUP    = 0x44E00400,
   CM_DPLL    = 0x44E00500,
   CM_MPU     = 0x44E00600,
   CM_DEVICE  = 0x44E00700,
   CM_RTC     = 0x44E00800,
   CM_GFX     = 0X44E00900,
   CM_CEFUSE  = 0X44E00A00
}CLK_MODULE_t;



/*
 * @brief Clock Modules Registers & their coresponding offsets from their chapter/domain/memory zone: TRM 8.1.12.1
 */
typedef enum
{
   // CM_PER zone

   CM_PER_L4LS_CLKSTCTRL        = 0x000,
   CM_PER_L3S_CLKSTCTRL         = 0x004,
   CM_PER_L4FW_CLKSTCTRL        = 0x008,
   CM_PER_L3_CLKSTCTRL          = 0x00C,
   CM_PER_CPGMAC0_CLKCTRL       = 0x014,
   CM_PER_LCDC_CLKCTRL          = 0x018,
   CM_PER_USB0_CLKCTRL          = 0x01C,
   CM_PER_TPTC0_CLKCTRL         = 0x024,
   CM_PER_EMIF_CLKCTRL          = 0x028,
   CM_PER_OCMCRAM_CLKCTRL       = 0x02C,
   CM_PER_GPMC_CLKCTRL          = 0x030,
   CM_PER_MCASP0_CLKCTRL        = 0x034,
   CM_PER_UART5_CLKCTRL         = 0x038,
   CM_PER_MMC0_CLKCTRL          = 0x03C,
   CM_PER_ELM_CLKCTRL           = 0x040,
   CM_PER_I2C2_CLKCTRL          = 0x044,
   CM_PER_I2C1_CLKCTRL          = 0x048,
   CM_PER_SPI0_CLKCTRL          = 0x04C,
   CM_PER_SPI1_CLKCTRL          = 0x050,
   CM_PER_L4LS_CLKCTRL          = 0x060,
   CM_PER_L4FW_CLKCTRL          = 0x064,
   CM_PER_MCASP1_CLKCTRL        = 0x068,
   CM_PER_UART1_CLKCTRL         = 0x06C,
   CM_PER_UART2_CLKCTRL         = 0x070,
   CM_PER_UART3_CLKCTRL         = 0x074,
   CM_PER_UART4_CLKCTRL         = 0x078,
   CM_PER_TIMER7_CLKCTRL        = 0x07C,
   CM_PER_TIMER2_CLKCTRL        = 0x080,
   CM_PER_TIMER3_CLKCTRL        = 0x084,
   CM_PER_TIMER4_CLKCTRL        = 0x088,
   CM_PER_GPIO1_CLKCTRL         = 0x0AC,
   CM_PER_GPIO2_CLKCTRL         = 0x0B0,
   CM_PER_GPIO3_CLKCTRL         = 0x0B4,
   CM_PER_TPCC_CLKCTRL          = 0x0BC,
   CM_PER_DCAN0_CLKCTRL         = 0x0C0,
   CM_PER_DCAN1_CLKCTRL         = 0x0C4,
   CM_PER_EPWMSS1_CLKCTRL       = 0x0CC,
   CM_PER_EMIF_FW_CLKCTRL       = 0x0D0,
   CM_PER_EPWMSS0_CLKCTRL       = 0x0D4,
   CM_PER_EPWMSS2_CLKCTRL       = 0x0D8,
   CM_PER_L3_INSTR_CLKCTRL      = 0x0DC,
   CM_PER_L3_CLKCTRL            = 0x0E0,
   CM_PER_IEEE5000_CLKCTRL      = 0x0E4,
   CM_PER_PRU_ICSS_CLKCTRL      = 0x0E8,
   CM_PER_TIMER5_CLKCTRL        = 0x0EC,
   CM_PER_TIMER6_CLKCTRL        = 0x0F0,
   CM_PER_MMC1_CLKCTRL          = 0x0F4,
   CM_PER_MMC2_CLKCTRL          = 0x0F8,
   CM_PER_TPTC1_CLKCTRL         = 0x0FC,
   CM_PER_TPTC2_CLKCTRL         = 0x100,
   CM_PER_SPINLOCK_CLKCTRL      = 0x10C,
   CM_PER_MAILBOX0_CLKCTRL      = 0x110,
   CM_PER_L4HS_CLKSTCTRL        = 0x11C,
   CM_PER_L4HS_CLKCTRL          = 0x120,
   CM_PER_OCPWP_L3_CLKSTCTRL    = 0x12C,
   CM_PER_OCPWP_CLKCTRL         = 0x130,
   CM_PER_PRU_ICSS_CLKSTCTRL    = 0x140,
   CM_PER_CPSW_CLKSTCTRL        = 0x144,
   CM_PER_LCDC_CLKSTCTRL        = 0x148,
   CM_PER_CLKDIV32K_CLKCTRL     = 0x14C,
   CM_PER_CLK_24MHZ_CLKSTCTRL   = 0x150,
   // CM_WKUP zone
   CM_WKUP_CLKSTCTRL            = 0x00,
   CM_WKUP_CONTROL_CLKCTRL      = 0x04,
   CM_WKUP_GPIO0_CLKCTRL        = 0x08,
   CM_WKUP_L4WKUP_CLKCTRL       = 0x0C,
   CM_WKUP_TIMER0_CLKCTRL       = 0x10,
   CM_WKUP_DEBUGSS_CLKCTRL      = 0x14,
   CM_L3_AON_CLKSTCTRL          = 0x18,
   CM_AUTOIDLE_DPLL_MPU         = 0x1C,
   CM_IDLEST_DPLL_MPU           = 0x20,
   CM_SSC_DELTAMSTEP_DPLL_MPU   = 0x24,
   CM_SSC_MODFREQDIV_DPLL_MPU   = 0x28,
   CM_CLKSEL_DPLL_MPU           = 0x2C,
   CM_AUTOIDLE_DPLL_DDR         = 0x30,
   CM_IDLEST_DPLL_DDR           = 0x34,
   CM_SSC_DELTAMSTEP_DPLL_DDR   = 0x38,
   CM_SSC_MODFREQDIV_DPLL_DDR   = 0x3C,
   CM_CLKSEL_DPLL_DDR           = 0x40,
   CM_AUTOIDLE_DPLL_DISP        = 0x44,
   CM_IDLEST_DPLL_DISP          = 0x48,
   CM_SSC_DELTAMSTEP_DPLL_DISP  = 0x4C,
   CM_SSC_MODFREQDIV_DPLL_DISP  = 0x50,
   CM_CLKSEL_DPLL_DISP          = 0x54,
   CM_AUTOIDLE_DPLL_CORE        = 0x58,
   CM_IDLEST_DPLL_CORE          = 0x5C,
   CM_SSC_DELTAMSTEP_DPLL_CORE  = 0x60,
   CM_SSC_MODFREQDIV_DPLL_CORE  = 0x64,
   CM_CLKSEL_DPLL_CORE          = 0x68,
   CM_AUTOIDLE_DPLL_PER         = 0x6C,
   CM_IDLEST_DPLL_PER           = 0x70,
   CM_SSC_DELTAMSTEP_DPLL_PER   = 0x74,
   CM_SSC_MODFREQDIV_DPLL_PER   = 0x78,
   CM_CLKDCOLDO_DPLL_PER        = 0x7C,
   CM_DIV_M4_DPLL_CORE          = 0x80,
   CM_DIV_M5_DPLL_CORE          = 0x84,
   CM_CLKMODE_DPLL_MPU          = 0x88,
   CM_CLKMODE_DPLL_PER          = 0x8C,
   CM_CLKMODE_DPLL_CORE         = 0x90,
   CM_CLKMODE_DPLL_DDR          = 0x94,
   CM_CLKMODE_DPLL_DISP         = 0x98,
   CM_CLKSEL_DPLL_PERIPH        = 0x9C,
   CM_DIV_M2_DPLL_DDR           = 0xA0,
   CM_DIV_M2_DPLL_DISP          = 0xA4,
   CM_DIV_M2_DPLL_MPU           = 0xA8,
   CM_DIV_M2_DPLL_PER           = 0xAC,
   CM_WKUP_WKUP_M3_CLKCTRL      = 0xB0,
   CM_WKUP_UART0_CLKCTRL        = 0xB4,
   CM_WKUP_I2C0_CLKCTRL         = 0xB8,
   CM_WKUP_ADC_TSC_CLKCTRL      = 0xBC,
   CM_WKUP_SMARTREFLEX0_CLKCTRL = 0xC0,
   CM_WKUP_TIMER1_CLKCTRL       = 0xC4,
   CM_WKUP_SMARTREFLEX1_CLKCTRL = 0xC8,
   CM_L4_WKUP_AON_CLKSTCTRL     = 0xCC,
   CM_WKUP_WDT1_CLKCTRL         = 0xD4,
   CM_DIV_M6_DPLL_CORE          = 0xD8
}CM_PER_REG;


void CM_SetClk(CLK_MODULE_t module, CM_PER_REG reg, unsigned int value);

unsigned int CM_GetClk(CLK_MODULE_t module, CM_PER_REG reg);
void Init_UART0_Clk();

/*
static inline void CM_SetClk(CLK_MODULE_t module, CM_PER_REG reg, unsigned int value)
{

	PUT32(module+reg, value);
}
*/
#endif
