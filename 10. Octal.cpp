#include<iostream>

using namespace std;

class OCTAL
{
    int dec;
    int oct[10];
    int count;

    public:
    OCTAL(int x)
    {
        count = 0;
        dec = x;
        dec_to_oct(x);
    }

    OCTAL operator=(int x)
    {
        dec = x;
        dec_to_oct(x);
        return *this;
    }

    int operator+(int k)
    {
        return dec + k;
    }

    void dec_to_oct(int x)
    {
        int arr[10];
        int i=0,rem {};
        while(x)
        {
            rem = x%8;
            arr[i] = rem;
            x = x/8;
            // cout<<"rem : "<<rem<<" x : "<<x<<"\n";
            i++;   
        }

        count = i;
        int n = count-1;

        // cout<<"count : "<<count<<"\n";
        int j=0;
        for(int i=n;i>=0;i--)
        {
            oct[j] = arr[i];
            j++;
        }
    }

    friend ostream& operator<<(ostream& os,OCTAL o);
};

ostream& operator<<(ostream& os,OCTAL o)
{
    os<<"OCTAL num : ";
    for(int i=0;i<o.count;i++)
    {
        os<<o.oct[i];
    }
    cout<<" ("<<o.dec<<")";
    os<<"\n";
    return os;
}

int main()
{
    OCTAL h = 10;
    cout<<h;

    int k = 20;
    int y = h + k;
    cout<<"Additon of \n";
    cout<<h;
    cout<<"Decimal number : "<<k<<" is ";
    cout<<y<<"\n";;
}