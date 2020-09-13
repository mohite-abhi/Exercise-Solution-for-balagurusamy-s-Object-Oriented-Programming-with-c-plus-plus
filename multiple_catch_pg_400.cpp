#include<iostream>
using namespace std;

void fun(int k) throw(char)
{
    try
    {
        if (k==0)
        {
            throw('a');
        }
        else if(k==1)
        {
            throw(1.1);
        }
        else if (k==2)
        {
            throw("abhi");
        }
        
    }
    catch(...)
    {
        cout<<"something caught";
        throw;
    }
   
}

int main()
{

    try
    {
        fun(1);
    }
    catch(double)
    {
        cout<<"caught double";
    }
    catch(char)
    {
        cout<<"char caught";
    }
    

    return 0;
}
