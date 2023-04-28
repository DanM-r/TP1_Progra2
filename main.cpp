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
    /* std::tm dateTime{};
    dateTime.tm_year = 2023-1900;
    dateTime.tm_mday = 27;
    dateTime.tm_hour = 13;
    std::mktime(&dateTime);
    char output[100];
    std::strftime(output, sizeof(dateTime), "%m %d %Y %H %M %S", &dateTime);
    cout << output; */
    //tests();
    Menu menu = Menu();
}

/* >>> Functions <<< */
void tests() {
    bool* x = nullptr;
    bool* y = nullptr;
    char something[2] = "4";
    cout << something << endl;
    cout << atoi(something);
    x = new bool[atoi(something)];
    y = new bool[4];
    for (int i = 0; i < 4; i++) {
        x[i] = true;
        y[i] = false;
    }
    for (int i = 0; i < 4; i++) {
        cout << "x[" << i << "]: " << x[i] << endl;
        cout << "y[" << i << "]: " << y[i] << endl;
    }
    delete [] x;
    delete [] y;
}