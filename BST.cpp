#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class BST
{
public:
    Node *root;
    BST() : root(NULL) {}

    // Getter for Root
    Node *getRoot()
    {
        return root;
    }

    // Constructing a BST from an Array
    Node *constructBST(vector<int> &arr, int start, int end)
    {
        if (start > end)
            return NULL;
        int mid = start + (end - start) / 2;

        Node *root = new Node(arr[mid]);
        root->left = constructBST(arr, start, mid - 1);
        root->right = constructBST(arr, mid + 1, end);

        return root;
    }

    Node *buildBSTFromArray(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        root = constructBST(arr, 0, n - 1);
    }

    // Insertion in BST(always builds a skewed tree)
    Node *insert(Node *root, int data)
    {
        if (!root)
            return new Node(data);
        if (data < root->data)
            insert(root->left, data);
        else if (data > root->data)
            insert(root->right, data);

        return root;
    }

    void insert(int data)
    {
        root = insert(root, data);
    }

    // Deletion in BST
    Node *deleteNodeBST(Node *root, int key)
    {
        if (!root)
            return NULL;

        if (root->data > key)
        {
            root->left = deleteNodeBST(root->left, key);
            return root;
        }

        else if (root->data < key)
        {
            root->right = deleteNodeBST(root->right, key);
            return root;
        }

        else
        {
            // Leaf Node
            if (!root->left && !root->right)
            {
                delete root;
                return NULL;
            }

            // 1 Child Exists
            else if (!root->right)
            { // left child exists
                Node *temp = root->left;
                delete root;
                return temp;
            }
            else if (!root->left)
            { // right child exists
                Node *temp = root->right;
                delete root;
                return temp;
            }

            // Both Child Exists
            else
            { // Find greatest from left Subtree to make that new Root
                Node *child = root->left;
                Node *parent = root;
                while (child->right)
                {
                    parent = child;
                    child = child->right;
                }
                if (root != parent)
                {
                    parent->right = child->left;
                    child->left = root->left;
                    child->right = root->right;
                    delete root;
                    return child;
                }
                else
                {
                    child->right = root->right;
                    delete root;
                    return child;
                }
            }
        }
        return root;
    }

    void deleteNode(int key)
    {
        root = deleteNodeBST(root, key);
    }

    // Inorder Traversal (Left-Root-Right)
    void inorder(Node *node)
    {
        if (!node)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void displayInorder()
    {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }

    // Find Minimum in BST
    int findMin(Node *node)
    {
        while (node->left)
            node = node->left;
        return node->data;
    }

    int findMin()
    {
        if (!root)
            return -1;
        return findMin(root);
    }

    // Find Maximum in BST
    int findMax(Node *node)
    {
        while (node->right)
            node = node->right;
        return node->data;
    }

    int findMax()
    {
        if (!root)
            return -1;
        return findMax(root);
    }

    // Find InorderSuccessor
    void findCeil(Node *root, int x, int &ans)
    {
        if (!root)
            return;
        if (root->data > x)
        {
            ans = root->data;
            findCeil(root->left, x, ans);
        }
        else
            findCeil(root->right, x, ans);
    }

    int inOrderSuccessor(int x)
    {
        if (!root)
            return -1;
        int ans = -1;
        findCeil(root, x, ans);
        return ans;
    }


    // Find InorderPredecessor
    void findFloor(Node *root, int x, int &ans)
    {
        if (!root)
            return;
        if (root->data < x)
        {
            ans = root->data;
            findFloor(root->right, x, ans);
        }
        else
            findFloor(root->left, x, ans);
    }

    int inOrderPredecessor(int x)
    {
        if (!root)
            return -1;
        int ans = -1;
        findFloor(root, x, ans);
        return ans;
    }

    void inorderTraverse(Node *root, vector<int> &nodes)
    {
        if (!root)
            return;
        inorderTraverse(root->left, nodes);
        nodes.push_back(root->data);
        inorderTraverse(root->right, nodes);
    }
    bool isValidBST()
    {
        vector<int> nodes;
        inorderTraverse(root, nodes);
        for (int i = 0; i < nodes.size() - 1; i++)
        {
            if (nodes[i] >= nodes[i + 1])
                return false;
        }
        return true;
    }
};

int main()
{

    vector<int> arr = {7, 2, 5, 8, 6, 1, 3, 9, 4, 10, 14, 12, 13, 11};
    BST tree;
    tree.buildBSTFromArray(arr);
    tree.displayInorder();
    tree.deleteNode(10);
    tree.displayInorder();
    cout << tree.inOrderSuccessor(10) << endl;
    cout << tree.isValidBST() << endl;
    return 0;
}