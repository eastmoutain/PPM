#include "stm32f10x.h"
#include "systick.h"
#include "ppm.h"

#define MS      20
#define MS_TICK     72000
#define PERIOD      MS*MS_TICK

void systick_init(unsigned int cnt)
{
    SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);	//Ê±ÖÓÔ´Ñ¡Ôñ
    SysTick_Config(cnt);
    SysTick->VAL = 0;
}

void Systick_IRQ(void)
{
    ppm_output();
}

