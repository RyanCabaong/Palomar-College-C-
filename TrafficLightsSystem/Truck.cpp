
#include <iostream>
#include "Truck.h"
#include "Place.h"
#include "Constants.h"
#include "Vehicle.h"

using namespace std;

Truck::Truck()
{
	int n = rand() % 12;

	color = COLORS[n];
	weight_trailer = 0;
	destination.first = 0;
	destination.second = 0;

	for (int i = 0; i < 5; i++)
		placeptr[i] = NULL;
}

Truck::Truck(pair<int, int> loc, float w, float sp, char d,
		float w_t, pair<int, int> dest) : Vehicle(loc, w, sp, d)
{
	int n = rand() % 12;

	color = COLORS[n];
	weight_trailer = w_t;
	destination = dest;

	for (int i = 0; i < 5; i++)
		placeptr[i] = NULL;
}

string Truck::getcolor() const
{
	return color;
}

void Truck::setcolor()
{
	color = COLORS[rand() % 12];
}

float Truck::getweight() const
{
	float w;

	w = weight_trailer + (Vehicle::getweight());

	return w;
}

void Truck::setweight(float w_e, float w_t)
{
	weight_trailer = w_t;
	Vehicle::setweight(w_e);
}

pair<int, int> Truck::getdestination() const
{
	return destination;
}

void Truck::setdestination(pair<int, int> d)
{
	destination = d;
}

void Truck::setplace(Place* front, Place* p1, Place* p2, Place* p3,
		Place* back)
{
	placeptr[0] = front;
	placeptr[1] = p1;
	placeptr[2] = p2;
	placeptr[3] = p3;
	placeptr[4] = back;
}

Place** Truck::getplace()
{
	return placeptr;
}

void Truck::move()
{
	char dir = dir;
	pair<int, int> loc;

	dir = Vehicle::getdirection();
	loc = Vehicle::getlocation();

	if(placeptr[0]->freeToMove(dir)){
		cout<<"A Truck moves!"<<endl;
		if (dir == 'N')
		{
			if(placeptr[0]->next(dir) == NULL){
				loc.first=0;
				loc.second=0;
				placeptr[0] = NULL;
				placeptr[1] = NULL;
				placeptr[2] = NULL;
				placeptr[3] = NULL;
				placeptr[4] = NULL;
			}
			else{
				loc.second += 1;
				for (int i = 4; i > 0; i--)
					placeptr[i] = placeptr[i - 1];
				placeptr[0] = placeptr[0]->getnorth();
			}

		}
		else if (dir == 'S')
		{
			if(placeptr[0]->next(dir) == NULL){
				loc.first=0;
				loc.second=0;
				placeptr[0] = NULL;
				placeptr[1] = NULL;
				placeptr[2] = NULL;
				placeptr[3] = NULL;
				placeptr[4] = NULL;
			}
			else{
				loc.second -= 1;
				for (int i = 4; i > 0; i--)
					placeptr[i] = placeptr[i - 1];
				placeptr[0] = placeptr[0]->getsouth();
			}

		}
		else if (dir == 'E')
		{
			if(placeptr[0]->next(dir) == NULL){
				loc.first=0;
				loc.second=0;
				placeptr[0] = NULL;
				placeptr[1] = NULL;
				placeptr[2] = NULL;
				placeptr[3] = NULL;
				placeptr[4] = NULL;
			}
			else{
				loc.first += 1;
				for (int i = 4; i > 0; i--)
					placeptr[i] = placeptr[i - 1];
				placeptr[0] = placeptr[0]->geteast();
			}

		}
		else
		{
			if(placeptr[0]->next(dir) == NULL){
				loc.first=0;
				loc.second=0;
				placeptr[0] = NULL;
				placeptr[1] = NULL;
				placeptr[2] = NULL;
				placeptr[3] = NULL;
				placeptr[4] = NULL;
			}
			else{
				loc.first -= 1;
				for (int i = 4; i > 0; i--)
					placeptr[i] = placeptr[i - 1];
				placeptr[0] = placeptr[0]->getwest();
			}

		}
	}


	Vehicle::setlocation(loc);
}
