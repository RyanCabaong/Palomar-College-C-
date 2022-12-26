#include <iostream>
#include "ResonantCircuit.h"
#include "SeriesResonantCircuit.h"
#include "ParallelResonantCircuit.h"
using namespace std;
int main(){
	PRC* p = new PRC(105.10, 80.25,2.75);
	SRC* s = new SRC(105.10, 80.25,2.75);
	p->display();
	s->display();
	delete p,s;
	p=NULL;
	s=NULL;
	return 0;
}
