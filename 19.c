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
    
    float a=x[1],b=x[2],c=x[3];
    printf("Equation: y= %.2f + %.2fx + %.2fx^2\n", a, b,c);

}
int main()
{
    int n;
    float sumx=0,sumx2=0,sumx3=0,sumx4=0,sumy=0,sumxy=0,sumx2y=0;
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
        sumx2+=x[i]*x[i];
        sumx3+=x[i]*x[i]*x[i];
        sumx4+=x[i]*x[i]*x[i]*x[i];
        sumy+=y[i];
        sumxy+=x[i]*y[i];
        sumx2y+=x[i]*x[i]*y[i];
    }

    table[1][1]=n,table[1][2]=sumx,table[1][3]=sumx2,table[1][4]=sumy;
    table[2][1]=sumx,table[2][2]=sumx2,table[2][3]=sumx3,table[2][4]=sumxy;
    table[3][1]=sumx2,table[3][2]=sumx3,table[3][3]=sumx4,table[3][4]=sumx2y;
    gaussjordon(table,3);
    return 0;
}
