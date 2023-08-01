//======================================//
// インクルード
//======================================//
#include "control.h"
//====================================//
// グローバル変数の宣言
//====================================//
uint16_t analog[2];
//////////////////////////////////////////////////////////////////////////
// モジュール名 initSys
// 処理概要     初期化
// 引数         なし
// 戻り値       なし
//////////////////////////////////////////////////////////////////////////
void initSys(void) {
    // intiLcd();						// LCD initialize
    // lcdClear();						// LCD clear
    HAL_TIM_Base_Start_IT(&htim6);	// タイマ割り込み(1ms)
    // PWM start
    if (HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3) != HAL_OK)	Error_Handler();
    if (HAL_TIM_PWM_Start(&htim13, TIM_CHANNEL_1) != HAL_OK)	Error_Handler();
    if (HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2) != HAL_OK)	Error_Handler();
    // LCD ON
    // lcdRowPrintf(UPROW, "Hello  ");
    // lcdRowPrintf(LOWROW, "Cube IDE");
    // ADC start
    if (HAL_ADC_Start_DMA(&hadc1, (uint16_t *) analog, 1) != HAL_OK) Error_Handler();
    HAL_GPIO_WritePin(motorDIR_GPIO_Port, motorDIR_Pin, GPIO_PIN_RESET);
    // Graphic display
    // LCD_setup();
}
