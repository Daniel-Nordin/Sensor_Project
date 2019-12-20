/**
 * Time.c
 *
 *  Created on: Dec 9, 2019
 *      Author: Daniel
 */
#include <Time.h>
/**
 * @breif Gets the time from the rtc and sends it to the display
 * @param none
 * @retval none
 */
void update_time(){
	uint8_t temp;
	RTC_TimeTypeDef real_time;

	clear_display();
	real_time = get_time();
	temp = real_time.Hours;
	update_display((char)((temp / 10) + 48), 1, 0);
	update_display((char)((temp % 10) + 48), 1, 0);
	update_display(':', 1, 0);
	temp = real_time.Minutes;
	update_display((char)((temp / 10) + 48), 1, 0);
	update_display((char)((temp % 10) + 48), 1, 0);
	update_display(':', 1, 0);
	temp = real_time.Seconds;
	update_display((char)((temp / 10) + 48), 1, 0);
	update_display((char)((temp % 10) + 48), 1, 0);
	HAL_Delay(100);
}
/**
 * @breif Gets the current time from the rtc
 * @param none
 * @retval time struct
 */
RTC_TimeTypeDef get_time() {
	RTC_TimeTypeDef gTime;
	RTC_DateTypeDef gDate;

	HAL_RTC_GetTime(&hrtc, &gTime, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &gDate, RTC_FORMAT_BIN);

	return gTime;
}
/**
 * @breif Sets the rtc's time by getting input from uart
 * @param none
 * @retval none
 */
void set_time() {
	RTC_TimeTypeDef sTime;
	RTC_DateTypeDef sDate;

	sTime.StoreOperation = RTC_STOREOPERATION_RESET;
	sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	sTime.Hours = receiveUART();
	sTime.Minutes = receiveUART();
	sTime.Seconds = receiveUART();


	HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN);

}
/**
 * @breif Receives data from the uart port
 * @param none
 * @retval uart data
 */
uint8_t receiveUART() {
	uint8_t uart = 0;

	if (HAL_UART_Receive(&huart5, &uart, 1, HAL_MAX_DELAY) != HAL_OK) {
		Error_Handler();
	}
	else{
		return uart;
	}

}
