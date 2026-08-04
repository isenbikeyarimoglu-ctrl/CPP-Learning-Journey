#include <iostream>

#pragma once

class Room;

class Customer {
private:
	char name[10];
	int daystostay;
	Room* assignedroom;
public:
	Customer(char newname[10], int DTS);
	void checkin(Room& roomptr);
	const char* getName() {
		return name;
	}

	int getDaysToStay() {
		return daystostay;
	}

	Room* getAssignedRoom() {
		return assignedroom;
	}
};