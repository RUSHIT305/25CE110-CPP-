#include <iostream>
#include <string>
using namespace std;

class DigitalSavingsAccount {
private:
    string customerName;
    int accountID;
    double balance;

public:

    DigitalSavingsAccount(string name, int id, double initialBalance = 0) {
        customerName = name;
        accountID = id;

        if (initialBalance >= 0)
            balance = initialBalance;
        else
            balance = 0;
    }


    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful: " << amount << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }


    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount." << endl;
        }
        else if (amount > balance) {
            cout << "Insufficient balance. Withdrawal denied." << endl;
        }
        else {
            balance -= amount;
            cout << "Withdrawal successful: " << amount << endl;
        }
    }


    void displaySummary() {
        cout << "\nAccount Summary" << endl;
        cout << "--------------------------" << endl;
        cout << "Customer Name : " << customerName << endl;
        cout << "Account ID    : " << accountID << endl;
        cout << "Balance       : " << balance << endl;
    }
};

int main() {

    DigitalSavingsAccount acc1("Rahul Mehta", 101);
    DigitalSavingsAccount acc2("Priya Singh", 102, 3000);


    acc1.deposit(1500);
    acc1.withdraw(500);


    acc2.deposit(2000);


    acc1.withdraw(5000);


    acc1.displaySummary();
    acc2.displaySummary();

    return 0;
}

