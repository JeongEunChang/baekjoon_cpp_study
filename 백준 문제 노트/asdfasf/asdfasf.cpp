#include <iostream>
#include <cstring>
using namespace std;

int Arr[10] = { 5, 5, 10, 1, 0, 8, 6, 7, 2, 3 };

void Merge(int Left, int Mid, int Right)
{
	int tmpArr[10] = { 0 };
	int L = Left;
	int R = Right;
	int tmpPointer = Left;
	int M = Mid + 1;

	while (L <= Mid && M <= Right)
	{
		if (Arr[L] <= Arr[M])
		{
			tmpArr[tmpPointer++] = Arr[L++];
		}

		else
		{
			tmpArr[tmpPointer++] = Arr[M++];
		}
	}

	if (L > Mid)
	{
		while (M <= Right)
		{
			tmpArr[tmpPointer++] = Arr[M++];
		}		
	}

	else
	{
		while (L <= Mid)
		{
			tmpArr[tmpPointer++] = Arr[L++];
		}
	}

	for (int i = Left; i <= Right; i++)
	{
		Arr[i] = tmpArr[i];
		cout << Arr[i] << " ";
	}

	cout << endl;
}

void Device(int Left, int Right)
{
	if (Left < Right)
	{
		int Mid = (Left + Right) / 2;
		Device(Left, Mid);
		Device(Mid + 1, Right);
		Merge(Left, Mid, Right);
	}
}



int main()
{
	for (int i = 0; i < 10; i++)
	{
		cout << Arr[i] << " ";
	}

	cout << endl;

	Device(0, (sizeof(Arr) / sizeof(int)) - 1);

	for (int i = 0; i < 10; i++)
	{
		cout << Arr[i] << " ";
	}
}