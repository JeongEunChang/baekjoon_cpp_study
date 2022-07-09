#include <iostream>

using namespace std;

int main()
{
    int X;
    int make = 0;
    int arr[100] = { 0 };
    int k = 0;
    int stick = 64;
    int count = 0;

    cin >> X;

    while (true)
    {
        if (X == 64) {
            count = 1;
            break;
        }

        make = 0;

        stick = stick / 2;
        arr[count] = stick;
        count++;

        for (int i = 0; i < count; i++)
        {
            make += arr[i];
        }

        if (make >= X) {
            if (make == X)
                break;

            count--;
            arr[count] = 0;

        }






    }

    cout << count << endl;

    return 0;
}