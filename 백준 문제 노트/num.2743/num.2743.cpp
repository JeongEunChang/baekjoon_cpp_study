#include <iostream>
#include <cstring>
using namespace std;

string Input;
int Count;

int main()
{
	cin >> Input;

	for (int i = 0; i <= 101; i++)
	{
		if (Input[i] == NULL)
			break;

		Count++;
		
	}

	cout << Count;
}