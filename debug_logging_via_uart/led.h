/**
 * Copyright (c) 2015, Lukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 */

#ifndef _PROJECT_LED_H_
#define _PROJECT_LED_H_

#include "stm32f0xx_hal_gpio.h"

#define	LED_NUM			(1)
#define	LED_GPIO_PORT		GPIOB
#define	LED_GPIO_PIN1		GPIO_PIN_1
#define LED_GPIO_CLK_ENABLE() 	__HAL_RCC_GPIOB_CLK_ENABLE()

typedef enum {
	LED1, // Blue
} led_t;

#define	LED_BLUE		LED1

void led_on(led_t led);
void led_off(led_t led);
void led_toggle(led_t led);
void led_all_on();
void led_all_off();

#endif	/* !_PROJECT_LED_H_ */
