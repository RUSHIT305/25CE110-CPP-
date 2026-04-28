#include <iostream>
#include <cmath>
#include <exception>

// 1. Define the custom exception class
class NegativeNumberException : public std::exception {
public:
    // Override the what() method to return a custom error message
    const char* what() const noexcept override {
        return "Error: Cannot calculate the square root of a negative number.";
    }
};

int main() {
    double number;
    char choice;

    do {
        std::cout << "Enter a number to calculate its square root: ";
        std::cin >> number;

        // 2. Use a try-catch block for exception handling
        try {
            if (number < 0) {
                // 3. Throw the custom exception
                throw NegativeNumberException();
            }
            // 4. Calculate and display result if no exception
            std::cout << "Square root: " << sqrt(number) << std::endl;
        }
        catch (const NegativeNumberException& e) {
            // 5. Catch and handle the exception
            std::cerr << e.what() << std::endl;
        }

        std::cout << "Do you want to enter another number? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
