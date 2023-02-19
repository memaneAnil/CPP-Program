#include<iostream>

using namespace std;

class ArrayX
{
    public:

        int iSize;
        int * Arr;

        ArrayX(int size)
        {
            iSize=size;
            Arr=new int(iSize);
        }

        ~ArrayX()
        {
            delete []Arr;
        }
        void Accept()
        {
            printf("Enter the element of array");

            int iCnt=0;
            for(iCnt=0;iCnt<iSize;iCnt++)
            {
                cin>>Arr[iCnt];
            }
        }

        void Display()
        {
            for(int iCnt=0;iCnt<iSize;iCnt++)
            {
                cout<<Arr[iCnt]<<"\t";
            }
            cout<<"\n";
        }
        int Minimum()
        {
            int iMin=Arr[0];
            for(int iCnt=1;iCnt<iSize;iCnt++)
            {
                if(Arr[iCnt]<iMin)
                {
                    iMin=Arr[iCnt];
                }
            }
            return iMin;
        }
};
int main()
{
    int iLength=0,iRet=0;

    cout<<"Enter the number of elements\n";
    cin>>iLength;


    ArrayX *obj=new ArrayX(iLength);//Dynamic
    obj->Accept();
    obj->Display();

    iRet=obj->Minimum();

    cout<<"Smallest element is :"<<iRet<<"\n";
    delete obj;

    return 0;
}