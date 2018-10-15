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
	string const inText1 = "Foten �r en kroppsdel som f�rekommer mycket i v�ra uttryck.";
	string const inText2 = "P� st�ende fot betyder omedelbart, utan f�rberedelse.";
	string const inText3 = "F�rs�tta p� fri fot betyder att ge n�gon friheten.";
	string const inText4 = "S�tta foten i munnen betyder att g�ra bort sig.";
	string const inText5 = "F� om bakfoten betyder att missuppfatta n�got.";
	string const inText6 = "Skrapa med foten betyder att visa sig underd�nig eller �dmjuk.";
	string const inText7 = "Stryka p� foten betyder att tvingas ge upp.";
	string const inText8 = "Leva p� stor fot betyder att f�ra ett dyrbart eller sl�saktigt leverne.";
	string const inText9 = "Varf�r fick du foten???";


	// Deklaration p� hela texten s� att den g�r att �ndra i.
	string wholeText = inText1 + inText2 + inText3 + inText4 + inText5 + inText6 + inText7 + inText8 + inText9;


	//G�r om hela texten s� att den �r sm� bokst�ver.
	transform(wholeText.begin(), wholeText.end(), wholeText.begin(), ::tolower);


	// leta reda p� alla som heter fot och ers�tta det med hand.
	size_t findFot = 0;
	while ((findFot = wholeText.find("fot", findFot)) != string::npos) {
		wholeText.replace(findFot, 3, "hand");
	}


	// Anger att 0 dvs f�rsta bokstaven i wholeText ska ers�ttas fr�n l�g bokstav till en stor bokstav.
	string firstChar;
	if (islower(wholeText[0])) {
		firstChar = toupper(wholeText[0]);
		wholeText.replace(0, 1, firstChar);
	}




	// hitta punkterna f�r att g�ra radbrytning och sen g�r en stor bokstav p� n�stkommande bokstav efter radbrytning nu n�r den �r en liten bokstav.
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

