#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *left,*right;
};
struct node *root=NULL;
struct node *insert(struct node *root,int item)
{
	struct node *temp,*current,*prev;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->left=temp->right=NULL;
	if(root==NULL)
		root=temp;
	else
	{
		prev=current=root;
		while(current!=NULL)
		{	
			prev=current;
			if(item<=current->data)
				current=current->left;
			else
				current=current->right;
		}
		if(item<=prev->data)
			prev->left=temp;
		else
			prev->right=temp;
		return root;
	}
}
void preorder(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d",root->data);		
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d",root->data);
		inorder(root->right);
	}
}
void postorder(struct node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d",root->data);
	}
}


void main()
{
	struct node *root=NULL;
	int item,ch;
	while(1)
	{
		printf("\n1.insert\n2.inorder\n3.preorder\n4.postorder\n5.exit");
		printf("\nenter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter the item:");
				scanf("%d",&item);
				root=insert(root,item);
				break;
			case 2:inorder(root);
					break;
			case 3:preorder(root);
					break;
			case 4:postorder(root);
					break;
			
			case 5:exit(0);
		}
	}
}

