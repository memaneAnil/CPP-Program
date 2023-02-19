#include<iostream>

using namespace std;

struct node
{
    int data;
    struct node * prev;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class DoublyCLL
{
    public :
            PNODE First;
            PNODE Last;
            
            DoublyCLL();

            void InsertFirst(int);
            void InsertLast(int);
            void InsertAtPos(int,int);

            void DeleteFirst();
            void DeleteLast();
            void DeleteAtPos(int);

            void Display();
            int Count();

};

DoublyCLL::DoublyCLL()
{
    First = NULL;
    Last = NULL;
}

void DoublyCLL::InsertFirst(int No)
{
    PNODE newn = new NODE;
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
void DoublyCLL::InsertLast(int No)
{
    PNODE newn = new NODE;
    newn->data = No;
    newn->next = NULL;
    PNODE temp = NULL;

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
int DoublyCLL::Count()
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

void DoublyCLL::InsertAtPos(int No,int ipos)
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
void DoublyCLL::DeleteFirst()
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
void DoublyCLL::DeleteLast()
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
        delete(Last)->next;
        First->prev = Last;
        Last->next = First;
      
    }
}
void DoublyCLL::DeleteAtPos(int ipos)
{
    int i = 1;
    PNODE temp = NULL;
    
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
        free(temp->next->prev);
        temp->next->prev = temp;
        
    }
}
void DoublyCLL::Display()
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
    DoublyCLL obj;
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
