#include <iostream>
#include <algorithm>
using namespace std;

int Array[1001][1001];
int DP[1001][1001];
int N, M;

int main()
{
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> Array[i][j];
        }
    }

    DP[1][1] = Array[1][1];

    for (int i = 2; i <= N; i++)
    {
        DP[i][1] = DP[i - 1][1] + Array[i][1];
    }

    for (int i = 2; i <= M; i++)
    {
        DP[1][i] = DP[1][i - 1] + Array[1][i];
    }

    for (int i = 2; i <= N; i++)
    {
        for (int j = 2; j <= M; j++)
        {
            DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]) + Array[i][j];
        }
    }

    cout << DP[N][M];
}