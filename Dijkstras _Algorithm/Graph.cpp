#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <stack>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Graph.h"
#include "Vertex.h"

//#include <stdlib.h>
using namespace std;

#define NVERTICES 5
#define INF 1e10
//working fine
//traverses each vertex along graph
template <typename T>
void Graph<T>::dftraverse(){
	stack<Vertex<T>*> backtrack;
	set<Vertex<T>*> visited;
	Vertex<T>* cur_vertex;

	auto it = start.begin();

	cur_vertex = *it;

	//cout<<"test"<<endl;
	//FIRST PRINT 1
	//cout << cur_vertex->getID() << " ";
	//double while loop
	while (visited.size() < start.size())
	{
		backtrack.push(cur_vertex);
		visited.insert(cur_vertex);

		while (backtrack.size() > 0)
		{

			//cout << cur_vertex->getID() << " ";
			cur_vertex = backtrack.top();
			Vertex<T>* neighbor = NULL;
			int i = 0;
			for(i = 0; i < cur_vertex->getedge().size(); i++){
				if(visited.count(cur_vertex->getedge()[i] ) != 1){
					break;
				}
			}
//			//it2 has strange vertex from edge vector of vertices
//			auto it2 = cur_vertex->getedge().begin();
//			//Checks if each vertex in current vertex has been visited by iterating through vertex.edge vector
//			while (it2 != cur_vertex->getedge().end())
//			{
//				if (visited.count(*it2) == 1)
//					it2++;
//				else
//					break;
//			}

			//something bad happens here
//			if (it2 != cur_vertex->getedge().end())
//			{
//				neighbor = *it2;
//				//neighbor has ID 16025144 and Data 16029992? most time data=0
//				visited.insert(neighbor);
//				backtrack.push(neighbor);
//				cur_vertex = neighbor;
//				//OUTPUTS ERROR
//				cout << cur_vertex->getID() << " ";
//			}
			if(i != cur_vertex->getedge().size()){
				neighbor = cur_vertex->getedge()[i++];
				visited.insert(neighbor);
				backtrack.push(neighbor);
				cur_vertex = neighbor;
			}
			else
				backtrack.pop();
		}

		if (start.size() > visited.size())//recently put +1
		{
			for (it = start.begin(); it != start.end(); it++)
			{
				if (visited.count(*it) == 0)
				{
					cur_vertex = *it;
					break;
				}
			}
		}
	}

	cout << endl;
}
template <typename T>
vector<Vertex<T> *> Graph<T>::shortest_path(int startID, int endID, double &d){//source,sinkID,dist
	Vertex<T>* cur_vertex;
	set<Vertex<T>*> visited;
	vector<Vertex<T>*> shortest;
	double* sdist = new double[start.size()];

	cur_vertex = find_vertex(startID);

	for (auto it = start.begin(); it != start.end(); it++)
	{
		Vertex<T>* temp = *it;
		int index;

		index = find_index(temp->getID());
		*(sdist + index) = -1;//????
	}

	*(sdist + find_index(startID)) = 0;

	visited.insert(cur_vertex);

	int idcount=1;//just for the while loop below to represent the ID in cout (line 140)

	while (visited.size() < start.size())
	{
		vector<Vertex<T>*> neighbors = cur_vertex->getedge();
		list<double> costs = cur_vertex->getweights();//prev: vector<double> costs

		int currentID = cur_vertex->getID();
		int currentindex = find_index(currentID);

		//declare an interator
		list<double>::iterator itl;
		itl = costs.begin();
//		cout << cur_vertex->getID() << " ";
//		cur_vertex = backtrack.top();
//		Vertex<T>* neighbor = NULL;
//		int i = 0;
//		for(i = 0; i < cur_vertex->getedge().size(); i++){
//			if(visited.count(cur_vertex->getedge()[i] ) != 1){
//				break;
//			}
//		}
		//cout<<"ultimate test!"<<endl;
		cout<<"Loop "<<idcount<<endl;

		for (int i = 0; i < neighbors.size(); i++)
		{
			cout<<i<<" "<<*itl<<endl;

			double distance;

			distance = *itl + *(sdist + currentindex);//it ==== is costs[i]

			int nindex = find_index(neighbors[i]->getID());//+1 prev: none

			if (distance < *(sdist + nindex))
			{
				*(sdist + nindex) = distance;
			}
			itl++;
		}
		//cout<<"second"<<endl;

		double cheapest = INF;//inf
		int cheapindex = -1;
		int cheapid = -1;

		//[it] is bugged
		for (auto it = start.begin(); it != start.end(); it++)
		{
			//cout<<"second for loop: "<<*it<<endl;
			Vertex<T>* temp = *it;

			if (visited.count(temp) != 0)
				continue;

			//cout<<temp->getID()<<endl;;//PRINT!!!!

			if (cheapest > * (sdist + find_index(temp->getID())))//since the first comparison
			{
				cur_vertex = temp;
				cheapindex = find_index(temp->getID());
				cheapest = *(sdist + cheapindex);
				cheapid = temp->getID();
			}
		}

		visited.insert(cur_vertex);
		idcount++;
	}  // Dijkstra algorithm

	// find the path from sourceID to sinkID



	//int current = find_index(endID);//dont need this professor

	Vertex<T>* current_vertex = find_vertex(endID);

	//cout<<current_vertex->getID()<<endl;//PRINTTT

	//int edgecount = 0;//used for line 214

	//!!!WARNING INFINITE LOOP HERE!!!
	while (current_vertex != find_vertex(startID))//Vertex<T>*
	{
		int currentID = current_vertex->getID();

		//cout<<currentID<<endl;//PRINT!! INFINITE 4's

		shortest.push_back(find_vertex(currentID));

		double cheapest = *(sdist + find_index(currentID));

		list<double> costs = current_vertex->getweights();//prev: vector<double> costs
		vector<Vertex<T>*> neighbors = current_vertex->getedge();//sets a vector = vector
		//unused neighbors
		//declare an interator
		list<double>::iterator it2;
		it2 = costs.begin();
		//fix neighbors?
		//fails to be used therefore cannot change cur vertex

		//infinite loop happens because it cannot get into this for loop which should update the current_vertex
		for (int i = 0; i < current_vertex->getedge().size(); i++)//prev: neighbors.size()
		{
			double ncost = *(sdist + find_index(current_vertex->getedge()[i]->getID()));//neighbors[i]->

			if (cheapest - *it2 == ncost)
			{
				current_vertex = current_vertex->getedge()[i];
				break;
			}
			it2++;
		}
		//edgecount++;
	}

	shortest.push_back(find_vertex(startID));
	d = *(sdist + find_index(endID));

	return shortest;
}
//returns the Vertex index on start depending on vertex ID (starting from begin())
template <typename T>
int Graph<T>::find_index(int id) const
{
	int index = 0;

	for (auto it = start.begin(); it != start.end(); it++)
	{
		Vertex<T>* temp = *it;

		if (temp->getID() == id)
			return index;

		index++;
	}

	return index;
}
template <typename T>
Vertex<T>* Graph<T>::find_vertex(int id)
{
	auto it = start.begin();

	for (; it != start.end(); it++)
	{
		Vertex<T>* temp = *it;

		if (temp->getID() == id)
			return temp;
	}

	return *it;
}
//GET START
template <typename T>
vector<Vertex<T> *> Graph<T>::get_start() const{
	return start;
}
//returns a double summed from all getdata vertices along v
template <typename T>
double Graph<T>::compute_cost(vector<Vertex<T> *> v){
	double cost = 0;
	for (auto it =v.begin(); it != v.end(); it++){
		Vertex<T>* temp = *it;
		cost += temp->getdata();

	}
	return cost;
}
//pushes v into start vector
template <typename T>
void Graph<T>::add_vertex(Vertex<T> *v){	// add a vertex to the graph
	start.push_back(v);

}
//prints Vertice(ID) and Weight(Data)
template <typename T>
void Graph<T>::print_path(vector<Vertex<T> *> v){//prev const
	cout<<"Vertice, Weight"<<endl;

	//2->3 weight: 5
	for (auto it =v.begin(); it != v.end(); it++){
		Vertex<T>* temp = *it;
		cout<<temp->getID()<<" "<<temp->getdata()<<endl;

	}
}
