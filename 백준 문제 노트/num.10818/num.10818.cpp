#include <iostream>
using namespace std;

int main()
{
    int N;
    int Biggest = -1000001;
    int Smallest = 1000001;

    cin >> N;

    while (N--)
    {
        int Input;
        cin >> Input;

        if (Input > Biggest)
            Biggest = Input;

        if (Input < Smallest)
            Smallest = Input;
    }

    /*for (int i = 0; i < N; i++)
    {
        int Input;
        cin >> Input;

        if (Input > Biggest)
            Biggest = Input;

        if (Input < Smallest)
            Smallest = Input;
    }*/

    cout << Smallest << " " << Biggest;
}
