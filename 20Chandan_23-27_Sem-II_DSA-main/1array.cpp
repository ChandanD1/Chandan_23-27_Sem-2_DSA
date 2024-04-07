// 1. Implement Array and write a menu driven program to perform 
// all the operations on array element

// Theory:
// This code defines a class Array to handle various operations on 
// an array such as initialization, traversal, insertion, deletion, 
// searching, sorting, and reversal. The main function prompts the 
// user to input the capacity of the array and its elements, then 
// provides a menu-driven interface to perform different operations.

#include <iostream>
using namespace std;

class Array 
{
private:
    int capacity, size;
    int *arr;

public:
    void init(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        size = 0;
    }

    void traverse() 
    {
        cout << "Array elements: ";
        for (int i = 0; i < size; ++i) 
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void insertBeginning(int element) 
    {
        if (size < capacity) 
        {
            for (int i = size; i > 0; --i) 
            {
                arr[i] = arr[i - 1];
            }
            arr[0] = element;
            size++;
            cout << "element inserted at beginning!" << endl;
        } 
        else 
        {
            cout << "array is full" << endl;
        }
    }

    void insertEnd(int element) 
    {
        if (size < capacity) 
        {
            arr[size++] = element;
            cout << "element inserted at end!" << endl;
        } 
        else 
        {
            cout << "array is full" << endl;
        }
    }

    void insertIndex(int element, int index) 
    {
        if (index >= 0 && index <= size && size < capacity) 
        {
            for (int i = size; i > index; --i) 
            {
                arr[i] = arr[i - 1];
            }
            arr[index] = element;
            size++;
            
            cout << "element inserted at index " << index << endl;
        } 
        else 
        {
            cout << "invalid index or array is full" << endl;
        }
    }

    void deleteElement(int index) 
    {
        if (index >= 0 && index < size) 
        {
            for (int i = index; i < size - 1; ++i) 
            {
                arr[i] = arr[i + 1];
            }
            size--;
            cout << "element deleted!" << endl;
        } 
        else 
        {
            cout << "invalid index" << endl;
        }
    }

    int search(int element) 
    {
        for (int i = 0; i < size; ++i) 
        {
            if (arr[i] == element) 
            {
                return i;
            }
        }
        return -1;
    }

    void sort() 
    {
        for (int i = 0; i < size - 1; ++i) 
        {
            for (int j = 0; j < size - i - 1; ++j) 
            {
                if (arr[j] > arr[j + 1]) 
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        cout << "array sorted!" << endl;
    }

    void reverse() 
    {
        for (int i = 0; i < size / 2; ++i) 
        {
            int temp = arr[i];
            arr[i] = arr[size - i - 1];
            arr[size - i - 1] = temp;
        }
        cout << "array reversed!" << endl;
    }
};

int main() 
{
    Array arr;
    int capacity;
    cout << "enter capacity of array: ";
    cin >> capacity;
    arr.init(capacity);

    cout << "enter elements for array: " << endl;
    for (int i = 0; i < capacity; ++i) 
    {
        int element;
        cout << "element " << i + 1 << ": ";
        cin >> element;
        arr.insertEnd(element);
    }

    int choice, element, index;
    do 
    {
        cout << "1. traverse\n";
        cout << "2. insert at beginning\n";
        cout << "3. insert at end\n";
        cout << "4. insert at any index\n";
        cout << "5. delete\n";
        cout << "6. search\n";
        cout << "7. sort\n";
        cout << "8. reverse\n";
        cout << "9. exit\n";
        cout << "enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                arr.traverse();
                break;
            case 2:
                cout << "enter element to insert at beginning: ";
                cin >> element;
                arr.insertBeginning(element);
                break;
            case 3:
                cout << "enter element to insert at end: ";
                cin >> element;
                arr.insertEnd(element);
                break;
            case 4:
                cout << "enter element to insert: ";
                cin >> element;
                cout << "enter index no. to insert at: ";
                cin >> index;
                arr.insertIndex(element, index);
                break;
            case 5:
                cout << "enter index of element to delete: ";
                cin >> index;
                arr.deleteElement(index);
                break;
            case 6:
                cout << "enter element to search: ";
                cin >> element;
                index = arr.search(element);
                if (index != -1) 
                {
                    cout << "element found at index " << index << endl;
                } 
                else 
                {
                    cout << "element not found" << endl;
                }
                break;
            case 7:
                arr.sort();
                break;
            case 8:
                arr.reverse();
                break;
            case 9:
                cout << "exiting!\n";
                break;
            default:
                cout << "invalid choice" << endl;
        }
    } 
    while (choice != 9);

    return 0;
}








