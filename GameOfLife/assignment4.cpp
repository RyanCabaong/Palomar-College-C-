#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;

//The Grid class of the game of life. The grid is a 2D array.
//takes in txt file as first generation
class Grid {
	int width, height;
	//vector<vector<bool>> grid;
	bool grid[100][100];
public:
	Grid(int, int);
	//Grid(int x, int y) : grid(vector<vector<bool>>(x, vector<bool>(y))){}
	void nextFrame();
	void printFrame();
};

Grid::Grid(int a, int b) {//instead of taking in a file the grid cells is going to be random
	srand(time(0));
	height = a;//rows
	width = b;//cols
	for(int i = 0; i < a; i++){
		for(int j = 0; j < b; j++){
			int n = rand() % 2;
			if(n == 1){
				grid[i][j] = true;
			}
			else{
				grid[i][j] = false;
			}
		}
	}
}


//Checks how many surrounding cells are alive for a cell and changes it depending on the game of life rules.
//The changes are stored in a temporary 2D array. Then, it is copied to the main grid array.
void Grid::nextFrame() {

	int numSurrounding = 0;
	bool tempGrid[height][width];

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if ((i + 1) < height && grid[i + 1][j] == true)
			{
				numSurrounding++;
			}
			if ((i - 1) >= 0 && grid[i - 1][j] == true)
			{
				numSurrounding++;
			}
			if ((j + 1) < width && grid[i][j + 1] == true)
			{
				numSurrounding++;
			}
			if ((j - 1) >= 0 && grid[i][j - 1] == true)
			{
				numSurrounding++;
			}
			if ((i + 1) < height && (j + 1) < width && grid[i + 1][j + 1] == true)
			{
				numSurrounding++;
			}
			if ((i + 1) < height && (j - 1) >= 0 && grid[i + 1][j - 1] == true)
			{
				numSurrounding++;
			}
			if ((i - 1) >= 0 && (j + 1) < width && grid[i - 1][j + 1] == true)
			{
				numSurrounding++;
			}
			if ((i - 1) >= 0 && (j - 1) >= 0 && grid[i - 1][j - 1] == true)
			{
				numSurrounding++;
			}

			if (numSurrounding < 2 || numSurrounding > 3)
			{
				tempGrid[i][j] = false;
			}
			else if (numSurrounding == 2)
			{
				tempGrid[i][j] = grid[i][j];
			}
			else if (numSurrounding == 3)
			{
				tempGrid[i][j] = true;
			}

			numSurrounding = 0;

		}
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			grid[i][j] = tempGrid[i][j];
		}
	}
}

//Prints the grid into the console.
void Grid::printFrame() {
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (grid[i][j] == true)
			{
				cout << "1";
			}
			else
			{
				cout << "0";
			}

			if ((j + 1) >= width)
			{
				cout << endl;
			}
		}
	}
}

//MAIN FUNCTION
int main() {
	int inputHeight, inputWidth;
	string kbd;

	cout << "The Game of Life in C++\n\n";
	cout << "How many rows? (up to 100)" << endl;
	cin >> inputHeight;
	cout << "How many columns? (up to 100)" << endl;
	cin >> inputWidth;

	Grid life(inputHeight, inputWidth);
	life.printFrame();
	cout << endl;

	do {
		kbd = "";
		cout << "Enter \"y\" for next cycle, anything else to quit... ";
		cin >> kbd;
		cout << endl;

		life.nextFrame();
		life.printFrame();
		cout << endl;
	} while (kbd == "y");

	cout << "Goodbye." << endl;

	return 0;
}
