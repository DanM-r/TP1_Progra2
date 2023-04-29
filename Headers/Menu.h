#ifndef MENU_H
#define MENU_H
    // ===> Libraries <===
    #include <fstream>
    #include <cstring>
    #include <ctime>
    #include <iostream>
    #include <iomanip>

    // ===> Files <===
    #include "Flight.h"

    // ===> Using From Libraries <===
    using std::ofstream;
    using std::ifstream;
    using std::ios;
    using std::cout;
    using std::cerr;
    using std::cin;
    using std::endl;
    using std::flush;
    using std::left;
    using std::setfill;
    using std::setw;
    using std::tm;
    using std::strtok; 

    class Menu {
        /*
            ===> Atributes <===
        */
        Flight** list;
        int num_flights;

        /*
            ===> Private Methods <===
        */
        void printAll();
        int fnd(char*);
        bool rqst(char*);
        bool mod(char*);
        bool checkSeats(char*);
        void checkIn();
        void readData();
        void saveData();
        bool atool(char*);
        void copy(char*, char*);

        /*
            ==> Public Methods <===
        */
        public:
            ~Menu();
            Menu();
    };
#endif