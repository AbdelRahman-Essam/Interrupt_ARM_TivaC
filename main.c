#include"INT.h"
#include "GPIO.h"
/**
 * main.c
 */
 //main.c

	extern void (* g_pfnVectors[])(void);

	#pragma DATA_ALIGN(g_pfnRAMVectors, 1024)
	#pragma DATA_SECTION(g_pfnRAMVectors, ".vtable")
	void (*g_pfnRAMVectors[155])(void);

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


	    REG Int_Mask = PORTF_AHB + GPIOIM ;
	    SETBIT(*Int_Mask,4);
	    //INT_Init();
    int i=0;
    	for(i = 0; i < 155; i++)
    	   {
               g_pfnRAMVectors[i] = g_pfnVectors[i];
           }
           REG reg     =   0xE000ED08 ;
           *reg = (unsigned long int)g_pfnRAMVectors; // Point the NVIC at the RAM vector table.

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
