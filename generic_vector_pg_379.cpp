#include<iostream>
using namespace std;

template<class T>

class vector
{
private:
    int size;
    T *val;
public:
    vector(int vl):size(vl) {val=new T[vl];}
    
    ~vector() {delete []val;}
    T& modify(int ele)
    {
        return val[ele];
        
    }

    vector & operator *(double mul)
    {
        for (int i = 0; i < size; i++)
        {
            val[i]=mul*val[i];
        }
        return *this;
    }

    template<class O>
    friend ostream & operator << (ostream & out, vector<O> & obj);
    

};

template<class T>
ostream & operator << (ostream & out, vector<T> & obj)
    {
        out<<"( ";
        for (int i = 0; i < obj.size; i++)
        {
            out<<obj.val[i];
            if (i!=obj.size-1)
            {
                cout<<", ";
            }
            
        }
    out<<" )"<<endl;
        
        return (out);
    }



int main()
{
vector <int> v1(3);

v1.modify(0) = 12;
v1*3;
cout<<v1;

return 0;
}
