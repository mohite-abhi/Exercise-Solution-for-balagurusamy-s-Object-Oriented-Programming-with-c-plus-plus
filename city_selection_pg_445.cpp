#include<iostream>
#include<list>
using namespace std;



int main()
{
    list<string> city_names;
    

    string choice="thatsit";
    cout<<"give name of city and press enter, give 'thatsit' as city to exit \n";
    do
    {   
        cout<<"give city : ";cin>>choice;
        city_names.push_front(choice);
    }while (choice != "thatsit");
    
    cout<<"\nyour list :\n___________________________";
    list <string> ::iterator point ;
    for (point= city_names.begin() ; point!=city_names.end(); point++)
    {
        string temp_str=*point;
        if (temp_str[0]=='B' or temp_str[0]=='C')
        {
            cout<<*point<<endl;
        }
        
        
    }
    
    string kk;
    

return 0;
}
