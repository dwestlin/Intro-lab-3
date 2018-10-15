// Lab3uppg1.cpp :
// Daniel Vestlin
// Lab3 Uppgift 1
// 2016-11-28

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>


using namespace std;
using std::string;

int main()
{
	// Hela texten som skulle finnas med.
	string const inText1 = "Foten är en kroppsdel som förekommer mycket i våra uttryck.";
	string const inText2 = "På stående fot betyder omedelbart, utan förberedelse.";
	string const inText3 = "Försätta på fri fot betyder att ge någon friheten.";
	string const inText4 = "Sätta foten i munnen betyder att göra bort sig.";
	string const inText5 = "Få om bakfoten betyder att missuppfatta något.";
	string const inText6 = "Skrapa med foten betyder att visa sig underdånig eller ödmjuk.";
	string const inText7 = "Stryka på foten betyder att tvingas ge upp.";
	string const inText8 = "Leva på stor fot betyder att föra ett dyrbart eller slösaktigt leverne.";
	string const inText9 = "Varför fick du foten???";


	// Deklaration på hela texten så att den går att ändra i.
	string wholeText = inText1 + inText2 + inText3 + inText4 + inText5 + inText6 + inText7 + inText8 + inText9;


	//Gör om hela texten så att den är små bokstäver.
	transform(wholeText.begin(), wholeText.end(), wholeText.begin(), ::tolower);


	// leta reda på alla som heter fot och ersätta det med hand.
	size_t findFot = 0;
	while ((findFot = wholeText.find("fot", findFot)) != string::npos) {
		wholeText.replace(findFot, 3, "hand");
	}


	// Anger att 0 dvs första bokstaven i wholeText ska ersättas från låg bokstav till en stor bokstav.
	string firstChar;
	if (islower(wholeText[0])) {
		firstChar = toupper(wholeText[0]);
		wholeText.replace(0, 1, firstChar);
	}




	// hitta punkterna för att göra radbrytning och sen gör en stor bokstav på nästkommande bokstav efter radbrytning nu när den är en liten bokstav.
	size_t findPeriod = 0;
	while ((findPeriod = wholeText.find(".", findPeriod + 1)) != string::npos) {
		wholeText.replace(findPeriod, 1, ".\n");

		string upperChar;
		if (wholeText[findPeriod + 2]) {
			char c;
			c = wholeText[findPeriod + 2];
			upperChar = wholeText.substr(findPeriod + 2, 1);
			if (islower(c)) {
				upperChar = toupper(c);
				wholeText.replace(findPeriod + 2, 1, upperChar);
			}
		}

	}



	cout << wholeText << endl;
	system("pause");

	return 0;
}

