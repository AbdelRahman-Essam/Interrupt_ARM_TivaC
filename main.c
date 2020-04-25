#include"INT.h"
#include "GPIO.h"
/**
 * main.c
 */
 //main.c



int main(void)
{
    SYSCTL_RCC_R |= (1<<11);
    SYSCTL_RCC_R &= ~(1<<22);
    SYSCTL_RCC_R |= (1<<4);
    SYSCTL_RCC_R &= ~(1<<5);
    SYSCTL_RCC_R |= (1<<13);

    GPIOQuickInit(PORTF,AHB,RCGC,0b00000010,OUT,Drive_8mA,PAD_NPU_NPD);

    GPIOQuickInit(PORTF,AHB,RCGC,0b00010000,IN,Drive_8mA,Pad_PU);
    GPIOWrite(PORTF,0b00000010,0x0);
    INT_Enable(INT_PortF);
    GPIOIntQuickInit(PORTF,0b00010000,Edge,Falling);


	    INT_Init();

        g_pfnRAMVectors[46] = usr_isr_portF;
while(1)
{

}
	return 0;
}
void usr_isr_portF(void)
{
	   int i=0;
	    REG GPIOICR_Reg = PORTF_AHB + GPIOICR ;
	    SETBIT(*GPIOICR_Reg,4);
	    TOG_BIT(GPIO_PORTF_AHB_DATA_R, 1);
}
