#include<stdio.h>
#include<stdlib.h>
typedef struct link
{
	int data;
	struct link *next;
}node;
void CreateCircularLinkedList(node*);
void DisplayCircularLinkedList(node*);
void mergeCLL(node*,node*);
int main()
{
	int x,y;
	node *h1;
	h1=(node*)malloc(sizeof(node));
	node *h2;
	h2=(node*)malloc(sizeof(node));
	while(1)
	{
		printf("\n press 1 to create CLL1");
		printf("\n press 2 to create CLL2");
		printf("\n press 3 to display CLL1");
		printf("\n press 4 to display CLL2");
		printf("\n press 5 to merge two CLLs");
		printf("\n press 6 to display merged CLL");
		printf("\n press 7 to exit");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				CreateCircularLinkedList(h1);
				break;
			case 2:
				CreateCircularLinkedList(h2);
				break;
			case 3:
				DisplayCircularLinkedList(h1);
				break;
			case 4:
				DisplayCircularLinkedList(h2);
				break;
			case 5:
				mergeCLL(h1,h2);
				break;
			case 6:
				DisplayCircularLinkedList(h1);
				break;
			case 7:
				exit(0);
		}
		
	}
	return 0;
}
void CreateCircularLinkedList(node*h)
{
	node *l=h;
	int ans;
	while(1)
	{
		printf("\n enter the data:");
		scanf("%d",&l->data);
		printf("\n another node 0/1:");
		scanf("%d",&ans);
		if(ans==0)
		{
			l->next =h;
			break;
		}
		l->next=(node*)malloc(sizeof(node));
		l=l->next;
	}
}
void DisplayCircularLinkedList(node*l)
{
	int ch;
	printf("\nPress 1 to transverse,2 to exit");
	while(1)
	{
		printf("%d ",l->data);
		scanf("%d",&ch);
		if(ch==1)
		l=l->next;
		else 
		break;
	}
	
}
void mergeCLL(node* l1,node* l2)
{
	node* h1=l1;
	node* h2=l2;
	while(l2->next!=h2)
		l2=l2->next;
	l2->next=h1;
	while(l1->next!=h1)
		l1=l1->next;
	l1->next=h2;
	//return(h1);
}
	
	
	

	
