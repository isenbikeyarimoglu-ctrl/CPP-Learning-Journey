#include <iostream>

#pragma once
class Room;
class Customer;

class Hotel {
private:
	Room* rooms[10];
	Customer* customers[10];
	static double totalRevenue;
public:
	Hotel();
	void showAvailableRooms();
	void processPayment(Customer& c);
	Room* getRoom(int targetRoomNum);
	bool addCustomer(Customer* c);
	Customer* getCustomer(const char* name);
	void removeCustomer(Customer* c);
public:
	static double getTotalRevenue() {
		return totalRevenue;
	}
};