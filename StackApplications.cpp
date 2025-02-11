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
class Stack
{
    Node<T> *top;
    int size;

public:
    Stack()
    {
        top = NULL;
        size = 0;
    }

    void push(T val)
    {
        Node<T> *newTop = new Node<T>(val);
        newTop->next = top;
        top = newTop;
        size++;
    }

    void pop()
    {
        if (size)
        {
            Node<T> *temp = top;
            top = top->next;
            delete temp;
            size--;
        }
        else
        {
            cout << "Stack is already empty!\n";
        }
    }

    T Top()
    {
        if (size)
            return top->data;
        else
            throw out_of_range("Stack is empty!");
    }

    int Size()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }
};

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '^')
        return 3;
    return -1;
}

string convertInfixToPostfix(string infix)
{
    Stack<char> s;
    string postfix = "";

    for (char c : infix)
    {
        if (isalnum(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.isEmpty() && s.Top() != '(')
            {
                postfix += s.Top();
                s.pop();
            }
            s.pop();
        }
        else if (isOperator(c))
        {
            while (!s.isEmpty() && precedence(s.Top()) >= precedence(c))
            {
                postfix += s.Top();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty())
    {
        postfix += s.Top();
        s.pop();
    }
    return postfix;
}

string convertInfixToPrefix(string infix)
{
    Stack<char> s;
    string prefix = "";
    reverse(infix.begin(), infix.end());

    for (char &c : infix)
    {
        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';
    }

    for (char c : infix)
    {
        if (isalnum(c))
        {
            prefix += c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.isEmpty() && s.Top() != '(')
            {
                prefix += s.Top();
                s.pop();
            }
            s.pop();
        }
        else if (isOperator(c))
        {
            while (!s.isEmpty() && precedence(s.Top()) > precedence(c))
            {
                prefix += s.Top();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty())
    {
        prefix += s.Top();
        s.pop();
    }
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

string convertPrefixToPostfix(string prefix)
{
    Stack<string> s;
    reverse(prefix.begin(), prefix.end());

    for (char c : prefix)
    {
        if (isalnum(c))
        {
            s.push(string(1, c));
        }
        else if (isOperator(c))
        {
            string op1 = s.Top();
            s.pop();
            string op2 = s.Top();
            s.pop();
            s.push(op1 + op2 + c);
        }
    }
    return s.Top();
}

float evaluatePostfix(string postfix)
{
    Stack<float> st;
    for (char ch : postfix)
    {
        if (isdigit(ch))
            st.push(ch - '0');
        else if (isOperator(ch))
        {
            float num2 = st.Top();
            st.pop();
            float num1 = st.Top();
            st.pop();
            if (ch == '+')
                st.push(num1 + num2);
            else if (ch == '-')
                st.push(num1 - num2);
            else if (ch == '*')
                st.push(num1 * num2);
            else if (ch == '/')
                st.push(num1 / num2);
            else if (ch == '^')
                st.push(pow(num1, num2));
        }
    }
    return st.Top();
}

float evaluatePrefix(string prefix)
{
    Stack<float> st;
    reverse(prefix.begin(), prefix.end());

    for (char ch : prefix)
    {
        if (isdigit(ch))
            st.push(ch - '0');
        else if (isOperator(ch))
        {
            float num1 = st.Top();
            st.pop();
            float num2 = st.Top();
            st.pop();
            if (ch == '+')
                st.push(num1 + num2);
            else if (ch == '-')
                st.push(num1 - num2);
            else if (ch == '*')
                st.push(num1 * num2);
            else if (ch == '/')
                st.push(num1 / num2);
            else if (ch == '^')
                st.push(pow(num1, num2));
        }
    }
    return st.Top();
}

int main()
{
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = convertInfixToPostfix(infix);
    cout << "Postfix expression: " << postfix << "\n";

    string prefix = convertInfixToPrefix(infix);
    cout << "Prefix expression: " << prefix << "\n";

    string prefixToPostfix = convertPrefixToPostfix(prefix);
    cout << "Converted Prefix to Postfix: " << prefixToPostfix << "\n";

    cout << "Evaluation of Postfix expression: " << evaluatePostfix(postfix) << "\n";
    cout << "Evaluation of Prefix expression: " << evaluatePrefix(prefix) << "\n";

    return 0;
}
