/*
 * servo.c
 *
 * Created: 18.06.2023 2:01:54
 *  Author: Dmitrenok D.A.
 */ 


#include "servo.h"


void servo_init(void)
{
	pwm_init();
}

void servo_set_position(unsigned int serv_pos)
{
	DUTY_REG = serv_pos;
}