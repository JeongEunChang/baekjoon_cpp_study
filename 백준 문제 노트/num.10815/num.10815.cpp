#include <stdio.h>
#include <cmath>
#pragma warning (disable:4996)
using namespace std;

int Array_N[10000001][2];
int Array_M[500000];

int main()
{
    int N;
    int M;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int tmp;
        
        scanf("%d", &tmp);

        if (tmp < 0)
        {
            Array_N[abs(tmp)][0] = tmp;
        }

        else
        {
            Array_N[tmp][1] = tmp;
        }
    }

    scanf("%d", &M);

    for (int i = 0; i < M; i++)
    {
        scanf("%d", &Array_M[i]);
    }

    for (int i = 0; i < M; i++)
    {
        int tmp = Array_M[i];

        if (tmp < 0)
        {
            if (Array_N[abs(tmp)][0] != 0)
            {
                printf("%d ", 1);
                continue;
            }

            else
            {
                printf("%d ", 0);
                continue;
            }
        }

        else
        {
            if (Array_N[tmp][1] != 0)
            {
                printf("%d ", 1);
                continue;
            }

            else
            {
                printf("%d ", 0);
                continue;
            }
        }
    }
}
