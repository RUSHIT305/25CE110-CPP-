#include <iostream>
using namespace std;

class Calculator {
public:
    // Overload 1: Integers
    int add(int a, int b) { return a + b; }

    // Overload 2: Floats
    double add(double a, double b) { return a + b; }

    // Overload 3: Mixed
    double add(int a, double b) { return a + b; }
};

int main() {
    Calculator calc;
    cout << "Int Sum: " << calc.add(5, 10) << endl;
    cout << "Double Sum: " << calc.add(5.5, 10.5) << endl;
    cout << "Mixed Sum: " << calc.add(5, 10.5) << endl;
    return 0;
}
