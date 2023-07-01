/*
 * adc.c
 *
 * Created: 18.06.2023 2:58:14
 *  Author: Dmitrenok D.A.
 */ 


#include "adc.h"


void adc_init(void)
{
	// ADC initialization
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);
	DIDR0 = 1 << ADC0D;
}

unsigned char adc_get_val(void)
{
	ADCSRA |= 1 << ADSC;
	while (!(ADCSRA & (1 << ADIF)));
	ADCSRA |= 1 << ADIF;
	return ADCL;
}