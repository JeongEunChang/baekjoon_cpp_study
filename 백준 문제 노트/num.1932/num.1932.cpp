#include <iostream>
#include <algorithm>
using namespace std;

int Array[3211311];
int DP[3211311];
int N, TriangleArrSize, Max;

int main()
{    
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        TriangleArrSize += i;
    }

    for (int i = 1; i <= TriangleArrSize; i++)
    {
        cin >> Array[i];
    }

    DP[1] = Array[1];

    int Index = 1;

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            DP[Index + i] = max(DP[Index] + Array[Index + i], DP[Index + i]);
            DP[Index + i + 1] = max(DP[Index] + Array[Index + i + 1], DP[Index + i + 1]);
            Index++;
        }
    }

    for (int i = (TriangleArrSize - N) + 1; i <= TriangleArrSize; i++)
    {
        if (DP[i] > Max)
            Max = DP[i];
    }

    cout << Max;
}