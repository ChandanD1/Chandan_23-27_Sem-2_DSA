// 7. Implement Singly Linked List ADT.

// Theory:
// This code implements a singly linked list data structure with 
// functionalities to append elements to the list, display the 
// elements in the list, and clear the list. It utilizes a Node class 
// to represent individual elements and a singlylist class to manage 
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

class singlylist 
{
private:
    Node* head;
    Node* tail;

public:
    singlylist() 
    {
        head = nullptr;
        tail = nullptr;
    }

    void append(int value) 
    {
        Node* newNode = new Node(value);
        if (head == nullptr) 
        {
            head = tail = newNode;
        } 
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
        cout << value << " appended to the list." << endl;
    }

    void display() 
    {
        if (head == nullptr) 
        {
            cout << "list is empty" << endl;
            return;
        }

        cout << "elements in list: ";

        Node* current = head;
        while (current != nullptr) 
        {
            cout << current->data << " ";
            current = current->next;
        }
        
        cout << endl;
    }

    void clear() 
    {
        while (head != nullptr) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        tail = nullptr;
        cout << "list cleared." << endl;
    }
};

int main() 
{
    singlylist list;
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

