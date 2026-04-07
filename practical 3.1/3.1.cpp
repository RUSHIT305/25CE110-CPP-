#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Class definition to store employee records
class Employee {
private:
    string name;
    float basicSalary;
    float bonus;

public:
    // Constructor to initialize details, with a default bonus (1000)
    Employee(string empName, float bSalary, float bns = 1000.0) {
        name = empName;
        basicSalary = bSalary;
        bonus = bns;
    }

    // Inline function to compute total salary
    inline float calculateTotalSalary() const {
        return basicSalary + bonus;
    }

    // Member function to display employee details
    void displayEmployee() const {
        cout << "Name: " << name
             << "\t| Basic Salary: " << basicSalary
             << "\t| Bonus: " << bonus
             << "\t| Total: " << calculateTotalSalary() << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    // Dynamic storage of employee records (Scalability)
    Employee** employees = new Employee*[n];

    for (int i = 0; i < n; ++i) {
        string name;
        float basic, bonus;
        cout << "\nEnter Name for Employee " << i + 1 << ": ";
        cin >> name;
        cout << "Enter Basic Salary: ";
        cin >> basic;
        cout << "Enter Bonus (Enter -1 for default 1000): ";
        cin >> bonus;

        // Handling custom or default bonus via Constructor
        if (bonus == -1) {
            employees[i] = new Employee(name, basic);
        } else {
            employees[i] = new Employee(name, basic, bonus);
        }
    }

    // Displaying all employee details
    cout << "\n--- Employee Payroll Details ---\n";
    for (int i = 0; i < n; ++i) {
        employees[i]->displayEmployee();
    }

    // Freeing allocated memory
    for (int i = 0; i < n; ++i) {
        delete employees[i];
    }
    delete[] employees;

    return 0;
}

