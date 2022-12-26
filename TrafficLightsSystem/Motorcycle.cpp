
#include <iostream>
#include <cstdlib>
#include <utility>
#include "Motorcycle.h"

#include "Place.h"
#include "Constants.h"


using namespace std;

Motorcycle::Motorcycle()
{
	brand_name = " ";
	placeptr[0] = NULL;
}

Motorcycle::Motorcycle(pair<int, int> loc, float w, float sp, char d,
	string bn) : Vehicle(loc, w, sp, d)
{
	brand_name = bn;
	placeptr[0] = NULL;
}

string Motorcycle::getbrandname() const
{
	return brand_name;
}

void Motorcycle::setbrandname(string bn)
{
	brand_name = bn;
}

void Motorcycle::setplace(Place* p)
{
	placeptr[0] = p;
}

Place** Motorcycle::getplace()
{
	return placeptr;
}
void Motorcycle::move()
{
	char dir;
	pair<int, int> loc;

	dir = Vehicle::getdirection();
	//loc = getlocation();
	if(placeptr[0]->freeToMove(dir)){
		cout<<"A Motorcycle moves!"<<endl;
		if (dir == 'N')
			{
				//if the next place is out of bounds than NULL our standing
				if(placeptr[0]->next(dir) == NULL){
					loc.first=0;
					loc.second=0;
					placeptr[0] = NULL;
				}
				else{
					loc.second = loc.second + 1;
					placeptr[0] = placeptr[0]->getnorth();
				}


			}
			else if (dir == 'S')
			{
				if(placeptr[0]->next(dir) == NULL){
					loc.first=0;
					loc.second=0;
					placeptr[0] = NULL;
				}
				else{
					loc.second = loc.second - 1;
					placeptr[0] = placeptr[0]->getsouth();
				}

			}
			else if (dir == 'E')
			{
				if(placeptr[0]->next(dir) == NULL){
					loc.first=0;
					loc.second=0;
					placeptr[0] = NULL;
				}
				else{
					loc.first = loc.first + 1;
					placeptr[0] = placeptr[0]->geteast();
				}

			}
			else
			{
				if(placeptr[0]->next(dir) == NULL){
					loc.first=0;
					loc.second=0;
					placeptr[0] = NULL;
				}
				else{
					loc.first = loc.first - 1;
					placeptr[0] = placeptr[0]->getwest();
				}

			}
	}


	Vehicle::setlocation(loc);
}
