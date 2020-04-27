/*
 * Reg_map.h
 *
 *  Created on: Feb 8, 2020
 *      Author: Abdelrahman Essam
 */

#ifndef REG_MAP_H_
#define REG_MAP_H_

/*
 * for port (A,B,C,D)
 *  AHB = base + 0x54000
 * for port (E,F)
 *  AHB = base + 0x38000
 */
/***********************SYSCTL**************************/
#define     SYSCTL          0x400FE000

#define     GPIOHBCTL       0x06C
#define		PRTIMER			0xA04
#define		PRWTIMER		0xA5C
/***********************GPIO****************************/
#define     PORTA_APB       0x40004000
#define     PORTA_AHB       0x40058000

#define     PORTB_APB       0x40005000
#define     PORTB_AHB       0x40059000

#define     PORTC_APB       0x40006000
#define     PORTC_AHB       0x4005A000

#define     PORTD_APB       0x40007000
#define     PORTD_AHB       0x4005B000

#define     PORTE_APB       0x40024000
#define     PORTE_AHB       0x4005C000

#define     PORTF_APB       0x40025000
#define     PORTF_AHB       0x4005D000


#define     GPIODATA        0x000
#define     GPIODIR         0x400
#define     GPIOAFSEL       0x420
#define     GPIODR2R        0x500
#define     GPIODR4R        0x504
#define     GPIODR8R        0x508
#define     GPIOODR         0x50C
#define     GPIOPUR         0x510
#define     GPIOPDR         0x514
#define     GPIOSLR         0x518
#define     GPIODEN         0x51C
#define     GPIOIM          0x410
#define     GPIOIS          0x404
#define     GPIOIEV         0x40C
#define     GPIOIBE         0x408
#define     GPIORIS         0x414
#define     GPIOMIS			0x418
#define     GPIOICR         0x41C

/**********************INT*****************************/
#define     INT             0xE000E000

#define     INT_UART0       5
#define     INT_UART1       6
#define     INT_SSI0        7
#define     INT_I2C0        8


#define     EN0             0x100
#define     PRI7            0x41C
#define     PEND0           0x200

/***********************GPTM*******************************/
#define		GPTMCFG			0x000
#define		GPTMTAMR		0x004
#define 	GPTMTBMR		0x008
#define		GPTMCTL			0x00C
#define 	GPTMSYNC		0x010
#define		GPTMIMR			0x018
#define		GPTMRIS			0x01C
#define		GPTMMIS			0x020
#define		GPTMICR			0x024
#define 	GPTMTAILR		0x028
#define		GPTMTBILR		0x02C
#define		GPTMTAMATCHR	0x030
#define		GPTMTBMATCHR	0x034
#define		GPTMTAPR		0x038
#define		GPTMTBPR		0x03C
#define		GPTMTAPMR		0x040
#define		GPTMTBPMR		0x044
#define		GPTMTAR			0x048
#define		GPTMTBR			0x04C
#define 	GPTMTAV			0x050
#define		GPTMTBV			0x054
#define		GPTMRTCPD		0x058
#define		GPTMTAPS		0x060

#define TIMER0_TAILR_R          (*((volatile u32 *)0x40030028))
#define TIMER0_IMR_R            (*((volatile u32 *)0x40030018))
#define TIMER0_CTL_R            (*((volatile u32 *)0x4003000C))
#define TIMER0_ICR_R            (*((volatile u32 *)0x40030024))
#define TIMER0_CFG_R            (*((volatile u32 *)0x40030000))
#define TIMER0_TAMR_R           (*((volatile u32 *)0x40030004))


