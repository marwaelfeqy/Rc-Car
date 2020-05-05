/*
 * ext_interr.c
 *
 *  Created on: Feb 1, 2020
 *      Author: toshipa
 */


#include "priv.h"
#include "uart_inter.h"
#include "util/delay.h"
#include "motor.h"
#include "ext_inter.h"
void (*ptrfun0)(void);

void set_callback_exti(void(*ptr0)(void))
{
	if(ptr0 !=NULL)
		ptrfun0=ptr0;
}
void exti_enable (u8 intnum,u8 event)
{

	switch (intnum)
	{
	case 0:
		SET_BIT(gicr,6);
		mcucr &=0b11111100 ;
		mcucr |= event ;
		break;
	case 1:
			SET_BIT(gicr,7);
			mcucr &=0b11110011 ;
			mcucr |= event<<2 ;
			break;
	case 2:
				SET_BIT(gicr,5);
				mcucsr &=0b10111111;
				mcucsr |=event<<6;
				break;
	default :
	            break;
	}

}



void __vector_1 (void) __attribute__ ((signal)) ; //external interrupt
 void __vector_1 (void)
{
	 ptrfun0();


}
