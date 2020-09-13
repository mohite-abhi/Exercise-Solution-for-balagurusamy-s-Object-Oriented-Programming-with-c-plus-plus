#include<iostream>
using namespace std;

inline float max3(float a = 0,float b = 0, float c = 0)
{
  return (a>b?(a>c?a:c):(b>c?b:c));
}

int main()
{
  cout<<max3(4,6,1)<<endl;

return 0;
}
