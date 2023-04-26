#ifndef FLIGHT_H
#define FLIGHT_H
    // ===> Libraries <===
    #include <ctime>
    #include <iostream>
    #include <iomanip>

    // ===> Files <===
    #include "AirplaneSeats.h"

    // ===> Using From Libraries <===
    using std::tm;
    using std::cout;
    using std::setw;

    class Flight {
        /*
            ===> Atributes <===
        */
        char id[6];
        char model[50];
        char* aircrew[6];
        char from[50];
        char to[50];
        char state[10];
        tm dateTime;
        int time;
        AirplaneSeats seats;

        /*
            ===> Private Methods <===
        */


        /*
            ==> Public Methods <===
        */
        public:
            Flight(char*, char*, char*, char*, tm);
            ~Flight();
            void printLess();
            void printFull();
            void printSeats();
    };
#endif