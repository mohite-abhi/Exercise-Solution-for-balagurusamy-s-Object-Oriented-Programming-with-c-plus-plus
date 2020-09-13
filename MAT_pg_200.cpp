#include<iostream>
#include <cmath>
using namespace std;

class MAT
{
private:
  int x, y;
  double **matrix;

public:
  MAT(){x=0;y=0;}
  MAT(int, int);
  MAT(const MAT &obj);
  void operator = (const MAT & obj);
  friend istream & operator >>(istream & mat_in,const MAT &obj);
  friend ostream & operator <<( ostream & mat_out,const MAT &obj);

  MAT operator +(const MAT &obj);
  MAT operator -( const MAT &obj);
  MAT operator *( const MAT &obj);
  friend MAT transpose(const MAT &obj);
  friend MAT cofactor(const MAT & obj, int row, int col);
  friend int determinant(const MAT &obj, int size);
  friend MAT adjoint(const MAT & obj);
  friend MAT inverse(const MAT & obj);

};

//-----------------------------------------------------------------------------------------------------------------------------------------------------

MAT transpose(const MAT &obj)            //transpose of matrix
{
  int x=obj.x,y=obj.y;
  MAT temp(y, x);

  for (int i = 0; i < obj.x; i++)
  {
    for (int j = 0; j <obj.y; j++)
    {
      temp.matrix[j][i]=obj.matrix[i][j];
    }

  }
  return temp;
}



MAT cofactor(const MAT & obj, int row, int col)
{
  MAT temp_mat(obj.x-1, obj.y-1);
  int rr=0,cc=0;

  for (int i = 0; i < obj.x; i++) {
    cc=0;
    if (i==row )
    {
      continue;
    }

    for (int j = 0; j < obj.y; j++) {

      if (j == col)
      {
        continue;
      }

      temp_mat.matrix[rr][cc] = obj.matrix[i][j];
      cc++;
    }

    rr++;
  }
  return temp_mat;
}


int determinant(const MAT &obj, int size)
{
  if (size == 1) {
    return obj.matrix[0][0];
  }

  int sum = 0;

  for (int i = 1; i <= size; i++) {
    MAT temp_mat = cofactor(obj, 0, i-1);

    sum = sum + pow(-1, i+1)*obj.matrix[0][i-1]*determinant(temp_mat, size-1);
  }
  return sum;

}


MAT adjoint(const MAT & obj)
{
  MAT temp_mat(obj.x, obj.y);

  for (int i = 0; i < obj.x; i++)
  {
    for (int j = 0; j < obj.y; j++)
    {
      temp_mat.matrix[i][j] = pow(-1, i+j)*determinant(cofactor(obj, i, j), obj.x-1);
    }
  }
  return transpose(temp_mat);
}



void MAT:: operator = (const MAT & obj)
{
  x=obj.x;y=obj.y;

  matrix = new double *[x];
  for (int i = 0; i < x; i++)
  {
    matrix[i] = new double[y];
  }

  for (int i = 0; i < x; i++)
  {
    for (int j = 0; j <y; j++)
    {
      matrix[i][j] = obj.matrix[i][j];
    }
  }
}



MAT::MAT(const MAT &obj)
{
  x=obj.x;y=obj.y;

  matrix = new double *[x];
  for (int i = 0; i <x; i++)
  {
    matrix[i] = new double[y];
  }

  for (int i = 0; i < x; i++)
  {
    for (int j = 0; j <y; j++)
    {
      matrix[i][j] = obj.matrix[i][j];
    }
  }
}




MAT::MAT(int xx, int yy)
{
  x=xx;y=yy;
  matrix = new double *[xx];
  for (int i = 0; i < xx; i++)
  {
    matrix[i] = new double[yy];
  }
}

istream & operator >>(istream & mat_in,const MAT &obj)
{
  for (int i = 0; i < obj.x; i++)
  {
    for (int j = 0; j <obj.y; j++)
    {
      mat_in>>obj.matrix[i][j];
    }
  }
  return (mat_in);
}
ostream & operator <<(ostream & mat_out,const MAT &obj)
{
  for (int i = 0; i < obj.x; i++)
  {
    for (int j = 0; j <obj.y; j++)
    {
      mat_out<<obj.matrix[i][j]<<"  ";
    }
    cout<<endl;

}

  return (mat_out);
}



MAT MAT:: operator +( const MAT &obj)
{
  MAT temp_mat(x,y);

  for (int i = 0; i < x; i++)
  {
    for (int j = 0; j <y; j++)
    {
      temp_mat.matrix[i][j]=obj.matrix[i][j] + matrix[i][j];
    }

  }
  return temp_mat;
}

MAT MAT:: operator -( const MAT &obj)
{
  MAT temp_mat(x,y);

  for (int i = 0; i < x; i++)
  {
    for (int j = 0; j <y; j++)
    {
      temp_mat.matrix[i][j]=obj.matrix[i][j] - matrix[i][j];
    }

  }
  return temp_mat;
}

MAT MAT:: operator *( const MAT &obj)
{
  MAT temp_mat(x,obj.y);

  for (int i = 0; i < x; i++)
  {
    for (int j = 0; j <obj.y; j++)
    {
      int sum=0;
      for (int k = 0; k < y; k++)
      {
        sum = sum + matrix[i][k]*obj.matrix[k][j];
      }
      temp_mat.matrix[i][j] = sum;
    }

  }

  return temp_mat;
}


MAT inverse(const MAT & obj)
{
  MAT temp_mat(obj.x, obj.y);
  MAT temp_mat2 = adjoint(obj);

  if (determinant(obj, obj.x) == 0) {
    cout<<"\n!! determinant is zero, so no inverse !!\n";
    return temp_mat;
  }

  for (int i = 0; i < obj.x; i++) {
    for (int j = 0; j < obj.y; j++) {
      temp_mat.matrix[i][j] = temp_mat2.matrix[i][j] / determinant(obj, obj.x);
    }
  }

  return temp_mat;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
  int x,y;

  cout<<"give size of first matrix : "<<endl<<"x1 = ";
  cin>>x;
  cout<<"y1 = ";
  cin>>y;
  MAT mat1(x,y);
  cout<<"\ngive matrix 1 of size : ("<<x<<", "<<y<<")\n";
  cin>>mat1;

  cout<<mat1<<endl;

  //MAT mat2 = cofactor(mat1,2,2);
  //cout<<"cofactor of mat1 :\n\n"<<mat2;
//  MAT mat2 = ;
  cout<<endl<<"inverse of mat1 is :\n\n"<<inverse(mat1);
/*
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      cout<<endl<<cofactor(mat1, i, j)<<endl;
    }
  }
*/
/*
  cout<<"give size of second matrix : "<<endl<<"x2 = ";
  cin>>x;
  cout<<"y2 = ";
  cin>>y;
  MAT mat2(x,y);
  cout<<"\ngive matrix 2 of size : ("<<x<<", "<<y<<")\n";
  cin>>mat2;

  cout<<mat2<<endl;

  MAT mat3 = mat1*mat2;

  cout<<endl<<"multiplication of matrix1 and matrix2 :\n\n"<<mat3;
*/

return 0;
}
