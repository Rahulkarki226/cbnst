//bisection method
#include<stdio.h>
#include<math.h>
float f(float x)
{
    return (cos(x)-x*exp(x));
}
int main()
{
    float x0,x1,x,alErr;
    do{
        printf("Enter the value of x0 and x1:");
        scanf("%f %f",&x0,&x1);
        if(f(x0)*f(x1)>=0)
        {
            printf("Wrong interval, try again:");
        }
        else
        {
            printf("The root lie between [%f %f]\n",x0,x1);
            break;
        }
    }while(1);
    printf("Enter the allowed error:");
    scanf("%f",&alErr);
    int count=1;
    do{
        x=(x1+x0)/2;
        printf("%d Iteration value of x is %f , value f(%f) is %f\n",count,x,x,f(x));
        if(f(x)*f(x0)<0)
        {
            x1=x;
        }
        else
        {
            x0=x;
        }
        count++;
    
    }while(fabs(f(x))>alErr);
    printf("The Root of the Equation is :%f",x);
    

}
