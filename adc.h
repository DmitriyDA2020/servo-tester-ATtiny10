/*
 * adc.h
 *
 * Created: 18.06.2023 2:58:32
 *  Author: Dmitrenok D.A.
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "main.h"

// Functions definition
void adc_init(void);
unsigned char adc_get_val(void);

#endif /* ADC_H_ */