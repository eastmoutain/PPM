#include "stm32f10x.h"
#include "systick.h"
#include "ppm.h"

#define MS      20
#define MS_TICK     72000
#define PERIOD      MS*MS_TICK

void systick_init(unsigned int cnt)
{
	/* select clk source for systick */
    SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);
	/* Init systick counter with value @cnt at which
	*  point it should trigger interrupt
	*/
    SysTick_Config(cnt);
	/* clear systick counter */
    SysTick->VAL = 0;
}

void Systick_IRQ(void)
{
    ppm_output();
}

