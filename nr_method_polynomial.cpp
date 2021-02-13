#include<iostream>
#include<math.h>
float *ptr;
int degree;
float f(float x)
{
  float value=0;
  for(int i=0;i<=degree;i++)
  {
    value+=*(ptr+i)*pow(x,i);
  }
  return value;
}
float df(float x)
{
  float value=0;
  for(int i=1;i<=degree;i++)
  {
    value+=*(ptr+i)*i*pow(x,i-1);
  }
  return value;
}
int main()
{
  std::cout<<"Enter degree of polynomial(greater than 1):";
  std::cin>>degree;
  ptr=new float[degree+1];
  if(degree<2)
  {
    std::cout<<"Enter degree greater than 1";
    return 0;
  }
  for(int i=0;i<=degree;i++)
  {
    std::cout<<"Enter coefficient for term with degree "<<i<<":";
    std::cin>>*(ptr+i);
  }
  float a,b,e;
  int max_itr,itr=1;
  float x,x1;
  std::cout<<"Enter the values for a,b,e,max_itr:";
  std::cin>>a>>b>>e>>max_itr;
  if(f(a)*f(b)<0)
  {
    x=(a+b)/2;
    do {
      x1=x-f(x)/df(x);
      std::cout<<"After "<<itr<<" iteration x="<<x1<<std::endl;
      if(fabs(x1-x)<e)
      {
        std::cout<<"x="<<x1<<"->Number of iteration required is "<<itr<<std::endl;
        break;
      }
      x=x1;
      itr++;
    } while(itr<max_itr);
  }
  else
  {
    std::cout<<"Interval maynot contain the solution"<<std::endl;
  }
  delete[] ptr;
  return 0;
}
