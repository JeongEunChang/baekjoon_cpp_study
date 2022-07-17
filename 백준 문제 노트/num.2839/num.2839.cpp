#include <iostream>
#include <stdio.h>
#pragma warning (disable:4996)
using namespace std;

int main()
{
    int N = 0;

    scanf("%d", &N);
    int tmp = (5 - (N % 5)) + N;

    if (N % 5 == 0)
    {
        printf("%d", N / 5);
        return 0;
    }

    else
    {
        while (tmp > 0)
        {
            tmp -= 5;

            if ((N - tmp) % 3 == 0)
            {
                printf("%d", (tmp / 5) + ((N - tmp) / 3));
                return 0;
            }
        }
    }

    printf("%d", -1);
}