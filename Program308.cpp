#include <iostream>

using namespace std;

template<class T>
void Display(T arr[],int size)
{
    int iCnt=0;

    for(iCnt=0;iCnt<size;iCnt++)
    {
        cout<<arr[iCnt]<<"\n";
    }
}

int main()
{
    int Data[]={10,20,30,40};
    Display(Data,4);

    float Data1[]={10.2,20.3,30.5,40.9};
    Display(Data1,4);

    char Data2[]={'a','b','c','d'};
    Display(Data2,4);

    double Data3[]={10.2,20.3,30.5,40.9};
    Display(Data3,4);

    return 0;
}