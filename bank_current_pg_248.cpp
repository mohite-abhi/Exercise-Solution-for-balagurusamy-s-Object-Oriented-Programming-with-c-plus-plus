#include <iostream>
#include <cmath>

using namespace std;

class account
{
protected:
    string name;
    int acc_num;
    string acc_type;
    double balance;

public:
    account(string nm, int acno) : name(nm), acc_num(acno) {}
    void accept(double money)  {  balance = balance + money;}
    void show(){cout<<"============data==============\n"<<"\nname : "<<name<<"\nacc. no : "<<acc_num<<"\nacc. type : "
    <<acc_type<<"\nbalance : "<<balance<<endl;}


};

class cur_acct : public account
{
private:
    double min_bal;
    double penalty;

public:
    cur_acct(string nm, int acno) : account(nm,acno) { acc_type = "current"; balance = min_bal = 20000;}
    void penalty_update(){if (balance < min_bal){ penalty += 500;}}

};

class sav_acct : public account
{
private:
    int time_in_years;
    static double rate_of_interest;
public:
    sav_acct(string nm, int acno) : account(nm,acno) { acc_type = "saving"; balance = time_in_years = 0;}
    void withdraw(double money){ if (money < balance){balance -= money;} else {cout<<"Balace insufficient !";}}
    void update_time(int yrs){time_in_years = yrs;}
    void compuoud_interest() { balance = balance * pow(1+rate_of_interest, time_in_years);}

};
double sav_acct::rate_of_interest = 0.06;

int main()
{
    sav_acct acc1("abhishek",12345);
    acc1.accept(1111.11);
    acc1.show();
    acc1.update_time(3);
    acc1.compuoud_interest();
    acc1.show();
    acc1.withdraw(122345);
    acc1.show();
}