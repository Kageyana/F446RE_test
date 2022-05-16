#ifndef I2C_LCD_H_
#define I2C_LCD_H_
#ifdef __cplusplus
extern "C" {
#endif
//====================================//
// インクルード
//====================================//
#include "main.h"
#include <stdio.h>
#include <stdarg.h>
//====================================//
// シンボル定義
//====================================//
// スレーブアドレス
#define LCD_SLAVEADDRESS	0x7C
// 液晶関連変数
#define LCD_MAX_X	17		// 表示文字数 横 16 or 20
#define LCD_MAX_Y	2		// 表示文字数 縦  2 or  4
#define RSBIT0		0x00	// コマンド送信ビット
#define RSBIT1		0x40	// データ送信ビット
#define UPROW       0       // 1行目
#define LOWROW      1       // 2行目

#define CLOCK		84		// 動作周波数[MHz]

/******************************** 自動生成関数 *********************************/
#define 	I2C_LCD_DATA_SEND	HAL_I2C_Master_Transmit(&hi2c1,LCD_SLAVEADDRESS,word,2,100);
#define	    I2C_LCD_CMD_SEND	HAL_I2C_Master_Transmit(&hi2c1,LCD_SLAVEADDRESS,Command,2,100);
/***************************************************************************/
//====================================//
// グローバル変数の宣言
//====================================//
extern I2C_HandleTypeDef hi2c1;
//====================================//
// プロトタイプ宣言
//====================================//
// LCD関連
void waitLcd ( short waitTime );
void lcdShowProcess ( void );
void lcdPosition ( char x ,char y );
void intiLcd ( void );
void lcdCMD ( uint8_t  cmd );
void lcdPut ( uint8_t  data );
void lcdClear( void );
int lcdPrintf ( char *format, ... );
void lcdcursol (void);
int lcdRowPrintf (char step, char *format, ...);

#endif // I2C_LCD_H_
