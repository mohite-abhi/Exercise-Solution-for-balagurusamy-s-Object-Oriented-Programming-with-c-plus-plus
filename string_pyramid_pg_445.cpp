#include<iostream>
using namespace std;

int main()
{

string s("123456789");

for (int i = 1; i < 6; i++)
    {
        for (int k = i; k < 6; k++)
        {
            cout<<"  ";
        }

        for (int j = 1; j <= (2*i-1); j++)
        {
            cout<<s[abs((2*i-1) - abs(i-j))-1]<<" ";
            
        }
        cout<<endl;
    }


return 0;
}
