// Circular queue using arr?


#include<iostream>

using namespace std;

template <typename t>
class Queue
{
    int size;
    int front;
    int rear;
    t *q;

    public:

    Queue()
    {
        cout<<"Enter the size of the queue : ";
        cin>>size;
        size++;
        q = new t[size];

        front = rear = 0;
    }

    bool isempty()
    {
        return front == rear;
    }

    bool isfull()
    {
        return (rear+1)%size == front;
    }

    void push(t x)
    {
        //cout<<"front = "<<front<<" , rear = "<<rear<<"\n";
        if(isfull())
        {
            cout<<"Queue is FULL cannot insert "<<x<<"\n";
            return;
        }

        rear = (rear+1) % size;
        q[rear] = x;
        cout<<x<<" successfully inserted\n";
    }

    void pop()
    {
        if(isempty())
        {
            cout<<"Queue is Empty\n";
            return;
        }

        front = (front+1)%size;
        cout<<q[front]<<" is popped \n";
        return;
    }

    void display()
    {
        if(isempty())
        {
            cout<<"Empty queue to display\n";
            return;
        }

        for(int i=(front+1)%size; i != (rear+1)%size ;)
        {
            cout<<q[i]<<"<-";
            i = (i+1)%size;
        }
        cout<<"\n";
    }
};

int main()
{
    cout<<"Integer Queue\n";
    Queue <int> q1;
    q1.push(10);
    q1.push(20);
    q1.display();
    q1.push(30);
    q1.display();
    q1.pop();
    q1.display();
    q1.pop();
    q1.display();
    q1.pop();

    cout<<"=========================\n";
    cout<<"\nDouble Queue\n";
    Queue <double> q2;
    q2.push(1.0);
    q2.push(2.20);
    q2.display();
    q2.push(3.3);
    q2.display();
    q2.pop();
    q2.display();
    q2.pop();
    q2.display();
    q2.pop();
}