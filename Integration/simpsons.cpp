#include<iostream>
#include<conio.h>
#include<cmath>
float f(float x)
{
    return pow(x,3);
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
        if(i%3==0)
        {
            iValue+=2*f(a+i*h);
        }
        else
        {
            iValue+=3*f(a+i*h);
        }
    }
    iValue=iValue*(3*h/8);
    std::cout<<"Integration Value:"<<iValue<<std::endl;
    getch();
    return 0;
}