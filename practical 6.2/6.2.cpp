#include <iostream>
#include <string>
#include <vector>
#include <map>

// 1. Base Level - Person Class
class Person {
protected:
    std::string name;
    int age;

public:
    Person(std::string n, int a) : name(n), age(a) {}

    virtual void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

// 2. Intermediate Level - Employee Class (Inherits from Person)
class Employee : public Person {
protected:
    int employeeID;

public:
    // Constructor chaining
    Employee(std::string n, int a, int id) : Person(n, a), employeeID(id) {}

    void display() const override {
        Person::display(); // Call base display
        std::cout << "Employee ID: " << employeeID << std::endl;
    }

    int getID() const { return employeeID; }
};

// 3. Top Level - Manager Class (Inherits from Employee)
class Manager : public Employee {
private:
    std::string department;

public:
    // Constructor chaining
    Manager(std::string n, int a, int id, std::string dept)
        : Employee(n, a, id), department(dept) {}

    void display() const override {
        Employee::display(); // Call intermediate display
        std::cout << "Department: " << department << " (Manager)" << std::endl;
    }
};

int main() {
    // Create Managers
    Manager m1("Alice", 35, 101, "Engineering");
    Manager m2("Bob", 40, 102, "Marketing");

    // Strategy 1: Efficient Retrieval Method (std::map)
    std::map<int, Manager> managerMap;
    managerMap.insert({m1.getID(), m1});
    managerMap.insert({m2.getID(), m2});

    std::cout << "--- Retrieval-Based Method (Map) ---" << std::endl;
    managerMap[101].display();
    std::cout << std::endl;

    // Strategy 2: Static Storage Method (std::vector)
    std::vector<Manager> managerList = {m1, m2};

    std::cout << "--- Static Storage Method (Vector) ---" << std::endl;
    for (const auto& mgr : managerList) {
        mgr.display();
        std::cout << "-----------------" << std::endl;
    }

    return 0;
}
