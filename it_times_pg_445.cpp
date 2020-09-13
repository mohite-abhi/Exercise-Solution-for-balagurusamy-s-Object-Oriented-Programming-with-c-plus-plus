#include<iostream>
using namespace std;

int main()
{

string text="";

char temp='k';
int count=0;
int flag=0;

while (temp != 27)
{
    temp = getchar();
    if (flag==1 && temp == 't')
    {
        count++;
    }
    flag=0;
    
    
    if (temp == 'I')
    {
        flag=1;
    }
    
}

cout<<"\'It\' was used "<<count<<" times.";



return 0;
}
