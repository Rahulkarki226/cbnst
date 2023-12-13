#include<stdio.h>
#include<conio.h>
int main()
{
	 float x[10], y[10], xp, yp=0, p;
	 int i,j,n;
	 printf("Enter number of data: ");
	 scanf("%d", &n);
	 printf("Enter points:\n");
	 for(i=1;i<=n;i++)
	 {
    	scanf("%f%f",&x[i], &y[i]);
	 }
	 printf("Enter interpolation point: ");
	 scanf("%f", &xp);
	 for(i=1;i<=n;i++)
	 {
		  p=1;
		  for(j=1;j<=n;j++)
		  {
			   if(i!=j)
			   {
			    	p = p* (xp - x[j])/(x[i] - x[j]);
			   }
		  }
		  yp = yp + p * y[i];
	 }
	 printf("Interpolated value at %.3f is %.3f.", xp, yp);
	 getch();
}