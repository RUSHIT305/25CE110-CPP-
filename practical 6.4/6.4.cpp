#include <iostream>
#include <vector>
#include <string>

// --- Base Class ---
class Account {
protected:
    std::string accountNumber;
    double balance;

public:
    Account(std::string accNum, double bal) : accountNumber(accNum), balance(bal) {}
    virtual ~Account() {} // Virtual destructor for proper cleanup

    virtual void deposit(double amount) {
        balance += amount;
    }
    virtual void withdraw(double amount) {
        if (amount <= balance) balance -= amount;
        else std::cout << "Insufficient funds.\n";
    }
    virtual void display() {
        std::cout << "Acc: " << accountNumber << " | Bal: $" << balance << std::endl;
    }
};

// --- Derived: Savings ---
class SavingsAccount : public Account {
    double interestRate;
public:
    SavingsAccount(std::string accNum, double bal, double rate)
        : Account(accNum, bal), interestRate(rate) {}
    void applyInterest() { balance += balance * interestRate; }
};

// --- Derived: Current ---
class CurrentAccount : public Account {
    double overdraftLimit;
public:
    CurrentAccount(std::string accNum, double bal, double limit)
        : Account(accNum, bal), overdraftLimit(limit) {}
    void withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) balance -= amount;
        else std::cout << "Overdraft limit exceeded.\n";
    }
};
