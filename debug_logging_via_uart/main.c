/**
 * Copyright (c) 2015, Lukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 */

#include "stm32f0xx_hal.h"
#include "config.h"
#include "led.h"
#include "log.h"

extern void error_handler(void);
extern UART_HandleTypeDef UART_DBG_Handle;
#define DELAY   (1000)

int
main(void)
{

	HAL_Init();
        SystemClock_Config();
        RCC_Config();
        GPIO_Config();
	UART_Config();

        if (SysTick_Config(SystemCoreClock / 1000)) {
                error_handler();
        }

        log_init(LOGLEVEL_INFO);
        log_info("PROJECT STERTED");

        while (1) {
                led_toggle(LED_BLUE);
		log_info("Hello! :)");
                HAL_Delay(DELAY);
	}
}
