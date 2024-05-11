#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *lchild,*rchild;
};

struct node* getnode(int ele){
        struct node * temp=(struct node *)malloc(sizeof(struct node));
        temp->lchild=temp->rchild=NULL;
        temp->data=ele;
        return temp;
}

struct node *createroot(){
    int ele;
    struct node *p;
    printf("Enter the key element of root:");
    scanf("%d",&ele);
    p=getnode(ele);
    return p;
}

void inorder(struct node *root){
    if(root==NULL){
        return;
    }

    inorder(root->lchild);
    printf("%d ",root->data);
    inorder(root->rchild);
}
void preorder(struct node *root){
    if(root==NULL){
        return;
    }

    printf("%d ",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}
void postorder(struct node *root){
    if(root==NULL){
        return;
    }

    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ",root->data);
}

void insertion(struct node **root,int ele){
    struct node *p,*q,*temp;
    q=*root;
    while(q!=NULL){
        p=q;
        if(ele<=p->data){
            q=p->lchild;
        }
        else if(ele>p->data){
            q=p->rchild;
        }    
    }

    if(p->data>=ele){
            temp=getnode(ele);
            p->lchild=temp;
    }
    else if(ele>p->data){
        temp=getnode(ele);
        p->rchild=temp;
    }
}

struct node * inordersuccessor(struct node * root){
        struct node *p=root;
        while(p->lchild!=NULL){
            p=p->lchild;
        }
        return p;
}

struct node * deletion(struct node *root,int ele){
        struct node * temp=NULL;
        if(root==NULL){
            return NULL;
        }

        if(ele<root->data)
            root->lchild=deletion(root->lchild,ele);
        else if(ele>root->data)
            root->rchild=deletion(root->rchild,ele);

        else{
            if(root->lchild==NULL){
                temp=root->rchild;
                free(root);
                return temp;
            }
            if(root->rchild==NULL){
                temp=root->lchild;
                free(root);
                return temp;
            }
        temp=inordersuccessor(root->rchild);
        root->data=temp->data;
        root->rchild=deletion(root->rchild,temp->data);
        }
        return root;

        
}

int main(){
    struct node * root=NULL;
    int ch,ele;
    root=createroot();

    while(1){
            printf("1.Insert\n2.Display\n3.Delete\n4.Exit\nEnter the choice:");
            scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the element to insert:");
                scanf("%d",&ele);
                insertion(&root,ele);
                break;
            case 2:
                printf("Inorder: ");
                inorder(root);
                printf("Preorder: ");
                preorder(root);
                printf("Postorder: ");
                postorder(root);
                break;
            case 3:
                printf("Enter the element to delete:");
                scanf("%d",&ele);
                root=deletion(root,ele);
                break;
            default:
                return 0;

        }
    }
}