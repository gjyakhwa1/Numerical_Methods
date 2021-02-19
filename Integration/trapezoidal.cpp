#include<iostream>
#include<conio.h>
#include<cmath>
float f(float x)
{
    return cos(x);
}
int main()
{
    float a,b,n,h;
    std::cout<<"Enter lowerlimit,upperlimit,number of subintervals>>";
    std::cin>>a>>b>>n;
    h=(b-a)/n;
    float iValue{f(a)+f(b)};
    for(int i=1;i<n;i++)
    {
        iValue+=2*f(a+i*h);
    }
    iValue=iValue*(h/2);
    std::cout<<"Integration Value:"<<iValue<<std::endl;
    getch();
    return 0;
}