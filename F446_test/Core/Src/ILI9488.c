//======================================//
// インクルード
//======================================//
#include "ILI9488.h"
//====================================//
// グローバル変数の宣言
//====================================//
// ILI9488を初期設定して画面をblackにして、シアンとマゼンタの矩形を描きます．
void LCD_setup(void){
//	LCD_RESET();							// hardware reset
	HAL_GPIO_WritePin(SPI_LCD_RESET_GPIO_Port, SPI_LCD_RESET_Pin, GPIO_PIN_RESET);
	HAL_Delay(200);
	HAL_GPIO_WritePin(SPI_LCD_RESET_GPIO_Port, SPI_LCD_RESET_Pin, GPIO_PIN_SET);
	HAL_Delay(200);							// 200mSec待ち
//	LCD_BACKLIGHT_ON();						// hardware back light LED ON
//	LCD_CS();								// hardware CS=Low
	LCD_send_command(ILI9488_SLPOUT);		// Sleep Out  (11H)
	LCD_send_command(ILI9488_MADCTL);		// Memory Access Ctl. (36H)
	LCD_send_byte(0xE0);					// 座標系設定
	LCD_send_command(ILI9488_PIXFMT);		// Interface Pixel fmt. (3AH)
	LCD_send_byte(0x01);					// 3bit/pixel mode

	LCD_rectangle(0,0,479,319,0);			// 全画面ブラック
	LCD_rectangle(0,0,239,159,6);			// シアンの矩形
	LCD_rectangle(239,159,479,319,5);		// マゼンタの矩形
}

// レジスタコマンド送信routine
void LCD_send_command( uint8_t x ){
	DTREG_LOW;			// DT/REG=Low
	SPI_LCD_SEND;
}

// データ送信routine
void LCD_send_byte(uint8_t x){
	DTREG_HIGH;			// DT/REG=High
	SPI_LCD_SEND;
}

// 矩形範囲を塗りつぶすroutine
void LCD_rectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t col){
	uint8_t c;
	c = col & 0x7;
	LCD_send_command(ILI9488_DISPOFF);			// 一応画面OFF
	LCD_send_command(ILI9488_CASET);			// 描画X座標範囲指定
	LCD_send_byte( x1>>8 );
	LCD_send_byte( x1 );
	LCD_send_byte( x2>>8 );
	LCD_send_byte( x2 );
	LCD_send_command(ILI9488_PASET);		// 描画Y座標範囲指定
	LCD_send_byte( y1>>8 );
	LCD_send_byte( y1 );
	LCD_send_byte( y2>>8 );
	LCD_send_byte( y2 );
	LCD_send_command(ILI9488_RAMWR);		// GRAM書き予告
	for(int i=0;i<(x2-x1)*(y2-y1)/2;i++) 
			LCD_send_byte((c<<3) + c);		// GRAMデータ送信
	LCD_send_command(ILI9488_DISPON);		// 画面ON
}
