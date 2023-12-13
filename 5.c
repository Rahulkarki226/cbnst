#include<stdio.h>
#include<math.h>
float f(float x)
{
    return cos(x)-3*x+1;
}
float g(float x)
{
    return (1+cos(x))/3;
}
float h(float x)
{
    return (-sin(x)/3);
}
int main()
{
    int count=1;
    float x0,x,alErr;
    do{
        printf("Enter the value of x0: \n");
        scanf("%f",&x0);
        if(fabs(h(x0))<1)
        {
            printf("Valid input\n");
            break;
        }
        else
        {
            printf("Try again");
        }
    }while(1);
    printf("Enter allowed error:");
    scanf("%f",&alErr);
    do{
        x=g(x0);
        printf("%d Iteration ,value of x is %f, value of g(%f) is %f\n",count,x,x,g(x0));
        count++;
        x0=x;
    }while(fabs(f(x))>alErr);
    printf("\n Root is %f",x);
    return 0;
}