#include<iostream>
using namespace std;

int main()
{

    try
    {
        cout<<"give  number except 0";
        float k;
        cin>>k;
        if (k==0)
        {
            throw k;
        }
        cout<<1/k;
    }
    catch(float k)
    {
        cout<<"why you motherfucker ?";
    }
    

return 0;
}
