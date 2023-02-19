#include<iostream>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

class Queue
{
    public:
        struct node * First;
        int iCount;

        Queue();

        bool isStackEmpty();
        void enQueue(int no);
        int deQueue();
        void Display();
};

Queue::Queue()
{
    First=NULL;
    iCount=0;
}
bool Queue::isStackEmpty()
{
    if(iCount==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Queue::enQueue(int no)  //InsertLast
{
    struct node * newn=new node;
    newn->data=no;
    newn->next=NULL;

    if(First==NULL)
    {
        First=newn;
    }
    else
    {
        struct node * temp=First;

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
    }
    iCount++;

    cout<<"Get pushed in Stack Successfully \n";
}
int Queue::deQueue()//DeleteFirst
{
    if(First==NULL)
    {
        cout<<"Unable to pop element as stack is empty"<<"\n";
        return -1;
    }
    else
    {
        int value=First->data;
        struct node * temp=First;

        First=First->next;
        delete(temp);

        iCount--;

        return value;
    }
}
void Queue::Display()
{
    if(First==NULL)
    {
        cout<<"Stack is Empty "<<"\n";
    }
    else
    {
        struct node *temp=First;

        while(temp!=NULL)
        {
            cout<<"| "<<temp->data<<"| ->";
            temp=temp->next;
        }
        cout<<"NULL"<<"\n";
    }
}
int main()
{
   
   Queue obj;

   obj.enQueue(11);
   obj.enQueue(21);
   obj.enQueue(21);
   obj.enQueue(51);

   obj.Display();

   int iRet=obj.deQueue();
   cout<<"Poped element is :"<<iRet<<"\n";

   iRet=obj.deQueue();
   cout<<"Poped element is :"<<iRet<<"\n";

    return 0;
}