//*****************************************************************************
//
// System Control registers (SYSCTL)
//
//*****************************************************************************
#define SYSCTL_DID0_R           (*((volatile u32 *)0x400FE000))
#define SYSCTL_DID1_R           (*((volatile u32 *)0x400FE004))
#define SYSCTL_DC0_R            (*((volatile u32 *)0x400FE008))
#define SYSCTL_DC1_R            (*((volatile u32 *)0x400FE010))
#define SYSCTL_DC2_R            (*((volatile u32 *)0x400FE014))
#define SYSCTL_DC3_R            (*((volatile u32 *)0x400FE018))
#define SYSCTL_DC4_R            (*((volatile u32 *)0x400FE01C))
#define SYSCTL_DC5_R            (*((volatile u32 *)0x400FE020))
#define SYSCTL_DC6_R            (*((volatile u32 *)0x400FE024))
#define SYSCTL_DC7_R            (*((volatile u32 *)0x400FE028))
#define SYSCTL_DC8_R            (*((volatile u32 *)0x400FE02C))
#define SYSCTL_PBORCTL_R        (*((volatile u32 *)0x400FE030))
#define SYSCTL_SRCR0_R          (*((volatile u32 *)0x400FE040))
#define SYSCTL_SRCR1_R          (*((volatile u32 *)0x400FE044))
#define SYSCTL_SRCR2_R          (*((volatile u32 *)0x400FE048))
#define SYSCTL_RIS_R            (*((volatile u32 *)0x400FE050))
#define SYSCTL_IMC_R            (*((volatile u32 *)0x400FE054))
#define SYSCTL_MISC_R           (*((volatile u32 *)0x400FE058))
#define SYSCTL_RESC_R           (*((volatile u32 *)0x400FE05C))
#define SYSCTL_RCC_R            (*((volatile u32 *)0x400FE060))
#define SYSCTL_GPIOHBCTL_R      (*((volatile u32 *)0x400FE06C))
#define SYSCTL_RCC2_R           (*((volatile u32 *)0x400FE070))
#define SYSCTL_MOSCCTL_R        (*((volatile u32 *)0x400FE07C))
#define SYSCTL_RCGC0_R          (*((volatile u32 *)0x400FE100))
#define SYSCTL_RCGC1_R          (*((volatile u32 *)0x400FE104))
#define SYSCTL_RCGC2_R          (*((volatile u32 *)0x400FE108))
#define SYSCTL_SCGC0_R          (*((volatile u32 *)0x400FE110))
#define SYSCTL_SCGC1_R          (*((volatile u32 *)0x400FE114))
#define SYSCTL_SCGC2_R          (*((volatile u32 *)0x400FE118))
#define SYSCTL_DCGC0_R          (*((volatile u32 *)0x400FE120))
#define SYSCTL_DCGC1_R          (*((volatile u32 *)0x400FE124))
#define SYSCTL_DCGC2_R          (*((volatile u32 *)0x400FE128))
#define SYSCTL_DSLPCLKCFG_R     (*((volatile u32 *)0x400FE144))
#define SYSCTL_SYSPROP_R        (*((volatile u32 *)0x400FE14C))
#define SYSCTL_PIOSCCAL_R       (*((volatile u32 *)0x400FE150))
#define SYSCTL_PIOSCSTAT_R      (*((volatile u32 *)0x400FE154))
#define SYSCTL_PLLFREQ0_R       (*((volatile u32 *)0x400FE160))
#define SYSCTL_PLLFREQ1_R       (*((volatile u32 *)0x400FE164))
#define SYSCTL_PLLSTAT_R        (*((volatile u32 *)0x400FE168))
#define SYSCTL_SLPPWRCFG_R      (*((volatile u32 *)0x400FE188))
#define SYSCTL_DSLPPWRCFG_R     (*((volatile u32 *)0x400FE18C))
#define SYSCTL_DC9_R            (*((volatile u32 *)0x400FE190))
#define SYSCTL_NVMSTAT_R        (*((volatile u32 *)0x400FE1A0))
#define SYSCTL_LDOSPCTL_R       (*((volatile u32 *)0x400FE1B4))
#define SYSCTL_LDODPCTL_R       (*((volatile u32 *)0x400FE1BC))
#define SYSCTL_PPWD_R           (*((volatile u32 *)0x400FE300))
#define SYSCTL_PPTIMER_R        (*((volatile u32 *)0x400FE304))
#define SYSCTL_PPGPIO_R         (*((volatile u32 *)0x400FE308))
#define SYSCTL_PPDMA_R          (*((volatile u32 *)0x400FE30C))
#define SYSCTL_PPHIB_R          (*((volatile u32 *)0x400FE314))
#define SYSCTL_PPUART_R         (*((volatile u32 *)0x400FE318))
#define SYSCTL_PPSSI_R          (*((volatile u32 *)0x400FE31C))
#define SYSCTL_PPI2C_R          (*((volatile u32 *)0x400FE320))
#define SYSCTL_PPUSB_R          (*((volatile u32 *)0x400FE328))
#define SYSCTL_PPCAN_R          (*((volatile u32 *)0x400FE334))
#define SYSCTL_PPADC_R          (*((volatile u32 *)0x400FE338))
#define SYSCTL_PPACMP_R         (*((volatile u32 *)0x400FE33C))
#define SYSCTL_PPPWM_R          (*((volatile u32 *)0x400FE340))
#define SYSCTL_PPQEI_R          (*((volatile u32 *)0x400FE344))
#define SYSCTL_PPEEPROM_R       (*((volatile u32 *)0x400FE358))
#define SYSCTL_PPWTIMER_R       (*((volatile u32 *)0x400FE35C))
#define SYSCTL_SRWD_R           (*((volatile u32 *)0x400FE500))
#define SYSCTL_SRTIMER_R        (*((volatile u32 *)0x400FE504))
#define SYSCTL_SRGPIO_R         (*((volatile u32 *)0x400FE508))
#define SYSCTL_SRDMA_R          (*((volatile u32 *)0x400FE50C))
#define SYSCTL_SRHIB_R          (*((volatile u32 *)0x400FE514))
#define SYSCTL_SRUART_R         (*((volatile u32 *)0x400FE518))
#define SYSCTL_SRSSI_R          (*((volatile u32 *)0x400FE51C))
#define SYSCTL_SRI2C_R          (*((volatile u32 *)0x400FE520))
#define SYSCTL_SRUSB_R          (*((volatile u32 *)0x400FE528))
#define SYSCTL_SRCAN_R          (*((volatile u32 *)0x400FE534))
#define SYSCTL_SRADC_R          (*((volatile u32 *)0x400FE538))
#define SYSCTL_SRACMP_R         (*((volatile u32 *)0x400FE53C))
#define SYSCTL_SRPWM_R          (*((volatile u32 *)0x400FE540))
#define SYSCTL_SRQEI_R          (*((volatile u32 *)0x400FE544))
#define SYSCTL_SREEPROM_R       (*((volatile u32 *)0x400FE558))
#define SYSCTL_SRWTIMER_R       (*((volatile u32 *)0x400FE55C))
#define SYSCTL_RCGCWD_R         (*((volatile u32 *)0x400FE600))
#define SYSCTL_RCGCTIMER_R      (*((volatile u32 *)0x400FE604))
#define SYSCTL_RCGCGPIO_R       (*((volatile u32 *)0x400FE608))
#define SYSCTL_RCGCDMA_R        (*((volatile u32 *)0x400FE60C))
#define SYSCTL_RCGCHIB_R        (*((volatile u32 *)0x400FE614))
#define SYSCTL_RCGCUART_R       (*((volatile u32 *)0x400FE618))
#define SYSCTL_RCGCSSI_R        (*((volatile u32 *)0x400FE61C))
#define SYSCTL_RCGCI2C_R        (*((volatile u32 *)0x400FE620))
#define SYSCTL_RCGCUSB_R        (*((volatile u32 *)0x400FE628))
#define SYSCTL_RCGCCAN_R        (*((volatile u32 *)0x400FE634))
#define SYSCTL_RCGCADC_R        (*((volatile u32 *)0x400FE638))
#define SYSCTL_RCGCACMP_R       (*((volatile u32 *)0x400FE63C))
#define SYSCTL_RCGCPWM_R        (*((volatile u32 *)0x400FE640))
#define SYSCTL_RCGCQEI_R        (*((volatile u32 *)0x400FE644))
#define SYSCTL_RCGCEEPROM_R     (*((volatile u32 *)0x400FE658))
#define SYSCTL_RCGCWTIMER_R     (*((volatile u32 *)0x400FE65C))
#define SYSCTL_SCGCWD_R         (*((volatile u32 *)0x400FE700))
#define SYSCTL_SCGCTIMER_R      (*((volatile u32 *)0x400FE704))
#define SYSCTL_SCGCGPIO_R       (*((volatile u32 *)0x400FE708))
#define SYSCTL_SCGCDMA_R        (*((volatile u32 *)0x400FE70C))
#define SYSCTL_SCGCHIB_R        (*((volatile u32 *)0x400FE714))
#define SYSCTL_SCGCUART_R       (*((volatile u32 *)0x400FE718))
#define SYSCTL_SCGCSSI_R        (*((volatile u32 *)0x400FE71C))
#define SYSCTL_SCGCI2C_R        (*((volatile u32 *)0x400FE720))
#define SYSCTL_SCGCUSB_R        (*((volatile u32 *)0x400FE728))
#define SYSCTL_SCGCCAN_R        (*((volatile u32 *)0x400FE734))
#define SYSCTL_SCGCADC_R        (*((volatile u32 *)0x400FE738))
#define SYSCTL_SCGCACMP_R       (*((volatile u32 *)0x400FE73C))
#define SYSCTL_SCGCPWM_R        (*((volatile u32 *)0x400FE740))
#define SYSCTL_SCGCQEI_R        (*((volatile u32 *)0x400FE744))
#define SYSCTL_SCGCEEPROM_R     (*((volatile u32 *)0x400FE758))
#define SYSCTL_SCGCWTIMER_R     (*((volatile u32 *)0x400FE75C))
#define SYSCTL_DCGCWD_R         (*((volatile u32 *)0x400FE800))
#define SYSCTL_DCGCTIMER_R      (*((volatile u32 *)0x400FE804))
#define SYSCTL_DCGCGPIO_R       (*((volatile u32 *)0x400FE808))
#define SYSCTL_DCGCDMA_R        (*((volatile u32 *)0x400FE80C))
#define SYSCTL_DCGCHIB_R        (*((volatile u32 *)0x400FE814))
#define SYSCTL_DCGCUART_R       (*((volatile u32 *)0x400FE818))
#define SYSCTL_DCGCSSI_R        (*((volatile u32 *)0x400FE81C))
#define SYSCTL_DCGCI2C_R        (*((volatile u32 *)0x400FE820))
#define SYSCTL_DCGCUSB_R        (*((volatile u32 *)0x400FE828))
#define SYSCTL_DCGCCAN_R        (*((volatile u32 *)0x400FE834))
#define SYSCTL_DCGCADC_R        (*((volatile u32 *)0x400FE838))
#define SYSCTL_DCGCACMP_R       (*((volatile u32 *)0x400FE83C))
#define SYSCTL_DCGCPWM_R        (*((volatile u32 *)0x400FE840))
#define SYSCTL_DCGCQEI_R        (*((volatile u32 *)0x400FE844))
#define SYSCTL_DCGCEEPROM_R     (*((volatile u32 *)0x400FE858))
#define SYSCTL_DCGCWTIMER_R     (*((volatile u32 *)0x400FE85C))
#define SYSCTL_PRWD_R           (*((volatile u32 *)0x400FEA00))
#define SYSCTL_PRTIMER_R        (*((volatile u32 *)0x400FEA04))
#define SYSCTL_PRGPIO_R         (*((volatile u32 *)0x400FEA08))
#define SYSCTL_PRDMA_R          (*((volatile u32 *)0x400FEA0C))
#define SYSCTL_PRHIB_R          (*((volatile u32 *)0x400FEA14))
#define SYSCTL_PRUART_R         (*((volatile u32 *)0x400FEA18))
#define SYSCTL_PRSSI_R          (*((volatile u32 *)0x400FEA1C))
#define SYSCTL_PRI2C_R          (*((volatile u32 *)0x400FEA20))
#define SYSCTL_PRUSB_R          (*((volatile u32 *)0x400FEA28))
#define SYSCTL_PRCAN_R          (*((volatile u32 *)0x400FEA34))
#define SYSCTL_PRADC_R          (*((volatile u32 *)0x400FEA38))
#define SYSCTL_PRACMP_R         (*((volatile u32 *)0x400FEA3C))
#define SYSCTL_PRPWM_R          (*((volatile u32 *)0x400FEA40))
#define SYSCTL_PRQEI_R          (*((volatile u32 *)0x400FEA44))
#define SYSCTL_PREEPROM_R       (*((volatile u32 *)0x400FEA58))
#define SYSCTL_PRWTIMER_R       (*((volatile u32 *)0x400FEA5C))

