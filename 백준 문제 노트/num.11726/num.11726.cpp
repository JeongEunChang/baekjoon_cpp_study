#include <iostream>
using namespace std;

int N;
int DP[1001];

int main()
{
    cin >> N;

    DP[0] = 1;
    DP[1] = 1;

    for (int i = 2; i <= N; i++)
    {
        DP[i] = DP[i - 1] % 10007 + DP[i - 2] % 10007;
    }

    cout << DP[N] % 10007;
}