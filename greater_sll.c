#include<stdio.h>
#include<stdlib.h>
typedef struct link{
	int data;
	struct link *next;
}node;

void createSingleLinkList(node*);
void displaySingleLinkList(node*);
void greatest(node*);
void smallest(node*);
int main()
{
	int q;
	node *h;
	h = (node*)malloc(sizeof(node));
	
	while(1)
	{
		printf("press 1 to create\n2 to display\n3 to find greatest\n4 to find smallest\n5 to exit\n");
		scanf("%d", &q);
		switch(q){
			case 1:	createSingleLinkList(h);
					break;
			case 2: displaySingleLinkList(h);
					break;
			case 3: greatest(h);
					break;
			case 4: smallest(h);
					break;
			case 5: exit(0);
											
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
void greatest(node*l)
{
	node* great=(node*)malloc(sizeof(node));
	great=l;
	while(l->next!=NULL)
	{
		l=l->next;
		if(l->data>=great->data)
			great=l;
	}
	printf("greatest: %d\n",great->data);
}
void smallest(node*l)
{
	node* small=(node*)malloc(sizeof(node));
	small=l;
	while(l->next!=NULL)
	{
		l=l->next;
		if(l->data<=small->data)
			small=l;
	}
	printf("smallest: %d\n",small->data);
}
		
