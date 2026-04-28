#include <iostream>
#include <vector>
#include <algorithm> // For std::reverse
#include <iterator>

void printVector(const std::vector<int>& v) {
    for (int i : v) std::cout << i << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> numbers;
    int input;

    std::cout << "Enter integers (type non-numeric to stop): ";
    while (std::cin >> input) {
        numbers.push_back(input);
    }

    if (numbers.empty()) return 0;

    // Method 1: Using std::reverse() from <algorithm>
    std::vector<int> v1 = numbers;
    std::reverse(v1.begin(), v1.end());
    std::cout << "Reversed using std::reverse: ";
    printVector(v1);

    // Method 2: Manual reversal using iterators and std::swap
    std::vector<int> v2 = numbers;
    auto left = v2.begin();
    auto right = v2.end();

    // Move 'right' iterator to the last element
    if (left != right) {
        --right;
        while (left < right) {
            std::swap(*left, *right);
            ++left;
            --right;
        }
    }

    std::cout << "Reversed manually using iterators: ";
    printVector(v2);

    return 0;
}
