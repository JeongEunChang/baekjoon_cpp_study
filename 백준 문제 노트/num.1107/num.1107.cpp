#include <set>
#include < math.h>
#include <iostream>

using namespace std;

int main()
{
    int Channel;
    int BrokenBotton;
    int BrokenChannel = 0;
    int ClickCount = 0;
    int Channel_0_Count = -1;
    int High_0 = 1;
    set<int> s;

    cin >> Channel;
    cin >> BrokenBotton;

    for (int i = 0; i < 10; i++)
    {
        s.insert(i);
    }

    for (int i = 0; i < BrokenBotton; i++)  
    {
        int Input;
        cin >> Input;
        s.erase(Input);
    }

    for (int i = Channel; i > 0; i /= 10)
    {
        Channel_0_Count++;
    }

    for (int i = 0; i < Channel_0_Count; i++)
    {
        High_0 *= 10;
    }


    int Lasttmp = Channel;
    
    for (int i = High_0; i > 0; i /= 10)
    {
        int tmp = Lasttmp / i;

        int tmpArr[12] = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
        int Shortest1 = 10;
        int Shortest2 = 11;

        for (int j : s)
        {
            tmpArr[j] = abs(tmp - j);

            if (abs(tmp - j) < tmpArr[Shortest1])
                Shortest1 = j;

            else if (abs(tmp - j) == tmpArr[Shortest1])
                Shortest2 = j;
        }

        if (Shortest1 == 10 && Shortest2 == 11)
        {
            tmpArr[Shortest1] = 0;
            tmpArr[Shortest2] = 0;
        }

        if (Shortest1 == Shortest2)
        {
            if (Channel - (Shortest1 * i) < Channel - (Shortest2 * i))
                Shortest1 = Shortest1;

            else if (Channel - (Shortest1 * i) > Channel - (Shortest2 * i))
                Shortest1 = Shortest2;
        }

        BrokenChannel += (i * Shortest1);
        ClickCount++;

        Lasttmp -= tmp * i;
    }

    cout << abs(BrokenChannel - Channel) + ClickCount;
}