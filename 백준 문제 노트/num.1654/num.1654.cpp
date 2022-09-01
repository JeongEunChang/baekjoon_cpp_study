#include <iostream>
#include <vector>
using namespace std;

int K, N;
vector<long> v;
long long Result;

void FindResult(int Standard)
{
    long long First = 0;
    long long Mid = (First + Standard) / 2;
    long long End = Standard;

    while (First <= End)
    {
        if (Mid == 0)
        {
            Mid = 1;
            break;
        }

        int Count = 0;

        for (int i = 0; i < v.size(); i++)
        {
            Count += v[i] / Mid;
        }

        if (Count >= N)
        {
            First = Mid + 1;
            Mid = (First + End) / 2;
            continue;
        }

        else if (Count < N)
        {
            End = Mid - 1;
            Mid = (First + End) / 2;
            continue;
        }
    }

    Result = Mid;
}


int main()
{
    long long Standard = 0;

    cin >> K >> N;

    for (int i = 0; i < K; i++)
    {
        int Input;
        cin >> Input;

        v.push_back(Input);

        Standard += Input;
    }

    Standard /= N;


    FindResult(Standard);

    cout << Result;
}