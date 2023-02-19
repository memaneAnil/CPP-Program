#include<iostream>
#pragma pack(1)

using namespace std;


struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node** PPNODE;

class SinglyCLL
{
    public:
        PNODE First;
        PNODE Last;


    SinglyCLL();

    void insertFirst(int no);
    void insertLast(int no);
    void insertAtPos(int no,int ipos);

    void deleteFirst();
    void deleteLast();
    void deleteAtPos(int ipos);

    void Display();
    int Count();
};

SinglyCLL::SinglyCLL()
{
    First=NULL;
    Last=NULL;
}

void SinglyCLL::insertFirst(int no)
{
    PNODE newn= new NODE;
    newn->data=no;
    newn->next=NULL;
    if(First==NULL && Last==NULL)
    {
        First=Last=newn;
        (Last)->next=First;
    }
    else 
    {
        newn->next=First;
        First=newn;
        (Last)->next=First;
    }

}
void SinglyCLL::insertLast(int no)
{
    PNODE newn= new NODE;
    //PNODE newn=(PNODE) malloc(sizeof(NODE));
    newn->data=no;
    newn->next=NULL;
    if(First==NULL && Last==NULL)
    {
        First=Last=newn;
        (Last)->next=First;
    }
    else 
    {
        (Last)->next=newn;
        Last=newn;
        (Last)->next=First;
    }
}

void SinglyCLL::deleteFirst()
{
    PNODE temp=First;//***************************************
    if(First==NULL && Last==NULL)
    {
        return;
    }
    else if(First==Last)
    {
        //free(First);
        delete(First);
        First=NULL;
        Last=NULL;
    }
    else
    {
       
        First=(First)->next;
        
        //free((Last)->next); 
        ((Last)->next)=First; 
        delete(temp); 
    }
}
void SinglyCLL::deleteLast()
{
    PNODE temp=NULL;//*********************************
    
    if(First==NULL && Last==NULL)
    {
        return;
    }
    else if(First==Last)
    {
       delete(First);
        //free(First);
        First=NULL;
        Last=NULL;
         
    }
    else
    {
        temp=First;
        while(temp->next!=Last)//************************************
        {
            temp=temp->next;
        }
        delete(temp->next);
        //free(temp->next);//free(*Last)
        Last=temp;
        (Last)->next=First;

    }
}
void SinglyCLL::insertAtPos(int no,int ipos)
{
    PNODE temp=NULL;
    PNODE newn=NULL;
    int iCnt=0;
    int iNodeCnt=0;
    iNodeCnt=Count();

    if(ipos<1||ipos>(iNodeCnt+1))
    {
         cout<<"Invalid position"<<"\n";
        return;
    }
    if(ipos==1)
    {
        insertFirst(no);
    }
    else if(ipos==(iNodeCnt+1))
    {
        insertLast(no);
    }
    else
    {
        PNODE newn= new NODE;
        //newn=(PNODE)malloc(sizeof(NODE));
        newn->data=no;
        newn->next=NULL;

        temp=First;

        for(iCnt=1;iCnt<ipos-1;iCnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
        
    }
}
void SinglyCLL::deleteAtPos(int ipos)
{
    PNODE temp1=NULL;
    PNODE temp2=NULL;
    int iCnt=0;
    int iNodeCnt=0;
    iNodeCnt=Count();

    if(ipos<1||ipos>(iNodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }
    
    if(ipos==1)
    {
        deleteFirst();
    }
    else if(ipos==iNodeCnt)
    {
        deleteLast();
    }
    else
    {
        temp1=First;

        for(iCnt=1;iCnt<ipos-1;iCnt++)
        {
            temp1=temp1->next;
        }
        temp2=temp1->next;
        temp1->next=temp2->next;
        delete(temp2);
        //free(temp2); 

    }
}
int SinglyCLL::Count()
{
    int iCnt=0;
     PNODE temp=First;
    /*
    if(First==NULL && Last==NULL)
    {
        cout<<"Empty ll"<<"\n";
        return;
    }
   */
    do
    {
        temp=temp->next;
        iCnt++;
    }while(temp!=Last->next);
    printf("\n");
    
   return iCnt;
}
void SinglyCLL::Display()
{
    cout<<"Elements of linked list are<<"<<" \n";

    PNODE temp=First;
    /*
    if(First==NULL && Last==NULL)
    {
        return;
    }
    */
    do
    {
        cout<<"| "<<temp->data<<"| ->";
        temp=temp->next;
    }while(temp!=Last->next);
    cout<<"\n";
   
}
int main()
{
    SinglyCLL obj1;
    int iRet=0;

    

    obj1.insertFirst(51);
    obj1.insertFirst(21);
    obj1.insertFirst(11);
    obj1.Display();
    iRet=obj1.Count();
    cout<<"Number of elements in linkedlist is :"<<iRet<<"\n";

    obj1.insertLast(101);
    obj1.insertLast(111);
    obj1.insertLast(121);
    obj1.Display();
    iRet=obj1.Count();
    cout<<"Number of elements in linkedlist is :"<<iRet<<"\n";

    obj1.insertAtPos(999,5);
    obj1.Display();
    iRet=obj1.Count();
    cout<<"Number of elements in linkedlist is :"<<iRet<<"\n";

    obj1.deleteAtPos(5);
    obj1.Display();
    iRet=obj1.Count();
    cout<<"Number of elements in linkedlist is :"<<iRet<<"\n";


    obj1.deleteFirst();
    obj1.Display();
    iRet=obj1.Count();
    cout<<"Number of elements in linkedlist is :"<<iRet<<"\n";

    obj1.deleteLast();
    obj1.Display();
    iRet=obj1.Count();
    cout<<"Number of elements in linkedlist is :"<<iRet<<"\n";
    return 0;
}
