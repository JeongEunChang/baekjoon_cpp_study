#include <iostream>
using namespace std;

int Chord[9];

int main()
{
	for (int i = 1; i <= 8; i++)
	{
		int Input;
		cin >> Input;

		Chord[i] = i;
	}

	if (Chord[1] == 1)
	{
		for (int i = 1; i <= 8; i++)
		{
			if (Chord[i] != i)
			{
				cout << "mixed";
				return 0;
			}
		}
	}

	else if (Chord[1] == 8)
	{
		for (int i = 8; i >= 1; i--)
		{
			if (Chord[i] != i)
			{
				cout << "mixed";
				return 0;
			}
		}
	}

	for (int i = 1; i <= 8; i++)
	{
		int Input;
		cin >> Input;

		Chord[i] = i;
	}

	if (MakeChord == "cdefgabC")
		cout << "ascending";

	else if (MakeChord == "Cbagfedc")
		cout << "descending";

	else
		cout << "mixed";
}