#include <iostream>
#include <queue>
using namespace std;

// Node structure for Binary Tree
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Tree
{
public:
    Node *root;
    Tree() : root(NULL) {}

    // Insert a node in Binary Tree (Level Order)
    void insert(int data)
    {
        if (!root)
        {
            root = new Node(data);
            return;
        }
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (!temp->left)
            {
                temp->left = new Node(data);
                return;
            }
            else
                q.push(temp->left);

            if (!temp->right)
            {
                temp->right = new Node(data);
                return;
            }
            else
                q.push(temp->right);
        }
    }

    // Preorder Traversal (Root-Left-Right)
    void preorder(Node *node)
    {
        if (!node)
            return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void displayPreorder()
    {
        cout << "Preorder: ";
        preorder(root);
        cout << endl;
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

    // Postorder Traversal (Left-Right-Root)
    void postorder(Node *node)
    {
        if (!node)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void displayPostorder()
    {
        cout << "Postorder: ";
        postorder(root);
        cout << endl;
    }

    // Level Order Traversal
    void levelOrder()
    {
        if (!root)
            return;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        cout << endl;
    }

    // Height of Binary Tree
    int height(Node *node)
    {
        if (!node)
            return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    int getHeight()
    {
        return height(root);
    }

    // Count Total Nodes
    int countNodes(Node *node)
    {
        if (!node)
            return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int getTotalNodes()
    {
        return countNodes(root);
    }

    // Count Leaf Nodes
    int countLeafNodes(Node *node)
    {
        if (!node)
            return 0;
        if (!node->left && !node->right)
            return 1;
        return countLeafNodes(node->left) + countLeafNodes(node->right);
    }

    int getLeafNodes()
    {
        return countLeafNodes(root);
    }

    // Mirror a Binary Tree
    void mirror(Node *node)
    {
        if (!node)
            return;
        swap(node->left, node->right);
        mirror(node->left);
        mirror(node->right);
    }

    void mirrorTree()
    {
        mirror(root);
    }

    // Diameter of Binary Tree
    int diameter(Node *node, int &ans)
    {
        if (!node)
            return 0;
        int leftHeight = diameter(node->left, ans);
        int rightHeight = diameter(node->right, ans);
        ans = max(ans, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }

    int getDiameter()
    {
        int ans = 0;
        diameter(root, ans);
        return ans;
    }
};

int main()
{
    Tree tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);

    cout << "Preorder: ";
    tree.displayPreorder();
    cout << "Inorder: ";
    tree.displayInorder();
    cout << "Postorder: ";
    tree.displayPostorder();
    cout << "Level Order: ";
    tree.levelOrder();
    cout << "Height: " << tree.getHeight() << endl;
    cout << "Total Nodes: " << tree.getTotalNodes() << endl;
    cout << "Leaf Nodes: " << tree.getLeafNodes() << endl;
    cout << "Diameter: " << tree.getDiameter() << endl;

    tree.mirrorTree();
    cout << "Inorder of Mirrored Tree: ";
    tree.displayInorder();

    return 0;
}
