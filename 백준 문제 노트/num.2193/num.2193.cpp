#include <iostream>

using namespace std;

long long Result = 0;
int N;
int Arr[91];

void FindResult(int Count, int Index, int Value, int PreValue)
{
    if (Index >= N - 1)
    {
        Result++;
        return;
    }

    Arr[Index];

    int Next;

    if (Value == 1)
    {
        Next = 0;
    }

    else
        Next = 1;

    FindResult(Count, Index + 1, 0, Value);
}


int main()
{
    cin >> N;

    FindResult(0, 1, 0, 0);

    cout << Result;
}