//*****************************************************************************
//
// GPIO registers (PORTA AHB)
//
//*****************************************************************************
#define GPIO_PORTA_AHB_DATA_BITS_R                                            \
                                ((  volatile u32 *)0x40058000)
#define GPIO_PORTA_AHB_DATA_R   (*((volatile u32 *)0x400583FC))
#define GPIO_PORTA_AHB_DIR_R    (*((volatile u32 *)0x40058400))
#define GPIO_PORTA_AHB_IS_R     (*((volatile u32 *)0x40058404))
#define GPIO_PORTA_AHB_IBE_R    (*((volatile u32 *)0x40058408))
#define GPIO_PORTA_AHB_IEV_R    (*((volatile u32 *)0x4005840C))
#define GPIO_PORTA_AHB_IM_R     (*((volatile u32 *)0x40058410))
#define GPIO_PORTA_AHB_RIS_R    (*((volatile u32 *)0x40058414))
#define GPIO_PORTA_AHB_MIS_R    (*((volatile u32 *)0x40058418))
#define GPIO_PORTA_AHB_ICR_R    (*((volatile u32 *)0x4005841C))
#define GPIO_PORTA_AHB_AFSEL_R  (*((volatile u32 *)0x40058420))
#define GPIO_PORTA_AHB_DR2R_R   (*((volatile u32 *)0x40058500))
#define GPIO_PORTA_AHB_DR4R_R   (*((volatile u32 *)0x40058504))
#define GPIO_PORTA_AHB_DR8R_R   (*((volatile u32 *)0x40058508))
#define GPIO_PORTA_AHB_ODR_R    (*((volatile u32 *)0x4005850C))
#define GPIO_PORTA_AHB_PUR_R    (*((volatile u32 *)0x40058510))
#define GPIO_PORTA_AHB_PDR_R    (*((volatile u32 *)0x40058514))
#define GPIO_PORTA_AHB_SLR_R    (*((volatile u32 *)0x40058518))
#define GPIO_PORTA_AHB_DEN_R    (*((volatile u32 *)0x4005851C))
#define GPIO_PORTA_AHB_LOCK_R   (*((volatile u32 *)0x40058520))
#define GPIO_PORTA_AHB_CR_R     (*((volatile u32 *)0x40058524))
#define GPIO_PORTA_AHB_AMSEL_R  (*((volatile u32 *)0x40058528))
#define GPIO_PORTA_AHB_PCTL_R   (*((volatile u32 *)0x4005852C))
#define GPIO_PORTA_AHB_ADCCTL_R (*((volatile u32 *)0x40058530))
#define GPIO_PORTA_AHB_DMACTL_R (*((volatile u32 *)0x40058534))

