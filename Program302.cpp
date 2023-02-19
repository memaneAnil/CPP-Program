#include <iostream>

using namespace std;

template<class T>
T Addition(T no1,T no2)
{
    T Ans;
    Ans=no1+no2;
    return Ans;
}
int main()
{
    int value1=10,value2=11,iRet=0;

    iRet=Addition(value1,value2);
    cout<<" Addition is "<<iRet<<"\n";

    double value1=10.1,value2=11.3,iRet=0.0;

    iRet=Addition(value1,value2);
    cout<<" Addition is "<<iRet<<"\n";

    return 0;
}