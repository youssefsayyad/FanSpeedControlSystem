/*
 * Module: Fan Control
 *
 * File Name: fanControl.c
 *
 * Description: source file for the Fan Control System
 *
 * Created on: Oct 11, 2023
 *
 * Author: Youssef ElSayyad
 */
#include "lm35.h"
#include "lcd.h"
#include "dc_motor.h"

int main() {
	uint8 temperature=0, newTemp;
	ADC_ConfigType ADC_Configurations = { INTERNAL_REF, ADC_8_PRESCALER };
	LCD_init();
	ADC_init(&ADC_Configurations);
	DcMotor_Init();
	while (1) {
		temperature = LM35_getTemperature();
		/*If the temperature is less than 30C turn off the fan*/
		if ((temperature < 30) && (newTemp != temperature)) {
			newTemp = temperature;
			LCD_moveCursor(0, 4);
			LCD_displayString("Fan is OFF");
			LCD_moveCursor(1, 4);
			LCD_displayString("Temp =    C");
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temperature);
			DcMotor_Rotate(STOP, 0);
		}
		/*If the temperature is greater than or equal 30C turn on the fan with 25% of its maximum speed*/
		else if ((temperature >= 30) && (newTemp != temperature) && ( temperature<60 ) ) {
			newTemp = temperature;
			LCD_moveCursor(0, 4);
			LCD_displayString("Fan is ON ");
			LCD_moveCursor(1, 4);
			LCD_displayString("Temp =    C");
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temperature);
			DcMotor_Rotate(CLOCKWISE, 25);
		}
		/*If the temperature is greater than or equal 60C turn on the fan with 50% of its maximum speed*/
		else if ((temperature >= 60) && (newTemp != temperature) && (temperature<90 )) {
			newTemp = temperature;
			LCD_moveCursor(0, 4);
			LCD_displayString("Fan is ON ");
			LCD_moveCursor(1, 4);
			LCD_displayString("Temp =    C");
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temperature);
			DcMotor_Rotate(CLOCKWISE, 50);
		}
		/*If the temperature is greater than or equal 90C turn on the fan with 75% of its maximum speed*/
		else if ((temperature >= 60) && (newTemp != temperature) && (temperature<120 )) {
			newTemp = temperature;
			LCD_moveCursor(0, 4);
			LCD_displayString("Fan is ON ");
			LCD_moveCursor(1, 4);
			LCD_displayString("Temp =    C");
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temperature);
			DcMotor_Rotate(CLOCKWISE, 75);
		}
		/*If the temperature is greater than or equal 120C turn on the fan with 100% of its maximum speed*/
		else if ((temperature >= 120) && (newTemp != temperature)) {
			newTemp = temperature;
			LCD_moveCursor(0, 4);
			LCD_displayString("Fan is ON ");
			LCD_moveCursor(1, 4);
			LCD_displayString("Temp =    C");
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temperature);
			DcMotor_Rotate(CLOCKWISE, 100);
		}
	}
}

