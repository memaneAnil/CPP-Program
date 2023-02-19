#include <iostream>

using namespace std;
template<class T>
class Array
{
    public:
    T *arr;
    int size;
        
        Array(int size);
        void Accept();
        void Display();      

};
template<class T>
Array<T>::Array(int i)
    {
        size=i;
        arr=new T[size];
    }
    template<class T>
void Array<T>::Accept()
        {
            cout<<"Enter the array element"<<"\n";
            for(int iCnt=0;iCnt<size;iCnt++)
            {
                cin>>arr[iCnt];
            }
        }
        template<class T>
void Array<T>::Display()
        {
            cout<<"Array element are :\n";
            for(int iCnt=0;iCnt<size;iCnt++)
            {
                cout<<arr[iCnt]<<"\n";
            }
        }
int main()
{
    Array <int>obj(5);
    obj.Accept();
    obj.Display();
    Array <double>obj1(5);
    obj1.Accept();
    obj1.Display();
    return 0;
}