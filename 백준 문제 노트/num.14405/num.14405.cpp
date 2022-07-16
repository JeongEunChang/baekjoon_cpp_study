#include <iostream>
#include <string>

using namespace std;

int main()
{
    string Input;
    bool IsResult = true;

    cin >> Input;

    if (Input.length() < 2)
    {
        IsResult = false;
    }

    for (int i = 0; i < Input.length() - 1; i++)
    {
        if (Input[i] != 'p' && Input[i] != 'i' &&
            Input[i] != 'k' && Input[i] != 'a' &&
            Input[i] != 'c' && Input[i] != 'h' && Input[i] != 'u')
        {
            IsResult = false;
        }

        else if (Input[i] == 'p' && Input[i + 1] != 'i')
        {
            IsResult = false;
        }

        else if (Input[i] == 'i' && Input[i + 1] != 'p' && Input[i + 1] != 'k' && Input[i + 1] != 'c')
        {
            IsResult = false;
        }

        else if (Input[i] == 'k' && Input[i + 1] != 'a')
        {
            IsResult = false;
        }

        else if (Input[i] == 'a' && Input[i + 1] != 'p' && Input[i + 1] != 'k' && Input[i + 1] != 'c')
        {
            IsResult = false;
        }

        else if (Input[i] == 'c' && Input[i + 1] != 'h')
        {
            IsResult = false;
        }

        else if (Input[i] == 'h' && Input[i + 1] != 'u')
        {
            IsResult = false;
        }

        else if (Input[i] == 'u' && Input[i + 1] != 'p' && Input[i + 1] != 'k' && Input[i + 1] != 'c')
        {
            IsResult = false;
        }

        else if (Input[Input.length() - 1] != 'i' && Input[Input.length() - 1] != 'a' && Input[Input.length() - 1] != 'u')
        {
            IsResult = false;
        }

        else if (Input[0] != 'p' && Input[0] != 'k' && Input[0] != 'c')
        {
            IsResult = false;
        }
    }

    if (IsResult)
        cout << "YES";

    else
        cout << "NO";
}