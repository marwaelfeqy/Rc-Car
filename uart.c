/*
 * uart.c
 *
 *  Created on: Jan 29, 2020
 *      Author: toshipa
 */

#include "priv.h"
#include "uart_inter.h"
#include "util/delay.h"
#include "motor.h"
#include "ext_inter.h"



void (*ptrfun)(void);

void set_callback(void(*ptr)(void))
{
	if(ptr!=NULL)
		ptrfun=ptr;
}

void uart_int(void)
{
	u16 x=my_ubrr;

	ubrrl =x;
	ubrrh=(x>>8);


	ucsrb |= ((1<<4)|(1<<3)); //enable transmitter and reciver
	ucsrc |=((1<<2)|(1<<1)); //frame 8 bit , 1 stop , no parity
}


void uart_transmit (u8 data)
{
	while (!(ucsra&(1<<udre))); //while not empty (when its empty the bit=1)
	udr =data;

}

void uart_transmit_string(u8* str)
{
	u8 i=0;
	while (str[i]!='\0')
	{
		uart_transmit(str[i]);
		i++;
	}

}

u8 uart_receive (void)
{
	//while (!(ucsra&(1<<rxc))); //wait until receiving (when it received the bit=1)
	while ((ucsra&(1<<rxc))==0);
	return udr;
//check 3al flag ezay????

}


void __vector_13 (void) __attribute__ ((signal)) ; //rx interrupt
 void __vector_13 (void)
 {

	 ptrfun();
}

