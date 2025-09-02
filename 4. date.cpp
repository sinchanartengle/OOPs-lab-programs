// DATE.cpp
#include<iostream>

using namespace std;

bool leapyear(int year);
int NODM(int month, int year);
class DATE
{
    public:
    int day;
    int month;
    int year;

    DATE() {}
    friend istream& operator>>(istream &in,DATE &d1);
    friend ostream& operator<<(ostream &os,DATE &d1);
    friend bool operator==(DATE &d1,DATE &d2);
    friend bool operator!=(DATE &d1,DATE &d2);
    friend DATE operator+(DATE d1,int n);
    friend int operator-(DATE d1,DATE d2);
};


int main()
{
    DATE d1,d2,d3;

    cout<<"Date 1 : \n";
    cin>>d1;

    cout<<"Date 1 : \n";
    cin>>d1;
    cout<<d1;

    cout<<"Date 2 : \n";
    cin>>d2;
    cout<<d2;

    // d2 must be greater than or equal to d1 ;
    cout<<"d2 - d1 = "<<d2-d1<<" days\n";

    int n;
    cout<<"Enter no of days to add : ";
    cin>>n;

    d3 = d1 + n;
    cout<<"d1 + "<<n<<" = "<<d3<<"\n";

    d3 = d2 + n;
    cout<<"d2 + "<<n<<" = "<<d3<<"\n";
}

bool leapyear(int year)
{
    if(year % 4 == 0)
    {
        if(year%100 == 0)
        {
            if(year % 400 == 0)
                return true;

            return false;
        }
        return true;
    }
    return false;
}

int NODM(int month,int year)
{
    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: return 31;
        case 4:
        case 6:
        case 9:
        case 11: return 30;
        case 2: if(leapyear(year))
                    return 29;
                return 28;
        
        default: cout<<"Invalid mOnth \n"; return -1;
    }
}


istream& operator>>(istream &in,DATE &d1)
{
    int d,m,y;
    cout<<"Enter day,month,year : ";
    in>>d>>m>>y;

    if(d <= 0 || m <=0 || y<= 0|| m > 12 || d > NODM(m,y) )
    {
        cout<<"InValid Date \n";
        return in;
    }
    d1.day = d;
    d1.month = m;
    d1.year = y;

    return in;
}

ostream& operator<<(ostream &os,DATE &d1)
{
    os<<d1.day<<"-"<<d1.month<<"-"<<d1.year<<"\n";
    return os;
}

bool operator==(DATE &d1,DATE &d2)
{
    return (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year);
}

bool operator!=(DATE &d1,DATE &d2)
{
    return !(d1==d2);
}

DATE operator+(DATE d1,int n)
{
    DATE d2 = d1;

    for(int i=0;i<n;i++)
    {
        d2.day += 1;
        if(d2.day > NODM(d2.month,d2.year))
        {
            d2.day = 1;
            d2.month += 1;
            if(d2.month > 12)
            {
                d2.month = 1;
                d2.year += 1;
            }
        }
    }
    return d2;
}


int operator-(DATE d1,DATE d2)
{
    int n = 0;
    while(d1 != d2)
    {
        n++;
        d2 = d2 + 1;
    }
    return n;
}

