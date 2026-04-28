#include <iostream>
#include <set>
#include <vector>
#include <iterator>

int main() {
    std::set<int> uniqueNumbers;
    int input, count;

    std::cout << "How many integers would you like to enter? ";
    std::cin >> count;

    std::cout << "Enter " << count << " integers (duplicates allowed):" << std::endl;
    for (int i = 0; i < count; ++i) {
        std::cin >> input;
        uniqueNumbers.insert(input);
    }

    // Displaying elements using an iterator
    std::cout << "\nUnique elements in sorted order:" << std::endl;
    std::set<int>::iterator it;
    for (it = uniqueNumbers.begin(); it != uniqueNumbers.end(); ++it) {
        std::cout << *it << " ";
    }

    // Optional: Conversion to vector
    std::vector<int> resultVector(uniqueNumbers.begin(), uniqueNumbers.end());

    return 0;
}
