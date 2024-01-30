/*
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega32 ADC driver
 *
 * Created on: Oct 9, 2023
 *
 * Author: Youssef ElSayyad
 */

#ifndef ADC_H_
#define ADC_H_
#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56
typedef enum
{
	OFF,AVCC,RESERVED,INTERNAL_REF
}ADC_ReferenceVolatge;
typedef enum
{
	ADC_0_PRESCALER,ADC_2_PRESCALER,ADC_4_PRESCALER,ADC_8_PRESCALER,ADC_16_PRESCALER,ADC_32_PRESCALER,ADC_64_PRESCALER,ADC_128_PRESCALER
}ADC_Prescaler;
typedef struct
{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler  prescaler;
}ADC_ConfigType;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);
/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 ch_num);

#endif /* ADC_H_ */
