#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
    string A;
    string B;
    int Ai = 0;
    int Bi = 0;
    int Digit = 1;

    cin >> A >> B;

    for (int i = 0; i < 3; i++)
    {
        Ai += (A[i] - '0') * Digit;
        Bi += (B[i] - '0') * Digit;

        Digit *= 10;
    }

    cout << max(Ai, Bi);
}