#pragma once
#include <iostream>

class Car {
public:
	const char* color;
	int fuel;
	int speed;
	void accelerate();
	void printstatus();
};