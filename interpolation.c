#include<stdio.h>
#include<stdlib.h>
int search(int a[],int n,int x)
{
    int lo,hi,pos;
    lo=0,hi=n-1;
    while((lo<=hi)&&a[lo]<=a[hi]){
        pos =lo+(x-a[lo])*(hi-lo)/(a[hi]-a[lo]);
        if(x==a[pos]){
            return pos;
        }
        else if(x>a[pos]){
            lo=pos+1;
        }
        else{
            hi=pos-1;
        }
    }
    return -1;
}

void main()
{
    int a[100],n,i,x,p;
    printf("Enter the size of the array :");
    scanf("%d",&n);
    printf("Enter the elements :");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the Element to be searched :");
    scanf("%d",&x);
    p=search(a,n,x);
    if(p==-1){
        printf("Element Not Found .");
    }
    else{
        printf("Element Found At :%d",p);
    }
}
        
            
    
