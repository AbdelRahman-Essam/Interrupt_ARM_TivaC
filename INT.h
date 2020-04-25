/*
 * INT_init.h
 *
 *  Created on: Mar 4, 2020
 *      Author: Abdelrahman Essam
 */
#ifndef INT_H_
#define INT_H_

#include "Reg_map.h"
#include "utils.h"
#include "std_types.h"

extern void (*g_pfnRAMVectors[155])(void);
extern void (* g_pfnVectors[])(void);





typedef enum{INT_PortA=16,INT_PortB=17,INT_PortC=18,INT_PortD=19,INT_PortE=20,INT_PortF=46,UART0=21,UART1=22,SSI0=23,I2C0=24,
	PWM0_Fault=25,PWM0_Generator0=26,PWM0_Generator1=27,PWM0_Generator2=28,QEI0=29,
	INT_16Timer0A=35,INT_16Timer0B=36,INT_16Timer1A=37,INT_16Timer1B=38,INT_16Timer2A=39,
	INT_16Timer2B=40,INT_16Timer3A=51,INT_16Timer3B=52,INT_16Timer4A=86,INT_16Timer4B=87,
	INT_16Timer5A=108,INT_16Timer5B=109,INT_32Timer0A=110,INT_32Timer0B=111,INT_32Timer1A=112,INT_32Timer1B=113,INT_32Timer2A=114,
		INT_32Timer2B=115,INT_32Timer3A=116,INT_32Timer3B=117,INT_32Timer4A=118,INT_32Timer4B=119,
		INT_32Timer5A=120,INT_32Timer5B=121}INT_ID_t;


void isr_Empty (void);
void INT_Init(void);
void INT_Enable(u8 ID);
void INT_Disable(u8 ID);

void INT_SetPending(u8 ID);
void INT_ClearPending(u8 ID);
u8 INT_GetPending(u8 ID);

u8 INT_GetActiveState(u8 ID);
void INT_SetPriority(u8 ID,u8 priority);
u8 INT_GetPriority(u8 ID);
void usr_isr_portF(void);



#endif /* INT_H_ */
