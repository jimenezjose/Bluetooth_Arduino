#ifndef CONTROLLER_H 
#define CONTROLLER_H /* multiple inclusion guard */

#define MAX_DIM 255
#define MIN_DIM 0

#define CONTROL_FUNCS { button_up, button_down,  button_left, button_right,\
                        button_select, button_start, button_triangle, \
                        button_square, button_o, button_x, powerButton, \
                        powerButton, NULL }

/* Controller Mode */
int button_up();
int button_down();
int button_left();
int button_right();
int button_select();
int button_start();
int button_triangle();
int button_square();
int button_o();
int button_x();

/* Switch Mode */
int powerButton();

/* Dimmer Mode */
int slideButton();

#endif 
