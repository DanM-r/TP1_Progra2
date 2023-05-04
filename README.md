
# Airline  Management and Search System

A system designed to manage the flights of an airline and provide customers and employees a reliable tool for searching the right flight they're looking for. The System is online from 5:00 to 22:59.

## What it can do?

1. Print all flights
2. Request a flight
3. Modify a flight
4. Verify seats of a flight
5. Check-in a person to a flight
6. Memory Management.

## Important Note: How to compile the project?

To compile this project on VSCode is required to have installed any C++ compiler and follow the instructions specified on [the VSCode documentation on how to configure a task](https://code.visualstudio.com/docs/cpp/config-msvc). After creating the file `tasks.json`, is required to do a slight change on the args section.
```json
	"${workspaceFolder}/Headers/*.h",
	"${workspaceFolder}/Models/*.cpp",
	"${workspaceFolder}/*.cpp"
```
Replace `"${file}"` with the code above to indicate the linker it has to get the files from these three paths. If done right this project should compile.

## The library iomanip

The use of this library was allowed by the instructor as a way to format the outputs into a more eye pleasing look.

### Memory Management

Consists of two files:
- `active\_flights.txt`: stores flights with less than 24 hours since last modification.
- `inactive\_flights.txt`: stores flights with more than 24 hours since last modification.
> System initially loads data from active\_flights.txt. When there's a modification, the system will upload the changes to the active\_flights.txt. When the system updates, the system will store the flights that meets the criteria and delete from HEAP. **Format**:
```
1
JH867 Boeing-737 Delhi London 1 27 2023 13 00 00 Daniel Javier Ana Melissa Christopher 8 Scheduled 4 10
1 0 0 0 0 1 0 0 0 1
1 1 0 1 0 1 0 0 1 1
0 0 0 1 0 0 1 1 1 0
1 1 0 1 0 1 0 0 1 1
John-1A Steve-1F Steve-1J Steve-2A Daniel-2J Sebastian-3C Kevin-4C Aden-4J
```

### Class Flight

**Atributes**:
- id (char array): will consists of 5 digits from 0 to z, letters in lowercase.
- Model (char array): model of the airplane.
- Aircrew: (char* array [pilot, copilot, attendant1, attendant2, attendant3]) remember it is a char array of pointers to char arrays in Heap.
- Date & Time (std::tm)
- From City (char array) 
- To City (char array)
- Duration in hours (int)
- Seats (Class AirplaneSeats)
- State: consists on a char array of two characters plus termination symbol.
    - Scheduled: no passengers yet
    - Ontime: confirmed
    - Late: s.e.
    - Early: s.e.
    - Canceled: s.e.
    - Landed: s.e.
    - Onair: the flight is on the air.
**Methods**
- printLess()
- printFull()
- setters & getters
- showSeats

### Class AirplaneSeats

**Atributes**
- seats (bool matrix) Changes based upon the plane technical specifications when creating a new flight
- users (array of char pointers)
- rows (int)
- collumns (int)
**Methods**
- printSeats();
- reserveSeats(char* name);
- getters & setters;
- isEmpty();

### Class User

**Atributes**
- name (char array)
- seat (char array)
**Methods**
- Getters and setters

### Class Menu

**Atributes**
- List **Flight
- int num_flights

**Methods**
- Print all flights from collection
- Request information about a flight
- Modify a flight
- Verify seats of a flight
- Check-In a flight
- StoreData
- ReadData

### Other Possible Classes

- Airline
- User
- State
