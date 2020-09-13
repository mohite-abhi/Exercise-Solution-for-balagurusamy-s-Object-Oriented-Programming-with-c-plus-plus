#include<iostream>
#include<iomanip>
using namespace std;

class list
{
private:
    int no_of_item;
    string *name;
    int *code;
    float *cost;
public:
    list(int kk): no_of_item(kk) {name = new string[kk]; code = new int[kk]; cost = new float[kk];}
    void get_list();
    static void display_head();
    void display();
};




void list::get_list()
{
    for (int i = 0; i < no_of_item; i++)
    {
        cout<<"name : ";cin>>name[i];
        cout<<"code : ";cin>>code[i];
        cout<<"cost : ";cin>>cost[i];
    }
    
}

void list:: display_head()
{
    cout.setf(ios::left,ios::adjustfield);
    cout.width(20);cout<<"NAME";
    cout.width(10);cout<<"CODE";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(10);cout<<"COST\n";
    cout<<"________________________________________\n";

}


void list:: display()
{
    cout.fill('-');
    display_head();
    for (int i = 0; i < no_of_item; i++)
    {
        cout.setf(ios::left,ios::adjustfield);
    cout.width(20);cout<<name[i];
    cout.width(10);cout<<code[i];
    cout.setf(ios::right, ios::adjustfield);
    cout.width(10);cout<<fixed<<setprecision(2)<<cost[i]<<"\n";
    
    }
    
    cout<<"________________________________________\n";
}


int main()
{
list l1(1);

l1.get_list();
l1.display();


return 0;
}
