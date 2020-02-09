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

void LCD_Set_Cursor(uint8_t linea, uint8_t columna){
    uint8_t corrimiento = 0;
    switch (linea){
        case 1:
            corrimiento = 0x80 + columna;
            LCD_Cmd(corrimiento);
            break;
        case 2:
            corrimiento = 0x80 + 0x40 + columna;
            LCD_Cmd(corrimiento);
            break;
        default:
            LCD_Cmd(0x80);
    }
}

void LCD_Shift_links(){
    LCD_Cmd(0x18);
}

void LCD_Shift_rechts(){
    LCD_Cmd(0x1C);
}

void LCD_Cursor_rechts(uint8_t espacios){
    for (uint8_t n = 0; n <= espacios; n++){
        LCD_Cmd(0x14);
    }
}

void LCD_Cursor_links(uint8_t espacios){
    for (uint8_t n = 0; n <= espacios; n++){
        LCD_Cmd(0x10);
    }
}

char uint_to_char(uint8_t numero){
    char numChr = 214;
    switch (numero){
        case 0:
            numChr = 48;
            break;
        case 1:
            numChr = 49;
            break;
        case 2:
            numChr = 50;
            break;
        case 3:
            numChr = 51;
            break;
        case 4:
            numChr = 52;
            break;
        case 5:
            numChr = 53;
            break;
        case 6:
            numChr = 54;
            break;
        case 7:
            numChr = 55;
            break;
        case 8:
            numChr = 56;
            break;
        case 9:
            numChr = 57;
            break;
        default:
            numChr = 214;
    }
    return(numChr);
}