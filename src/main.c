/*
 * main.c
 *
 *  Created on: 07.11.2016
 *      Author: x
 */

#include "stm32f4xx.h"

#include "stm32f4xx_conf.h"
#include "common.h"
#include "port_config.h"

#include "74hct595_drv.h"
#include "l293d_drv.h"

extern int main(void);

int main (void) {
	int i = 0;
	unsigned int delay=52;
	MCU_init();
	ic74hct595_state(IC_ENABLE);

	GPIO_WriteBit(PWM0A_PORT, PWM0A_PIN, 1);
	GPIO_WriteBit(PWM0B_PORT, PWM0B_PIN, 1);
	GPIO_WriteBit(PWM1A_PORT, PWM1A_PIN, 1);
	GPIO_WriteBit(PWM1B_PORT, PWM1B_PIN, 1);
	GPIO_WriteBit(PWM2A_PORT, PWM2A_PIN, 1);
	GPIO_WriteBit(PWM2B_PORT, PWM2B_PIN, 1);

	while(1) {
		delay=51;
		for(i=0; i < 4096; i++) {
			step(1);
			//angle(360, 10, -1);
			if (i < 50)
				delay_pool(delay--);
			if (i > 4046)
				delay_pool(delay++);
			else
				delay_pool(delay);
		}
		delay_pool(2000);
	}

	return 0;
}

