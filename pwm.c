/*
 * pwm.c
 *
 * Created: 18.06.2023 1:51:46
 *  Author: Dmitrenok D.A.
 */ 

#include "pwm.h"


void pwm_init(void)
{
	// 16-bit timer/counter0 and phase and frequency correct PWM initialization
	DDRB |= 1 << PWM_PIN;
	TCCR0A = (1 << COM0B1);
	TCCR0B = (1 << WGM03) | (1 << CS01); // Prescaler Fcpu/8 (1 MHz)
	PERIOD_REG = 10000; // Set period (10000 - 20 ms)
	DUTY_REG = 0; // Default duty cycle0%
}