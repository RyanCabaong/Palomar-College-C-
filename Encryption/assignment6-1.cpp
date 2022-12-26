/*
 * assignment6-1.cpp
 *
 *  Created on: Oct 26, 2022
 *      Author: ryanc
 */
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	string line;
	int i, len;
	//frequency of each character
	int freq[26];
	float percent[26];
	// Input file
	ifstream file("input6.txt");
	getline(file,line);

	len = line.size();
	//Initialize frequency of each character to 0
	for(i=0; i<26; i++)
	{
		freq[i] = 0;
	}
	//Find total number of occurrences of each character
	for(i=0; i<len; i++)
	{
		//if the current character is lowercase alphabet
		if(line[i]>='a' && line[i]<='z')
		{
			freq[(int)line[i] - 97]++;
		}
		// else upper case
		else if(line[i]>='A' && line[i]<='Z')
		{
			freq[(int)line[i] - 65]++;
		}
	}

	//firstly find sum of all used letters
	float sum = 0;
	for(int i = 0; i < 26; i++){
		sum += freq[i];
	}
	//find percentages of each letter
	for(int i = 0; i < 26; i++){
		if(freq[i]!=0){
			percent[i] = freq[i]/sum;
			//cout<<percent[i]<<endl;
		}

	}
	// max frequent letter loop
	int max=freq[0],maxposition;
	for(int i=1;i<26;i++)
	{
		if(freq[i]>max)
		{
			max = freq[i];
			maxposition=i;
		}
	}
	// Print the frequency of all characters in the string
	cout<<"\nFrequency of all characters in the given string: "<<line<<endl;
	cout<<"Letter \t frequency \t percentage\n";
	for(i=0; i<26; i++)
	{
		// If current character exists in given string
		if(freq[i] != 0)
		{
			percent[i] = freq[i]/sum;
			cout<<(char)(i + 97)<<" \t"<< freq[i]<<" \t\t"<<percent[i]<<endl;
		}
	}


	return 0;
}




