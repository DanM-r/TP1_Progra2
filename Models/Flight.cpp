#include "../Headers/Flight.h"

Flight::Flight(char* id, char* model, char* from, char* to, tm dateTime, char* pilot, char* copilot, char* attend1, char* attend2, char* attend3, int hours, char* state, bool** seats, int rows, int collumns, User** users) {
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
    this->hours = hours;
    this->seats = new PlaneSeats(rows, collumns, seats, users);
}

Flight::~Flight() {
    for (int i = 0; i < 5; i++) {
        delete aircrew[i];
    }
    delete seats;
}

void Flight::printLess() {
    char output[16];
    mktime(&dateTime);
    strftime(output, sizeof(this->dateTime), "%m/%d/%Y %H:%M", &this->dateTime);
    cout << setw(1) << "| " << setw(10) << this->id << setw(1) << "| " << setw(20) << this->model << setw(1) << "| " << setw(20) << this->from << setw(1) << "| " << setw(20) << this->to << setw(1) << "| " << setw(20) << output << setw(1) << "| " << setw(20) << this->state << setw(1) << "|" << endl;
}

void Flight::printFull() {
    char dateTime[16];
    mktime(&this->dateTime);
    strftime(dateTime, sizeof(this->dateTime), "%m/%d/%Y %H:%M", &this->dateTime);

    cout << setfill('-');
    cout << setw(1) << "+" << setw(35) << "-" << setw(1) << "+" << endl;
    cout << setfill(' ');
    cout << setw(2) << "| " << setw(15) << "ID: " << setw(19) << this->id << setw(2) << "| " << endl;
    cout << setw(2) << "| " << setw(15) << "Model: " << setw(19) << this->model << setw(2) << "| " << endl;
    cout << setw(2) << "| " << setw(15) << "State: " << setw(19) << this->state << setw(2) << "| " << endl;
    cout << setw(2) << "| " << setw(15) << "From: " << setw(19) << this->from << setw(2) << "| " << endl;
    cout << setw(2) << "| " << setw(15) << "To: " << setw(19) << this->to << setw(2) << "| " << endl;
    cout << setw(2) << "| " << setw(15) << "At: " << setw(19) << dateTime << setw(2) << "| " << endl;
    cout << setw(2) << "| " << setw(15) << "Hours on air: " << setw(19) << this->hours << setw(2) << "| " << endl;
    cout << setw(2) << "| " << setw(15) << "Pilot: " << setw(19) << this->aircrew[0] << setw(2) << "| " << endl;
    cout << setw(2) << "| " << setw(15) << "Copilot: " << setw(19) << this->aircrew[1] << setw(2) << "| " << endl;
    cout << setw(2) << "| " << setw(15) << "Attendants: " << setw(19) << " " << setw(2) << "| " << endl;
    cout << setw(2) << "| " << setw(3) << " - " << setw(31) << this->aircrew[2] << setw(2) << "| " << endl;
    cout << setw(2) << "| " << setw(3) << " - " << setw(31) << this->aircrew[3] << setw(2) << "| " << endl;
    cout << setw(2) << "| " << setw(3) << " - " << setw(31) << this->aircrew[4] << setw(2) << "| " << endl;
    cout << setfill('-');
    cout << setw(1) << "+" << setw(35) << "-" << setw(1) << "+" << endl;
}

bool Flight::isInactive() {
    time_t current_time = time(nullptr);
    time_t flight_time = mktime(&this->dateTime);
    if (  current_time  >  flight_time  and  difftime(current_time, flight_time)  >  86400  ) {

        return true;

    } else {

        return false;

    }
}


char* Flight::getId() {
    return this->id;
}

char* Flight::getModel() {
    return this->model;
}

char* Flight::getFrom() {
    return this->from;
}

char* Flight::getTo() {
    return this->to;
}

void Flight::getDateTime(char* dateTime) {
    mktime(&this->dateTime);
    strftime(dateTime, sizeof(this->dateTime), "%m %d %Y %H %M %S", &this->dateTime);
}

void Flight::getAircrew(char* aircrew) {
    strcpy(aircrew, this->aircrew[0]);
    strcat(aircrew, " ");
    strcat(aircrew, this->aircrew[1]);
    strcat(aircrew, " ");
    strcat(aircrew, this->aircrew[2]);
    strcat(aircrew, " ");
    strcat(aircrew, this->aircrew[3]);
    strcat(aircrew, " ");
    strcat(aircrew, this->aircrew[4]);
}

int Flight::getHours() {
    return this->hours;
}

char* Flight::getState() {
    return this->state;
}

