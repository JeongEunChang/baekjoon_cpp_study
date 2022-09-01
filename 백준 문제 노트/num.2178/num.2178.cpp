#include <iostream>
#include <stdio.h>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;

int Array[102][102];
int Visited[102][102];
int N, M;
int Result = 10500;

void FindResult(int X, int Y, int Scalar_X, int Scalar_Y, int Count)
{
    if (Array[Y][X] == 0)
        return;

    if (X == M - 1 && Y == N - 1)
    {
        if (Count < Result)
        {
            Result = Count;
            return;
        }
    }
    

    if (Visited[Y][X] == 0 || Visited[Y][X] > Count)
    {
        Visited[Y][X] = Count;
    }

    else
        return;
    

    if (Scalar_X != 1 && X - 1 != -1 )
    {
        FindResult(X - 1, Y, -1, 0, Count + 1);
    }

    if (Scalar_X != -1 && X + 1 != M)
    {
        FindResult(X + 1, Y, 1, 0, Count + 1);
    }

    if (Scalar_Y != 1 && Y - 1 != -1)
    {
        FindResult(X, Y - 1, 0, -1, Count + 1);
    }

    if (Scalar_Y != -1 && Y + 1 != N)
    {
        FindResult(X, Y + 1, 0, 1, Count + 1);
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%1d", &Array[i][j]);
        }
    }

    FindResult(0, 0, 0, 0, 1);

    cout << Result;
}