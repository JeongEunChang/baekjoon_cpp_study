#include <iostream>
using namespace std;

int main()
{
    string Input;
    int Count = 0;
    cin >> Input;

    for (int i = 0; i < Input.length(); i++)
    {
        if (Input[i] == ' ')
        {
            if (i == Input[Input.length() - 1])

            Count++;
        }          
    }

    if (Input[0] == ' ')
        Count--;

    if (Input[Input.length() - 1] == ' ')
        Count--;

    cout << Count + 1;
}