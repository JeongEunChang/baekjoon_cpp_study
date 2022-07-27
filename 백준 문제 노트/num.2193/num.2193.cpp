#include <iostream>
using namespace std;

long long Result = 0;
int N;

int main()
{
    cin >> N;

    int index = 2;
    long long Arr[90];
    Arr[0] = 1;
    Arr[1] = 1;

    if (N == 1)
    {
        cout << 1;
        return 0;
    }

    else if (N == 2)
    {
        cout << 1;
        return 0;
    }

    while (index <= N - 1)
    {
        Result = Arr[index - 1] + Arr[index - 2];
        Arr[index] = Result;
        index++;
    }

    cout << Result;
}