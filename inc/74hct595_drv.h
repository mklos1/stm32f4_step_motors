/*
 * 74hct595_drv.h
 *
 *  Created on: 14.11.2016
 *      Author: x
 */

#ifndef SRC_74HCT595_DRV_H_
#define SRC_74HCT595_DRV_H_

#define M3A				0x80
#define M2A				0x40
#define M1A				0x20
#define M1B				0x10
#define M2B				0x08
#define M4A				0x04
#define M3B				0x02
#define M4B				0x01

typedef enum {IC_DISABLE = 0, IC_ENABLE = !IC_DISABLE} ICState;

void ic74hct595_state(ICState state);
void ic74hct595_load(unsigned int val);
void ic74hct595_clk_pulse(void) __attribute__((always_inline));
void ic74hct595_latch_pulse(void) __attribute__((always_inline));



#endif /* SRC_74HCT595_DRV_H_ */
