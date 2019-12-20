/*
 * test_time.c
 *
 *  Created on: Dec 9, 2019
 *      Author: Daniel
 */

#include <test_time.h>

void test_time(){
	set_time();

	get_time();

	update_time();
}

void test_uart(){
	int a = receiveUART();
}
