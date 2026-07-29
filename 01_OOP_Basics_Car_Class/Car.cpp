#include <iostream>
#include "Car.h"

void Car::accelerate() {
	fuel -= 10;
	speed += 20;
}
void Car::printstatus() {
	std::cout << color << "Arabanin hizi: " << speed << ", Kalan yakit: " << fuel << std::endl;
}