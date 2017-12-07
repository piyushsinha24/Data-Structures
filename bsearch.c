#include<stdio.h>
int bsearch(int a[],int n,int x)
{
	int l=0,u=n-1,mid;
	while(l<=u)
	{
		mid=(l+u)/2;
		if(a[mid]==x)
			return(mid);
		else if(x>a[mid])
			l=mid+1;
		else
			u=mid-1;
	}
	return (-1);
}

int main()
{
	int i,n,x;
	printf("enter n\n");
	scanf("%d",&n);
	printf("enter element u wanna search\n");
	scanf("%d",&x);
	int a[n];
	printf("enter the elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int res=bsearch(a,n,x);
	if(res==-1)
		printf("search unsuccessful\n");
	else
		printf("%d found at %d index\n",x,res);
	return 0;
}
	
	
