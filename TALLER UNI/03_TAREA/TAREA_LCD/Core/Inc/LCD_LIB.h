/*
 * LCD_LIB.h
 *
 *  Created on: Mar 7, 2022
 *      Author: Diego
 */

#ifndef INC_LCD_LIB_H_
#define INC_LCD_LIB_H_

void busdata(char a);

void comando(char a);

void LCD_Init(void);

void LCD_SetCursor(char x, char y);

void LCD_PrintCaracter(char a);

void LCD_PrintString(char a[]);

void LCD_CreateCaracter(char a,char b, char c, char d, char e, char f, char g,char h, char i);

void LCD_WriteCaracter(char a);

#endif /* INC_LCD_LIB_H_ */
