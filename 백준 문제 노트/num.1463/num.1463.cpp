#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int Array[1000001];
int DP[1000001];
int N;

int main()
{
    cin >> N;

    DP[0] = INT_MAX - 1;
    DP[1] = 0;
    DP[2] = 1;

    for (int i = 3; i <= N; i++)
    {
        int a = 0;
        int b = 0;
        int tmp = 0;

        if (i % 2 == 0)
            a = i / 2;

        if (i % 3 == 0)
            b = i / 3;

        tmp = min(DP[a] + 1, DP[b] + 1);

        DP[i] = min(tmp, DP[i - 1] + 1);
    }

    cout << DP[N];
}
