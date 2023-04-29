#ifndef FLIGHT_H
#define FLIGHT_H
    // ===> Libraries <===
    #include <ctime>
    #include <cstring>
    #include <iostream>
    #include <iomanip>

    // ===> Files <===

    // ===> Using From Libraries <===
    using std::tm;
    using std::cout;
    using std::endl;
    using std::flush;
    using std::setw;
    using std::setfill;
    using std::mktime;
    using std::strftime;

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
        int time;
        bool** seats;

        /*
            ===> Private Methods <===
        */


        /*
            ==> Public Methods <===
        */
        public:
            Flight(char*, char*, char*, char*, tm, char*, char*, char*, char*, char*, int, char*, bool**);
            ~Flight();
            void printLess();
            void printFull();
            void printSeats();
            void mod();
            char* getId();
    };
#endif