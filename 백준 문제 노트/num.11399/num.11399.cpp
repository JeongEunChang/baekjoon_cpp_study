#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int PersonNum;
    int Result = 0;
    int Time = 0;
    vector<int> PersonVec;

    cin >> PersonNum;

    for (int i = 0; i < PersonNum; i++)
    {
        int Input;

        cin >> Input;

        PersonVec.push_back(Input);
    }

    sort(PersonVec.begin(), PersonVec.end());

    for (vector<int>::size_type i = 0; i < PersonVec.size(); i++)
    {
        Time += PersonVec[i];
        Result += Time;
    }

    cout << Result;
}