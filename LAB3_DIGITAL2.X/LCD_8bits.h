/* 
 * File:   LCD_8bits.h
 * Author: Josue Asturias
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __LCD_8BITS_H
#define	__LCD_8BITS_H

#include <xc.h> // include processor files - each processor file is guarded.  


void LCD_Port(uint8_t bits);
void LCD_Cmd(uint8_t comando);
void LCD_clear(void);
void LCD_home(void);
void LCD_init(void);
void LCD_Write_Character(char caracter);
void LCD_Write_String(char *a);


#endif	

