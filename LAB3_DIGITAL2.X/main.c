/*
 * File:   main.c
 * Author: jotas
 *
 * Created on February 5, 2020, 12:32 PM
 */

// PIC16F887 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include "LCD_8bits.h"
#define _XTAL_FREQ 4000000
char hola[12];

void main(void) {
    TRISD = 0;
    TRISC = 0;
    PORTD = 0;
    PORTC = 0;
    LCD_init();
    //LCD_clear();
    //sprintf(hola, "hola %.2d", w );
    //LCD_Write_String("Hola malnacidos, vamos a chupar");
    LCD_Set_Cursor(1,3);
    LCD_Write_String("Sho viejo");
    LCD_Set_Cursor(2,5);
    while(1){
        LCD_Write_Character('W');
        LCD_Cursor_rechts(1);
        //LCD_Write_String("UA UA UA UA");
        //LCD_Shift_links();
        __delay_ms(500);
    }
    return;
}
