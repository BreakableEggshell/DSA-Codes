#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    int count;
} Queue;

Queue* initialize() {
    Queue *Q = (Queue *)malloc(sizeof(Queue));
    Q->front = NULL;
    Q->rear = NULL;
    Q->count = 0;
    return S;
}

bool isFull(Queue* q) {
    return false;
}

bool isEmpty(Queue* q) {
    return s->top == NULL;
}

void enqueue(Queue* q, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next NULL;
    
    if(isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
        (q->count)++;
        return;
    }
    
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(Queue* q) {
    
}

int front(Queue* q) {
    
}

void display(Queue* q) {
    
}

int main() {
    Stack *S = initialize();
    
    char textMenu[5][30] = {"Push", "Pop", "Peek", "Display", "Exit"};
    int choice, data;
    
    do {
        for(int i = 0; i < 5; i++) {
            printf("[%d] %s\n", i + 1, textMenu[i]);
        }
        printf("Select item: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Data to be pushed: ");
                scanf("%d", &data);
                push(S, data);
                printf("Data has been pushed.\n");
                break;
            case 2:
                data = pop(S);
                (data != -1)
                    ? printf("%d has been popped.\n", data)
                    : printf("List is empty.\n");
                break;
            case 3:
                printf("Peek data: %d", peek(S));
                break;
            case 4:
                display(S);
                break;
            case 5:
                return 0;
                break;
            default:
                printf("Invalid option.\n");
        }
    }while(choice != 5);
    
    return 0;
}

