#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int Array[101];
int DP[10001];

int main()
{
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
    {
        cin >> Array[i];
    }

    for (int i = 1; i <= K; i++)
    {
        DP[i] = 10002;
    }

    sort(Array, Array + N);


    for (int i = 1; i <= N; i++)
    {
        for (int j = Array[i]; j <= K; j++)
        {
            DP[j] = min(DP[j], DP[j - Array[i]] + 1);
        }
    }

    if (DP[K] == 10002)
        cout << -1;

    else
        cout << DP[K];
}