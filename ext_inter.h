/*
 * ext_inter.h
 *
 *  Created on: Feb 1, 2020
 *      Author: toshipa
 */

#ifndef EXT_INTER_H_
#define EXT_INTER_H_

#define u8 unsigned char
#define u16 unsigned short

#define gie_enable() sreg |=  (1 << (7))
void set_callback_exti(void(*ptr0)(void));
void exti_enable (u8 intnum,u8 event);
/*
 *1- gie-->1 sreg
 *2- bit 6,7,5 -->1 gicr
 *3- type of event mcucr (0,1)int0 (2,3)int1
 *4- write the function
 * void __vector_num(void); __attribut__((signal))
 *\\num from vector table skip the reset
 *
 * void __vector_1 (void) {
 *            ...
 *           }
 * protd 2 -->int0
 * protd 3 -->int1
 * */

// int2 rising edge-->1 in mcucsr pin6
#define int0 0
#define int1 1
#define int2 2
#define event0 0
#define event1 1
#define event2 2 //falling edge
#define event3 3 //rising

#endif /* EXT_INTER_H_ */
