#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int InputTime;
    int Arr[1003] = { 0 };

    cin >> InputTime;

    for (int i = 0; i < InputTime; i++)
    {
        int InputValue;

        cin >> InputValue;

        Arr[i] = InputValue;
    }

    sort(Arr, Arr + InputTime);

    for (int i = 0; i < InputTime; i++)
    {
        cout << Arr[i] << endl;
    }
}
