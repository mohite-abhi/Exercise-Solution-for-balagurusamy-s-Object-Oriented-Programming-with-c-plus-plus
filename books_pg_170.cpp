#include<iostream>
#include <cstring>
using namespace std;

int bookcount = 0;

class books
{
private:
  string author;
  string title;
  string publisher;
  int stock;
  double price;
  int success;
  int unsuccess;
  void increase_price(double addd)
  {
    price += addd;
  }

public:
    books()
    {
      author = "";
      title = "";
      publisher = "";
      stock = 0;
      price = 0;
    }
    void details(string ath, string tit, string pub, int stk, double prc);
    void show_details();
    friend void findbooks(books arr_obj[], string given_ath, string given_tit);

};


void books::show_details()
{
  cout<<"\n\""<<title<<"\" by "<<author<<endl<<"publisher :"<<publisher<<",\tstock = "<<stock<<",\tprice"<<price<<endl<<endl;
}

void books::details(string ath, string tit, string pub, int stk, double prc)
{
  author = ath;
  title =  tit;
  publisher =  pub;
  stock = stk;
  price = prc;
  bookcount++;
}


void findbooks(books arr_obj[], string given_ath, string given_tit)
{
  for (int i = 0; i < bookcount; i++) {
    if(arr_obj[i].success-arr_obj[i].unsuccess >20)
    {
      arr_obj[i].price+=10;
    }
    if(arr_obj[i].author == given_ath &&arr_obj[i].title == given_tit)
    {

      arr_obj[i].show_details();

      cout<<"\nhow many books do you want?";
      int temp;
      cin>>temp;
      if (temp<=arr_obj[i].stock) {
        cout<<"your bill is Rs. "<<arr_obj[i].price*temp;
        int tem;
        cout<<"\nenter 1 to confirm...";
        cin>>tem;
        if (tem ==1) {
          arr_obj[i].stock -= temp;
          arr_obj[i].success ++;
        }
        else
        {
          arr_obj[i].unsuccess++;
        }

      }
      else
      {
        cout<<"that much stock not availeble";
        arr_obj[i].unsuccess++;
      }
      break;

    }
    else if (i==bookcount-1)
    {
      cout<<"no luck finding your book"<<endl;
      arr_obj[i].unsuccess++;
    }
  }
}

int main()
{
  books fiction[3];

  fiction[0].details( "j k rowling", "harry potter", "swan", 12, 321.00);
  fiction[1].details("abhishek", "mohite", "rewa", 100, 100);



  void (books::*alias)(string,string,string,int,double) = & books::details;





return 0;
}
