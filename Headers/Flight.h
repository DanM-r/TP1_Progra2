#ifndef FLIGHT_H
#define FLIGHT_H
    // ===> Libraries <===
    #include <ctime>
    #include <cstring>
    #include <iostream>
    #include <iomanip>

    // ===> Files <===
    #include "../Headers/PlaneSeats.h"

    // ===> Using From Libraries <===
    using std::tm;
    using std::cout;
    using std::cin;
    using std::cerr;
    using std::endl;
    using std::flush;
    using std::setw;
    using std::setfill;
    using std::mktime;
    using std::strftime;
    using std::time_t;
    using std::time;
    using std::localtime;
    using std::difftime;

    class Flight {
        /*
            ===> Atributes <===
        */
        char id[6];
        char model[50];
        char* aircrew[5];
        char from[50];
        char to[50];
        char state[10];
        tm dateTime;
        int duration;
        PlaneSeats* seats;

        /*
            ===> Private Methods <===
        */


        /*
            ==> Public Methods <===
        */
        public:
            Flight(char*, char*, char*, char*, tm, char*, char*, char*, char*, char*, int, char*, bool**, int, int);
            ~Flight();
            void printLess();
            void printFull();
            bool isInactive();
            void mod();
            char* getId();
            char* getModel();
            char* getFrom();
            char* getTo();
            char* getDateTime();
            char* getAircrew();
            int getDuration();
            char* getState();
            void setDateTime(char*);
            void setAircrew(char*, int);
    };
#endif