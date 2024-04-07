// 6. Implement Circular Queue ADT using array.

// Theory:
// This code implements a queue data structure using an array with 
// circular buffering to optimize space usage. It provides 
// functionalities to enqueue elements into the queue, dequeue 
// elements from the queue, and display the elements currently in the 
// queue. The circular buffering technique ensures efficient 
// utilization of the array.

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Queue 
{
private:
    int front, rear;
    int arr[MAX_SIZE];

public:
    Queue() 
    {
        front = rear = -1;
    }

    bool isEmpty() 
    {
        return (front == -1);
    }

    bool isFull() 
    {
        return ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1));
    }

    void enqueue(int data) 
    {
        if (isFull()) 
        {
            cout << "queue is full" << endl;
            return;
        } 
        else if (isEmpty()) 
        {
            front = rear = 0;
        } 
        else if (rear == MAX_SIZE - 1) 
        {
            rear = 0;
        } 
        else 
        {
            rear++;
        }
        arr[rear] = data;
        cout << data << " enqueued to queue" << endl;
    }

    void dequeue() 
    {
        if (isEmpty()) 
        {
            cout << "queue is empty" << endl;
            return;
        } 
        else if (front == rear) 
        {
            cout << arr[front] << " dequeued from queue" << endl;
            front = rear = -1;
        } 
        else if (front == MAX_SIZE - 1) 
        {
            cout << arr[front] << " dequeued from queue" << endl;
            front = 0;
        } 
        else 
        {
            cout << arr[front] << " dequeued from queue" << endl;
            front++;
        }
    }

    void display() 
    {
        if (isEmpty()) 
        {
            cout << "queue is empty" << endl;
            return;
        }
        cout << "elements in queue: ";
        if (rear >= front) 
        {
            for (int i = front; i <= rear; i++) 
            {
                cout << arr[i] << " ";
            }
        }
        else 
        {
            for (int i = front; i < MAX_SIZE; i++) 
            {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++) 
            {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() 
{
    Queue q;
    int choice, data;

    do 
    {
        cout << "\n1. enqueue\n";
        cout << "2. dequeue\n";
        cout << "3. display\n";
        cout << "4. exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) 
        {
            case 1:
                cout << "enter elements to enqueue: ";
                cin >> data;
                q.enqueue(data);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "exited!" << endl;
                break;
            default:
                cout << "invalid choice" << endl;
        }

    } 
    while (choice != 4);

    return 0;
}
