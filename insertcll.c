#include<stdio.h>
#include<stdlib.h>
typedef struct link
{
	int data;
	struct link *next;	
}node;
void createCLL(node *);
void displayCLL(node *);
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
		printf("\nPress 1 to create a Circular Linked List");
		printf("\nPress 2 to display the Circular Linked List");
		printf("\nPress 3 to insert");
		printf("\nPress 4 to exit : ");
		scanf("%d",&x);
		switch(x)
		{
			case 1: createCLL(h);
					break;
			case 2: displayCLL(h);
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
node* insertFront(node *l)
{
	node* new1;
	node* h=l;
	new1=(node*)malloc(sizeof(node));
	printf("Enter data for the new node : ");
	scanf("%d",&new1->data);
	new1->next=l;
	while(l->next!=h)
		l=l->next;
	l->next=new1;
	return(new1);
}
void insertEnd(node *l)
{
	node* h=l;
	while(l->next!=h)
		l=l->next;

	node* new1;
	new1=(node*)malloc(sizeof(node));
	printf("Enter data for the new node : ");
	scanf("%d",&new1->data);
	l->next=new1;
	new1->next=h;
	l=new1;
}
node* insertPos(node *l)
{
	int v,x;
	node* new1, *h;
	h=l;
	new1=(node*)malloc(sizeof(node));
	printf("Enter data for the new node : ");
	scanf("%d",&new1->data);

	printf("Enter the data value of a node where the node is to be inserted : ");
	scanf("%d",&v);
	while(l->data!=v)
		l=l->next;	
	new1->next = l->next;
	l->next = new1;
		
	return h;
}



