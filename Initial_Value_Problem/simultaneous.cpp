#include<iostream>
#include<cmath>
#include<conio.h>
float f(float x,float y,float z)
{
    return z;
}
float g(float x,float y,float z)
{
    return x*z-y;
}
int main()
{
    float x0,y0,z0,xn,yn,zn;
    float k1,k2,k3,k4,k;
    float l1,l2,l3,l4,l;
    float h;
    std::cout<<"Enter x0,y0,z0,xn,h>>";
    std::cin>>x0>>y0>>z0>>xn>>h;
    while(x0!=xn)
    {
        k1=h*f(x0,y0,z0);
        l1=h*g(x0,y0,z0);
        k2=h*f(x0+h/2,y0+k1/2,z0+l1/2);
        l2=h*g(x0+h/2,y0+k1/2,z0+l1/2);
        k3=h*f(x0+h/2,y0+k2/2,z0+l2/2);
        l3=h*g(x0+h/2,y0+k2/2,z0+l2/2);
        k4=h*f(x0+h,y0+k3,z0+l3);
        l4=h*g(x0+h,y0+k3,z0+l3);
        k=(k1+2*k2+2*k3+k4)/6;
        l=(l1+2*l2+2*l3+l4)/6;
        yn=y0+k;
        zn=z0+l;
        y0=yn;
        z0=zn;
        x0=x0+h;
    }
    std::cout<<"Required value yn="<<yn<<",zn="<<zn<<std::endl;
    getch();
    return 0;
}