/****************************************************************************

                                                Jose Jorge Jimenez-Olivas
                                                June 25, 2018

                      Arduino bluetooth controller

File Name:      Bluetooth_Arduino.ino
Description:    This program integrates the HC-06 bluetooth module
		with the "Arduino Bluetooth Controller" app. Compatible to 
		Controller, Swicth, Dimmer, and Terminal mode.
****************************************************************************/

#include <SoftwareSerial.h>
#include "HandleInput.h"
#include "Controller.h"

char buffer[ BUFSIZ ] = { 0 }; /* user input buffer */
int (* commandFunc)();         /* interpreted bluetooth command */

SoftwareSerial BT(10, 11);     /* RX, TX */
const int ledPin = 7;
const int knobPin = A0;

void setup() {
  Serial.begin( 9600 );
  BT.begin( 9600 );
  pinMode( ledPin, OUTPUT );
  pinMode( knobPin, INPUT );
}

void loop() {

  if( BT.available() > 0 ) {
    /* incomming Bluetooth data */
    populateBuffer( buffer, BUFSIZ );              /* populate buffer BT data */
    Serial.println( buffer );         /* report command on the serial monitor */
    commandFunc = interpretCmd( buffer );         /* interpret button pressed */
    if( commandFunc != NULL ) {
      /* valid button comand - execute button function */
      commandFunc();
    }
  }

  if( Serial.available() > 0 ) {
    /* Bluetooth communication */
    String message = getMessage();
    sendMessage( message );
  }
  
}

