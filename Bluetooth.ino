/****************************************************************************

                                                Jose Jorge Jimenez-Olivas
                                                June 25, 2018

                      Arduino bluetooth controller

File Name:      Bluetooth.ino
Description:    This program integrates the HC-06 bluetooth module
		with the "Arduino Bluetooth Controller" app. Compatible to 
		Controller, Swicth, Dimmer, and Terminal mode.
****************************************************************************/

#include "HandleInput.h"
#include "Controller.h"

#include <IRremote.h>
IRsend irsend;



char buffer[ BUFSIZ ] = { 0 }; /* user input buffer */
int (* commandFunc)();         /* interpreted bluetooth command */

const int ledPin = 3;

/***************************************************************************
% Routine Name : setup
% File :         Bluetooth.ino
% Parameters:    None
% Description :  Configure arduino peripherals 
% Return:        Nothing
***************************************************************************/
void setup() {
  Serial.begin( 9600 );
  pinMode( ledPin, OUTPUT );
}

/***************************************************************************
% Routine Name : loop
% File :         Bluetooth.ino
% Parameters:    None
% Description :  logic driver for interpreting and executing the correct
%		 button function.
% Return:        Nothing
***************************************************************************/
void loop() {
 if( Serial.available() > 0 ) {
    /* Serial data incoming */
    populateBuffer( buffer, BUFSIZ ); /* populate buffer BT data */
    Serial.println( buffer );         /* report command on the serial monitor */

    commandFunc = interpretCmd( buffer ); /* interpret button pressed */
    if( commandFunc != NULL ) {
      /* valid button comand - execute button function */
      commandFunc();
    }

  }
  
}

