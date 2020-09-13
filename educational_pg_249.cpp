#include<iostream>
#include<iomanip>
using namespace std;

class staff
{
protected:
    int code;
    string name;
    staff(int cd, string nm) : code(cd), name(nm){}
    void show(){cout<<"=================data=================\n\nCode : "<<setw(20)<<code<<"\nName : "<<setw(20)<<name<<endl;}

};

class education
{
protected:
    string max_study_degree;
    string max_work_degree;
    education(string msd, string mwd) : max_study_degree(msd), max_work_degree(wsd) {}
}

class teacher : public staff, public education
{
    string subject;
    string publication;

public:
    teacher (int cd, string nm, string sub, string pub, string msd, string mwd) : staff(cd, nm), subject(sub), publication(pub),
    education(msd, mwd) {}
    void show(){staff::show(); cout<<"subject : "<<setw(17)<<subject<<"\npublication : "<<setw(13)<<publication<<endl;}

};

class officer : public staff, public education
{
    string grade;
public:
    officer(int cd, string nm, string grd, string msd, string mwd) : staff(cd, nm), grade(grd), subject(sub), publication(pub),
    education(msd, mwd) {}
    void show(){staff::show(); cout<<"grade : "<<setw(19)<<grade<<endl;}

};

class typist : public staff
{
protected:
    double speed;
    typist(int cd, string nm, double spd) : staff(cd, nm), speed(spd) {}
    void show(){staff::show(); cout<<"speed : "<<setw(19)<<speed<<endl;}


};

class regular : public typist
{
public:
    regular(int cd, string nm, double spd) : typist(cd,nm,spd){};
    void show(){typist::show();}
    
};

class casual : public typist
{
private:
    double daily_wages;
public:
    casual(int cd, string nm, double spd, double dlwg) : typist(cd,nm,spd), daily_wages(dlwg) {};
    void show(){typist::show(); cout<<"daily wages : "<<setw(13)<<daily_wages<<endl;}
};


int main()
{

casual t1(123, "hasan", 333, 33.33);
t1.show();
return 0;
}
