#include<iostream>

using namespace std;

struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class SinglyCLL
{
    public :
            PNODE First = NULL;
            PNODE Last = NULL;

            SinglyCLL();

            void InsertFirst(int);
            void InsertLast(int);
            void InsertAtPos(int,int);

            void DeleteFirst();
            void DeleteLast();
            void DeleteAtPos(int);

            void Display();
            int Count();

};

SinglyCLL::SinglyCLL()
{
    First = NULL;
    Last = NULL;
}

void SinglyCLL::InsertFirst(int No)
{
    PNODE newn = new NODE;
    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    Last->next = First;
}
void SinglyCLL::InsertLast(int No)
{
    PNODE newn = new NODE;
    newn->data = No;
    newn->next = NULL;

    if(First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        //newn->next = *First;
        Last = newn;
    }
    Last->next = First;
}
int SinglyCLL::Count()
{
    PNODE temp = First;
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

void SinglyCLL::InsertAtPos(int No,int ipos)
{
    int counter = Count();
    PNODE temp = NULL;
    PNODE newn = NULL;
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
        newn = new NODE;
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
void SinglyCLL::DeleteFirst()
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
        Last->next = First;
        
    }
}
void SinglyCLL::DeleteLast()
{
    PNODE temp = NULL;
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
    	temp = First;  
        while(temp->next->next != (Last)->next)
        {
            temp = temp->next;
        }
        Last = temp;
        delete(temp->next);
        Last->next = First;
        
    }
}
void SinglyCLL::DeleteAtPos(int ipos)
{
    int i = 1;
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;

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
void SinglyCLL::Display()
{
    PNODE temp = First;
    int counter = 0;

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


int main()
{
    SinglyCLL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.InsertLast(121);
    obj.InsertLast(151);

    obj.InsertAtPos(999 ,3);

    obj.Display();
    iRet = obj.Count();
    cout<<"\nNumber of nodes in LL is :"<<iRet<<"\n";
    
    obj.DeleteAtPos(3);
    
    obj.Display();
    iRet = obj.Count();
    cout<<"\nNumber of nodes in LL is :"<<iRet<<"\n";
    
    obj.DeleteFirst();
    obj.DeleteLast();
    
    obj.Display();
    iRet = obj.Count();
    cout<<"\nNumber of nodes in LL is :"<<iRet<<"\n";

    return 0;
}
