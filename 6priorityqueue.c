#include<stdio.h>
#define max 10

int h[max],n=0;

void heapify(){
    int i,j,v,k;
    for(i=n/2;i>=1;i--){
        k=i;
        v=h[k];
        int heap=0;
        while(!heap && 2*k<=n){
            j=2*k;
            if(j<n){
                if(h[j]<h[j+1]){
                    j=j+1;
                }
            }
            if(v>=h[j]){
                heap=1;

            }
            else{
                h[k]=h[j];
                k=j;
            }
        }
        h[k]=v;
    }
}

void display(){

     if(n==0){
        printf("Empty queue\n");
        return ;
    }

    printf("Priority queue contents are: ");
    for(int i=1;i<=n;i++){
        printf("%d ",h[i]);
    }
    printf("\n");
}

void insert(){

    int ele;
    if(n>=max){
        printf("Queue is full\n");
        return;
    }
    printf("Enter the element to insert:");
    scanf("%d",&ele);
    h[++n]=ele;
    heapify();
}

void delete(){
    if(n==0){
        printf("Empty queue\n");
        return ;
    }
    printf("Deleted %d\n",h[1]);
    h[1]=h[n--];
    heapify();
}

int main(){
    int ch;
    while(1){
    printf("1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter the choice:");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            insert();
            display();
            break;
        case 2:
            delete();
            display();
            break;
        case 3:
            display();
            break;
        default:
            return 0;
    }
    }
}