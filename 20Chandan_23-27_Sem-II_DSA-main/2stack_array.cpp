// 2. Implement Stack ADT using array in CPP.

// Theory:
// This code implements a stack using a class Stack with 
// functionalities like initialization, checking if the stack is empty 
// or full, pushing elements onto the stack, popping elements from 
// the stack, and peeking at the top element. The main function 
// provides menu-driven interface for users to interact with the stack.

#include <iostream>
using namespace std;

class Stack 
{
private:
    int capacity;
    int *arr;
    int top;

public:
    void init(int cap) 
    {
        capacity = cap;
        arr = new int[capacity];
        top = -1;
    }

    bool isEmpty() 
    {
        return top == -1;
    }

    bool isFull() 
    {
        return top == capacity - 1;
    }

    void push(int element) 
    {
        if (!isFull()) 
        {
            arr[++top] = element;
            cout << element << " pushed in stack." << endl;
        } 
        else 
        {
            cout << "stack overflow" << endl;
        }
    }

    int pop() 
    {
        if (!isEmpty()) 
        {
            int element = arr[top--];
            cout << element << " popped from stack" << endl;
            return element;
        } 
        else 
        {
            cout << "stack underflow" << endl;
            return -1;
        }
    }

    int peek() 
    {
        if (!isEmpty()) 
        {
            return arr[top];
        } 
        else 
        {
            cout << "stack is empty" << endl;
            return -1;
        }
    }
};

int main() 
{
    Stack stack;
    int capacity;
    cout << "enter capacity of stack: ";
    cin >> capacity;
    stack.init(capacity);

    int num_elements;
    cout << "how many elements do you want to push in stack? ";
    cin >> num_elements;

    int element;
    for (int i = 0; i < num_elements; ++i) 
    {
        cout << "enter element " << i + 1 << ": ";
        cin >> element;
        stack.push(element);
    }

    int choice;
    do 
    {
        cout << "\n1. push\n";
        cout << "2. pop\n";
        cout << "3. peek\n";
        cout << "4. exit\n";
        cout << "enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "enter element to push in stack: ";
                cin >> element;
                stack.push(element);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                element = stack.peek();
                if (element != -1) 
                {
                    cout << "top element of stack: " << element << endl;
                }
                break;
            case 4:
                cout << "exited!\n";
                break;
            default:
                cout << "invalid choice" << endl;
        }
    } 
    while (choice != 4);

    return 0;
}

