#include<iostream>
using namespace std;

class shape
{
protected:
    double val1, val2;
public:
    void get_data(double vl1, double vl2=0) {val1=vl1;val2 =vl2;}
    virtual void display_area() {cout<<"area is fuck you;!";};
 
};



class triangle : public shape
{
private:
    /* data */
public:

    void display_area(){cout<<"area of triangle is " << (0.5*val1*val2)<<endl;}
    

 
};



class rectangle : public shape
{
private:
    /* data */
public:
    void display_area(){cout<<"area of rectangle is "<<(val1*val2)<<endl;}
};

class circle : public shape
{
private:
    /* data */
public:
};


int main()
{
    double temp1,temp2, temp3, temp4;

    cout<<"give space seperated values for length and breadth : "; cin>>temp1>>temp2;
    rectangle r1;
    r1.get_data(temp1,temp2);

    

    cout<<"give space seperated values for base and height : "; cin>>temp3>>temp4;
    circle t1;
    t1.get_data(temp3, temp4);
    
    shape *ptr[2];

    ptr[0]=&t1;
    ptr[1]=&r1;

    ptr[0]->display_area();
    ptr[1]->display_area();


return 0;
}
