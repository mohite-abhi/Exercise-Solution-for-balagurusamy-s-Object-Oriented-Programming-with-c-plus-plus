#include<iostream>
#include<iomanip>
using namespace std;

class person
{
protected:
    string name;
    int code;
public:
    person(string nm, int cd) : name(nm), code(cd) {}
    void update(string nm, int cd) {name = nm; code = cd;}
    void show(){cout<<"Name : "<<setw(20)<<name<<"\nCode : "<<setw(20)<<code<<endl;}
};

class account : virtual public person
{
protected:
    double pay;
public:
    account(string nm, int cd, double pe) : person(nm, cd), pay(pe) {}
    void update(double pe){pay = pe;}
    void show(){cout<<"pay : "<<setw(21)<<pay<<endl;}
};

class admin : virtual public person 
{
protected:
    int xp_yrs;
public:
    admin(string nm, int cd, int xp) : person(nm, cd), xp_yrs(xp) {}
    void update(int xp) {xp_yrs = xp;}
    void show(){cout<<"experience : "<<setw(14)<<xp_yrs<<endl;}
};

class master : public account, public admin
{
public:
    master(string nm, int cd, double pe, int xp) : account(nm, cd, pe), admin(nm, cd, xp), person(nm, cd) {}
    void update (string nm, int cd, double pe, int xp){person::update(nm, cd); account::update(pe);admin::update(xp);}
    void show(){person::show();account::show();admin::show();}
};

int main()
{
    master m1("abhi", 1234, 30000, 12);
    m1.update("mohite",1111,10000000, 20);
    m1.show();


return 0;
}
