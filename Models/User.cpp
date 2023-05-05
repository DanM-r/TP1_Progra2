#include "../Headers/User.h"

User::User(char* name, char* seat) {
    csm.copy(this->name, name);
    csm.copy(this->seat, seat);
}

User::~User() {

}

char* User::getName() {
    return this->name;
}

char* User::getSeat() {
    return this->seat;
}