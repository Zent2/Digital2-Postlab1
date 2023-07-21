# Digital2-Postlab1

 *********************************************************************************************************************************************************************/
    <p><b>Function prototype: IOC_INIT</b></p>
  
    <p><b>Summary: Función que configura los pines como interrupción</b></p>

    <p><b>Description: Esta función configura los pines que se le envien
 *  como interrupciones, lo que significa que al cambiar de estado se 
 * activará la interrupción.</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters: PINES DEL PUERTO B QUE SE QUIERE COLOCAR COMO 
 * INTERRUPCIONES</b></p>

    <p><b>Returns: N/A</b></p>

    <p><b>Example: ioc_init(0) hará que el pin 0 del PORTB tenga habilitada 
 * las interrupciones</b></p>
    <code>
 
    </code>

    <p><b>Remarks: </b></p>
 *********************************************************************************************************************************************************************/
     <p><b>Function prototype: ADC_CONFIG</b></p>
  
    <p><b>Summary: Configuración del ADC</b></p>

    <p><b>Description: Esta librería configura el ADC, permitiendo escoger
 * el puerto de entrada y el puerto de salida del ADC, sin necesidad de tener la
 * salida, puede tener solo la entrada.</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters: Channel, el canal analógico a leer</b></p>

    <p><b>Returns: Lectura ADC</b></p>

    <p><b>Example: adc_init(0); //Configura el adc en el canal 0
 * PORTB=adc_read();  //Muestra ADC en PORTB
 * __delay_ms(10); //Delay antes de cambio de canal
 * adc_change_channel(1); //cambia el canal al canal 1
 * PORTC=adc_read(); //Muestra ADC en PORTC
 * PORTE=adc_get_channel(); //Devuelve el valor/número del canal al 
 * PuertoE</b></p>
    <code>
 
    </code>

    <p><b>Remarks: </b></p>
 */
 
 *********************************************************************************************************************************************************************/
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
 *********************************************************************************************************************************************************************/
    <p><b>Function prototype: Configuración TMR0</b></p>
  
    <p><b>Summary: Configura el tmr0</b></p>

    <p><b>Description: Esta librería configura el tmr0 dependiendo de los valores
 * de: preescaler y TMR0 Preload requeridos </b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters: preescaler es el valor del preescaler del TMR0; tmr0_value
 * es el valor precargado del TMR0; mandar ambos como valores numéricos </b></p>

    <p><b>Returns:</b></p>

    <p><b>Example: </b></p>
    <code>
 
    </code>

    <p><b>Remarks: </b></p>
 */
