#include<iostream>
#include <cmath>
using namespace std;

class DB;

class DM
{
private:
  int meter;
  float centimeter;

public:
  DM();
  DM(int, float);
  friend void display(DM obj);
  friend DB sum(DB, DM);
  friend DM sum(DM, DB);
};


DM::DM()
{
  meter = 0;
  centimeter = 0;
}


DM::DM(int mt, float cm)
{
  meter = mt;
  centimeter = cm;
}


class DB
{
private:
  int feet;
  float inches;

public:
  DB();
  DB(int, float);
  friend void display(DB obj);
  friend DB sum(DB, DM);
  friend DM sum(DM, DB);
};


DB::DB()
{
  feet = 0;
  inches = 0;
}


DB::DB(int ft, float in)
{
  feet = ft;
  inches = in;
}


DB sum(DB obj1, DM obj2)
{
  DB new1;
  float total = (obj2.meter*100 + obj2.centimeter)*0.393701 + obj1.feet*12 + obj1.inches;

  new1.feet = int(total)/12;
  new1.inches = fmod(total,12);
  return new1;
}


DM sum(DM obj2, DB obj1)
{
  DM new1;
  float total = obj2.meter*100 + obj2.centimeter + (obj1.feet*12 + obj1.inches)*2.54;

  new1.meter = int(total)/100;
  new1.centimeter = fmod(total,100);
  return new1;
}


void display(DB obj)
{
  cout<<obj.feet<<" foots & "<<obj.inches<<" inches\n";
}
void display(DM obj)
{
  cout<<obj.meter<<" meter & "<<obj.centimeter<<" centimeter\n";
}


int main()
{

  DB ft(1, 12);
  DM mt(0,60);

  DB sm1 = sum(ft, mt);
  DM sm2 = sum(mt, ft);

  display(sm1);
  display(sm2);



return 0;
}
