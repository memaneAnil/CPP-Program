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
        void DisplayFreq()
        {
            int Arr[10]={0};
            int iDigit=0,iTemp=iNo,iMaxFreq=0,iMaxDigit=0;

            while(iTemp!=0)
            {
                iDigit=iTemp%10;
                Arr[iDigit]++;
                iTemp=iTemp/10;
            }
            
            
            for(int iCnt=0;iCnt<10;++iCnt)
            {
                if(Arr[iCnt]==0)
                {
                    continue;
                    
                }
                else
                {
                    if(Arr[iCnt]>iMaxFreq)
                    {
                        iMaxFreq=Arr[iCnt];
                        iMaxDigit=iCnt;
                    }
                   
                }
            }
            cout<<" Maximum time occured digit is "<<iMaxDigit<<"and is frequency is"<<iMaxFreq<<"\n";
        }
};

int main()
{
    int iValue=0;

    cout<<"Enter the number : "<<"\n";
    cin>>iValue;

    DigitX obj(iValue);

    obj.DisplayFreq();

  

    cout<<obj.iNo<<"\n";


    return 0;
}