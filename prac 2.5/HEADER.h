#include <iostream>
using namespace std;
class Bank_Loan
{
    string name;
    int loan_id;
    float loan_amount;
    int interest_rate;
    float tenure;
    public:
    Bank_Loan()
    {
        name="null";
        loan_id=0;
        loan_amount=1000;
        interest_rate=8;
        tenure=1;
    }
    Bank_Loan(string user_name_input,int loan_id_input,float loan_amount_input,float interest_rate_input,int tenure_input)
    {
        name=user_name_input;
        loan_id=loan_id_input;
        loan_amount=loan_amount_input;
        interest_rate=interest_rate_input;
        tenure=tenure_input;
    }
    inline float EMI();
    void display();

};
