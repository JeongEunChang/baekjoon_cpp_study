#include <iostream>
#include <stdio.h>
using namespace std;
#pragma warning (disable:4996)

int main()
{
	int A, B;

	while (scanf("%d %d", &A, &B) != EOF)
	{

		if (A <= 0 || B >= 10)
			return 0;

		cout << A + B << endl;
	}
}