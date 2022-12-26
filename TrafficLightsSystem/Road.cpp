
#include <iostream>
#include "Road.h"
#include "Vehicle.h"
#include "Place.h"

using namespace std;

Road::Road()
{
	direction = ' ';
}

Road::Road(pair<int, int> locations[], int nplaces, int dir)
{
	// allocate memory for all the places corresponding to the 
	// locations inputed
	for (int i = 0; i < nplaces; i++)
	{
		Place *temp = new Place(locations[i]);
		lane.push_back(temp);
	}

	if (dir == 0)
		direction = 'N';
	else if (dir == 1)
		direction = 'S';
	else if (dir == 2)
		direction = 'E';
	else
		direction = 'W';

	// link the places together to form the lane
	switch (dir)
	{
	case 0:
		for (int i = 0; i < nplaces - 1; i++)
		{
			lane[i]->setnorth(lane[i + 1]);
		}
		lane[nplaces - 1]->setnorth(NULL);

		break;

	case 1:
		for (int i = 0; i < nplaces - 1; i++)
		{
			lane[i]->setsouth(lane[i + 1]);
		}
		lane[nplaces - 1]->setsouth(NULL);

		break;

	case 2:
		for (int i = 0; i < nplaces - 1; i++)
		{
			lane[i]->seteast(lane[i + 1]);
		}
		lane[nplaces - 1]->seteast(NULL);

		break;

	case 3:
		for (int i = 0; i < nplaces - 1; i++)
		{
			lane[i]->setwest(lane[i + 1]);
		}
		lane[nplaces - 1]->setwest(NULL);
	}
}

vector<Place*> Road::getlane()
						{
	return lane;
						}

void Road::setlane(pair<int, int> locs[], int nplaces, int dir)
{
	for (int i = 0; i < nplaces; i++)
	{
		Place* temp = new Place(locs[i]);
		lane.push_back(temp);
	}

	lane.clear();

	if (dir == 0)
		direction = 'N';
	else if (dir == 1)
		direction = 'S';
	else if (dir == 2)
		direction = 'E';
	else
		direction = 'W';

	// link the places together to form the lane
	switch (dir)
	{
	case 0:
		for (int i = 0; i < nplaces - 1; i++)
		{
			lane[i]->setnorth(lane[i + 1]);
		}
		lane[nplaces - 1]->setnorth(NULL);

		break;

	case 1:
		for (int i = 0; i < nplaces - 1; i++)
		{
			lane[i]->setsouth(lane[i + 1]);
		}
		lane[nplaces - 1]->setsouth(NULL);

		break;

	case 2:
		for (int i = 0; i < nplaces - 1; i++)
		{
			lane[i]->seteast(lane[i + 1]);
		}
		lane[nplaces - 1]->seteast(NULL);

		break;

	case 3:
		for (int i = 0; i < nplaces - 1; i++)
		{
			lane[i]->setwest(lane[i + 1]);
		}
		lane[nplaces - 1]->setwest(NULL);
	}
}


char Road::getdirection() const
{
	return direction;
}

void Road::setdirection(char dir)
{
	direction = dir;
}

//return specified place on road based on int
Place* Road::getplace(int n){
	int i =0;
	while(i != n){
		i++;
	}
	return lane[i];
}
void Road::setplace(Place* p, int n, char dir){
	int i =0;
	while(i != n){
		i++;
	}
	lane[i]=p;
	//set directions of new place
	if(dir=='N'){
		p->setnorth(lane[i+1]);
		p->setsouth(lane[i-1]);
	}
	if(dir=='S'){
		p->setnorth(lane[i+1]);
		p->setsouth(lane[i-1]);
	}
	else if(dir == 'E'){
		p->seteast(lane[i+1]);
		p->setwest(lane[i-1]);
	}
	else{
		p->seteast(lane[i+1]);
		p->setwest(lane[i-1]);
	}
}
int Road::getfreeplace(int dir)
{
	if (dir == 0)  // North
	{
		for (int i = YMAX-1; i >= 0; i--)
		{
			pair<int, int> loc = lane[i]->getlocation();

			if (loc.second >= YMAX / 2)
				continue;

			if (lane[i]->isoccupied())
				continue;

			return i;
		}
	}
	else if (dir == 1) //south
	{
		for (int i = 0; i < YMAX; i++)
		{
			pair<int, int> loc = lane[i]->getlocation();

			if (loc.second <= YMAX / 2)
				continue;

			if (lane[i]->isoccupied())
				continue;

			return i;
		}
	}
	else if (dir == 2) //east
	{
		for (int i = XMAX-1; i >= 0; i--)
		{
			pair<int, int> loc = lane[i]->getlocation();

			if (loc.first >= XMAX / 2)
				continue;

			if (lane[i]->isoccupied())
				continue;

			return i;
		}
	}
	else  // west
	{
		for (int i = 0; i < XMAX; i++)
		{
			pair<int, int> loc = lane[i]->getlocation();

			if (loc.first <= XMAX / 2)
				continue;

			if (lane[i]->isoccupied())
				continue;

			return i;
		}
	}

	return -1;
}
