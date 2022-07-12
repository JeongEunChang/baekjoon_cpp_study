#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int DivisionAlgorithm(int A, int B)
{
	if (B > A)
	{
		int tmp = B;
		B = A;
		A = tmp;
	}

	while (B != 0)
	{
		int tmp = A % B;
		A = B;
		B = tmp;
	}

	return A;
}

int main()
{
	int Ap = 0;
	int Ac = 0;
	int Bp = 0;
	int Bc = 0;
	int tmp;
	int tmp2;


	cin >> Ac >> Ap;

	tmp = DivisionAlgorithm(Ap, Ac);

	Ap /= tmp;
	Ac /= tmp;


	cin >> Bc >> Bp;

	tmp = DivisionAlgorithm(Bp, Bc);

	Bp /= tmp;
	Bc /= tmp;


	tmp = Ap;
	tmp2 = Bp;

	Bp *= tmp;
	Bc *= tmp;

	Ap *= tmp2;
	Ac *= tmp2;

	Ac += Bc;

	tmp = DivisionAlgorithm(Ap, Ac);

	Ap /= tmp;
	Ac /= tmp;

	cout << Ac << " " << Ap;


}