#include "../Headers/CstringM.h"

CstringM::CstringM() {

}

int CstringM::len(const char* str) {

    int len = 0;
    int index = -1;

    do {

        index++;
        len++;

    } while (  str[index] != '\0'  );

    return len;
}

int CstringM::compare(const char* str1, const char* str2) {

    int result = 0;
    const int str1_len = this->len(str1);
    const int str2_len = this->len(str2);


    if (  str1_len == str2_len  ) {

        for (  int i = 0;  i < str1_len;  i++  ) {
            
            if (  str1[i] != str2[i]  ) {

                result = 1;

            }
        }

    } else {

        result = 1;

    }

    return result;
}

void CstringM::copy(char* destin, const char* source) {

    int index = -1;

    do {

        index++;
        destin[index] = source[index];

    } while (  source[index] != '\0'  );

}

void CstringM::concat(char* destin, const char* source) {

    int last_element_str1 = this->len(destin) - 1;
    int index = -1;

    do {

        index++;
        destin[last_element_str1 + index] = source[index];

    } while (  source[index] != '\0'  );

}

char* CstringM::str_ptr = nullptr;

char* CstringM::tok(char* str, const char* delim) {

    int str_index = -1;
    int len_delim = this->len(delim);
    char* tok = nullptr;
    
    if (  str != nullptr  ) {

        str_ptr = &str[0];
    }

    if (  this->len(str_ptr) > 2  ) {

        do {
            
            str_index++;

            for (  int i = 0;  i < len_delim;  i++  ) {

                if (  *(str_ptr + str_index) == delim[i]  ) {

                    tok = new char[str_index + 1];
                    *(str_ptr + str_index) = '\0';
                    break;

                }

            }

        } while (  *(str_ptr + str_index) != '\0'  );


        for (  int i = 0;  i < str_index + 1;  i++  ) {

            tok[i] = *(str_ptr + i);

        }

        str_ptr += str_index + 1;


    }
    
    return tok;
}