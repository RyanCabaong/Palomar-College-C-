#pragma once

#ifndef CAR_H

#include <iostream>
#include <string>
#include <utility>
#include "Vehicle.h"
#include "Place.h"
using namespace std;

#define CAR_H

class Car : public Vehicle
{
private:
	pair<int, int> loc;
	string color;
	Place* placeptr[2];
public:
	Car();
	Car(pair<int, int> loca, float w, float sp, char d);
	string getcolor() const;
	void setcolor(string c);
	void setplace(Place*, Place*);
	Place** getplace();
	void move();

};

#endif
