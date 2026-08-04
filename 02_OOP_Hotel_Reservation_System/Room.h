#include <iostream>

class Room {
private:
    int roomNumber;
    bool IsOccupied;
    double dailyRate;

public:
    Room(int rNumber, double rRate); 

    int getRoomNumber() {
        return roomNumber; 
    }

    bool getIsOccupied() {
        return IsOccupied; 
    }

    double getDailyRate() {
        return dailyRate;
    }

    bool bookRoom();
    void freeRoom();
};