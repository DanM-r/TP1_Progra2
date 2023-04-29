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
char** vvfv();

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
    int p;
    char* n [5];
    char** x = vvfv();
    for (int i = 0; i < 5; i++) {
        n[i] = x[i];
    }
    cout << "test 1";
    cout << "test 2" << endl;
    cin >> p;
}

char** vvfv() {
    char* l = new char[] {"Ja"};
    char** z = new char*[5];
    for (int i = 0; i < 5; i++) {
        z[i] = l;
    }
    return z;
}