/*
 * Module: LM35 Sensor
 *
 * File Name: lm35.h
 *
 * Description: header file for the LM35 Sensor driver
 *
 * Created on: Oct 10, 2023
 *
 * Author: Youssef ElSayyad
 */
#include "lm35.h"
#include "adc.h"
#include <util/delay.h>
/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void) {
	uint8 temp = 0;
	uint16 adcResult = 0;
	/* Read ADC channel where the temperature sensor is connected */
	adcResult = ADC_readChannel(SENSOR_CHANNEL_ID);

	/* Make delay for some time until g_adcResult value is updated with the ADC interrupt */
	_delay_ms(5);

	/* Calculate the temperature from the ADC value*/
	temp =(uint8) ( ( (uint32) adcResult * SENSOR_MAX_TEMPERATURE* ADC_REF_VOLT_VALUE) / (ADC_MAXIMUM_VALUE * SENSOR_MAX_VOLT_VALUE));

	return temp;
}

