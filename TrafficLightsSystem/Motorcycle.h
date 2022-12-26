#pragma once

#ifndef MOTORCYCLE_H

#include <iostream>
#include "Place.h"
#include "Vehicle.h"

using namespace std;

#define MOTORCYCLE_H

class Motorcycle : public Vehicle
{
private:
	string brand_name;
	Place* placeptr[0];

public:
	Motorcycle();
	Motorcycle(pair<int, int> loc, float w, float sp, char d,
		string bn);
	
	string getbrandname() const;
	void setbrandname(string bn);
	void setplace(Place* p);
	Place** getplace();

	void move();
};

#endif
