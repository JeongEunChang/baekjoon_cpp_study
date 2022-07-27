#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <string>
#include <cstring>
#pragma warning (disable:4996)

using namespace std;

int Farm[50][50];
bool Visited[50][50];
int Result = 0;

void FindResult(int j, int k, int M, int N, int Count, int jp, int kp)
{
    if (j < 0 || k < 0 || j > N - 1|| k > M - 1)
        return;

    if (Farm[j][k] == 0)
        return;

    if (Visited[j][k] == true) // 현재 위치를 이미 방문한 적이 있을 때
        return;

    Visited[j][k] = true;

    if (j - 1 >= 0 && Farm[j - 1][k] == 1 && jp != 1) // 위이 막다른 곳인지 체크
    {
        FindResult(j - 1, k, M, N, Count + 1, -1, 0);
    }

    if (j + 1 <= N - 1 && Farm[j + 1][k] == 1 && jp != -1) // 아래쪽이 막다른 곳인지 체크
    {
        FindResult(j + 1, k, M, N, Count + 1, 1, 0);
    }

    if (k - 1 >= 0 && Farm[j][k - 1] == 1 && kp != 1) // 왼쪽이 막다른 곳인지 체크
    {
        FindResult(j, k - 1, M, N, Count + 1, 0, -1);
    }

    if (k + 1 <= M - 1 && Farm[j][k + 1] == 1 && kp != -1) // 오른쪽이 막다른 곳인지 체크
    {
        FindResult(j, k + 1, M, N, Count + 1, 0, 1);
    }

    if (Count == 0)
        Result++;
}

int main()
{
    int TestCase;
    scanf("%d", &TestCase);

    for (int i = 0; i < TestCase; i++)
    {
        int M = 0; // 가로길이 M, 세로길이 N
        int N = 0;
        int K = 0;
        Result = 0;
        memset(Farm, 0, sizeof(Farm));
        memset(Visited, false, sizeof(Visited));


        scanf("%d %d %d", &M, &N, &K);

        for (int j = 0; j < K; j++)
        {
            int Horizon;
            int Vartical;

            scanf("%d %d", &Horizon, &Vartical);

            Farm[Vartical][Horizon] = 1;
        }

        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (Farm[j][k] == 1)
                    FindResult(j, k, M, N, 0, 0, 0);
            }       
        }

        printf("%d\n", Result);
    }
}