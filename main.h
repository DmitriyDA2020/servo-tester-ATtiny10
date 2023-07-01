/*
 * main.h
 *
 * Created: 17.06.2023 23:14:01
 *  Author: Dmitrenok D.A.
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "servo.h"
#include "adc.h"


// Pins definitions
#define POTENTIOMETR_PIN PINB0
#define BUTTON_PIN PINB2

// Button definitions
#define START_BUTTON_COUNT TIMSK0 |= 1 << TOIE0
#define STOP_BUTTON_COUNT TIMSK0 &= ~(1 << TOIE0)

// ADC definition
#define ADC_START_CONVERSATION ADCSRA |= 1 << ADSC
#define ADC_MINIMAL_VALUE 0
#define ADC_MAXIMUM_VALUE 255

// Work mode definitions
#define ANALOG_MODE 0
#define CENTRAL_POS_MODE 1
#define TEST_MODE 2

// Function definitions
void button_init(void);

#endif /* MAIN_H_ */