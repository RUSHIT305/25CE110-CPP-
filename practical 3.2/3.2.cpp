#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Recursive function to compute sum
// Time Complexity: O(n), Space Complexity: O(n) due to call stack
long long recursiveSum(const vector<int>& arr, int n) {
    if (n <= 0) return 0; // Base Case
    return arr[n - 1] + recursiveSum(arr, n - 1); // Recursive Step
}

// Iterative function to compute sum
// Time Complexity: O(n), Space Complexity: O(1)
long long iterativeSum(const vector<int>& arr) {
    long long total = 0;
    for (int x : arr) {
        total += x;
    }
    return total;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Measure Iterative Performance
    auto startIter = high_resolution_clock::now();
    long long iterResult = iterativeSum(arr);
    auto endIter = high_resolution_clock::now();
    auto durationIter = duration_cast<nanoseconds>(endIter - startIter);

    // Measure Recursive Performance
    auto startRecur = high_resolution_clock::now();
    long long recurResult = recursiveSum(arr, n);
    auto endRecur = high_resolution_clock::now();
    auto durationRecur = duration_cast<nanoseconds>(endRecur - startRecur);

    cout << "\n--- Results ---" << endl;
    cout << "Iterative Sum: " << iterResult << " (Time: " << durationIter.count() << " ns)" << endl;
    cout << "Recursive Sum: " << recurResult << " (Time: " << durationRecur.count() << " ns)" << endl;

    return 0;
}

