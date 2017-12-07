#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node *next;	
}node;
void createCLL(node *);
void displayCLL(node *);
node* deleteFront(node*);
void deleteEnd(node*);
node* deletePos(node*);
int main()
{
	int x,y;
	node *h=(node*)malloc(sizeof(node));
	while(1)
	{
		printf("\nPress 1 to create a Circular Linked List");
		printf("\nPress 2 to display the Circular Linked List");
		printf("\nPress 3 to delete");
		printf("\nPress 4 to exit : ");
		scanf("%d",&x);
		switch(x)
		{
			case 1: createCLL(h);
					break;
			case 2: displayCLL(h);
					break;
			case 3: printf("Press 1 to delete at start.\n");
					printf("Press 2 to delete at end.\n");
					printf("Press 3 to delete at different position. \n");
					printf("Press 4 to go to the previous menu.\n");
					scanf("%d",&y);
					switch(y)
					{
						case 1: h=deleteFront(h);
								break;
						case 2: deleteEnd(h);
								break;
						case 3: h=deletePos(h);
								break;
						case 4: break;
					}
					break;
			case 4: exit(0);
		}
	}
	return 0;
}
void createCLL(node *h)
{
	node *l=h;
	int ch;
	while(1)
	{
		printf("\nEnter data : ");
		scanf("%d",&l->data);
		printf("\nAnother node(0/1)");
		scanf("%d",&ch);
		if(ch==0)
		{
			l->next=h;
			break;
		}
		l->next=(node*)malloc(sizeof(node));
		l=l->next;
	}
}
void displayCLL(node *l)
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
node* deleteFront(node *l)
{
	
	node*h=l;
	node*temp=h;
	while(l->next!=h)
		l=l->next;
		h=h->next;
		l->next=h;
		free(temp);
		return h;
}
void deleteEnd(node *l)
{
	node*h=l;
	while(l->next->next!=h)
		l=l->next;
	l->next=h;
}
node* deletePos(node *l)
{
	node*h=l;
	int v;
	printf("Enter the data value of a node where the node is to be deleted : ");
	scanf("%d",&v);
		
	while(l->next->data!=v)
			l=l->next;
			node* temp=l->next;
			l->next=l->next->next;
			temp->next=NULL;
		free(temp);
		return(h);
}


