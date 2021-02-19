#include<iostream>
#include<cmath>
#include<conio.h>
float f(float x,float y)
{
    return cos(x);
}
int main()
{
    float x0,y0,n,xn,yn,k1,k2,k;
    std::cout<<"Enter x0,y0,n,xn>>";
    std::cin>>x0>>y0>>n>>xn;
    float h{(xn-x0)/n};
    for(int i=0;i<n;i++)
    {
        k1=h*f(x0,y0);
        k2=h*f(x0+h,y0+k1);
        k=(k1+k2)/2;
        yn=y0+k;
        y0=yn;
        x0=x0+h;
    }
    std::cout<<"Required value:"<<yn<<std::endl;
    getch();
    return 0;
}