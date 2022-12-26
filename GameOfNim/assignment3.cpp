#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

	int pile;
	int marbles;
	int num = 0;
	int low = 1;
	short coin;
	short choice;
	bool turn, smart;
	//Generate a random integer 10 to 100 for inital size of pile
	srand(time(0));
	pile = rand() % 100 + 10;//gets me 10 to 109
	//output pile
	cout << "Starting pile: " << pile << endl;

	//ask user for smart or stupid mode
	cout << "make computer smart or stupid?(0 for smart, 1 for stupid): ";
	cin >> choice;
	if (choice == 0) {
		cout << "You have chosen smart mode!" << endl;
		smart = true;
	}
	else if (choice == 1) {
		cout << "You have chosen stupid mode!" << endl;
		smart = false;
	}
	else {
		cout << "Invalid selection";
		exit(0);
	}

	//flip a coin to see whether player or computer goes FIRST
	coin = rand() % 2;
	//player goes first
	if (coin == 0) {
		cout << "Player goes first!" << endl;
		turn = true;
	}
	//computer goes first
	else {
		cout << "Computer goes first!" << endl;
		turn = false;
	}


	while (true) {

		if (pile > 0) {
			marbles = pile / 2;
			if (turn == false) {//COMPUTER TURN
				if (smart == false) {//stupid mode
					if (pile == 1) {
						cout << "Computer took away 1" << endl;
						pile = pile - 1;
					}
					else {
						//int marblesLost = rand() % marbles + low;//gets me random value between marbles

						cout << "Computer took away " << marbles << endl;
						pile = pile - marbles;
					}
				}
				else {//smart mode
					if (pile == 1) {
						cout << "Computer took away 1" << endl;
						pile = pile - 1;
					}
					else {
						//int marblesLost = (marbles / 2) + 1;
						int marblesLost = marbles + 1;
						cout << "Computer took away " << marblesLost << endl;
						pile = pile - marblesLost;
					}
				}

				turn = true;
				cout << "current pile: " << pile << endl;
			}
		}


		if (pile > 0) {
			marbles = pile / 2;
			if (turn == true) {//PLAYER TURN
				cout << "How many marbles (between 1 and " << marbles << ") do you want to remove?: " << endl;
				cin >> num;
				if (pile != 1) {
					if (num <= 0 || num > marbles) {
						cout << "Invalid selection!";
						break;
					}
				}

				pile = pile - num;
				turn = false;
				cout << "current pile: " << pile << endl;
			}
		}



		if (pile == 0) {
			if (turn == true) {
				cout << "Computer took last marble. Player won!";
			}
			else {
				cout << "Player took last marble. Computer won!";
			}
			break;
		}
	}

	return 0;
}
