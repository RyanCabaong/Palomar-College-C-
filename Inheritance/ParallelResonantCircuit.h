#pragma once

#ifndef ParallelResonantCircuit_H

#include <iostream>
#include <utility>
#include "ResonantCircuit.h"
using namespace std;

#define ParallelResonantCircuit_H

using namespace std;
class PRC : public ResonantCircuit {//ParallelResonantCircuit
public:
	PRC();
	PRC(double,double,double);

	double getR();
	
	double getC();
	
	double getL();
	
	void display();
private:
	double R;//Resistance
	double C;//Capacitor
	double L;//Induction
};
#endif
