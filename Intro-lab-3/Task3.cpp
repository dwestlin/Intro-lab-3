//------------------------------------------------------------------------------
//
// Daniel Vestlin 2016-11-27
//
//------------------------------------------------------------------------------
#include <iostream>   // cout, cin
#include <string>     // string-klssen

using namespace std;

//
int main()
{

	//Deklarationer
	string text, cryptedText, decryptedText;
	int i = 0;
	int key7 = 7;
	int key13 = 13;


	//Key får rot13 så att den vet om det inne i for-looparna.
	int key = key7;


	cout << "Skriv in en valfri text" << endl << endl;
	getline(cin, text);


	// Inititera till origiinalsträngen så att den får lika många bokstäver i sig och att man ska kunna ändra inne i for-loopen.
	cryptedText = text;

	// Krypterings-loopen. Valt att använda modulusoperatorn för att räkna ut antal tecken. När den har nått var femte sträng och har ett visst värde tilldelat sig på key, då ska den byta key
	// till den andre av dom.
	for (i = 0; i < cryptedText.length(); i++)
	{
		if (i % 5 == 0)
		{
			if (key == key13)
			{
				key = key7;
			}
			else if (key == key7)
			{
				key = key13;
			}

		}

		cryptedText[i] += key;
	}

	cout << endl;
	cout << "    ****THE CRYPTED TEXT****" << endl;
	cout << cryptedText << endl;



	//initiera key till rot13 som det gör i första crypteringen.
	key = key7;


	//dekrypterings-loopen. Enda som skiljer här är att i slutet av for-loopen har vi valt att subtrahera istället för att addera key.
	for (i = 0; i < cryptedText.length(); i++)
	{
		if (i % 5 == 0)
		{
			if (key == key13)
			{
				key = key7;
			}
			else if (key == key7)
			{
				key = key13;
			}

		}

		cryptedText[i] -= key;
	}

	cout << endl;
	cout << "   ****THE DECRYPTED TEXT****" << endl;
	cout << cryptedText << endl;

	system("pause");


	return 0;

}
