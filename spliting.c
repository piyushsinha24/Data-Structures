#include<stdio.h>
#include<stdlib.h>
typedef struct link {
    int data;
    struct link *next;
    }node;
    
node* findNode(node*l , int v)
{
    while(l->data!=v&&l!=NULL){
        l=l->next;
    }
    return l;
}
    
void createSingleLinkList(node *h)
{   
    int c;
    node *l;
    //h=(node*)malloc(sizeof(node));
    l=h;
    while(1){
        printf(" Enter the node :\n");
        scanf("%d",&l->data);
        //l=l->next;
        printf(" add another node ?(1/0) :\n");
        scanf("%d",&c);
        if(c==0){
            l->next=NULL;
            break;
        }
        l->next =(node*)malloc(sizeof(node));
        l=l->next; 
   }
   //return h;
}

void displaySingleLinkList(node *l)
{
    if(l==NULL){
        printf(" List is empty .");
    } 
    printf("\n YOUR LINK LIST :\n");
    while(l->next!=NULL){
        printf("%4d",l->data);
        l=l->next;
    }
    printf("%4d",l->data);
    
}

node* delAtFirst(node* h)
{
    node* temp;
    if(h==NULL){
        printf(" List is empty .");
    }
    else{
        temp = h;
        h=h->next;
        free(temp);
    }
    return h;
}

void delNode(node *h)
{
    int x;
    node *l=h;
    node *temp,*res,*t;
    printf(" Enter the node data to be deleted :");
    scanf("%d",&x);
    res=findNode(l,x);
    if(res==NULL)
        printf(" ELEMENT NOT PRESENT .");
      
    if(h->next->data==x){
        t=h;
        h=h->next;
        free(t);
        l=h;
    }    
    
    while(l->next->data!=x){
        l=l->next;
    }
    temp=l->next;
    l->next = temp->next;
    temp->next = NULL;
    free(temp);
    //return l;
} 
node* reverse(node *h)
{
    node *c,*p;//c=current , p=previous
    p=NULL;
    c=h;
    if(h==NULL)
        printf(" List is empty .");
    while(h!=NULL){
        h=h->next;
        c->next=p;
        p=c;
        c=h;
    }
    return p;
}

node* mergeTwoList (node *h1,node *h2)
{
    node *l1=h1;
    node *l2=h2;
    while(l1->next!=NULL){
        l1=l1->next;
    }
    l1->next = l2;
    return h1;
    
}   

void splitListInEqualRatio(node *h)
{
    int sum =0;
    node *l=h;
    node *h1=h;
    node *h2;
    while(l!=NULL){
        sum++;
        l=l->next;
    }
    int s1 =1;
    while(s1<(sum/2))
    {
        h1=h1->next;
        s1++;
    }
    h2=h1->next;
    h1->next = NULL;
    //printf(" First list :\n");
    displaySingleLinkList(h);
    //printf(" Second list :\n");
    displaySingleLinkList(h2);
       
} 
             
void main()
{
    int ch;
    int x;
    node *h,*l;
    h=(node*)malloc(sizeof(node));
    l=(node*)malloc(sizeof(node));
    while(1){
        printf(" \nSINGLE LINKLIST : \n");
        printf(" ....................\n\n");
        printf(" 1. Create a single linklist .\n");
        printf(" 2. Delete a node.\n");
        printf(" 3. Delete a specific node.\n");
        printf(" 4. Reverse a Sll.\n");
        printf(" 5. Merge two lists .\n");
        printf(" 6. Splitting List in equal ratios .\n");
        printf(" 7. Display the single Linklist.\n");
        printf(" 8. Exit node .\n");
        scanf("%d",&x);
        switch(x){
            
            case  1 : createSingleLinkList(h);
                      break;
                      
            case  2 : h=delAtFirst(h);
                      break;
                      
            case  3 :  delNode(h);
                      break;
                                 
            case  4 : h = reverse(h);
                      break;
                      
            case  5 : printf(" Enter the 1st linklist :\n");
                      createSingleLinkList(h);
                      printf(" Enter the 2nd LinkList :\n");
                      createSingleLinkList(l);
                      h= mergeTwoList(h,l);
                      printf(" Your LinkList After merging :\n");
                      displaySingleLinkList(h);
                      break; 
            case  6 : splitListInEqualRatio(h);
                      break;
                                      
            case  7: displaySingleLinkList(h);
                      break;
                      
            case  8 : exit(0);
            
            default : printf(" Wrong input .");
            
        }
    }
}    
