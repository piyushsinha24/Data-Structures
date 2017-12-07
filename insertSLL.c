#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node *next;	
}node;
void createSingleLinkedList(node*);
void displaySingleLinkedList(node*);
node* insertFront(node*);
void insertEnd(node*);
node* insertPos(node*);
node* findNode(node *,int);
int main()
{
	int x,y;
	node *h=(node*)malloc(sizeof(node));
	while(1)
	{
		printf("\nPress 1 to create a Single Linked List");
		printf("\nPress 2 to display the Single Linked List");
		printf("\nPress 3 to insert");
		printf("\nPress 4 to exit : ");
		scanf("%d",&x);
		switch(x)
		{
			case 1: createSingleLinkedList(h);
					break;
			case 2: displaySingleLinkedList(h);
					break;
			case 3: printf("Press 1 to insert at start.\n");
					printf("Press 2 to insert at end.\n");
					printf("Press 3 to insert at different position. \n");
					printf("Press 4 to go to the previous menu.\n");
					scanf("%d",&y);
					switch(y)
					{
						case 1: h=insertFront(h);
								break;
						case 2: insertEnd(h);
								break;
						case 3: h=insertPos(h);
								break;
						case 4: break;
					}
					break;
			case 4: exit(0);
		}
	}
	return 0;
}
void createSingleLinkedList(node *l)
{
	int ans;
	while(1)
	{
		printf("\nEnter data : ");
		scanf("%d",&l->data);
		printf("\nAnother node(0/1) : ");
		scanf("%d",&ans);
		if(ans==0)
		{
			l->next=NULL;
			break;
		}
		l->next=(node*)malloc(sizeof(node));
		l=l->next;
	}
}
void displaySingleLinkedList(node *l)
{
	while(l->next!=NULL)
	{
		printf("%d ",l->data);
		l=l->next;
	}
	printf("%d",l->data);
}
node* insertFront(node *l)
{
	node* new1;
	new1=(node*)malloc(sizeof(node));
	printf("Enter data for the new node : ");
	scanf("%d",&new1->data);
	new1->next=l;
	return(new1);
}
void insertEnd(node *l)
{
	while(l->next!=NULL)
		l=l->next;

	node* new1;
	new1=(node*)malloc(sizeof(node));
	printf("Enter data for the new node : ");
	scanf("%d",&new1->data);
	l->next=new1;
	new1->next=NULL;
}
node* insertPos(node *h)
{
	int v;
	node* new1, *l;
	new1=(node*)malloc(sizeof(node));
	printf("Enter data for the new node : ");
	scanf("%d",&new1->data);

	printf("Enter the data value of a node where the node is to be inserted : ");
	scanf("%d",&v);
	l=findNode(h,v);
	if(l==NULL)
		printf("Node not found.");
	else
		{
			new1->next = l->next;
			l->next = new1;
		}
	return(h);
}

node* findNode(node *l,int v)
{
	while(l!=NULL && l->data!=v)
		l=l->next;
	return (l);
}
