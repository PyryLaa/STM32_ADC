/*
 * defines.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Pyry
 */

#ifndef INC_DEFINES_H_
#define INC_DEFINES_H_

#define AdcClk ((uint32_t*)0x40023844) //ADC clock control register
#define GpioClk ((uint32_t*)0x40023830) //GPIO clock control register
#define GpioAModer ((uint32_t*)0x40020000) //GPIOA mode register
#define Adc1r ((uint32_t*)0x40012000) //ADC1 register
#define Adc1Sqr3 ((uint32_t*)0x40012034) //ADC1 sequence register 3
#define Adc1Sqr1 ((uint32_t*)0x4001202C) //ADC1 sequence register 1, for amount of conversions
#define Adc1Cr2 ((uint32_t*)0x40012008) //ADC1 control register to enable the adc
#define Adc1Sr ((uint32_t*)0x40012000) //ADC1 status register
#define Adc1Dr ((uint32_t*)0x4001204C) //ADC1 data register

#endif /* INC_DEFINES_H_ */
