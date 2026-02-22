#include <iostream>
using namespace std;
class Inventory
{
    string name;
    int id;
    float price;
    int quantity;
    public:
    Inventory()
    {
        name="null";
        id=0;
        price=0;
        quantity=1;
    }
    Inventory(string name_input,int id_input,float price_input,int quantity_input)
    {
        name=name_input;
        id=id_input;
        price=price_input;
        quantity=quantity_input;
    }
    void sell();
    void add_stock();
    void view_item_info();
};
