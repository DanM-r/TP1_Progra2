#include "../Headers/Menu.h"

Menu::Menu() {
    this->readData();

    int option;
    char id[6];

    cout << "===>> Flight Management and Search System <<===" << endl;
    cout << "0: Show active flights" << endl;
    cout << "1: Inspect an active flight"<< endl;
    cout << "2: Modify an active flight"<< endl;
    cout << "3: Inspect available seats in a flight"<< endl;
    cout << "4: Check-in a flight"<< endl;
    cout << "5: Save Data"<< endl;
    cout << "6: Exit System"<< endl;
    cout << "> Select an option: " << flush;
    cin >> option;

    switch (option) {
        case 0:
            // ==> Print all Flights
            printAll();
            break;
        case 1:
            // ==> Request info a flight
            cout << "> Enter id of the flight: " << flush;
            cin >> id;
            this->rqst(id);
            break;
        case 2:
            // ==> Modify a flight
            cout << "> Enter id of the flight: " << flush;
            cin >> id;
            this->mod(id);
            break;
        case 3:
            // ==> Verify Seats of a flight
            cout << "> Enter id of the flight: " << flush;
            cin >> id;
            this->checkSeats(id);
            break;
        case 4:
            // ==> Check in a person to a flight
            this->checkIn();
            break;
        case 5:
            // ==> Save Data
            break;
        case 6:
            // ==> Exit
            break;
        default:
            cerr << "> ERROR: that option is not allowed." << endl;
    }
}

Menu::~Menu() {
    this->saveData();
    for (int i = 0; i < this->num_flights; i++) {
        delete this->list[i];
    }
    delete [] this->list;
}

void Menu::readData() {
    ifstream fileRead("./Data/active_flights.txt");

    if (fileRead.fail()) {
        cerr << "> ERROR: " << endl;
    } else {
        cout << "> Reading data..." << endl;
        fileRead >> this->num_flights;
        this->list = new Flight*[this->num_flights];

        tm dateTime;
        char line_str[150];
        char seats_str[100];
        char* tok = nullptr;
        char* info[19];
        char* aircrew[5];
        bool** seats = nullptr;

        fileRead.ignore(150,'\n');
        for (int i = 0; i < this->num_flights; i++) {
            if (fileRead.eof()) {
                break;
            } else {
                fileRead.getline(line_str, 150);
                tok = strtok(line_str, " ");

                for (int j = 0; j < 19; j++) {
                    if (tok != nullptr) {
                        info[j] = tok;
                        tok = strtok(nullptr, " ");
                    } else {
                        break;
                    }
                }

                dateTime.tm_mday = atoi(info[4]);
                dateTime.tm_mon = atoi(info[5]);
                dateTime.tm_year = atoi(info[6]) - 1900;
                dateTime.tm_hour = atoi(info[7]);
                dateTime.tm_min = atoi(info[8]);
                dateTime.tm_sec = atoi(info[9]);
                
                for (int j = 0; j < 5; j++) {
                    aircrew[j] = info[j + 9];
                }
                
                seats = new bool*[atoi(info[17])];
                for (int j = 0; j < atoi(info[17]); j++) {
                    seats[j] = new bool[atoi(info[18])];
                    fileRead.ignore(100,'\n');
                    fileRead.getline(seats_str, 100);
                    tok = strtok(seats_str, " ");
                    for (int k = 0; k < atoi(info[18]); k++) {
                        if (tok != nullptr) {
                            seats[j][k] = tok;
                            tok = strtok(nullptr, " ");
                        } else {
                            break;
                        }
                    }
                }
                
                
                this->list[i] = new Flight(info[0], info[1], info[2], info[3], dateTime, aircrew, atoi(info[10]), info[11], seats);
                seats = nullptr;
            }
        }
    }

    fileRead.close();
}

void Menu::saveData() {
    ofstream writeActiveFlights("../Data/active_flights.txt");
    ofstream writeInactiveFlights("../Data/inactive_flights.txt");

    
}

void Menu::printAll() {
    cout << "ID     Model     From    To   Date / Time  State"  << endl;
    for (int i = 0; i < this->num_flights; i++) {
        this->list[i]->printLess();
    }
}

int Menu::fnd(char* id) {
    if (this->list == nullptr) {
        return -1;
    } else {
        int index = -1;
        for (int i = 0; i < this->num_flights; i++) {
            if (this->list[i]->getId() == id) {
                index = i;
                break;
            }
        }
        return index;
    }
}

bool Menu::rqst(char* id) {
    int index = this->fnd(id);
    if (index == -1) {
        return false;
    } else {
        this->list[index]->printFull();
        return true;
    }
}

bool Menu::mod(char* id) {
    int index = this->fnd(id);
    if (index == -1) {
        return false;
    } else {
        this->list[index]->mod();
        return true;
    }
}

bool Menu::checkSeats(char* id) {
    int index = this->fnd(id);
    if (index == -1) {
        return false;
    } else {
        this->list[index]->printSeats();
        return true;
    }
}

void Menu::checkIn() {

}

bool Menu::atool(char* str) {
    if (*str == '0') {
        return false;
    } else {
        return true;
    }
}