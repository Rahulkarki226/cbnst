// gauss elimination
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    float a[10][10],x[10],ratio;
    int n;
    printf("Enter number of unknowns:");
    scanf("%d",&n);
    printf("Enter Augmented Matrix:\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n+1;j++)
        {
            scanf("%f",&a[i][j]);
        }
    }
    // applying gauss elimination
    for(int i=1;i<=n-1;i++)
    {
        if(a[i][i]==0.0)
        {
            printf("Mathematical Error");
            exit(0);
        }
        for(int j=i+1;j<=n;j++)
        {
            ratio =a[j][i]/a[i][i];
            for(int k=1;k<=n+1;k++)
            {
                a[j][k]=a[j][k]-ratio*a[i][k];
            }
        }
    }

    x[n]=a[n][n+1]/a[n][n];
    for(int i=n-1;i>=1;i--)
    {
        x[i]=a[i][n+1];
        for(int j=i+1;j<=n;j++)
        {
            x[i]=x[i]-a[i][j]*x[j];
        }
        x[i]=x[i]/a[i][i];
    }

    printf("solution\n");
    for(int i=1;i<=n;i++)
    {
        printf("x[%d]=%0.3f\n",i,x[i]);
    }
    return 0;
}
