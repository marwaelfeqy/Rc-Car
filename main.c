/*
 * main.c
 *
 *  Created on: Jan 29, 2020
 *      Author: toshipa
 */
#include "priv.h"
#include "uart_inter.h"
#include "util/delay.h"
#include "motor.h"
#include "ext_inter.h"
u8 x=0;

void uart_rxi(void)
{
	x= uart_receive();

		 motor_dir (x);

}
void ext_interr(void)
{
	static u8 flag =1;

			 if (flag==1) //falling
			 {

				 		CLR_BIT(porta,1);
				 		CLR_BIT(porta,0);
				 flag=0;
				 exti_enable(int0 , event3);
			 }
			 else //rising
			 {
				 SET_BIT(porta,0);
				 SET_BIT(porta,1);

				 		exti_enable(int0 , event2);

				 flag=1;
			 }



}
int main (void)
{

	gie_enable();
	////
	set_callback_exti(ext_interr);
	SET_BIT(ddra,0);
	SET_BIT(ddra,1);
	exti_enable(int0 , event2);
///
	uart_int();
	set_callback(uart_rxi);
	motor_driver_int();
	rxi_enable();
	ubrrh=0;


	while(1)
	{



	}
	return 0;
}
