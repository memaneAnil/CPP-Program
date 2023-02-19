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

class SinglyLL
{
    public :
            PNODE First = NULL;

            SinglyLL();

            void InsertFirst(int);
            void InsertLast(int);
            void InsertAtPos(int,int);

            void DeleteFirst();
            void DeleteLast();
            void DeleteAtPos(int);

            void Display();
            int Count();

};

SinglyLL::SinglyLL()
{
    First = NULL;
}

void SinglyLL::InsertFirst(int No)
{
    PNODE newn = new NODE;
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
void SinglyLL::InsertLast(int No)
{
    PNODE newn = new NODE;
    newn->data = No;
    newn->next = NULL;
    PNODE temp = NULL;

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
int SinglyLL::Count()
{
    PNODE temp = First;
    int counter = 0;

    while(temp != NULL)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}

void SinglyLL::InsertAtPos(int No,int ipos)
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
void SinglyLL::DeleteFirst()
{
    PNODE temp = NULL;

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
void SinglyLL::DeleteLast()
{
    PNODE temp = NULL;

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
void SinglyLL::DeleteAtPos(int ipos)
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
        free(temp2);
    }
}
void SinglyLL::Display()
{
    PNODE temp = First;
    while(temp != NULL)
    {
        cout<<"|"<< temp->data <<"|->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}


int main()
{
    SinglyLL obj;
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

    return 0;
}