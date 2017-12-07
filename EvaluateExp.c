#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int top=-1;
float stack[MAX];
float power(float a,float b)
{
    if(b==0)return 1;
    else return (a*power(a,b-1));
}
void push(float n)
{
    if(top==MAX-1){
        printf("Stack Overflow .");
        return ;
    }
    stack[++top]=n;
}

float pop()
{
    if(top==-1){
        printf(" Stack Underflow.");
        return -1;
    }
    float x=stack[top--];
    return x;
}


float evaluateExp(char postfix[],float v[])
{
    int i=0;
    char ch;
    float op1,op2,r;
    while(postfix[i]!='\0'){
        ch = postfix[i];
        if((ch>=65&&ch<=90)||(ch>=97&&ch<=122)){
            push(v[i]);
        }
        else{
            op2=pop();
            op1=pop();
            
            switch(ch){
            
                case '^' : r=power(op1,op2);
                           push(r);
                           break;
                           
                case '/' : r=op1/op2;
                           push(r);
                           break;
                           
                case '*' : r=op1*op2;
                           push(r);
                           break;
                           
                case '+' : r=op1+op2;
                           push(r);
                           break;
                           
                case '-' : r=op1-op2;
                           push(r);
                           break;
                           
                default  : printf(" Operator Not Present.\n");
                           break;
                           
            }
        } 
        i++;
    }
    r=pop();
    return r;
    
}

int main()
{
    char postfix[100],ch;
    int t,i,j=0;
    float v[100],res;
    printf(" Enter no. of test cases :");
    scanf("%d",&t);
    for(i=0;i<t;i++){
        printf("\n Enter a valid Postfix Expression :\n");
        scanf("%s",&postfix);
        while(postfix[j]!='\0'){
            ch = postfix[j];
            if((ch>=65&&ch<=90)||(ch>=97&&ch<=122)){
                printf(" Enter the value of %c :",ch);
                scanf("%f",&v[j]);
            }
            j++;
        }
        res=evaluateExp(postfix,v);
        printf(" \n Result of the Postfix Expression :\n%f",res);
    }
    return 0;
}
    
         
