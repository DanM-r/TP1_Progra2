#include "../Headers/User.h"

User::User(char* name, char* seat) {
    strcpy(this->name, name);
    strcpy(this->seat, seat);
}

User::~User() {

}

char* User::getName() {
    return this->name;
}

char* User::getSeat() {
    return this->seat;
}