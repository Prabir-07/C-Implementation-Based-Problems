#include<bits/stdc++.h>
using namespace std;

class Stack {
    int *arr;
    int size;
    int top;
public:
    Stack(int s) {
        size = s;
        top = -1;
        arr = new int[s];
    }
    void push(int val) {
        top++;
        if(top < size) 
            arr[top] = val;
        else
            throw out_of_range("Overflow! Stack is full.");
    }
    void pop() {
        if(top != -1) {
            top--;
        }
        else throw out_of_range("Underflow! Stack is empty");
    }
    int Top() {
        if(top != -1) 
            return arr[top];
        else
            throw out_of_range("Can't access! Stack is empty.");
    }
    bool isEmpty() {
        if(top == -1) return true;
        else return false;
    }
    void print() {
        if(top != -1) {
            for(int i=0; i<=top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else cout << "Stack is empty!";
    }
    int Size() {
        if(top != -1) return top+1;
        else return 0;
    }
};

int main() {
    Stack st(8);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    cout << endl << st.Size() << endl;
    st.print();
    st.pop();
    cout << endl << st.Size() << endl;
    st.print();
    st.pop();
    cout << endl << st.Size() << endl;
    st.print();
    st.pop();
    cout << endl << st.Size() << endl;
    st.print();
    st.pop();
    cout << endl << st.Size() << endl;
    st.print();
    st.pop();
    cout << endl << st.Size() << endl;
    st.print();
    st.pop();
    cout << endl << st.Size() << endl;
    st.print();
    st.pop();
    cout << endl << st.Size() << endl;
    st.print();
    st.pop();
    cout << endl << st.Size() << endl;
    st.print();
    st.pop();
    return 0;
}