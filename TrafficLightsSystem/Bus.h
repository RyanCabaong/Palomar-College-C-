#pragma once

#ifndef BUS_H

#include <iostream>
#include <string>
#include "Place.h"
#include "Constants.h"
#include "Vehicle.h"

using namespace std;

#define BUS_H

class Bus : public Vehicle
{
private:
	string name;
	int npassengers;
	Place* placeptr[4];

public:
	Bus();
	Bus(pair<int, int> loc, float w, float sp, char d, string na,
		int n);

	string getname() const;
	void setname(string na);
	int getnpassengers() const;
	void setnpassenger(int n);
	void setplace(Place*, Place*, Place*, Place*);
	Place** getplace();
	void move();

};

#endif
