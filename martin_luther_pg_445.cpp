#include<iostream>
using namespace std;

int main()
{

    string nme[3];

    cout<<"give name : ";

    for (int i = 0; i < 3; i++)
    {
        cin>>nme[i];
    }

    string temp="";
    for (int i = 0; i < 3; i++)
    {
        temp+=nme[i];
        temp.append(" ");
    }

    cout<<"done using + :"<<temp<<endl;

    temp="";
    for (int i = 0; i < 3; i++)
    {
        temp.append(nme[i]);;
        temp.append(" ");
    }
    cout<<"done usign append() :"<<temp<<endl;
    
return 0;
}
