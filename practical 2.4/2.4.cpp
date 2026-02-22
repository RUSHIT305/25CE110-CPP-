#include <iostream>
#include "header.h"
using namespace std;
int main()
{
    int choice,i,no;
    int t=0;
    int item_no;
    string name;
    long double price;
    int quantity;
    Inventory item[10];
    menu:
    cout << "Welcome to the Inventory!" << endl
         << "1. Add Item" << endl
         << "2. View Item Summary" << endl
         << "3. Add Stock" << endl
         << "4. Sell Item" << endl
         << "5. Exit" << endl;
    cin >> choice;
    switch(choice)
    {
        case 1:
            cout << "Enter Item Name" << endl;
            cin.ignore();
            getline(cin,name);
            cout << "Enter Item's Price" << endl;
            cin >> price;
            cout << "Enter Item's Quantity" << endl;
            cin >> quantity;
            item[t] = Inventory(name,t,price,quantity);;
            t++;
            goto menu;
        case 2:
            for(i=0;i<t;i++)
            {
                item[i].view_item_info();
            }
            goto menu;
        case 3:
            cout << "Please enter your Item number" << endl;
            cin >> item_no;
            item[item_no].add_stock();
            goto menu;
        case 4:
            cout << "Please enter your Item number" << endl;
            cin >> item_no;
            item[item_no].sell();
            goto menu;
        case 5:
            break;
        default:
            cout << "Invalid Choice, Please try again!" << endl;
            goto menu;
    }

    cout << "Visit Again!" << endl;
}
