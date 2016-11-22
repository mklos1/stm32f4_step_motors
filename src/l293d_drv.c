#include "stm32f4xx_conf.h"
#include "l293d_drv.h"
#include "74hct595_drv.h"
#include "common.h"
#include "port_config.h"


unsigned int step_counter = 0;

void step(int dir) {
	unsigned int val;
#ifdef CYCLES8
	switch (step_counter % 8) {
	case 0:
		val = M1A;
		ic74hct595_load(val);
		break;
	case 1:
		val = M1A | M2A;
		ic74hct595_load(val);
		break;
	case 2:
		val = M2A;
		ic74hct595_load(val);
		break;
	case 3:
		val = M2A | M1B;
		ic74hct595_load(val);
		break;
	case 4:
		val = M1B;
		ic74hct595_load(val);
		break;
	case 5:
		val = M1B | M2B;
		ic74hct595_load(val);
		break;
	case 6:
		val = M2B;
		ic74hct595_load(val);
		break;
	case 7:
		val = M2B | M1A;
		ic74hct595_load(val);
		break;
	default:
		break;
	}
#else
	switch (step_counter % 4) {
	case 0:
		val = M1A;
		ic74hct595_load(val);
		break;
	case 1:
		val = M2A;
		ic74hct595_load(val);
		break;
	case 2:
		val = M1B;
		ic74hct595_load(val);
		break;
	case 3:
		val = M2B;
		ic74hct595_load(val);
		break;
	default:
		break;
	}
#endif
	if (dir > 0)
		step_counter++;
	else step_counter--;
}



void angle(unsigned int angle, unsigned int delay, int dir) {
	unsigned int i;
	unsigned int cnt;
	unsigned int step_count = (angle * 1000000) / DEG_PER_STEP;
	for(i = 0; i < step_count; i++) {
		step(dir);
		delay_pool(delay);
	}
}

