#include <iostream>
#include <vector>

using namespace std;
// 3 12 3     4  5
int StairsNum;
vector<int> vec;
int Arr[1000][5000];
int Result;

void FindResult(int Sum, int Now, int OverlapCount, int NodeCount)
{
    NodeCount++;

    if (Now > StairsNum)
    {
        return;
    }
    Sum += vec[Now];
    OverlapCount++;

    if (OverlapCount != 3)
    {
        if (Now == StairsNum)
        {
            if (Result < Sum)
                Result = Sum;

            return;
        }

        if (Arr[Now][NodeCount] == 0)
            Arr[Now][NodeCount] = Sum;

        else if (Arr[Now][NodeCount] != 0)
        {
            if (Arr[Now][NodeCount] < Sum)
                Arr[Now][NodeCount] = Sum;

            else
                return;
        }
        FindResult(Sum, Now + 1, OverlapCount, NodeCount);

        FindResult(Sum, Now + 2, 0, NodeCount);
    }

    else if (OverlapCount == 3)
    {
        return;
    }
}

int main()
{
    cin >> StairsNum;
    vec.push_back(0);

    int Sum = 0;
    int OverlapCount = -1;

    for (int i = 0; i < StairsNum; i++)
    {
        int Input;

        cin >> Input;

        vec.push_back(Input);
    }


    FindResult(Sum, 0, OverlapCount, -1);

    std::cout << Result;
}