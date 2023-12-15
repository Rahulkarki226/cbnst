// Write a program in "C" Language for Linear Curve Fitting

#include<stdio.h>

void gaussjordon(float arr[10][10],int n)
{
    float ratio,x[10];
    for(int i=1;i<=n;i++)
    {
        if(arr[i][i]==0.0)
           {
            printf("Math Error");
            break;
           }
        for(int j=1;j<=n;j++){
            if(i!=j){
                ratio =arr[j][i]/arr[i][i];
                for(int k=1;k<=n+1;k++)
                   arr[j][k]=arr[j][k]-ratio*arr[i][k];
            }
        }
    }
    for(int i=1;i<=n;i++)
        x[i]=arr[i][n+1]/arr[i][i];
    
    float a=x[1],b=x[2];
    printf("Equation: y= %.2f + %.2fx\n", a, b);

}
int main()
{
    int n;
    float sumx=0,sumy=0,sumx2=0,sumxy=0;
    printf("Enter no of points:");
    scanf("%d",&n);
    float x[n],y[n],table[10][10];
    printf("Enter points:\n");
    for(int i=0;i<n;i++)
      {
         scanf("%f%f",&x[i],&y[i]);
      }
    for(int i=0;i<n;i++)
    {
        sumx+=x[i];
        sumy+=y[i];
        sumx2+=x[i]*x[i];
        sumxy+=x[i]*y[i];
    }

    table[1][1]=n,table[1][2]=sumx,table[1][3]=sumy;
    table[2][1]=sumx,table[2][2]=sumx2,table[2][3]=sumxy;

    gaussjordon(table,2);
    return 0;
}
