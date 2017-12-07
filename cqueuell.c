#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node *next;	
}node;
node *front=NULL;
node *rear=NULL;
void enQueue(int x)
{
	node *n1;
	n1=(node*)malloc(sizeof(node));
	n1->data=x;
	if(rear==NULL)
	{
		front=rear=n1;
		return;
	}    
	rear->next=n1;
	n1->next=front;
	rear=rear->next;
}
int deQueue()
{
    int x;
	node *temp;
	if(front==NULL)
	{
		printf("\nQueue is empty");
		return(0);
	}
	temp=front;
	front=front->next;
	rear->next=front;
	x=temp->data;
	temp->next=NULL;
	free(temp);
	return(x);
}
void display(node *l)
{
	int ch;
	printf("\nPress 1 to traverse, 2 to exit");
	while(1)
	{
		printf(" %d ",l->data);
		scanf("%d",&ch);
		if(ch==1)
			l=l->next;
		else
			break;
	}
}
int main()
{
    int x,i,del,t;
    printf("\n***** Circular Queue *****\n");
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
                       enQueue(t);
                       break;
                       
            case  2  : del=deQueue();
                       printf("\nDeleted Element :%d",del);
                       break;
                       
            case  3  : display(front);
                       break;
                       
            case  4  : exit(0);
            
            default  : printf("\n Wrong Input . Try Again.");           
                       break;
                       
        }
    }
} 
