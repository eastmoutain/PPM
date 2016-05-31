/************************************************************************************
**	  ���������壨V1.0��
**	  TIMʵ��
**
**	  ��    ̳��bbs.openmcu.com
**	  ��    ����www.openmcu.com
**	  ��    �䣺support@openmcu.com
**
**    ��    ����V1.0
**	  ��    �ߣ�FXL
**	  �������:	2012.7.25
------------------------------------------------------------------------------------
**	TIM ����˵����TIM��ʱ����ʱ��ƣ��߼���ʱ��TIM1��ͨ�ö�ʱ��TIM2 �������ã�
**                                   ������ʱ���Դ�Ϊ�������ܿ������գ�  
**		    ���裺��ʼ��ϵͳʱ��
**				  �жϳ�ʼ��
**				  TIM��ʼ��
**			ע�⣺�ж�ʹ�ܣ�NVIC��
**                �жϺ������ã�STM32F10X_IT.C��
**
**          JLINK�������к�
**          �������ʱʱ�䵽������һ�θ����¼�Update;
**          Ӳ����LED1�ư�������˸��
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

/****������****/
int main(void)
{
	RCC_Configuration();	//��ʼ��ϵͳʱ��
	NVIC_Configuration();	//�жϳ�ʼ�� 
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
