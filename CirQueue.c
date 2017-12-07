#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int cq[MAX];
int rear=-1,front=-1;
void enQueue(int x)
{
    if(front==(rear+1)%MAX){
        printf("Queue OverFlow .");
        return;
    }
    if(front==-1)
        front=0;
    rear=(rear+1)%MAX;
    cq[rear]=x;
}

int deQueue()
{
    int x;
    if(front==-1||rear==-1){
        printf("Queue is Underflow .");
        return -1;
    }
    else if(rear==front){
        x=cq[front];
        rear=front=-1;
    }
    else{
        x=cq[front];
        front=front+1%MAX;
    }
    return x;
}

void display()
{
    printf("\n Circular Queue:");
    int i;
    for(i=front;i<=rear;i++){
        printf("%4d",cq[i]);
    }
}
int main()
{
        int x,i,del,t;
        system("clear");
        printf("\n***** Circular Queue *****\n");
        printf("\n1. Enter the element .");
        printf("\n2. Delete the element.");
        printf("\n3. Display the Queue.");
        printf("\n4. Exit.");
        while(1){
            printf("\n Enter choice :");
            scanf("%d",&x);
            switch(x){
            
                case  1  : printf("\nEnter the element :");
                           scanf("%d",&t);
                           enQueue(t);
                           break;
                           
                case  2  : del=deQueue();
                           printf("\nDeleted Element :%d",del);
                           break;
                           
                case  3  : display();
                           break;
                           
                case  4  : exit(0);
                
                default  : printf("\n Wrong Input . Try Again.");           
                           break;
                           
            }
        }
    }               
