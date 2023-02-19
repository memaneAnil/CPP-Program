#include<iostream>

using namespace std;

class ArrayX
{
    public:
        int * Arr;
        int iSize;

        ArrayX(int i)
        {
            iSize=i;
            Arr=new int[iSize];
        }

        ~ArrayX()
        {
            cout<<"Inside the destructor\n";
            delete []Arr;
        }

        void Accept()
        {
            cout<<"Enter the numbers:\n";

            int iCnt=0;

            for(iCnt=0;iCnt<iSize;iCnt++)
            {
                cin>>Arr[iCnt];
            }

        }

        void Display()
        {
            cout<<"Elements of array are :"<<"\n";

            int iCnt=0;

            for(iCnt=0;iCnt<iSize;iCnt++)
            {
                cout<<Arr[iCnt]<<"\t";
            }
            cout<<"\n";
        }
        int SumEven()
        {
            int iCnt=0;
            int iAdd=0;
            for(iCnt=0;iCnt<iSize;iCnt++)
            {
                if((Arr[iCnt]%2)==0)
                {
                    iAdd=iAdd+Arr[iCnt];
                }
            }
            return iAdd;
        }
        int SumOdd()
        {
            int iCnt=0;
            int iAdd=0;
            for(iCnt=0;iCnt<iSize;iCnt++)
            {
                if((Arr[iCnt]%2)!=0)
                {
                    iAdd=iAdd+Arr[iCnt];
                }
            }
            return iAdd;
        }
    
};

int main()
{
    int iLength=0;
    int iRet=0;

    cout<<"Enter the number of Elements"<<"\n";
    cin>>iLength;

    ArrayX obj(iLength);

    obj.Accept();
    obj.Display();

    iRet=obj.SumEven();

    cout<<"Addition of SumEven is :"<<iRet<<"\n";

    iRet=obj.SumOdd();

    cout<<"Addition of SumOdd is :"<<iRet<<"\n";

    return 0;
}