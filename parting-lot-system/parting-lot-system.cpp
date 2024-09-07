#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <map>

using namespace std;

class ParkingLot {
    public:
        string parkingLotName;
        Address location;

        vector<ParkingFloor> parkingFloors;
        vector<EntranceGate> entrances;
        vector<ExitGate> exits;

        bool isParkingSpaceAvailableForVehicle(Vehicle vehicle) {};
        bool updateParkingAttendant(ParkingAttendant parkingAttendant, int gateId) {};
};

class ParkingFloor {
    public:
        int levelId;
        bool isFull;

        vector<ParkingSpace> parkingSpace;

        ParkingDisplayBoard parkingDisplayBoard;
};


class Gate {
    public:
        int gateId;
        ParkingAttendant parkingAttendant;
};

class EntranceGate : public Gate {
    public:
        ParkingTicket getParkingTicket(Vehicle vehicle) {};
};

class ExitGate : public Gate {
    public:
        ParkingTicket payForParking(ParkingTicket parkingTicket, PaymentType paymentType) {};
};

class Address {
    public:
        string country;
        string state;
        string city;
        string street;
        string pinCode;
};

class ParkingSpace {
    public:
        int spaceId;
        bool isFree;
        double costPerHour;
        Vehicle vehicle;
        ParkingSpaceType parkingSpaceType;
};

class ParkingDisplayBoard {
    public:
        map<ParkingSpace, int> freeSpotsAvailable;

        void updateFreeSpotsAvailable(ParkingSpaceType parkingSpaceType, int spaces) {};
};


class Account {
    public:
        string name;
        string email;
        string password;
        string empId;
        Address address;
};

class Admin : public Account {
    public:
        bool addParkingFloor(ParkingLot parkingLot, ParkingFloor parkingFloor) {};
        bool addParkingSpace(ParkingFloor parkingFloor, ParkingSpace parkingSpace) {};
        bool addParkingDisplayBoard(ParkingFloor parkingFloor, ParkingDisplayBoard parkingDisplayBoard) {};
};

class ParkingAttendant : public Account {
    public:
        Payment paymentService;

        bool processVehicleEntry(Vehicle vehicle) {};
        PaymentInfo processPayment(ParkingTicket parkingTicket, PaymentType paymentType) {};
};

class Vehicle {
    public:
        string licenseNumber;
        VehicleType vehicleType;
        ParkingTicket parkingTicket;
        PaymentInfo paymentInfo;
};

class ParkingTicket {
    public:
        int ticketId;
        int levelId;
        int spaceId;
        tm vehicleEntryDate;
        tm vehicleExitDate;
        ParkingSpaceType parkingSpaceType;
        double totalCost;
        ParkingTicketStatus parkingTicketStatus;

        void updateTotalCost() {};
        void updateVehicleExitTime(tm vehicleExitDate) {};
};

enum PaymentType
{
    CASH,
    CREDIT_CARD,
    DEBIT_CARD,
    UPI
};

enum ParkingSpaceType
{
    BIKE_PARKING,
    CAR_PARKING,
    TRUCK_PARKING
};


class Payment {
    public:
        PaymentInfo makePayment(ParkingTicket parkingTicket, PaymentType paymentType) {};
};

class PaymentInfo {
    public:
        double amount;
        tm paymentDate;
        int transactionId;
        ParkingTicket parkingTicket;
        PaymentStatus paymentStatus;
};

enum VehicleType
{
    BIKE,
    CAR,
    TRUCK
};

enum ParkingTicketStatus
{
   PAID, ACTIVE
};

enum PaymentStatus
{
    UNPAID,
    PENDING,
    COMPLETED,
    DECLINED,
    CANCELLED,
    REFUNDED
};

int
main()
{
    return 0;
}