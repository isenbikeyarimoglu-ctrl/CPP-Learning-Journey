#include <iostream>
#include "Hotel.h"
#include "Customer.h"
#include "Room.h"

int main() {
    Hotel myHotel;
    int choice = 0;

    std::cout << "--- HOTEL RESERVATION SYSTEM ---\n";

    while (choice != 5) {
        std::cout << "\n===========================\n";
        std::cout << "1- Show Available Rooms\n";
        std::cout << "2- Check-in Customer\n";
        std::cout << "3- Check-out Customer\n";
        std::cout << "4- View Total Revenue\n";
        std::cout << "5- Exit\n";
        std::cout << "===========================\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "\n--- AVAILABLE ROOMS ---\n";
            myHotel.showAvailableRooms();
        }
        else if (choice == 2) {
            std::cout << "\n--- CHECK-IN ---\n";
            char name[50];
            int days;
            int selectedRoomNum;

            std::cout << "Customer Name: ";
            std::cin >> name;
            std::cout << "Days to Stay: ";
            std::cin >> days;

            std::cout << "\nAvailable Rooms:\n";
            myHotel.showAvailableRooms();

            std::cout << "Select Room Number: ";
            std::cin >> selectedRoomNum;

            Room* foundRoom = myHotel.getRoom(selectedRoomNum);

            if (foundRoom != nullptr && foundRoom->getIsOccupied() == false) {
                Customer* newCustomer = new Customer(name, days);
                newCustomer->checkin(*foundRoom);
                myHotel.addCustomer(newCustomer);

                std::cout << "Customer " << name << " registered to room " << selectedRoomNum << ".\n";
            }
            else {
                std::cout << "Error: Room is invalid or already occupied!\n";
            }
        }
        else if (choice == 3) {
            std::cout << "\n--- CHECK-OUT ---\n";
            char searchName[10];
            std::cout << "Enter Customer Name to Check-out: ";
            std::cin >> searchName;

            Customer* c = myHotel.getCustomer(searchName);

            if (c != nullptr) {
                myHotel.processPayment(*c);
                myHotel.removeCustomer(c);
                std::cout << "Check-out successful. Revenue added and room freed.\n";
            }
            else {
                std::cout << "Error: Customer not found!\n";
            }
        }
        else if (choice == 4) {
            std::cout << "\n--- REVENUE STATUS ---\n";
          
            std::cout << "Calculating total revenue...\n";
            std::cout << Hotel::getTotalRevenue() << std::endl;
        }
        else if (choice == 5) {
            std::cout << "\nExiting system. Have a good day!\n";
        }
        else {
            std::cout << "\nInvalid choice! Please enter a number between 1 and 5.\n";
        }
    }

    return 0;
}