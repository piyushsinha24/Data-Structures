#include<stdio.h>
#include<stdlib.h>
typedef struct link
{
	int data;
	struct link *next;
}node;
node *front=NULL;
node *rear=NULL;

void enqueue(int x)
{
	node *new1;
	new1=(node*)malloc(sizeof(node));
	new1->data=x;
	if(rear==NULL)
	{	
		front=rear=new1;
		return ;
	}
	rear->next=new1;
	new1->next=NULL;
	rear=rear->next;
}
int dequeue()
{
	int x;
	node *temp;
	if(front==NULL)
	{
		printf("Queue is empty \n");
		return 0;
	}
	temp=front;
	front=front->next;
	x=temp->data;
	temp->next=NULL;
	free(temp);
	return x;
}
void display(node *l)
{
	while(l->next!=NULL)
	{
		printf("%d\n",l->data);
		l=l->next;
	}
	printf("%d\n",l->data);
}

int main()
{
	int ch,x,delt;
	while(1)
	{
		printf("\nPress 1 to insert elements in queue");
		printf("\nPress 2 to delete elements in queue");
		printf("\nPress 3 to display");
		printf("\nPress 4 to exit : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nenter new element");
					scanf("%d",&x);
					enqueue(x);
					break;
			case 2: delt=dequeue();
					printf("deleted element is: %d",delt);
					break;
			case 3: display(front);
					break;
			case 4: exit(0);
		}
	}
	return 0;
}
