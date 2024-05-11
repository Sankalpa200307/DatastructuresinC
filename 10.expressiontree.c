#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char data;
    struct node * lchild,*rchild;
};

struct stack{
    char a[10];
    int top;
}s;

struct node * getnode(char data){
        struct node * temp;
        temp=(struct node *)malloc(sizeof(struct node));
        temp->lchild=NULL;
        temp->rchild=NULL;
        temp->data=data;
        return temp;
}

void push(char ele){
    s.a[++s.top]=ele;
}

char pop(){
    return s.a[s.top--];
}

int prcd(char op1,char op2){
    switch(op1){
        case '$':
            if(op1=='/'||op2=='*'||op2=='+'||op2=='-')
                return 1;
        case '*':
        case '/':
            if(op1=='/'||op2=='*'||op2=='+'||op2=='-')
                return 1;
        case '+':
        case '-':
            if(op2=='+'||op2=='-')
                return 1;
    }
    return 0;
}

char * postfix(){
    char exp[10],postfix[10],sym;
    s.top=-1;
    int k=0;
    printf("Enter the infix expression:");
    scanf("%s",exp);
    for(int i=0;exp[i]!='\0';i++){
        sym=exp[i];
        if((sym>='A')&&(sym<='Z')||(sym>='a')&&(sym<='z')||(sym>='0')&&(sym<='9')){
            postfix[k++]=sym;
        }
        else{
            while(s.top!=-1 && prcd(s.a[s.top],sym)){
                    postfix[k++]=pop();
            }
            push(sym);
        }
    }
while(s.top!=-1){
    postfix[k++]=pop();
}

postfix[k]='\0';

return strdup(postfix);

}

struct stack1{
    struct node * a[10];
    int top;
}s1;

void push1(struct node * tree){
    s1.a[++s1.top]=tree;
}

struct node * pop1(){
    return s1.a[s1.top--];
}

void preorder(struct node * root){
    if(root==NULL){
        return;
    }

    printf("%c ",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}

void inorder(struct node * root){
    if(root==NULL){
        return;
    }

    inorder(root->lchild);
    printf("%c ",root->data);
    inorder(root->rchild);
}

void postorder(struct node * root){
    if(root==NULL){
        return;
    }

    postorder(root->lchild);
    postorder(root->rchild);
    printf("%c ",root->data);
}

int main(){
    char *exp,sym;
    s1.top=-1;
    struct node * temp=NULL,*root=NULL;
    exp=postfix();
    for(int i=0;exp[i]!='\0';i++){
        sym=exp[i];
        if(sym>='A'&&sym<='Z' || sym>='a'&&sym<='z'|| sym>='0'&&sym<='9'){
                temp=getnode(sym);
                push1(temp);
        }
        else{
                temp=getnode(sym);
                temp->rchild=pop1();
                temp->lchild=pop1();
                push1(temp);

        }
    }

    root=pop1();

    printf("Inorder: ");
    inorder(root);
    printf("Preorder: ");
    preorder(root);
    printf("postorder: ");
    postorder(root);
    return 0;
}