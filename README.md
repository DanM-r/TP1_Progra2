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
```json
	"${workspaceFolder}/Headers/*.h",
	"${workspaceFolder}/Models/*.cpp",
	"${workspaceFolder}/*.cpp"
```
Replace `"${file}"` with the code above to indicate the linker it has to get the files from these three paths.

### Memory Management
Consists of two files:
- active\_flights.txt: stores flights with less than 24 hours since last modification.
- inactive\_flights.txt: stores flights with more than 24 hours since last modification.
> System initially loads data from active\_flights.txt. When there's a modification, the system will upload the changes to the active\_flights.txt. When the system updates, the system will store the flights that meets the criteria and delete from HEAP. **Format**:
```
1
                              MM DD YYYY HH MN SC
JH867 Boeing-737 Delhi London 1 27 2023 13 00 00 Daniel Javier Ana Melissa Christopher 8 Scheduled 4 10
1 0 0 0 0 1 0 0 0 1
1 1 0 1 0 1 0 0 1 1
0 0 0 1 0 0 1 1 1 0
1 1 0 1 0 1 0 0 1 1
```

### Class Flight
**Atributes**:
- id (char array): will consists of 5 digits from 0 to z, letters in lowercase. As it needs a termination symbol, the size of this array is 6.
- Model (char array)
- Aircrew: (char* array [pilot, copilot, attendant1, attendant2, attendant3]) remember it is a char array of pointers to char arrays in HEap.
- Date & Time (std::ctime)
- From City (char array) 
- To City (char array)
- Duration in hours (int)
- Seats (Class AirplaneSeats)
- State: consists on a char array of two characters plus termination symbol.
    - Scheduled: no passengers yet
    - On time: confirmed
    - Late: s.e.
    - Early: s.e.
    - Canceled: s.e.
    - Landed: s.e.
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
