/* 
 * File:   
 * Author: Christian
 * Comments: Lab1-ADC
 * Revision history: A
 */

#include "ADC_config.h"
#define _XTAL_FREQ 8000000     // Frecuencia de oscilador de 8MHz
//******************************************************************************
// Configuración ADC; configura el ADC con su canal respectivo
//******************************************************************************
void adc_init(int channel){
    INTCONbits.GIE = 1;     // Habilitar interrupciones globales
    INTCONbits.PEIE = 1; //Habilitar interrupciones perifericas
    PIE1bits.ADIE=1; //Habilitar interrupciones por ADC
    PIR1bits.ADIF=0; //Bandera ADC
    
    
    //config ADC
    ADCON0bits.ADCS=0;
    ADCON0bits.CHS= channel; //Configuración canal ADC
    ADCON1bits.ADFM=0;
    __delay_ms(10);    
    ADCON1bits.VCFG0=0;
    ADCON1bits.VCFG1=0;
    ADCON0bits.ADON=1;
    
    
    adc_change_channel(channel);//Configuración canal ADC
    ADCON0bits.GO=1;
    
}
//******************************************************************************
// Lectura ADC; retorna el valor del ADC
//******************************************************************************
int adc_read (){
    return ADRESH;
}
//******************************************************************************
// Cambiar canal ADC
//Se pide el número entero del canal analógico para la lectura ADC
//******************************************************************************
void adc_change_channel(int channel){
    switch (channel) { //Se configura cada canal dependiendo del valor
            case 0x00:
                 TRISAbits.TRISA0= 1;    // AN0
                 ANSELbits.ANS0=1;
                break;
                
            case 0x01:
                TRISAbits.TRISA1= 1;    // AN1
                ANSELbits.ANS1=1;
                break;
            case 0x02:
                 TRISAbits.TRISA2= 1;    // AN2
                 ANSELbits.ANS2=1;
                break;
                
            case 0x03:
                TRISAbits.TRISA3= 1;    // AN3
                ANSELbits.ANS3=1;
                break;
                
            case 0x04:
                TRISAbits.TRISA5= 1;    // AN4
                ANSELbits.ANS4=1;
                break;
                
            case 0x05:
                TRISEbits.TRISE0= 1;    // AN5
                ANSELbits.ANS5=1;
                break;
                
            case 0x06:
                TRISEbits.TRISE1= 1;    // AN6
                ANSELbits.ANS6=1;
                break;
                
            case 0x07:
                TRISEbits.TRISE2= 1;    // AN7
                ANSELbits.ANS7=1;
                break;
                
            case 0x08:
                TRISBbits.TRISB2= 1;    // AN8
                ANSELHbits.ANS8=1;
                break;
                
            case 0x09:
                TRISBbits.TRISB3= 1;    // AN9
                ANSELHbits.ANS9=1;
                break;
                
            case 0x10:
                TRISBbits.TRISB1= 1;    // AN10
                ANSELHbits.ANS10=1;
                break;
                
            case 0x11:
                TRISBbits.TRISB4= 1;    // AN11
                ANSELHbits.ANS11=1;
                break;
                
            case 0x12:
                TRISBbits.TRISB0= 1;    // AN12
                ANSELHbits.ANS12=1;
                break;
                
            case 0x13:
                TRISBbits.TRISB5= 1;    // AN13
                ANSELHbits.ANS13=1;
                break;
                
            
        }
}
//******************************************************************************
// Conocer el canal de configuración; devuelve el canal como un entero
//******************************************************************************
int adc_get_channel(){
    return ADCON0bits.CHS;
}

