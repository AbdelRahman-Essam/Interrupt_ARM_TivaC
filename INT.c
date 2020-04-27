/*
 * INT_prog.c
 *
 *  Created on: Mar 4, 2020
 *      Author: Abdelrahman Essam
 */
#include "INT.h"
#include "std_types.h"
#pragma DATA_ALIGN(g_pfnRAMVectors, 1024)
#pragma DATA_SECTION(g_pfnRAMVectors, ".vtable")


void (* g_pfnRAMVectors[]) (void) =
{
    (void *)0,                      // GPIO Port A
    isr_Empty,                      // GPIO Port B
    isr_Empty,                      // GPIO Port C
    isr_Empty,                      // GPIO Port D
    isr_Empty,                      // GPIO Port E
    isr_Empty,                      // UART0 Rx and Tx
    isr_Empty,                      // UART1 Rx and Tx
    isr_Empty,                      // SSI0 Rx and Tx
    isr_Empty,                      // I2C0 Master and Slave
    isr_Empty,                      // PWM Fault
    isr_Empty,                      // PWM Generator 0
    isr_Empty,                      // PWM Generator 1
    isr_Empty,                      // PWM Generator 2
    isr_Empty,                      // Quadrature Encoder 0
    isr_Empty,                      // ADC Sequence 0
    isr_Empty,                      // ADC Sequence 1
    isr_Empty,                      // ADC Sequence 2
    isr_Empty,                      // ADC Sequence 3
    isr_Empty,                      // Watchdog timer
    isr_Empty,                      // Timer 0 subtimer A
    isr_Empty,                      // Timer 0 subtimer B
    isr_Empty,                      // Timer 1 subtimer A
    isr_Empty,                      // Timer 1 subtimer B
    isr_Empty,                      // Timer 2 subtimer A
    isr_Empty,                      // Timer 2 subtimer B
    isr_Empty,                      // Analog Comparator 0
    isr_Empty,                      // Analog Comparator 1
    isr_Empty,                      // Analog Comparator 2
    isr_Empty,                      // System Control (PLL, OSC, BO)
    isr_Empty,                      // FLASH Control
    isr_Empty,                      // GPIO Port F
    isr_Empty,                      // GPIO Port G
    isr_Empty,                      // GPIO Port H
    isr_Empty,                      // UART2 Rx and Tx
    isr_Empty,                      // SSI1 Rx and Tx
    isr_Empty,                      // Timer 3 subtimer A
    isr_Empty,                      // Timer 3 subtimer B
    isr_Empty,                      // I2C1 Master and Slave
    isr_Empty,                      // Quadrature Encoder 1
    isr_Empty,                      // CAN0
    isr_Empty,                      // CAN1
    0,                                      // Reserved
    0,                                      // Reserved
    isr_Empty,                      // Hibernate
    isr_Empty,                      // USB0
    isr_Empty,                      // PWM Generator 3
    isr_Empty,                      // uDMA Software Transfer
    isr_Empty,                      // uDMA Error
    isr_Empty,                      // ADC1 Sequence 0
    isr_Empty,                      // ADC1 Sequence 1
    isr_Empty,                      // ADC1 Sequence 2
    isr_Empty,                      // ADC1 Sequence 3
    0,                                      // Reserved
    0,                                      // Reserved
    isr_Empty,                      // GPIO Port J
    isr_Empty,                      // GPIO Port K
    isr_Empty,                      // GPIO Port L
    isr_Empty,                      // SSI2 Rx and Tx
    isr_Empty,                      // SSI3 Rx and Tx
    isr_Empty,                      // UART3 Rx and Tx
    isr_Empty,                      // UART4 Rx and Tx
    isr_Empty,                      // UART5 Rx and Tx
    isr_Empty,                      // UART6 Rx and Tx
    isr_Empty,                      // UART7 Rx and Tx
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    isr_Empty,                      // I2C2 Master and Slave
    isr_Empty,                      // I2C3 Master and Slave
    isr_Empty,                      // Timer 4 subtimer A
    isr_Empty,                      // Timer 4 subtimer B
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    isr_Empty,                      // Timer 5 subtimer A
    isr_Empty,                      // Timer 5 subtimer B
    isr_Empty,                      // Wide Timer 0 subtimer A
    isr_Empty,                      // Wide Timer 0 subtimer B
    isr_Empty,                      // Wide Timer 1 subtimer A
    isr_Empty,                      // Wide Timer 1 subtimer B
    isr_Empty,                      // Wide Timer 2 subtimer A
    isr_Empty,                      // Wide Timer 2 subtimer B
    isr_Empty,                      // Wide Timer 3 subtimer A
    isr_Empty,                      // Wide Timer 3 subtimer B
    isr_Empty,                      // Wide Timer 4 subtimer A
    isr_Empty,                      // Wide Timer 4 subtimer B
    isr_Empty,                      // Wide Timer 5 subtimer A
    isr_Empty,                      // Wide Timer 5 subtimer B
    isr_Empty,                      // FPU
    0,                                      // Reserved
    0,                                      // Reserved
    isr_Empty,                      // I2C4 Master and Slave
    isr_Empty,                      // I2C5 Master and Slave
    isr_Empty,                      // GPIO Port M
    isr_Empty,                      // GPIO Port N
    isr_Empty,                      // Quadrature Encoder 2
    0,                                      // Reserved
    0,                                      // Reserved
    isr_Empty,                      // GPIO Port P (Summary or P0)
    isr_Empty,                      // GPIO Port P1
    isr_Empty,                      // GPIO Port P2
    isr_Empty,                      // GPIO Port P3
    isr_Empty,                      // GPIO Port P4
    isr_Empty,                      // GPIO Port P5
    isr_Empty,                      // GPIO Port P6
    isr_Empty,                      // GPIO Port P7
    isr_Empty,                      // GPIO Port Q (Summary or Q0)
    isr_Empty,                      // GPIO Port Q1
    isr_Empty,                      // GPIO Port Q2
    isr_Empty,                      // GPIO Port Q3
    isr_Empty,                      // GPIO Port Q4
    isr_Empty,                      // GPIO Port Q5
    isr_Empty,                      // GPIO Port Q6
    isr_Empty,                      // GPIO Port Q7
    isr_Empty,                      // GPIO Port R
    isr_Empty,                      // GPIO Port S
    isr_Empty,                      // PWM 1 Generator 0
    isr_Empty,                      // PWM 1 Generator 1
    isr_Empty,                      // PWM 1 Generator 2
    isr_Empty,                      // PWM 1 Generator 3
    isr_Empty                       // PWM 1 Fault
};

