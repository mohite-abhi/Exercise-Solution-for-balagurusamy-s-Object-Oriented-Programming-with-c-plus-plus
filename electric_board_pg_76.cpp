#include<iostream>
using namespace std;

int main()
{
  int N;

  cout << "Give no. of consumers : " << endl;
  cin >> N;

  float units[N];

  string names[N];

  for (int i = 0; i < N; i++)
  {
    cout << "Give name : ";
    cin >> names[i];
    cout << "Give units : ";
    cin >> units[i];
  }

  for (int i = 0; i < N; i++)
  {
    float bill;

    if (units[i] <= 100) {
      bill = (60 * units[i])/100;
    }

    else if (units[i] <= 200)
    {
      bill = (80 * units[i])/100;
    }

    else if (units[i] <= 300)
    {
      bill = (90 * units[i])/100;
    }

    else
    {
      bill = (90 * units[i])/100 + ((90 * units[i])/100)*0.15;
    }

    cout << "Bil for "<<names[i]<<" is Rs. ";
    printf("%.2f\n", bill);
  }


return 0;
}
