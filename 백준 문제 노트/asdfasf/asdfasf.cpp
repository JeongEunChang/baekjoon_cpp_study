#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int Wine[1000];
    int DP[1000];

    int fianlAnswer;

    for (int i = 1; i <= n; i++) {
        cin >> Wine[i];
    }

    DP[0] = 0;
    DP[1] = Wine[1];
    DP[2] = Wine[1] + Wine[2];

    for (int i = 3; i <= n; i++) {
        int answer1 = DP[i - 3] + Wine[i - 1] + Wine[i];
        int answer2 = DP[i - 2] + Wine[i];
        int answer3 = DP[i - 1];
        int temp = max(answer1, answer2);
        DP[i] = max(temp, answer3);
    }

    cout << DP[n];
}