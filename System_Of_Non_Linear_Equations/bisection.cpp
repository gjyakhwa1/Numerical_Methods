#include<iostream>
#include<cmath>
float f(float x)
{
    return x*sin(x)+cos(x);
}
int main()
{
    int chk=0;
    float a,b,c,e;
    int maxitr,itr=0;
    std::cout<<"Enter values for a,b,e,maxitr>>";
    std::cin>>a>>b>>e>>maxitr;
    if(f(a)*f(b)<0)
    {
        chk=1;
        while(itr<maxitr)
        {
            c=(a+b)/2;
            if(f(a)*f(c)<0)
            {
                b=c;
            }
            else
            {
                a=c;
            }
            if(fabs(f(c))<e)
            {
                std::cout<<"Solution is "<<c<<std::endl;
                std::cout<<"Number of iterations required is "<<itr<<std::endl;
                chk=2;
                break;
            }
            itr++;
        }
        if(chk==1)
        {
            std::cout<<"Solution doesnot converge in given step"<<std::endl;
        }
    }
    if(chk==0)
    {
        std::cout<<"Solution doesnot exist in the given interval"<<std::endl;
    }
    return 0;
}