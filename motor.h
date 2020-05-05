/*
 * motor.h
 *
 *  Created on: Jan 29, 2020
 *      Author: toshipa
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#define p 300
#define mddr ddrc
#define mport portc
#define rb 3
#define rf 4
#define lb 2
#define lf 1
#define forward '1'
#define back '2'
#define right '3'
#define left '4'
#define stop '5'

void motor_driver_int(void);

void m_stop(void);

void motor_dir (unsigned char y);

#endif /* MOTOR_H_ */
