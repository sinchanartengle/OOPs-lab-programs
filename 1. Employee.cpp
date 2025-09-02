#include<iostream>

using namespace std;

class Employee
{
    public:
    char Employee_Number[10];    
    string Employee_Name; 
    double Basic;
    double DA; 
    double IT;
    double Gross_sal; 
    double Net_Sal;

    void calculate()
    {
        DA = 0.52 * Basic;
        Gross_sal = Basic + DA;
        IT = 0.30 * Gross_sal;
        Net_Sal = Gross_sal - IT;
    }

    void get_data()
    {
        cout<<"--------------------------------\n";
        cout<<"Number : ";
        cin>>Employee_Number;

        cout<<"Name : ";
        cin>>Employee_Name;

        cout<<"Basic : ";
        cin>>Basic;
        calculate();
        cout<<"==================================\n";

    }

    

    void display()
    {
        cout<<"==================================\n";
        cout<<"Number : "<<Employee_Number<<"\n";
        cout<<"Name : "<<Employee_Name<<"\n";
        cout<<"Basic : "<<Basic<<"\n";
        cout<<"Net Salary : "<<Net_Sal<<"\n";
        cout<<"==================================\n";
    }    
};

int main()
{
    int n;
    cout<<"Enter the number of employees : ";
    cin>>n;
    
    Employee emps[n];

    for(int i=0;i<n;i++)
    {
        cout<<"Enter the Employee "<<i+1<<" details : \n";
        emps[i].get_data();
    }

    for(int i=0;i<n;i++)
    {
        cout<<"Employee "<<i+1<<" details : \n";
        emps[i].display();
    }
}