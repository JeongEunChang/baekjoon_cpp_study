// asdfasdfsadf.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>

using namespace std;

void Sum(int a, int b, int& Sum)
{
    Sum = (a + b);
}


int main()
{
    int a = 5;
    int b = 3;

    int sum = 0;
    int as[500];

    for (int i = 1; i < 501; i++)
    {
        sum += i;
    }

    cout << sum;

    //cout << a[A - 65];


}