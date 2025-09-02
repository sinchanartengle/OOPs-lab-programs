#include<iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node(int d = -1)
    {
        data = d;
        next = NULL;
    }
};

class List
{
    Node *head;
    // Node *tail;
    int count;

    public:
    List()
    {
        head = NULL;
        count = 0;
    }

    void display()
    {
        cout<<"==================================\n";
        cout<<"No of Nodes : "<<count<<"\n";

        Node *temp = head;
        while(temp)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<'\n';
        cout<<"==================================\n";
    }

    void insert_at_front()
    {
        int key;
        cout<<"Enter the value to insert : ";
        cin>>key;

        Node *temp = new Node(key);
        
        if(!head)
        {
            head = temp;
            count = 1;
            display();
            return;
        }

        temp->next = head;
        head = temp;
        count += 1;
        display();
        return;
    }

    void delete_at_front()
    {
        if(!head)
        {
            cout<<"Empty List to delete \n";
            count = 0;
            display();
            return;
        }

        Node *temp = head;
        head = head->next;
        cout<<temp->data<<" deleted\n";
        delete temp;
        temp = NULL;
        count -= 1;
        display();
        return;
    }
};

int main()
{
    List list;
    
    int choice {};

    while(choice != 3)
    {
        cout<<"Linked List Operations : \n";
        cout<<"1. Insert at Front \n";
        cout<<"2. Delete at Front\n";
        cout<<"3. Exit \n";
        cout<<"Enter you choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1: list.insert_at_front();break;
            case 2: list.delete_at_front();break;
            case 3: cout<<"Thank You \n";break;
            default : cout<<"InValid Choice \n";break;
        }
    }
}