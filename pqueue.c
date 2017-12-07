#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int front=0;
int rear=-1;
int pq[MAX][2];

void enQueue(int x,int p)
{
    if(rear==(MAX-1)){
        printf("\nQueue Overflow .");
        return;
    }
    ++rear;
	pq[rear][0]=x;
	pq[rear][1]=p;
}
int deQueue()
{
    int i,l,min,x;
    if(front>rear)
	{
        printf("\nQueue is Underflow .");
        return 0;
    }
    min=pq[front][1];
	l=front;
	for(i=front+1;i<=rear;i++)
	{
		if(pq[i][1]<min)
		{
			min=pq[i][1];
			l=i;
		}
	}
	x=pq[l][0];
	for(i=l;i>front;i--)
	{
		pq[i][0]=pq[i-1][0];
		pq[i][1]=pq[i-1][1];
	}
	front++;
	return x;
}
int main()
{
    int x,i,del,t,p;
    printf("\n***** Priority Queue *****\n");
    printf("\n1. Enter the element .");
    printf("\n2. Delete the element.");
    printf("\n3. Display the Queue.");
    printf("\n4. Exit.");
    while(1){
        printf("\n Enter choice :");
        scanf("%d",&x);
        switch(x){
        
            case  1  : printf("\nEnter the element :");
					   scanf("%d",&t);
					   printf("\nEnter the priority :");
					   scanf("%d",&p);
                       enQueue(t,p);
                       break;
                       
            case  2  : del=deQueue();
                       printf("\nDeleted Element :%d",del);
                       break;
                       
            case  3  : printf("\nQueue :");
                       for(i=front;i<=rear;i++){
                           printf("%4d %d",pq[i][0],pq[i][1]);
					   }
                       break;
                       
            case  4  : exit(0);
            
            default  : printf("\n Wrong Input . Try Again.");           
                       break;
                       
        }
    }
}           
