#include <iostream>
using namespace std;

class Bank_Account
{
private:
    string name;
    double account_number;
    long double balance;

public:
    static int number;

    Bank_Account() {}

    Bank_Account(string n, long double b)
    {
        name = n;
        balance = b;
        account_number = 1000 + number;
    }

    int search_account(double acct)
    {
        if (acct == account_number)
            return 1;
        return 0;
    }

    void view_bal()
    {
        cout << "Name: " << name << endl;
        cout << "Account Number: " << account_number << endl;
        cout << "Balance: " << balance << endl;
    }

    void deposit()
    {
        long double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        balance += amount;
        cout << "Deposit successful.\n";
    }

    void withdraw()
    {
        long double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount > balance)
            cout << "Insufficient balance!\n";
        else
        {
            balance -= amount;
            cout << "Withdrawal successful.\n";
        }
    }
};

int Bank_Account::number = 0;

int main()
{
    Bank_Account user[10];
    int choice, i;
    string name;
    double acct_no;
    long double balance;

    while (true)
    {
        cout << "\nWelcome to the Bank!\n";
        cout << "1. Create Account\n";
        cout << "2. View Balance\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Exit\n";

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter Initial Balance: ";
            cin >> balance;

            user[Bank_Account::number] = Bank_Account(name, balance);
            Bank_Account::number++;

            cout << "Account Created!\n";
            cout << "Account Number: " << 1000 + Bank_Account::number - 1 << endl;
            break;

        case 2:
        case 3:
        case 4:

            cout << "Enter Account Number: ";
            cin >> acct_no;

            for (i = 0; i < Bank_Account::number; i++)
            {
                if (user[i].search_account(acct_no))
                {
                    if (choice == 2)
                        user[i].view_bal();
                    else if (choice == 3)
                        user[i].deposit();
                    else
                        user[i].withdraw();
                    break;
                }
            }

            if (i == Bank_Account::number)
                cout << "Account not found!\n";

            break;

        case 5:
            cout << "Visit Again!\n";
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
