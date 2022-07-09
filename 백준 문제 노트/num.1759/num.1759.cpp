#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


//1. 입력 받은 값에서 소문자 대문자 구분
//2.


//아스키 코드값으로 비교해서, 다음에 오는 문자를 제한해서 자동적으로 정렬되도록 구현

//소문자, 대문자 카운트 적용
int main()
{
    int WordLength;
    int Alp;
    //char Capital[20] = { NULL };
    //char Small[20] = { NULL };
    char Input[20] = { NULL };
    string Code[2000];
    int arr[20] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };

    cin >> WordLength >> Alp;
    

    for (int i = 0; i < Alp; i++)
    {
        char tmp;
        cin >> tmp;

        Input[i] = tmp;

        /*if (tmp == 'i' || tmp == 'a' || tmp == 'e' || tmp == 'o' || tmp == 'u')
        {
            Small[SmallCount] = tmp;
            SmallCount++;
        }

        else
        {
            Capital[CapitalCount] = tmp;
            CapitalCount++;
        }*/
    }
    
    sort(Input, Input + Alp);
        
    while (true)
    {
        int CapitalCount = 0;
        int SmallCount = 0;
        char WordArr[15] = { NULL };

        for (int i = 0; i < WordLength; i++)
        {
            if (Input[arr[i]] == 'i' || Input[arr[i]] == 'a' || Input[arr[i]] == 'e' || Input[arr[i]] == 'o' || Input[arr[i]] == 'u')
                SmallCount++;

            else
                CapitalCount++;

            WordArr[i] = Input[arr[i]];
        }

        if (SmallCount >= 1 && CapitalCount >= 2)
            cout << WordArr << endl;

        if (arr[WordLength - 1] == Alp - 1)
        {
            bool out = false;

            if (arr[WordLength - 1] - arr[WordLength - 2] != 1)
            {
                arr[WordLength - 2]++;
                arr[WordLength - 1] = arr[WordLength - 2] + 1;
            }

            else
            {
                for (int i = WordLength - 2; i > 0; i--)
                {

                    if (arr[i] - 1 != arr[i - 1])
                    {
                        arr[i - 1]++;

                        for (int q = i - 1; q < WordLength - 1; q++)
                        {
                            arr[q + 1] = arr[q] + 1;
                        }

                        break;
                    }

                    if (i == 1)
                    {
                        out = true;
                    }
                }

                if (out == true)
                {
                    break;
                }
            }
        }

        else
            arr[WordLength - 1]++;
    }
}