#include<stdio.h>
#include<stdlib.h>
typedef struct link
{
	struct link*prev;
	int data;
	struct link*next;
}node;
//h->prev=next;
void createDLL(node *);
void displayDLL(node *);
node* insertFront(node *);
void insertEnd(node *);
void insertPos(node *);
node* findNode(node *,int );
int main()
{
	int x,y;
	node *h=(node*)malloc(sizeof(node));
	//h->prev=next;
	while(1)
	{
		printf("\nPress 1 to create a double Linked List");
		printf("\nPress 2 to display the double Linked List");
		printf("\nPress 3 to insert the double Linked List");
		printf("\nPress 4 to exit : ");
		scanf("%d",&x);
		switch(x)
		{
			case 1: createDLL(h);
					break;
			case 2: displayDLL(h);
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
						case 3: insertPos(h);
								break;
						case 4: break;
					}
					break;
			case 4: exit(0);
		}
	}
	return 0;
}
void createDLL(node *l)
{
	int x;
	while(1)
	{
		printf("\nEnter data : ");
		scanf("%d",&l->data);
		printf("\nAnother node(0/1)");
		scanf("%d",&x);
		if(x==0)
		{
			l->next=NULL;
			break;
		}
		l->next=(node*)malloc(sizeof(node));
		l->next->prev=l;
		l=l->next;
	}
}
void displayDLL(node *l)
{
	int x;
	printf("\nPress 1 ,2,0 for right,transverse & exit");
	while(1)
	{
		printf(" %d ",l->data);
		scanf("%d",&x);
		if(x==1)
		{
			if(l->next==NULL)
			printf("\n last node");
			else
			l=l->next;
		}
		else if(x==2)
		{
			if(l->prev==NULL)
			printf("\n first node");
			else
			l=l->prev;
		}
		else if(x==0)
			break;
	}
}
node* insertFront(node* h)
{
	node* new1;
	new1=(node*)malloc(sizeof(node));
	printf("Enter the data : ");
	scanf("%d",&new1->data);
	h->prev=new1;
	new1->next=h;
	new1->prev=NULL;
	h=new1;
	return h;
}
void insertEnd(node* h)
{
	node* new1;
	new1=(node*)malloc(sizeof(node));
	printf("Enter the data : ");
	scanf("%d",&new1->data);
	while(h->next!=NULL)
		h=h->next;
	h->next=new1;
	new1->prev=h;
	new1->next=NULL;
}
void insertPos(node* h)
{
	int v;
	node* new1,*l;
	new1=(node*)malloc(sizeof(node));
	printf("Enter the data : ");
	scanf("%d",&new1->data);
	printf("Enter the data value of a node where the node is to be inserted : ");
	scanf("%d",&v);
	l=findNode(h,v);
	if(l==NULL)
		printf("Node not found.");
	else
	{
		new1->next=l->next;
		new1->prev=l;
		l->next->prev=new1;
		l->next=new1;
	}
}
node* findNode(node *l,int v)
{
	while(l!=NULL && l->data!=v)
		l=l->next;
	return (l);
}
