#include<iostream>
using namespace std;

int main()
{

int m;
float x;
int *intptr;
float *floatptr;

intptr=reinterpret_cast<int*>(m);
//floatptr=reinterpret_cast<float*>(x);
return 0;
}
