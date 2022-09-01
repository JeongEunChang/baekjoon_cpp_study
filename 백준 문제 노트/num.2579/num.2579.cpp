#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int Array[301];
int DP[301];
int Stairs;

int main()
{
    cin >> Stairs;

    for (int i = 1; i <= Stairs; i++)
    {
        cin >> Array[i];
    }

    if (Stairs == 1)
    {
        DP[Stairs] = Array[1];
    }

    else if (Stairs == 2)
    {
        DP[Stairs] = Array[1] + Array[2];
    }
    
    else
    {
        DP[0] = 0;
        DP[1] = Array[1];
        DP[2] = Array[1] + Array[2];

        for (int i = 3; i <= Stairs; i++)
        {
            DP[i] = max(DP[i - 3] + Array[i - 1] + Array[i], DP[i - 2] + Array[i]);
        }
    }  

    std::cout << DP[Stairs];
}