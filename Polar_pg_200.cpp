#include<iostream>
#include <cmath>
using namespace std;

class Polar
{
private:
  double radius;
  double angle;

public:
  Polar(double a, double b)
  {
    radius = a;
    angle = fmod(b,360);
  }
  void show()
  {
    cout<<radius<<" ( "<<angle;
  }

  Polar operator +(Polar obj2);

};

Polar Polar:: operator +(Polar obj2)
{
  Polar temp_polar(0,0);
  double temp1, temp2;

  temp1 = radius*sin((angle*3.14159)/180) + obj2.radius*sin((obj2.angle*3.14159)/180);

  temp2 = radius*cos((angle*3.14159)/180) + obj2.radius*cos((obj2.angle*3.14159)/180);

  temp_polar.radius = sqrt(temp1*temp1 + temp2*temp2 );

  temp_polar.angle = (atan(temp1/temp2))*180*(1/3.14159);

  return temp_polar;

}

int main()
{

  Polar a(12,0), b(12,90), c=a+b;

  c.show();

return 0;
}
