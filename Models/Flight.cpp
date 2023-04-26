#include "..\Headers\Flight.h"

Flight::Flight(char* id, char* model, char* from, char* to, tm dateTime) {
    strcpy(this->id, id);
    strcpy(this->model, model);
    strcpy(this->from, from);
    strcpy(this->to, to);
    this->dateTime = dateTime;
    strcpy(this->state, "Scheduled");
}

void Flight::printLess() {
    cout << this->id << setw(5) << this->model << setw(20) << this->from << setw(20) << this->to << setw(20) << this->state;
}

void Flight::printFull() {
    
}

void Flight::printSeats() {
    
}