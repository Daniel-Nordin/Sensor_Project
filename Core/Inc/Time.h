/*
 * Time.h
 *
 *  Created on: Dec 9, 2019
 *      Author: Daniel
 */

#ifndef INC_TIME_H_
#define INC_TIME_H_



#endif /* INC_TIME_H_ */

#include <stdint.h>
#include <Display.h>
#include <usart.h>
#include <rtc.h>

void set_time();
uint8_t receiveUART();
RTC_TimeTypeDef get_time();
void update_time();
