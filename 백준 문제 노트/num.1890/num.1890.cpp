#include <iostream>
using namespace std;

int N;
int Array[101][101];
int DP[101][101];

int main()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> Array[i][j];
        }
    }

    DP[1 + Array[1][1]][1] = 1;
    DP[1][1 + Array[1][1]] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == 1 && j == 1)
                continue;

            if (i == N && j == N)
                continue;

            if (DP[i][j] == 0)
            {
                continue;
            }

            if (i + Array[i][j] <= N)
            {
                DP[i + Array[i][j]][j] += DP[i][j];              
            }

            if (j + Array[i][j] <= N)
            {
                DP[i][j + Array[i][j]] += DP[i][j];
            }
        }
    }

    cout << DP[N][N];
}