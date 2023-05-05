#ifndef CSTRINGM_H
#define CSTRINGM_H

    #include <iostream>

    using std::cout;
    using std::endl;
    using std::flush;
    using std::cin;

    class CstringM {
        // ===> Atributes <===
        static char* str_ptr;

        // ===> Methods <===
        public:
            CstringM();
            int len(const char*);
            int compare(const char*, const char*);
            void copy(char*, const char*);
            void concat(char*, const char*);
            char* tok(char*, const char*);
    };

#endif