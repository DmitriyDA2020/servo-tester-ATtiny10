/*
 * pwm.h
 *
 * Created: 18.06.2023 1:52:03
 *  Author: Dmitrenok D.A.
 */ 


#ifndef PWM_H_
#define PWM_H_

#include "main.h"


// Pins definition
#define PWM_PIN PINB1

// Other definitions
#define DUTY_REG OCR0B
#define PERIOD_REG ICR0

// Functions definition
void pwm_init(void);

#endif /* PWM_H_ */