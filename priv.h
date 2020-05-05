/*
 * priv.h
 *
 *  Created on: Jan 29, 2020
 *      Author: toshipa
 */

#ifndef PRIV_H_
#define PRIV_H_
#define NULL ((void*)0)
#define u8 unsigned char
#define u16 unsigned short
#define ddra *(( unsigned char*)0x3A)
#define porta *(( unsigned char*)0x3B)
#define pina *(( unsigned char*)0x39)
#define ddrb *(( unsigned char*)0x37)
#define portb *(( unsigned char*)0x38)
#define pinb *(( unsigned char*)0x36)
#define ddrc *(( unsigned char*)0x34)
#define portc *(( unsigned char*)0x35)
#define pinc *(( unsigned char*)0x33)
#define ddrd *(( unsigned char*)0x31)
#define portd *(( unsigned char*)0x32)
#define pind *(( unsigned char*)0x30)
#define admux *(( unsigned char*)0x27)
#define adcsra *(( unsigned char*)0x26)
#define adcl *(( unsigned char*)0x24)
#define adch *(( unsigned char*)0x25)
//interrupts
#define sreg *(( unsigned char*)0x5F)//(pin7)(GIE Global Interrupt Enable) bit must be set for the interrupts to be enabled

#define gicr *(( unsigned char*)0x5B) /*(PIE)General external Interrupt Control Register   bit(6,7,5) for enable external (0,1,2)  */

#define mcucr *(( unsigned char*)0x55) /* to select the event for int0 and int 1
                                          The MCU Control Register contains control bits for interrupt sense control
                                          bit (0,1) for external 0      bit (2,3) for external 1  */
#define mcucsr *(( unsigned char*)0x54) /* to select event for int2*/

#define gifr *(( unsigned char*)0x5A) /*General Interrupt Flag Register    bit(6,7,5) for  (0,1,2)  */

//timer
#define tcnt0 *(( unsigned char*)0x52) // counter 8 bit reg to read from 0 to 255

#define tccr0 *(( unsigned char*)0x53) /*
                                          (bit3-wgm01 &bit6-wgm00) to select the mode (normal-pwm-ctc)
                                          (bit4-com00 &bit5-com01) to select the mode for co0(inverting -non)
                                          (bit0,1,2) to select the freq/?? (change time cycle)
                                        */
#define ocr0 *(( unsigned char*)0x5C) //  set a value to compared with the counter value (TCNT0)
#define timsk *(( unsigned char*)0x59) /*
                                        (bit-0) to enable normal overflow interrupt (PIE)
                                        (bit-1) to enable *ctc* overflow interrupt (PIE)
                                       */
#define tccr1a *(( unsigned char*)0x4f)
#define tccr1b *(( unsigned char*)0x4e)
#define wdtcr *(( unsigned char*)0x41) /*
										bit3 watchdog enable
										bit4 wdtoe to turnof watchdog(bit3,4=1 -->bit3=0)
										bit(0-2) clk pre
 	 	 	 	 	 	 	 	 	   */

#define ucsra *(( unsigned char*)0x2b)
#define ucsrb *(( unsigned char*)0x2a)
#define ucsrc *(( unsigned char*)0x40)
#define ubrrh *(( unsigned char*)0x40)
#define ubrrl *(( unsigned char*)0x29)
#define udr *(( unsigned char*)0x2c)
#define spcr *(( unsigned char*)0x2d)
#define spsr *(( unsigned char*)0x2e)
#define spdr *(( unsigned char*)0x2f)


#define SET_BIT(Var,BitNo)    Var |=  (1 << (BitNo))
#define CLR_BIT(Var,BitNo)    Var &= ~(1 << (BitNo))
#define TOG_BIT(Var,BitNo)    Var ^=  (1 << (BitNo))
#define readbit (Var,BitNo)    Var &  (1 << (BitNo)>>BitNo)
#define ch_bit (Var,BitNo)    Var &=  (1 << (BitNo))



#endif /* PRIV_H_ */
