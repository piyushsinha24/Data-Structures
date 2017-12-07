#include<stdio.h>
void swap(int *xp,int *yp)
{
	int temp=*xp;
	*xp=*yp;
	*yp=temp;
}
void bubble(int arr[10],int n)
{
	int i,j,k,flag=0;
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
				flag=1;
			}
				printf("\n");
		}
		if(flag==1)
		{
			printf("%dth iteration",i+1);
			for(k=0;k<n;k++)
				printf("%5d\t",arr[k]);
		}
		if (flag==0)
			break;
		printf("\n");
	}
}
void print (int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%5d\t",arr[i]);
	printf("\n");
}
int main()
{
	int i,n,arr[100];
	printf("enter the size of the array");
	scanf("%d",&n);
	printf("enter the values");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	bubble(arr,n);
	printf("sorted array");
	print(arr,n);
	return 0;
}
	
	
	
	
	
