#include <iostream>
#include <math.h>
#include < ctime >

using namespace std;

int abc(long long a)
{
    int high = 0;
    long long tmp1 = 0;
    long long tmp2 = 0;
    int i = 2;
    int least = 1000000000;
    int k = 2;
    int q = 2;
    int least_k = 0;
    int sum = 0;

    while (pow(i, 2) < a)
    {
        i++;
    }
    high = i;

    for (k = 2; k <= high; k++)
    {
        if (k == 2) {
            while (pow(k, q) < a)
            {
                q++;
            }
            tmp1 = (pow(k, q) - a) + k - 1 + 1;
            tmp2 = (a - pow(k, q - 1)) + k - 1 + 1;
        }
        else {
            while (pow(k, q) > a)
            {
                q--;
            }
            tmp1 = (pow(k, q + 1) - a) + k - 1 + 1;
            tmp2 = (a - pow(k, q)) + k - 1 + 1;
        }

        if (tmp1 > tmp2) {
            if (tmp2 < least) {
                least = tmp2;
                least_k = k;
            }
        }

        else if (tmp1 < tmp2) {
            if (tmp1 < least) {
                least = tmp1;
                least_k = k;
            }
        }

        else {
            if (tmp2 < least) {
                least = tmp1;
                least_k = k;
            }
        }
    }

    if (a == 2)
        return 1;
    else if (a == 3)
        return 2;
    else {
        sum = abc(least_k) + (least - least_k) + 1;
    }

    return sum;
}


int main()
{
    clock_t begin = clock();

    unsigned long long N = 0;
    int high = 0;
    unsigned long long tmp1 = 0;
    unsigned long long tmp2 = 0;
    int i = 2;
    int least = 1000000000;
    int k = 2;
    int q = 2;
    int least_k = 0;


    cin >> N;

    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }

    if (N == 2) {
        cout << 1 << endl;
        return 0;
    }

    if (N == 3) {
        cout << 2 << endl;
        return 0;
    }

    while (pow(i, 2) < N)
    {
        i++;
    }
    high = i;

    for (k = 2; k <= high; k++)
    {
        if (k == 2) {
            while (pow(k, q) < N)
            {
                q++;
            }
            tmp1 = (pow(k, q) - N) + k - 1 + 1;
            tmp2 = (N - pow(k, q - 1)) + k - 1 + 1;
        }
        else {
            while (pow(k, q) > N)
            {
                q--;
            }
            tmp1 = (pow(k, q + 1) - N) + k - 1 + 1;
            tmp2 = (N - pow(k, q)) + k - 1 + 1;
        }
     
        if (tmp1 > tmp2) {
            if (tmp2 < least) {
                least = tmp2;
                least_k = k;
            }
        }

        else if (tmp1 < tmp2) {
            if (tmp1 < least) {
                least = tmp1;
                least_k = k;
            }
        }

        else {
            if (tmp2 < least) {
                least = tmp1;
                least_k = k;
            }
        }
    }
 
    least = abc(least_k) + (least - least_k) + 1;

    cout << least << endl;

    clock_t finish = clock();
    double elapsed_secs = double(begin - finish) / CLOCKS_PER_SEC;
    printf("방법2: Elasped time is %.2lf seconds.\n", elapsed_secs);

    return 0;
}