#include <iostream>

using namespace std;


struct Node
{
    char NodeName;
    Node* ParentsNode = nullptr;;
    Node* LeftNode = nullptr;
    Node* RightNode = nullptr;
};

Node* NodeArr[26] = { nullptr };

void Last(Node* Roote)
{
    if (Roote->LeftNode == nullptr &&
        Roote->RightNode == nullptr){
        cout << Roote->NodeName;
        return;
    }

    if (Roote->LeftNode != nullptr)
        Last(Roote->LeftNode);

    if (Roote->RightNode != nullptr)
        Last(Roote->RightNode);

    cout << Roote->NodeName;
    return;
}

void Middle(Node* Roote)
{
    if (Roote->LeftNode == nullptr &&
        Roote->RightNode == nullptr) {
        cout << Roote->NodeName;
        return;
    }

    if (Roote->LeftNode != nullptr)
        Middle(Roote->LeftNode);

    cout << Roote->NodeName;

    if (Roote->RightNode != nullptr)
        Middle(Roote->RightNode);
}

void First(Node* Roote)
{
    cout << Roote->NodeName;

    if (Roote->LeftNode == nullptr &&
        Roote->RightNode == nullptr) {
        return;
    }

    if (Roote->LeftNode != nullptr)
        First(Roote->LeftNode);

    if (Roote->RightNode != nullptr)
        First(Roote->RightNode);
}

int main()
{
    int NodeNum;
    //Node* NodeArr[26] = { nullptr };

    cin >> NodeNum;

    for (int i = 0; i < NodeNum; i++)
    {
        char Input[3] = { NULL };

        cin >> Input[0] >> Input[1] >> Input[2];

        for (int j = 0; j < 3; j++)
        {
            if (Input[j] != '.' && NodeArr[Input[j] - 65] == nullptr)
            {
                NodeArr[Input[j] - 65] = new Node();
                NodeArr[Input[j] - 65]->NodeName = Input[j];
            }
        }

        if (Input[1] != '.')
        {
            NodeArr[Input[0] - 65]->LeftNode = NodeArr[Input[1] - 65];
            NodeArr[Input[1] - 65]->ParentsNode = NodeArr[Input[0] - 65];
        }

        if (Input[2] != '.')
        {
            NodeArr[Input[0] - 65]->RightNode = NodeArr[Input[2] - 65];
            NodeArr[Input[2] - 65]->ParentsNode = NodeArr[Input[0] - 65];
        }

    }
    First(NodeArr[0]);
    cout << endl;
    Middle(NodeArr[0]);
    cout << endl;
    Last(NodeArr[0]);
    cout << endl;
}