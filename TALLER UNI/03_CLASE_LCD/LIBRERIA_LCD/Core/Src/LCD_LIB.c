/*
 * LCD_LIB.c
 *
 *  Created on: Mar 7, 2022
 *      Author: Diego
 */

#include "LCD_LIB.h"
#include "main.h"

void busdata(char a){
	HAL_GPIO_WritePin(GPIOB, D4_Pin, a & 0x01);
	HAL_GPIO_WritePin(GPIOB, D5_Pin, a & 0x02);
	HAL_GPIO_WritePin(GPIOB, D6_Pin, a & 0x04);
	HAL_GPIO_WritePin(GPIOA, D7_Pin, a & 0x08);
}

void comando(char a){
	HAL_GPIO_WritePin(GPIOC, EN_Pin,0);
	HAL_GPIO_WritePin(GPIOC, EN_Pin,1);
	busdata(a);
	HAL_Delay(1);
	HAL_GPIO_WritePin(GPIOC, EN_Pin,0);
}

void LCD_Init(void){
	comando(0x03);
	comando(0x03);
	comando(0x03);
	comando(0x02);
	comando(0x02);
	comando(0x08);
	comando(0x00);
	comando(0x08);
	comando(0x00);
	comando(0x01);
	comando(0x00);
	comando(0x0C); //0x0E
}

void LCD_SetCursor(char x, char y){

	char m,n;		//m= nibble high, n=nibble low
	if(y==1){
		m=0x80 + x;
		n=(0x80 + x)>>4;
		comando(n);
		comando(m);
	}
	if(y==2){
		m=0xC0+x;
		n=(0xc0+ x)>>4;
		comando(n);
		comando(m);
	}if(y==3){
		m=0x80 + 20 +x;
		n=(0x80 + 20 + x)>>4;
		comando(n);
		comando(m);
	}if(y==4){
		m=0xC0 +20 +x;
		n=(0xC0 + 20 +x)>>4;
		comando(n);
		comando(m);
	}

}

void LCD_PrintCaracter(char a){
	char m,n;
	m=a>>4;
	n=a;
	//RS=1;
	HAL_GPIO_WritePin(GPIOA, RS_Pin,1);
	comando(m);
	comando(n);
	HAL_GPIO_WritePin(GPIOA, RS_Pin, 0);
}

void LCD_PrintString(char a[]){
	for(int k=0;a[k]!='\0';k++){
		LCD_PrintCaracter(a[k]);
	}
}

void LCD_CreateCaracter(char a,char b, char c, char d, char e, char f, char g,char h, char i){
	if(a==1){
		comando(0x04);
		comando(0x00);
		HAL_GPIO_WritePin(GPIOA, RS_Pin,1);
		char m,n;
		m=b>>4;
		n=b;
		comando(m);
		comando(n);
		m=c>>4;
		n=c;
		comando(m);
		comando(n);
		m=d>>4;
		n=d;
		comando(m);
		comando(n);
		m=e>>4;
		n=e;
		comando(m);
		comando(n);
		m=f>>4;
		n=f;
		comando(m);
		comando(n);
		m=g>>4;
		n=g;
		comando(m);
		comando(n);
		m=h>>4;
		n=h;
		comando(m);
		comando(n);
		m=i>>4;
		n=i;
		comando(m);
		comando(n);
		HAL_GPIO_WritePin(GPIOA, RS_Pin,0);
		//comando(0x00);
		//comando(0x01);
		HAL_Delay(100);
	}if(a==2){
		comando(0x04);
		comando(0x08);
		HAL_GPIO_WritePin(GPIOA, RS_Pin, 1);
		char m,n;
		m=b>>4;
		n=b;
		comando(m);
		comando(n);
		m=c>>4;
		n=c;
		comando(m);
		comando(n);
		m=d>>4;
		n=d;
		comando(m);
		comando(n);
		m=e>>4;
		n=e;
		comando(m);
		comando(n);
		m=f>>4;
		n=f;
		comando(m);
		comando(n);
		m=g>>4;
		n=g;
		comando(m);
		comando(n);
		m=h>>4;
		n=h;
		comando(m);
		comando(n);
		m=i>>4;
		n=i;
		comando(m);
		comando(n);
		HAL_GPIO_WritePin(GPIOA, RS_Pin, 0);
		//comando(0x00);
		//comando(0x01);
		HAL_Delay(100);
	}
}

void LCD_WriteCaracter(char a){

		HAL_GPIO_WritePin(GPIOA, RS_Pin, 1);
		comando(0x00);
		comando(a-1);
		HAL_GPIO_WritePin(GPIOA, RS_Pin, 0);
}
