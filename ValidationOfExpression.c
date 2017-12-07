#include<stdio.h>
#include<stdlib.h>
void check(char postfix[])
{
    int sum2 =0,sum1=0,i=0;
    char ch;
    while(postfix[i]!='\0'){
        ch=postfix[i];
        if(ch=='{'){
            sum2++;
        }
        i++;
    }
    i=0;
    while(postfix[i]!='\0'){
        ch=postfix[i];
        if(ch=='}'){
            sum1++;
        }
        i++;
    }
    if(sum1==sum2){
        printf(" Expression Valid .");
    }
    else{
        printf(" Expression Not Valid .");
    }
}

void check2(char postfix[])
{
    int sum2 =0,sum1=0,i=0;
    char ch;
    while(postfix[i]!='\0'){
        ch=postfix[i];
        if(ch=='('){
            sum2++;
        }
        i++;
    }
    i=0;
    while(postfix[i]!='\0'){
        ch=postfix[i];
        if(ch==')'){
            sum1++;
        }
        i++;
    }
    if(sum1==sum2){
        printf(" Expression Valid .");
    }
    else{
        printf(" Expression Not Valid .");
    }
}
void check3(char postfix[])
{
    int sum2 =0,sum1=0,i=0;
    char ch;
    while(postfix[i]!='\0'){
        ch=postfix[i];
        if(ch=='['){
            sum2++;
        }
        i++;
    }
    i=0;
    while(postfix[i]!='\0'){
        ch=postfix[i];
        if(ch==']'){
            sum1++;
        }
        i++;
    }
    if(sum1==sum2){
        printf(" Expression Valid .");
        return;
    }
    else{
        printf(" Expression Not Valid .");
        return;
    }
}
   
void main()
{
    char postfix[100],ch;
    int i=0;
    printf(" Enter the postfix Expression :");
    scanf("%s",&postfix);
    while(postfix[i]!='\0'){
        ch=postfix[i];
        switch(ch)
        {
             
            case '{' : check(postfix);
                       break;
                       
            case '[' : check3(postfix);
                       break;
                       
            case '(' : check2(postfix);
                       break;
                       
            default  : break;
            
        }
        i++;
    }                                                  
}    
    
