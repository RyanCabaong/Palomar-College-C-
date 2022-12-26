#include <iostream>
#include <fstream>
#include <string>
#include "Matrix.h"

using namespace std;

int main()
{
	int choice;
	int dims;

	cout<<"Welcome to the Matrix Class"<<endl;
	//Opening the file
	ifstream inputfile("input1.txt");
	//file check
	if (!inputfile.is_open())
		cout<<"Error opening file" ;
	//receive matrix dimensions
	inputfile >> dims;
	cout<<dims<<endl;

	int arrayOne[dims][dims];
	//Defining the loop for getting input from the file

	for (int i = 0; i < dims; i++)
	{
		for (int j = 0; j < dims; j++)
		{
			inputfile >> arrayOne[i][j];  //Take input from file and put into myArray
			cout<<arrayOne[i][j]<<" ";
		}
		cout<<endl;
	}

	int *pm[dims];
	for (int i = 0; i < dims; i++){
		pm[i] = arrayOne[i];
	}
	//create Matrix
	Matrix matrixOne(pm,dims);
	//receive and output operation
	string d;
	inputfile >> d;
	cout<<d;

	inputfile >> choice;
	cout<<" "<<choice<<endl;
	//1 add
	//2 subtract
	//3 mult
	//4 pre inc
	//5 pre dec
	//6 transpose
	if (choice == 1){
		//add
		int arrayTwo[dims][dims];
		for (int i = 0; i < dims; i++)
		{
			for (int j = 0; j < dims; j++)
			{
				inputfile >> arrayTwo[i][j];  //Take input from file and put into myArray
				cout<<arrayTwo[i][j]<<" ";
			}
			cout<<endl;
		}
		int *pmm[dims];
		for (int i = 0; i < dims; i++){
			pmm[i] = arrayTwo[i];
		}
		cout<<endl;
		//create Matrix
		Matrix matrixTwo(pmm,dims);
		//perform subtraction
		Matrix matrixSum(matrixOne + matrixTwo);
		cout << matrixSum;
	}
	else if(choice == 2){
		//subtract
		int arrayTwo[dims][dims];
		for (int i = 0; i < dims; i++)
		{
			for (int j = 0; j < dims; j++)
			{
				inputfile >> arrayTwo[i][j];  //Take input from file and put into myArray
				cout<<arrayTwo[i][j];
			}
			cout<<endl;
		}
		int *pmm[dims];
		for (int i = 0; i < dims; i++){
			pmm[i] = arrayTwo[i];
		}
		cout<<endl;
		//create Matrix
		Matrix matrixTwo(pmm,dims);
		Matrix matrixSub(matrixOne - matrixTwo);
		cout << matrixSub;
	}
	else if(choice == 3){
		//multiply
		int arrayTwo[dims][dims];
		for (int i = 0; i < dims; i++)
		{
			for (int j = 0; j < dims; j++)
			{
				inputfile >> arrayTwo[i][j];  //Take input from file and put into myArray
				cout<<arrayTwo[i][j];
			}
			cout<<endl;
		}
		int *pmm[dims];
		for (int i = 0; i < dims; i++){
			pmm[i] = arrayTwo[i];
		}
		cout<<endl;
		//create Matrix
		Matrix matrixTwo(pmm,dims);
		Matrix matrixMul(matrixOne * matrixTwo);
		cout << matrixMul;
	}
	else if(choice == 4){
		//pre-inc
		cout << ++matrixOne;
	}
	else if(choice == 5){
		//pre-dec
		cout << matrixOne++;
	}
	else if(choice == 6){
		//transpose
		cout<<matrixOne.transpose();
	}
	else if(choice == 7){
		//exponential
		int num;
		inputfile >> num;
		cout<<matrixOne^num;
	}
	else{
		cout<<"Error"<<endl;
		exit(0);
	}


	return 0;
}
