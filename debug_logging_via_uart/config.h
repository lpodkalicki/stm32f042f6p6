/**
 * Copyright (c) 2015, Lukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 */

#ifndef _PROJECT_CONFIG_H_
#define _PROJECT_CONFIG_H_

#include "stm32f0xx_hal_uart.h"

/* -- DEBUG USART -- */
#define UART_DBG			USART2
#define UART_DBG_RCC_CLK_ENABLE()	__HAL_RCC_USART2_CLK_ENABLE()
#define UART_DBG_RX_GPIO_CLK_ENABLE()  	__HAL_RCC_GPIOA_CLK_ENABLE()
#define UART_DBG_TX_GPIO_CLK_ENABLE()	__HAL_RCC_GPIOA_CLK_ENABLE()
#define UART_DBG_FORCE_RESET()		__HAL_RCC_USART2_FORCE_RESET()
#define UART_DBG_RELEASE_RESET()	__HAL_RCC_USART2_RELEASE_RESET()
#define UART_DBG_TX_PIN			GPIO_PIN_2
#define UART_DBG_TX_GPIO_PORT		GPIOA
#define UART_DBG_TX_AF			GPIO_AF1_USART2
#define UART_DBG_RX_PIN			GPIO_PIN_3
#define UART_DBG_RX_GPIO_PORT		GPIOA
#define UART_DBG_RX_AF			GPIO_AF1_USART2

void SystemClock_Config(void);
void RCC_Config(void);
void GPIO_Config(void);
void UART_Config(void);

#endif	/* !_PROJECT_CONFIG_H_ */
