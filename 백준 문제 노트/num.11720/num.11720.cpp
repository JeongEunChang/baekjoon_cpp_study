#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int N;
    int Sum = 0;
    char Input[101];

    cin >> N;
    cin >> Input;

    for (int i = 0; i < N; i++)
    {
        Sum += Input[i] - '0';
    }

    cout << Sum;
}