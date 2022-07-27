#include <iostream>
using namespace std;

int main()
{
    int Arr[9];
    int Biggest = 0;
    int IndexBigest = 0;

    for (int i = 0; i < 9; i++)
    {
        cin >> Arr[i];

        if (Arr[i] > Biggest)
        {
            Biggest = Arr[i];
            IndexBigest = i + 1;
        }
    }

    cout << Biggest << endl << IndexBigest;
}