#include <iostream>
#include <vector>
#include <string>
#include "Apair.h"
using namespace std;

//template AssociativeArray<K, V>. Use a vector<pair<K, V>> to hold the key/value pairs.
//no constructor, method takes param(K,V) from template
template <typename K, typename V>
void Apair<K,V>::put(K key,V value){
	  pair<K, V> p;
	  p.first = key;
	  p.second = value;
	  vect.push_back(p);
}
//RETURNS V value, get(K key) parameters K
template <typename K, typename V>
V Apair<K,V>::get(K key){
	//have to iterate O(n) to equal K key == vect[i].first
	  for (int i=0; i<vect.size(); i++) {
	    if (vect[i].first == key) {
	      return vect[i].second;
	    }
	  }
	  return 0;
}

int main()
{
	Apair<string,double> prices;

	prices.put("toaster",12.9);
	prices.put("Vacuum",21.4);
	cout<<prices.get("toaster");

	return 0;
}






