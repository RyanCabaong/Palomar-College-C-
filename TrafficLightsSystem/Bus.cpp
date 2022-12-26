
#include <iostream>
#include "Bus.h"
#include "constants.h"
#include "Place.h"
#include "Vehicle.h"

using namespace std;

Bus::Bus()
{
	name = " ";
	npassengers = 0;
	for (int i = 0; i < 4; i++)
		placeptr[i] = NULL;
}

Bus::Bus(pair<int, int> loc, float w, float sp, char d, string na,
		int n) : Vehicle(loc, w, sp, d)
{
	name = na;
	npassengers = n;

	for (int i = 0; i < 4; i++)
		placeptr[i] = NULL;
}

void Bus::setname(string na)
{
	name = na;
}

string Bus::getname() const
{
	return name;
}

void Bus::setnpassenger(int n)
{
	npassengers = n;
}

int Bus::getnpassengers() const
{
	return npassengers;
}

void Bus::setplace(Place* front, Place* p1, Place* p2, Place* back)
{
	placeptr[0] = front;
	placeptr[1] = p1;
	placeptr[2] = p2;
	placeptr[3] = back;
}

Place** Bus::getplace()
{
	return placeptr;
}

void Bus::move()
{
	char dir = dir;
	pair<int, int> loc;

	dir = Vehicle::getdirection();
	loc = Vehicle::getlocation();

	if(placeptr[0]->freeToMove(dir)){
		cout<<"A Bus moves!"<<endl;
		if (dir == 'N')
		{
			//if the next place is out of bounds than NULL our standing
			if(placeptr[0]->next(dir) == NULL){
				loc.first=0;
				loc.second=0;
				placeptr[0] = NULL;
				placeptr[1] = NULL;
				placeptr[2] = NULL;
				placeptr[3] = NULL;
			}
			else{
				loc.second += 1;
				for (int i = 3; i > 0; i--)
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
			}
			else{
				loc.second -= 1;
				for (int i = 3; i > 0; i--)
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
			}
			else{
				loc.first += 1;
				for (int i = 3; i > 0; i--)
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
			}
			else{
				loc.first -= 1;
				for (int i = 3; i > 0; i--)
					placeptr[i] = placeptr[i - 1];
				placeptr[0] = placeptr[0]->getwest();
			}

		}
	}

	Vehicle::setlocation(loc);
}
