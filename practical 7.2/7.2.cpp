#include <iostream>
#include <vector>
#include <numeric>

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overload + operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload - operator
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Method to display complex number
    void display() const {
        std::cout << real << (imag >= 0 ? " + " : " - ") << std::abs(imag) << "i" << std::endl;
    }
};

int main() {
    // 1. Testing Arithmetic Operators
    Complex c1(5.0, 3.0);  // 5 + 3i
    Complex c2(2.0, 1.0);  // 2 + 1i

    std::cout << "c1: "; c1.display();
    std::cout << "c2: "; c2.display();

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    std::cout << "Sum (c1 + c2): "; sum.display();
    std::cout << "Difference (c1 - c2): "; diff.display();

    // 2. Optional: Managing a collection of complex objects
    std::vector<Complex> complexNumbers = {Complex(1, 2), Complex(3, 4), Complex(5, 6)};

    std::cout << "\nCollection Testing:" << std::endl;
    Complex totalSum(0,0);
    for(const auto& c : complexNumbers) {
        c.display();
        totalSum = totalSum + c;
    }
    std::cout << "Total Sum of Collection: "; totalSum.display();

    return 0;
}
