# Flight Management System and Search Engine
A system designed to manage the flights of an airline and provide customers and employees a reliable tool for searching the right flight they're looking for. The System is online from 5:00 to 22:59.

## What it can do?
1. Print all flights
2. Request a flight
3. Modify a flight
4. Verify seats of a flight
5. Check-in a person to a flight
6. Memory Management.

### Memory Management
Consists of two files:
- active_flights.txt: stores flights with less than 24 hours since last modification.
- inactive_flights.txt: stores flights with more than 24 hours since last modification.
> System initially loads data from active_flights.txt. When there's a modification, the system will upload the changes to the active_flights.txt. When the system updates, the system will store the flights that meets the criteria and delete from HEAP. **Format**:

### Class Collection & Node
Binary Tree for storing the flights in HEAP based on how close are to departure. Node is a private nested class to Collection.

### Class Flight
Atributes:
- Model (Airline?)
- Tripulation (For what?)
- Date & Time
- From City
- To City
- Duration
- Seats (Ocupado, Disponible)
- Estado (Programado, Retrasado, Cancelado, Partió, Aterrizó)

### Class AirplaneSeats
### Class CheckIn
### Class Main (Menu)
### Other Possible Classes
- Tripulation
- Airline
- User
