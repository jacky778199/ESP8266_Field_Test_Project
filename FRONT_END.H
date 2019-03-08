#ifndef FRONT_END_H
#define FRONT_END_H

#include <Arduino.h>

class FRONT_END {

public:

        FRONT_END ();

        ~FRONT_END ();

        char * Home_page();

        String Gateway_mode();

        String Node_mode();

};


#endif