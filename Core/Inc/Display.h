/*
 * Display.h
 *
 *  Created on: 9 Dec 2019
 *      Author: Daniel
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_



#endif /* INC_DISPLAY_H_ */

#include <stdint.h>
#include <spi.h>
#include <tim.h>
#include <adc.h>

void update_display(uint8_t data, uint8_t rs, uint8_t rw);
void BG_green(int t);
void Display_init();
void pwm_brightness();
void clear_display();
