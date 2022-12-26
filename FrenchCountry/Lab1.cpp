#include<iostream>
#include<string>

using namespace std;

int main()
{
	//take input string
	string country;
	cout << "enter the city name ";
	cin >> country;
	//length of string
	int len = country.length();
	//If country name starts with a VOWEL then use 'l'' and in rare case les
	if (country[0] == 'a' || country[0] == 'A' || country[0] == 'e' || country[0] == 'E' || country[0] == 'i' || country[0] == 'I' || country[0] == 'o' || country[0] == 'O' || country[0] == 'u' || country[0] == 'U')
	{
		for (int i = 0; i <= len; i++)
		{
			if (country[i] == '-')
			{
				cout << "les " << country;
				exit(0);
			}

		}
		cout << "l'" << country;
		exit(0);

	}
	// CHECK LES FIRST!! 
	//checking masculine country name exceptions and check if feminine, otherwise it's masculine  
	else
	{
		for (int i = 0; i <= len; i++)
		{
			if (country[i] == '-')
			{
				cout << "les " << country;
				exit(0);
			}
		}
		//masculine country names that end with 'e'
		if (country == "Belize" || country == "Cambodge" || country == "Mexique" || country == "Mozambique" || country == "Zaire" || country == "Zimbabwe"
			|| country == "belize" || country == "cambodge" || country == "mexique" || country == "mozambique" || country == "zaire" || country == "zimbabwe")
		{
			cout << "Le " << country;
			exit(0);

		}
		//check feminine
		else
		{
			if (country[len - 1] == 'e' || country[len - 1] == 'E')
			{
				cout << "La " << country;
				exit(0);
			}
			//all else fails it must be masculine
			else
			{
				cout << "Le " << country;
				exit(0);
			}
		}

	}

	return 0;
}