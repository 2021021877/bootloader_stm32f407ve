#ifndef __BSP_UART_C
#define __BSP_UART_C
#include "stm32f4xx.h"
#include <stdio.h>

void Uart_Init(void);
void Uart_SendByte(USART_TypeDef* USARTx, uint8_t byte);
uint8_t Uart_ReceByte(USART_TypeDef* USARTx);

#endif
