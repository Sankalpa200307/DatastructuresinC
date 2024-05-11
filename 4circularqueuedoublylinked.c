#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* next;
    struct node* prev;
};

void enqueue(struct node ** rear, int ele) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->info = ele;

    if (*rear == NULL) {
        *rear = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
    } else {
        new_node->next = (*rear)->next;
        new_node->prev = *rear;
        (*rear)->next->prev = new_node;
        (*rear)->next = new_node;
        *rear = new_node;
    }
}

void dequeue(struct node ** rear) {
    struct node* front;

    if (*rear == NULL) {
        printf("Empty Queue\n");
    } else {
        front = (*rear)->next;

        if (front == *rear) {
            printf("\nDeleted %d\n", front->info);
            free(front);
            *rear = NULL;
        } else {
            (*rear)->next = front->next;
            front->next->prev = *rear;
            printf("\nDeleted %d\n", front->info);
            free(front);
        }
    }
}

void display(struct node * rear) {
    if (rear == NULL) {
        printf("Empty queue\n");
    } else {
        struct node* p = rear->next;
        printf("\nqueue contents are :\n");
        do {
            printf("%d ", p->info);
            p = p->next;
        } while (p != rear->next);
    }
}

int main() {
    struct node* rear;
    rear = NULL;

    int choice, ele;

    while(1){
        printf("Enter the choice: \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("Else to exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter element to enqueue: ");
                scanf("%d", &ele);
                enqueue(&rear, ele);
                break;

            case 2:
                dequeue(&rear);
                break;

            case 3:
                display(rear);
                break;

            default:
                return 0;
               
        }
    }
    

}
