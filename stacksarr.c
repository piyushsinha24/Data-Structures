#include<stdio.h>
#include<stdlib.h>
int push(int value,int top,int stack[])
{	
	if(top==9)
	{
		printf("Stack is full\n");
	}
	else
	{	
		top++;
		stack[top]=value;
		printf("Insertion Success\n");
	}
	return top;
	}
int pop(int top,int stack[])
{
	if(top==-1)
	{
		printf("Stack is Empty\n");
	}
	else
	{
		printf("Deletion success : %i\n",stack[top]);
		top--;
	}
	return top;
}
void display(int top,int stack[])
{
	if(top==-1)
		printf("stack is empty");
	else
	{
		int i;
		printf("stack elements are : \n");
		for(i=top;i>=0;i--)
			printf("%i\n",stack[i]);
	}
}
int main()
{
	int stack[10];
	int top=-1,ans,value;
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
				scanf("%i",&value);
				top=push(value,top,stack);

				break;
			case 2:
				top=pop(top,stack);
				break;
			case 3:
				display(top,stack);
				break;
			case 4:
				exit(0);
		}
	}
	return 0;
}
			

