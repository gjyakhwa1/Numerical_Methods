#include<iostream>
#include<cmath>
float f(float x)
{
  return exp(cos(x))-sin(x);
}
int main()
{
  float x1,x2,x,e;
  int max_itr,itr=0;
  std::cout<<"Enter values for x1,x2,e,max_itr>>";
  std::cin>>x1>>x2>>e>>max_itr;
  if(f(x1)*f(x2)<0)
  {
    do {
        itr++;
        x=((x1*f(x2)-x2*f(x1))/(f(x2)-f(x1)));
        if(abs(f(x))<e)
        {
          std::cout<<"Root is :"<<x<<" after "<<itr<<" iterations"<<std::endl;
          break;
        }
        // std::cout<<"After "<<itr<<" iterations root is "<<x<<std::endl;
        x1=x2;
        x2=x;
    } while(itr<max_itr);
    if(itr>max_itr)
    {
    std::cout<<"Solution didnot converge with given number of iteration"<<std::endl;
  }
  }
  else
  {
    std::cout<<"Interval doesnot contain the solution"<<std::endl;
  }
  return 0;
}
