#include<stdio.h>
#include<stdlib.h>

struct node{
    int co,po;
    struct node * next;

}s;

struct node* getnode(int co,int po){
    struct node* temp=(struct node *)malloc(sizeof(struct node));
    temp->co=co;
    temp->po=po;
    temp->next=NULL;

    return temp;
}

void insertend(struct node** root,int co,int po){
    struct node *temp=getnode(co,po);
    if(*root==NULL){
        *root=temp;
        return;
    }
    struct node* p;
    p=*root;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=temp;
}

struct node * addterm(struct node *res,int co,int po){
    struct node *p,* temp=getnode(co,po);
    p=res;
    int flag=0;
    if(res==NULL){
        return temp;
    }
    while(p!=NULL){
        if(p->po==po){
            p->co=p->co+co;
            flag=1;
        }
        p=p->next;
    }

    if(flag==0){
        p=res;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=temp;
    }   
    return res;
}

struct node* multiply(struct node *poly1,struct node* poly2){
    struct node *p,*q,*res=NULL;

    for(p=poly1;p!=NULL;p=p->next){
        for(q=poly2;q!=NULL;q=q->next){
                res=addterm(res,(p->co)*(q->co),(p->po)+(q->po));
        }
    }
    return res;
}

void display(struct node* head){
    if(head==NULL){
        printf("Empty list\n");
        return ;

    }
    struct node* p;
    p=head;
    while(p->next!=NULL){
        printf("%dX^%d+",p->co,p->po);
        p=p->next;
    }
    printf("%dX^%d",p->co,p->po);
}

int main(){
    struct node *poly1=NULL,*poly2=NULL,*res=NULL;
    int n1,n2,co,po;
    printf("Enter the terms in polynomial 1\n");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++){
        printf("Enter the coefficient:");
        scanf("%d",&co);
        printf("Enter the exponent:");
        scanf("%d",&po);
        insertend(&poly1,co,po);
    }

    printf("Enter the terms in polynomial 1\n");
    scanf("%d",&n2);
    for(int i=0;i<n2;i++){
        printf("Enter the coefficient:");
        scanf("%d",&co);
        printf("Enter the exponent:");
        scanf("%d",&po);
        insertend(&poly2,co,po);
    }

    res=multiply(poly1,poly2);

    printf("First polynomial:");
    display(poly1);
    printf("Second polynomial:");
    display(poly2);

    printf("Result:");
    display(res);

    return 0;
}