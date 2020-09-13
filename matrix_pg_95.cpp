#include<iostream>
using namespace std;


void create_mat(int** (&matrix), int no_rows1=3, int no_coloumns1=3);

void print_mat(int **matrix,int no_rows2,int no_coloumns2);

int main()
{

  int no_rows,no_coloumns;

  cout<<"give no of rows ";
  cin >>no_rows;
  cout<<"give no of coloumns ";
  cin >>no_coloumns;

  int **matrix1;

  create_mat(matrix1, no_rows, no_coloumns);


cout<<"\n\n\n";

  print_mat(matrix1, no_rows, no_coloumns);

return 0;
}


void create_mat(int** (&matrix), int no_rows1, int no_coloumns1)
{
  matrix = new int *[no_rows1];
  for (int i = 0; i < no_rows1; i++) {
    matrix[i] = new int[no_coloumns1];
  }
  cout << "Give matrix : \n";

  for (int i = 0; i < no_rows1; i++) {

    cout<<"[Row "<<i+1<<" ]  ";
    for (int j = 0; j < no_coloumns1; j++) {

      cin >>matrix[i][j];
    }
  }

}


void print_mat(int **matrix,int no_rows2,int no_coloumns2)
{

  for (int i = 0; i < no_rows2; i++) {
    for (int j = 0; j < no_coloumns2; j++) {
      cout<<matrix[i][j]<<"\t";
    }
    cout<<"\n";
  }

}
