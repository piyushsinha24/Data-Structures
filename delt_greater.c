#include<stdio.h>
#include<stdlib.h>
typedef struct link{
	int data;
	struct link *next;
}node;

void createSingleLinkList(node*);
void displaySingleLinkList(node*);
node* delete(node* ,int);
void deletionlast(node *);
node* deletionbeg(node *);
void deletionanypos(node* );
int main()
{
	int q,value;
	node *h;
	h = (node*)malloc(sizeof(node));
	
	while(1)
	{
		printf("press 1 to create\n2 to display\n3 to delete\n4 to exit\n");
		scanf("%d", &q);
		switch(q){
			case 1:	createSingleLinkList(h);
					break;
			case 2: displaySingleLinkList(h);
					break;
			case 3: printf("enter the value whose greater ones u wanna delete\n");
			        scanf("%d",&value);
				h=delete(h,value);
					break;
			case 4: exit(0);
											
		}
	}
	return 0;
}
void createSingleLinkList(node *l)
{
	int x;
	while(1)
	{
		printf("Enter the data\n");
		scanf("%d", &l->data);
		printf("another node press 1 else 0 \n");
		scanf("%d", &x);
		if(x == 0){
		l->next = NULL;
		break;
		}
		l->next = (node*)malloc(sizeof(node));
		l = l->next;
		
	}
}
void displaySingleLinkList(node*l)
{
	while(l->next != NULL)
	{
		printf("%d ", l->data);
		l = l->next;
	}
	printf("%d ", l->data);
	
}

node* delete(node* l,int value)
{
	node*h=l;
	while(l->next!=NULL)
	{
		if(l->data > value)
		{
			if(l==h)
				l=deletionbeg(h);
			else if(l->next==NULL)
				deletionlast(h);
			else 
				deletionanypos(l);
		}
		l=l->next;
	}
}
node* deletionbeg(node *l)
	{
		node * temp;
		temp=(node*)malloc(sizeof(node));
		l=temp;
		l=l->next;
		temp->next=NULL;
		free(temp);
		return (l);
	}
void deletionlast(node *l)
	{
		node* temp;
		temp=(node*)malloc(sizeof(node));
		while(l->next->next!=NULL)
		{
			l=l->next;
		}
		temp=l->next;
		l->next=NULL;
		free(temp);
	}
void deletionanypos(node* l)
{
	
	node* temp;
	temp=(node*)malloc(sizeof(node));
	temp=l->next;
	l->next=l->next->next;
	temp->next=NULL;
	free(temp);
}
			
	
		
	

