/*
 * 74hct595_drv.c
 *
 *  Created on: 14.11.2016
 *      Author: x
 */

#include "74hct595_drv.h"
#include "port_config.h"

#include "stm32f4xx.h"

inline void IC_GPIO_WriteBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BitAction BitVal) __attribute__((always_inline));


void ic74hct595_state(ICState state) {
	if (state == IC_DISABLE)
		GPIO_SetBits(DIR_EN_PORT, DIR_EN_PIN);
	else
		GPIO_ResetBits(DIR_EN_PORT, DIR_EN_PIN);
	GPIO_ResetBits(DIR_LATCH_PORT, DIR_LATCH_PIN);
}

void ic74hct595_load(unsigned int val) {
	IC_GPIO_WriteBit(DIR_SER_PORT, DIR_SER_PIN, (val >> 0) & 1);
	ic74hct595_clk_pulse();
	IC_GPIO_WriteBit(DIR_SER_PORT, DIR_SER_PIN, (val >> 1) & 1);
	ic74hct595_clk_pulse();
	IC_GPIO_WriteBit(DIR_SER_PORT, DIR_SER_PIN, (val >> 2) & 1);
	ic74hct595_clk_pulse();
	IC_GPIO_WriteBit(DIR_SER_PORT, DIR_SER_PIN, (val >> 3) & 1);
	ic74hct595_clk_pulse();
	IC_GPIO_WriteBit(DIR_SER_PORT, DIR_SER_PIN, (val >> 4) & 1);
	ic74hct595_clk_pulse();
	IC_GPIO_WriteBit(DIR_SER_PORT, DIR_SER_PIN, (val >> 5) & 1);
	ic74hct595_clk_pulse();
	IC_GPIO_WriteBit(DIR_SER_PORT, DIR_SER_PIN, (val >> 6) & 1);
	ic74hct595_clk_pulse();
	IC_GPIO_WriteBit(DIR_SER_PORT, DIR_SER_PIN, (val >> 7) & 1);
	ic74hct595_clk_pulse();
	ic74hct595_latch_pulse();
}

inline void ic74hct595_clk_pulse(void) {
	DIR_CLK_PORT->BSRRH = DIR_CLK_PIN; //CLK 0
	DIR_CLK_PORT->BSRRL = DIR_CLK_PIN; //CLK 1
}

inline void ic74hct595_latch_pulse(void) {
	DIR_LATCH_PORT->BSRRL = DIR_LATCH_PIN; //LATCH 1
	DIR_LATCH_PORT->BSRRH = DIR_LATCH_PIN; //LATCH 0
}

inline void IC_GPIO_WriteBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BitAction BitVal)
{

  if (BitVal != Bit_RESET)
  {
    GPIOx->BSRRL = GPIO_Pin;
  }
  else
  {
    GPIOx->BSRRH = GPIO_Pin ;
  }
}
