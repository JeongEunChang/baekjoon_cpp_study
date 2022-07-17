#include <iostream>
#include <cstring>
#include <stdio.h>
#pragma warning (disable:4996)
using namespace std;

int main()
{
    int TestCase;
    int Arr[21] = {0};
    char Input[7];
    int Value = 0;

    scanf("%d", &TestCase);

    for (int i = 0; i < TestCase; i++)
    {
        scanf("%s", Input);

        if (!strcmp(Input, "add"))
        {
            scanf("%d", &Value);

            if (Arr[Value] == 0)
                Arr[Value] = Value;
        }

        else if (!strcmp(Input, "remove"))
        {
            scanf("%d", &Value);

            if (Arr[Value] != 0)
                Arr[Value] = 0;
        }

        else if (!strcmp(Input, "check"))
        {
            scanf("%d", &Value);

            if (Arr[Value] == 0)
                printf("%d\n", 0);

            else
                printf("%d\n", 1);
        }

        else if (!strcmp(Input, "toggle"))
        {
            scanf("%d", &Value);

            if (Arr[Value] == 0)
                Arr[Value] = Value;

            else
                Arr[Value] = 0;
        }

        else if (!strcmp(Input, "all"))
        {
            for (int i = 1; i <= 20; i++)
            {
                Arr[i] = i;
            }

        }

        else if (!strcmp(Input, "empty"))
        {
            for (int i = 1; i <= 20; i++)
            {
                Arr[i] = 0;
            }
        }
    }
}