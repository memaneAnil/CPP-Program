//Program 211
#include<iostream>

using namespace std;

#pragma pack(1)

struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node** PPNODE;

class SinglyLL 
{
    public:
        PNODE First;
        int iCount;

        SinglyLL();
        
        void insertFirst(int);
        
        void insertLast(int);
        
        void insertAtPos(int,int);
        
        void deleteFirst();
        
        void deleteLast();
        
        void deleteAtPos(int);
        
        void Display();
        
        
};
    SinglyLL::SinglyLL()
    {
        First=NULL;
        iCount=0;
    }

    void SinglyLL::insertFirst(int no)
    {
        PNODE newn=new NODE;
        newn->data=no;
        newn->next=NULL;

        if(First==NULL)//if (iCount==0)
        {
            First=newn;
            iCount++;  
        }
        else
        {
            newn->next=First;
            First=newn;
            iCount++;
        }

        
    }
    
    void SinglyLL::insertLast(int no)
    {
        PNODE newn=new NODE;
        newn->data=no;
        newn->next=NULL;

        if(First==NULL)//if (iCount==0)
        {
            First=newn;
            iCount++;  
        }
        else
        {
            PNODE temp=First;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newn; 
        }
        iCount++;
    }
    
    void SinglyLL::insertAtPos(int no,int ipos)
    {
        if(ipos==1)
        {
           insertFirst(no); 
        }
        else if(ipos==iCount+1)
        {
            insertLast(no);
        }
        else
        {
            PNODE newn=new NODE;
            newn->data=no;
            newn->next=NULL;
            PNODE temp=First;

            for(int iCnt=1;iCnt<ipos-1;iCnt++)
            {
                temp=temp->next;
            }
            newn->next=temp->next;
            temp->next=newn;

            iCount++;
        }
        

    }
    void SinglyLL::deleteFirst()
    {
        if(First==NULL)
        {
           return;
        }
        else if(First->next==NULL)
        {
            delete First;
            First=NULL;
            iCount--;
        }
        else
        {
            PNODE temp=First;
            First=First->next;
            delete temp;
            iCount--;
        }
    }
    void SinglyLL::deleteLast()
    {
        if(First==NULL)
        {
           return;
        }
        else if(First->next==NULL)
        {
            delete First;
            First=NULL;
            iCount--;
        }
        else
        {
            PNODE temp=First;
            while(temp->next->next!=NULL)
            {
                temp=temp->next;
            }
            delete temp->next;
            temp->next=NULL;
            iCount--;   
        }
    }
    void SinglyLL::deleteAtPos(int ipos)
    {
        if(First==NULL)
        {
           return;
        }
        else if(First->next==NULL)
        {
            delete First;
            First=NULL;
            iCount--;
        }
        else
        {
            PNODE temp1=First;

            for(int iCnt=1;iCnt<ipos-1;iCnt++)
            {
                temp1=temp1->next;
            }
            PNODE temp2=temp1->next;

            temp1->next=temp2->next;

            delete temp2;

            iCount--;
        }

    }
    void SinglyLL::Display()
    {
        PNODE temp=First;
        while(temp!=NULL)
        {
            cout<<"|"<<temp->data<<"|->";
            temp=temp->next;
        }
       
    }

   
    
int main()
{
    SinglyLL obj1;
    SinglyLL obj2;
    cout<<sizeof(obj1)<<"\n";
    cout<<"First pointer contains :"<<obj1.First<<"\n";
    cout<<"Number of nodes are :"<<obj1.iCount<<"\n";

    obj1.insertFirst(51);
    obj1.insertFirst(21);
    obj1.insertFirst(11);

     
    obj1.Display();

    cout<<"\n";
    obj1.insertLast(151);
    obj1.insertLast(121);
    obj1.insertLast(111);

    obj1.insertAtPos(999,5);
    //obj1.deleteFirst();
    //obj1.deleteLast();

    
    obj1.Display();
    cout<<"\n";
    obj1.deleteAtPos(5);
    obj1.Display();
    cout<<"Number of nodes are :"<<obj1.iCount<<"\n";


    obj2.insertFirst(511);
    obj2.insertFirst(211);
    obj2.insertFirst(111);
    obj2.insertFirst(155);

    obj2.Display();

    cout<<"Number of nodes are :"<<obj2.iCount<<"\n";

   

    return 0;
}