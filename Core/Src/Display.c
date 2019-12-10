/*
 * Display.c
 *
 *  Created on: 9 Dec 2019
 *      Author: Daniel
 */

#include <Display.h>

void update_display(uint8_t data, uint8_t rs, uint8_t rw){

	uint8_t transmit_data[3];
	transmit_data[0] = 0x1F;
	if(rw == 1)
		transmit_data[0] = transmit_data[0] | 0x3F;
	if(rs == 1)
		transmit_data[0] = transmit_data[0] | 0x5F;

	transmit_data[1] = data & 0x0F;
	transmit_data[2] = (data >> 4) & 0x0F;

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi2, &transmit_data, 3, HAL_MAX_DELAY);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
}

void BG_green(int t){
	//HAL_TIM_PWM_Start();

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, GPIO_PIN_SET);
	HAL_Delay(t);
	//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, GPIO_PIN_RESET);
}

void Display_init(){
	HAL_GPIO_WritePin(Disp_Reset_GPIO_Port, Disp_Reset_Pin, GPIO_PIN_RESET);
	HAL_Delay(500);
	HAL_GPIO_WritePin(Disp_Reset_GPIO_Port, Disp_Reset_Pin, GPIO_PIN_SET);
	HAL_Delay(500);

	uint8_t func_set[3] = { 0x1f, 0x01, 0x03 };
	uint8_t clear_disp[3] = { 0x1f, 0x01, 0x0 };
	uint8_t internal_div[3] = { 0x1f, 0x03, 0x01 };
	uint8_t contrast_set[3] = { 0x1f, 0x0f, 0x07 };
	uint8_t power_icon_power[3] = { 0x1f, 0x0c, 0x05 };
	uint8_t follower_ctrl[3] = { 0x1f, 0x0e, 0x06 };
	uint8_t on_off[3] = { 0x1f, 0x0f, 0x0 };

	HAL_SPI_Transmit(&hspi2, &func_set, 3, 100);
	HAL_SPI_Transmit(&hspi2, &clear_disp, 3, 100);
	HAL_SPI_Transmit(&hspi2, &internal_div, 3, 100);
	HAL_SPI_Transmit(&hspi2, &contrast_set, 3, 100);
	HAL_SPI_Transmit(&hspi2, &power_icon_power, 3, 100);
	HAL_SPI_Transmit(&hspi2, &follower_ctrl, 3, 100);
	HAL_SPI_Transmit(&hspi2, &on_off, 3, 100);
}
