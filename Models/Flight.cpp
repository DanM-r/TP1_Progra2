#include "..\Headers\Flight.h"

Flight::Flight(char* id, char* model, char* from, char* to, tm dateTime, char* pilot, char* copilot, char* attend1, char* attend2, char* attend3, int time, char* state, bool** seats) {
    strcpy(this->id, id);
    strcpy(this->model, model);
    strcpy(this->from, from);
    strcpy(this->to, to);
    strcpy(this->state, state);
    aircrew[0] = new char[sizeof(pilot)/sizeof(pilot[0])];
    strcpy(this->aircrew[0], pilot);
    aircrew[1] = new char[sizeof(copilot)/sizeof(copilot[1])];
    strcpy(this->aircrew[1], copilot);
    aircrew[2] = new char[sizeof(attend1)/sizeof(attend1[2])];
    strcpy(this->aircrew[2], attend1);
    aircrew[3] = new char[sizeof(attend2)/sizeof(attend2[3])];
    strcpy(this->aircrew[3], attend2);
    aircrew[4] = new char[sizeof(attend3)/sizeof(attend3[4])];
    strcpy(this->aircrew[4], attend3);
    this->dateTime = dateTime;
    this->time = time;
    this->seats = seats;
}

Flight::~Flight() {
    for (int i = 0; i < 5; i++) {
        delete aircrew[i];
    }
}

void Flight::printLess() {
    char output[16];
    mktime(&dateTime);
    strftime(output, sizeof(this->dateTime), "%m/%d/%Y %H:%M", &this->dateTime);
    cout << setw(10) << this->id << setw(20) << this->model << setw(20) << this->from << setw(20) << this->to << setw(20) << output << setw(20) << this->state << endl;
}

void Flight::printFull() {
    char output[16];
    mktime(&dateTime);
    strftime(output, sizeof(this->dateTime), "%m/%d/%Y %H:%M", &this->dateTime);
    cout << setfill('-');
    cout << "+" << setw(90) << "+" << endl;
    cout << setfill(' ');
    cout << "|" << setw(5) << "ID: " << setw(20) << this->id << setw(10) << "Model: " << setw(20) << this->model << setw(10) << "State: " << setw(20) << this->state << "|" << endl;
    cout << "|" << setw(10) << "From: " << setw(20) << this->from << setw(10) << "To: " << setw(20) << this->to << setw(10) << "At: " << setw(20) << output << "|" << endl;
    cout << "|" << setw(10) << "Time: " << setw(20) << this->time << setw(10) << "Pilot: " << setw(20) << this->aircrew[0] << setw(10) << "Copilot: " << setw(20) << this->aircrew[1] << "|" << endl;
    cout << "|" << setw(20) << "Flight Attendants: " << setw(20) << this->aircrew[2] << setw(20) << this->aircrew[3] << setw(20) << this->aircrew[4] << "|" << endl;
    cout << setfill('-');
    cout << "+" << setw(90) << "+" << endl;
}

void Flight::printSeats() {
    
}

char* Flight::getId() {
    return this->id;
}

void Flight::mod() {
    
}