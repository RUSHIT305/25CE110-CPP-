#include <iostream>
#include <iomanip>
using namespace std;

// ✅ User-defined manipulator for currency
ostream& currency(ostream& output) {
    output << "₹ ";   // You can change to "$ " if needed
    return output;
}

int main() {
    // Sample student data
    string names[] = {"Amit", "Riya", "Karan"};
    int marks[] = {85, 92, 78};
    float fees[] = {25000.5, 30000.75, 27000.25};

    int n = 3;

    // Table Header
    cout << setfill('=') << setw(50) << "=" << endl;
    cout << setfill(' ')
         << left << setw(15) << "Name"
         << setw(10) << "Marks"
         << setw(15) << "Fees" << endl;

    cout << setfill('-') << setw(50) << "-" << endl;

    // Data Output
    for (int i = 0; i < n; i++) {
        cout << setfill(' ')
             << left << setw(15) << names[i]
             << setw(10) << marks[i]
             << currency << fixed << setprecision(2) << fees[i]
             << endl;
    }

    cout << setfill('=') << setw(50) << "=" << endl;

    return 0;
}
