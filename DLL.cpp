#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int n)
    {
        data = n;
        prev = NULL;
        next = NULL;
    }
};

void insert(Node *&head, int val)
{
    Node *newNode = new Node(val);

    if (!head)
    {
        head = newNode;
        return;
    }

    if (val <= head->data)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next && temp->data < val)
    {
        temp = temp->next;
    }

    if (!temp->next && temp->data < val)
    {
        temp->next = newNode;
        newNode->prev = temp;
    }
    else
    {
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }
}

void deleteNode(Node *&head, int val)
{
    if (!head)
        return;

    Node *temp = head;
    while (temp && temp->data != val)
    {
        temp = temp->next;
    }

    if (!temp)
        return;

    if (temp == head)
    {
        head = head->next;
        if (head)
            head->prev = NULL;
        delete temp;
        return;
    }

    if (temp->next)
    {
        temp->next->prev = temp->prev;
    }
    if (temp->prev)
    {
        temp->prev->next = temp->next;
    }

    delete temp;
}

void print(Node *head)
{
    Node *temp = head;
    cout << "NULL";
    while (temp)
    {
        cout << "<-->" << temp->data;
        temp = temp->next;
    }
    cout << "<-->NULL" << endl;
}

int main()
{
    Node *head = NULL;
    int val;

    while (true)
    {
        cout << "Enter a value to insert in DLL(or -1 to stop): ";
        cin >> val;

        if (val == -1)
            break;

        insert(head, val);
    }

    cout << "Final list after all insertions:" << endl;
    print(head);

    while (true)
    {
        cout << "Enter a value to delete from DLL(or -1 to stop): ";
        cin >> val;

        if (val == -1)
            break;

        deleteNode(head, val);
        print(head);
    }

    return 0;
}
