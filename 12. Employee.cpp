// Non type arguments must be known at compile time;

#include<iostream>

using namespace std;


template<typename t,int size>
class arr
{
};

template <typename T = int>
void display(T value = "kiran") {
    cout << "Value: " << value << endl;
}

int main()
{
    int n;
    cout<<"Enter the size : ";
    cin>>n;

    // arr<int,n> obj;
    display();
}