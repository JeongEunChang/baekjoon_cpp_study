#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#pragma warning (disable:4996)
using namespace std;

int Array[20][20];
int a_People[20];
vector<int> Team_Odd;
vector<int> Team_Even;
int Horizon_Member[20];
int Vartical_Member[20];
int MemberScore[20][20];
bool Horizon_Visited[20];
bool Vartical_Visited[20];

void FindResult(int TeamNumber)
{
    for (int i = 0; i < N / 2; i++)
    {
        People.
    }
}

int main()
{
    int N;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &Array[i][j]);
        }
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (Horizon_Visited[j] == true)
                continue;

            if (Vartical_Visited[i] == true)
                continue;

            MemberScore[i] += Array[i][j];
            MemberScore[j] += Array[i][j];

            Horizon_Visited[j] = true;
        }

        Vartical_Visited[i] = true;
        memset(Horizon_Visited, true, sizeof(Horizon_Visited));
    }

    int MemeberLimit = N / 2;

    for (int i = 0; i < MemeberLimit / 2; i++)
    {

    }

    // 배열 내에서 같은 값 처리해주기
    // 모든 경우의 수에 점수를 저장
    // 저장된 점수를 비교하며 최솟값 탐색
    std::cout << "Hello World!\n";
}