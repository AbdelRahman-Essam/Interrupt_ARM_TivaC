/*
 * INT_prog.c
 *
 *  Created on: Mar 4, 2020
 *      Author: Abdelrahman Essam
 */
#ifndef INT_PROG_C_
#define INT_PROG_C_

#include <INT.h>




void INT_Init(void)
{
	extern void (* g_pfnVectors[])(void);

	#pragma DATA_ALIGN(g_pfnRAMVectors, 1024)
	#pragma DATA_SECTION(g_pfnRAMVectors, ".vtable")
	void (*g_pfnRAMVectors[155])(void);
	int i=0;
	for(i = 0; i < 155; i++)
	   {
           g_pfnRAMVectors[i] = g_pfnVectors[i];
       }
       REG reg     =   0xE000ED08 ;
       *reg = (unsigned long int)g_pfnRAMVectors; // Point the NVIC at the RAM vector table.
}
/*************************************************/
void INT_Enable(u8 ID)
{/*You Can Get the ID from INT_config.h*/
    u8 n=(ID-16)%32;
    u16 ofst=0x100+(((ID-16)/32)*4);
    REG reg = INT+ofst;
    SETBIT(*reg,n);
}
/*************************************************/
void INT_Disable(u8 ID)
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
void INT_SetPending(u8 ID)
{/*You Can Get the ID from INT_config.h*/
    u8 n=(ID-16)%32;
    u16 ofst=0x200+(((ID-16)/32)*4);
    REG reg = INT+ofst;
    SETBIT(*reg,n);
}
/*************************************************/
void INT_ClearPending(u8 ID)
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
u8 INT_GetPending(u8 ID)
{/*You Can Get the ID from INT_config.h*/
    u8 n=(ID-16)%32;
    u16 ofst=0x200+(((ID-16)/32)*4);
    REG reg = INT+ofst;
    u8 data=GETBIT(*reg,n);
    return(data);
}
/*************************************************/
u8 INT_GetActiveState(u8 ID)
{/*You Can Get the ID from INT_config.h*/
    u8 n=(ID-16)%32;
    u16 ofst=0x300+(((ID-16)/32)*4);
    REG reg = INT+ofst;
    u8 data=GETBIT(*reg,n);
    return(data);
}
/*************************************************/
void INT_SetPriority(u8 ID,u8 priority)
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
u8 INT_GetPriority(u8 ID)
{/*You Can Get the ID from INT_config.h ,, priority 0 --> 7 */
    u8 n=(ID-16)%4;
    u16 ofst=0x400+(((ID-16)/4)*4);
    REG reg = INT+ofst;
    u8 pins=(n+1)*5+n*3;
    u8 data=((*reg>>pins)&3);
    return(data);
}
/*************************************************/




   //
   // Save the interrupt handler.
   //
  // g_pfnRAMVectors[46] = usr_isr_portF;

#endif /* INT_PROG_C_ */
