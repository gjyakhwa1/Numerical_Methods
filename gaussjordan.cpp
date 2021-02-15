#include<iostream>

int main()
{
  int m;
  std::cout<<"Enter number of variables>>";
  std::cin>>m;
  float a[m][m+1],x[m];
  float r;
  //setting the values in the matrix
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<m+1;j++)
    {
      std::cout<<"Enter value a["<<i<<"]["<<j<<"]:";
      std::cin>>a[i][j];
    }
  }
  //applying Gauss jordan method
  for(int i=0;i<m;i++)
  {
    if(a[i][i]==0)
    {
      std::cout<<"Diagonal element cannot be zero"<<std::endl;
      return 0;
    }
    for(int j=0;j<m;j++)
    {
      if(i!=j)
      {
        r=a[j][i]/a[i][i];
        for(int k=i;k<m+1;k++)
        {
          a[j][k]=a[j][k]-r*a[i][k];
        }
      }
    }
  }
  //solution
  for(int i=0;i<m;i++)
  {
      x[i]=a[i][m]/a[i][i];
  }
  std::cout<<"Required solution is"<<std::endl;
  for(int i=0;i<m;i++)
  {
    std::cout<<"x"<<i+1<<"="<<x[i]<<std::endl;
  }
return 0;
}
