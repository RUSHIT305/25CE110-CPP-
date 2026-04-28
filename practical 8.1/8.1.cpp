#include <iostream>
#include <limits>
#include <stdexcept>

int main() {
    int num, den;

    std::cout << "Enter two integers (numerator and denominator): ";

    try {
        // 1. Handle Invalid Input (Non-integers) during extraction
        if (!(std::cin >> num >> den)) {
            throw std::runtime_error("Invalid input: Please enter integer values only.");
        }

        // 2. Handle Division by Zero before evaluation
        if (den == 0) {
            throw std::runtime_error("Math error: Attempted to divide by zero.");
        }

        // Immediate evaluation
        std::cout << "Result: " << num / den << std::endl;

    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
