#include<stdio.h>
#include<stdlib.h>
typedef struct link{
    int coef;
    int exp;
    struct link *next;
    
}node;

void createPoly(node *h)
{
    node *l=h;
    int x;
    while(1)
    {
        printf(" Enter the coefficient :");
        scanf("%d",&l->coef);
        printf(" Enter the exponent :");
        scanf("%d",&l->exp);
        printf("add another terms ?(0/1):");
        scanf("%d",&x);
        if(x==0){
            l->next=NULL;
            break;
        }
        l->next = (node*)malloc(sizeof(node));
        l=l->next;
    }
}

void displayPoly(node *h)
{
    printf(" Polynomial are :");
    while(h!=NULL){
        printf("%dx^%d->\n",h->coef,h->exp);
        h=h->next;
    }
    printf("\n");
}

node* addPolys(node *h1,node *h2)
{
    node *p1=h1,*p2=h2,*p3,*poly3;
    poly3=(node*)malloc(sizeof(node));
    p3=poly3;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->exp==p2->exp)
        {
            p3->coef=p1->coef+p2->coef;
            p3->exp=p1->exp;
            p1=p1->next;
            p2=p2->next;
            
        }
        else if(p1->exp>p2->exp)
        {
            p3->coef=p1->coef;
            p3->exp=p1->exp;
            p1=p1->next;
                        
        }
        else{
            p3->coef=p2->coef;
            p3->exp=p2->exp;
            p2=p2->next;
        }
        p3->next=(node*)malloc(sizeof(node));
        p3=p3->next;
     }
     
     while(p1!=NULL)
     {
        p3->coef=p1->coef;
        p3->exp=p1->exp;
        p1=p1->next;
        p3->next=(node*)malloc(sizeof(node));
        p3=p3->next;
     }
     while(p2!=NULL)
     {
        p3->coef=p2->coef;
        p3->exp=p2->exp;
        p2=p2->next;
        p3->next=(node*)malloc(sizeof(node));
        p3=p3->next;
     }
     p3->next=NULL;   
     return poly3;
}
            
void main()
{
    int x,y;
    node *h =(node*)malloc(sizeof(node));
    node *h1 =(node*)malloc(sizeof(node));
    node *h2 =(node*)malloc(sizeof(node));
    node *h3;
    while(1)
    {
        printf("********* POLYNOMIALS*********\n");
        printf(" 1. Create a Polynomial term .\n");
        printf(" 2. Display Polynomial Terms .\n");
        printf(" 3. Add Polynomial Terms .\n");
        printf(" 4. Exit menu .\n");
        scanf("%d",&x);
        switch(x){
            
            case 1 : createPoly(h);
                     break;
                     
            case 2 : displayPoly(h);
                     break;
                     
            case 3 : printf(" 1st Poly : \n");
                     createPoly(h1);
                     printf(" 2nd Poly : \n");
                     createPoly(h2);
                     h3=addPolys(h1,h2);
                     printf(" After adding :\n");
                     displayPoly(h3);         
                     break;
                     
            case 4 : exit(0);
            
            default : printf(" Wrong input .");
                      break;
                      
        }
    
    }
}
