#include <iostream>
using namespace std;

int N, Answer;
long long DP[101][10];

int main()
{
    cin >> N;

    for (int i = 1; i <= 9; i++)
    {
        DP[1][i] = 1;
    }

    for (int i = 2; i <= N; i++)
    {
        DP[i][0] = DP[i - 1][1] % 1000000000;
        DP[i][9] = DP[i - 1][8] % 1000000000;

        for (int j = 1; j <= 8; j++)
        {
            DP[i][j] = (DP[i - 1][j - 1] % 1000000000)+ (DP[i - 1][j + 1] % 1000000000);
        }
    }

    for (int i = 0; i <= 9; i++)
    {
        Answer = (Answer + DP[N][i]) % 1000000000;
    }

    cout << Answer % 1000000000;
}