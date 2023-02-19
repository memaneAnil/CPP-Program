#include<iostream>

using namespace std;

bool checkAnagram(int iNo1,int iNo2)
{
    int Freq1[10]={0};
    int Freq2[10]={0};
    bool Flag=true;

    while(iNo1!=0)
    {
        Freq1[iNo1%10]++;
        iNo1=iNo1/10;
    }
    while(iNo2!=0)
    {
        Freq2[iNo2%10]++;
        iNo2=iNo2/10;
    }
    for(int iCnt=0;iCnt<10;iCnt++)
    {
        if(Freq1[iCnt]!=Freq2[iCnt])
        {
            cout<<Freq1[iCnt]<<" "<<Freq2[iCnt]<<"\n";
            Flag=false;
            break;
        }
    }
    return Flag;
}

int main()
{
    int iValue1=0,iValue2=0;
    bool bRet=false;

    cout<<"Enter the first number"<<"\n";
    cin>>iValue1;

    cout<<"Enter the second number"<<"\n";
    cin>>iValue2;

    bRet=checkAnagram(iValue1,iValue2);

    if(bRet==true)
    {
        cout<<"Number is Anagram"<<"\n";
    }
    else
    {
        cout<<"Number is not  Anagram"<<"\n";
    }

    return 0;
}
