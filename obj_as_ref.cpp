#include<iostream>
using namespace std;

class duration
{
private:
  int hours;
  int minutes;

public:
  void setduration(int,int);
  void sum(duration &, duration &);
  void puttime();

};

void duration::setduration(int hr,int mn)
{
  hours =  hr;
  minutes = mn;
}

void duration::sum(duration & obj1, duration & obj2)
{
  minutes = (obj1.minutes + obj2.minutes) % 60;
  int rem_hours = (obj1.minutes + obj2.minutes) / 60;
  hours = obj1.hours + obj2.hours + rem_hours;
}

void duration::puttime()
{
  printf("%02d:%02d\n",hours, minutes );
}

int main()
{

  duration mid_sem, end_sem, total;

  mid_sem.setduration(1, 30);
  end_sem.setduration(2, 30);

  total.sum(end_sem, mid_sem);

  total.puttime();


return 0;
}
