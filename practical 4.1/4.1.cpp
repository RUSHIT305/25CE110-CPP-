#include <iostream>
using namespace std;

class DynamicArray
{
private:
    int *arr;
    int size;

public:
    DynamicArray()
    {
        arr = NULL;
        size = 0;
    }

    // Insert element at end
    void insert(int value)
    {
        int *temp = new int[size + 1];

        for(int i = 0; i < size; i++)
            temp[i] = arr[i];

        temp[size] = value;

        delete[] arr;
        arr = temp;
        size++;
    }

    // Delete element from position
    void remove(int pos)
    {
        if(pos < 0 || pos >= size)
        {
            cout << "Invalid position\n";
            return;
        }

        int *temp = new int[size - 1];

        for(int i = 0, j = 0; i < size; i++)
        {
            if(i != pos)
                temp[j++] = arr[i];
        }

        delete[] arr;
        arr = temp;
        size--;
    }

    // Display array
    void display()
    {
        if(size == 0)
        {
            cout << "Array is empty\n";
            return;
        }

        cout << "Array elements: ";
        for(int i = 0; i < size; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main()
{
    DynamicArray arr;
    int choice, value, pos;

    while(true)
    {
        cout << "\n1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                arr.insert(value);
                break;

            case 2:
                cout << "Enter position to delete: ";
                cin >> pos;
                arr.remove(pos);
                break;

            case 3:
                arr.display();
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}
