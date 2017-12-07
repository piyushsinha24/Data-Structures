#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct stack
{
	int st[MAX];
	int top;
};
struct stack stack;
int top=-1;

void push(int);
int pop();
void display();
int isFull();
int isEmpty();

void main()
{
	int ch,a,x;
	while(1)
	{	
		printf("\n ENTER 1 TO PUSH \n ENTER 2 TO POP \n ENTER 3 TO DISPlAY \n ENTER 4 TO EXIT");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("ENTER THE VALUE TO BE PUSHED");
					scanf("%d",&x);
					push(x);				
					break;
			case 2: a=pop();
					printf("\n %d",stack.st[stack.top]);				
					break;
			case 3: display();
					break;
			case 4: exit(0);
		}
	}
}

void push(int v)
{
	if(isFull())
	{
		printf("Stack is Full");		
		return;
	}
	else
		{
			stack.st[++stack.top]=v;
			return;
		}
}

int pop()
{
	int x;	
	if(isEmpty())
	{
		printf("The stack is Empty");
		return 0;
	}
	else	
		x=stack.st[stack.top--];
	return (x);
}

int isFull()
{
	if(stack.top==MAX)
		return 1;
	else
		return 0;
}

int isEmpty()
{
	if(stack.top==-1)
		return 1;
	else
		return 0;
}

void display()
{
	int i;	
	if(isEmpty())
	{
		printf("\n THE STACK IS EMPTY");
		return;
	}	
	else
	{
		for(i=stack.top;i>0;i--)
			printf("%d\n",stack.st[i]);
	}
}





