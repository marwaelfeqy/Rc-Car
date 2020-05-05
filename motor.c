/*
 * motor.c
 *
 *  Created on: Jan 29, 2020
 *      Author: toshipa
 */
#include "priv.h"
#include "uart_inter.h"
#include "util/delay.h"
#include "motor.h"
#include "ext_inter.h"

void motor_driver_int(void)
{
	SET_BIT(mddr,lb);
	 SET_BIT(mddr,lf);
	 SET_BIT(mddr,rb);
	 SET_BIT(mddr,rf);
}
void m_stop(void)
{
 CLR_BIT(mport,lb);
 CLR_BIT(mport,lf);
 CLR_BIT(mport,rb);
 CLR_BIT(mport,rf);

}
void motor_dir (u8 y)
{
	if(y==forward)
	{
		m_stop();
		_delay_ms(p);
		SET_BIT(mport,rf);
		SET_BIT(mport,lf);
		_delay_ms(p);
	}
	else if(y==back)
		{
			m_stop();
			_delay_ms(p);
			SET_BIT(mport,rb);
			SET_BIT(mport,lb);
			_delay_ms(p);
		}
	else if(y==right)
			{
			m_stop();
			_delay_ms(p);
				SET_BIT(mport,rf);
				SET_BIT(mport,lb);
				_delay_ms(p);
			}
	else if(y==left)
				{
					m_stop();
					_delay_ms(p);
					SET_BIT(mport,rb);
					SET_BIT(mport,lf);
					_delay_ms(p);
				}
	else if(y==stop)
					{
						m_stop();
						_delay_ms(p);
					}
	else
	{
		//m_stop();
	}


}
