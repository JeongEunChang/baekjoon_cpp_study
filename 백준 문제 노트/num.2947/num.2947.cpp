#include <iostream>

using namespace std;

int main()
{
    int a[5] = { 0 };
    int tmp;

    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];

    while (true)
    {
        for (int i = 0; i < 4; i++) {
            if (a[i] > a[i + 1]) {
                tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;

                for (int i = 0; i < 5; i++) {
                    cout << a[i] << " ";
                    }

                cout << endl;
            }
        }

        if (a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5)
            break;
    }

    return 0;
}

