/*
 * servo.h
 *
 * Created: 18.06.2023 2:02:11
 *  Author: Dmitrenok D.A.
 */ 


#ifndef SERVO_H_
#define SERVO_H_

#include "main.h"
#include "pwm.h"

// Definitions
#define SERVO_CENTRAL_POS 750U
#define SERVO_LEFT_END_POS 290U
#define SERVO_RIGHT_END_POS 1210U

// Functions definition 
void servo_init(void);
void servo_set_position(unsigned int serv_pos);

#endif /* SERVO_H_ */