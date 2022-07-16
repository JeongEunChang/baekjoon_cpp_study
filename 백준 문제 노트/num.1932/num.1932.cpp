#include <iostream>
#include <stdio.h>
#pragma warning (disable:4996)

using namespace std;

int Arr[126000];
int vec[126000];
int tmp;

void MakeResultArr(int NowNode, int Sum, int Count, int& Result)
{
    Sum += vec[NowNode];

    if ((NowNode + Count) > tmp - 1)
    {
        if (Sum > Result)
            Result = Sum;
        return;
    }

    if (Arr[NowNode] == 0)
    {
        Arr[NowNode] = Sum;
    }

    else if (Arr[NowNode] != 0)
    {
        if (Arr[NowNode] < Sum)
        {
            Arr[NowNode] = Sum;
        }

        else
            return;
    }

    Count++;

    MakeResultArr(NowNode + Count, Sum, Count, Result);
    MakeResultArr(NowNode + Count + 1, Sum, Count, Result);
}

int main()
{
    int TriangleSize = 0;
    int Sum = 0;
    int Count = 0;
    int NowNode = 0;
    int Result = 0;
    
    scanf("%d", &TriangleSize);

    for (int i = 1; i <= TriangleSize; i++)
    {
        tmp += i;
    }

    for (int i = 0; i < tmp; i++)
    {
        int Input;

        scanf("%d", &Input);

        vec[i] = Input;
    }

    MakeResultArr(NowNode, Sum, Count, Result);

    

    printf("%d", Result);
}