#include <iostream>
#include <stdio.h>
#pragma warning (disable:4996)
using namespace std;

int main()
{
    int Num = 0;
    int Arr[13] = { 0 };
    bool Out = false;

    while (true)
    {
        int SelectArr[6] = { 0, 1, 2, 3, 4, 5 };
        Out = false;

        scanf("%d", &Num);
        //cin >> Num;

        if (Num == 0)
            return 0;


        for (int i = 0; i < Num; i++)
        {
            scanf("%d", &Arr[i]);
            //cin >> Arr[i];
        }

        while (!Out)
        {
            for (int i = 0; i < 6; i++)
            {
                printf("%d ", Arr[SelectArr[i]]);
                //cout << Arr[SelectArr[i]] << " ";

            }

            if (SelectArr[5] == Num - 1)
            {
                for (int i = 1; i < 6; i++)
                {
                    if (SelectArr[5 - i] != Num - i - 1)
                    {
                        SelectArr[5 - i]++;

                        for (int j = 0; j < i; j++)
                        {
                            SelectArr[5 - i + 1 + j] = SelectArr[5 - i + j] + 1;
                        }

                        break;
                    }

                    if (i == 5)
                        Out = true;
                }
            }

            else
                SelectArr[5]++;

            printf("\n");
            //cout << endl;
        }

        printf("\n");
        //cout << endl;
    }
}