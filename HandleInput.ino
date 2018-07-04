/****************************************************************************
                                                Jose Jorge Jimenez-Olivas
                                                CSE 12, Winter Quarter
                                                June 25, 2018

File Name:      HandleInput.ino
Description:    Reads Serial data recieved from the bluetooth module and 
                interprets the serial data into button commands. 
****************************************************************************/
#include "handleInput.h"
#include "controller.h"

static const char * const COMMANDS_LIST[] = COMMANDS;
static int (* const button_funcs[])() = CONTROL_FUNCS;

/***************************************************************************
% Routine Name : populateBuffer
% File :         HandleInput.ino
% Parameters:    buffer: character buffer awaiting to be filled with bytes
%                        of bluetooth data.
%                size:   size of the character buffer.
% Description :  Populates buffer with bytes of Serial data. After the 
%                all the bytes are read, the message is null terminated.
% Return:        Nothing
***************************************************************************/
void populateBuffer( char * buffer, long size ) {

  int index; /* buffer index */

  index = 0;
  while( Serial.available() > 0 && index < size - 1 ) {
    /* populate buffer with bluetooth data*/
    buffer[ index ] = toLowerCase( Serial.read() );
    index++;
    delay( BT_TX_DELAY );
  }

  buffer[ index ] = '\0';

}

/***************************************************************************
% Routine Name : interpretCmd
% File :         HandleInput.ino
% Parameters:    command: command string
% Description :  Translates the command string into its button function 
%                pointer
% Return:        pointer to the interpreted command function OR NULL if 
%                command is not recognized. 
***************************************************************************/
int ( * interpretCmd( char * command ))() {

  int validInt = atoi( buffer ) || buffer[ 0 ] == '0'; /* valid integer conv.*/
  int stringLen = strlen( command ); /* length of user command string */
  int index = 0; 		                       /* commands list index */

  while( COMMANDS_LIST[ index ] != NULL ) {
    /* searching for command in list */
    if( strncmp( command, COMMANDS_LIST[ index ], stringLen ) == 0 ) {
      return button_funcs[ index ];
    }
    index++;
  }

  if( validInt ) {
    /* Controller in Dimmer Mode */
    return slideButton;
  }

  return NULL;
}
