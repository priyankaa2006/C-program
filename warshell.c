#include<stdio.h>
#include<conio.h>int
a[10][10];
void main()
{
intj,k,n;
clrscr();
printf("enter the number of vertice\n");
scanf("%d",&n);
printf("enter the adjacency matrix");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d",&a[i][j]);
for(k=1;k<=n;k++)
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
a[i][j]=a[i][j] || a[i][k] && a[k][j]; printf("\n
the transitive closure is\n");for(i=1;i<=n;i++)
{
}
}
getch();
