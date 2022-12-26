#include <iostream>
#include <vector>
#include <string>
using namespace std;

class AssociativeArray
{
	typedef struct Record
	{
		double price;
		string name;
	}data;
	vector<data> stack;
public:
	//hint: double& operator[](string)
	double& operator [] (string xname)//relies on stack to already have items
	{
		//check if name is in stack
		for(int i=0; i<stack.size(); i++)
		{
			if(stack[i].name==xname)
				return stack[i].price;
		}
		//push new item to stack
		long index = stack.size();
		data item;
		item.name = xname;
		stack.push_back(item);
		return stack[index].price;
	}

};
int main()
{
	AssociativeArray array;

	array["toaster"]=12.9;
	array["vacuum"]=29.5;
	cout<<array["toaster"];

	return 0;
}
