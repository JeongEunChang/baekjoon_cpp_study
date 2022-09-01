#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int A, B;

    cin >> A >> B;

    if (A > B)
        printf(">");

    else if (A < B)
        printf("<");

    else
        printf("==");
}