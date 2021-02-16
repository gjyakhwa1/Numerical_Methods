#include<iostream>
#include<conio.h>
int main()
{
  const int n=4;
  float mat[n][2*n];

  //Getting value for each elements of matrix
  std::cout<<"Enter value for"<<std::endl;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      std::cout<<"a["<<i<<"]["<<j<<"]:";
      std::cin>>mat[i][j];
    }
  }

  //constructing augmented matrix [mat:I]
  for(int i=0;i<n;i++)
  {
    for(int j=n;j<2*n;j++)
    {
      if(j-n==i)
      {
        mat[i][j]=1;
      }
      else
      {
        mat[i][j]=0;
      }
    }
  }

  //Applying gauss jordan inverse method
  float r;
  for(int i=0;i<n;i++)
  {
    if(mat[i][i]==0)
    {
      std::cout<<"diagonal elements cannot be zero"<<std::endl;
      break;
    }
    for(int j=0;j<n;j++)
    {
      if(i!=j)
      {
      r=mat[j][i]/mat[i][i];
      for(int k=i;k<2*n;k++)
      {
        mat[j][k]=mat[j][k]-r*mat[i][k];
      }
      }
    }
  }
  //making diagonal elemnts one
  for(int i=0;i<n;i++)
  {
    r=mat[i][i];
    for(int j=0;j<2*n;j++)
    {
      mat[i][j]=mat[i][j]/r;
    }
  }
  //displaying matrix
  std::cout<<"Inverse matrix is"<<std::endl;
  for(int i=0;i<n;i++)
  {
    for(int j=n;j<2*n;j++)
    {
      std::cout<<mat[i][j]<<"  ";
    }
    std::cout<<std::endl;
  }
  getch();
  return 0;
}
