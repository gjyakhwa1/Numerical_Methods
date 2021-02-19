#include<iostream>
#include<cmath>
#include<conio.h>
float f(float x,float y)
{
    return x*x+y*y;
}
int main()
{
    float x0,y0,n,xn,yn,k1,k2,k3,k4,k;
    std::cout<<"Enter x0,y0,n,xn>>";
    std::cin>>x0>>y0>>n>>xn;
    float h{(xn-x0)/n};
    for(int i=0;i<n;i++)
    {
        k1=h*f(x0,y0);
        k2=h*f(x0+h/2,y0+k1/2);
        k3=h*f(x0+h/2,y0+k2/2);
        k4=h*f(x0+h,y0+k3);
        k=(k1+2*k2+2*k3+k4)/6;
        yn=y0+k;
        y0=yn;
        x0=x0+h;
    }
    std::cout<<"Required value:"<<yn<<std::endl;
    getch();
    return 0;
}