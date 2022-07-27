#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    string s_Input;
    char c_Input[11];

    cin >> s_Input;

    for (int i = 0; i < s_Input.length(); i++)
    {
        c_Input[i] = s_Input[i];
    }

    c_Input[s_Input.length()] = NULL;

    sort(c_Input, c_Input + s_Input.length(), greater<>());

    cout << c_Input;
}