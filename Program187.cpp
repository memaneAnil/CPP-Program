#include<iostream>

using namespace std;

int Addition(int no1,int no2)
{
    return no1+no2;
}
int main()
{
    int iValue1=0,iValue2=0;
    int iRet=0;

    cout<<"Enter the first number : \n";
    cin>>iValue1;
    
    cout<<"Enter the second number :\n";
    cin>>iValue2;

    iRet=Addition(iValue1,iValue2);

    cout<<"Addition is :"<<iRet<<"\n";
    
    return 0;
}