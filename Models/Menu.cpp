#include "../Headers/Menu.h"

Menu::Menu() {
    this->readData();

    int option = 1;
    char id[6];

    do {
        cout << endl;
        cout << left;
        cout << setfill('-');
        cout << setw(1) << "+" << setw(50) << "-" << setw(1) << "+" << endl;
        cout << setfill(' ');
        cout << setw(1) << "|" << setw(50) << "      Airline Management and Search System      " << setw(1) << "|" << endl;
        cout << setw(1) << "|" << setw(50) << " 0. Show all flights" << setw(1) << "|" << endl;
        cout << setw(1) << "|" << setw(50) << " 1. Show specific flight" << setw(1) << "|" << endl;
        cout << setw(1) << "|" << setw(50) << " 2. Modify a flight" << setw(1) << "|" << endl;
        cout << setw(1) << "|" << setw(50) << " 3. See available seats of a flight" << setw(1) << "|" << endl;
        cout << setw(1) << "|" << setw(50) << " 4. Check-in a flight" << setw(1) << "|" << endl;
        cout << setw(1) << "|" << setw(50) << " 5. Save and refresh" << setw(1) << "|" << endl;
        cout << setw(1) << "|" << setw(50) << " 6. Exit" << setw(1) << "|" << endl;
        cout << setfill('-');
        cout << setw(1) << "+" << setw(50) << "-" << setw(1) << "+" << endl;
        cout << setfill(' ');
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
                cout << "> Enter id of the flight: " << flush;
                cin >> id;
                this->checkIn(id);
                break;
            case 5:
                // ==> Save Data
                cout << "> Saving Data..." << endl;
                this->saveData();
                cout << "> Cleaning..." << endl;
                this->cleanList();
                break;
            case 6:
                // ==> Exit
                cout << "> Saving Data..." << endl;
                this->saveData();
                cout << "===> Thanks for using the program <===";
                break;
            default:
                cerr << "> ERROR: that option is not allowed." << endl;
        }
    } while(option != 6);
}

Menu::~Menu() {
    for (int i = 0; i < this->num_flights; i++) {
        delete this->list[i];
    }
    delete [] this->list;
}

void Menu::readData() {
    ifstream fileRead("./Data/active_flights.txt");

    if (fileRead.fail()) {
        cerr << "> ERROR: the file was not found." << endl;
    } else {
        cout << "> Reading data..." << endl;
        fileRead >> this->num_flights;
        this->list = new Flight*[this->num_flights];

        tm dateTime;
        char line_str[150];
        char seats_str[100];
        char* tok = nullptr;
        char* info[19];
        bool** seats = nullptr;
        User** users = nullptr;

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

                dateTime.tm_mon = atoi(info[4]) - 1;
                dateTime.tm_mday = atoi(info[5]);
                dateTime.tm_year = atoi(info[6]) - 1900;
                dateTime.tm_sec = atoi(info[9]);
                dateTime.tm_min = atoi(info[8]);
                dateTime.tm_hour =  atoi(info[7]);
                
                seats = new bool*[atoi(info[17])];
                for (int j = 0; j < atoi(info[17]); j++) {
                    seats[j] = new bool[atoi(info[18])];
                    fileRead.getline(seats_str, 100);
                    tok = strtok(seats_str, " ");
                    for (int k = 0; k < atoi(info[18]); k++) {
                        if (tok != nullptr) {
                            seats[j][k] = this->atool(tok);
                            tok = strtok(nullptr, " ");
                        } else {
                            break;
                        }
                    }
                }

                users = new User*[atoi(info[17])*atoi(info[18])];
                fileRead.getline(seats_str, 100);
                tok = strtok(seats_str, " -");
                for (int j = 0; j < atoi(info[17])*atoi(info[18]); j++) {
                    if (tok != nullptr) {
                        char name[20];
                        char seat[3];
                        strcpy(name, tok);
                        tok = strtok(nullptr, " -");
                        strcpy(seat, tok);
                        users[j] = new User(name, seat);
                        tok = strtok(nullptr, " -");
                    } else {
                        users[j] = nullptr;
                    }
                }

                this->list[i] = new Flight(info[0], info[1], info[2], info[3], dateTime, info[10], info[11], info[12], info[13], info[14], atoi(info[15]), info[16], seats, atoi(info[17]), atoi(info[18]), users);
            }
        }
    }

    fileRead.close();
}

