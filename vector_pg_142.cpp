#include<iostream>
using namespace std;

class bector
{
private:
  float i;
  float j;
  float k;

public:
  bector();
  bector(float, float, float);
  void modify(float, float, float);
  void multiply(float);
  void display();
  friend bector add(bector&, bector&);

};


bector::bector(float x, float y, float z)
{
  i = x;
  j = y;
  k = z;
}


bector::bector()
{
  i = 0;
  j = 0;
  k = 0;
}


void bector::modify(float new_x, float new_y, float new_z)
{
  i = new_x;
  j = new_y;
  k = new_z;
}


void bector::multiply(float scaler)
{
  i = i*scaler;
  j = j*scaler;
  k = k*scaler;
}


void bector::display()
{
    cout <<i<<"i + "<<j<<"j + "<<k<<"k\n";
}


bector add(bector &vec1, bector &vec2)
{
  bector new_vec;
  new_vec.i = vec1.i + vec2.i;
  new_vec.j = vec1.j + vec2.j;
  new_vec.k = vec1.k + vec2.k;

  return new_vec;
}


int main()
{

  bector v1(1.1, 2.2, 3.3), v2(1.9, 2.8, 3.7), v3;
  v3 = add(v1, v2);
  v3.display();

return 0;
}