//*****************************************************************************
//
// GPIO registers (PORTB AHB)
//
//*****************************************************************************
#define GPIO_PORTB_AHB_DATA_BITS_R                                            \
                                ((volatile u32 *)0x40059000)
#define GPIO_PORTB_AHB_DATA_R   (*((volatile u32 *)0x400593FC))
#define GPIO_PORTB_AHB_DIR_R    (*((volatile u32 *)0x40059400))
#define GPIO_PORTB_AHB_IS_R     (*((volatile u32 *)0x40059404))
#define GPIO_PORTB_AHB_IBE_R    (*((volatile u32 *)0x40059408))
#define GPIO_PORTB_AHB_IEV_R    (*((volatile u32 *)0x4005940C))
#define GPIO_PORTB_AHB_IM_R     (*((volatile u32 *)0x40059410))
#define GPIO_PORTB_AHB_RIS_R    (*((volatile u32 *)0x40059414))
#define GPIO_PORTB_AHB_MIS_R    (*((volatile u32 *)0x40059418))
#define GPIO_PORTB_AHB_ICR_R    (*((volatile u32 *)0x4005941C))
#define GPIO_PORTB_AHB_AFSEL_R  (*((volatile u32 *)0x40059420))
#define GPIO_PORTB_AHB_DR2R_R   (*((volatile u32 *)0x40059500))
#define GPIO_PORTB_AHB_DR4R_R   (*((volatile u32 *)0x40059504))
#define GPIO_PORTB_AHB_DR8R_R   (*((volatile u32 *)0x40059508))
#define GPIO_PORTB_AHB_ODR_R    (*((volatile u32 *)0x4005950C))
#define GPIO_PORTB_AHB_PUR_R    (*((volatile u32 *)0x40059510))
#define GPIO_PORTB_AHB_PDR_R    (*((volatile u32 *)0x40059514))
#define GPIO_PORTB_AHB_SLR_R    (*((volatile u32 *)0x40059518))
#define GPIO_PORTB_AHB_DEN_R    (*((volatile u32 *)0x4005951C))
#define GPIO_PORTB_AHB_LOCK_R   (*((volatile u32 *)0x40059520))
#define GPIO_PORTB_AHB_CR_R     (*((volatile u32 *)0x40059524))
#define GPIO_PORTB_AHB_AMSEL_R  (*((volatile u32 *)0x40059528))
#define GPIO_PORTB_AHB_PCTL_R   (*((volatile u32 *)0x4005952C))
#define GPIO_PORTB_AHB_ADCCTL_R (*((volatile u32 *)0x40059530))
#define GPIO_PORTB_AHB_DMACTL_R (*((volatile u32 *)0x40059534))

//*****************************************************************************
//
// GPIO registers (PORTC AHB)
//
//*****************************************************************************
#define GPIO_PORTC_AHB_DATA_BITS_R                                            \
                                ((volatile u32 *)0x4005A000)
#define GPIO_PORTC_AHB_DATA_R   (*((volatile u32 *)0x4005A3FC))
#define GPIO_PORTC_AHB_DIR_R    (*((volatile u32 *)0x4005A400))
#define GPIO_PORTC_AHB_IS_R     (*((volatile u32 *)0x4005A404))
#define GPIO_PORTC_AHB_IBE_R    (*((volatile u32 *)0x4005A408))
#define GPIO_PORTC_AHB_IEV_R    (*((volatile u32 *)0x4005A40C))
#define GPIO_PORTC_AHB_IM_R     (*((volatile u32 *)0x4005A410))
#define GPIO_PORTC_AHB_RIS_R    (*((volatile u32 *)0x4005A414))
#define GPIO_PORTC_AHB_MIS_R    (*((volatile u32 *)0x4005A418))
#define GPIO_PORTC_AHB_ICR_R    (*((volatile u32 *)0x4005A41C))
#define GPIO_PORTC_AHB_AFSEL_R  (*((volatile u32 *)0x4005A420))
#define GPIO_PORTC_AHB_DR2R_R   (*((volatile u32 *)0x4005A500))
#define GPIO_PORTC_AHB_DR4R_R   (*((volatile u32 *)0x4005A504))
#define GPIO_PORTC_AHB_DR8R_R   (*((volatile u32 *)0x4005A508))
#define GPIO_PORTC_AHB_ODR_R    (*((volatile u32 *)0x4005A50C))
#define GPIO_PORTC_AHB_PUR_R    (*((volatile u32 *)0x4005A510))
#define GPIO_PORTC_AHB_PDR_R    (*((volatile u32 *)0x4005A514))
#define GPIO_PORTC_AHB_SLR_R    (*((volatile u32 *)0x4005A518))
#define GPIO_PORTC_AHB_DEN_R    (*((volatile u32 *)0x4005A51C))
#define GPIO_PORTC_AHB_LOCK_R   (*((volatile u32 *)0x4005A520))
#define GPIO_PORTC_AHB_CR_R     (*((volatile u32 *)0x4005A524))
#define GPIO_PORTC_AHB_AMSEL_R  (*((volatile u32 *)0x4005A528))
#define GPIO_PORTC_AHB_PCTL_R   (*((volatile u32 *)0x4005A52C))
#define GPIO_PORTC_AHB_ADCCTL_R (*((volatile u32 *)0x4005A530))
#define GPIO_PORTC_AHB_DMACTL_R (*((volatile u32 *)0x4005A534))

