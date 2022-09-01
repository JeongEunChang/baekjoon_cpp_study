#include <iostream>
#include <vector>
using namespace std;

vector<int> vArray[101];
int N, M;
int BaconNum[101][101];
int ResultBaconNum[101];

void FindResult(int People, int NowPeople, int Count)
{
    if (People == NowPeople && Count != 0)
        return;

    if (BaconNum[People][NowPeople] == 0 && Count != 0)
    {
        BaconNum[People][NowPeople] = Count;
        BaconNum[NowPeople][People] = Count;
    }

    else if (BaconNum[People][NowPeople] > Count) 
    {
        BaconNum[People][NowPeople] = Count;
        BaconNum[NowPeople][People] = Count;
    }

    else if (BaconNum[People][NowPeople] < Count)
        return;

    for (int i = 1; i <= vArray[NowPeople].size() - 1; i++)
    {
        FindResult(People, vArray[NowPeople][i], Count + 1);
    }
}

int main()
{
    cin >> N >> M;
    int Result = 100000;
    int ResultP = 0;

    for (int i = 1; i <= N; i++)
    {
        vArray[i].push_back(101);
    }

    for (int i = 1; i <= M; i++)
    {
        int A, B;
        cin >> A >> B;

        vArray[A].push_back(B);
        vArray[B].push_back(A);
    }


    for (int i = 1; i <= N; i++)
    {
        FindResult(i, i, 0);

        int Sum = 0;
        for (int j = 1; j <= N; j++)
        {
            Sum += BaconNum[i][j];
        }
        ResultBaconNum[i] = Sum;
    }

    for (int i = 1; i <= N; i++)
    {
        if (ResultBaconNum[i] < Result)
        {
            Result = ResultBaconNum[i];
            ResultP = i;
        }

        else if (ResultBaconNum[i] == Result)
        {
            if (ResultP > i)
                ResultP = i;
        }
    }

    cout << ResultP;
}