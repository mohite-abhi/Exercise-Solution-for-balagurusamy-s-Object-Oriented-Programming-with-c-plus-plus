#include<iostream>
#include<iomanip>
#include<boost/lexical_cast.hpp>
#include<fstream>
using namespace std;

class contact
{
private:
  string name;
  int telephone;

public:
  
  void update(int no, string filename)
  {
    telephone=no;
    fstream ff;
    ff.open(filename,ios::app);
    ff<<endl<<name<<"  "<<no;
    ff.close();
  }
  void put(string nme, int phn){name=(nme);telephone=(phn);}
  void show()
  {
    cout<<left<<setw(15)<<name;
    cout<<right<<setw(15)<<telephone;
    cout<<endl;
  }

  int check_no(int &num)
  {
    if(telephone==num) 
    {
      return 1;
      }
    else
    {
      return 0;
    } 
  }
  int check_nm(string& nm){if(name==nm) {return 1;}else{return 0;} }
};

int main()
{
  
  fstream fp;
  fp.open("/home/tyson/Desktop/abc.txt", ios::in);
  
  string temp1;
  string temp2;


  string line_temp_storage;
  int no_of_line;
  while(getline(fp, line_temp_storage))
  {
    no_of_line++;
  }


  contact connection[no_of_line];
  
  fp.close();

  fp.open("/home/tyson/Desktop/abc.txt", ios::in);

  int index=0;
  while (fp.good())
  {
    fp>>temp1;
    fp>>temp2;

    connection[index++].put(temp1,boost::lexical_cast<float>(temp2));
  }

  fp.close();
  cout<<left<<setw(15)<<" Name :";
  cout<<right<<setw(15)<<"telephone : "<<endl<<"______________________________\n";
  

/*
    cout<<left<<setw(15)<<temp1;
    cout<<right<<setw(15)<<temp2;
    cout<<endl;
    */

   cout.fill('-');

  int choice, temp_num, found_id=-1;
   cout<<left<<setw(30)<<"1. Find by telephone no."<<endl;
   cout<<left<<setw(30)<<"2. Find by name"<<endl;
   cin>>choice;

   if (choice==1)
   {
    cout<<"\ngive no : ";cin>>temp_num;

     for (int i = 0; i < no_of_line; i++)
     {
       if (connection[i].check_no(temp_num))
       {
         found_id=i;
         
       }
       
     }
     
   }

  string temp_nme;
   if (choice==2)
   {
    cout<<"\ngive name : ";cin>>temp_nme;

     for (int i = 0; i < no_of_line; i++)
     {
       if (connection[i].check_nm(temp_nme))
       {
         found_id=i;
       }
       
     }
     
   }

  if (found_id !=-1)
  {
    cout<<"----found !----\n\n";
    connection[found_id].show();
    cout<<endl;
  }
  
   
   
  if (found_id !=-1)
  {
   cout<<left<<setw(30)<<"3. Update contact? y or n";
   char up;cin>>up;
   if (up=='y')
   {
     int no;
     cout<<"\ngive new no.";
     cin>>no;
     connection[found_id].update(no, "/home/tyson/Desktop/abc.txt");
    
   }
   
  }
  

  return 0;
}
