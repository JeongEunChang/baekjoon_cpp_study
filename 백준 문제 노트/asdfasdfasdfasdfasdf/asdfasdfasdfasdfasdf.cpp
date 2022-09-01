#include <iostream>
#include <vector>
using namespace std;

int n;
int Time[16];
int Pay[16];
int ResultTime;
int ResultPay;
int tmpTime;
int tmpPay = 0;
vector<int> v;

void Find(int Pre)
{
    if (tmpTime <= 0)
    {
        for (int i = 0; i < v.size(); i++)
        {
            tmpPay += Pay[v[i]];
        }

        if (tmpPay > ResultPay)
            ResultPay = tmpPay;

        tmpPay = 0;

        return;
    }

    for (int i = Pre; i < n; i++)
    {
        tmpTime -= Time[i];

        v.push_back(i);

        Find(i + 1);

        tmpTime += Time[i];;
        v.pop_back();
    }

}

int main()
{
    cin >> n;
    ResultTime = n;
    tmpTime = n;

    for (int i = 0; i < n; i++)
    {
        int A, B;
        cin >> A >> B;

        Time[i] = A;
        Pay[i] = B;
    }

    Find(0);

    cout << ResultPay;
}