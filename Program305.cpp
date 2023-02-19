#include <iostream>

using namespace std;
void swap(int &no1,int &no2)
{
    int temp=0;

    temp=no1;
    no1=no2;
    no2=temp;
}
int main()
{
    int a=11,b=10;

    cout<<"Value of "<<a<<"\n";
    cout<<"Value of "<<b<<"\n";

    swap(a,b);

    cout<<"Value of "<<a<<"\n";
    cout<<"Value of "<<b<<"\n";

    return 0;
}