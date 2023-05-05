#ifndef MENU_H
#define MENU_H
    // ===> Libraries <===
    #include <fstream>
    #include <ctime>
    #include <iostream>
    #include <iomanip>

    // ===> Files <===
    #include "Flight.h"
    #include "PlaneSeats.h"
    #include "User.h"
    #include "CstringM.h"

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

    class Menu {
        /*
            ===> Atributes <===
        */
        CstringM csm = CstringM();
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
        bool checkIn(char*);
        void readData();
        void saveData();
        bool atool(char*);
        void cleanList();

        /*
            ==> Public Methods <===
        */
        public:
            ~Menu();
            Menu();
    };
#endif