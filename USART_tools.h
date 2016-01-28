#ifndef USART_TOOLS_H
#define USART_TOOLS_H

#include <stdint.h>
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_usart.h"
#include "stm32f4xx_dma.h"

#ifdef __cplusplus
	extern "C" {
#endif

void UART_init();
uint16_t inline UART_DMA_print(uint8_t *message, uint16_t len);
void UART_print(char *message,uint16_t len);

#ifdef __cplusplus
	}
#endif

#endif
