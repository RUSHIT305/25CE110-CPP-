#include <iostream>
#include <queue>
#include <vector>

// Forward declaration
class Fahrenheit;

class Celsius {
private:
    double temp;
public:
    Celsius(double t = 0) : temp(t) {}

    // Type-conversion operator: Celsius to Fahrenheit
    operator Fahrenheit() const;

    // Equality operator
    bool operator==(const Celsius& other) const {
        return (this->temp == other.temp);
    }

    double getTemp() const { return temp; }
};

class Fahrenheit {
private:
    double temp;
public:
    Fahrenheit(double t = 0) : temp(t) {}

    // Type-conversion operator: Fahrenheit to Celsius
    operator Celsius() const {
        return Celsius((temp - 32.0) * 5.0 / 9.0);
    }

    // Equality operator
    bool operator==(const Fahrenheit& other) const {
        return (this->temp == other.temp);
    }

    double getTemp() const { return temp; }
};

// Definition of Celsius to Fahrenheit conversion
Celsius::operator Fahrenheit() const {
    return Fahrenheit((temp * 9.0 / 5.0) + 32.0);
}

int main() {
    // 1. Conversions & Comparison
    Celsius c1(100.0);
    Fahrenheit f1 = c1; // Automatic conversion
    std::cout << c1.getTemp() << "C is " << f1.getTemp() << "F\n";

    Fahrenheit f2(32.0);
    Celsius c2 = f2;
    std::cout << f2.getTemp() << "F is " << c2.getTemp() << "C\n";

    if (c2 == Celsius(0)) {
        std::cout << "Freezing point comparison successful.\n";
    }

    // 2. Storage: Dynamic Queue (FIFO)
    std::queue<Celsius> tempQueue;
    tempQueue.push(Celsius(25.0));
    tempQueue.push(c2); // Storing converted object

    std::cout << "Queue front: " << tempQueue.front().getTemp() << "C\n";
    tempQueue.pop();

    // 3. Storage: Fixed Array
    Fahrenheit forecast[3] = {Fahrenheit(70.0), Fahrenheit(72.0), Fahrenheit(68.0)};
    std::cout << "Array middle element: " << forecast[1].getTemp() << "F\n";

    return 0;
}
