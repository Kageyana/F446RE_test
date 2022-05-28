#ifndef ILI9488_H_
#define ILI9488_H_
//====================================//
// インクルード
//====================================//
#include "main.h"
//====================================//
// シンボル定義
//====================================//
#define 	ILI9488_SLPOUT  0x11
#define		ILI9488_MADCTL	0x36
#define		ILI9488_PIXFMT  0x3a
#define		ILI9488_DISPON	0x29
#define		ILI9488_DISPOFF	0x28
#define		ILI9488_CASET 	0x2a
#define		ILI9488_PASET	0x2b
#define		ILI9488_RAMWR	0x2c

#define 	SPI_LCD_SEND 	HAL_SPI_Transmit(&hspi1, &x, 1, 1000)
#define 	DTREG_HIGH 		HAL_GPIO_WritePin(SPI_LCD_DTREG_Pin, SPI_LCD_DTREG_Pin, GPIO_PIN_SET)
#define 	DTREG_LOW 		HAL_GPIO_WritePin(SPI_LCD_DTREG_Pin, SPI_LCD_DTREG_Pin, GPIO_PIN_RESET)
//====================================//
// グローバル変数の宣言
//====================================//
extern SPI_HandleTypeDef hspi1;
//====================================//
// プロトタイプ宣言
//====================================//
void LCD_setup(void);
void LCD_send_command( uint8_t x );
void LCD_send_byte(uint8_t x);
void LCD_rectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t col);
#endif // ILI9488_H_
