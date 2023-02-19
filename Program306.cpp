#include <iostream>

using namespace std;
void swapi(int &no1,int &no2)
{
    int temp;

    temp=no1;
    no1=no2;
    no2=temp;
}
void swapd(double &no1,double &no2)
{
    double temp;

    temp=no1;
    no1=no2;
    no2=temp;
}
int main()
{
    int a=11,b=10;

    cout<<"Value of "<<a<<"\n";
    cout<<"Value of "<<b<<"\n";
    swapi(a,b);
    cout<<"Value of "<<a<<"\n";
    cout<<"Value of "<<b<<"\n";

    double p=11.9,q=10.7;

    cout<<"Value of "<<p<<"\n";
    cout<<"Value of "<<q<<"\n";
    swapd(p,q);
    cout<<"Value of "<<p<<"\n";
    cout<<"Value of "<<q<<"\n";

    return 0;
}