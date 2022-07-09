#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int arr[100];
    int N = 0;
    int M = 0;

    int Result = 0;

    //scanf("%d %d", &N, &M);
    cin >> N >> M;

    for (int i = 0; i < N; i++) 
    {
        cin >> arr[i];
    }


    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (arr[i]>= M)
                break;


            for (int k = j + 1; k < N; k++)
            {
                if (arr[i] + arr[j] >= M)
                    break;

                else if (arr[i] + arr[j] + arr[k] == M) 
                {
                    Result = M;
                    printf("%d", Result);
                    return 0;
                }

                else if (arr[i] + arr[j] + arr[k] < M && arr[i] + arr[j] + arr[k] > Result)
                {
                    Result = arr[i] + arr[j] + arr[k];
                }
            }
        }
    }

    if (Result == 0)
        return 0;

    else if (Result != 0)
        printf("%d", Result);
    
    return 0;
}
