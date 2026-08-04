#include <cstring>
#include <iostream>
#include "Hotel.h"
#include "Room.h"     
#include "Customer.h" 

double Hotel::totalRevenue = 0.0;


void Hotel::showAvailableRooms() {
    for (int i = 0; i < 10; i++) {

        if (rooms[i]->getIsOccupied() == false) {
            std::cout << rooms[i]->getRoomNumber() << std::endl;
        }
    }
}

void Hotel::processPayment(Customer& c) {
   
    totalRevenue += c.getDaysToStay() * c.getAssignedRoom()->getDailyRate();

    c.getAssignedRoom()->freeRoom();
}

Hotel::Hotel() {
    for (int i = 0; i < 10; i++) {
        rooms[i] = new Room(100 + i, i * 100 + 500.0);
        customers[i] = nullptr;
    }
}

bool Hotel::addCustomer(Customer* c) {
    for (int i = 0; i < 10; i++) {
        if (customers[i] == nullptr) {
            customers[i] = c;
            return true;
        }
    }
    return false;
}

Customer* Hotel::getCustomer(const char* name) {
    for (int i = 0; i < 10; i++) {
        if (customers[i] != nullptr && strcmp(customers[i]->getName(), name) == 0) {
            return customers[i];
        }
    }
    return nullptr;
}

void Hotel::removeCustomer(Customer* c) {
    for (int i = 0; i < 10; i++) {
        if (customers[i] == c) {
            delete customers[i];
            customers[i] = nullptr;
            break;
        }
    }
}

Room* Hotel::getRoom(int targetRoomNum) {
    for (int i = 0; i < 10; i++) {
        if (rooms[i] != nullptr && rooms[i]->getRoomNumber() == targetRoomNum) {
            return rooms[i];
        }
    }
    return nullptr;
}