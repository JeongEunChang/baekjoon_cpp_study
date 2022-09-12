#include <iostream>
#include <algorithm>
using namespace std;

int A, Answer;
int Array[1001];
int DP[1001];

int main()
{
    cin >> A;

    for (int i = 1; i <= A; i++)
    {
        cin >> Array[i];
    }

    for (int i = 1; i <= A; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (Array[j] < Array[i])
            {
                DP[i] = max(DP[j] + 1, DP[i]);
            } 
        }
    }

    for (int i = 1; i <= A; i++)
    {
        if (DP[i] > Answer)
            Answer = DP[i];
    }

    cout << Answer;
}