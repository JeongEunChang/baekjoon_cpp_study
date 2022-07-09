#include <iostream>
using namespace std;


struct AllHouse {
    int _house_X[100] = { 0 };
    int _house_Y[100] = { 0 };
    int _chiken_house_X[13] = { 0 };
    int _chiken_house_Y[13] = { 0 };
};

int main()
{
    int N = 0;
    int M = 0;
    int high_house = 0;
    int high_chiken = 0;
    int low =100;
    int tmp1 = 0;
    int tmp2 = 0;
    int high = 0;
    int chiken_distance = 0;
    int arr[50][50] = {3};
    int chiken_arr[50] = {0};
    struct AllHouse house;
    int sum = 0;
    
    cin >> N;
    cin >> M;
    
    int k = 0;
    int l = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 1) {
                house._house_X[k] = j;
                house._house_Y[k] = i;
                k++;
            }

            else if (arr[i][j] == 2) {
                house._chiken_house_X[l] = j;
                house._chiken_house_Y[l] = i;
                l++;
            }
        }
    }
    
    high_house = k;
    high_chiken = l;
  
    for (int i = 0; i < high_chiken; i++) {
        for (int k = 0; k < high_house; k++) {
            tmp1 = house._house_X[k] - house._chiken_house_X[i];
            tmp2 = house._house_Y[k] - house._chiken_house_Y[i];

            if (tmp1 < 0)
                tmp1 = tmp1 * -1;
            if (tmp2 < 0)
                tmp2 = tmp2 * -1;

            if ((tmp1 + tmp2) == 1) {
                low = 1;
                break;
            }

            if ((tmp1 + tmp2) < low)
                low = tmp1 + tmp2;

            chiken_distance += low;
        }

        if(i == 0)
            chiken_arr[i] = low;
        else {
            int tmp;
            chiken_arr[i] = low;

            if (chiken_arr[i] < chiken_arr[i - 1]) {
                tmp = chiken_arr[i];
                chiken_arr[i] = chiken_arr[i - 1];
                chiken_arr[i - 1] = tmp;
            }
        }

        low = 100;
    }

    high = high_chiken - 1;
    for (int i = 0; i < high_chiken - 2; i++) {
        for (int k = 0; k < high - 1; k++) {
            int tmp;
            tmp = chiken_arr[i];
            chiken_arr[i] = chiken_arr[i + 1];
            chiken_arr[i + 1] = tmp;
        }
        high--;
    }


    for (int i = 0; i < M; i++) {
        sum += chiken_arr[i];
    }

    printf("%d\n", sum);

    return 0;
}