#include<iostream>

using namespace std;

class Complex
{
    int real;
    int img;

    public:
    Complex(int r=0,int i=0)
    {
        real = r;
        img = i;
    }

    void get_data()
    {
        cout<<"Enter the real and imaginary part : ";
        cin>>real>>img;
    }

    void display()
    {
        cout<<"Complex Number : "<<real<<"+i("<<img<<")\n";
    }

    friend Complex ADD(int s,Complex C);
    friend Complex ADD(Complex C1,Complex C2);
};

Complex ADD(int s,Complex C)
{
    int r = s + C.real;
    int i = 0 + C.img;

    Complex res {r,i};
    return res;
}

Complex ADD(Complex C1,Complex C2)
{
    int r = C1.real + C2.real;
    int i = C1.img + C2.img;
    
    Complex res {r,i};
    return res;
}

int main()
{
    Complex C1,C2;
    cout<<"Complex Number 1 : \n";
    C1.get_data();
    C1.display();

    cout<<"Complex Number 2 : \n";
    C2.get_data();
    C2.display();

    cout<<"C1 + C2 : \n";
    Complex C3 = ADD(C1,C2);
    C3.display();

    int n {};
    cout<<"Enter the Integer to add to Complex Numbers : ";
    cin>>n;

    C3 = ADD(n,C1);
    cout<<"C1 + "<<n<<" : \n";
    C3.display();

    C3 = ADD(n,C2);
    cout<<"C2 + "<<n<<" : \n";
    C3.display();
}