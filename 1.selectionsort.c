#include<stdio.h>
void swap(int *xp,int *yp)
{
	int temp=*xp;
	*xp=*yp;
	*yp=temp;
}
void selectionsort(int arr[],int n)
{
	int i,j,min_idx,k,flag=0;
	for(i=0;i<n-1;i++)
	{
		flag=0;
		min_idx=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min_idx])
			{
				min_idx=j;
			}
		}
		swap(&arr[min_idx],&arr[i]);
		flag=1;
		if(flag==1)
		{
			printf("%dth iteration",i+1);
			for(k=0;k<n;k++)
				printf("%5d\t",arr[k]);
		}
		printf("\n");
	}
}
int print(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
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
	selectionsort(arr,n);
	printf("sorted array: ");
	print(arr,n);
	printf("\n");
	return 0;
}
