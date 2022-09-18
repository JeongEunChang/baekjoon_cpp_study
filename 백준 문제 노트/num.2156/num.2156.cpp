#include <iostream>
#include <algorithm>
using namespace std;

int N, Answer;
int Array[10001];
int DP[10001];

int main()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> Array[i];
    }

    DP[1] = Array[1];
    DP[2] = Array[1] + Array[2];

    for (int i = 3; i <= N; i++)
    {
        for (int j = 0; j <= i - ; j++)
        {
            DP[i] = max(DP[j] + Array[i - 1] + Array[i], DP[i]);
            DP[i] = max(DP[j] + Array[i], DP[i]);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        Answer = max(Answer, DP[i]);
    }

    cout << Answer;
}