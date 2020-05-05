/*
 * uart_inter.h
 *
 *  Created on: Jan 29, 2020
 *      Author: toshipa
 */

#ifndef UART_INTER_H_
#define UART_INTER_H_

#define gie_enable() sreg |=  (1 << (7))
#define rxi_enable() ucsrb |=  (1 << (7))

//user
 #define fosc 8000000
#define baud 9600
//

#define udre 5
#define rxc 7
#define my_ubrr fosc/16/baud-1

#define r_t 11
#define r 10
#define t 01
 void uart_int(void);
void uart_transmit (u8 data);
void uart_transmit_string(u8* str);
u8 uart_receive(void);
void set_callback(void(*ptr)(void));





#endif /* UART_INTER_H_ */

