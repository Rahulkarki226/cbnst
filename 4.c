// newton raphson method
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float f(float x )
{
    return 3*x - cos(x) -1;
}
float g(float x)
{
    return 3 + sin(x);
}
int main()
{
    float x0,x,f0,g0,alErr;
    int count=1;
    printf("Enter the initial guess:\n");
       scanf("%f",&x0);
     printf("Enter the allowed error:");
     scanf("%f",&alErr);
     printf("it\t\tx0\t\tf(x0)\t\tx\t\tf(x)\n");
     do{
         g0=g(x0);
         f0=f(x0);
         if(g0==0.0)
         {
             printf("Mathematical error");
             exit(0);
         }
         
         x = x0 - f0/g0;
         printf("%d\t\t%f\t%f\t%f\t%f\n",count,x0,f0,x,f(x));
         x0=x;
         count++;
         
     }while(fabs(f(x))>alErr);
     printf("Root is: %f",x);
     return 0;
   
   
}