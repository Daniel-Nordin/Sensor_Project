/*
 * test_display.c
 *
 *  Created on: Dec 9, 2019
 *      Author: Daniel
 */

#include <test_display.h>

void test_disp(){
	Display_init();
	while(1){
		update_display(0xAA, 0, 0);
		HAL_Delay(1000);
		update_display(0xBB, 0, 1);
		HAL_Delay(1000);

		BG_green(500);
	}
}


