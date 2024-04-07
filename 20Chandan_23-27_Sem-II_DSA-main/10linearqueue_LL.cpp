// 10. Implement Linear Queue ADT using Linked List

// Theory:
// This code implements a queue data structure using a singly linked 
// list. It provides functionalities to enqueue elements into the 
// queue, dequeue elements from the queue, display the elements in 
// the queue, and check if the queue is empty. The main function 
// offers a menu-driven interface for users to interact with the queue.

#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
};

class Queue 
{
private:
    Node* front; 
    Node* rear; 

public:
    Queue() 
    {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int value) 
    {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (isEmpty()) 
        {
            front = rear = newNode;
        } 
        else 
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() 
    {
        if (isEmpty()) 
        {
            cout << "queue is empty\n";
            return -1; 
        }
        
        int dequeuedvalue = front->data;
        Node* temp = front;
        front = front->next;

        if (front == nullptr) 
        {
            rear = nullptr;
        }

        delete temp;
        return dequeuedvalue;
    }

    bool isEmpty() 
    {
        return front == nullptr;
    }

    void display() 
    {
        if (isEmpty()) 
        {
            cout << "queue is empty\n";
            return;
        }

        cout << "queue: ";
        Node* current = front;

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
    Queue queue;
    char choice;
    int value;

    do 
    {
        cout << "1. enqueue\n";
        cout << "2. dequeue\n";
        cout << "3. display\n";
        cout << "4. exit\n";
        cout << "enter your choice: ";
        cin >> choice;

        switch(choice) 
        {
            case '1':
                cout << "enter element to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case '2':
                if (!queue.isEmpty())
                    cout << "dequeued value: " << queue.dequeue() << endl;
                break;
            case '3':
                queue.display();
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

