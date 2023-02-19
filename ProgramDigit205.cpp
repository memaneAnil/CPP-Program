#include<iostream>

using namespace std;

class DigitX
{
    public:
        int iNo;

        DigitX()
        {
            iNo=0;
        }
        DigitX(int value)
        {
            iNo=value;
        }
        int SumEvenDigit()
        {
            int iDigit=0,iSum=0;

            int iTemp=iNo;

            while(iTemp!=0)
            {
                iDigit=iTemp%10;
                if((iDigit%2)==0)
                {
                    iSum=iSum+iDigit;
                }
                iTemp=iTemp/10;
            }
            return iSum;
        }

};

int main()
{
    int iValue=0,iRet=0;

    cout<<"Enter the number : "<<"\n";
    cin>>iValue;

    DigitX obj(iValue);

    iRet=obj.SumEvenDigit();

    cout<<"Addition of Even digit is : "<<iRet<<"\n";

    cout<<obj.iNo<<"\n";


    return 0;
}