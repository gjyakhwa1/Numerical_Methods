#include<iostream>
#include<conio.h>
int main()
{
    int n;
    float *x,*y;
    float sumX=0,sumY=0,sumXY=0,sumX2=0,a,b;
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
    //calculating sum of x,x2,xy
    for(int i=0;i<n;i++)
    {
        sumX+=x[i];
        sumX2+=x[i]*x[i];
        sumXY+=x[i]*y[i];
        sumY+=y[i];
    }
    //finding constant a and b
    b=(n*sumXY-sumX*sumY)/(n*sumX2-sumX*sumX);
    a=(sumY-b*sumX)/n;
    std::cout<<"Required equations is"<<std::endl;
    if(b<0)
    {
        std::cout<<a<<"-"<<-b<<"x";
    }
    else
    {
        std::cout<<a<<"+"<<b<<"x";
    }
    delete[] x;
    delete[] y;
    getch();
    return 0;
}