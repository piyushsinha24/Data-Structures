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
node* deleteFront(node *);
void deleteEnd(node *);
void deletePos(node *);
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
		printf("\nPress 3 to delete the double Linked List");
		printf("\nPress 4 to exit : ");
		scanf("%d",&x);
		switch(x)
		{
			case 1: createDLL(h);
					break;
			case 2: displayDLL(h);
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
						case 3: deletePos(h);
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
node* deleteFront(node* h)
{
	node *temp=h;
	h=h->next;
	h->prev=NULL;
	free(temp);
	return h;
}
void deleteEnd(node* h)
{
	while(h->next->next!=NULL)
		h=h->next;
	node *temp=h->next;
	h->next=NULL;
	free(temp);
}
void deletePos(node* h)
{
	node *l=h;
    node *t;
    int x;
    printf(" Enter the node to be deleted :");
    scanf("%d",&x);
    while(l->next->data!=x){
        l=l->next;
    }
    t=l->next;
    l->next=t->next;
    l->next->prev=l;
    t->next=t->prev=NULL;
    free(t);
}

