#ifndef LCD_H
#define LCD_H


#define LCD_RS          _RB3
#define LCD_EN          _RB4
#define LCD_D4          _RB5
#define LCD_D5          _RB6
#define LCD_D6          _RB8
#define LCD_D7          _RB9

#define LCD_RS_TRIS     _TRISB3
#define LCD_EN_TRIS     _TRISB4
#define LCD_D4_TRIS     _TRISB5
#define LCD_D5_TRIS     _TRISB6
#define LCD_D6_TRIS     _TRISB8
#define LCD_D7_TRIS     _TRISB9



void LCD_SendData(byte);
void LCD_WriteConf(byte);
void LCD_WriteChar(byte);
void LCD_Init(void);


#endif	/* LCD_H */
