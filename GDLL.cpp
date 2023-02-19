#include<iostream>

using namespace std;
template<class T>
struct node
{
    T data;
    struct node * prev;
    struct node * next;
};
template<class T>
class DoublyLL
{
    public :
            struct node<T> * First;
            
            DoublyLL();

            void InsertFirst(T);
            void InsertLast(T);
            void InsertAtPos(T,int);

            void DeleteFirst();
            void DeleteLast();
            void DeleteAtPos(int);

            void Display();
            int Count();

            void Reverse();
            int SerchFirstOcc(T);
            int SerchLastOcc(T);
            int Freq(T);

};
template<class T>
DoublyLL<T>::DoublyLL()
{
    First = NULL;
}
template<class T>
void DoublyLL<T>::InsertFirst(T No)
{
    struct node<T> * newn = new node<T>;
    newn->data = No;
    newn->prev=NULL;//////////////////
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        (First)->prev=newn;
        First = newn;
    }
}
template<class T>
void DoublyLL<T>::InsertLast(T No)
{
    struct node<T> * newn = new node<T>;
    newn->data = No;
    newn->prev=NULL;///////////
    newn->next = NULL;
    struct node<T> * temp = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
}
template<class T>
int DoublyLL<T>::Count()
{
    struct node<T> * temp = First;
    int counter = 0;

    while(temp != NULL)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}
