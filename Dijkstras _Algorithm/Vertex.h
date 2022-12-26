#pragma once
#ifndef VERTEX_H
#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <stack>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;
#define VERTEX_H
template <typename S>
class Vertex
{
public:
	Vertex(S ndata){
		data = ndata;
	}
	Vertex(S ndata, int id){
		data = ndata;
		ID = id;
	}
	~Vertex(){ delete[] data; }
	//Vertex(S);
	//Vertex(int);//new
	S getdata() const;
	list<double> getweights();  // Not constant because we may want to change the weights
	vector<Vertex *> getedge();  // Not constant because we may want to change the edges
	void setdata(S &);
	void addedge(Vertex *);
	void addweight(double );
	int get_degree() const;
	int getID();//const?
	void setID(int id);// return the degree of a vertex, # if all edges in edge vertex*
private:
	S data;  // data to store at each vertex
	int ID;   // ID of the vertex
	list<double> weights;   // list of weights for all edges connected to vertex
	vector<Vertex *> edge;   // list of all vertices connected to this vertex
	int count_vertices;  // use to keep count of how many vertices are added to the graph

	//ETC...(you may need to add additional member functions to implement this class)

};
#endif
