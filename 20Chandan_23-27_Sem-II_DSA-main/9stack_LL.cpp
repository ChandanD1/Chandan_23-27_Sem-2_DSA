// 9. Implement Stack ADT using Linked List

// Theory:
// This code implements a stack data structure using a singly linked 
// list. It provides functionalities to push elements onto the stack, 
// pop elements from the stack, display the elements in the stack, 
// and check if the stack is empty. The main function offers a 
// menu-driven interface for users to interact with the stack.

#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
};

class Stack 
{
private:
    Node* top; 

public:
    Stack() 
    {
        top = nullptr;
    }

    void push(int value) 
    {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    int pop() 
    {
        if (isEmpty()) 
        {
            cout << "stack is empty\n";
            return -1; 
        }

        int poppedvalue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return poppedvalue;
    }

    bool isEmpty() 
    {
        return top == nullptr;
    }

    void display() 
    {
        if (isEmpty()) 
        {
            cout << "stack is empty\n";
            return;
        }
        cout << "stack: ";
        Node* current = top;

        while (current != nullptr) 
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() 
{
    Stack stack;
    char choice;
    int value;

    do 
    {
        cout << "1. push\n";
        cout << "2. pop\n";
        cout << "3. display\n";
        cout << "4. exit\n";
        cout << "enter your choice: ";
        cin >> choice;

        switch(choice) 
        {
            case '1':
                cout << "enter element to push: ";
                cin >> value;
                stack.push(value);
                break;
            case '2':
                if (!stack.isEmpty())
                    cout << "popped element: " << stack.pop() << endl;
                break;
            case '3':
                stack.display();
                break;
            case '4':
                cout << "exited!\n";
                break;
            default:
                cout << "invalid choice\n";
        }
    } 
    while(choice != '4');

    return 0;
}

