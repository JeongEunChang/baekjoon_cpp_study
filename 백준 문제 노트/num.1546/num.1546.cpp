#include <iostream>
#include <stdio.h>
using namespace std;

int N, M;
double Sum;
double Array[1000];

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> Array[i];

        if (M < Array[i])
            M = Array[i];
    }

    for (int i = 0; i < N; i++)
    {
        Array[i] = (Array[i] / M) * 100;
    }

    for (int i = 0; i < N; i++)
    {
        Sum += Array[i];
    }

    cout << fixed;
    cout.precision(6);
    //double av = Sum / N;
    //printf("%f", Sum / N);
    cout << Sum / N;
}