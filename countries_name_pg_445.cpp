#include<iostream>
#include<list>
using namespace std;



int main()
{

list <string> countries;

string temp;

cout<<"give space seperated country names : ";
do
{
    cin>>temp;
    countries.push_back(temp);
}while (getchar()!='\n');

list<string>::iterator point;

countries.sort();

point = countries.begin();

while (point != countries.end())
{
    cout<<*point<<" ";
    point++;
}


return 0;
}
