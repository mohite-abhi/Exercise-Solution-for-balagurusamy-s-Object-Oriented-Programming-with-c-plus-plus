#include<iostream>
using namespace std;

int main()
{

string kk = "my name is abhishek mohite so what is your name : ";

string::iterator point = kk.begin();

while (point != kk.end())
{
    cout<<*point;
    point++;
}


return 0;
}
