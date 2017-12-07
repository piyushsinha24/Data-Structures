#include<stdio.h>
int insertion(int arr[],int n)
{
	int i,j,k=0,s,flag=0;
	for(i=0;i<n;i++)
	{
		flag=0;
		k=arr[i];
		j=i-1;
			while(j >= 0 && arr[j]>k)
			{
				arr[j+1]=arr[j];
				j=j-1;
			}
		arr[j+1]=k;
		flag=1;
		if(flag==1)
		{
			printf("%dth iteration",i+1);
			for(s=0;s<n;s++)
				printf("%5d\t",arr[s]);
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
	int i,n,arr[50];
	printf("enter the size of the array");
	scanf("%d",&n);
	printf("enter the values");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	insertion(arr,n);
	printf("sorted array: ");
	print(arr,n);
	printf("\n");
	return 0;
}
		
