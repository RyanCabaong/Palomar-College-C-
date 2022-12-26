#include <iostream>
#include <string>

using namespace std;

int main() {
	string user_name;
	cout << "Hello, my name is Hal!\n What is your name?" << endl;
	getline(cin, user_name);
	cout << "Hello, " << user_name << ". I am glad to meet you!" << endl;

}