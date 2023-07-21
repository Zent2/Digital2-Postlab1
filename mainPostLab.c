/*
 * File:   mainPostLab.c
 * Author: Christian Campos 
 *
 * Created on 20 de julio de 2023, 11:58 AM
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
// Librerías Generales
//******************************************************************************
#include <xc.h>
#include <stdio.h>
#include <stdint.h>
//******************************************************************************
// Librerías Propias
//******************************************************************************
#include "ioc_init.h"
#include "ADC_config.h"
#include "display7A.h"
#include "tmr0_set.h"
//******************************************************************************
// Variables
//******************************************************************************
#define _XTAL_FREQ 8000000     // Frecuencia de oscilador de 8MHz

unsigned char contador = 0;
unsigned char display, valor1, valor2;
int preescaler=2;
int valor_timer0=0;
int c;

//******************************************************************************
// Prototipos de función
//******************************************************************************
void setup(void);
//******************************************************************************
// Vector de Interrupción
//******************************************************************************
void __interrupt() isr(void) {
    if (INTCONbits.T0IF){
        if (c==0){
            PORTA=conversorD7A(valor1);
            RE0=1;
            RE1=0;            
            c=1;//Cambia al siguiente puerto pero hasta la siguiente interrupción
        }
        else if (c==1){ //El else es para que solo realice uno de los 2 ifs y no ambos
            PORTA=conversorD7A(valor2);
            RE0=0;
            RE1=1;
            c=0;
        }
        
        INTCONbits.T0IF=0; //Limpiar bandera T0IF
    }
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
    if (PIR1bits.ADIF && !INTCONbits.RBIF && !INTCONbits.T0IF) {
        display=adc_read(); //Leer ADC y guardar valor en una variable
        __delay_us(10); //Pequeño delay de seguridad
        PIR1bits.ADIF=0; //Limpiar bandera ADC
        
    }
    return;
}
//******************************************************************************
// Función principal
//******************************************************************************
void main(void) {
    setup();     // Inicializar el microcontrolador

    while (1) {
        PORTD = contador;   // Mostrar el valor del contador en el puerto D
        valor1 = (display >> 4) & 0x0F; // Desplaza 4 bits a la derecha y aplica una máscara para conservar solo los 4 bits más significativos.
        valor2 = display & 0x0F; // Aplica una máscara para conservar solo los 4 bits menos significativos.
        ADCON0bits.GO=1; //Inicia conversión ADC
        if (PORTD<=display){
            RE2=1; //Bandera de alarma encendida 
        }
        if (PORTD>display){
            RE2=0;//Bandera de alarma apagada
        }
    }
}
//******************************************************************************
// Funciones secundarias
//******************************************************************************
void setup(void) {
    // Configuración de los puertos
    TRISB = 0;           
    PORTB=0; //Estas 2 lineas solo es para asegurarnos que solo se activen como entradas las que queremos
    ioc_init(0);
    ioc_init(1);
    TRISD = 0;           
    PORTD=0;
    TRISA=0;
    PORTA=0;
    TRISE=0;
    PORTE=0b010; //Valor inicial del multiplexeado xd
    //Oscilador a 8MHz
    OSCCONbits.IRCF=0b111;
    OSCCONbits.SCS=1;
    
    
    
    // Configuración TMR0
    tmr0_preescaler(preescaler); //Configura el preescaler
    tmr0_value(valor_timer0); //configura el valor inicial del TMR0
    tmr0_configIE(1); //Habilita interripciones por Timer0
    //Configuración ADC 
    adc_init(13); //Inicia conversión ADC con el canal indicado
    
}
