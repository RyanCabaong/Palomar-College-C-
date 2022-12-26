#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <stack>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Vertex.h"
//#include <stdlib.h>
using namespace std;

#define NVERTICES 5
#define INF 1e10
//vars to instantiate in yeah
//S data, int ID,
//template <typename S>
//Vertex<S>::Vertex<S>(S ndata){
//	data = ndata;
//	ID = 0;
//}
//template <typename S>
//Vertex<S>::Vertex<S>(int id){
//	ID = id;
//}
template <typename S>
S Vertex<S>::getdata() const{
	return data;
}
template <typename S>
list<double> Vertex<S>::getweights(){
	return weights;
}
template <typename S>
vector<Vertex<S> *> Vertex<S>::getedge(){
	return edge;
}
template <typename S>
void Vertex<S>::setdata(S &ndata){
	data=ndata;
}
template <typename S>
void Vertex<S>::addedge(Vertex *v){//add edge?
	edge.push_back(v);
	count_vertices++;
}
template <typename S>
void Vertex<S>::addweight(double w){
	weights.push_back(w);
}
template <typename S>
int Vertex<S>::get_degree() const{
	return edge->size();
}
template <typename S>
int Vertex<S>::getID(){
	return ID;
}
template <typename S>
void Vertex<S>::setID(int id){
	ID = id;
}
