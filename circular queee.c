#include<stdio.h>
int main()
{
int a[50],b[50],i,j,temp,n,m;
printf("enter the size of the array:");
scanf("%d",&n);
printf("enter the first array elements:");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
for(i=0;i<n-1;i++)
{
for(j=j+1;j<n;j++)
{
if(a[i]>a[j])
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}
printf("sorted first array:")
for(i=0;i<n;i++)
{
printf("%d",a[i]);
}
printf(" \n enter the size of the second array:");
scanf("%d",&m);
printf("enter the second array elements:");
for(i=0;i<m;i++)
{
scanf("%d",&b[i]);
}
for(i=0;i<m-1;i++)
{
for(j=j+1;j<m;j++)
{
if(b[i]>b[j])
{
temp=b[i];
b[i]=b[j];
b[j]=temp;
}
}
}
printf("sorted second array:")
for(i=0;i<m;i++)
printf("sorted array");
for(i=0;i<n;i++)
{
printf("%d",b[i]);
}
}
