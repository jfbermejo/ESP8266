/*
 * Sketch que comunica con el módulo ESP8266 mediante comandos AT
 * El módulo se conecta a través de un puerto serie emulado en pines 10 y 11
 * Utilizando el monitor serie se pueden enviar comandos al módulo
 * 
 * Algunos de los comandos AT de configuración para ESP8266:
 *    - AT+CIOBAUD?         Consulta la frecuencia a la que trabaja el módulo ESP
 *    - AT+CIOBAUD=9600     Fija la frecuencia a la que trabaja el módulo ESP
 *    - AT+RST              Reinicia el módulo ESP
 *    - AT+CWMODE?          Consulta el modo de trabajo del ESP (1 cliente, 2 host, 3 ambos)
 *    - AT+CWMODE=modo      Fija el modo de trabajo del ESP
 *    - AT+CWLAP            Consulta los SSID de las redes wifi disponibles
 *    - AT+CWLAP?           Consulta la información de la red wifi a la que está conectado el ESP
 *    - AT+CWJAP=SSID,PWD   Conecta a la red wifi especificada
 */

#include "SoftwareSerial.h"       //Libreria para emular puerto serial

SoftwareSerial Serial2(10, 11);   // RX, TX

void setup(){ 
  Serial.begin(9600);   //Iniciar el monitor serial
  Serial2.begin(9600);  //Iniciar el modulo ESP
}
 
void loop(){

  // Envia los datos de la consola serial al ESP
  // Muestra lo enviado por el ESP en la consola serial
  
  if( Serial2.available() ){ 
    char a = Serial2.read();
    Serial.print(a);
  }
  
  if( Serial.available() ){ 
    char a = Serial.read();
    Serial2.print(a);
  }
  
}
