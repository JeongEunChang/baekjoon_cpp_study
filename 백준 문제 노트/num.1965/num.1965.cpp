#include <iostream>
#include <cmath>
using namespace std;

int N, Answer;
int Array[1001];
int DP[1001];

int main()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> Array[i];
    }

    DP[1] = 1;

    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (Array[i] > Array[j])
            {
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }

        if (DP[i] == 0)
            DP[i] = 1;
    }
    
    for (int i = 1; i <= N; i++)
    {
        Answer = max(Answer, DP[i]);
    }

    cout << Answer;
}