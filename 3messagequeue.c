#include<stdio.h>
#include<string.h>
#define max 10

struct queue{
    char a[max][max];
    int front,rear;
}cq;

void enqueue(char *ele){
    if((cq.rear+1)%max==cq.front){
        printf("Queue is full\n");
        return ;
    }
    strcpy(cq.a[cq.rear],ele);
    cq.rear=(cq.rear+1)%max;

    if(cq.front==-1){
        cq.front=0;
    }

}

void dequeue(){
    if(cq.front==-1){
        printf("Queue is empty\n");
        return ;
    }
    printf("Deleted %s\n",cq.a[cq.front]);
    cq.front=(cq.front+1)%max;

    if(cq.front==cq.rear){
        cq.rear=0;
        cq.front=-1;
    }
}

void display(){
     if(cq.front==-1){
        printf("Queue is empty\n");
        return ;
    }
    int i=cq.front;
    printf("The messages are:\n");
    do{
        printf("%s\n",cq.a[i]);
        i=(i+1)%max;
    }while(i!=cq.rear);
}

int main(){
    cq.rear=0;
    cq.front=-1;
    char msg[max];
    int choice;
    while(1){
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter the choice:");
        scanf("%d",&choice);
        switch(choice){
                case 1:
                    printf("Enter the message to insert:");
                    scanf("%s",msg);
                    enqueue(msg);
                    break;
                case 2:
                    dequeue();
                    break;
                case 3:
                    display();
                default:
                    return 0;
        }
    }
}