#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data, height;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        height = 1;
        left = right = NULL;
    }
};

int getHeight(Node *root)
{
    if (!root)
        return 0;
    return root->height;
}

int getBalance(Node *root)
{
    return getHeight(root->left) - getHeight(root->right);
}

Node *rightRotation(Node *root)
{
    Node *child = root->left;
    Node *childRight = child->right;

    child->right = root;
    root->left = childRight;

    // update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}

Node *leftRotation(Node *root)
{
    Node *child = root->right;
    Node *childLeft = child->left;

    child->left = root;
    root->right = childLeft;

    // update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}

Node *insert(Node *root, int key)
{
    // doesn't exist
    if (!root)
        return new Node(key);

    // exists
    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    else
        return root; // duplicates are not allowed

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    // left-left case
    if (balance > 1 && key < root->left->data)
    {
        return rightRotation(root);
    }
    // right-right case
    else if (balance < -1 && key > root->right->data)
    {
        return leftRotation(root);
    }
    // left-right case
    else if (balance > 1 && key > root->left->data)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    // right-left case
    else if (balance < -1 && key < root->right->data)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    // no imbalancing
    else
    {
        return root;
    }
}

void inOrder(Node *root, vector<int> &inOrderArray)
{
    if (!root)
        return;
    inOrder(root->left, inOrderArray);
    cout << root->data << " ";
    inOrder(root->right, inOrderArray);
}

int main()
{
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 50);
    root = insert(root, 80);
    root = insert(root, 90);
    root = insert(root, 15);
    root = insert(root, 5);
    root = insert(root, 60);
    vector<int> inOrderArray;
    inOrder(root, inOrderArray);
    return 0;
}