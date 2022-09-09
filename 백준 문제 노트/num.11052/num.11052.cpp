#include <iostream>
#include <algorithm>
using namespace std;

int N;
int Array[1001];
int DP[1001];

int main()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> Array[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            DP[i] = max(DP[i], DP[i - j] + Array[j]);
        }
    }

    cout << DP[N];
}