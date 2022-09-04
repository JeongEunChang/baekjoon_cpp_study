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

    sort(Array, Array + N);

    DP[0] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = Array[i]; j <= K; j++)
        {
            DP[j] = DP[j] + DP[j - Array[i]];
        }
    }

    cout << DP[K];
}