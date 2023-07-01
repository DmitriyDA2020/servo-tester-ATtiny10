/*
 *****************
 * Servo_tester.c*
 *****************
 *
 * Pins definition:
 * PB0 - Potentiometr input (ADC)
 * PB1 - PWM output (OC0B)
 * PB2 - Button (INT0)
 *
 * Created: 17.06.2023 23:13:33
 * Author : Dmitrenok D.A.
 */ 

#include "main.h"


volatile char mode_flag = ANALOG_MODE;
volatile char button_flag = 1;
unsigned int servo_minimal_pwm_value = SERVO_LEFT_END_POS;
unsigned int servo_maximum_pwm_value = SERVO_RIGHT_END_POS;
unsigned int servo_central_pwm_value = SERVO_CENTRAL_POS;

ISR(TIM0_OVF_vect)
{
	static char delay_counter = 0;
	delay_counter++;
	if (delay_counter > 10) // Delay 300ms
	{
		delay_counter = 0;
		button_flag = 1;
		STOP_BUTTON_COUNT;
	}
}

ISR(INT0_vect)
{
	if (button_flag == 1)
	{
		START_BUTTON_COUNT;
		button_flag = 0;
		mode_flag++;
		if (mode_flag > TEST_MODE)
		{
			mode_flag = ANALOG_MODE;
		}
	}
}

int main(void)
{
	// Unlock protection and set Fcpu 8 MHz
	CCP = 0xD8;
	CLKPSR = 0x00;
	
	// Peripherial initialization
	adc_init();
	button_init();
	servo_init();
	
	// Enable global interrupt
	sei();
    while (1)
    {
		if (mode_flag == ANALOG_MODE)
		{
			unsigned char adc_val;
			unsigned int servo_val;
			adc_val = adc_get_val();
			servo_val = (adc_val - ADC_MINIMAL_VALUE) * (unsigned long) (servo_maximum_pwm_value - servo_minimal_pwm_value) / (ADC_MAXIMUM_VALUE - ADC_MINIMAL_VALUE) + servo_minimal_pwm_value;
			servo_set_position(servo_val);
		}
		else
		{
			if (mode_flag == CENTRAL_POS_MODE)
			{
				servo_set_position(servo_central_pwm_value);
			}
			else
			{
				if (mode_flag == TEST_MODE)
				{
					for (unsigned int pos_counter = servo_minimal_pwm_value; pos_counter <= servo_maximum_pwm_value; pos_counter++)
					{
						if (mode_flag != TEST_MODE)
						{
							break;
						}
						servo_set_position(pos_counter);
						_delay_ms(1);
					}
					_delay_ms(150);
					for (unsigned int pos_counter = servo_maximum_pwm_value; pos_counter >= servo_minimal_pwm_value; pos_counter--)
					{
						if (mode_flag != TEST_MODE)
						{
							break;
						}
						servo_set_position(pos_counter);
						_delay_ms(1);
					}
					_delay_ms(150);
				}
			}
		}
	}
}

void button_init(void)
{
	// Button initialization
	PUEB = 1 << BUTTON_PIN;
	// Button interrupt setting
	EICRA = 1 << ISC01; // Interrupt request on falling edge on INT0 pin
	EIMSK = 1 << INT0; 
}
