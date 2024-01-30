/*
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: source file for the ATmega32 ADC driver
 *
 * Created on: Oct 9, 2023
 *
 * Author: Youssef ElSayyad
 */
#include <avr/io.h> /* To use the ADC Registers */
#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType *Config_Ptr) {
	/* ADMUX Register Bits Description:
	 * REFS1:0: insert the required ref_volt config in the bits (REFS1, REFS0)
	 * of ADMUX Register
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
	ADMUX = (ADMUX & 0) | ((Config_Ptr->ref_volt) << 6);

	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 0 Enable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger
	 * ADPS2:0 = insert the required prescaler config in the bits (ADPS2, ADPS1, ADPS0)
	 * of ADCSRA Register
	 */
	SET_BIT(ADCSRA, ADEN);
	CLEAR_BIT(ADCSRA, ADIE);
	ADCSRA |= (Config_Ptr->prescaler);
}
uint16 ADC_readChannel(uint8 ch_num) {

	ADMUX = (ADMUX & 0xE0) | (ch_num & 0x1F); /* Input channel number must be from 0 --> 7 *//* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	SET_BIT(ADCSRA, ADSC); /* Start conversion write '1' to ADSC */
	while (BIT_IS_CLEAR(ADCSRA, ADIF)) { }; /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA, ADIF); /* Clear ADIF by write '1' to it :) */
	return ADC; /* Return the digital value from the ADC data register */

}
