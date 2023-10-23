# STM32_ADC
ADC with STM32F407G

Convert Analog data in pin PA1 to voltage. Data is here emulated with potentiometer. 
Uses the stm32f4xx_hal library for USART connection to host PC and prints the data in a terminal, eg. Tera Term
I used Arduino Uno as the USART - USB converter here

How to convert USART to USB with Arduino:
1. Ground the reset pin
2. Connect STM32 RX to Arduino RX and STM32 TX to Arduino TX
3. Connect Arduino and STM32 grounds
Now when you choose the COM port with the Arduino from your terminal program, you should see the data printed there
