#include <iostream>
using namespace std;

int main()
{
    int n, m;

    cout << "Enter size of first array: ";
    cin >> n;

    cout << "Enter size of second array: ";
    cin >> m;

    // Dynamic allocation
    int *arr1 = new int[n];
    int *arr2 = new int[m];
    int *merged = new int[n + m];

    cout << "Enter elements of first sorted array:\n";
    for(int i = 0; i < n; i++)
        cin >> arr1[i];

    cout << "Enter elements of second sorted array:\n";
    for(int i = 0; i < m; i++)
        cin >> arr2[i];

    int i = 0, j = 0, k = 0;

    // Merge arrays
    while(i < n && j < m)
    {
        if(arr1[i] <= arr2[j])
            merged[k++] = arr1[i++];
        else
            merged[k++] = arr2[j++];
    }

    // Copy remaining elements
    while(i < n)
        merged[k++] = arr1[i++];

    while(j < m)
        merged[k++] = arr2[j++];

    cout << "Merged Sorted Array:\n";
    for(int x = 0; x < n + m; x++)
        cout << merged[x] << " ";

    cout << endl;

    // Free memory
    delete[] arr1;
    delete[] arr2;
    delete[] merged;

    return 0;
}
