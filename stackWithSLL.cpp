#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node(T val)
    {
        data = val;
        next = NULL;
    }
};

template <typename T>
class Queue
{
    Node<T> *front;
    Node<T> *rear;
    int size;

public:
    Queue()
    {
        front = rear = NULL;
        size = 0;
    }

    // Insert an element at the rear
    void push(T val)
    {
        Node<T> *newNode = new Node<T>(val);
        if (rear == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    // Remove an element from the front
    void pop()
    {
        if (front == NULL)
        {
            cout << "Queue is already empty!\n";
            return;
        }
        Node<T> *temp = front;
        front = front->next;
        delete temp;
        size--;
        if (front == NULL)
            rear = NULL; // If queue becomes empty
    }

    // Get the front element
    T Front()
    {
        if (front == NULL)
            throw out_of_range("Queue is empty!");
        return front->data;
    }

    // Get the size of the queue
    int Size()
    {
        return size;
    }

    // Check if queue is empty
    bool isEmpty()
    {
        return size == 0;
    }

    // Print queue elements
    void print()
    {
        if (front == NULL)
        {
            cout << "Queue is empty!\n";
            return;
        }
        Node<T> *temp = front;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue<int> q;

    cout << "Pushing elements: 10, 20, 30\n";
    q.push(10);
    q.push(20);
    q.push(30);
    q.print(); // Output: 10 20 30

    cout << "Front element: " << q.Front() << endl; // Output: 10
    cout << "Queue size: " << q.Size() << endl;     // Output: 3

    cout << "Popping front element...\n";
    q.pop();
    q.print(); // Output: 20 30

    cout << "Checking if queue is empty: " << (q.isEmpty() ? "Yes" : "No") << endl; // Output: No

    cout << "Popping all elements...\n";
    q.pop();
    q.pop();
    q.pop(); // Trying to pop when empty

    return 0;
}
