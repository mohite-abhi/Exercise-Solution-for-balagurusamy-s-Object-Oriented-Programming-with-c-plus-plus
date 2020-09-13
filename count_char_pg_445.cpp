#include<iostream>
#include<limits>
using namespace std;

int main()
{

char count_key;
int count=0;
cout<<"give char to count\n>>>";cin>>count_key;cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
string text="";
cout<<"give text\n>>>";

char temp ='h';

while (temp != '\n')
{
    temp=getchar();

    text=text+temp;

    if (temp == count_key)
    {
        count++;
    }
    
}

cout<<"your text contained '"<<count_key<<"' "<<count<<" times";


return 0;
}
