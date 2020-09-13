#include<iostream>
using namespace std;

template<class T>

T min_in_arr(T *ar, int sz)
{

    T cur_min=ar[0];

    for (int i = 0; i < sz; i++)
    {
        if (ar[i]<cur_min)
        {
            cur_min=ar[i];
        }
        
    }

    return cur_min;
    
}

int main()
{

    cout<<"give size of array\n";
    int s;cin>>s;


    string arr[s];
    cout<<"give array elements : \n";

    for (int i = 0; i < s; i++)
    {
        cout<<i+1<<" : ";cin>>arr[i];
    }

cout<<endl<<min_in_arr(arr,s)<<endl;

return 0;
}
