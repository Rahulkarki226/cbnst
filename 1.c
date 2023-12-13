#include<stdio.h>
#include<math.h>
int main()
{
    float tv,appval,absErr;
    float relErr,perErr;
    tv=1/3.0;
    printf("Enter the approximate value:");
    scanf("%f",&appval);
    absErr=fabs(tv-appval);
    relErr=absErr/(float)tv;
    perErr=relErr*100;
    printf("Absolute error:%f\n",absErr);
    printf("Relative Error:%f\n",relErr);
    printf("Percentage Error:%f\n",perErr);
    return 0;
}