//*****************************************************************************
//
// GPIO registers (PORTD AHB)
//
//*****************************************************************************
#define GPIO_PORTD_AHB_DATA_BITS_R                                            \
                                ((volatile u32 *)0x4005B000)
#define GPIO_PORTD_AHB_DATA_R   (*((volatile u32 *)0x4005B3FC))
#define GPIO_PORTD_AHB_DIR_R    (*((volatile u32 *)0x4005B400))
#define GPIO_PORTD_AHB_IS_R     (*((volatile u32 *)0x4005B404))
#define GPIO_PORTD_AHB_IBE_R    (*((volatile u32 *)0x4005B408))
#define GPIO_PORTD_AHB_IEV_R    (*((volatile u32 *)0x4005B40C))
#define GPIO_PORTD_AHB_IM_R     (*((volatile u32 *)0x4005B410))
#define GPIO_PORTD_AHB_RIS_R    (*((volatile u32 *)0x4005B414))
#define GPIO_PORTD_AHB_MIS_R    (*((volatile u32 *)0x4005B418))
#define GPIO_PORTD_AHB_ICR_R    (*((volatile u32 *)0x4005B41C))
#define GPIO_PORTD_AHB_AFSEL_R  (*((volatile u32 *)0x4005B420))
#define GPIO_PORTD_AHB_DR2R_R   (*((volatile u32 *)0x4005B500))
#define GPIO_PORTD_AHB_DR4R_R   (*((volatile u32 *)0x4005B504))
#define GPIO_PORTD_AHB_DR8R_R   (*((volatile u32 *)0x4005B508))
#define GPIO_PORTD_AHB_ODR_R    (*((volatile u32 *)0x4005B50C))
#define GPIO_PORTD_AHB_PUR_R    (*((volatile u32 *)0x4005B510))
#define GPIO_PORTD_AHB_PDR_R    (*((volatile u32 *)0x4005B514))
#define GPIO_PORTD_AHB_SLR_R    (*((volatile u32 *)0x4005B518))
#define GPIO_PORTD_AHB_DEN_R    (*((volatile u32 *)0x4005B51C))
#define GPIO_PORTD_AHB_LOCK_R   (*((volatile u32 *)0x4005B520))
#define GPIO_PORTD_AHB_CR_R     (*((volatile u32 *)0x4005B524))
#define GPIO_PORTD_AHB_AMSEL_R  (*((volatile u32 *)0x4005B528))
#define GPIO_PORTD_AHB_PCTL_R   (*((volatile u32 *)0x4005B52C))
#define GPIO_PORTD_AHB_ADCCTL_R (*((volatile u32 *)0x4005B530))
#define GPIO_PORTD_AHB_DMACTL_R (*((volatile u32 *)0x4005B534))

//*****************************************************************************
//
// GPIO registers (PORTE AHB)
//
//*****************************************************************************
#define GPIO_PORTE_AHB_DATA_BITS_R                                            \
                                ((volatile u32 *)0x4005C000)
#define GPIO_PORTE_AHB_DATA_R   (*((volatile u32 *)0x4005C3FC))
#define GPIO_PORTE_AHB_DIR_R    (*((volatile u32 *)0x4005C400))
#define GPIO_PORTE_AHB_IS_R     (*((volatile u32 *)0x4005C404))
#define GPIO_PORTE_AHB_IBE_R    (*((volatile u32 *)0x4005C408))
#define GPIO_PORTE_AHB_IEV_R    (*((volatile u32 *)0x4005C40C))
#define GPIO_PORTE_AHB_IM_R     (*((volatile u32 *)0x4005C410))
#define GPIO_PORTE_AHB_RIS_R    (*((volatile u32 *)0x4005C414))
#define GPIO_PORTE_AHB_MIS_R    (*((volatile u32 *)0x4005C418))
#define GPIO_PORTE_AHB_ICR_R    (*((volatile u32 *)0x4005C41C))
#define GPIO_PORTE_AHB_AFSEL_R  (*((volatile u32 *)0x4005C420))
#define GPIO_PORTE_AHB_DR2R_R   (*((volatile u32 *)0x4005C500))
#define GPIO_PORTE_AHB_DR4R_R   (*((volatile u32 *)0x4005C504))
#define GPIO_PORTE_AHB_DR8R_R   (*((volatile u32 *)0x4005C508))
#define GPIO_PORTE_AHB_ODR_R    (*((volatile u32 *)0x4005C50C))
#define GPIO_PORTE_AHB_PUR_R    (*((volatile u32 *)0x4005C510))
#define GPIO_PORTE_AHB_PDR_R    (*((volatile u32 *)0x4005C514))
#define GPIO_PORTE_AHB_SLR_R    (*((volatile u32 *)0x4005C518))
#define GPIO_PORTE_AHB_DEN_R    (*((volatile u32 *)0x4005C51C))
#define GPIO_PORTE_AHB_LOCK_R   (*((volatile u32 *)0x4005C520))
#define GPIO_PORTE_AHB_CR_R     (*((volatile u32 *)0x4005C524))
#define GPIO_PORTE_AHB_AMSEL_R  (*((volatile u32 *)0x4005C528))
#define GPIO_PORTE_AHB_PCTL_R   (*((volatile u32 *)0x4005C52C))
#define GPIO_PORTE_AHB_ADCCTL_R (*((volatile u32 *)0x4005C530))
#define GPIO_PORTE_AHB_DMACTL_R (*((volatile u32 *)0x4005C534))

