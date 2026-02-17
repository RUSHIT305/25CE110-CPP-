#include <iostream>
using namespace std;

class Student
{
    string name;
    int roll_no;
    float m1,m2,m3;
    public:
    Student()
    {
        name = "null";
        roll_no=0;
        m1=0;
        m2=0;
        m3=0;
    }
    Student(string input_name,int roll,float marks1,float marks2,float marks3)
    {
        name = input_name;
        roll_no=roll;
        m1=marks1;
        m2=marks2;
        m3=marks3;
    }
    void get_average_marks()
    {
        cout <<"Student: "<< name << "Average Marks: " <<  ((m1+m2+m3)/3) << endl;
    }
};

int main()
{
    Student s1;
    Student s2("Megh",99,95.5,94.8,100);
    s1.get_average_marks();
    s2.get_average_marks();
    return 0;
}
