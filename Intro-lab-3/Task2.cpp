//------------------------------------------------------------------------------
// Lab3uppg2.cpp :
// Daniel Vestlin
// Lab3 Uppgift 2
// 2016-11-28
//------------------------------------------------------------------------------

#include <iostream>   // cout, cin
#include <string>     // string-klssen
#include <algorithm>

using namespace std;

//
int main()
{
	//
	//Deklarera strängvariabler
	//
	string firstName, lastName, firstName2, lastName2, firstName3, lastName3;


	cout << "********************INPUT THREE NAMES**********************" << endl;
	cout << "Input first name: " << endl;
	cin >> firstName >> lastName;
	cout << "...And the second name: " << endl;
	cin >> firstName2 >> lastName2;
	cout << "...Last but not least: " << endl;
	cin >> firstName3 >> lastName3;


	// stringar för att sätta lowercase på alla och sortera ut på efternamn+förnamn i samma sträng.
	string name = lastName + ' ' + firstName;
	string name2 = lastName2 + ' ' + firstName2;
	string name3 = lastName3 + ' ' + firstName3;

	transform(name.begin(), name.end(), name.begin(), ::tolower);
	transform(name2.begin(), name2.end(), name2.begin(), ::tolower);
	transform(name3.begin(), name3.end(), name3.begin(), ::tolower);

	cout << endl;
	cout << "*************THE NAMES SORTED IN ALPHABETICALLY ORDER******" << endl;

	// Om första efternamnet är mindre än både efternamn två och tre ska den sorteras för att alltid vara först, precis som det står i nästlade if-satsen och else if.
	// I den andra if-satsen kollar den om förnamn två är mindre än tre, är det fallet ska den sättas som nummer två i positionering.
	if ((name < name2) && (name < name3))
	{
		if (name2 < name3)
		{
			cout << firstName << " " << lastName << "\n" << firstName2 << " " << lastName2 << "\n" << firstName3 << " " << lastName3 << endl;
		}
		if (name2 > name3)
		{
			cout << firstName << " " << lastName << "\n" << firstName3 << " " << lastName3 << "\n" << firstName2 << " " << lastName2 << endl;
		}
	}

	if ((name2 < name) && (name2 < name3))
	{
		if (name < name3)
		{
			cout << firstName2 << " " << lastName2 << "\n" << firstName << " " << lastName << "\n" << firstName3 << " " << lastName3 << endl;
		}
		if (name > name3)
		{
			cout << firstName2 << " " << lastName2 << "\n" << firstName3 << " " << lastName3 << "\n" << firstName << " " << lastName << endl;
		}
	}


	if ((name3 < name) && (name3 < name2))
	{
		if (name < name2)
		{
			cout << firstName3 << " " << lastName3 << "\n" << firstName << " " << lastName << "\n" << firstName2 << " " << lastName2 << endl;
		}

		if (name > name2)
		{
			cout << firstName3 << " " << lastName3 << "\n" << firstName2 << " " << lastName2 << "\n" << firstName << " " << lastName << endl;
		}
	}

	system("pause");
	return 0;
}
//------------------------------------------------------------------------------

