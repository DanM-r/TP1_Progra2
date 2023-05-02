#include "../Headers/PlaneSeats.h"

PlaneSeats::PlaneSeats(int rows, int colluns) {
    this->rows = rows;
    this->collumns = collumns;
    this->seats = new bool*[rows];
    this->users = new User*[rows*collumns];
    for (int i = 0; i < rows; i++) {
        this->seats[i] = new bool[collumns];
        users[i] = nullptr;
    }
}

PlaneSeats::PlaneSeats(int rows, int collumns, bool** seats, User** users) {
    this->rows = rows;
    this->collumns = collumns;
    this->seats = new bool*[rows];
    this->users = new User*[rows*collumns];
    for (int i = 0; i < this->rows*this->collumns; i++) {
        if (users[i] == nullptr) {
            this->users[i] = nullptr;
        } else {
            *(this->users[i]) = *(users[i]);
        }
    }
    for (int i = 0; i < this->rows; i++) {
        this->seats[i] = new bool[this->collumns];
        for (int j = 0; j < this->collumns; j++) {
            this->seats[i][j] = seats[i][j];
        }
    }
}

PlaneSeats::~PlaneSeats() {
    for (int i = 0; i < this->rows; i++) {
        delete seats[i];
        delete users[i];
    }
    delete [] seats;
    delete [] users;
}

void PlaneSeats::printSeats() {
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

void PlaneSeats::reserveSeats(char* name) {
    char seat[3];
    cout << "  " << char(65);
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
            for (int i = 0; i < this->rows*this->collumns; i++) {
                if (this->users[i] == nullptr) {
                    this->users[i] = new User(name, seat);
                    cout << "> Seat was reserved succesfully" << endl;
                    break;
                }
            }
        }
    } else {
        cerr << "> ERROR: the seat requested doesn't exists" << endl;
    }
}