void INT_SetISR(INT_ID_t ID,void (*function) (void))
{
	g_pfnRAMVectors[ID]=function;
}
void INT_Init(void)
{
	int i=0;
	for(i = 0; i < 155; i++)
	   {
           g_pfnRAMVectors[i] = g_pfnVectors[i];
       }
       REG reg     =   0xE000ED08 ;
       *reg = (unsigned long int)g_pfnRAMVectors; // Point the NVIC at the RAM vector table.
}
/*************************************************/
void INT_Enable(INT_ID_t ID)
{/*You Can Get the ID from INT_config.h*/
    u8 n=(ID-16)%32;
    u16 ofst=0x100+(((ID-16)/32)*4);
    REG reg = INT+ofst;
    SETBIT(*reg,n);
}
/*************************************************/
void INT_Disable(INT_ID_t ID)
{/*You Can Get the ID from INT_config.h*/
    u8 n=(ID-16)%32;
    u16 ofst=0x180+(((ID-16)/32)*4);
    REG reg = INT+ofst;//disable reg
    u16 offset=0x100+(((ID-16)/32)*4);
    REG reg1 = INT+offset;//set  reg
    u32 data = *reg;
    data &=~(1<<n);
    SETBIT(*reg,0xFF);
    *reg1=data;
}
/*************************************************/
void INT_SetPending(INT_ID_t ID)
{/*You Can Get the ID from INT_config.h*/
    u8 n=(ID-16)%32;
    u16 ofst=0x200+(((ID-16)/32)*4);
    REG reg = INT+ofst;
    SETBIT(*reg,n);
}
/*************************************************/
void INT_ClearPending(INT_ID_t ID)
{/*You Can Get the ID from INT_config.h*/
    u8 n=(ID-16)%32;
    u16 ofst=0x280+(((ID-16)/32)*4);
    REG reg = INT+ofst;//disable reg
    u16 offset=0x200+(((ID-16)/32)*4);
    REG reg1 = INT+offset;//set  reg
    u32 data = *reg;
    data &=~(1<<n);
    SETBIT(*reg,0xFF);
    *reg1=data;
}
/*************************************************/
u8 INT_GetPending(INT_ID_t ID)
{/*You Can Get the ID from INT_config.h*/
    u8 n=(ID-16)%32;
    u16 ofst=0x200+(((ID-16)/32)*4);
    REG reg = INT+ofst;
    u8 data=GETBIT(*reg,n);
    return(data);
}
/*************************************************/
u8 INT_GetActiveState(INT_ID_t ID)
{/*You Can Get the ID from INT_config.h*/
    u8 n=(ID-16)%32;
    u16 ofst=0x300+(((ID-16)/32)*4);
    REG reg = INT+ofst;
    u8 data=GETBIT(*reg,n);
    return(data);
}
/*************************************************/
void INT_SetPriority(INT_ID_t ID,u8 priority)
{/*You Can Get the ID from INT_config.h ,, priority 0 --> 7 */
    u8 n=(ID-16)%4;
    u16 ofst=0x400+(((ID-16)/4)*4);
    REG reg = INT+ofst;
    u8 pins=(n+1)*5+n*3;
    u32 mask=((*reg)&(~(7<<pins)));
    mask|=(priority<<pins);
    *reg=mask;
}
/*************************************************/
u8 INT_GetPriority(INT_ID_t ID)
{/*You Can Get the ID from INT_config.h ,, priority 0 --> 7 */
    u8 n=(ID-16)%4;
    u16 ofst=0x400+(((ID-16)/4)*4);
    REG reg = INT+ofst;
    u8 pins=(n+1)*5+n*3;
    u8 data=((*reg>>pins)&3);
    return(data);
}
/*************************************************/
void isr_Empty (void)
{

    while(1)
        ;
}

  // g_pfnRAMVectors[46] = usr_isr_portF;
