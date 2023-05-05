#ifndef PLANESEATS_H
#define PLANESEATS_H
    // ===> Libraries <===
    #include <fstream>
    #include <ctime>
    #include <iostream>
    #include <iomanip>

    // ===> Files <===
    #include "../Headers/User.h"
    #include "CstringM.h"

    // ===> Using From Libraries <===
    using std::cout;
    using std::cerr;
    using std::cin;
    using std::endl;
    using std::flush;
    using std::left;
    using std::setfill;
    using std::setw;
    using std::tm;

    class PlaneSeats {
        /*
            ===> Atributes <===
        */
        CstringM csm = CstringM();
        int rows;
        int collumns;
        bool** seats;
        User** users;

        /*
            ===> Private Methods <===
        */

        /*
            ==> Public Methods <===
        */
        public:
            PlaneSeats(int, int);
            PlaneSeats(int, int, bool**, User**);
            ~PlaneSeats();
            void printSeats();
            void reserveSeats(char* name);
            int getRows();
            int getCollumns();
            bool** getSeats();
            User** getUsers();
            bool isEmpty();
    };
#endif