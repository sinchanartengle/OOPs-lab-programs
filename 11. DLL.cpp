// Doubly Linked List
#include<iostream>

using namespace std;

class Node
{
    public:
    Node* prev;
    int data;
    Node* next;

    Node(int d = -1)
    {
        prev = next = NULL;
        data = d ;
    }
};

class DLL
{
    Node *head;
    Node *tail;
    int count;

    public:
    DLL()
    {
        head = tail = NULL;
        count = 0;
    }

    void display()
    {
        if(!head)
        {
            cout<<"Empyt LIST\n";
            return;
        }

        Node *p = head;
        while(p)
        {
            cout<<p->data<<" <=> ";
            p = p->next;
        }
    }

    void insert()
    {
        int pos,ele;
        cout<<"\nEnter the position to insert : ";
        cin>>pos;

        if(pos < 1 || pos > count+1 )
        {
            cout<<"InValid Position to insert\n";
            display();
            return;
        }

        cout<<"Enter the element to insert : ";
        cin>>ele;

        Node *temp = new Node(ele);

        //count == 0
        if(!head)
        {
            head = tail = temp;
            count = 1;
            display();
            return;
        }

        // Insert At Begin
        if(pos == 1)
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
            count += 1;
            display();
            return;
        }

        // Insert At End
        if(pos == count+1)
        {
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
            count += 1;
            display();
            return;
        }

        // Inserting in middle
        Node *p = head;
        for(int i=1;i<pos-1;i++)
        {
            p = p->next;
        }
        Node *q = p->next;
        temp->next = q;
        temp->prev = p;
        p->next = temp;
        q->prev = temp;
        count += 1;
        display();
        return;
    }

    void remove()
    {
        int pos;
        cout<<"\nEnter the pos to delete : ";
        cin>>pos;

        if(pos<=0 || pos > count)
        {
            cout<<"Invalid POSITON to delete\n";
            display();
            return;
        }

        // count == 0;
        if(!head)
        {
            display();
            return;
        }

        // count == 1
        if(count == 1 || head->next == NULL || head == tail)
        {
            delete head;
            head = tail = NULL;
            count == 0;
            display();
            return;
        }

        // Delete at Front
        if(pos == 1)
        {
            Node *temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
            temp = NULL;
            count += -1;
            display();
            return;
        }

        // Delete At End
        if(pos == count)
        {
            Node *p = tail->prev;
            delete tail;
            tail = p;
            tail->next = NULL;
            count += -1;
            display();
            return;
        }

        // Deleting in Between
        Node *p = head;
        for(int i=1;i<pos;i++)
        {
            p = p->next;
        }

        Node *q = p->prev;
        Node *r = p->next;

        delete p;
        q->next = r;
        r->prev = q;
        count += -1;
        display();
        return;
    }
};

int main()
{
    DLL dll;
    dll.display();

    dll.insert();
    dll.insert();
    dll.insert();
    dll.insert();
    dll.insert();
    dll.insert();

    dll.remove();
    dll.remove();

    dll.insert();
    dll.remove();
    dll.remove();
}