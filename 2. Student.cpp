#include<iostream>

using namespace std;

class Student
{
    public:
    string USN;
    string Name;
    int marks[3];
    double avg;

    void get_data()
    {
        cout<<"---------------------------------------------------\n";
        cout<<"USN : ";
        cin>>USN;
        cout<<"Name : ";
        cin>>Name;
        cout<<"Marks of test 1,test 2 and test 3 : ";
        cin>>marks[0]>>marks[1]>>marks[2];
        calculate();
        cout<<"====================================================\n";
    }

    void calculate()
    {
        int lowest = marks[0];
        int sum = 0;
        for(int i : marks)
        {
            if(i<lowest)
                lowest = i;

            sum += i;
        }
        sum = sum - lowest;
        avg = sum / 2.0;
    }

    void display()
    {
        cout<<"====================================================\n";
        cout<<"USN : "<<USN<<"\n";
        cout<<"Name : "<<Name<<"\n";
        cout<<"Avg Marks (best of 2) : "<<avg<<"\n";
        cout<<"====================================================\n";
    }
};

int main()
{
    int n;
    cout<<"Enter the number of stduents : ";
    cin>>n;

    Student studs[n];

    for(int i=0;i<n;i++)
    {
        cout<<"Enter the student "<<i+1<<" details : \n";
        studs[i].get_data();
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<"Student "<<i+1<<" details : \n";
        studs[i].display();
    }

}