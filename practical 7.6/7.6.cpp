#include <iostream>

class Base {
public:
    Base() { std::cout << "Base Constructor\n"; }
    // Non-virtual destructor: causes resource leak in polymorphic deletion
    ~Base() { std::cout << "Base Destructor\n"; }
};

class Derived : public Base {
    int* data;
public:
    Derived() {
        std::cout << "Derived Constructor (Allocating Resource)\n";
        data = new int(100);
    }
    ~Derived() {
        std::cout << "Derived Destructor (Releasing Resource)\n";
        delete data;
    }
};

int main() {
    std::cout << "--- Non-Virtual Destructor Test ---\n";
    Base* ptr = new Derived();
    delete ptr; // Only calls ~Base(), leaking 'data'
    return 0;
}
