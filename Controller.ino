/****************************************************************************
                                                Jose Jorge Jimenez-Olivas
                                                June 25, 2018

File Name:      Controller.ino
Description:    Button command functions. Button behavior is handled in this
                file, every function is mapped to a specific button from the 
                bluetooth controller. 
****************************************************************************/
#include "controller.h"

/* Connected in: Controller Mode */

int button_up() {

  return 0;
}

int button_down() {

  return 0;
}

int button_left() {

  return 0;
}

int button_right() {

  return 0;
}

int button_select() {

  return 0;
}

int button_start() {

  return 0;
}

int button_triangle() {

  return 0;
}

int button_square() {
  
  return 0;
}

int button_o() {

  return 0;
}

int button_x() {

  return 0;
}

/* Connected in: Swicth Mode */

int powerButton() {

  digitalWrite( ledPin , !digitalRead( ledPin ) );

  return 0;
}

/* Connected in: Dimmer Mode */


int slideButton() {

  return 0; 
}


