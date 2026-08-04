#include <iostream>
#include "Room.h"

Room::Room(int rNumber, double rRate) {
	IsOccupied = false;
	roomNumber = rNumber;
	dailyRate = rRate;

}

bool Room::bookRoom() {
	if (IsOccupied == false) {
		IsOccupied = true;
		return true;
	}
	else {
		return false;
	}
}
void Room::freeRoom() {
	IsOccupied = false;
}
