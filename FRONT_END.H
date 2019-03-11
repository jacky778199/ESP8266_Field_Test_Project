#ifndef FRONT_END_H
#define FRONT_END_H

#include <Arduino.h>

class FRONT_END {

public:

        FRONT_END ();

        ~FRONT_END ();

        char * Home_page();

		char* Gateway_mode();

		char* Node_mode();

};


#endif