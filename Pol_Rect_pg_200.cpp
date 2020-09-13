#include<iostream>
#include<cmath>
using namespace std;

class Pol;

class Rect
{
private:
  double x_coordinate, y_coordinate;

public:
  Rect(){x_coordinate=y_coordinate=0;}
  Rect(double xx, double yy){x_coordinate=xx;y_coordinate=yy;}
  friend istream & operator >> (istream & rectin, Rect &obj);
  friend ostream & operator << (ostream & rectout, const Rect & obj);
  friend Pol;

};

class Pol

{
private:
  double r_amplitude;
  double theta;

public:
  Pol(double amp, double tta){r_amplitude=amp;theta=fmod(tta, 360);}
  Pol(){r_amplitude=theta=0;}
  friend istream & operator >> (istream & polin, Pol &obj);
  friend ostream & operator << (ostream & polout, const Pol & obj);

  operator Rect()
  {
    Rect temp;
    temp.x_coordinate = r_amplitude*cos((theta/180)*3.14159265359);
    temp.y_coordinate = r_amplitude*sin((theta/180)*3.14159265359);
    return temp;
  }

  Pol(Rect obj)
  {
    r_amplitude = sqrt(obj.x_coordinate*obj.x_coordinate + obj.y_coordinate*obj.y_coordinate);
    theta = (atan(obj.y_coordinate / obj.x_coordinate))*(180/3.14159265359);
  }

};

istream & operator >> (istream & rectin, Rect &obj)
{
  cout<<"x coordinate : ";
  rectin>>obj.x_coordinate;
  cout<<"y coordinate : ";
  rectin>>obj.y_coordinate;

  return (rectin);
}

istream & operator >> (istream & polin, Pol & obj)
{
  double temp;
  cout<<"amplitude : ";
  polin>>obj.r_amplitude;
  cout<<"anlge : ";
  polin>>temp;
  obj.theta=fmod(temp,360);

  return (polin);
}

ostream & operator << (ostream & rectout, const Rect & obj)
{
  rectout<<obj.x_coordinate<<" + "<<obj.y_coordinate<<" j"<<endl;

  return (rectout);
}

ostream & operator << (ostream & polout, const Pol & obj)
{
  polout<<obj.r_amplitude<<" ( "<<obj.theta<<endl;

  return (polout);
}


int main()
{
  Pol a;
  cin>>a;
  cout<<"here \n\n"<<a;

  Rect b;
  b = a;
  cout<<"here:\n"<<b;

return 0;
}
