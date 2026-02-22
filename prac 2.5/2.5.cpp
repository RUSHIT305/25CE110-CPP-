#include <iostream>
#include "header.h"
using namespace std;
int main()
{
    int choice,i,no;
    int t=0;
    int loan_no;
    string name;
    int loan_id;
    float loan_amount;
    int interest_rate;
    float tenure;
    Bank_Loan loan[10];
    menu:
    cout << "Welcome to the Inventory!" << endl
         << "1. Add User" << endl
         << "2. View Loan Summary" << endl
         << "3. Exit" << endl;
    cin >> choice;
    switch(choice)
    {
        case 1:
            cout << "Enter User Name" << endl;
            cin.ignore();
            getline(cin,name);
            cout << "Loan Principal Amount: " << endl;
            cin >> loan_amount;
            cout << "Loan Tenure: " << endl;
            cin >> tenure;
            cout << "Interest Rate: " << endl;
            cin >> interest_rate;
            loan[t] = Bank_Loan(name,t,loan_amount,interest_rate,tenure);
            t++;
            goto menu;
        case 2:
            cout << "Enter Loan ID: ";
            cin >> loan_id;
            loan[loan_id].display();
            goto menu;
        case 3:
            break;
        default:
            cout << "Invalid Choice, Please try again!" << endl;
            goto menu;
    }

    cout << "Visit Again!" << endl;
}
