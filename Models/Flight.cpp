#include "..\Headers\Flight.h"

Flight::Flight(char* id, char* model, char* from, char* to, tm dateTime, int time, char* state, bool** seats) {
    strcpy(this->id, id);
    strcpy(this->model, model);
    strcpy(this->from, from);
    strcpy(this->to, to);
    strcpy(this->state, state);
    this->dateTime = dateTime;
    this->time = time;
    this->seats = seats;
}

Flight::~Flight() {
    
}

void Flight::printLess() {
    mktime(&dateTime);
    cout << this->id << ", " << this->model << ", " << this->from << ", " << this->to << ", " << asctime(&this->dateTime) << ", " << this->state << ", " << endl;
}

void Flight::printFull() {
    
}

void Flight::printSeats() {
    
}