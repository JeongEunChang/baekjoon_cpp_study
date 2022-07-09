#include <iostream>
#include <string.h>

using namespace std;


int length;
int* stack;

void push(int x);
void pop();
void size();
void empty();
void top();

int main()
{
    int N = 0;;
    int X = 0;
    char order[100] = { NULL };

    cin >> N;

    stack = new int[N];


    
    for (int i = 0; i < N; i++) {
        cin >> order;

        if (strcmp(order, "push") == 0) {
            cin >> X;
            push(X);
        }

        else if (strcmp(order, "pop") == 0)
            pop();

        else if (strcmp(order, "size") == 0)
            size();

        else if (strcmp(order, "empty") == 0)
            empty();

        else if (strcmp(order, "top") == 0)
            top();
    }

    return 0;
}

void push(int x)
{
    stack[length] = x;
    length++;
}

void pop()
{
    if (length == 0)
        cout << -1 << endl;

    else if (length > 0) {
        cout << stack[length-1] << endl;;
        stack[length-1] = NULL;
        length--;
        }
}

void size()
{
    cout << length << endl;
}

void empty()
{
    if (length == 0)
        cout << 1 << endl;
    else if (length > 0)
        cout << 0 << endl;
}

void top()
{
    if (length > 0)
        cout << stack[length-1] << endl;
    else if (length == 0)
        cout << -1 << endl;
}
