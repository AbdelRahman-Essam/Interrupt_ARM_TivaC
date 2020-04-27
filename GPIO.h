/*
 * GPIO_init.h
 *
 *  Created on: Feb 17, 2020
 *      Author: Abdelrahman Essam
 */
/*
 * How to Set GPIO for a port:
 * 1)   GPIOBusSet(gpio_port_t port,gpio_bus_t bus);
 * 2)   GPIOClockSet(gpio_port_t port);
 * 3)   GPIODirModeSet(gpio_port_t port, u8 pins, gpio_mode_t Mode);
 * 4)   GPIOPadSet(gpio_port_t port, u8 pins, gpio_drive_t str, gpio_pad_t pad);
 * ************** Write & Read ****************************
 * 5)   GPIORead(gpio_port_t port, u8 pins);
 * 6)   GPIOWrite(gpio_port_t port, u8 pins, u8 data);
 */
#ifndef GPIO_H_
#define GPIO_H_

#include "Reg_map.h"
#include "utils.h"
#include "std_types.h"


typedef enum {PORTA=0x40004000, PORTB=0x40005000, PORTC=0x40006000,PORTD=0x40007000,PORTE=0x40024000,PORTF=0x40025000} gpio_port_t;
typedef enum {APB,AHB} gpio_bus_t;
typedef enum {RCGC=0x608 ,SCGC=0x708 ,DCGC=0x808} gpio_ClockMode_t;
typedef enum {IN = 0x00, OUT = 0xff, AF = 0x3} gpio_mode_t;
typedef enum {Drive_2mA=0x500, Drive_4mA=0x504, Drive_8mA=0x508, Drive_8mA_Selw=0x518} gpio_drive_t;
typedef enum {Pad_PU=0x510,Pad_PD=0x514,PAD_NPU_NPD=0xFF,PAD_OD=0x50C} gpio_pad_t;
typedef enum{Edge = 0, Level = 0xFF}gpio_sense_t;
typedef enum{Rising = 0xFF, Falling = 0, Both = 2,Low = 0, High = 0xFF}gpio_event_t;
typedef enum{Masked=0,unMasked=0xFF}gpio_mask_t;

//Functions prototype
void GPIOQuickInit(gpio_port_t port,gpio_bus_t bus,gpio_ClockMode_t ClockMode,u8 pins,gpio_mode_t Mode,gpio_drive_t str,gpio_pad_t pad);

void GPIOBusSet(gpio_port_t port,gpio_bus_t bus);
u32 GPIOBusGet(gpio_port_t port);

void GPIOClockSet(gpio_port_t port,gpio_ClockMode_t ClockMode);
void GPIOClockRst(gpio_port_t port);
u8 GPIOClockGet(gpio_port_t port);

void GPIODirModeSet(gpio_port_t port, u8 pins, gpio_mode_t Mode);
u8 GPIODirGet(gpio_port_t port, u8 pins);
u8 GPIOModeGet(gpio_port_t port, u8 pins);

void GPIOPadSet(gpio_port_t port, u8 pins, gpio_drive_t str, gpio_pad_t pad);
u8 GPIOPadDrive2mAStrGet(gpio_port_t port, u8 pins);// it needed to be separated
u8 GPIOPadDrive4mAStrGet(gpio_port_t port, u8 pins);
u8 GPIOPadDrive8mAStrGet(gpio_port_t port, u8 pins);
u8 GPIOPadOpenDrainGet(gpio_port_t port, u8 pins);
u8 GPIOPadPullUpGet(gpio_port_t port, u8 pins);
u8 GPIOPadPullDownGet(gpio_port_t port, u8 pins);
u8 GPIOSlewRateGet(gpio_port_t port, u8 pins);

u8 GPIORead(gpio_port_t port, u8 pins);
void GPIOWrite(gpio_port_t port, u8 pins, u8 data);

/*******************Interrupt Functions***************************/
u8 GPIOIntRawStatusGet(gpio_port_t port, u8 pins);
u8 GPIOIntMaskedStatusGet(gpio_port_t port, u8 pins);
void GPIOIntClear(gpio_port_t port, u8 pins);

void GPIOIntMaskSet(gpio_port_t port, u8 pins, gpio_mask_t masked);
u8 	 GPIOIntMaskGet(gpio_port_t port ,u8 pins);

void GPIOIntSenseSet(gpio_port_t port, u8 pins, gpio_sense_t sense);
u8   GPIOIntSenseGet(gpio_port_t port, u8 pins);

void GPIOIntEventSet(gpio_port_t port, u8 pins, gpio_event_t event);
u8   GPIOIntBothGet(gpio_port_t port, u8 pins);
u8   GPIOIntEventGet(gpio_port_t port, u8 pins);

void GPIOIntQuickInit(gpio_port_t port, u8 pins, gpio_sense_t sense, gpio_event_t event);

void isr_portF(void);
/**********************************************/

//functions used internal
u8 GPIOPortTrans(gpio_port_t port);
u32 GPIOPortAddrGet(gpio_port_t port);


void TIMER0_Handler(void);

#endif /* GPIO_H_ */
