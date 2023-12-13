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

 /* Generating Backward Difference Table */
 for(i = 1; i < n; i++)
 {
  for(j = n-1; j > i-1; j--)
  {
   y[j][i] = y[j][i-1] - y[j-1][i-1];
  }
 }

 /* Displaying Backward Difference Table */
 printf("\nBACKWARD DIFFERENCE TABLE\n\n");
 for(i = 0; i < n; i++)
 {
  printf("%0.2f", x[i]);
  for(j = 0; j <= i ; j++)
  {
   printf("\t%0.2f", y[i][j]);
  }
  printf("\n");
 }
  float input,u,unew,factorial=1,output;
  printf("Enter x:");
  scanf("%f",&input);
  u=(input-x[n-1])/(x[1]-x[0]);
  output=y[n-1][0];
  unew=u;
  for(i=1;i<n;i++)
  {
    output+=(unew*y[n-1][i])/factorial;
    factorial*=i+1;
    unew=unew*(u+i);
  }
  printf("Value at x=%f is %f",input,output); 
 return 0;
}