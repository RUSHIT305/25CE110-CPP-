#include <iostream>
#include <string>
#include <stdexcept>

// Basic array to store transaction and flow logs
std::string logs;
int logCount = 0;

void addLog(const std::string& msg) {
    if (logCount < 50) logs[logCount++] = msg;
}

class BankAccount {
    double balance;
public:
    BankAccount(double initial) : balance(initial) {
        addLog("BankAccount: Initialized with balance " + std::to_base_cast<std::string>(initial));
    }

    void deposit(double amount) {
        addLog("Entering: BankAccount::deposit");
        if (amount <= 0) {
            addLog("Error: Invalid deposit amount");
            throw std::invalid_argument("Deposit must be positive.");
        }
        balance += amount;
        addLog("Exiting: BankAccount::deposit (Success)");
    }

    void withdraw(double amount) {
        addLog("Entering: BankAccount::withdraw");
        if (amount > balance) {
            addLog("Error: Insufficient balance for withdrawal");
            throw std::runtime_error("Insufficient balance!");
        }
        balance -= amount;
        addLog("Exiting: BankAccount::withdraw (Success)");
    }

    double getBalance() const { return balance; }
};

// Wrapper function to demonstrate stack unwinding
void processTransaction(BankAccount& acct, double amount, bool isDeposit) {
    addLog("Entering: processTransaction");
    if (isDeposit) acct.deposit(amount);
    else acct.withdraw(amount);
    addLog("Exiting: processTransaction");
}

int main() {
    BankAccount myAcct(1000.0);

    try {
        addLog("Main: Attempting valid deposit");
        processTransaction(myAcct, 500, true);

        addLog("Main: Attempting invalid withdrawal (Triggering Exception)");
        processTransaction(myAcct, 2000, false);
    } catch (const std::exception& e) {
        addLog("Main: Caught Exception - " + std::string(e.what()));
    }

    // Display logs to show control flow and stack unwinding
    std::cout << "\n--- Transaction Flow Logs ---\n";
    for (int i = 0; i < logCount; ++i) {
        std::cout << "[" << i + 1 << "] " << logs[i] << "\n";
    }

    return 0;
}
