#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;


int main()
{
    int N = 0;
    string Serial[50];

    cin >> N;

    for (int i = 0; i < N; i++) // 시리얼 입력 받음
    {
        cin >> Serial[i];
    }

    for (int i = 0; i < N; i++)
    {
        int shortest = 51;
        int shortestarr = 0;
        string tmp;

        for (int j = i; j < N; j++)
        {
            if (Serial[j].length() < shortest)
            {
                shortest = Serial[j].length();
                shortestarr = j;
            }
        }

        tmp = Serial[i];
        Serial[i] = Serial[shortestarr];
        Serial[shortestarr] = tmp;
    }
    
    for (int k = 0; k < N - 1; k++)
    {
        for (int i = 0; i < N - k - 1; i++)
        {
            int sum1 = 0;
            int sum2 = 0;
            string tmp;
            int tmpi;

            if (Serial[i].length() == Serial[i + 1].length()) {

                for (int j = 0; j < Serial[i].length(); j++)
                {
                    if (Serial[i][j] >= 48 && Serial[i][j] <= 57)
                    {
                        sum1 += int(Serial[i][j]) - 48;
                    }
                }

                for (int j = 0; j < Serial[i + 1].length(); j++)
                {
                    if (Serial[i + 1][j] >= 48 && Serial[i + 1][j] <= 57)
                    {
                        sum2 += int(Serial[i + 1][j]) - 48;
                    }
                }

                if (sum1 > sum2)
                {
                    tmp = Serial[i];
                    Serial[i] = Serial[i + 1];
                    Serial[i + 1] = tmp;
                }
            }
        }
    }

    for (int k = 0; k < N - 1; k++)
    {
        for (int i = 0; i < N - k - 1; i++)
        {
            int sum1 = 0;
            int sum2 = 0;
            string tmp;

            if (Serial[i].length() == Serial[i + 1].length())
            {
                for (int j = 0; j < Serial[i].length(); j++)
                {
                    if (Serial[i][j] >= 48 && Serial[i][j] <= 57)
                    {
                        sum1 += int(Serial[i][j]) - 48;
                    }
                }

                for (int j = 0; j < Serial[i + 1].length(); j++)
                {
                    if (Serial[i + 1][j] >= 48 && Serial[i + 1][j] <= 57)
                    {
                        sum2 += int(Serial[i + 1][j]) - 48;
                    }
                }

                if (sum1 == sum2)
                {
                    for (int j = 0; j < Serial[i].length(); j++)
                    {
                        if (Serial[i][j] > Serial[i + 1][j])
                        {
                            tmp = Serial[i];
                            Serial[i] = Serial[i + 1];
                            Serial[i + 1] = tmp;
                            break;
                        }

                        else if (Serial[i][j] < Serial[i + 1][j])
                            break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << Serial[i] << endl;
    }

    return 0;
}
