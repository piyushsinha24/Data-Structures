#include<stdio.h>
#include<stdlib.h>
typedef struct link
{
	int data;
	struct link *next;
}node;
node* top=NULL;
void push(int x)
{
	node* new1;
	new1=(node*)malloc(sizeof(node));
	if(new1==NULL)
	{
		printf("overflow");
		return;
	}
	new1->data=x;
	new1->next=top;
	top=new1;
}
int pop()
{
	int x;
	node*temp;
	if(top==NULL){
		printf("underflow");
		return 0;
	}
	temp=top;
	top=top->next;
	x=temp->data;
	free(temp);
	return x;
}
void DisplaySingleLinkedList()
{	
	node*l=top;
	if(l==NULL)
	{
		printf("stack underflow");
		return;
	}
	printf("stacks :\n");
	while(l->next!=NULL)
	{
		printf("\n%d ",l->data);
		l=l->next;
	}
	printf("\n%d ",l->data);
}
	
int main()
{
	int ans,x;
	node *h;
	h=(node*)malloc(sizeof(node));
	while(1)
	{
		printf("What you wanna do \n");	
		printf("Press 1 to insert elements\n");
		printf("Press 2 to delete elements\n");
		printf("Press 3 to display\n");
		printf("Press 4 to exit\n");
		scanf("%i",&ans);
		switch(ans)
		{
			case 1:
				printf("Enter the value :");
				scanf("%i",&x);
				push(x);

				break;
			case 2:
				x=pop();
				break;
			case 3:
				DisplaySingleLinkedList();
				break;
			case 4:
				exit(0);
		}
	}
	return 0;
}
			
	


