#include<iostream>
#include<cmath>
/* Defining equation to be solved.
   Change this equation to solve another problem. */
float f(float x)
{
    return x*sin(x)+cos(x);
}   
/* Defining derivative of g(x).
   As you change f(x), change this function also. */
float g(float x)
{
    return x*cos(x);
}  
int main()
{
	 float x0, x1, f0, f1, g0, e;
	 int step = 1, maxitr;
	 std::cout<<"Enter initial guess: ";
	 std::cin>>x0;
	 std::cout<<"Enter tolerable error: ";
	 std::cin>>e;
	 std::cout<<"Enter maximum iteration: ";
	 std::cin>>maxitr;
	 do
	 {
		  g0 = g(x0);
		  f0 = f(x0);
		  if(g0 == 0.0)
		  {
			   std::cout<<"Derivate zero not possible";
			   exit(0);
		  }
		  x1 = x0 - f0/g0;
		  x0 = x1;
		  step++;
		  if(step > maxitr)
		  {
			   std::cout<<"Not Convergent.";
			   exit(0);
		  }

		  f1 = f(x1);

	 }while(fabs(f1)>e);
	 std::cout<<"Root is: "<< x1;
	 return 0;
}