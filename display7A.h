/* 
 * File:   display7A.h
 * Author: Christian
 * Comments: Lab1-Display7
 * Revision history: A
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef DISPLAY7A_H
#define	DISPLAY7A_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
/** Para el ReadMe
    <p><b>Function prototype: ADC_CONFIG</b></p>
  
    <p><b>Summary: Configuraci�n de un Display de 7 Segmentos Anodo</b></p>

    <p><b>Description: Esta librer�a configura el Display de 7 segmentos �nodo
 * haciendo la conversi�n del valor que se le mande al PUERTO al que se 
 * conecte el display </b></p>

    <p><b>Precondition: Mandar valor como decimal, binario o hexadecimal, el
 * valor puede ir de 0 a F</b></p>

    <p><b>Parameters: Valor es el n�mero que se quiere desplegar en el 
 * display</b></p>

    <p><b>Returns: Valor Display a un PUERTO</b></p>

    <p><b>Example: PORTA=conversorD7A(10); mostrar�a A en el display</b></p>
    <code>
 
    </code>

    <p><b>Remarks: NOTA IMPORTANTE: 
    Esta configuraci�n est� hecha para un display �nodo
    Para un display catodo se podr�a usar la misma funci�n pero al llamarla
    Habr�a que negarla: PORTX=~conversorD7A(value)  </b></p>
 */

//******************************************************************************
// Funci�n conversor a Display 7 segmentos 
//******************************************************************************
char conversorD7A(char value);


#endif	/* DISPLAY7A_H */