//*****************************************************************************
//
// GPIO registers (PORTF AHB)
//
//*****************************************************************************
#define GPIO_PORTF_AHB_DATA_BITS_R                                            \
                                ((volatile u32 *)0x4005D000)
#define GPIO_PORTF_AHB_DATA_R   (*((volatile u32 *)0x4005D3FC))
#define GPIO_PORTF_AHB_DIR_R    (*((volatile u32 *)0x4005D400))
#define GPIO_PORTF_AHB_IS_R     (*((volatile u32 *)0x4005D404))
#define GPIO_PORTF_AHB_IBE_R    (*((volatile u32 *)0x4005D408))
#define GPIO_PORTF_AHB_IEV_R    (*((volatile u32 *)0x4005D40C))
#define GPIO_PORTF_AHB_IM_R     (*((volatile u32 *)0x4005D410))
#define GPIO_PORTF_AHB_RIS_R    (*((volatile u32 *)0x4005D414))
#define GPIO_PORTF_AHB_MIS_R    (*((volatile u32 *)0x4005D418))
#define GPIO_PORTF_AHB_ICR_R    (*((volatile u32 *)0x4005D41C))
#define GPIO_PORTF_AHB_AFSEL_R  (*((volatile u32 *)0x4005D420))
#define GPIO_PORTF_AHB_DR2R_R   (*((volatile u32 *)0x4005D500))
#define GPIO_PORTF_AHB_DR4R_R   (*((volatile u32 *)0x4005D504))
#define GPIO_PORTF_AHB_DR8R_R   (*((volatile u32 *)0x4005D508))
#define GPIO_PORTF_AHB_ODR_R    (*((volatile u32 *)0x4005D50C))
#define GPIO_PORTF_AHB_PUR_R    (*((volatile u32 *)0x4005D510))
#define GPIO_PORTF_AHB_PDR_R    (*((volatile u32 *)0x4005D514))
#define GPIO_PORTF_AHB_SLR_R    (*((volatile u32 *)0x4005D518))
#define GPIO_PORTF_AHB_DEN_R    (*((volatile u32 *)0x4005D51C))
#define GPIO_PORTF_AHB_LOCK_R   (*((volatile u32 *)0x4005D520))
#define GPIO_PORTF_AHB_CR_R     (*((volatile u32 *)0x4005D524))
#define GPIO_PORTF_AHB_AMSEL_R  (*((volatile u32 *)0x4005D528))
#define GPIO_PORTF_AHB_PCTL_R   (*((volatile u32 *)0x4005D52C))
#define GPIO_PORTF_AHB_ADCCTL_R (*((volatile u32 *)0x4005D530))
#define GPIO_PORTF_AHB_DMACTL_R (*((volatile u32 *)0x4005D534))

//*****************************************************************************
//
// GPIO registers (PORTA)
//
//*****************************************************************************
#define GPIO_PORTA_DATA_BITS_R  ((volatile   u32 *)0x40004000)
#define GPIO_PORTA_DATA_R       (*((volatile u32 *)0x400043FC))
#define GPIO_PORTA_DIR_R        (*((volatile u32 *)0x40004400))
#define GPIO_PORTA_IS_R         (*((volatile u32 *)0x40004404))
#define GPIO_PORTA_IBE_R        (*((volatile u32 *)0x40004408))
#define GPIO_PORTA_IEV_R        (*((volatile u32 *)0x4000440C))
#define GPIO_PORTA_IM_R         (*((volatile u32 *)0x40004410))
#define GPIO_PORTA_RIS_R        (*((volatile u32 *)0x40004414))
#define GPIO_PORTA_MIS_R        (*((volatile u32 *)0x40004418))
#define GPIO_PORTA_ICR_R        (*((volatile u32 *)0x4000441C))
#define GPIO_PORTA_AFSEL_R      (*((volatile u32 *)0x40004420))
#define GPIO_PORTA_DR2R_R       (*((volatile u32 *)0x40004500))
#define GPIO_PORTA_DR4R_R       (*((volatile u32 *)0x40004504))
#define GPIO_PORTA_DR8R_R       (*((volatile u32 *)0x40004508))
#define GPIO_PORTA_ODR_R        (*((volatile u32 *)0x4000450C))
#define GPIO_PORTA_PUR_R        (*((volatile u32 *)0x40004510))
#define GPIO_PORTA_PDR_R        (*((volatile u32 *)0x40004514))
#define GPIO_PORTA_SLR_R        (*((volatile u32 *)0x40004518))
#define GPIO_PORTA_DEN_R        (*((volatile u32 *)0x4000451C))
#define GPIO_PORTA_LOCK_R       (*((volatile u32 *)0x40004520))
#define GPIO_PORTA_CR_R         (*((volatile u32 *)0x40004524))
#define GPIO_PORTA_AMSEL_R      (*((volatile u32 *)0x40004528))
#define GPIO_PORTA_PCTL_R       (*((volatile u32 *)0x4000452C))
#define GPIO_PORTA_ADCCTL_R     (*((volatile u32 *)0x40004530))
#define GPIO_PORTA_DMACTL_R     (*((volatile u32 *)0x40004534))

