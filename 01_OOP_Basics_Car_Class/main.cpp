#include <iostream>
#include "Car.h"

void refuel(Car& target_car) {
	target_car.fuel = 100;
}
int main(){
	Car mycar;
	mycar.speed = 0;
	mycar.color = "Mavi";
	mycar.fuel = 50;

	mycar.accelerate();
	mycar.printstatus();
	refuel(mycar);
	mycar.printstatus();
	std::cin.get();

}