#include<iostream>
#include<conio.h>
int main()
{
  int n;
  float *x,*y,xp;
  std::cout<<"Enter number of data>>";
  std::cin>>n;
  x=new float[n];
  y=new float[n];
  std::cout<<"Enter x"<<std::endl;
  for(int i=0;i<n;i++)
  {
    std::cin>>x[i];
  }
  std::cout<<"Enter y"<<std::endl;
  for(int i=0;i<n;i++)
  {
    std::cout<<x[i]<<"-->";
    std::cin>>y[i];
  }
  std::cout<<"Enter xp>>";
  std::cin>>xp;
  float total=0;
  float midtotal=1;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(i==j)
      {
        continue;
      }
      else
      {
        midtotal*=(xp-x[j])/(x[i]-x[j]);
      }
    }
    total+=midtotal*y[i];
    midtotal=1;
  }
  std::cout<<"Interpolated value is "<<total<<std::endl;
  delete[] x;
  delete[] y;
  getch();
  return 0;
}
