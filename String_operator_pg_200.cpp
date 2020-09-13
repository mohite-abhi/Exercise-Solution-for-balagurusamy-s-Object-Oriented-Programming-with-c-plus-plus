#include<iostream>
#include<cstring>
using namespace std;

class String
{
private:
  int len;
  char* string;

public:
  String(){len=0;string = new char[0];}
  String(const char*);
  String(const String & str);
  void operator = (const String & str);
  friend ostream & operator << (ostream & strout, const String & str_obj);
  friend istream & operator >> (istream & strin, String & str_obj);
  friend bool operator == (const String & str1, const String str2);
};


void String ::operator = (const String & str)
{
  if (len != 0){delete [] string;}
  len = str.len;
  string = new char[len];

  for (int i = 0; i < len; i++) {
    string[i] = str.string[i];
  }

}


String::String(const String & str)
{
  len = str.len;
  string = new char[len];

  for (int i = 0; i < len; i++) {
    string[i] = str.string[i];
  }

}

ostream & operator << (ostream & strout, const String & str_obj)
{
  for (int i = 0; i < str_obj.len; i++)
  {
    strout<<str_obj.string[i];
  }

  return (strout);
}

istream & operator >> (istream & strin, String & str_obj)
{
  delete str_obj.string;

  string temp;

  getline(cin, temp);

  str_obj.len = temp.length();
  str_obj.string = new char[str_obj.len+1];


  for (int i = 0; i < str_obj.len; i++) {
    str_obj.string[i] = temp[i];
  }

  return (strin);
}

bool operator == (const String & str1, const String str2)
{
  bool ans = true;
  if (str1.len != str2.len) {
    ans = !ans;
    return ans;
  }

  else
  {
    for (int i = 0; i < str1.len; i++) {
      if (str1.string[i] != str2.string[i])
      {
        ans = !ans;
        break;
      }
    }
  }
  return ans;

}

String::String(const char* str)
{
  len = strlen(str);

  string = new char[len];

  for (int i = 0; i < len; i++) {
    string[i] = str[i];
  }

}

int main()
{
  String name, name2;

  cout<<"give name1:"<<endl;
  cin>>name;
  cout<<"give name2:"<<endl;
  cin>>name2;
  

  if (name==name2) {
    cout<<"yes equal";
  }
return 0;
}
