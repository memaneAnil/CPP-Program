#include<iostream>

using namespace std;

class Arithmatic
{
    public:
        int iValue1,iValue2;

        Arithmatic()
        {
            iValue1=0;
            iValue2=0;
        }

        Arithmatic(int no1,int no2)
        {
            iValue1=no1;
            iValue2=no2;
        }

        int Addition()
        {
            int iAdd=0;
            iAdd=iValue1+iValue2;
            return iAdd;
        }
};


int main()
{
    int iValue1=0,iValue2=0;
    int iRet=0;

    

    cout<<"Enter the first number : \n";
    cin>>iValue1;
    
    cout<<"Enter the second number :\n";
    cin>>iValue2;

    Arithmatic obj(iValue1,iValue2);
    iRet=obj.Addition();

    cout<<"Addition is :"<<iRet<<"\n";

    Arithmatic obj1;
    iRet=obj1.Addition();

    cout<<"Addition is :"<<iRet<<"\n";
    
    return 0;
}