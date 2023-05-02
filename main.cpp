/* >>> INCLUDING LIBRARIES <<< */
#include <iostream>
#include <ctime>

// ===> Using <===
using std::cout;
using std::endl;
using std::flush;
using std::cin;

/* >>> INCLUDING FILES <<< */
#include "./Headers/Menu.h"

/* >>> Function headers <<< */
void tests();

int main() {
    Menu menu = Menu();
}

/*
    Things to check:
    * The state needs validation for some cases (Also Manual Mode only).
    * Date/Time mod needs validation as it only may accept later hours, and not days.
    * Model mod shouldnt be possible because the seats on a plane might be lost.
    * If dateTime is changed, change duration as well
    * The seats need to have a person assigned, so we might need a user class. 
*/

/* >>> Functions <<< */
void tests() {
    
}