void Menu::saveData() {
    ofstream writeActiveFlights("./Data/active_flights.txt");
    ofstream writeInactiveFlights("./Data/inactive_flights.txt", ios::app);
    int num_active_flights = 0;
    
    for (int i = 0; i < this->num_flights; i++) {
        if (this->list[i]->isInactive()) {
            continue;
        } else {
            num_active_flights++;
        }
    }

    writeActiveFlights << num_active_flights << endl;
    Flight* selected = nullptr;
    for (int i = 0; i < this->num_flights; i++) {

        selected = this->list[i];
        char dateTime[50];
        selected->getDateTime(dateTime);
        char aircrew[100];
        selected->getAircrew(aircrew);

        if (selected->isInactive()) {

            writeInactiveFlights << selected->getId() << " "  << selected->getModel() << " "  << selected->getFrom() << " " << selected->getTo() << " " << dateTime << " "  << aircrew << " "  << selected->getHours() << endl;
        
        } else {

            PlaneSeats* planeseats = selected->getSeats();
            bool** seats = planeseats->getSeats();
            User** users = planeseats->getUsers();
            

            writeActiveFlights << selected->getId() << " " << selected->getModel() << " " << selected->getFrom() << " " << selected->getTo() << " " << dateTime << " " << aircrew << " " << selected->getHours() << " "  << selected->getState() << " "  << planeseats->getRows() << " " << planeseats->getCollumns()<< " " << endl;

            for (int j = 0; j < planeseats->getRows(); j++) {

                writeActiveFlights << seats[j][0];

                for (int k = 1; k < planeseats->getCollumns(); k++) {

                    writeActiveFlights << " " << seats[j][k];

                }

                writeActiveFlights << endl;
            }

            if (  planeseats->isEmpty() == false  ) {

                int i = 1;
                writeActiveFlights << users[0]->getName() << "-" << users[0]->getSeat();

                while (users[i] != nullptr) {

                    writeActiveFlights << " " << users[i]->getName() << "-" << users[i]->getSeat();
                    i++;

                }

                writeActiveFlights << endl;
            }
        }
    }

    writeActiveFlights.close();
    writeInactiveFlights.close();
}

void Menu::cleanList() {

    Flight** new_list;
    int num_active_flights = 0;

    for (int i = 0; i < this->num_flights; i++) {

        if (  this->list[i]->isInactive()  ) {

            num_active_flights++;

        }
    }

    new_list = new Flight*[num_active_flights];

    int j = 0;
    for (int i = 0; i < this->num_flights; i++) {

        if (  this->list[i]->isInactive() ) {

            delete this->list[i];
            this->list[i] = nullptr;

        } else {
            
            new_list[j] = this->list[i];
            j++;

        }
    }

    delete [] this->list;
    this->list = new_list;
    this->num_flights = num_active_flights;

}

void Menu::printAll() {
    cout << endl;
    cout << left;
    cout << setfill('-');
    cout << setw(1) << "+" << setw(121) << "-" << setw(1) << "+" << endl;
    cout << setfill(' ');
    cout << setw(1) << "| " << setw(10) << "ID" << setw(1) << "| " << setw(20) << "Model" << setw(1) << "| " << setw(20) << "From" << setw(1) << "| " << setw(20) << "To" << setw(1) << "| " << setw(20) << "Date/time" << setw(1) << "| " << setw(20) << "State" << setw(1) << "|" << endl;
    for (int i = 0; i < this->num_flights; i++) {
        this->list[i]->printLess();
    }
    cout << setfill('-');
    cout << setw(1) << "+" << setw(121) << "-" << setw(1) << "+" << endl;
}

int Menu::fnd(char* id) {
    if (this->list == nullptr) {
        return -1;
    } else {
        int index = -1;
        for (int i = 0; i < this->num_flights; i++) {
            char* selected_id = this->list[i]->getId();
            bool areEqual = true;
            for (int j = 0; j < 6; j++) {
                if (id[j] != selected_id[j]) {
                    areEqual = false;
                    break;
                }
            }
            
            if (areEqual) {
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
        cout << "> Flight cannot be located" << endl;
        return false;
    } else {
        this->list[index]->printFull();
        return true;
    }
}

bool Menu::mod(char* id) {
    int index = this->fnd(id);
    if (index == -1) {
        cout << "> Flight cannot be located" << endl;
        return false;
    } else {
        this->list[index]->mod();
        return true;
    }
}

bool Menu::checkSeats(char* id) {
    int index = this->fnd(id);
    if (index == -1) {
        cout << "> Flight cannot be located" << endl;
        return false;
    } else {
        PlaneSeats* seats = this->list[index]->getSeats();
        seats->printSeats();
        return true;
    }
}

bool Menu::checkIn(char* id) {
    int index = this->fnd(id);
    if (index == -1) {
        cout << "> Unable to check-in, flight cannot be located." << endl;
        return false;
    } else {
        char name[20];
        cout << "> Enter passanger name: " << flush;
        cin >> name;
        PlaneSeats* seats = this->list[index]->getSeats();
        seats->reserveSeats(name);
        return true;
    }
}

bool Menu::atool(char* str) {
    if (*str == '0') {
        return false;
    } else {
        return true;
    }
}