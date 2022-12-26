#pragma once

#include <iostream>
#include <string>

using namespace std;

#ifndef CONSTANTS_H

#define CONSTANTS_H

const int XMAX = 1000;
const int YMAX = 1000;

#define CAR_PROB 0.1
#define BUS_PROB 0.04
#define TRUCK_PROB 0.04
#define MOTORCYCLE_PROB 0.07

const string COLORS[12] = { "red", "blue", "green", "white", "black",
					 "yellow", "orange", "pink", "purple",
					 "teal", "brown", "magenta" };

enum traffic_state{
RED = 0,
GREEN,//1
YELLOW//2
};


#endif
