
#include <iostream>
#include "ResonantCircuit.h"

using namespace std;

//constructor
ResonantCircuit::ResonantCircuit(){

}
ResonantCircuit::ResonantCircuit(double freq, double bandwidth, double gain){
	w = freq;
	B = bandwidth;
	k = gain;
}
//retrieve (w) resonant frequency
double ResonantCircuit::getw(){
	return w;
}
//set (w) resonant frequency
void ResonantCircuit::setw(double freq){
	w=freq;
}
//retrieve (B) Bandwidth
double ResonantCircuit::getB(){
	return B;
}
//set (B) Bandwidth
void ResonantCircuit::setB(double bandwidth){
	B=bandwidth;
}
//retrieve (k) gains
double ResonantCircuit::getk(){
	return k;
}
//set (k) gains
void ResonantCircuit::setk(double gain){
	k=gain;
}

void ResonantCircuit::display(){
	cout<<"[Resonant Circuit]"<<endl;
	cout<<"(w) Resonance Frequency: "<<getw()<<", (B) Bandwidth: "<<getB()<<", (k) Gains: "<<getk()<<endl;
}