void Flight::mod() {

    char new_data[50];
    int option;

    cout << setfill('-');
    cout << setw(1) << "+" << setw(50) << "-" << setw(1) << "+" << endl;
    cout << setfill(' ');
    cout << setw(1) << "| " << setw(25) << "                Modifing" << setw(24) << this->id << setw(1) << "|" << endl;
    cout << setw(1) << "| " << setw(49) << "1. State" << setw(1) << "|" << endl;
    cout << setw(1) << "| " << setw(49) << "2. Time" << setw(1) << "|" << endl;
    cout << setw(1) << "| " << setw(49) << "3. Pilot" << setw(1) << "|" << endl;
    cout << setw(1) << "| " << setw(49) << "4. Copilot" << setw(1) << "|" << endl;
    cout << setw(1) << "| " << setw(15) << "5. Attendant " << setw(34) << this->aircrew[2] << setw(1) << "|" << endl;
    cout << setw(1) << "| " << setw(15) << "6. Attendant " << setw(34) << this->aircrew[3] << setw(1) << "|" << endl;
    cout << setw(1) << "| " << setw(15) << "7. Attendant " << setw(34) << this->aircrew[4] << setw(1) << "|" << endl;
    cout << setfill('-');
    cout << setw(1) << "+" << setw(50) << "-" << setw(1) << "+" << endl;
    cout << "> Select an option: " << flush;
    cin >> option;
    switch (option) {
        case 1:
            cout << "> Current state is: " << this->state << ". Enter the new state of the flight: " << flush;
            cin >> new_data;
            this->setState(new_data);
            break;;
        case 2:
            char current_dateTime[16];
            mktime(&this->dateTime);
            strftime(current_dateTime, sizeof(this->dateTime), "%m/%d/%Y %H:%M", &this->dateTime);
            cout << "> Current date/time is: " << current_dateTime << ". Enter the new time (use format HH:MM): " << flush;
            cin >> new_data;
            this->setDateTime(new_data);
            break;
        case 3:
            strcpy(aircrew[0], new_data);
            break;
        case 4:
            strcpy(aircrew[1], new_data);
            break;
        case 5:
            strcpy(aircrew[2], new_data);
            break;
        case 6:
            strcpy(aircrew[3], new_data);
            break;
        case 7:
            strcpy(aircrew[4], new_data);
            break;
        default:
            cerr << "> ERROR: that option is not allowed." << endl;
            break;
    }
}

void Flight::setDateTime(char* newDateTime) {

    tm new_dateTime;
    int dateTime[2];
    char* tok = nullptr;
    tok = strtok(newDateTime, ":");

    for (int i = 0; i < 2; i++) {

        if (tok != nullptr) {

            dateTime[i] = atoi(tok);
            tok = strtok(nullptr, ":");
        }
    }

    new_dateTime.tm_hour = dateTime[0];
    new_dateTime.tm_min = dateTime[1];

    if (  (this->dateTime.tm_hour*60 + this->dateTime.tm_min)  >  (new_dateTime.tm_hour*60 + new_dateTime.tm_min)  ) {

        cerr << "> ERROR: cannot assign a time earlier than the set original value" << endl;

    } else if (  (strcmp(this->state, "Landed\0\0\0") == 0)  ||  (strcmp(this->state, "Canceled\0") == 0)  ) {

        cerr << "> ERROR: cannot assign a time when the flight state is Canceled or Landed" << endl;

    } else {

        this->dateTime.tm_hour = new_dateTime.tm_hour;
        this->dateTime.tm_min = new_dateTime.tm_min;
        cout << "> Date/Time changed succesfully" << endl;
    }
}

void Flight::setAircrew(char* newAircrew, int opt) {
    int num_attendant;
    switch(opt) {

        default:
            cerr << "ERROR: that option is not allowed" << endl;
    }
}

void Flight::setState(char* new_state) {

    if (  strcmp(this->state, "Landed\0\0\0") == 0  ) {

        cerr << "> ERROR: a landed flight cannot be set up to any other state" << endl;

    } else if (  strcmp(this->state, "Canceled\0") == 0  ) {

        cerr << "> ERROR: a canceled flight cannot be set up to any other state" << endl;

    } else if (  strcmp(this->state, "Onair\0\0\0\0") == 0 && !(strcmp(new_state, "Landed") == 0) ) {

        cerr << "> ERROR: a flight on air cannot be set up to any other state that's not landed" << endl;
    
    } else if (  (strcmp(new_state, "Late\0\0\0\0") == 0) && (strcmp(this->state, "Early\0\0\0\0") == 0) || (strcmp(this->state, "Early\0\0\0\0") == 0) && (strcmp(this->state, "Late\0\0\0\0") == 0)  ) {

        cerr << "> ERROR: a late/early flight cannot be set up to their opposite" << endl;
    
    } else {

        if (  (strcmp(new_state, "Scheduled") == 0) || (strcmp(new_state, "Ontime\0\0\0") == 0) || (strcmp(new_state, "Early\0\0\0\0") == 0) || (strcmp(new_state, "Late\0\0\0\0\0") == 0) || (strcmp(new_state, "Canceled\0") == 0) || (strcmp(new_state, "Landed\0\0\0") == 0) || (strcmp(new_state, "Onair\0\0\0\0") == 0)  ) {

            strcpy(this->state, new_state);
            cout << "> State changed succesfully" << endl;

        } else {

            cerr << "> ERROR: invalid state" << endl;

        }
    }
}

PlaneSeats* Flight::getSeats() {
    return this->seats;
}