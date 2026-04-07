#include <iostream>
using namespace std;

// Function to display array
template <class T>
void display(T arr[], int size)
{
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Function to find maximum element
template <class T>
T findMax(T arr[], int size)
{
    T max = arr[0];

    for(int i = 1; i < size; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }

    return max;
}

// Function to reverse array
template <class T>
void reverseArray(T arr[], int size)
{
    T temp;

    for(int i = 0; i < size/2; i++)
    {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

int main()
{
    int intArr[] = {4, 7, 2, 9, 5};
    float floatArr[] = {2.5, 8.1, 1.4, 6.7};
    char charArr[] = {'A', 'D', 'B', 'C'};

    cout << "Integer Array: ";
    display(intArr, 5);

    cout << "Max Integer: " << findMax(intArr, 5) << endl;

    reverseArray(intArr, 5);
    cout << "Reversed Integer Array: ";
    display(intArr, 5);

    cout << endl;

    cout << "Float Array: ";
    display(floatArr, 4);

    cout << "Max Float: " << findMax(floatArr, 4) << endl;

    reverseArray(floatArr, 4);
    cout << "Reversed Float Array: ";
    display(floatArr, 4);

    cout << endl;

    cout << "Character Array: ";
    display(charArr, 4);

    cout << "Max Character: " << findMax(charArr, 4) << endl;

    reverseArray(charArr, 4);
    cout << "Reversed Character Array: ";
    display(charArr, 4);

    return 0;
}
