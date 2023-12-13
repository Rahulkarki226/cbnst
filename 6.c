#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float f(float x)
{
    return x*x*x-2*x-5;
}
int main()
{
    float x0, x1,x2,f0,f1,f2,alErr;
    int itr=1;
    printf("Enter the value of x0 and x1:\n");
    scanf("%f%f",&x0,&x1);
    printf("Enter allowed error:");
    scanf("%f",&alErr);
    do{
        f0=f(x0);
        f1=f(x1);
        if(f0==f1)
         {
            printf("Error");
            exit(0);
         }
         x2=x1-(x1-x0)*f1/(f1-f0);
         f2=f(x2);
         printf("%d iteration ,value of x0 is %f,value of x1 is %f, value of f(%f) is %f\n",itr,x0,x1,x2,f2);
         x0=x1;
         f0=f1;
         x1=x2;
         f1=f2;
         itr++;
    }while(fabs(f2)>alErr);
    printf("\n root is :%f",x2);
}