#include<iostream>
#include<conio.h>
int main()
{
  int m,chk=0;
  float **a,*x;
  std::cout<<"Enter number of variables>>";
  std::cin>>m;
  x=new float [m];
  a=new float *[m];
  for(int i=0;i<m;i++)
  {
    a[i]=new float[m+1];
  }
  float r;
  //setting the values in the matrix
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<m+1;j++)
    {
      std::cout<<"Enter value a["<<i<<"]["<<j<<"]:";
      std::cin>>a[i][j];
    }
  }
  //applying gauss elimination forward substitution
  for(int i=0;i<m-1;i++)
  {
    if(a[i][i]==0.0)
    {
      std::cout<<"Diagonal elements cannot be zero";
      chk=1;
      break;
    }
    for(int j=i+1;j<m;j++)
    {
      r=a[j][i]/a[i][i];
      for(int k=i;k<m+1;k++)
      {
        a[j][k]=a[j][k]-r*a[i][k];
      }
    }
  }
  if(chk==0)
  {
  float sum;
  //backward substitution
  for(int i=m-1;i>=0;i--)
  {
    sum=0;
    for(int j=i+1;j<m;j++)
    {
      sum+=a[i][j]*x[j];
    }
    x[i]=(a[i][m]-sum)/a[i][i];
  }
  //result
  for(int i=0;i<m;i++)
  {
    std::cout<<"x"<<i+1<<":"<<x[i]<<std::endl;
  }
  }
  delete[] x;
  for(int i=0;i<m;i++)
  {
    delete[] a[i];
  }
  delete[] a;
  getch();
  return 0;
}
