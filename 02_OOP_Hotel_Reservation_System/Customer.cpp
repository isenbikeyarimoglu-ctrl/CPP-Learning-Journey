#include <iostream>
#include "Customer.h"
#include "Room.h"
#include <cstring>


Customer::Customer(char newname[10], int DTS) {
	
	strcpy_s(name, 10, newname);
	daystostay = DTS;
	assignedroom = nullptr;
}
void Customer::checkin(Room& roomptr) {
	assignedroom = &roomptr;
	assignedroom->bookRoom();

}