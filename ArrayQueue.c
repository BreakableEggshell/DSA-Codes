#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int items[MAX];
    int count;
} List;

typedef struct {
    List list;
    int front;
    int rear;
} Queue;

Queue* initialize() {
    Queue* queueTemp = (Queue*)malloc(sizeof(Queue));
    queueTemp->front = -1;
    queueTemp->rear = -1;
    queueTemp->list.count = 0;
    
    return queueTemp;
}

bool isFull(Queue* q) {
    return q->list.count == MAX;
}

bool isEmpty(Queue* q) {
    return q->list.count <= 0;
}

void enqueue(Queue* q, int value) {
    if(isFull(q)) {
        printf("Queue is full.\n");
        return;
    }
    if(isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    }else {
        q->rear = (q->rear + 1) % MAX;
    }
    
    q->list.items[q->rear] = value;
    (q->list.count)++;
    printf("%d has been enqueued.\n", value);
}

int dequeue(Queue* q) {
    if(isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int value = q->list.items[q->front];
    
    if(q->list.count == 1) {
        q->front = 0;
        q->rear = 0;
        q->list.count = 0;
    }else {
        q->front = (q->front + 1) % MAX;
        (q->list.count)--;
    }
    return value;
}

int front(Queue* q) {
    if(isEmpty(q)) {
        return -1;
    }
    
    return q->list.items[q->front];
}

void display(Queue* q) {
    printf("{");
    for(int i = 0; i < q->list.count; i++) {
        printf("%d", q->list.items[(q->front + i) % MAX]);
        if(i + 1 < q->list.count) {
            printf(", ");
        }
    }
    printf("}\n");
}

int main() {
    Queue *Q = initialize();
    
    char textMenu[5][30] = {"Enqueue", "Dequeue", "Front", "Display", "Exit"};
    int choice, item;
    
    do {
        for(int i = 0; i < 5; i++) {
            printf("[%d] %s\n", i + 1, textMenu[i]);
        }
        printf("Select option: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Item: ");
                scanf("%d", &item);
                enqueue(Q, item);
                break;
            case 2:
                if(dequeue(Q) != -1) {
                    printf("Item has been dequeued\n");
                }
                break;
            case 3:
                item = front(Q);
                (item != 1)
                    ? printf("Item at the front: %d\n", Q->list.items[Q->front])
                    : printf("Queue is empty");
                break;
            case 4:
                display(Q);
                break;
            case 5:
                return 0;
                break;
            default:
                printf("Invalid option.\n\n");
        }
    }while(choice != -1);
    
    
    return 0;
}

