#include<iostream>
#include<fstream>
using namespace std;


int main()
{
  
    fstream fp, fp_cpy;
    fp.open("abc.txt", ios::in);

    fp_cpy.open("cba.txt",ios::out);

    char temp_ch;
    int flag=0;


    while (fp)
    {
        fp.get(temp_ch);
        if (temp_ch != ' ' )
        {
            fp_cpy.put(temp_ch);
            flag=0;
        }

        else if (flag == 0)
        {
            fp_cpy.put(temp_ch);
            flag=1;
        }
    }


    return 0;
}
