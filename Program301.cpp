#include <iostream>

using namespace std;

int Addition(int no1,int no2)
{
    int Ans=0;
    Ans=no1+no2;
    return Ans;
}
double Addition(double no1,double no2)
{
    double Ans=0;
    Ans=no1+no2;
    return Ans;
}

int main()
{
    int value1=10,value2=11,iRet=0;

    iRet=Addition(value1,value2);
    cout<<" Addition is "<<iRet<<"\n";

    value1=10.1;
    value2=11.30;
    iRet=Addition(value1,value2);
    cout<<" Addition is "<<iRet<<"\n";
    return 0;
}