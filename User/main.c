/************************************************************************************
**	  红龙开发板（V1.0）
**	  TIM实验
**
**	  论    坛：bbs.openmcu.com
**	  旺    宝：www.openmcu.com
**	  邮    箱：support@openmcu.com
**
**    版    本：V1.0
**	  作    者：FXL
**	  完成日期:	2012.7.25
------------------------------------------------------------------------------------
**	TIM 测试说明：TIM定时器定时点灯（高级定时器TIM1，通用定时器TIM2 均可设置，
**                                   其他定时器以此为例，均能快速掌握）  
**		    步骤：初始化系统时钟
**				  中断初始化
**				  TIM初始化
**			注意：中断使能（NVIC）
**                中断函数调用（STM32F10X_IT.C）
**
**          JLINK下载运行后
**          软件：定时时间到，发生一次更新事件Update;
**          硬件：LED1灯按设置闪烁。
************************************************************************************/
#include "stm32f10x.h"
#include <stdio.h>
#include "SystemClock.h"
#include "Nvic.h"
#include "ppm.h"
#include "systick.h"
#include "uart.h"

extern uint32_t interval[];

void delay(unsigned n)
{
    unsigned i;
    for (; n > 0; n--) {
        for (i = 0xffff; i > 0; --i);
    }
}

/****主函数****/
int main(void)
{
	RCC_Configuration();	//初始化系统时钟
	NVIC_Configuration();	//中断初始化 
    uart_init();    

    LedInit();
    Timer2Init();
    Timer4Init();
    systick_init(10000);
    printf("hello, world\r\n");
    
    while(1)
	{
        delay(40);
        printf("ch value: 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x\r\n",\
                interval[0], interval[1], interval[2], interval[3], \
                interval[4], interval[5], interval[6], interval[7]);
	}
}
