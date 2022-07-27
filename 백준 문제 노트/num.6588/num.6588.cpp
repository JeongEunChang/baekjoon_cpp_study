#include <iostream>
#include <stdio.h>
#pragma warning (disable:4996)
using namespace std;

int Eratos[1000001];

void PrintResult(int n)
{
    int SmallResult = 0;
    int LargeResult = 0;

    int First = 0;
    int Last = 1000000;
    First = 1;

    while (First <= Last)
    {
        Last = n;

        while (true)
        {
            First++;

            if (Eratos[First] == 0)
                break;
        }

        while (true)
        {
            if (Eratos[Last] == 0)
            {
                if (First + Last == n)
                {
                    SmallResult = First;
                    LargeResult = Last;
                    printf("%d = %d + %d\n", n, SmallResult, LargeResult);
                    return;
                }

                else if (First + Last < n)
                    break;
            }

            Last--;
        }

    }

    if (SmallResult == 0 && LargeResult == 0)
    {
        printf("Goldbach's conjecture is wrong.\n");
    }
}


int main()
{
    for (int i = 2; i < 500001; i++) // 에라토스테네스의 체를 이용하여 소수 찾기
    {
        for (int j = 2; i * j <= 1000000; j++)
        {
            if (Eratos[i * j] == 1)
                continue;

            Eratos[i * j] = 1;
        }
    }


    while (true)
    {
        int n;
        scanf("%d", &n);

        if (n == 0)
            return 0;

        PrintResult(n);
    }
}