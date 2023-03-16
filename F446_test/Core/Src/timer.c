//======================================//
// インクルード
//======================================//
#include "timer.h"
//====================================//
// グローバル変数の宣言
//====================================//
int32_t timer500 = 0;
int32_t btm_cnt = 0;
int32_t btm_push = 0;
bool    ledG = true;
int v_led = 0;
bool v_lim = true;

int32_t cnt = 0;
//////////////////////////////////////////////////////////////////////////
// モジュール名 inturrpt1ms
// 処理概要     タイマ割り込み
// 引数         なし
// 戻り値       なし
//////////////////////////////////////////////////////////////////////////
void inturrpt1ms(void) {
    // lcdShowProcess();

//	if (v_led == 1000 ) {
//		v_lim = false;
//	} else if (v_led == 0) {
//		v_lim = true;
//	}
//
//	if (v_lim) v_led++;
//	else v_led--;

	// switch flag
	if ( !HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13) && btm_cnt > 500 ) {
		btm_push++;
		if (btm_push > 2) btm_push = 0;
		btm_cnt = 0;
	}
	btm_cnt++;

	// switch push
	// lcdRowPrintf(UPROW, "PWM %4d",(uint16_t)((double)analog[0]/4095*1000));
	switch( btm_push ) {
		case 0:
			// lcdRowPrintf(LOWROW, "    STOP");
			__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 0);
            
			// __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0);
			break;
		case 1:
			// lcdRowPrintf(LOWROW, " FORWARD");
            HAL_GPIO_WritePin(motorDIR_GPIO_Port, motorDIR_Pin, GPIO_PIN_SET);
			__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, (uint16_t)((double)analog[0]/4095*223));
			// __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0);
			break;
		case 2:
			// lcdRowPrintf(LOWROW, " REVERSE");
            HAL_GPIO_WritePin(motorDIR_GPIO_Port, motorDIR_Pin, GPIO_PIN_RESET);
            __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, (uint16_t)((double)analog[0]/4095*223));
            // __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0);
			break;
	}

//	if (btm_push) {
////		lcdRowPrintf(UPROW, "PWM %4d",(uint16_t)((double)analog[0]/4095*1000));
////		lcdRowPrintf(LOWROW, "A0 %5d",analog[0]);
//		lcdRowPrintf(LOWROW, "positive");
//		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, (uint16_t)((double)analog[0]/4095*1000));
//	} else if (btm_push == false){
//		lcdRowPrintf(LOWROW, "negative");
//	}

	timer500++;
	switch ( timer500 ) {
		case 500:
			if (ledG) HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_SET);   //LED ON
			else HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_RESET); //LED OFF
			ledG = !ledG;

			// printf("cnt: %d\r\n", cnt++);
			timer500 = 0;
			break;
		default:
			break;
	}
}
