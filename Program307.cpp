#include <iostream>

using namespace std;
template<class T>
void swapX(T &no1,T &no2)
{
    T temp;

    temp=no1;
    no1=no2;
    no2=temp;
}

int main()
{
    int a=11,b=10;

    cout<<"Value of "<<a<<"\n";
    cout<<"Value of "<<b<<"\n";
    swapX(a,b);
    cout<<"Value of "<<a<<"\n";
    cout<<"Value of "<<b<<"\n";

    double p=11.9,q=10.7;

    cout<<"Value of "<<p<<"\n";
    cout<<"Value of "<<q<<"\n";
    swapX(p,q);
    cout<<"Value of "<<p<<"\n";
    cout<<"Value of "<<q<<"\n";

    return 0;
}