#include<iostream>

using namespace std;

template<typename t>
int partition(t arr[],int s,int e)
{
    t pivot = arr[s];

    int count = 0;
    for(int i=s+1;i<=e;i++)
    {
        if(arr[i] <= pivot)
        {
            count++;
        }
    }

    int pivot_index = s + count;
    swap(arr[s],arr[pivot_index]);

    int i = s;
    int j = e;
    while(i<pivot_index && j>pivot_index)
    {
        while(arr[i]<=pivot)
        {
            i++;
        }

        while(arr[j]>pivot)
        {
            j--;
        }

        if(i<pivot_index && j>pivot_index)
        {
            swap(arr[i++],arr[j--]);
        }
    }

    return pivot_index;

}

template <typename t>
void quick(t arr[],int s,int e)
{
    if(s>=e)
        return;
    
    int p = partition <t> (arr,s,e);

    quick(arr,s,p-1);
    quick(arr,p+1,e);
}

template <typename t>
void display(t arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

template <typename t>
void get_arr(t arr[],int n)
{
    cout<<"Enter the "<<n<<" elements : \n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}

int main()
{
    int n;
    cout<<"Enter the number of elements : ";
    cin>>n;

    int choice {};
    cout<<"Choose the type of numbers : \n";
    cout<<"1. Integers \n";
    cout<<"2. Floating point number \n";
    cout<<"Enter your choice : ";
    cin>>choice;

    int arr1[n];
    double arr2[n];


    switch(choice)
    {
        case 1 :    
                    get_arr<int>(arr1,n);
                    quick <int> (arr1,0,n-1);
                    display <int> (arr1,n);break;
        
        case 2 :    
                    get_arr<double>(arr2,n);
                    quick <double> (arr2,0,n-1);
                    display <double> (arr2,n);break;

        default :   cout<<"InValid Chocie\n";
    }
}