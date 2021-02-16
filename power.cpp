#include<iostream>
#include<conio.h>
#include<cmath>
int main()
{
    int n;
    float **a,*xOld,*xNew,lambdaOld,lambdaNew,e;
    std::cout<<"Enter size of matrix,tolerable error:";
    std::cin>>n>>e;
    xOld=new float [n];
    xNew=new float [n];
    a=new float *[n];
    for(int i=0;i<n;i++)
    {
        a[i]=new float [n];
    }
    //Inout matrix
    std::cout<<"Enter elements of matrix"<<std::endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            std::cout<<"a["<<i<<"]["<<j<<"]:";
            std::cin>>a[i][j];
        }
    }
  //Input Eigen Vector
    std::cout<<"Enter eigen vector"<<std::endl;
    for(int i=0;i<n;i++)
    {
        std::cout<<"x["<<i<<"]:";
        std::cin>>xOld[i];
    }
    lambdaNew=1;
    float temp;
    do
    {
        lambdaOld=lambdaNew;
        //performing xNew=a*xOld
        for(int i=0;i<n;i++)
        {
            temp=0;
            for(int j=0;j<n;j++)
            {
                temp+=a[i][j]*xOld[j];
            }
            xNew[i]=temp;
        }
        //finding maximum lamda from xNew
        lambdaNew=abs(xNew[0]);
        for(int i=1;i<n;i++)
        {
            if(lambdaNew<abs(xNew[i]))
            {
                lambdaNew=abs(xNew[i]);
            }
        }
        //normalization and replacing x by x_new
        for(int i=0;i<n;i++)
        {
            xOld[i]=xNew[i]/lambdaNew;
        }
    }while(abs(lambdaNew-lambdaOld)>e);
    std::cout<<"Eigen Value is "<<lambdaNew<<std::endl;
    std::cout<<"Eigen vector is"<<std::endl;
    for(int i=0;i<n;i++)
    {
        std::cout<<xOld[i]<<" ";
    }
    std::cout<<std::endl;
    delete[] xOld;
    delete[] xNew;
    for(int i=0;i<n;i++)
    {
        delete[] a[i];
    }
    delete[] a;
    getch();
    return 0;
}