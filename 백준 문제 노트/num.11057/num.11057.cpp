#include <iostream>
using namespace std;

int N;
int Answer;
int DP[10][1001];

int main()
{
    cin >> N;

    for (int i = 0; i <= 9; i++)
    {
        DP[i][1] = 1;
    }

    for (int i = 1; i <= N; i++)
    {
        DP[9][i] = 1;
    }

    for (int i = 2; i <= N; i++)
    {
        for (int j = 9 - 1; j >= 0; j--)
        {
            DP[j][i] = (DP[j][i - 1] + DP[j + 1][i]) % 10007;
        }
    }

    for (int i = 0; i <= 9; i++)
    {
        Answer += DP[i][N];
    }


    cout << Answer % 10007;
}