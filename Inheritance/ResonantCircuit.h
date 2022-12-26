#pragma once
#ifndef ResonantCircuit_H
#include <iostream>
#define ResonantCircuit_H
using namespace std;
class ResonantCircuit{
public:
	ResonantCircuit();
	ResonantCircuit(double freq, double bandwidth, double gain);
	double getw();
	void setw(double);
	double getB();
	void setB(double);
	double getk();
	void setk(double);
	virtual void display();
	double w;//resonant frequency
	double B;//bandwidth
	double k;//gain of resonant frequency
};
#endif
