#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int N = 0;
    int Arr[8] = { 0 };
    int Result = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> Arr[i];
    }

    sort(Arr, Arr + N);

    if (N % 2 == 0)
    {
        int Front = 0;
        int End = N - 1;
        int Count = 0;

        while (true)
        {
            Result += abs(Arr[Front] - Arr[End]);

            if (Front == N / 2 - 1)
            {
                break;
            }

            Result += abs(Arr[Front] - Arr[End - 1]);

            Front++;
            Count++;

            if (Count == 2)
            {
                End -= 2;
                Count = 0;
            }
        }
    }

    if (N % 2 == 1)
    {
        int Front = 0;
        int End = N - 1;
        int Count = 0;

        while (true)
        {
            Result += abs(Arr[Front] - Arr[End]);

            if (Front == N / 2 - 1)
            {
                if (abs(Arr[N / 2] - Arr[N / 2 + 1]) > abs(Arr[N / 2] - Arr[N / 2 - 1]))
                {
                    Result += abs(Arr[N / 2] - Arr[N / 2 + 1]);
                    break;
                }

                else if (abs(Arr[N / 2] - Arr[N / 2 + 1]) <= abs(Arr[N / 2] - Arr[N / 2 - 1]))
                {
                    Result += abs(Arr[N / 2] - Arr[N / 2 - 1]);
                    break;
                }
            }

            Result += abs(Arr[Front] - Arr[End - 1]);

            Front++;
            Count++;

            if (Count == 2)
            {
                End -= 2;
                Count = 0;
            }
        }
    }

    cout << Result;
}