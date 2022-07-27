#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;

int Result[500];
int A_Size;
int B_Size;
int C_Size;
int Count = 1;

void FindResult(int A, int B, int C, char Pre_p, char Pre_s)
{
    if (A == 0 && Count != 1)
    {
        if (Result[C] != -1)
            return;

        Result[C] = C;
        printf("%d", Result[C]);
        return;
    }

    Count++;

    if (Pre_p != 'B' && Pre_s != 'A' && A != 0) // A -> B, Pre B - Now A 가 아닐 때
    {
        B += A;

        if (B > B_Size)
        {
            A = B - B_Size;
            B = B_Size;
        }
        
        else
            A = 0;

        FindResult(A, B, C, 'A', 'B');
    }

    if (Pre_p != 'C' && Pre_s != 'A' && A != 0) // A -> C, Pre C - Now A 가 아닐 때
    {
        C += A;

        if (C > C_Size)
        {
            A = C - C_Size;
            C = C_Size;
        }

        else
            A = 0;

        FindResult(A, B, C, 'A', 'C');
    }

    if (Pre_p != 'A' && Pre_s != 'B' && B != 0) // B -> A, 전 연산이 A -> B 가 아닐 때
    {
        A += B;

        if (A > A_Size)
        {
            B = A - A_Size;
            A = A_Size;
        }

        else
            B = 0;

        FindResult(A, B, C, 'B', 'A');
    }

    if (Pre_p != 'C' && Pre_s != 'B' && B != 0) // B -> C, 전 연산이 C -> B 가 아닐 때
    {
        C += B;

        if (C > C_Size)
        {
            B = C - C_Size;
            C = C_Size;
        }

        else
            B = 0;

        FindResult(A, B, C, 'B', 'C');
    }

    if (Pre_p != 'A' && Pre_s != 'C' && C != 0) // C -> A, 전 연산이 A -> C 가 아닐 때
    {
        A += C;

        if (A > A_Size)
        {
            C = A - A_Size;
            A = A_Size;
        }

        else
            A = 0;

        FindResult(A, B, C, 'C', 'A');
    }

    if (Pre_p != 'B' && Pre_s != 'C' && C != 0) // C -> B, 전 연산이 B -> C 가 아닐 때
    {
        B += C;

        if (B > B_Size)
        {
            C = B - B_Size;
            B = B_Size;
        }

        else
            C = 0;

        FindResult(A, B, C, 'C', 'B');
    }
}

int main()
{
    // 모든 이동 경우의 수를 재귀함수로 전체 탐색
    // A가 0이 되면 리턴하고 해당 값을 추가
    // 결과를 저장하는 배열 생성, 인덱스 번호 = 값 방식을 통해 접근
    //전에 했던 연산을 기억해서, A->B 로 갔을 때 B->A 로 가지 않도록 제한해주기
    int A = 0;
    int B = 0;
    int C = 0;
    memset(Result, -1, sizeof(Result));

    scanf("%d %d %d", &A, &B, &C);

    A_Size = A;
    B_Size = B;
    C_Size = C;

    FindResult(0, 0, C, NULL, NULL);

    sort(Result, Result + 200);

    for (int i = 0; i < 200; i++)
    {
        if (Result[i] != -1)
            printf("%d ", Result[i]);

    }

}