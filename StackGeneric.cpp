#include<iostream>

using namespace std;
template<class T>
struct node
{
    T data;
    struct node *next;
};
template<class T>
class Stack
{
    public:
        struct node<T> * First;
        int iCount;

        Stack();

        bool isStackEmpty();
        void Push(T no);
        T Pop();
        void Display();
};
template<class T>
Stack<T>::Stack()
{
    First=NULL;
    iCount=0;
}
template<class T>
bool Stack<T>::isStackEmpty()
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
void Stack<T>::Push(T no)  //InsertFirst
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
        newn->next=First;
        First=newn;
    }
    iCount++;

    cout<<"Get pushed in Stack Successfully \n";
}
template<class T>
T Stack<T>::Pop()//DeleteFirst
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
void Stack<T>::Display()
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
   int iRet=0; 
   Stack<int> obj;

   obj.Push(11);
   obj.Push(11);
   obj.Push(21);
   obj.Push(51);

   obj.Display();

   iRet=obj.Pop();
   cout<<"Poped element is :"<<iRet<<"\n";

   iRet=obj.Pop();
   cout<<"Poped element is :"<<iRet<<"\n";
   
   Stack<float> fobj;

   fobj.Push(1.1);
   fobj.Push(1.14);
   fobj.Push(2.1);
   fobj.Push(5.1);

   fobj.Display();

   float fRet=fobj.Pop();
   cout<<"Poped element is :"<<fRet<<"\n";

   fRet=fobj.Pop();
   cout<<"Poped element is :"<<fRet<<"\n";


    return 0;
}
