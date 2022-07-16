#include <iostream>

using namespace std;

int main()
{
    int TestCase;

    cin >> TestCase;

    for (int i = 0; i < TestCase; i++)
    {
        int ResultPrice = 0;
        int BasicPrice;
        int OptionNum;

        cin >> BasicPrice;
        cin >> OptionNum;

        ResultPrice += BasicPrice;

        for (int j = 0; j < OptionNum; j++)
        {
            int Count;
            int OptionPrice;

            cin >> Count >> OptionPrice;

            ResultPrice += (Count * OptionPrice);
        }

        cout << ResultPrice << endl;
    }
}