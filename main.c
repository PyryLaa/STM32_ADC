#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "defines.h"

UART_HandleTypeDef huart2;
char buf[50];

void UART_Init(void);
void send_data(char*);
void ADC_init();
uint32_t ADC_read();

int adc_value;



int main(void){
	float voltage;
	HAL_Init();
	UART_Init();
	ADC_init();

	*GpioClk |= (1 << 0); //Enable GPIOA clock
	*GpioAModer |= (0b11 << 2); //Pin A1 as analog

	while(1){
		adc_value = ADC_read();
		voltage = (float)adc_value * (3.0/4096.0);
		sprintf(buf, "Value: %d\n\r", adc_value);
		send_data(buf);
		sprintf(buf, "Voltage: %f\n\r", voltage);
		send_data(buf);
		HAL_Delay(1000);
	}
}

void UART_Init(void){
	__HAL_RCC_USART2_CLK_ENABLE();

	huart2.Instance = USART2;
	huart2.Init.BaudRate = 115200;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.Mode = UART_MODE_TX_RX;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;

	HAL_UART_Init(&huart2);

}

void send_data(char* data){
	HAL_UART_Transmit(&huart2, (uint8_t*) data, strlen(data), HAL_MAX_DELAY);
}

void ADC_init(){

	*AdcClk |= (1 << 8); //Enable ADC1 clock
	*Adc1Sqr3 |= (1 << 0); //Only 1 sequence needed
	*Adc1Sqr1 = 0; //Amount of conversions is 1 so all bits to 0
	*Adc1Cr2 |= (1 << 0); //Enable the adc

}

uint32_t ADC_read(){

	*Adc1Cr2 |= (1 << 30); //Start the conversion

	while(!(*Adc1Sr & (1 << 1))); //Wait for the conversion to complete

	return *Adc1Dr;

}
