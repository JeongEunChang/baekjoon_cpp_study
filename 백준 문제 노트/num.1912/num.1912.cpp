#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int N;
int Answer = INT_MIN;
int Array[100001];
int DP[100001];

int main()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> Array[i];
    }

    DP[1] = Array[1];

    for (int i = 2; i <= N; i++)
    {
        DP[i] = max(DP[i - 1] + Array[i], Array[i]);
    }

    for (int i = 1; i <= N; i++)
    {
        Answer = max(DP[i], Answer);
    }

    cout << Answer;
}