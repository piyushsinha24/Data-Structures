#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int LQ[100];
int front =0,rear=-1;

void enqueue(int x)
{
	if(rear==MAX-1)
	{
		printf("Queue is full \n");
		return ;
	}
	LQ[++rear]=x;
}
int dequeue()
{
	int x;
	if(front>rear)
	{
		printf("Queue is empty \n");
		return 0;
	}
	x=LQ[front++];
	return x;
}
void display()
{
	int i;
	for(i=front;i<=rear;i++)
		{
			printf("%d\n",LQ[i]);
		}
}
int main()
{
	int ch,x;
	while(1)
	{
		printf("\nPress 1 to insert elements in queue");
		printf("\nPress 2 to delete elements in queue");
		printf("\nPress 3 to display");
		printf("\nPress 4 to exit : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nenter new element");
					scanf("%d",&x);
					enqueue(x);
					break;
			case 2: dequeue();
					break;
			case 3: display();
					break;
			case 4: exit(0);
		}
	}
	return 0;
}
