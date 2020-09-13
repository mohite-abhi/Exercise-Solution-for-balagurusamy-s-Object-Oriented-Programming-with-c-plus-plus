#include<iostream>
using namespace std;

double power(double m, int n = 2);
int power(int m, int n= 2);

int main()
{
  cout<<power(5)<<endl;
  cout<<power(6.6)<<endl;

return 0;
}

double power(double  m, int n)
{
  double ans = 1;
  while (n != 0)
  {
    ans = ans * m;
    n--;
  }
  return ans;

}

int power(int m, int n)
{
  int ans = 1;
  while (n != 0)
  {
    ans = ans * m;
    n--;
  }
  return ans;

}
