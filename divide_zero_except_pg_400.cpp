#include<iostream>
using namespace std;

template<class T>

void division(T d1, T d2)
{
    try
    {
        if (d2==0)
        {
            throw(0);
        }
        cout<<d1<<" / "<<d2<<" = "<<d1/d2;

        if (sizeof(d1)==1)
        {
            throw('a');
        }
        
    }
    catch(int)
    {
        cout<<"\nyour parants did not teach you not to divide by zero ?";
    }
    catch(char)
    {
        cout<<"\nek chapada maribi, tor char use kariba band heijiba";
    }
    
}

int main()
{
char d1='d', d2='k';

division(d1,d2);
return 0;
}