//*****************************************************************************
//
// GPIO registers (PORTB)
//
//*****************************************************************************
#define GPIO_PORTB_DATA_BITS_R  ((  volatile u32 *)0x40005000)
#define GPIO_PORTB_DATA_R       (*((volatile u32 *)0x400053FC))
#define GPIO_PORTB_DIR_R        (*((volatile u32 *)0x40005400))
#define GPIO_PORTB_IS_R         (*((volatile u32 *)0x40005404))
#define GPIO_PORTB_IBE_R        (*((volatile u32 *)0x40005408))
#define GPIO_PORTB_IEV_R        (*((volatile u32 *)0x4000540C))
#define GPIO_PORTB_IM_R         (*((volatile u32 *)0x40005410))
#define GPIO_PORTB_RIS_R        (*((volatile u32 *)0x40005414))
#define GPIO_PORTB_MIS_R        (*((volatile u32 *)0x40005418))
#define GPIO_PORTB_ICR_R        (*((volatile u32 *)0x4000541C))
#define GPIO_PORTB_AFSEL_R      (*((volatile u32 *)0x40005420))
#define GPIO_PORTB_DR2R_R       (*((volatile u32 *)0x40005500))
#define GPIO_PORTB_DR4R_R       (*((volatile u32 *)0x40005504))
#define GPIO_PORTB_DR8R_R       (*((volatile u32 *)0x40005508))
#define GPIO_PORTB_ODR_R        (*((volatile u32 *)0x4000550C))
#define GPIO_PORTB_PUR_R        (*((volatile u32 *)0x40005510))
#define GPIO_PORTB_PDR_R        (*((volatile u32 *)0x40005514))
#define GPIO_PORTB_SLR_R        (*((volatile u32 *)0x40005518))
#define GPIO_PORTB_DEN_R        (*((volatile u32 *)0x4000551C))
#define GPIO_PORTB_LOCK_R       (*((volatile u32 *)0x40005520))
#define GPIO_PORTB_CR_R         (*((volatile u32 *)0x40005524))
#define GPIO_PORTB_AMSEL_R      (*((volatile u32 *)0x40005528))
#define GPIO_PORTB_PCTL_R       (*((volatile u32 *)0x4000552C))
#define GPIO_PORTB_ADCCTL_R     (*((volatile u32 *)0x40005530))
#define GPIO_PORTB_DMACTL_R     (*((volatile u32 *)0x40005534))

//*****************************************************************************
//
// GPIO registers (PORTC)
//
//*****************************************************************************
#define GPIO_PORTC_DATA_BITS_R  ((  volatile u32 *)0x40006000)
#define GPIO_PORTC_DATA_R       (*((volatile u32 *)0x400063FC))
#define GPIO_PORTC_DIR_R        (*((volatile u32 *)0x40006400))
#define GPIO_PORTC_IS_R         (*((volatile u32 *)0x40006404))
#define GPIO_PORTC_IBE_R        (*((volatile u32 *)0x40006408))
#define GPIO_PORTC_IEV_R        (*((volatile u32 *)0x4000640C))
#define GPIO_PORTC_IM_R         (*((volatile u32 *)0x40006410))
#define GPIO_PORTC_RIS_R        (*((volatile u32 *)0x40006414))
#define GPIO_PORTC_MIS_R        (*((volatile u32 *)0x40006418))
#define GPIO_PORTC_ICR_R        (*((volatile u32 *)0x4000641C))
#define GPIO_PORTC_AFSEL_R      (*((volatile u32 *)0x40006420))
#define GPIO_PORTC_DR2R_R       (*((volatile u32 *)0x40006500))
#define GPIO_PORTC_DR4R_R       (*((volatile u32 *)0x40006504))
#define GPIO_PORTC_DR8R_R       (*((volatile u32 *)0x40006508))
#define GPIO_PORTC_ODR_R        (*((volatile u32 *)0x4000650C))
#define GPIO_PORTC_PUR_R        (*((volatile u32 *)0x40006510))
#define GPIO_PORTC_PDR_R        (*((volatile u32 *)0x40006514))
#define GPIO_PORTC_SLR_R        (*((volatile u32 *)0x40006518))
#define GPIO_PORTC_DEN_R        (*((volatile u32 *)0x4000651C))
#define GPIO_PORTC_LOCK_R       (*((volatile u32 *)0x40006520))
#define GPIO_PORTC_CR_R         (*((volatile u32 *)0x40006524))
#define GPIO_PORTC_AMSEL_R      (*((volatile u32 *)0x40006528))
#define GPIO_PORTC_PCTL_R       (*((volatile u32 *)0x4000652C))
#define GPIO_PORTC_ADCCTL_R     (*((volatile u32 *)0x40006530))
#define GPIO_PORTC_DMACTL_R     (*((volatile u32 *)0x40006534))

