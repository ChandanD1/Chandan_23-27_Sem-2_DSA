// 11. Implement Binary Search Tree ADT using Linked List.

// Theory:
// This code implements a binary search tree (BST) data structure 
// with functionalities to insert elements into the tree, search for 
// elements in the tree, and display the elements of the tree in 
// sorted order. It utilizes a recursive approach for insertion and 
// traversal. The main function offers a menu-driven interface for 
// users to interact with the BST.

#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* left;
    Node* right;
};

class bst 
{
private:
    Node* root;

    Node* createnode(int value) 
    {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    Node* insert(Node* root, int value) 
    {
        if (root == nullptr) 
        {
            return createnode(value);
        }

        if (value < root->data) 
        {
            root->left = insert(root->left, value);
        } 
        else if (value > root->data) 
        {
            root->right = insert(root->right, value);
        }
        return root;
    }

    void traversal(Node* root) 
    {
        if (root != nullptr) 
        {
            traversal(root->left);
            cout << root->data << " ";
            traversal(root->right);
        }
    }

public:
    bst() 
    {
        root = nullptr;
    }

    void insert(int value) 
    {
        root = insert(root, value);
    }

    bool search(int value) 
    {
        Node* current = root;
        while (current != nullptr) 
        {
            if (value == current->data) 
            {
                return true;
            } 
            else if (value < current->data) 
            {
                current = current->left;
            } 
            else 
            {
                current = current->right;
            }
        }
        return false;
    }

    void display() 
    {
        if (root == nullptr) 
        {
            cout << "binary search tree is empty\n";
        } 
        else 
        {
            cout << "binary search tree: ";
            traversal(root);
            cout << endl;
        }
    }
};

int main() 
{
    bst bst;
    char choice;
    int value;

    do 
    {
        cout << "1. insert\n";
        cout << "2. search\n";
        cout << "3. display\n";
        cout << "4. exit\n";
        cout << "enter your choice: ";
        cin >> choice;

        switch(choice) 
        {
            case '1':
                cout << "enter element to insert: ";
                cin >> value;
                bst.insert(value);
                break;
            case '2':
                cout << "enter element to search: ";
                cin >> value;
                if (bst.search(value)) 
                {
                    cout << "found in binary search tree.\n";
                } else {
                    cout << "not found in binary search tree.\n";
                }
                break;
            case '3':
                bst.display();
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

