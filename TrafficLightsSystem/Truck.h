#pragma once

#ifndef TRUCK_H

#include <iostream>
#include "Vehicle.h"
#include "Place.h"
#include "Constants.h"

using namespace std;

#define TRUCK_H

class Truck : public Vehicle
{
private:
	string color;
	float weight_trailer;
	pair<int, int> destination;
	Place* placeptr[5];

public:
	Truck();
	Truck(pair<int, int> loc, float w, float sp, char d, float wt,
		pair<int, int> destination);

	string getcolor() const;
	void setcolor();
	float getweight() const;  // override the getweight in Vehicle
	void setweight(float w_e, float w_t);
	pair<int, int> getdestination() const;
	void setdestination(pair<int, int> dest);
	void setplace(Place*, Place*, Place*, Place*, Place*);
	Place** getplace();
	void move();
};

#endif