//*****************************************************************************
//
// GPIO registers (PORTD)
//
//*****************************************************************************
#define GPIO_PORTD_DATA_BITS_R  ((  volatile u32 *)0x40007000)
#define GPIO_PORTD_DATA_R       (*((volatile u32 *)0x400073FC))
#define GPIO_PORTD_DIR_R        (*((volatile u32 *)0x40007400))
#define GPIO_PORTD_IS_R         (*((volatile u32 *)0x40007404))
#define GPIO_PORTD_IBE_R        (*((volatile u32 *)0x40007408))
#define GPIO_PORTD_IEV_R        (*((volatile u32 *)0x4000740C))
#define GPIO_PORTD_IM_R         (*((volatile u32 *)0x40007410))
#define GPIO_PORTD_RIS_R        (*((volatile u32 *)0x40007414))
#define GPIO_PORTD_MIS_R        (*((volatile u32 *)0x40007418))
#define GPIO_PORTD_ICR_R        (*((volatile u32 *)0x4000741C))
#define GPIO_PORTD_AFSEL_R      (*((volatile u32 *)0x40007420))
#define GPIO_PORTD_DR2R_R       (*((volatile u32 *)0x40007500))
#define GPIO_PORTD_DR4R_R       (*((volatile u32 *)0x40007504))
#define GPIO_PORTD_DR8R_R       (*((volatile u32 *)0x40007508))
#define GPIO_PORTD_ODR_R        (*((volatile u32 *)0x4000750C))
#define GPIO_PORTD_PUR_R        (*((volatile u32 *)0x40007510))
#define GPIO_PORTD_PDR_R        (*((volatile u32 *)0x40007514))
#define GPIO_PORTD_SLR_R        (*((volatile u32 *)0x40007518))
#define GPIO_PORTD_DEN_R        (*((volatile u32 *)0x4000751C))
#define GPIO_PORTD_LOCK_R       (*((volatile u32 *)0x40007520))
#define GPIO_PORTD_CR_R         (*((volatile u32 *)0x40007524))
#define GPIO_PORTD_AMSEL_R      (*((volatile u32 *)0x40007528))
#define GPIO_PORTD_PCTL_R       (*((volatile u32 *)0x4000752C))
#define GPIO_PORTD_ADCCTL_R     (*((volatile u32 *)0x40007530))
#define GPIO_PORTD_DMACTL_R     (*((volatile u32 *)0x40007534))
//*****************************************************************************
//
// GPIO registers (PORTE)
//
//*****************************************************************************
#define GPIO_PORTE_DATA_BITS_R  ((  volatile u32 *)0x40024000)
#define GPIO_PORTE_DATA_R       (*((volatile u32 *)0x400243FC))
#define GPIO_PORTE_DIR_R        (*((volatile u32 *)0x40024400))
#define GPIO_PORTE_IS_R         (*((volatile u32 *)0x40024404))
#define GPIO_PORTE_IBE_R        (*((volatile u32 *)0x40024408))
#define GPIO_PORTE_IEV_R        (*((volatile u32 *)0x4002440C))
#define GPIO_PORTE_IM_R         (*((volatile u32 *)0x40024410))
#define GPIO_PORTE_RIS_R        (*((volatile u32 *)0x40024414))
#define GPIO_PORTE_MIS_R        (*((volatile u32 *)0x40024418))
#define GPIO_PORTE_ICR_R        (*((volatile u32 *)0x4002441C))
#define GPIO_PORTE_AFSEL_R      (*((volatile u32 *)0x40024420))
#define GPIO_PORTE_DR2R_R       (*((volatile u32 *)0x40024500))
#define GPIO_PORTE_DR4R_R       (*((volatile u32 *)0x40024504))
#define GPIO_PORTE_DR8R_R       (*((volatile u32 *)0x40024508))
#define GPIO_PORTE_ODR_R        (*((volatile u32 *)0x4002450C))
#define GPIO_PORTE_PUR_R        (*((volatile u32 *)0x40024510))
#define GPIO_PORTE_PDR_R        (*((volatile u32 *)0x40024514))
#define GPIO_PORTE_SLR_R        (*((volatile u32 *)0x40024518))
#define GPIO_PORTE_DEN_R        (*((volatile u32 *)0x4002451C))
#define GPIO_PORTE_LOCK_R       (*((volatile u32 *)0x40024520))
#define GPIO_PORTE_CR_R         (*((volatile u32 *)0x40024524))
#define GPIO_PORTE_AMSEL_R      (*((volatile u32 *)0x40024528))
#define GPIO_PORTE_PCTL_R       (*((volatile u32 *)0x4002452C))
#define GPIO_PORTE_ADCCTL_R     (*((volatile u32 *)0x40024530))
#define GPIO_PORTE_DMACTL_R     (*((volatile u32 *)0x40024534))

//*****************************************************************************
//
// GPIO registers (PORTF)
//
//*****************************************************************************
#define GPIO_PORTF_DATA_BITS_R  ((  volatile u32 *)0x40025000)
#define GPIO_PORTF_DATA_R       (*((volatile u32 *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile u32 *)0x40025400))
#define GPIO_PORTF_IS_R         (*((volatile u32 *)0x40025404))
#define GPIO_PORTF_IBE_R        (*((volatile u32 *)0x40025408))
#define GPIO_PORTF_IEV_R        (*((volatile u32 *)0x4002540C))
#define GPIO_PORTF_IM_R         (*((volatile u32 *)0x40025410))
#define GPIO_PORTF_RIS_R        (*((volatile u32 *)0x40025414))
#define GPIO_PORTF_MIS_R        (*((volatile u32 *)0x40025418))
#define GPIO_PORTF_ICR_R        (*((volatile u32 *)0x4002541C))
#define GPIO_PORTF_AFSEL_R      (*((volatile u32 *)0x40025420))
#define GPIO_PORTF_DR2R_R       (*((volatile u32 *)0x40025500))
#define GPIO_PORTF_DR4R_R       (*((volatile u32 *)0x40025504))
#define GPIO_PORTF_DR8R_R       (*((volatile u32 *)0x40025508))
#define GPIO_PORTF_ODR_R        (*((volatile u32 *)0x4002550C))
#define GPIO_PORTF_PUR_R        (*((volatile u32 *)0x40025510))
#define GPIO_PORTF_PDR_R        (*((volatile u32 *)0x40025514))
#define GPIO_PORTF_SLR_R        (*((volatile u32 *)0x40025518))
#define GPIO_PORTF_DEN_R        (*((volatile u32 *)0x4002551C))
#define GPIO_PORTF_LOCK_R       (*((volatile u32 *)0x40025520))
#define GPIO_PORTF_CR_R         (*((volatile u32 *)0x40025524))
#define GPIO_PORTF_AMSEL_R      (*((volatile u32 *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile u32 *)0x4002552C))
#define GPIO_PORTF_ADCCTL_R     (*((volatile u32 *)0x40025530))
#define GPIO_PORTF_DMACTL_R     (*((volatile u32 *)0x40025534))






#endif /* REG_MAP_H_ */
