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
  
    <p><b>Summary: Configuración de un Display de 7 Segmentos Anodo</b></p>

    <p><b>Description: Esta librería configura el Display de 7 segmentos ánodo
 * haciendo la conversión del valor que se le mande al PUERTO al que se 
 * conecte el display </b></p>

    <p><b>Precondition: Mandar valor como decimal, binario o hexadecimal, el
 * valor puede ir de 0 a F</b></p>

    <p><b>Parameters: Valor es el número que se quiere desplegar en el 
 * display</b></p>

    <p><b>Returns: Valor Display a un PUERTO</b></p>

    <p><b>Example: PORTA=conversorD7A(10); mostraría A en el display</b></p>
    <code>
 
    </code>

    <p><b>Remarks: NOTA IMPORTANTE: 
    Esta configuración está hecha para un display ánodo
    Para un display catodo se podría usar la misma función pero al llamarla
    Habría que negarla: PORTX=~conversorD7A(value)  </b></p>
 */

//******************************************************************************
// Función conversor a Display 7 segmentos 
//******************************************************************************
char conversorD7A(char value);


#endif	/* DISPLAY7A_H */


