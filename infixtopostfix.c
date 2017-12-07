#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int top=-1;
char stack[MAX];
int precedence(char c)
{
    if(c=='^'||c=='$'){
        return 5;
    }
    else if(c=='/'){
        return 4;
    }
    else if(c=='*'){
        return 3;
    }
    else if(c=='+'){
        return 2;
    }
    else if(c=='-'){
        return 1;
    }
    else{
        return 0;
    }
}

void push(char n)
{
    if(top==MAX-1){
        printf("Stack Overflow .");
        return ;
    }
    stack[++top]=n;
}

char pop()
{
    if(top==-1){
        printf(" Stack Underflow.");
        return -1;
    }
    char x=stack[top--];
    return x;
}

0

void conversion(char infix[])
{
    char postfix[100],ch,temp;
    int i=0,peek1,j=0;
    while(infix[i]!='\0'){
        ch = infix[i]; 
        switch(ch){
            
            case '(' : push(ch);
                       break;
                       
            case '^' :
            case '$' :
            case '/' :
            case '*' :
            case '+' : 
            case '-' :  
                        while(precedence(stack[top])>=precedence(ch)){
                            postfix[j++]=pop();
                        }
                        push(ch);
                        break;
                        
            case ')' :  temp=pop();
                        while(temp!='('){
                            postfix[j++]=temp;
                            temp=pop();
                        }
                        break;
                        
            default :   postfix[j++]=ch;
                        break;
                      
        } 
        i++;
    }
	while(top!=-1)
	postfix[j++]=pop();
    postfix[j++]='\0';
    printf("Your Postfix Expression is :%s",postfix);
}
void main()

{
    char infix[100],postfix[100];
    system("clear");
    int x,i;
    printf("\n Enter no. of test cases :\n");
    scanf("%d",&x);
    for(i=0;i<x;i++){
        printf("\n Enter the infix expression :\n");
        scanf("\n%s",infix);
        conversion(infix);
    }
    //postfix[]=conversion(infix);
    //printf("Your Postfix Expression :\n%s",postfix);
}
         
            
                                               
                       
                       























































