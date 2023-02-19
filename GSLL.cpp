#include<iostream>

using namespace std;

template< class T>
struct node
{
    T data;
    struct node * next;
};

template< class T>
class SinglyLL
{
    public :
            struct node<T> * First = NULL;

            SinglyLL();

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
            T DisplayAddition();
            void DisplayLargeDigit();
            T secondMax();
            void Reverse();

};
template< class T>
SinglyLL<T>::SinglyLL()
{
    First = NULL;
}
template< class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct node<T> * newn = new struct node<T>;
    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
}
template< class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct node<T> * newn = new struct node<T>;
    newn->data = No;
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
    }
}
template< class T>
int SinglyLL<T>::Count()
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
template< class T>
void SinglyLL<T>::InsertAtPos(T No,int ipos)
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
        newn = new struct node<T>;
        newn->data = No;
        newn->next = NULL;

        for(i=1 ;i< ipos-1;i++)
        {
            temp = temp->next;
        }
        
        newn->next = temp->next;
        temp->next= newn;
    }
}
template< class T>
void SinglyLL<T>::DeleteFirst()
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
        First = (First)->next;
        delete(temp);
    }
}
template< class T>
void SinglyLL<T>::DeleteLast()
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
template< class T>
void SinglyLL<T>::DeleteAtPos(int ipos)
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
        delete(temp2);
    }
}
template< class T>
void SinglyLL<T>::Display()
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
void SinglyLL<T>::Reverse()
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
int SinglyLL<T>::SerchFirstOcc(T No)
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
int SinglyLL<T>::SerchLastOcc(T No)
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
int SinglyLL<T>::Freq(T No)
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
template< class T>
void SinglyLL<T>::DisplayLargeDigit()
{
   int iCnt=0,iDigit=0,iLarge=0;
   int dup=0;
   
    struct node<T> * temp = First;
    while(temp!=NULL)
    {
        dup = temp->data;
       while((temp->data)!=0)
        {
            iDigit=temp->data%10;
            if(iDigit>iLarge)
            {
                iLarge=iDigit;
            }
            temp->data=temp->data/10;
        }
        temp->data = dup;
        cout<<"Largest digit of elements from LL are : "<<iLarge<<"\n";
        temp=temp->next;
        iLarge=0;
    }
    
}
template< class T>
T SinglyLL<T>::DisplayAddition()
{
   
   T iAdd=0;
   
   struct node<T> * temp = First;

    while(temp!=NULL)
    {

        iAdd = iAdd+temp->data;
        
        temp=temp->next;
        
    }
    return iAdd;
   
}
template< class T>
T SinglyLL<T>::secondMax()
{
    T iMax2=0,iMax1=0;
    struct node<T> * temp = First;
    
    while(temp != NULL)
    {
    	
        if(iMax1<temp->data)
        {
        	iMax2=iMax1;
        	iMax1 = temp->data;
        	
        }
        if(iMax2 < temp->data && iMax1 != temp->data)
        {
        	iMax2 = temp->data;
        }
        temp = temp->next;
    }
    
    return iMax2;
}
int main()
{
    SinglyLL<int> obj;
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

    iRet =obj.secondMax();
    cout<<"Second maximum number from linklist is : "<<iRet<<"\n";


    iRet = obj.DisplayAddition();
    cout<<"Addition of elements of LinkList are : "<<iRet<<"\n";

    obj.DisplayLargeDigit();
    
        
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

    cout<<"Reversed link list :\n";

    obj.Reverse();
    obj.Display();
    
    
    obj.Reverse();
    obj.Display();
    
    
    obj.DeleteAtPos(3);
    
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes in LL is :"<<iRet<<"\n";
    
    obj.DeleteFirst();
    obj.DeleteLast();
    
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes in LL is :"<<iRet<<"\n";

    cout<<"\n";
    
    SinglyLL<float>fobj;

    fobj.InsertFirst(51.51f);
    fobj.InsertFirst(21.21f);
    fobj.InsertFirst(11.11f);

    fobj.Display();
    
    //fobj.DisplayLargeDigit();
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

    
    cout<<"Second maximum number from linklist is : "<<fobj.secondMax()<<"\n";
    cout<<"Addition of elements of LinkList are : "<<fobj.DisplayAddition()<<"\n";

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

    SinglyLL<double>dobj;

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
