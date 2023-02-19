#include<iostream>

using namespace std;
template<class T>
struct node
{
    T data;
    struct node *next;
};

template<class T>
class Queue
{
    public:
        struct node<T> * First;
        int iCount;

        Queue();

        bool isStackEmpty();
        void enQueue(T no);
        T deQueue();
        void Display();
};
template<class T>
Queue<T>::Queue()
{
    First=NULL;
    iCount=0;
}
template<class T>
bool Queue<T>::isStackEmpty()
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
template<class T>
void Queue<T>::enQueue(T no)  //InsertLast
{
    struct node<T> * newn=new node<T>;
    newn->data=no;
    newn->next=NULL;

    if(First==NULL)
    {
        First=newn;
    }
    else
    {
        struct node<T> * temp=First;

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
    }
    iCount++;

    cout<<"Get pushed in Stack Successfully \n";
}
template<class T>
T Queue<T>::deQueue()//DeleteFirst
{
    if(First==NULL)
    {
        cout<<"Unable to pop element as stack is empty"<<"\n";
        return -1;
    }
    else
    {
        T value=First->data;
        struct node<T> * temp=First;

        First=First->next;
        delete(temp);

        iCount--;

        return value;
    }
}
template<class T>
void Queue<T>::Display()
{
    if(First==NULL)
    {
        cout<<"Stack is Empty "<<"\n";
    }
    else
    {
        struct node<T> *temp=First;

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
   
   Queue<int> obj;

   obj.enQueue(11);
   obj.enQueue(21);
   obj.enQueue(21);
   obj.enQueue(51);

   obj.Display();

   int iRet=obj.deQueue();
   cout<<"Poped element is :"<<iRet<<"\n";

   iRet=obj.deQueue();
   cout<<"Poped element is :"<<iRet<<"\n";
   
   Queue<float> fobj;

   fobj.enQueue(1.1f);
   fobj.enQueue(2.1f);
   fobj.enQueue(2.15f);
   fobj.enQueue(5.1f);

   fobj.Display();

   float fRet=fobj.deQueue();
   cout<<"Poped element is :"<<fRet<<"\n";

   fRet=fobj.deQueue();
   cout<<"Poped element is :"<<fRet<<"\n";

    return 0;
}
