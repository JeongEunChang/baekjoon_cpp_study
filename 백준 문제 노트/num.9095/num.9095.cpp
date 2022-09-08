#include <iostream>
using namespace std;

int DP[12];

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int Input;

        cin >> Input;

        DP[1] = 1;
        DP[2] = 2;
        DP[3] = 4;

        for (int i = 4; i <= Input; i++)
        {
            DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
        }

        cout << DP[Input] << endl;
    }
}