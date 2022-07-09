#include <iostream>

using namespace std;

int main()
{
    int N = 0;
    int sum = 1;
    int count = 0;
    int tmp1 = 0;
    int tmp2 = 0;
    int i = 2;
    int j = 2;
    int least = 0;

    cin >> N;

    if (N == 1) {
        cout << count << endl;
        return 0;
    }

    sum += 1;
    count++;

    while (true)
    {
        if ((i ^ 2) > N)
            break;

        while (true)
        {
            sum = i ^ j;

            if ((i ^ j) > N)
                break;

            else if ((i ^ j) == N) {
                cout << least << endl;
                return 0;
            }

            j++;
        }

        if (least > count)
            least = count;

        count++;
        i++;
    }

    if ((sum - N) > 0) {
        cout << sum - N + least << endl;
    }
    else if ((sum - N) < 0) {
        cout << N - sum + least << endl;
    }

    return 0;
}