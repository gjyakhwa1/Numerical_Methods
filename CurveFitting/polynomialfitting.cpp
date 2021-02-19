#include<iostream>
#include<conio.h>
#include<iomanip>
#include<cmath>
int main()
{
    int mp,n,m;
    double **c,*a,*x,*y;
    std::cout<<"Enter degree of the polynomials,number of data points>>";
    std::cin>>mp>>n;
     if(n<=mp)
    {
        std::cout<<"Calculation not possible"<<std::endl;
        getch();
        return 0;
    }
    m=mp+1;
    x=new double[n];
    y=new double[n];
    a=new double[m];
    c=new double*[m];
    for(int i=0;i<m;i++)
    {
        c[i]=new double[m+1];
    }
    std::cout<<"Enter data points.."<<std::endl;
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
    //determining elements of the matrix
    double sum,sumXY;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            sumXY=0;
            sum=0;
            for(int k=0;k<n;k++)
            {
                sum+=pow(x[k],i+j);
                sumXY+=y[k]*pow(x[k],j);
            }
            c[i][j]=sum;
            c[j][m]=sumXY;
        }
    }
    //gauss jordan
    double r;
    for(int i=0;i<m;i++)
    {
    if(c[i][i]==0)
    {
        std::cout<<"Diagonal element cannot be zero"<<std::endl;
        return 0;
    }
    for(int j=0;j<m;j++)
    {
        if(i!=j)
        {
        r=c[j][i]/c[i][i];
        for(int k=i;k<m+1;k++)
        {
            c[j][k]=c[j][k]-r*c[i][k];
        }
        }
    }
    }
    //solution
    for(int i=0;i<m;i++)
    {
        a[i]=c[i][m]/c[i][i];
    }
    //constants are
    for(int i=0;i<m;i++)
    {
        std::cout<<"a"<<i+1<<":"<<a[i]<<std::endl;
    }
    delete[] a;
    delete[] x;
    delete[] y;
    for(int i=0;i<m;i++)
    {
        delete[] c[i];
    }
    delete[] c;
    getch();
    return 0;
}