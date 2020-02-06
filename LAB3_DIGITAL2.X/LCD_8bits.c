/*
 * File:   LCD_8bits.c
 * Author: josue
 *
 * Created on February 5, 2020, 12:37 PM
 */


#include <xc.h>
#include <stdint.h>
#include "LCD_8bits.h"

#define _XTAL_FREQ 4000000   // cambiar de acuerdo a la configuracion del OSC
#define D0 PORTDbits.RD0
#define D1 PORTDbits.RD1
#define D2 PORTDbits.RD2
#define D3 PORTDbits.RD3
#define D4 PORTDbits.RD4
#define D5 PORTDbits.RD5
#define D6 PORTDbits.RD6
#define D7 PORTDbits.RD7

#define RS PORTCbits.RC0
#define EN PORTCbits.RC1

#define DATA_PORT PORTD 


void LCD_Port(uint8_t bits){
    PORTD = bits;
}

void LCD_Cmd(uint8_t comando){
    RS = 0;
    __delay_ms(5);
    EN = 1;
    __delay_ms(5);
    //LCD_Port(comando);
    DATA_PORT = comando;
    __delay_ms(5);
    EN = 0;
    __delay_ms(5);
}

void LCD_clear(void){
    LCD_Cmd(0x00);
    LCD_Cmd(0x01);
    __delay_ms(4);
}

void LCD_home(void){
    LCD_Cmd(0x00);
    LCD_Cmd(0x02);
    __delay_ms(4);
}

void LCD_init(void){
    __delay_ms(20);
    LCD_Cmd(0x30);
    __delay_ms(5);
    LCD_Cmd(0x30);
    __delay_us(100);
    LCD_Cmd(0x30);
    __delay_us(100);
    LCD_Cmd(0x38);
    __delay_us(53);
    LCD_Cmd(0x08);
    __delay_us(53);
    LCD_Cmd(0x01);
    __delay_ms(3);
    LCD_Cmd(0x06);
    __delay_us(53);
    LCD_Cmd(0x0C);
    __delay_us(53);
}

void LCD_Write_Character(char caracter){
    RS = 1;
    // LCD_Port(caracter);
    DATA_PORT = caracter;
    EN = 1;
    __delay_us(40);
    EN = 0;
}

void LCD_Write_String(char *a){
    int n;
    for(n = 0; a[n] != '\0'; n++){
        LCD_Write_Character(a[n]);
    }
}