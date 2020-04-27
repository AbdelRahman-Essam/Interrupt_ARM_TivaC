/*
 * GPIO_prog.c
 *
 *  Created on: Feb 17, 2020
 *      Author: Abdelrahman Essam
 */
/*
 * bus  = APB , AHBA , AHBB , AHBC , AHBD , AHBE , AHBF
 */
#ifndef GPIO_PROG_C_
#define GPIO_PROG_C_

#include <GPIO.h>

u8 GPIOPortTrans(gpio_port_t port)
{
    u8 Port=0;
    if(port==PORTA)
        Port=0;
    else if(port==PORTB)
        Port=1;
    else if(port==PORTC)
        Port=2;
    else if(port==PORTD)
        Port=3;
    else if(port==PORTE)
        Port=4;
    else if(port==PORTF)
        Port=5;
    return (Port);
}
/*********************************************/
void GPIOBusSet(gpio_port_t port,gpio_bus_t bus)
{
/*
 * port = PORTA , PORTB , PORTC , PORTD , PORTE , PORTF
 * bus  = APB , AHB
 */
    u8 Port=GPIOPortTrans(port);
    SYSCTL_GPIOHBCTL_R &= ~(1<<Port);
    SYSCTL_GPIOHBCTL_R |=  (bus<<Port);
}
/*********************************************/
u32 GPIOBusGet(gpio_port_t port)
{
/* port = PORTA , PORTB , PORTC , PORTD , PORTE , PORTF
 * return 1 --> AHB  ,return 0 --> APB */
    u8 Port=GPIOPortTrans(port);
    u32 bus=0;
    u8 value=GETBIT(SYSCTL_GPIOHBCTL_R,Port);
    if((value==1)&&(Port<4))
    { bus=0x54000;}
    else if((value==1)&&(Port>4))
    {   bus=0x38000;  }

return (bus);
}
/**********************************************/
u32 GPIOPortAddrGet(gpio_port_t port)
{ /* port = PORTA , PORTB , PORTC , PORTD , PORTE , PORTF */
    u32 bus =0;
    bus =GPIOBusGet(port);
    u32 Address=port+bus;
    return (Address);
}
/**********************************************/
void GPIOClockSet(gpio_port_t port,gpio_ClockMode_t ClockMode)
{/* port = PORTA , PORTB , PORTC , PORTD , PORTE , PORTF
    ClockMode = RCGC , SCGC , DCGC */
    u8 Port=GPIOPortTrans(port);
    CLRBIT(SYSCTL_RCGCGPIO_R,Port);
    CLRBIT(SYSCTL_SCGCGPIO_R,Port);
    CLRBIT(SYSCTL_DCGCGPIO_R,Port);
    REG reg = SYSCTL + ClockMode;
    u8 reg_data=*reg;
    SETBIT(reg_data,Port);
    *reg = reg_data;
}
/**********************************************/
void GPIOClockRst(gpio_port_t port)
{/* port = PORTA , PORTB , PORTC , PORTD , PORTE , PORTF */
    u8 Port=GPIOPortTrans(port);
    CLRBIT(SYSCTL_RCGCGPIO_R,Port);
    CLRBIT(SYSCTL_SCGCGPIO_R,Port);
    CLRBIT(SYSCTL_DCGCGPIO_R,Port);
}
/**********************************************/
u8 GPIOClockGet(gpio_port_t port)
{/* port = PORTA , PORTB , PORTC , PORTD , PORTE , PORTF */
    u8 Port=GPIOPortTrans(port);
    if((GETBIT(SYSCTL_RCGCGPIO_R,Port)==1)||(GETBIT(SYSCTL_SCGCGPIO_R,Port)==1)||(GETBIT(SYSCTL_DCGCGPIO_R,Port)==1))
        return(1);
    else
        return(0);
}
/**********************************************/
void GPIODirModeSet(gpio_port_t port, u8 pins, gpio_mode_t Mode)
{
/*  port = PORTA , PORTB , PORTC , PORTD , PORTE , PORTF
 *  pins = 0bxxxxxxxx
 *  Mode = IN , OUT , AF
 * ex: 0b10100011  pins */
    u32 PORT=GPIOPortAddrGet(port);
    if(Mode==0x3)
    {
        REG reg =(PORT+GPIOAFSEL);
        u32 reg_data = *reg;
        reg_data |= pins; /* setting the pins  */
        *reg = reg_data;
    }
    else
    {
        REG AFSEL =(PORT+GPIOAFSEL);
        u32 AFSEL_data = *AFSEL;
        AFSEL_data &= ~(pins);

        REG DIR =(PORT+GPIODIR);
        u32 DIR_data = *DIR;
        DIR_data &= ~(pins);
        u32 mask = pins & Mode;
        DIR_data |= mask;
        *DIR = DIR_data;

        REG DEN =(PORT+GPIODEN);
        u32 DEN_data = *DEN;
        DEN_data &= ~(pins);
        DEN_data |= pins;
        *DEN = DEN_data;




    }
}
/**********************************************/
u8 GPIODirGet(gpio_port_t port, u8 pins)
{
    /*  port = PORTA , PORTB , PORTC , PORTD , PORTE , PORTF
     *  pins = 0bxxxxxxxx */
    u32 PORT=GPIOPortAddrGet(port);
    REG DIR =(PORT+GPIODIR);
    u8 DIR_data = *DIR;
    return (DIR_data);
}
/**********************************************/
u8 GPIOModeGet(gpio_port_t port, u8 pins)
{/* Alternative Function or GPIO (IN or out)
 *  port = PORTA , PORTB , PORTC , PORTD , PORTE , PORTF
 *  pins = 0bxxxxxxxx */
    u32 PORT=GPIOPortAddrGet(port);
    REG AFSEL =(PORT+GPIOAFSEL);
    u8 AFSEL_data = *AFSEL;
    return (AFSEL_data);
}
/**********************************************/
void GPIOPadSet(gpio_port_t port, u8 pins, gpio_drive_t str, gpio_pad_t pad)
{/* port = PORTA , PORTB , PORTC , PORTD , PORTE , PORTF
 *  pins = 0bxxxxxxxx
 *  Drive  =  Drive_2mA , Drive_4mA , Drive_8mA , Drive_8mA_Selw
 *  Pad = Pad_PU , Pad_PD , PAD_NPU_NPD , PAD_OD
 *
 *   */
    u32 PORT=GPIOPortAddrGet(port);
    if(str==GPIOSLR)/* setting the Drive : Drive_2mA , Drive_4mA , Drive_8mA , Drive_8mA_Selw */
       {// set drive to be 8mA
           REG DriveReg1 =(PORT+GPIODR8R);
               u8 DriveReg1_data = *DriveReg1;
               DriveReg1_data |= pins; /* setting the pins  */
               *DriveReg1 = DriveReg1_data;
       }
        REG DriveReg0 =(PORT+str);
        u8 DriveReg0_data = *DriveReg0;
        DriveReg0_data |= pins; /* setting the pins  */
        *DriveReg0 = DriveReg0_data;

    if(pad==PAD_NPU_NPD)
    {
        REG PUReg=(PORT+Pad_PU);
        u8 PUReg_data = *PUReg ;
        PUReg_data &= ~(pins);
        *PUReg=PUReg_data;

        REG PDReg=(PORT+Pad_PD);
        u8 PDReg_data = *PDReg ;
        PDReg_data &= ~(pins);
        *PDReg=PDReg_data;
    }
    else
    {
    REG PadReg =(PORT+pad);
    u8 PadReg_data = *PadReg;
    PadReg_data |= pins;
    *PadReg = PadReg_data;
    }
}
/**********************************************/
u8 GPIOPadDrive2mAStrGet(gpio_port_t port, u8 pins)
{/* Alternative Function or GPIO (IN or out)
 *  port = PORTA , PORTB , PORTC , PORTD , PORTE , PORTF
 *  pins = 0bxxxxxxxx */
    u32 PORT=GPIOPortAddrGet(port);
    REG reg =(PORT+GPIODR2R);
    u8 reg_data = *reg;
    return (reg_data);
}/**********************************************/
u8 GPIOPadDrive4mAStrGet(gpio_port_t port, u8 pins)
{/* Alternative Function or GPIO (IN or out)
 *  port = PORTA , PORTB , PORTC , PORTD , PORTE , PORTF
 *  pins = 0bxxxxxxxx */
    u32 PORT=GPIOPortAddrGet(port);
    REG reg =(PORT+GPIODR4R);
    u8 reg_data = *reg;
    return (reg_data);
}/**********************************************/
u8 GPIOPadDrive8mAStrGet(gpio_port_t port, u8 pins)
{/* Alternative Function or GPIO (IN or out)
 *  port = PORTA , PORTB , PORTC , PORTD , PORTE , PORTF
 *  pins = 0bxxxxxxxx */
    u32 PORT=GPIOPortAddrGet(port);
    REG reg =(PORT+GPIODR8R);
    u8 reg_data = *reg;
    return (reg_data);
}/**********************************************/
u8 GPIOSlewRateGet(gpio_port_t port, u8 pins)
{/* Alternative Function or GPIO (IN or out)
 *  port = PORTA , PORTB , PORTC , PORTD , PORTE , PORTF
 *  pins = 0bxxxxxxxx */
    u32 PORT=GPIOPortAddrGet(port);
    REG SLewRate =(PORT+GPIOSLR);
    u8 SLewRate_data = *SLewRate;
    return (SLewRate_data);
}/**********************************************/
u8 GPIOPadOpenDrainGet(gpio_port_t port, u8 pins)
{/* Alternative Function or GPIO (IN or out)
 *  port = PORTA , PORTB , PORTC , PORTD , PORTE , PORTF
 *  pins = 0bxxxxxxxx */
    u32 PORT=GPIOPortAddrGet(port);
    REG OpenDrain =(PORT+GPIOODR);
    u8 OpenDrain_data = *OpenDrain;
    return (OpenDrain_data);
}/**********************************************/
u8 GPIOPadPullUpGet(gpio_port_t port, u8 pins)
{/* Alternative Function or GPIO (IN or out)
 *  port = PORTA , PORTB , PORTC , PORTD , PORTE , PORTF
 *  pins = 0bxxxxxxxx */
    u32 PORT=GPIOPortAddrGet(port);
    REG PullUp =(PORT+GPIOPUR);
    u8 PullUp_data = *PullUp;
    return (PullUp_data);
}/**********************************************/
u8 GPIOPadPullDownGet(gpio_port_t port, u8 pins)
{/* Alternative Function or GPIO (IN or out)
 *  port = PORTA , PORTB , PORTC , PORTD , PORTE , PORTF
 *  pins = 0bxxxxxxxx */
    u32 PORT=GPIOPortAddrGet(port);
    REG PullDown =(PORT+GPIOPDR);
    u8 PullDown_data = *PullDown;
    return (PullDown_data);
}/**********************************************/
u8 GPIORead(gpio_port_t port, u8 pins)
{/* port = PORTA , PORTB , PORTC , PORTD , PORTE , PORTF
 *  pins = 0bxxxxxxxx */
    u32 PORT=GPIOPortAddrGet(port);
    u16 mask=pins;
    mask=mask<<2;
    REG DataReg =(PORT+mask);
    u32 DataReg_data = *DataReg;
    return (DataReg_data);
}
/**********************************************/
void GPIOWrite(gpio_port_t port, u8 pins, u8 data)
{/* port = PORTA , PORTB , PORTC , PORTD , PORTE , PORTF
 *  pins = 0bxxxxxxxx */
    u32 PORT=GPIOPortAddrGet(port);
    u16 mask=pins;
    mask=mask<<2;
    REG DataReg =(PORT+mask);
    u8 DataReg_data = *DataReg;
    DataReg_data &= ~(pins);
    u8 ANDING = pins & data;
    DataReg_data |=  ANDING;
    *DataReg =DataReg_data;
}
/*******************Quick Init***************************/
void GPIOQuickInit(gpio_port_t port,gpio_bus_t bus,gpio_ClockMode_t ClockMode, u8 pins, gpio_mode_t Mode, gpio_drive_t str, gpio_pad_t pad)
{   /* port = PORTA , PORTB , PORTC , PORTD , PORTE , PORTF
     * bus  = APB , AHB
     * ClockMode = RCGC , SCGC , DCGC
     * pins = 0bxxxxxxxx
     * Mode = IN , OUT , AF
     * Drive  =  Drive_2mA , Drive_4mA , Drive_8mA , Drive_8mA_Selw
     * Pad = Pad_PU , Pad_PD , PAD_NPU_NPD , PAD_OD */
    GPIOBusSet(port,bus);
    GPIOClockSet(port,ClockMode);
    GPIODirModeSet(port,pins,Mode);
    GPIOPadSet(port,pins,str,pad);
}
void GPIOIntQuickInit(gpio_port_t port,u8 pins,gpio_sense_t sense,gpio_event_t event)
{/*************if you will use the Edge Triggered you had to clear the flad with GPIOIntClear  */
	GPIOIntMaskSet(port, pins, Masked);
	GPIOIntSenseSet(port, pins, sense);
	GPIOIntEventSet(port, pins, event);
	GPIOIntClear(port, pins);
	GPIOIntMaskSet(port, pins, unMasked);

}
/*******************Interrupt Functions***************************/
void GPIOIntSenseSet(gpio_port_t port, u8 pins, gpio_sense_t sense)
{
    u32 PORT =GPIOPortAddrGet(port);
    REG SenseReg =PORT+GPIOIS;
    u32 sense_data =*SenseReg;
    sense_data &=~(pins);
    u32 mask =pins & sense;
    sense_data |= mask;
    *SenseReg=sense_data;
}
u8 GPIOIntSenseGet(gpio_port_t port, u8 pins)
{
	u32 PORT = GPIOPortAddrGet(port);
	REG SenseReg=PORT+GPIOIS;
	u8 sense_data=*SenseReg;
	return(sense_data);

}
void GPIOIntMaskSet(gpio_port_t port, u8 pins, gpio_mask_t masked)
{
		u32 PORT =GPIOPortAddrGet(port);
	    REG MaskReg =PORT+GPIOIM;
	    u32 mask_data =*MaskReg;
	    mask_data &=~(pins);
	    u32 mask =pins & masked;
	    mask_data |= mask;
	    *MaskReg=mask_data;
}
u8 GPIOIntMaskGet(gpio_port_t port,u8 pins)
{
	u32 PORT =GPIOPortAddrGet(port);
	REG reg=PORT+GPIOIM;
	u8 data=*reg;
	return(data);
}
void GPIOIntEventSet(gpio_port_t port, u8 pins, gpio_event_t event)
{
	u32 PORT =GPIOPortAddrGet(port);
	REG BothReg =PORT+GPIOIBE;
	u32 both_data=*BothReg;
	if(event==Both)
	{
		both_data|=pins;
		*BothReg=both_data;
	}
	else
	{
		both_data &=~(pins);
		*BothReg=both_data;

	    REG EventReg =PORT+GPIOIEV;
	    u32 event_data =*EventReg;
	    event_data &=~(pins);
	    u32 mask =pins & event;
	    event_data |= mask;
	    *EventReg=event_data;
	}
}
u8   GPIOIntBothGet(gpio_port_t port, u8 pins)
{
	u32 PORT =GPIOPortAddrGet(port);
	REG BothReg =PORT+GPIOIBE;
	u8 both_data=*BothReg;
	return(both_data);
}
u8   GPIOIntEventGet(gpio_port_t port, u8 pins)
{
	u32 PORT =GPIOPortAddrGet(port);
	REG EventReg =PORT+GPIOIEV;
    u8 event_data =*EventReg;
    return(event_data);
}
u8 GPIOIntRawStatusGet(gpio_port_t port, u8 pins)
{
	u32 PORT =GPIOPortAddrGet(port);
	REG Reg =PORT+GPIORIS;
    u8 data =*Reg;
    return(data);
}
u8 GPIOIntMaskedStatusGet(gpio_port_t port, u8 pins)
{
	u32 PORT =GPIOPortAddrGet(port);
	REG Reg =PORT+GPIOMIS;
    u8 data =*Reg;
    return(data);
}
void GPIOIntClear(gpio_port_t port, u8 pins)
{
    u32 PORT =GPIOPortAddrGet(port);
    REG Reg =PORT+GPIOICR;
    u32 data =*Reg;
    data &=~(pins);
    u32 mask =pins;
    data |= mask;
    *Reg=data;
}
/**********************************************/
void ISRPORTF(void)
{
    int i=0;
    REG GPIOICR_Reg = PORTF_AHB + GPIOICR ;
    SETBIT(*GPIOICR_Reg,4);
    TOG_BIT(GPIO_PORTF_AHB_DATA_R, 1);
}


#endif /* GPIO_PROG_C_ */
