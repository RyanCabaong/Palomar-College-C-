#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <stack>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>
#include "Graph.h"
#include "Graph.cpp"
////#include <stdlib.h>
using namespace std;
//
int main()
{//-1 replaces #define INF
	string filename = "inputlab5.txt";
	Graph<int> mygraph(filename);

	mygraph.print_path(mygraph.get_start());

	cout<<"Sum of all weights: "<<mygraph.compute_cost(mygraph.get_start());
	cout<<endl;

	cout<<"Traversing through each vertex"<<endl;
	mygraph.dftraverse();//works just fine

//	double dist;
//	cout<<endl;
//	mygraph.print_path(mygraph.shortest_path(1,4, dist));
//	cout<<dist;

	return 0;
}
