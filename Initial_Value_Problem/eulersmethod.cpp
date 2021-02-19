#include<iostream>
#include<cmath>
#include<conio.h>
float f(float x,float y)
{
    return sin(x*y);
}
int main()
{
    float x0,y0,n,xn,yn;
    std::cout<<"Enter x0,y0,n,xn>>";
    std::cin>>x0>>y0>>n>>xn;
    float h{(xn-x0)/n};
    for(int i=0;i<n;i++)
    {
        yn=y0+h*f(x0+h*i,y0);
        y0=yn;
    }
    std::cout<<"Required value:"<<yn<<std::endl;
    getch();
    return 0;
}