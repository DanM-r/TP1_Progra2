#ifndef USER_H
#define USER_H
    // ===> Libraries <===
    #include <fstream>
    #include <ctime>
    #include <iostream>
    #include <iomanip>
    #include "CstringM.h"

    // ===> Files <===

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

    class User {
        /*
            ===> Atributes <===
        */
        CstringM csm = CstringM();
        char name[50];
        char seat[3];

        /*
            ===> Private Methods <===
        */

        /*
            ==> Public Methods <===
        */
        public:
            User(char*, char*);
            ~User();
            char* getSeat();
            char* getName();
    };
#endif