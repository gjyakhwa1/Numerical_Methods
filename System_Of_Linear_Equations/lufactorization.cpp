#include<iostream>
#include<iomanip>
void display_matrix(float **a,int n)
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      std::cout<<std::left<<std::setw(10);
      std::cout<<a[i][j];
    }
    std::cout<<std::endl;
  }
}
int main()
{
  int n;
  std::cout<<"Enter number of varibales>>";
  std::cin>>n;
  float **a,**l,**u,*x,*b,*y;
  a=new float*[n];
  l=new float*[n];
  u=new float*[n];
  x=new float[n];
  y=new float[n];
  b=new float[n];
  for(int i=0;i<n;i++)
  {
    a[i]=new float[n];
    l[i]=new float[n];
    u[i]=new float[n];
  }
  std::cout<<"Getting coefficient input..."<<std::endl;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      std::cout<<"Enter a["<<i+1<<"]["<<j+1<<"]>>";
      std::cin>>a[i][j];
    }
  }
  std::cout<<"\nGetting input..."<<std::endl;
  for(int i=0;i<n;i++)
  {
    std::cout<<"Enter b["<<i+1<<"]>>";
    std::cin>>b[i];
  }
  std::cout<<"\nInput matrix is..."<<std::endl;
  display_matrix(a,n);
  float sum;
  std::cout<<"\nApplying LU factorization..."<<std::endl;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      sum=0;
      if(i<=j)
      {
        if(i==j)
        {
          l[i][j]=1;
        }
        else
        {
          l[i][j]=0;
        }
        for(int k=0;k<i;k++)
        {
          sum+=l[i][k]*u[k][j];
        }
        u[i][j]=a[i][j]-sum;
      }
      else
      {
        u[i][j]=0;
        for(int k=0;k<j;k++)
        {
          sum+=l[i][k]*u[k][j];
        }
        l[i][j]=(a[i][j]-sum)/u[j][j];
      }
    }
  }
  std::cout<<"\nUnit lower traingular matrix is..."<<std::endl;
  display_matrix(l,n);
  std::cout<<"\nUpper traingular matrix is..."<<std::endl;
  display_matrix(u,n);

  //forward substitution
for(int i=0;i<n;i++)
{
  sum=0;
  for(int j=0;j<=i-1;j++)
  {
    sum+=l[i][j]*y[j];
  }
  y[i]=b[i]-sum;
}
//backward substitution
for(int i=n-1;i>=0;i--)
{
  sum=0;
  for(int j=i+1;j<n;j++)
  {
    sum+=u[i][j]*x[j];
  }
  x[i]=(y[i]-sum)/u[i][i];
}
std::cout<<"\nSolution is..."<<std::endl;
for(int i=0;i<n;i++)
{
  std::cout<<"x"<<i+1<<":"<<x[i]<<std::endl;
}
  for(int i=0;i<n;i++)
  {
    delete[] a[i];
    delete[] l[i];
    delete[] u[i];
  }
  delete[] a;
  delete[] l;
  delete[] u;
  delete[] x;
  delete[] b;
  delete[] y;
  return 0;
}
