#ifndef WS2812C_H_
#define WS2812C_H_

//====================================//
// インクルード
//====================================//
#include "main.h"
//====================================//
// シンボル定義
//====================================//
#define MAX_LED 1
#define USE_BRIGHTNESS 1
#define PI 3.14159265
//====================================//
// グローバル変数の宣言
//====================================//
extern uint8_t datasentflag;

//====================================//
// プロトタイプ宣言
//====================================//
void Set_LED (int LEDnum, int Red, int Green, int Blue);
void Set_Brightness (int brightness);
void WS2812_Send (void);
#endif // WS2812C_H_
