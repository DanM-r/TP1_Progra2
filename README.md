# Flight Management System and Search Engine
A system designed to manage the flights of an airline and provide customers and employees a reliable tool for searching the right flight they're looking for. The System is online from 5:00 to 22:59.

## What it can do?
1. Print all flights
2. Request a flight
3. Modify a flight
4. Verify seats of a flight
5. Check-in a person to a flight
6. Memory Management.

## Important Note: How to compile the project?

### Memory Management
Consists of two files:
- active\_flights.txt: stores flights with less than 24 hours since last modification.
- inactive\_flights.txt: stores flights with more than 24 hours since last modification.
> System initially loads data from active\_flights.txt. When there's a modification, the system will upload the changes to the active\_flights.txt. When the system updates, the system will store the flights that meets the criteria and delete from HEAP. **Format**:

### Class Flight
**Atributes**:
- id (char array): will consists of 5 digits from 0 to z, letters in lowercase. As it needs a termination symbol, the size of this array is 6.
- Model (char array)
- Aircrew: (char* array [pilot, copilot, attendant1, attendant2, attendant3]) remember it is a char array of pointers to char arrays in HEap.
- Date & Time (std::ctime)
- From City (char array) 
- To City (char array)
- Duration (int)
- Seats (Class AirplaneSeats)
- State: consists on a char array of two characters plus termination symbol.
    - (SC) Scheduled: no passengers yet
    - (OT) On time: confirmed
    - (LT) Late: s.e.
    - (ER) Early: s.e.
    - (CL) Canceled: s.e.
    - (LN) Landed: s.e.
**Methods**
- printLess()
- printFull()
- setters & getters
- showSeats

### Class AirplaneSeats
**Atributes**
- seats (bool\*) Changes based upon the plane technical specifications when creating a new flight
**Methods**
- assign(int)
- print()
- capacity()
- doFitsMinRequirements()
- doFitsInPlane(int)

### Class Menu
**Atributes**
- Collection

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
