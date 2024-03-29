#ifndef TIMER_H_
#define TIMER_H_
//====================================//
// インクルード
//====================================//
#include "main.h"
//====================================//
// シンボル定義
//====================================//

//====================================//
// グローバル変数の宣言
//====================================//
extern int32_t  timer500;
extern int32_t  btm_cnt;
extern int32_t  btm_push;
extern bool     ledG;

extern int32_t cnt;
//====================================//
// プロトタイプ宣言
//====================================//
void inturrpt1ms(void);

#endif // TIMER_H_
