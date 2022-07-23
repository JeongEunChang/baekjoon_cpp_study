#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <math.h>
#pragma warning (disable:4996)
using namespace std;

bool Eratos[5000];
set<int> s_RelocateNum;
set<string> CheckSame;
vector<int> EndCheck;
int Result;
bool Check[10000002];
//string MadeValue;

bool CheckPrimeNumber(int Value)
{
    if (Value == 1 || Value == 0)
        return false;

    int Checking = (int)sqrt(Value);

    /*for (int i = 2; i < Checking; i++)
    {
        for (int j = 2; j * i <= Checking; j++)
        {
            if (Eratos[i * j] == true)
            {
                continue;
            }

            else
            {
                Eratos[i * j] = true;
            }
        }
    }*/

    for (int i = 2; i <= Checking; i++)
    {
        if (Eratos[i] == false)
        {
            if (Value % i == 0)
                return false;
        }
    }

    return true;
}

void MakeNumber(int Now, int Length, string Input, string MadeValue, bool Visited[])
{
    if (Now == Length)
    {
        /*if (CheckPrimeNumber(stoi(MadeValue)))
            Result++;*/

        if (Check[stoi(MadeValue)] != true)
        {
            int tmp = stoi(MadeValue);
            Check[tmp] = true;
            //s_RelocateNum.insert(stoi(MadeValue));
            
            if (CheckPrimeNumber(tmp))
                Result++;

            return;
        }

        //s_RelocateNum.insert(stoi(MadeValue));
        return;
    }

    for (int i = 0; i < Input.length(); i++)
    {
        if (Visited[i])
            continue;

        Visited[i] = true;
        MadeValue.push_back(Input[i]);

        //CheckSame.insert(MadeValue);

        MakeNumber(Now + 1, Length, Input, MadeValue, Visited);
        Visited[i] = false;
        MadeValue.pop_back();
    }
}

// 기존에 Set을 통해 중복 체크 했던 것
// 마지막에 Set을 순회하면서 정답 체크했던 것
// 에라토스 테네스의 체를 매번 구했던 것

int main()
{
    for (int i = 2; i < 3200; i++)
    {
        for (int j = 2; j * i <= 3200; j++)
        {
            if (Eratos[i * j] == true)
            {
                continue;
            }

            else
            {
                Eratos[i * j] = true;
            }
        }
    }

    int TestCase;
    scanf("%d", &TestCase);

    for (int k = 0; k < TestCase; k++)
    {
        //string Input;
        char cInput[10];
        scanf("%s", cInput);
        string Input = cInput;
        //cin >> Input;

        Result = 0;

        for (int i = 1; i <= Input.length(); i++)
        {
            string MadeValue;
            bool Visited[7] = { false };
            MakeNumber(0, i, Input, MadeValue, Visited);
            CheckSame.clear();
        }

        /*for (int i : s_RelocateNum)
        {
            if (CheckPrimeNumber(i))
                Result++;
        }*/
        printf("%d\n", Result);
        memset(Check, 0, sizeof(Check));
        /*s_RelocateNum.clear();*/
    }
}