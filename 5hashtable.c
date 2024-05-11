#include<stdio.h>
#define table_size 10
#define prime 7

int hashtable[table_size];

void display(){
    int i;
    printf("\nHashtable Content\n");
    for(i=0;i<table_size;i++){
        printf("h[%d]=%d\n",i,hashtable[i]);
    }   
}
void searchkey(){
        int i,hindex,hkey,key;
        printf("Enter the key to search:");
        scanf("%d",&key);
        hkey=key%table_size;
        for(i=0;i<table_size;i++){
            hindex=hkey+i%table_size;
            if(hashtable[hindex]==key){
                printf("%d found at h[%d] location",key,hindex);
                return;
            }
        }
        printf("The key is not found..................!\n");
}
void deletekey(){
        int i,hindex,hkey,key;
        printf("Enter the key to delete:");
        scanf("%d",&key);
        hkey=key%table_size;
        for(i=0;i<table_size;i++){
            hindex=hkey+i%table_size;
            if(hashtable[hindex]==key){
                printf("%d found at h[%d] location and is deleted",key,hindex);
                hashtable[hindex]=-1;
                return;
            }
        }
        printf("The key is not found,Cannot delete.......!\n");
}
void insertkey(){
        int i,hindex,h1key,h2key,key;
        printf("Enter the key to insert:");
        scanf("%d",&key);
        h1key=key%table_size;
        h2key=prime-key%prime;

        for(i=0;i<table_size;i++){
            hindex=h1key+i*h2key;
            if(hashtable[hindex]==-1){
                printf("%d inserted at h[%d] location",key,hindex);
                hashtable[hindex%table_size]=key;
                return;
            }
        }
        printf("The key cannot be inserted.......!\n");
}

int main(){
    int ch;
    for(int i=0;i<table_size;i++){
        hashtable[i]=-1;
    }
    while(1){
        printf("\nEnter the choice\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                insertkey();
                break;
            case 2:
                deletekey();
                break;
            case 3:
                searchkey();
                break;
            case 4:
                display();
                break;
            default:
                return 0;
        }
    }
    
}