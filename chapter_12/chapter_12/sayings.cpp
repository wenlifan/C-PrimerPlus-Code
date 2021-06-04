#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stringbad.h"

const int ArSize = 10;
const int MaxLen = 81;

int main2()
{
	using namespace std;
	StringBad name;
	cout << "Hi, whta's your name\n >>";
	cin >> name;

	cout << name << ", please enter to " << ArSize
		<< " short syaings <empty line to quit>:\n";
	StringBad sayings[ArSize];
	char temp[MaxLen];

	int i;
	for (i = 0; i < ArSize; i++)
	{
		cout << i + 1 << ": ";
		cin.get(temp, MaxLen);
		while (cin && cin.get() != '\n')
			continue;
		if (!cin || temp[0] == '\0')
			break;
		else
			sayings[i] = temp;
	}
	int totla = i;

	if (totla > 0) 
	{
		cout << "Here are your sayings:\n";
		for (i = 0; i < totla; i++)
			cout << sayings[i] << "\n";

		StringBad* shortest = &sayings[0];
		StringBad* first = &sayings[0];

		for (i = 1; i < totla; i++)
		{
			if (sayings[i].length() < shortest->length())
				shortest = &sayings[i];
			if (sayings[i] < *first)
				first = &sayings[i];
		}

		cout << "Shortest saying:\n" << *shortest << endl;
		cout << "First alphabetically:\n" << *first << endl;
		srand(time(0));
		int choice = rand() % totla;
		StringBad* favorite = new StringBad(sayings[choice]);
		cout << "My favorite saying:\n" << *favorite << endl;
		
		delete favorite;
	}

	return 0;
}