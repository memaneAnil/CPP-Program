#include<iostream>

using namespace std;
template<class T>
struct node
{
    int data;
    struct node * prev;
    struct node * next;
};

template<class T>
class DoublyCLL
{
    public :
            struct node<T> * First;
            struct node<T> * Last;
            
            DoublyCLL();

            void InsertFirst(T);
            void InsertLast(T);
            void InsertAtPos(T,int);

            void DeleteFirst();
            void DeleteLast();
            void DeleteAtPos(int);

            void Display();
            int Count();

            int SerchFirstOcc(T);
            int SerchLastOcc(T);
            int Freq(T);

};
template<class T>
DoublyCLL<T>::DoublyCLL()
{
    First = NULL;
    Last = NULL;
}
template<class T>
void DoublyCLL<T>::InsertFirst(T No)
{
    struct node<T> * newn = new node<T>;
    newn->data = No;
    newn->prev = NULL;
    newn->next = NULL;

    if(First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->next->prev = newn;
        First = newn;
    }
    First ->prev = Last;
    Last ->next = First;
}
template<class T>
void DoublyCLL<T>::InsertLast(T No)
{
    struct node<T> * newn = new node<T>;
    newn->data = No;
    newn->next = NULL;
    struct node<T> * temp = NULL;

    if(First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        //newn->next = First;
        newn->prev = Last;
        Last = newn;
    }
    First ->prev = Last;
    Last ->next = First;
}
template<class T>
int DoublyCLL<T>::Count()
{   
    struct node<T> * temp = First;
    int counter = 0;
    if(First == NULL && Last == NULL)
    {
        return 0;
    }
    do
    {
        counter++;
        temp = temp->next;
    }while(temp != Last->next);
    return counter;
}
template<class T>
void DoublyCLL<T>::InsertAtPos(T No,int ipos)
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
void DoublyCLL<T>::DeleteFirst()
{
    if(First == NULL && Last == NULL)
    {
        return;
    }
    else if(First == Last)
    {
        delete(First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete(Last->next);
        First->prev = Last;
        Last->next = First;
        
    }
}
template<class T>
void DoublyCLL<T>::DeleteLast()
{
    if(First == NULL && Last == NULL)
    {
        return;
    }
    else if(First == Last)
    {
        delete(First);
        First = NULL;
        Last = NULL;
    }
    else
    {   
        Last = Last->prev;
        delete(Last->next);
        First->prev = Last;
        Last->next = First;
      
    }
}
template<class T>
void DoublyCLL<T>::DeleteAtPos(int ipos)
{
    int i = 1;
    struct node<T> * temp = NULL;
    
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
        temp = First;

        for(i == 1;i < ipos-1;i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete(temp->next->prev);//////
        temp->next->prev = temp;
        
    }
}
template<class T>
void DoublyCLL<T>::Display()
{
    struct node<T> * temp = First;
    
    if(First == NULL && Last == NULL)
    {
        return;
    }
    do
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }while(temp != Last->next);
    
}
template< class T>
int DoublyCLL<T>::SerchFirstOcc(T No)
{
    
    int counter =0,iPos=0;
    struct node<T> * temp = First;
    if(First == NULL && Last == NULL)
    {
        cout<<"Empty linked list \n";
        return -1;
    }
    do
    {
        if(temp->data == No)
        {
            iPos = counter;
            break;
        }
        counter++;
        temp = temp->next;
    }while(temp != Last->next);
    
    return iPos;
    
}
template< class T>
int DoublyCLL<T>::SerchLastOcc(T No)
{
    int counter =0,iPos=0;
    struct node<T> * temp = First;

    if(First == NULL && Last == NULL)
    {
        cout<<"Empty linked list \n";
        return -1;
    }
    do
    {
        if(temp->data == No)
        {
            iPos = counter;
            
        }
        counter++;
        temp = temp->next;
    }while(temp != Last->next);
 
    return iPos;
}
template< class T>
int DoublyCLL<T>::Freq(T No)
{
    int counter =0;
    struct node<T> * temp = First;

    if(First == NULL && Last == NULL)
    {
        cout<<"Empty linked list \n";
        return -1;
    }

    do
    {
        if(temp->data == No)
        {
            counter++;
            
        }
        
        temp = temp->next;
    }while(temp != Last->next);
    
    return counter;
    
}

int main()
{
    DoublyCLL<int> obj;
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
    cout<<"\nNumber of nodes in LL is :"<<iRet<<"\n";

    iRet = obj.SerchFirstOcc(11);

    if(iRet == -1)
    {
        cout<<"Number is not in Linked list\n";
    }
    else
    {
        cout<<"Number occure first at index : " << iRet+1<<"\n";
    }
    iRet = obj.SerchLastOcc(11);

    if(iRet == -1)
    {
        cout<<"Number is not in Linked list\n";
    }
    else
    {
       cout<<"Number occure last at index : " << iRet+1<<"\n";
    }
    iRet = obj.Freq(11);

    cout<<"Frequency of given no is : "<< iRet<<" \n";
/*    
    obj.DeleteAtPos(3);
    
    obj.Display();
    iRet = obj.Count();
    cout<<"\nNumber of nodes in LL is :"<<iRet<<"\n";
    
    obj.DeleteFirst();
    obj.DeleteLast();
    
    obj.Display();
    iRet = obj.Count();
    cout<<"\nNumber of nodes in LL is :"<<iRet<<"\n";

    cout<<"\n";

    DoublyCLL<float>fobj;

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

    DoublyCLL<double>dobj;

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
*/

    return 0;
}