template<class T>
void DoublyLL<T>::InsertAtPos(T No,int ipos)
{
    int counter = Count();
    struct node<T> * temp = NULL;
    struct node<T> * newn = NULL;
    int i = 0;
 
    if(ipos == 1)
    {
        InsertFirst(No);
    }
    else if(ipos == (counter+1))
    {
        InsertLast(No);
    }
    else
    {
        temp = First;
        newn = new node<T>;
        newn->data = No;
        newn->prev = NULL;
        newn->next = NULL;

        for(i=1 ;i< ipos-1;i++)
        {
            temp = temp->next;
        }
        
        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next= newn;
    }
}
template<class T>
void DoublyLL<T>::DeleteFirst()
{
    
    if(First == NULL)
    {
        return;
    }
    else if((First)->next == NULL)
    {
        delete(First);
        First = NULL;
    }
    else
    {
        First=First->next;////////////////
        delete(First->prev);
        First->prev=NULL;
    }
}
template<class T>
void DoublyLL<T>::DeleteLast()
{
    struct node<T> * temp = NULL;

    if(First == NULL)
    {
        return;
    }
    else if((First)->next == NULL)
    {
        delete(First);
        First = NULL;
    }
    else
    { 
        temp = First;  
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = NULL;
    }
}
template<class T>
void DoublyLL<T>::DeleteAtPos(int ipos)
{
    int i = 1;
    struct node<T> * temp1 = NULL;
    struct node<T> * temp2 = NULL;

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == (Count()))
    {
        DeleteLast();
    }
    else
    {
        temp1 = First; 
        for(i == 1;i < ipos-1;i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        temp2->next->prev = temp1;
        delete(temp2);///////
    }
}
template<class T>
void DoublyLL<T>::Display()
{
    struct node<T> * temp = First;
    while(temp != NULL)
    {
        cout<<"|"<< temp->data <<"|->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}
template< class T>
void DoublyLL<T>::Reverse()
{
    struct node<T> *Previous;
    struct node<T>*Next;
    struct node<T>*Current;

    Previous = NULL;
    Next = NULL;
    Current = First;

    while(Current != NULL)
    {
        Next = Current->next;
        Current->next =Previous;
        Previous =Current;

        Current = Next;
    }
    First = Previous;
}
template< class T>
int DoublyLL<T>::SerchFirstOcc(T No)
{
    int counter =0,iPos=0;
    struct node<T> * temp = First;

    while(temp != NULL)
    {
        if(temp->data == No)
        {
            iPos = counter;
            break;
        }
        temp = temp->next;
        counter++;
    }
    return iPos;
}
template< class T>
int DoublyLL<T>::SerchLastOcc(T No)
{
    int counter =0,iPos=0;
    struct node<T> * temp = First;

    while(temp != NULL)
    {
        if(temp->data == No)
        {
            iPos = counter;
            
        }
        temp = temp->next;
        counter++;
    }
    return iPos;
}
template< class T>
int DoublyLL<T>::Freq(T No)
{
    int counter =0;
    struct node<T> * temp = First;

    while(temp != NULL)
    {
        if(temp->data == No)
        {
            counter++;
            
        }
        temp = temp->next;
        
    }
    return counter;
}

int main()
{
    DoublyLL<int> obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.InsertLast(121);
    obj.InsertLast(11);
    obj.InsertLast(151);

    obj.InsertAtPos(999 ,3);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes in LL is :"<<iRet<<"\n";

    iRet = obj.SerchFirstOcc(11);

    if(iRet == -1)
    {
        printf("Number is not in Linked list\n");
    }
    else
    {
        printf("Number occure first at index %d\n",iRet+1);
    }
    iRet = obj.SerchLastOcc(11);

    if(iRet == -1)
    {
        printf("Number is not in Linked list\n");
    }
    else
    {
        printf("Number occure last at index %d\n",iRet+1);
    }
    iRet = obj.Freq(11);

    printf("Frequency of given no is : %d \n",iRet);

    obj.Reverse();
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes in LL is :"<<iRet<<"\n";

    obj.Reverse();
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes in LL is :"<<iRet<<"\n";
    
    obj.DeleteAtPos(3);
    
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes in LL is :"<<iRet<<"\n";
    
    obj.DeleteFirst();
    obj.DeleteLast();
    
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes in LL is :"<<iRet<<"\n";

    DoublyLL<float>fobj;

    fobj.InsertFirst(51.51f);
    fobj.InsertFirst(21.21f);
    fobj.InsertFirst(11.11f);

    fobj.Display();
    iRet=fobj.Count();
    cout<<"Number of nodes are "<<iRet<<"\n";
    fobj.InsertLast(10.1f);
    fobj.InsertLast(12.1f);
    fobj.InsertLast(15.1f);
    fobj.Display();
    iRet=fobj.Count();
    cout<<"Number of nodes are "<<iRet<<"\n";

    fobj.InsertAtPos(99.9,5);
    fobj.Display();
    iRet=fobj.Count();
    cout<<"Number of nodes are "<<iRet<<"\n";

    fobj.DeleteAtPos(5);
    fobj.Display();
    iRet=fobj.Count();
    cout<<"Number of nodes are "<<iRet<<"\n";
    fobj.DeleteFirst();
    fobj.Display();
    iRet=fobj.Count();
    cout<<"Number of nodes are "<<iRet<<"\n";

    fobj.DeleteLast();
    fobj.Display();
    iRet=fobj.Count();
    cout<<"Number of nodes are "<<iRet<<"\n";

    cout<<"\n";

    DoublyLL<double>dobj;

    dobj.InsertFirst(51.11);
    dobj.InsertFirst(21.10);
    dobj.InsertFirst(11.11);
    dobj.Display();
    iRet=dobj.Count();
    cout<<"Number of nodes are "<<iRet<<"\n";

    dobj.InsertLast(12.1f);
    dobj.InsertLast(15.1f);
    dobj.Display();
    iRet=dobj.Count();
    cout<<"Number of nodes are "<<iRet<<"\n";

    dobj.InsertAtPos(99.9,5);
    dobj.Display();
    iRet=dobj.Count();
    cout<<"Number of nodes are "<<iRet<<"\n";

    dobj.DeleteAtPos(5);
    dobj.Display();
    iRet=dobj.Count();
    cout<<"Number of nodes are "<<iRet<<"\n";
    dobj.DeleteFirst();
    dobj.Display();
    iRet=dobj.Count();
    cout<<"Number of nodes are "<<iRet<<"\n";

    dobj.DeleteLast();
    dobj.Display();
    iRet=dobj.Count();
    cout<<"Number of nodes are "<<iRet<<"\n";


    return 0;
}
