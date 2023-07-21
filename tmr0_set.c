/* 
 * File:   tmr0_set.c
 * Author: Christian
 * Comments: Lab1
 * Revision history: A
 */

#include "tmr0_set.h"

//******************************************************************************
// Configuración Preescaler; mandar como binario, decimal o hexadecimal
//******************************************************************************
void tmr0_preescaler(char preescaler){
switch (preescaler) {
    case 1:
        OPTION_REGbits.PSA=1;
        break;
    case 2:
        OPTION_REGbits.PSA=0;
        OPTION_REGbits.PS=0;
        break;
    case 4:
        OPTION_REGbits.PSA=0;
        OPTION_REGbits.PS=0x1;
        break;
    case 8:
        OPTION_REGbits.PSA=0;
        OPTION_REGbits.PS=0x2;
        break;
    case 16:
        OPTION_REGbits.PSA=0;
        OPTION_REGbits.PS=0x3;
        break;
    case 32:
        OPTION_REGbits.PSA=0;
        OPTION_REGbits.PS=0x4;
        break;
    case 64:
        OPTION_REGbits.PSA=0;
        OPTION_REGbits.PS=0x5;
        break;
    case 128:
        OPTION_REGbits.PSA=0;
        OPTION_REGbits.PS=0x6;
        break;
    case 256:
        OPTION_REGbits.PSA=0;
        OPTION_REGbits.PS=0x7;
        break;
    default:
        OPTION_REGbits.PSA=1;
        break;
    }
}

//******************************************************************************
// Configuración valor precargado TMR0; mandar como binario, decimal o hex
//******************************************************************************
void tmr0_value(char tmr0_value){
    TMR0 = tmr0_value;
}
//******************************************************************************
// Configuración interrupcióntimer0; mandar como binario, decimal o hexadecimal
//******************************************************************************
void tmr0_configIE(int Enable){
    if (Enable!=0 && Enable!=1){
        Enable=0;
    }
    INTCONbits.GIE = 1;     // Habilitar interrupciones globales
    INTCONbits.T0IE=Enable; //Toma el valor del enable
    INTCONbits.T0IF=0;
    OPTION_REGbits.T0CS= 0;  
    OPTION_REGbits.T0SE = 0;  

}



