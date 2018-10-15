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


	//Key f�r rot13 s� att den vet om det inne i for-looparna.
	int key = key7;


	cout << "Skriv in en valfri text" << endl << endl;
	getline(cin, text);


	// Inititera till origiinalstr�ngen s� att den f�r lika m�nga bokst�ver i sig och att man ska kunna �ndra inne i for-loopen.
	cryptedText = text;

	// Krypterings-loopen. Valt att anv�nda modulusoperatorn f�r att r�kna ut antal tecken. N�r den har n�tt var femte str�ng och har ett visst v�rde tilldelat sig p� key, d� ska den byta key
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



	//initiera key till rot13 som det g�r i f�rsta crypteringen.
	key = key7;


	//dekrypterings-loopen. Enda som skiljer h�r �r att i slutet av for-loopen har vi valt att subtrahera ist�llet f�r att addera key.
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
