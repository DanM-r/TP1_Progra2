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
            this->users[i] = new User(users[i]->getName(), users[i]->getSeat());
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
    cout << setfill('-');
    cout << setw(1) << "+" << setw(this->collumns*2+1) << "-" << setw(1) << "+" << endl;
    cout << setfill(' ');
    for (int i = 0; i < this->rows; i++) {
        cout << "| ";
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
    cout << setw(1) << "+" << setw(this->collumns*2+1) << "-" << setw(1) << "+" << endl;
    cout << "> An available seat is represented by an underscore, an occupied seat is an X" << endl;
}

void PlaneSeats::reserveSeats(char* name) {

    char seat[3];
    cout << setfill('-');
    cout << setw(5) << "+---+" << setw(this->collumns*2+1) << "-" << setw(1) << "+" << endl;
    cout << setfill(' ');
    cout << setw(2) << "|   |" << setw(2) << " A";

    for (int i = 1; i < this->collumns; i++) {

        cout << setw(1) << " " << setw(1) << char(65 + i);

    }
    cout << setw(2) << " |" << endl;
    cout << setfill('-');
    cout << setw(5) << "+---+" << setw(this->collumns*2+1) << "-" << setw(1) << "+" << endl;
    cout << setfill(' ');

    for (int i = 0; i < this->rows; i++) {

        cout << setw(2) << "| " << setw(2) << i + 1 << setw(1) << "|";

        if (  this->seats[i][0] == true  ) {

            cout << " X";

        } else {

            cout << " _";

        }

        for (int j = 1; j < this->collumns; j++) {
            
            if (  this->seats[i][j] == true  ) {

                cout << " X";

            } else {
                
                cout << " _";

            }
        }
        cout << setw(2) << " |" << endl;
    }
    cout << setfill('-');
    cout << setw(5) << "+---+" << setw(this->collumns*2+1) << "-" << setw(1) << "+" << endl;
    cout << "> Enter the seat to reserve (use format 1A): " << flush;
    cin >> seat;

    if (  (atoi(&seat[0]) - 1  )  <=  this->rows  and  (  char(seat[1]) - 65  )  <=  this->collumns) {

        cout << atoi(&seat[0]) << endl;
        cout << int(seat[1]) - 65 << endl;
        cout << this->seats[atoi(&seat[0])][int(seat[1]) - 65] << endl;

        if (  this->seats[atoi(&seat[0])][int(seat[1])  -  65]  ==  true  ) {

            cerr << "> ERROR: the seat requested is already occupied" << endl;

        } else {

            this->seats[atoi(&seat[0]) - 1][char(seat[1]) - 65] = true;

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

int PlaneSeats::getRows() {
    return this->rows;
}

int PlaneSeats::getCollumns() {
    return this->collumns;
}

bool** PlaneSeats::getSeats() {
    return this->seats;
}

User** PlaneSeats::getUsers() {
    return this->users;
}

bool PlaneSeats::isEmpty() {
    bool isEmpty = true;

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->collumns; j++) {
            if (this->seats[i][j] == true) {
                isEmpty = false;
                break;
            }
        }
    }

    return isEmpty;
}