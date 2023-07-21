/*
 * File:   mainPreLab.c
 * Author: Christian Campos 
 *
 * Created on 17 de julio de 2023, 03:51 PM
 */

//******************************************************************************
// Palabra de configuración
//******************************************************************************
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

//******************************************************************************
// Librería
//******************************************************************************
#include <xc.h>
#include <stdio.h>
#include <stdint.h>
//******************************************************************************
// Variables
//******************************************************************************
#define _XTAL_FREQ 8000000     // Frecuencia de oscilador de 8MHz

unsigned char contador = 0;

//******************************************************************************
// Prototipos de función
//******************************************************************************
void setup(void);
//******************************************************************************
// Vector de Interrupción
//******************************************************************************
void __interrupt() isr(void) {
    if (INTCONbits.RBIF) {
        
        // Verificar si el pushbutton de suma fue presionado
        if (!PORTBbits.RB1) {
            contador++;
        }

        // Verificar si el pushbutton de resta fue presionado
        if (!PORTBbits.RB0) {
            contador--;
        }

        INTCONbits.RBIF = 0;    // Limpiar la bandera de interrupción del puerto B
    }
}
//******************************************************************************
// Función principal
//******************************************************************************
void main(void) {
    setup();     // Inicializar el microcontrolador

    while (1) {
        PORTD = contador;   // Mostrar el valor del contador en el puerto D
    }
}
//******************************************************************************
// Funciones secundarias
//******************************************************************************
void setup(void) {
    // Configuración de los puertos
    ANSEL=0;
    ANSELH=0;
    //Puerto B como entrada, con pullups
    OPTION_REGbits.nRBPU=0;
    TRISBbits.TRISB0=1;
    TRISBbits.TRISB1=1;
    WPUBbits.WPUB0=1;
    WPUBbits.WPUB1=1;
    // Configuración de las interrupciones por cambio en el puerto B
    IOCBbits.IOCB0 = 1;     // Habilitar interrupción para el pin RB0
    IOCBbits.IOCB1 = 1;     // Habilitar interrupción para el pin RB1
    //Puerto D como salida
    TRISD = 0b00000000;           // Puerto D como salida
    TRISA=0;
    //Oscilador a 8MHz
    OSCCONbits.IRCF=0b111;
    OSCCONbits.SCS=1;
    
    // Configuración de las interrupciones
    INTCONbits.GIE = 1;     // Habilitar interrupciones globales
    INTCONbits.PEIE = 1;
    INTCONbits.RBIE = 1;    // Habilitar interrupciones por cambio en el puerto B
    INTCONbits.RBIF = 0;    // Limpiar la bandera de interrupción del puerto B

    
}
