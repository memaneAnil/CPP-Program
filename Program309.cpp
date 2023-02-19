#include <iostream>

using namespace std;

template<class T>
T addition(T arr[],int size)
{
    int iCnt=0;
    T Sum;
    for(iCnt=0;iCnt<size;iCnt++)
    {
        Sum=Sum+arr[iCnt];
    }
    return Sum;
}
template<class T>
T maximum(T arr[],int size)
{
    int iCnt=0;
    T Max=arr[0];
    for(iCnt=0;iCnt<size;iCnt++)
    {
        if(arr[iCnt]>Max)
        {
            Max=arr[iCnt];
        }
    }
    return Max;
}
int main()
{
    int Data[]={10,20,50,40};
    int iRet=addition(Data,4);
    int addmax=maximum(Data,4);

    cout<<"Max is : "<<addmax<<"\n";
    cout<<"Addition is : "<<iRet<<"\n";

    float Data1[]={10.2,20.3,30.5,40.9};
    float fret=addition(Data1,4);
    cout<<"Addition is : "<<fret<<"\n";

    double Data3[]={10.2,20.3,30.5,40.9};
    double dret=addition(Data3,4);
    cout<<"Addition is : "<<dret<<"\n";
    return 0;
}