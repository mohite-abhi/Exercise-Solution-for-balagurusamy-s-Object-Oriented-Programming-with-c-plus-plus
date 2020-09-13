#include<iostream>
using namespace std;

class FLOAT
{
private:
  float only_one_data_member;
public:
  FLOAT(float dta){only_one_data_member = dta;}
  void show(){cout<<"data is "<<only_one_data_member;}
  float operator + (FLOAT flt_data);
  float operator - (FLOAT flt_data);
  float operator * (FLOAT flt_data);
  float operator / (FLOAT flt_data);

};

float FLOAT:: operator + (FLOAT flt_data)
{
  return only_one_data_member + flt_data.only_one_data_member;
}

float FLOAT::operator - (FLOAT flt_data)
{
  return only_one_data_member - flt_data.only_one_data_member;
}


float FLOAT:: operator * (FLOAT flt_data)
{
  return only_one_data_member * flt_data.only_one_data_member;
}

float FLOAT::operator / (FLOAT flt_data)
{
  return only_one_data_member / flt_data.only_one_data_member;
}

int main()
{
  FLOAT abc = 123.421, bca = 22.33, cba = abc + bca;
  cba.show();

return 0;
}
