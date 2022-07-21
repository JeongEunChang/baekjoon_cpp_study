#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    int Sum = 0;
    int A[51];
    int B[51];

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }

    sort(A, A + N);
    sort(B, B + N, greater<>());

    for (int i = 0; i < N; i++)
    {
        Sum += A[i] * B[i];
    }

    cout << Sum;
}