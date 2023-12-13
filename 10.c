#include<stdio.h>
#include<conio.h>

int main()
{
 float x[20], y[20][20];
 int i,j, n;
 /* Input Section */
 printf("Enter number of data?\n");
 scanf("%d", &n);
 printf("Enter data:\n");
  printf("x\ty\n");
 for(i = 0; i < n ; i++)
 {
  scanf("%f", &x[i]);
  scanf("%f", &y[i][0]);
 }

 /* Generating Forward Difference Table */
 for(i = 1; i < n; i++)
 {
  for(j = 0; j < n-i; j++)
  {
   y[j][i] = y[j+1][i-1] - y[j][i-1];
  }
 }

 /* Displaying Forward Difference Table */
 printf("\nFORWARD DIFFERENCE TABLE\n");
 for(i = 0; i < n; i++)
 {
  printf("%0.2f", x[i]);
  for(j = 0; j < n-i ; j++)
  {
   printf("\t%0.2f", y[i][j]);
  }
  printf("\n");
 }

  float input,u,unew,factorial=1,output;
  printf("Enter x:");
  scanf("%f",&input);
  u=(input-x[0])/(x[1]-x[0]);
  output=y[0][0];
  unew=u;
  for(i=1;i<n;i++)
  {
    output+=(unew*y[0][i])/factorial;
    factorial*=i+1;
    unew=unew*(u-i);
  }
  printf("Value at x=%f is %f",input,output); 
 return 0;
}