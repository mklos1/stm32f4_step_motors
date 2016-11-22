/*
 * l293d_drv.h
 *
 *  Created on: 15.11.2016
 *      Author: x
 */

#ifndef INC_L293D_DRV_H_
#define INC_L293D_DRV_H_

#define STEPS_PER_REV				512
#define DEG_PER_STEP				87890

#define CYCLES8

void step(int dir);
void angle(unsigned int angle, unsigned int delay, int dir);




#endif /* INC_L293D_DRV_H_ */
