/* 
 * File:   Display7A.c
 * Author: Christian
 * Comments: Lab1
 * Revision history: A
 */

#include "display7A.h"

//******************************************************************************
// Variables Internas
//******************************************************************************
char out;
//******************************************************************************
// Configuración de salida del PUERTO en el que querramos colocar el display
//Se pide el valor en formato de char, o sea como decimal, binario o Hexadecimal
//Devuelve el valor en char, para poder mostrarlo en un puerto
//NOTA IMPORTANTE: Esta configuración está hecha para un display ánodo
//Para un display catodo se podría usar la misma función pero al llamarla
//Habría que negarla: PORTX=~conversorD7A 
//******************************************************************************
char conversorD7A(char value){
    switch (value) { 
    case 0:
        out = 0x3F; // 0 (0b00111111)
        break;
    case 1:
        out = 0x06; // 1 (0b00000110)
        break;
    case 2:
        out = 0x5B; // 2 (0b01011011)
        break;
    case 3:
        out = 0x4F; // 3 (0b01001111)
        break;
    case 4:
        out = 0x66; // 4 (0b01100110)
        break;
    case 5:
        out = 0x6D; // 5 (0b01101101)
        break;
    case 6:
        out = 0x7D; // 6 (0b01111101)
        break;
    case 7:
        out = 0x07; // 7 (0b00000111)
        break;
    case 8:
        out = 0x7F; // 8 (0b01111111)
        break;
    case 9:
        out = 0x6F; // 9 (0b01101111)
        break;
    case 10:
        out = 0x77; // A (0b01110111)
        break;
    case 11:
        out = 0x7C; // B (0b01111100)
        break;
    case 12:
        out = 0x39; // C (0b00111001)
        break;
    case 13:
        out = 0x5E; // D (0b01011110)
        break;
    case 14:
        out = 0x79; // E (0b01111001)
        break;
    case 15:
        out = 0x71; // F (0b01110001)
        break;
    default:
        out= 0x00;
        break;
    }
}



