#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *lchild,*rchild;
};

struct node * getnode(int ele){
    struct node *p=(struct node *)malloc(sizeof(struct node));
    p->data=ele;
    p->lchild=NULL;
    p->rchild=NULL;
    return p;
}


void inorder(struct node* root){
    if(root==NULL)
        return;
    
    inorder(root->lchild);
    printf("%d ",root->data);
    inorder(root->rchild);
}

void preorder(struct node* root){
    if(root==NULL)
        return;
    
    printf("%d ",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}

void postorder(struct node* root){
    if(root==NULL)
        return;
    
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ",root->data);
}

struct node * createBT(){
    struct node *p;
    int i,key;
    printf("Enter 1 to insert or 0 to return\n");
    scanf("%d",&i);
    if(i==0){
        return NULL;
    }

    printf("Enter the element to insert:");
    scanf("%d",&key);

    p=getnode(key);
    printf("Creating leftsubtree of %d\n",key);
    p->lchild=createBT();
    printf("Creating rightsubtree of %d\n",key);
    p->rchild=createBT();

    return p;

}

int nodecount(struct node *root){
    if(root==NULL)
        return 0;
    return 1+nodecount(root->lchild)+nodecount(root->rchild);
}

int leafcount(struct node *root){
    if(root==NULL)
        return 0;
    if((root->lchild==NULL)&&(root->rchild==NULL))
        return 1;
    return leafcount(root->lchild)+leafcount(root->rchild);
}

int main(){
    struct node *root;
    root=createBT();
    printf("Inorder traversal: ");
    inorder(root);
    printf("Preorder traversal: ");
    preorder(root);
    printf("Postorder traversal: ");
    postorder(root);
    printf("The number of nodes is %d\n",nodecount(root));
    printf("The number of leafnodes is %d\n",leafcount(root));
    return 0;
}