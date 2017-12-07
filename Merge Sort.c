#include<stdio.h>
#include<stdlib.h>
void merge(int a[],int min,int mid,int max)
{
	int t[10],i,j,k,m;
	j=min;
	m=mid+1;
	for(i=min;j<=mid&&m<=max;i++)
	{
		if(a[j]<=a[m])
		{
			t[i]=a[j];
			j++;
		}
		else
		{
			t[i]=a[m];
			m++;
		}
	}
	if(j>mid)
	{
		for(k=m;k<=max;k++)
			t[i++]=a[k];
	}
	else
	{
		for(k=j;k<=mid;k++)
			t[i++]=a[k];
	}
	for(k=min;k<=max;k++)
		a[k]=t[k];
}
void mergesort(int a[],int min,int max)
{
	if(min<max)
	{
		int mid=(min+max)/2;
		mergesort(a,min,mid);
		mergesort(a,mid+1,max);
		merge(a,min,mid,max);
	}
}
void print1(int a[],int n)
{
	int i;
	printf("\nArray : ");
	for(i=0;i<n;i++)
		printf("%4d",a[i]);
}
int main()
{
	int n,a[100],x,i;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    printf("Enter the elements : ");
    for(i=0;i<n;i++)
	{
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);
    print1(a,n);
}

