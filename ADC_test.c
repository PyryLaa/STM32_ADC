/* ADC test with connecting potentiometer to pin PA1
 * please use the syscalls.c file provided in the github to use printf
 */








#include <stdint.h>
#include <stdio.h>

uint32_t *AdcClk = (uint32_t*) 0x40023844; //ADC clock control register
uint32_t *GpioClk = (uint32_t*) 0x40023830; //GPIO clock control register
uint32_t *GpioAModer = (uint32_t*) 0x40020000; //GPIOA mode register
uint32_t *Adc1r = (uint32_t*) 0x40012000; //ADC1 register
uint32_t *Adc1Sqr3 = (uint32_t*) 0x40012034; //ADC1 sequence register 3
uint32_t *Adc1Sqr1 = (uint32_t*) 0x4001202C; //ADC1 sequence register 1, for amount of conversions
uint32_t *Adc1Cr2 = (uint32_t*) 0x40012008; //ADC1 control register to enable the adc
uint32_t *Adc1Sr = (uint32_t*) 0x40012000; //ADC1 status register
uint32_t *Adc1Dr = (uint32_t*) 0x4001204C; //ADC1 data register

int adc_value;

void ADC_init();
uint32_t ADC_read();

int main(void){
	ADC_init();


	while(1){
		adc_value = ADC_read();
		printf("Value: %d\n", adc_value);
		for (int i = 0; i < 0xFFFFF; i++);
	}

}


void ADC_init(){

	*AdcClk |= (1 << 8); //Enable ADC1 clock
	*GpioClk |= (1 << 0); //Enable GPIOA clock
	*GpioAModer |= (0b11 << 2); //Pin A1 as analog
	*Adc1Sqr3 |= (1 << 0); //Only 1 sequence needed
	*Adc1Sqr1 = 0; //Amount of conversions is 1 so all bits to 0
	*Adc1Cr2 |= (1 << 0); //Enable the adc

}

uint32_t ADC_read(){

	*Adc1Cr2 |= (1 << 30); //Start the conversion

	while(!(*Adc1Sr & (1 << 1))); //Wait for the conversion to complete

	return *Adc1Dr;

}
