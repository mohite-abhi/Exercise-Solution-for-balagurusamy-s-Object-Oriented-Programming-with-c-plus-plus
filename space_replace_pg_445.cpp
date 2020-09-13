#include<iostream>
using namespace std;

int main()
{
    string words="";
    char temp=' ';

    int count = 0;
    cout<<">>>";
    while (temp!='\n' or count<=3)
    {   

        temp=getchar();
        if (temp == ' ')
        {
            count ++;
            words=words+'_';
            continue;
        }

        if (count <= 3 && temp=='\n')
        {
            cout<<"c'mon i expect you to give more words than that try again\n>>>";
            words="";
        }
        words=words+temp;
    }


    cout<<"your replaced string : "<<words;

    
    



return 0;
}
