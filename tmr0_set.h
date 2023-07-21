/* 
 * File:   tmr0_set.h
 * Author: Christian
 * Comments: Lab1-TMR0
 * Revision history: A
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef tmr0set_H
#define	tmr0set_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
/** Para el ReadMe
    <p><b>Function prototype: Configuraci�n TMR0</b></p>
  
    <p><b>Summary: Configura el tmr0</b></p>

    <p><b>Description: Esta librer�a configura el tmr0 dependiendo de los valores
 * de: preescaler y TMR0 Preload requeridos </b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters: preescaler es el valor del preescaler del TMR0; tmr0_value
 * es el valor precargado del TMR0; mandar ambos como valores num�ricos </b></p>

    <p><b>Returns:</b></p>

    <p><b>Example: </b></p>
    <code>
 
    </code>

    <p><b>Remarks: </b></p>
 */

//******************************************************************************
// Configuraci�n Preescaler
//******************************************************************************
void tmr0_preescaler(char preescaler);

//******************************************************************************
// Configuraci�n valor precargado TMR0
//******************************************************************************
void tmr0_value(char tmr0_value);
//******************************************************************************
// Configuraci�n interrupci�ntimer0
//******************************************************************************
void tmr0_configIE(int Enable);

#endif	/* tmr0set_H */


