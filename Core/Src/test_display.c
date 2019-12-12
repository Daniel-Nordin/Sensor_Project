/*
 * test_display.c
 *
 *  Created on: Dec 9, 2019
 *      Author: Daniel
 */

#include <test_display.h>

void test_disp(){

	update_display('2', 1, 0);
	update_display('3', 1, 0);
	update_display(':', 1, 0);
	update_display('5', 1, 0);
	update_display('6', 1, 0);

}

void test_brightness(){

	pwm_bright(30);
}
