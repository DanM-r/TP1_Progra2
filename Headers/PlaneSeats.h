#ifndef PLANESEATS_H
#define PLANESEATS_H
    // ===> Libraries <===
    #include <fstream>
    #include <cstring>
    #include <ctime>
    #include <iostream>
    #include <iomanip>

    // ===> Files <===
    #include "../Headers/User.h"

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
    using std::strtok; 

    class PlaneSeats {
        /*
            ===> Atributes <===
        */
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
            int geetCollumns();
            bool** getSeats();
            User** getUsers();
    };
#endif