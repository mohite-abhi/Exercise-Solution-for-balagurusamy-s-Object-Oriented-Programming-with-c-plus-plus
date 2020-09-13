#include<iostream>
using namespace std;



int main()
{
    char cont_input =' ', last_char=0;
    int no_of_char = 0;
    int no_of_words = 0;
    int no_of_lines = 0;

    

    int count=0;
    while (cont_input != 27)
    {

        no_of_char++;
        if (count==0 && cont_input != ' ' &&cont_input!='\n')
        {
            count=1;
        }

        if (count==1 && (cont_input ==' ' or cont_input =='\n' ) )
        {
            no_of_words++;
            count=0;
        }




        if (cont_input == '\n')
        {
            no_of_lines++;
        }
        last_char=cont_input;
        
        cin.get(cont_input);
    }
    if (!(last_char == '\n' || last_char ==' '))
    {
        no_of_words++;
    }
    
    
    cout<<"no. of words : "<<no_of_words<<endl;
    cout<<"no of lines : "<<no_of_lines<<endl;
    cout<<"no_of_characters : "<<no_of_char-1<<endl;
    


return 0;
}
