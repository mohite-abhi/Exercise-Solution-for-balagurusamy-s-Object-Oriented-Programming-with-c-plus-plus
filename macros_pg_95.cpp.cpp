#include<iostream>
using namespace std;

#define macro_max(x,y,z)({int retval; retval = (x>y?(x>z? x: z): (y>z?y:z)); retval;})
int main()
{
  cout<<macro_max(3,25,2);
return 0;
}
