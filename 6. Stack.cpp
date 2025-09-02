#include<iostream>

#define MAX 5

using namespace std;


class Stack
{
    int top;
    int size;
    int *s;
    
    public:
    Stack(int n = MAX)
    {
        size = n;
        s = new int[size];
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == size-1;
    }

    Stack operator-()
    {
        if(isEmpty())
        {
            cout<<"Stack UnderFlow\n";
            return *this;
        }
        int x = s[top--];
        cout<<"Pop : "<<x<<"\n";
        return *this;
    }

    friend Stack operator+(Stack &s1,int ele);
    friend ostream& operator<<(ostream &os,Stack &s1);
};

int main()
{
    Stack s1;
    cout<<s1;

    s1 = s1 + 10;
    s1 = s1 + 20;
    s1 = s1 + 30;

    cout<<s1;

    // s1 = s1-;
    Stack s2;
    s2 = -s1;
    cout<<s2;
    // cout<<s1;
}

Stack operator+(Stack &s1,int ele)
{
    if(s1.isFull())
    {
        cout<<"Stack OverFlow \n";
    }
    else
    {
        s1.s[++(s1.top)] = ele;
    }
    return s1;
}

ostream& operator<<(ostream &os,Stack &s1)
{
    os<<"Stack : \n";
    for(int i=s1.top;i>=0;i--)
    {
        os<<"|"<<s1.s[i]<<"|\n";
    }

    return os;
}