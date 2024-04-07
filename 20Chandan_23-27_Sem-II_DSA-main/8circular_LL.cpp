// 8. Implement Circular Linked List ADT.

// Theory:
// This code implements a circular singly linked list data structure 
// with functionalities to append elements to the list, display the 
// elements in the list, and clear the list. It utilizes a Node class 
// to represent individual elements and a circularlist class to manage 
// the list operations. The main function provides a menu-driven 
// interface for users to interact with the list.

#include <iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node* next;

    Node(int value) 
    {
        data = value;
        next = nullptr;
    }
};

class circularlist 
{
private:
    Node* head;

public:
    circularlist() 
    {
        head = nullptr;
    }

    void append(int value) 
    {
        Node* newNode = new Node(value);
        if (head == nullptr) 
        {
            head = newNode;
            head->next = head; 
        } 
        else 
        {
            Node* current = head;
            while (current->next != head) 
            {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head; 
        }
        
        cout << value << " appended to the list." << endl;
    }

    void display() 
    {
        if (head == nullptr) 
        {
            cout << "list is empty." << endl;
            return;
        }
        cout << "elements in list: ";
        Node* current = head;
        do 
        {
            cout << current->data << " ";
            current = current->next;
        } 
        
        while (current != head);
        cout << endl;
    }

    void clear() 
    {
        if (head == nullptr) 
        {
            cout << "list is empty." << endl;
            return;
        }
        Node* current = head;
        while (current->next != head) 
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }

        delete current;
        head = nullptr;
        cout << "list cleared." << endl;
    }
};

int main() 
{
    circularlist list;
    int choice, data;

    do 
    {
        cout << "\n1. append\n";
        cout << "2. display\n";
        cout << "3. clear\n";
        cout << "4. exit\n";
        cout << "enter your choice: ";
        cin >> choice;

        switch(choice) 
        {
            case 1:
                cout << "enter element to append: ";
                cin >> data;
                list.append(data);
                break;
            case 2:
                list.display();
                break;
            case 3:
                list.clear();
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

