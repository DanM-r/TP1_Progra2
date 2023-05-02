#include "..\Headers\Flight.h"

Flight::Flight(char* id, char* model, char* from, char* to, tm dateTime, char* pilot, char* copilot, char* attend1, char* attend2, char* attend3, int duration, char* state, bool** seats, int rows, int collumns) {
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
    this->duration = duration;
    this->rows = rows;
    this->collumns = collumns;
    this->seats = new bool*[rows];
    for (int i = 0; i < rows; i++) {
        this->seats[i] = new bool[collumns];
        for (int j = 0; j < collumns; j++) {
            this->seats[i][j] = seats[i][j];
        }
    }
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
    cout << "|" << setw(10) << "Time: " << setw(20) << this->duration << setw(10) << "Pilot: " << setw(20) << this->aircrew[0] << setw(10) << "Copilot: " << setw(20) << this->aircrew[1] << "|" << endl;
    cout << "|" << setw(20) << "Flight Attendants: " << setw(20) << this->aircrew[2] << setw(20) << this->aircrew[3] << setw(20) << this->aircrew[4] << "|" << endl;
    cout << setfill('-');
    cout << "+" << setw(90) << "+" << endl;
}

void Flight::printSeats() {
    cout << "> Available seats are represented by an underscore, occupied seats are represented by an X" << endl;
    cout << setfill('-');
    cout << "+" << setw(this->collumns*2+2) << "+" << endl;
    cout << setfill(' ');
    for (int i = 0; i < this->rows; i++) {
        cout << "|";
        for (int j = 0; j < this->collumns; j++) {
            if (this->seats[i][j] == true) {
                cout << "X ";
            } else {
                cout << "_ ";
            }
        }
        cout << "|" << endl;
    }
    cout << setfill('-');
    cout << "+" << setw(this->collumns*2+2) << "+" << endl;
    cout << "> Check-In to reserve your seat on this flight!" << endl;
}

void Flight::reserveSeats() {
    char seat[3];
    cout << char(65);
    for (int i = 1; i < this->collumns; i++) {
        cout << " " << char(65 + i);
    }
    cout << endl;

    for (int i = 0; i < this->rows; i++) {
        cout << i << " " << this->seats[i][0];
        for (int j = 1; j < this->collumns; j++) {
            cout << " " << this->seats[i][j];
        }
        cout << endl;
    }

    cout << "> The seats are ordered by a letter and a number, to choose a seat you want to reserve enter the number and letter (example: 2d): " << flush;
    cin >> seat;
    if (atoi(&seat[0]) < this->rows and (char(seat[1]) - 65) < this->collumns) {
        if (this->seats[atoi(&seat[0])][char(seat[1]) - 65] == true) {
            cerr << "> ERROR: the seat requested is already occupied" << endl;
        } else {
            this->seats[atoi(&seat[0])][char(seat[1]) - 65] = true;
            cout << "> Seat was reserved succesfully" << endl;
        }
    } else {
        cerr << "> ERROR: the seat requested doesn't exists" << endl;
    }
}

bool Flight::isInactive() {
    time_t current_time = time(nullptr);
    time_t flight_time = mktime(&this->dateTime);

    if (difftime(current_time, flight_time) <= 86400) {
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

char* Flight::getDateTime() {
    char output[100];
    mktime(&dateTime);
    strftime(output, sizeof(dateTime), "%m %d %Y %H %M %S", &dateTime);
    return output;
}

char* Flight::getAircrew() {
    char aircrew[100];
    strcat(aircrew, this->aircrew[0]);
    strcat(aircrew, " ");
    strcat(aircrew, this->aircrew[1]);
    strcat(aircrew, " ");
    strcat(aircrew, this->aircrew[2]);
    strcat(aircrew, " ");
    strcat(aircrew, this->aircrew[3]);
    strcat(aircrew, " ");
    strcat(aircrew, this->aircrew[4]);
    return aircrew;
}

int Flight::getDuration() {
    return this->duration;
}

char* Flight::getState() {
    return this->state;
}

int Flight::getRows() {
    return this->rows;
}

int Flight::getCollumns() {
    return this->collumns;
}

bool** Flight::getSeats() {
    return this->seats;
}

void Flight::mod() {
    char new_data[50];
    int option;
    cout << "> What do you want to modify?" << endl;
    cout << "1. State" << endl;
    cout << "2. Model" << endl;
    cout << "3. Date/Time" << endl;
    cout << "4. Aircrew" << endl;
    cin >> option;
    switch (option) {
        case 1:
            cout << "> Enter the new state of the flight: " << flush;
            cin >> new_data;
            strcpy(this->state, new_data);
            break;
        case 2:
            cout << "> Enter the new model of the plane of the flight: " << flush;
            cin >> new_data;
            strcpy(this->model, new_data);
            break;
        case 3:
            cout << "> Enter the new date/time (use format MM/DD/YYYY HH:MM:SS): " << flush;
            cin >> new_data;
            this->setDateTime(new_data);
            break;
        case 4:
            int opt;
            cout << "1. Pilot" << endl;
            cout << "2. Copilot" << endl;
            cout << "3. Attendants" << endl;
            cout << "> Enter which option you want to modify: " << flush;
            cin >> opt;
            cout << "> Enter the name of the new aircrew member: " << flush;
            cin >> new_data;
            this->setAircrew(new_data, opt);
            break;
        default:
            cerr << "> ERROR: that option is not allowed." << endl;
            break;
    }
}

void Flight::setDateTime(char* newDateTime) {
    int dateTime[6];
    char* tok = nullptr;
    tok = strtok(newDateTime, " /:");
    for (int i = 0; i < 6; i++) {
        if (tok != nullptr) {
            dateTime[i] = atoi(tok);
            tok = strtok(nullptr, " /:");
        }
    }
    this->dateTime.tm_mon = dateTime[0];
    this->dateTime.tm_mday = dateTime[1];
    this->dateTime.tm_year = dateTime[3] - 1900;
    this->dateTime.tm_sec = dateTime[5] + dateTime[4]*60 + dateTime[3]*3600;
}

void Flight::setAircrew(char* newAircrew, int opt) {
    int num_attendant;
    switch(opt) {
        case 0:
            this->aircrew[0] = newAircrew;
            break;
        case 1:
            this->aircrew[1] = newAircrew;
            break;
        case 2:
            cout << "1. " << this->aircrew[2] << endl;
            cout << "2. " << this->aircrew[3] << endl;
            cout << "3. " << this->aircrew[4] << endl;
            cout << "> Which flight attendant needs to be replaced, select an option: " << endl;
            cin >> num_attendant;
            if (num_attendant < 4) {
                this->aircrew[num_attendant - 1] = newAircrew;
            } else {
                cout << "> ERROR: that option is not allowed" << endl;
            }
            break;
    }
}