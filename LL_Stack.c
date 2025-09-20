#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef struct Stack {
    Node *top;
}Stack;

Stack *initialize() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

bool isFull(Stack* s) {
    return false;
}

bool isEmpty(Stack* s) {
    return s->top == NULL;
}

void push(Stack* s, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    
    if(isEmpty(s)) {
        s->top = newNode;
        return;
    }
    
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack *s) {
    if(isEmpty(s)) return -1;
    
    int value = s->top->data;
    Node *temp = s->top;
    s->top = s->top->next;
    free(temp);
    
    return value;
}

int peek(Stack *s) {
    if(isEmpty(s)) return -1;
    
    return s->top->data;
}

void display(Stack *s) {
    if(isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    
    printf("{");
    for(Node *trav = s->top; trav != NULL; trav = trav->next) {
        printf("%d", trav->data);
    }
    printf("}\n");
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

