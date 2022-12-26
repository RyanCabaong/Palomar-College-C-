#pragma once
#ifndef APAIR_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
template <typename K, typename V>//Key(string) , Value(double)
class Apair
{
private:
	vector<pair <K,V> > vect;
public:
	void put(K key, V value);
	V get(K);
//template AssociativeArray<K, V>. Use a vector<pair<K, V>> to hold the key/value pairs.

};
#endif
