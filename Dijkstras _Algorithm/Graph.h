#pragma once
#ifndef GRAPH_H
#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <stack>
#include <cstdlib>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "Vertex.h"
#include "Vertex.cpp"
using namespace std;
#define NVERTICES 5
#define INF 1e10
#define GRAPH_H
template <typename T>
class Graph
{
private:
	vector <Vertex<T> *> start;

public:
	Graph<T>(string filename){
		ifstream inputfile(filename);

		if (!inputfile.is_open())
			cout<<"Error opening file" ;
		//0 5 4 INF INF
		//5 0 INF 2 3
		//4 INF 0 1 INF
		//INF 2 1 0 2
		//INF 3 INF 2 0
		//convert file into double array NVERTICES = 5
		//double lol = atof(word.c_str());

		double adjmat[NVERTICES][NVERTICES];

		//getline(inputfile,line);
		//the data is the int ID

		//retrieve file input into double 2D array
		for (int i = 0; i < NVERTICES; i++)
		{
			//inputfile >>
			for (int j = 0; j < NVERTICES; j++)
			{
				inputfile >> adjmat[i][j];
				//cout<<adjmat[i][j]<<" ";
			}
			//cout<<endl;

		}

		// Creating all the vertices
		for (int i = 0; i < NVERTICES; i++)
		{
			for(int j = 0; j < NVERTICES; j++){
				Vertex<T>* temp = new Vertex<T>(adjmat[i][j],i+1);
				start.push_back(temp);
			}

		}

	// Create the graph
		auto it = start.begin();

		for (int i = 0; i < NVERTICES; i++)
		{
			Vertex<T>* temp = *it;

			for (int j = 0; j < NVERTICES; j++)
			{

				if (i == j)
					continue;

				double cur_weight = adjmat[i][j];

				if (cur_weight > -1)
				{


					//(*it)->getweight().push_back(cur_weight);//push into weight vector
					(*it)->addweight(cur_weight);
					//(*it)->getedge().push_back(findvertex(j + 1));//push into vertex vector
					(*it)->addedge(find_vertex(j + 1));
				}
			}

			it++;
		}
	}

	void dftraverse();          // depth first traversal
	vector<Vertex<T> *> shortest_path(int start, int end, double &s);
	// start = ID of starting vertex
	// end = ID of ending vertex
	// w is the total cost from start to end
	vector<Vertex<T> *> get_start() const;  // get the starting vertex of the graph
	double compute_cost(vector<Vertex<T> *>);  // compute cost given path of vertices
	void add_vertex(Vertex<T> *);      // add a vertex to the graph
	void print_path(vector<Vertex<T> *>) ;//prev const
	Vertex<T> * find_vertex(int ID); // find the vertex given its ID
	int find_index(int id) const;//new

};
#endif
